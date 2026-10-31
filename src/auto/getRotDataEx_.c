#include "m2c.h"

typedef s32 fx32;
typedef s32 BOOL;

typedef union MtxFx33 {
    struct {
        fx32 _00, _01, _02;
        fx32 _10, _11, _12;
        fx32 _20, _21, _22;
    };
    fx32 m[3][3];
    fx32 a[9];
} MtxFx33;

typedef struct VecFx32 {
    fx32 x, y, z;
} VecFx32;

typedef struct NNSG3dResJntAnm {
    u32 anmHeader;
    u16 numFrame;
    u16 numNode;
    u32 flag;
    u32 ofsRot3;
    u32 ofsRot5;
} NNSG3dResJntAnm;

BOOL getRotDataByIdx_(MtxFx33 *pRot, const void *pivotRecords, const void *packedRecords, u16 info);
void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);

enum {
    FX32_SHIFT                 = 12,         /* 20.12 fixed point */
    FX32_DEC_MASK              = 0xfff,      /* fraction within one frame */
    FX32_DEC_MASK_STEP2        = 0x1fff,     /* fraction within a 2-frame sample */
    FX32_DEC_MASK_STEP4        = 0x3fff,     /* fraction within a 4-frame sample */
    ROT_INFO_STEP_MASK         = 0xc0000000, /* curve is sampled every 2 or 4 frames */
    ROT_INFO_STEP_2            = 0x40000000, /* 2-frame step (else 4-frame step) */
    ROT_INFO_LAST_INTERP       = 0x1fff0000, /* first frame stored per frame, not per step */
    ROT_INFO_LAST_INTERP_SHIFT = 16,
    JNTANM_END_TO_START        = 0x2,        /* last frame blends toward record 0 */
};

static inline void crossProduct_(const VecFx32 *a, const VecFx32 *b, VecFx32 *axb) {
    fx32 x, y, z;

    x      = (a->y * b->z - a->z * b->y) >> FX32_SHIFT;
    y      = (a->z * b->x - a->x * b->z) >> FX32_SHIFT;
    z      = (a->x * b->y - a->y * b->x) >> FX32_SHIFT;
    axb->x = x;
    axb->y = y;
    axb->z = z;
}

/*
 * Joint-animation rotation at time Frame (20.12 fixed point frames) into pRot.
 *
 * pData = {info, offset of the per-sample u16 record array from pJntAnm}. Each
 * u16 is decoded by getRotDataByIdx_ from the pivot (ofsRot3) or packed (ofsRot5)
 * tables. Curves may be sampled every 1, 2 or 4 frames; frames from
 * lastInterp on are stored one per frame.
 *
 * Last frame: decode one record (or blend toward record 0 when the animation
 * wraps). Otherwise blend the two neighbouring records: row = a * step +
 * (b - a) * frac, where frac covers the whole step, so each row is scaled by
 * step and then normalized. Packed records leave the third row unwritten
 * (getRotDataByIdx_ returns 1); then it is rebuilt as row0 x row1.
 */
void getRotDataEx_(MtxFx33 *pRot, fx32 Frame, const u32 *pData, const NNSG3dResJntAnm *pJntAnm) {
    MtxFx33 rotA;
    MtxFx33 rotB;
    u32 frame;
    u32 info;
    u32 idx;
    u32 idxNext;
    fx32 frac;
    s32 step;
    const u16 *pRecords;
    BOOL rebuildRow2;
    const void *pivotRecords;
    const void *packedRecords;

    pRecords      = (const u16 *) ((const u8 *) pJntAnm + pData[1]);
    pivotRecords  = (const u8 *) pJntAnm + pJntAnm->ofsRot3;
    packedRecords = (const u8 *) pJntAnm + pJntAnm->ofsRot5;
    frame         = (u32) (Frame >> FX32_SHIFT);
    info          = pData[0];

    if (frame == pJntAnm->numFrame - 1) {
        if (info & ROT_INFO_STEP_MASK) {
            if (info & ROT_INFO_STEP_2) {
                idx = (frame >> 1) + (frame & 1);
            } else {
                idx = (frame >> 2) + (frame & 3);
            }
        } else {
            idx = frame;
        }
        if (pJntAnm->flag & JNTANM_END_TO_START) {
            idxNext = 0;
            goto blend_step1;
        }
        if (getRotDataByIdx_(pRot, pivotRecords, packedRecords, pRecords[idx])) {
            crossProduct_((const VecFx32 *) &pRot->_00, (const VecFx32 *) &pRot->_10, (VecFx32 *) &pRot->_20);
        }
        return;
    }

    if (info & ROT_INFO_STEP_MASK) {
        u32 lastInterp = (info & ROT_INFO_LAST_INTERP) >> ROT_INFO_LAST_INTERP_SHIFT;
        if (info & ROT_INFO_STEP_2) {
            if (frame >= lastInterp) {
                idx     = lastInterp >> 1;
                idxNext = idx + 1;
                goto blend_step1;
            } else {
                idx     = frame >> 1;
                idxNext = idx + 1;
                frac    = Frame & FX32_DEC_MASK_STEP2;
                step    = 2;
            }
        } else {
            if (frame >= lastInterp) {
                idx     = (frame >> 2) + (frame & 3);
                idxNext = idx + 1;
                goto blend_step1;
            } else {
                idx     = frame >> 2;
                idxNext = idx + 1;
                frac    = Frame & FX32_DEC_MASK_STEP4;
                step    = 4;
            }
        }
    } else {
        idx     = frame;
        idxNext = frame + 1;
    blend_step1:
        frac = Frame & FX32_DEC_MASK;
        step = 1;
    }

    rebuildRow2 = 0;
    rebuildRow2 |= getRotDataByIdx_(&rotA, pivotRecords, packedRecords, pRecords[idx]);
    rebuildRow2 |= getRotDataByIdx_(&rotB, pivotRecords, packedRecords, pRecords[idxNext]);

    pRot->_00 = rotA._00 * step + (((rotB._00 - rotA._00) * frac) >> FX32_SHIFT);
    pRot->_01 = rotA._01 * step + (((rotB._01 - rotA._01) * frac) >> FX32_SHIFT);
    pRot->_02 = rotA._02 * step + (((rotB._02 - rotA._02) * frac) >> FX32_SHIFT);
    pRot->_10 = rotA._10 * step + (((rotB._10 - rotA._10) * frac) >> FX32_SHIFT);
    pRot->_11 = rotA._11 * step + (((rotB._11 - rotA._11) * frac) >> FX32_SHIFT);
    pRot->_12 = rotA._12 * step + (((rotB._12 - rotA._12) * frac) >> FX32_SHIFT);

    VEC_Normalize((const VecFx32 *) &pRot->_00, (VecFx32 *) &pRot->_00);
    VEC_Normalize((const VecFx32 *) &pRot->_10, (VecFx32 *) &pRot->_10);

    if (!rebuildRow2) {
        pRot->_20 = rotA._20 * step + (((rotB._20 - rotA._20) * frac) >> FX32_SHIFT);
        pRot->_21 = rotA._21 * step + (((rotB._21 - rotA._21) * frac) >> FX32_SHIFT);
        pRot->_22 = rotA._22 * step + (((rotB._22 - rotA._22) * frac) >> FX32_SHIFT);
        VEC_Normalize((const VecFx32 *) &pRot->_20, (VecFx32 *) &pRot->_20);
    } else {
        crossProduct_((const VecFx32 *) &pRot->_00, (const VecFx32 *) &pRot->_10, (VecFx32 *) &pRot->_20);
    }
}
