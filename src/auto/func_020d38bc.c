/* func_020d38bc (USA ARM9, 0x020d38bc, 288 bytes).
 * Touch-screen state conversion: when the flag at data_02104364+0x34 is clear the input
 * quad is copied unchanged, otherwise each coordinate is scaled with the fixed point
 * factors in data_02104364+0x24 and clamped to 0..255 / 0..191. */
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
typedef long long s64;

extern u16 data_02117450[];
extern s32 data_0211746c[];

struct S {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
};

void func_020d38bc(struct S *out, struct S *in) {
    s32 *p;
    u16 w;
    u16 h;

    if (data_02117450[0x1a] == 0) {
        *out = *in;
    } else {
        p      = data_0211746c;
        w      = in->w;
        out->w = w;
        h      = in->h;
        out->h = h;
        if (w == 0) {
            out->x = 0;
            out->y = 0;
        } else {
            out->x = (u16) ((u32) (((s64) p[2] * ((s64) (in->x * 4) - p[0])) >> 22));
            if ((s16) out->x < 0) {
                out->x = 0;
            } else if ((s16) out->x > 255) {
                out->x = 255;
            }
            out->y = (u16) ((u32) (((s64) p[5] * ((s64) (in->y * 4) - p[3])) >> 22));
            if ((s16) out->y < 0) {
                out->y = 0;
            } else if ((s16) out->y > 191) {
                out->y = 191;
            }
        }
    }
}
