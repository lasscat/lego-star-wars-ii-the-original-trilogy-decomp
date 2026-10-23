#include "m2c.h"

void *func_02096b0c(void *, s32, u8);                         /* extern */
void *func_020aaa08(void *, s32, u8);                         /* extern */
M2C_UNK *func_020aaeb4(void);                                  /* extern */
extern M2C_UNK data_0210930c;
extern M2C_UNK data_020ed5cc;

typedef struct {
    void *f0;
    void *f4;
} Elem;

void func_02067838(void *arg0, s32 arg1) {
    void *obj;
    s32 idx;
    void *(*fn)(void *, u8, u16);

    idx = arg1 - 1;
    if (M2C_FIELD(arg0, Elem **, 0)[idx].f0 != 0) {
        return;
    }
    if (func_02096b0c(&data_0210930c, M2C_FIELD(arg0, u8 *, 4), arg1) != 0) {
        return;
    }
    if (func_020aaa08(func_020aaeb4(), M2C_FIELD(arg0, u8 *, 4), arg1) != 0) {
        return;
    }
    obj = M2C_FIELD(arg0, Elem **, 0)[idx].f4;
    fn  = ((void **) &data_020ed5cc)[M2C_FIELD(obj, u8 *, 6)];
    if (fn == 0) {
        return;
    }
    M2C_FIELD(arg0, Elem **, 0)[idx].f0 = fn(obj, M2C_FIELD(arg0, u8 *, 4), (u16) (idx + 1));
    if (M2C_FIELD(arg0, Elem **, 0)[idx].f0 == 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(arg0, Elem **, 0)[idx].f0, u8 *, 0x88) = M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(M2C_FIELD(arg0, Elem **, 0)[idx].f0, u8 *, 0x89) = (u8) (idx + 1);
    if (M2C_FIELD(arg0, u8 *, 6) != 0) {
        M2C_FIELD(arg0, u8 *, 6) = 1;
    }
}
