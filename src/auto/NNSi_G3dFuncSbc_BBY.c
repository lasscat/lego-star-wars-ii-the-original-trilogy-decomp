/* Reconstructed from USA ARM9 at 0x020c4b9c (868 bytes). */
#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;

typedef struct {
    s32 v[16];
} Mtx44;

typedef struct {
    s32 v[12];
} Mtx43;

typedef struct {
    u8 *unk0;
    u32 unk4;
    u32 unk8;
    u8 pad[0x20];
    void (*unk2c)(void *);
    u8 pad2[0x64];
    u8 unk94;
} Sbc;

extern M2C_UNK NNS_G3dGlb;
extern M2C_UNK data_027e0c60;
extern s32 data_02101450;
extern s32 data_02101454;
extern s32 data_0210145c[9];
extern s32 data_02101480[3];
extern s32 data_0210148c[3];

void NNS_G3dGeBufferOP_N(s32 op, void *param, s32 count);
void NNS_G3dGeFlushBuffer(void);
s32 G3X_GetClipMtx(void *dest);
void MIi_CpuSend32(const void *src, volatile void *dest, u32 size);
void MTX_Copy43To44_(const Mtx43 *src, Mtx44 *dst);
void MTX_Concat44(const Mtx44 *a, const Mtx44 *b, Mtx44 *out);
M2C_UNK *NNS_G3dGlbGetWV(void);
M2C_UNK *NNS_G3dGlbGetInvWV(void);
M2C_UNK *NNS_G3dGlbGetInvV(void);
s32 VEC_Mag(const VecFx32 *v);
void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);

void NNSi_G3dFuncSbc_BBY(void *arg0, s32 arg1) {
    Sbc *s = (Sbc *) arg0;
    s32 n  = 2;
    /* The original keeps the global addresses live in callee-saved registers
     * (r11/r6/r7) for the whole function; naming them as locals reproduces that. */
    s32 *g80 = data_02101480;
    s32 *g8c = data_0210148c;
    s32 *m   = data_0210145c;
    s32 sp4;
    s32 sp0;
    Mtx44 clip;
    Mtx44 wv;
    Mtx44 iv;
    s32 st;
    s32 r1;
    s32 r0;

    if (s->unk8 & 0x200) {
        if ((arg1 == 0x40) || (arg1 == 0x60)) {
            n++;
        }
        if ((arg1 == 0x20) || (arg1 == 0x60)) {
            n++;
        }
        s->unk0 = s->unk0 + n;
        return;
    }
    if ((arg1 == 0x40) || (arg1 == 0x60)) {
        n++;
        if (!(s->unk8 & 0x100)) {
            if (arg1 == 0x40) {
                sp4 = s->unk0[2];
            } else {
                sp4 = s->unk0[3];
            }
            NNS_G3dGeBufferOP_N(0x14, &sp4, 1);
        }
    }
    st = s->unk2c ? s->unk94 : 0;
    if (st == 1) {
        s->unk8 = s->unk8 & ~0x40;
        s->unk2c(s);
        st = s->unk2c ? s->unk94 : 0;
        r1 = s->unk8 & 0x40;
    } else {
        r1 = 0;
    }
    if (!(s->unk8 & 0x100) && (r1 == 0)) {
        NNS_G3dGeFlushBuffer();
        *(volatile u32 *) 0x04000400 = 0x151110;
        *(volatile u32 *) 0x04000400 = 0;
        *(volatile u32 *) 0x04000400 = 0;
        while (G3X_GetClipMtx(&clip) != 0) {
        }
        if (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 1) {
            MTX_Copy43To44_((const Mtx43 *) NNS_G3dGlbGetWV(), &wv);
            MTX_Concat44(&clip, &wv, &clip);
        } else if (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 2) {
            MTX_Copy43To44_((const Mtx43 *) &data_027e0c60, &iv);
            MTX_Concat44(&clip, &iv, &clip);
        }
        g80[0] = clip.v[12];
        g80[1] = clip.v[13];
        g80[2] = clip.v[14];
        g8c[0] = VEC_Mag((const VecFx32 *) &clip.v[0]);
        g8c[1] = VEC_Mag((const VecFx32 *) &clip.v[4]);
        g8c[2] = VEC_Mag((const VecFx32 *) &clip.v[8]);
        if (clip.v[5] != 0 || clip.v[6] != 0) {
            VEC_Normalize((const VecFx32 *) &clip.v[4], (VecFx32 *) &m[3]);
            m[7] = -m[5];
            m[8] = m[4];
        } else {
            VEC_Normalize((const VecFx32 *) &clip.v[8], (VecFx32 *) &m[6]);
            m[5] = -m[7];
            m[4] = m[8];
        }
        if (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 1) {
            *(volatile u32 *) 0x04000400 = 0x171012;
            MIi_CpuSend32(&data_02101454, (volatile void *) 0x04000400, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvWV(), (volatile void *) 0x04000400, 0x30);
            *(volatile u32 *) 0x04000400 = 0x1b19;
            MIi_CpuSend32(data_0210145c, (volatile void *) 0x04000400, 0x3c);
        } else if (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 2) {
            *(volatile u32 *) 0x04000400 = 0x171012;
            MIi_CpuSend32(&data_02101454, (volatile void *) 0x04000400, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvV(), (volatile void *) 0x04000400, 0x30);
            *(volatile u32 *) 0x04000400 = 0x1b19;
            MIi_CpuSend32(data_0210145c, (volatile void *) 0x04000400, 0x3c);
        } else {
            MIi_CpuSend32(&data_02101450, (volatile void *) 0x04000400, 0x48);
        }
    }
    if (st == 3) {
        s->unk8 = s->unk8 & ~0x40;
        s->unk2c(s);
        r0 = s->unk8 & 0x40;
    } else {
        r0 = 0;
    }
    if ((arg1 == 0x20) || (arg1 == 0x60)) {
        n++;
        if ((r0 == 0) && !(s->unk8 & 0x100)) {
            sp0 = s->unk0[2];
            NNS_G3dGeBufferOP_N(0x13, &sp0, 1);
        }
    }
    s->unk0 = s->unk0 + n;
}
