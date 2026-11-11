/* Fill the four global light slots in data_027e0874 for one object and set
 * the global material colours. Both matched callers (func_0208fbd8 and
 * func_02010644) pass data_0210930c; func_0208fbd8 then packs the four
 * directions into NNS_G3dGlb.lightVec.
 *
 * With a light table at +0x5C: light i (i < table->count) takes its direction
 * from table entry i and its colour from the object's 16-bit colour array at
 * +0x60. A table of 1 to 3 entries has the remaining lights set to black with
 * the direction (k, k, 0.9), where k = data_020ff9a8 and 0.9 has 12 fraction
 * bits (func_02007f24 multiplies by 4096.0 and truncates). The material
 * colours become white diffuse, the table's ambient colour, specular 0x1f and
 * emission 0.
 *
 * Without a table, func_020ac130 fills all four lights with its own fixed
 * directions and sets the material colours from white diffuse and grey
 * (12,12,12) ambient.
 *
 * Matching constraints: data_027e0874 is declared at its full 0x58 bytes
 * (data_027e08cc follows it); a shorter declaration changes the load/store
 * order of the direction copies in the first two cases. The colour element is
 * read through a pointer cast; an indexed read of a Color array keeps an index
 * where the target walks a pointer.
 */
#include "m2c.h"

enum {
    LIGHT_COUNT    = 4,
    COLOR_MAX      = 31, /* 5-bit channel maximum */
    GREY_LEVEL     = 12,
    SPECULAR_COLOR = 0x1f,
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef union {
    struct {
        u16 r : 5;
        u16 g : 5;
        u16 b : 5;
        u16 a : 1;
    } c;
    u16 raw;
} Color;

typedef struct {
    u16 unk0;
    u16 unk2;
    Vec3 dir; /* 0x04 */
} LightEntry;

typedef struct {
    u8 count;   /* 0x00 */
    u8 unk1;
    u16 ambient; /* 0x02 */
    LightEntry entries[1]; /* 0x04 */
} LightTable;

typedef struct {
    u8 pad0[0x5C];
    LightTable *table; /* 0x5C */
    u16 colors[1];     /* 0x60, one per table entry */
} Obj;

typedef struct {
    Vec3 dir;    /* 0x00 */
    Color color; /* 0x0C */
    u16 unkE;
} Light;

typedef struct {
    Light lights[LIGHT_COUNT]; /* 0x00 */
    s8 unk40;
    u16 unk44;
    u16 unk46;
    u8 pad48[0xe];
    u16 unk56;
} Data874;

extern void func_02007f24(s32 *out, f64 value);
extern void func_020ac130(Data874 *state, Color *diffuse, Color *ambient);
extern void NNS_G3dGlbMaterialColorDiffAmb(s32 arg0, s32 arg1, s32 arg2);
extern void NNS_G3dGlbMaterialColorSpecEmi(s32 arg0, s32 arg1, s32 arg2);
extern s32 data_020ff9a8;
extern Data874 data_027e0874;

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void light_idx(s32 n, const Vec3 *dir, Color color) {
    data_027e0874.lights[n].color = color;
    vec_set(&data_027e0874.lights[n].dir, dir);
}

void func_020932e8(Obj *arg0) {
    Color white;
    Color black;
    Color diffuse;
    Color ambient;
    s32 z;
    Vec3 fill_dir;
    LightTable *table;
    u32 i;

    white.c.r = COLOR_MAX;
    white.c.g = COLOR_MAX;
    white.c.b = COLOR_MAX;
    white.c.a = 0;
    black.raw = 0;
    func_02007f24(&z, 0.9);
    fill_dir.z = z;
    fill_dir.x = data_020ff9a8;
    fill_dir.y = data_020ff9a8;
    table      = arg0->table;
    if (table != NULL) {
        for (i = 0; i < arg0->table->count; i++) {
            const Vec3 *src = &arg0->table->entries[i].dir;
            light_idx(i, src, *(Color *) &arg0->colors[i]);
        }
        /* Lights the table leaves out; the cases fall through. */
        switch (arg0->table->count) {
            case 1:
                light_idx(1, &fill_dir, black);
            case 2:
                light_idx(2, &fill_dir, black);
            case 3:
                light_idx(3, &fill_dir, black);
        }
        NNS_G3dGlbMaterialColorDiffAmb(white.raw, arg0->table->ambient, 0);
        NNS_G3dGlbMaterialColorSpecEmi(SPECULAR_COLOR, 0, 1);
    } else {
        ambient.c.r = GREY_LEVEL;
        ambient.c.g = GREY_LEVEL;
        ambient.c.b = GREY_LEVEL;
        ambient.c.a = 0;
        diffuse.raw = white.raw;
        func_020ac130(&data_027e0874, &diffuse, &ambient);
    }
}
