/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* NNS_G3dScrPosToWorldLine from projets/blue-dragon-awakened-shadow/src/donor/NNS_G3dScrPosToWorldLine.c (same code in another
 * game of this workspace), reused by tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef s32 fx32;
typedef s64 fx64;
typedef struct {
    fx32 x, y, z;
} VecFx32;
typedef struct {
    fx32 _00, _01, _02, _03, _10, _11, _12, _13, _20, _21, _22, _23, _30, _31, _32, _33;
} MtxFx44;
extern fx32 FX_Div(fx32 a, fx32 b);
extern void func_020c9344(fx32 d);
extern fx64 func_020c92e8(void);
extern const MtxFx44 *NNS_G3dGlbGetInvVP(void);
extern void NNS_G3dGlbGetViewPort(int *x1, int *y1, int *x2, int *y2);
static inline fx32 Mul32x64c(fx32 v32, fx64 v64c) {
    fx64 tmp = v64c * v32 + 0x80000000LL;
    return (fx32) (tmp >> 32);
}
int NNS_G3dScrPosToWorldLine(int px, int py, VecFx32 *pNear, VecFx32 *pFar) {
    int x1, y1, x2, y2;
    fx32 x, y;
    int ret;
    const MtxFx44 *m;
    fx32 t;
    fx32 nx, ny, nz;
    fx32 fw, fx, fy, fz;
    fx64 inv;
    int h;

    NNS_G3dGlbGetViewPort(&x1, &y1, &x2, &y2);
    h = y2 - y1;
    x = FX_Div((px - x1) << 12, (x2 - x1) << 12);
    y = FX_Div((py + y1 - 191) << 12, -h << 12);

    if (x < 0 || y < 0 || x > 0x1000 || y > 0x1000) {
        ret = -1;
    } else {
        ret = 0;
    }

    x = (x - 0x800) * 2;
    y = (y - 0x800) * 2;

    m = NNS_G3dGlbGetInvVP();
    t = (fx32) (((fx64) x * m->_03 + (fx64) y * m->_13) >> 12) + m->_33;
    func_020c9344(t - m->_23);
    nx = (fx32) (((fx64) x * m->_00 + (fx64) y * m->_10) >> 12) + m->_30;
    ny = (fx32) (((fx64) x * m->_01 + (fx64) y * m->_11) >> 12) + m->_31;
    nz = (fx32) (((fx64) x * m->_02 + (fx64) y * m->_12) >> 12) + m->_32;

    if (pFar) {
        fx = nx + m->_20;
        fy = ny + m->_21;
        fz = nz + m->_22;
        fw = t + m->_23;
    }
    nx -= m->_20;
    ny -= m->_21;
    nz -= m->_22;

    inv = func_020c92e8();
    if (pFar) {
        func_020c9344(fw);
    }
    pNear->x = Mul32x64c(nx, inv);
    pNear->y = Mul32x64c(ny, inv);
    pNear->z = Mul32x64c(nz, inv);

    if (pFar) {
        inv     = func_020c92e8();
        pFar->x = Mul32x64c(fx, inv);
        pFar->y = Mul32x64c(fy, inv);
        pFar->z = Mul32x64c(fz, inv);
    }
    return ret;
}
