#include "m2c.h"

typedef struct {
    u16 v;
} A16;

typedef struct {
    A16 a;
    A16 b;
    A16 c;
} Trip;

s32 func_01ffa41c(M2C_UNK);                         /* extern */
M2C_UNK func_01ffa430(void *, M2C_UNK);             /* extern */

/* Reads three 16-bit angles (scaled by 0xB60B60B60B >> 44, 12-bit rounded fixed point) and three
   s32 values from the stream stream into the object; names guessed from callers. */
void func_0205bec8(void *obj, M2C_UNK stream) {
    Trip m;
    Trip l;
    s32 raw;
    raw                         = func_01ffa41c(stream);
    m.c.v                       = (s16) (((s64) raw * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
    l.c                         = m.c;
    M2C_FIELD(obj, u16 *, 0x1e) = l.c.v;
    raw                         = func_01ffa41c(stream);
    m.b.v                       = (s16) (((s64) raw * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
    l.b                         = m.b;
    M2C_FIELD(obj, u16 *, 0x1c) = l.b.v;
    raw                         = func_01ffa41c(stream);
    m.a.v                       = (s16) (((s64) raw * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
    l.a                         = m.a;
    M2C_FIELD(obj, u16 *, 0x20) = l.a.v;
    M2C_FIELD(obj, s32 *, 0x14) = func_01ffa41c(stream);
    M2C_FIELD(obj, s32 *, 0x18) = func_01ffa41c(stream);
    M2C_FIELD(obj, s32 *, 0x10) = func_01ffa41c(stream);
    func_01ffa430(obj, stream);
}
