/* Reconstructed from USA ARM9 at 0x020c4894 (776 bytes). */
#include "m2c.h"

typedef struct {
    float x;
    float y;
    float z;
} Vec3;

typedef struct {
    float v[16];
} Mtx44;

typedef struct {
    float v[12];
} Mtx43;

typedef struct {
    u8 *unk0;
    u32 unk4;
    u32 unk8;
    u8 pad[0x1c];
    void (*unk28)(void *);
    u8 pad2[0x67];
    u8 unk93;
} Sbc;

extern M2C_UNK NNS_G3dGlb;
extern M2C_UNK data_027e0c60;
extern M2C_UNK data_02101408;
extern M2C_UNK data_0210140c;
extern M2C_UNK data_02101414;
extern Vec3 data_02101438;
extern Vec3 data_02101444;

void NNS_G3dGeBufferOP_N(s32 op, void *param, s32 count);
void NNS_G3dGeFlushBuffer(void);
s32 G3X_GetClipMtx(void *dest);
void MIi_CpuSend32(const void *src, volatile void *dest, u32 size);
void MTX_Copy43To44_(const Mtx43 *src, Mtx44 *dst);
void MTX_Concat44(const Mtx44 *a, const Mtx44 *b, Mtx44 *out);
M2C_UNK *NNS_G3dGlbGetWV(void);
M2C_UNK *NNS_G3dGlbGetInvWV(void);
M2C_UNK *NNS_G3dGlbGetInvV(void);
float VEC_Mag(const Vec3 *v);

void NNSi_G3dFuncSbc_BB(void *arg0, s32 arg1) {
    Sbc *s = (Sbc *) arg0;
    s32 n  = 2;
    /* The original keeps both global addresses live in callee-saved registers
     * (r5/r6) for the whole function; naming them as locals reproduces that. */
    Vec3 *g38 = &data_02101438;
    Vec3 *g44 = &data_02101444;
    u32 sp4;
    u32 sp0;
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
    st = s->unk28 ? s->unk93 : 0;
    if (st == 1) {
        s->unk8 = s->unk8 & ~0x40;
        s->unk28(s);
        st = s->unk28 ? s->unk93 : 0;
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
        g38->x = clip.v[12];
        g38->y = clip.v[13];
        g38->z = clip.v[14];
        g44->x = VEC_Mag((const Vec3 *) &clip.v[0]);
        g44->y = VEC_Mag((const Vec3 *) &clip.v[4]);
        g44->z = VEC_Mag((const Vec3 *) &clip.v[8]);
        if (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 1) {
            *(volatile u32 *) 0x04000400 = 0x171012;
            MIi_CpuSend32(&data_0210140c, (volatile void *) 0x04000400, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvWV(), (volatile void *) 0x04000400, 0x30);
            *(volatile u32 *) 0x04000400 = 0x1b19;
            MIi_CpuSend32(&data_02101414, (volatile void *) 0x04000400, 0x3c);
        } else if (M2C_FIELD(&NNS_G3dGlb, s32 *, 0xFC) & 2) {
            *(volatile u32 *) 0x04000400 = 0x171012;
            MIi_CpuSend32(&data_0210140c, (volatile void *) 0x04000400, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvV(), (volatile void *) 0x04000400, 0x30);
            *(volatile u32 *) 0x04000400 = 0x1b19;
            MIi_CpuSend32(&data_02101414, (volatile void *) 0x04000400, 0x3c);
        } else {
            MIi_CpuSend32(&data_02101408, (volatile void *) 0x04000400, 0x48);
        }
    }
    if (st == 3) {
        s->unk8 = s->unk8 & ~0x40;
        s->unk28(s);
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
