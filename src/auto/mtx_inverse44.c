/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0206af18 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_glbstate.c (license: none),
 * reused by tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef struct UnkMtx44 {
    s32 unk_00[4][4];
} UnkMtx44;
extern void MTX_Identity44_(UnkMtx44 *m);
extern void MI_Copy64B(const void *src, void *dest);
extern s64 FX_InvFx64c(s32 denom);
int mtx_inverse44(const UnkMtx44 *src, UnkMtx44 *dst) {
    UnkMtx44 tmp;
    int i;
    int j;
    int k;

    MI_Copy64B(src, &tmp);
    MTX_Identity44_(dst);

    for (i = 0; i < 4; i++) {
        s32 max    = 0;
        int maxRow = i;
        s64 inv;

        for (j = i; j < 4; j++) {
            s32 v = tmp.unk_00[j][i];

            if (v < 0) {
                v = -v;
            }
            if (v > max) {
                maxRow = j;
                max    = v;
            }
        }
        if (max == 0) {
            return -1;
        }

        if (maxRow != i) {
            int k;

            for (k = 0; k < 4; k++) {
                s32 t                 = tmp.unk_00[i][k];
                tmp.unk_00[i][k]      = tmp.unk_00[maxRow][k];
                tmp.unk_00[maxRow][k] = t;

                t                      = dst->unk_00[i][k];
                dst->unk_00[i][k]      = dst->unk_00[maxRow][k];
                dst->unk_00[maxRow][k] = t;
            }
        }

        inv = FX_InvFx64c(tmp.unk_00[i][i]);
        for (k = 0; k < 4; k++) {
            tmp.unk_00[i][k]  = (s32) ((inv * tmp.unk_00[i][k] + 0x80000000LL) >> 32);
            dst->unk_00[i][k] = (s32) ((inv * dst->unk_00[i][k] + 0x80000000LL) >> 32);
        }

        for (j = 0; j < 4; j++) {
            if (j != i) {
                s32 f = tmp.unk_00[j][i];

                for (k = 0; k < 4; k++) {
                    tmp.unk_00[j][k]  = tmp.unk_00[j][k] - (((s64) f * tmp.unk_00[i][k]) >> 12);
                    dst->unk_00[j][k] = dst->unk_00[j][k] - (((s64) f * dst->unk_00[i][k]) >> 12);
                }
            }
        }
    }
    return 0;
}
