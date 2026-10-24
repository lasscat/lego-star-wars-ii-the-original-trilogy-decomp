/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0206f33c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_anm_jnt.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long long s64;
typedef int s32;
typedef short s16;
typedef s32 fx32;
typedef s16 fx16;
typedef s64 fx64;
typedef struct UnkResJntAnm {
    u8 anmHeader[4];
    u16 numFrame;
    u16 numNode;
    u32 flag;
    u32 ofsRot3;
    u32 ofsRot9;
    u16 ofsTag[1];
} UnkResJntAnm;
typedef struct UnkScale32 {
    fx32 s;
    fx32 inv;
} UnkScale32;
typedef struct UnkScale16 {
    fx16 s;
    fx16 inv;
} UnkScale16;
extern void getScaleData_(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res);
#pragma opt_propagation off
void getScaleData_(fx32 *out, fx32 frame, const u32 *p, const UnkResJntAnm *res) {
    u32 idx;
    u32 lastInterp;
    const void *data;
    u32 a;
    u32 info;
    u32 b;
    u32 f;

    f    = (u32) (frame >> 12);
    data = (u8 *) res + p[1];
    info = p[0];

    if (info & 0xc0000000) {
        lastInterp = (info & 0x1fff0000) >> 16;

        if (info & 0x40000000) {
            if (f & 1) {
                if (f > lastInterp) {
                    f = (lastInterp >> 1) + 1;
                    goto direct;
                } else {
                    idx = f >> 1;
                    goto half;
                }
            } else {
                f >>= 1;
                goto direct;
            }
        } else {
            if (f & 3) {
                if (f > lastInterp) {
                    f = (lastInterp >> 2) + (f & 3);
                    goto direct;
                }
                if (f & 1) {
                    if (f & 2) {
                        b = f >> 2;
                        a = b + 1;
                    } else {
                        a = f >> 2;
                        b = a + 1;
                    }
                    if (info & 0x20000000) {
                        const UnkScale16 *d = (const UnkScale16 *) data;
                        fx32 x;
                        x      = d[a].s;
                        out[0] = (d[b].s + (x + x * 2)) >> 2;
                        x      = d[a].inv;
                        out[1] = (d[b].inv + (x + x * 2)) >> 2;
                    } else {
                        const UnkScale32 *d = (const UnkScale32 *) data;
                        fx32 x;
                        fx32 y;
                        y      = d[b].s;
                        x      = d[a].s;
                        out[0] = (fx32) (((fx64) x * 3 - -(fx64) y) >> 2);
                        x      = d[a].inv;
                        out[1] = (fx32) (((fx64) x * 3 + d[b].inv) >> 2);
                    }
                    return;
                } else {
                    idx = f >> 2;
                    goto half;
                }
            } else {
                f >>= 2;
                goto direct;
            }
        }
    }

direct:
    if (info & 0x20000000) {
        const UnkScale16 *d = (const UnkScale16 *) data;
        out[0]              = d[f].s;
        out[1]              = d[f].inv;
    } else {
        const UnkScale32 *d = (const UnkScale32 *) data;
        out[0]              = d[f].s;
        out[1]              = d[f].inv;
    }
    return;

half:
    if (info & 0x20000000) {
        const UnkScale16 *d = (const UnkScale16 *) data;
        out[0]              = (d[idx].s + (d + idx + 1)->s) >> 1;
        out[1]              = ((d + idx)->inv + (d + idx + 1)->inv) >> 1;
    } else {
        const UnkScale32 *d = (const UnkScale32 *) data;
        out[0]              = (d[idx].s + (d + idx + 1)->s) >> 1;
        out[1]              = ((d + idx)->inv + (d + idx + 1)->inv) >> 1;
    }
}
