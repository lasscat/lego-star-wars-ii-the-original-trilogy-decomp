#include "m2c.h"

u32 func_02062ae4(s32 arg0);
void func_02082ef0(M2C_UNK arg0, M2C_UNK arg1);
s32 func_0208d874(M2C_UNK arg0, u16 *arg1);
s32 func_02083340(void *arg0, s32 arg1);
s32 func_0208d8cc(u16 arg0, u16 arg1);
void func_02082b88(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2);
void func_02081eac(M2C_UNK arg0, M2C_UNK arg1);
void func_020831b0(M2C_UNK arg0);

typedef struct {
    u16 v[6];
} Six;
typedef struct {
    u16 p[6];
    Six v;
    u16 q[6];
} Src;
extern Src data_020f0174;
extern void *data_02102900;

typedef struct Obj {
    u8 pad_000[0x108];
    s32 f108;
    u8 pad_10C[0x134 - 0x10C];
    u8 *slots[5];
    s32 counts[5];
    s32 f15C;
    s32 f160;
} Obj;

void func_02081a10(Obj *this) {
    s32 sel;
    Six buf;
    s32 idx;
    s32 i;

    sel = (this->f160 <= 0 || func_02062ae4((u16) (this->f160 - 1)) == 0) ? -1 : func_02062ae4((u16) (this->f160 - 1));
    func_02082ef0(this, sel);

    buf = data_020f0174.v;

    for (i = 0; i < 5; i++) {
        if (this->counts[i] <= 0 || (i == 4 && func_02062ae4(100) < 0x3C)) {
            idx = -1;
        } else {
            idx = func_02062ae4((u16) (this->counts[i] - 1));
            while (func_0208d874(this->slots[i][idx], (u16 *) &buf) == 0 ||
                   func_0208d8cc(func_02083340(this, sel), this->slots[i][idx]) == 0) {
                idx = func_02062ae4((u16) (this->counts[i] - 1));
            }
        }
        func_02082b88(this, i, idx);
        buf.v[i] = this->slots[i][idx];
    }

    if ((data_02102900 != NULL ? M2C_FIELD(data_02102900, s32 *, 4) : 0) == 9) {
        M2C_FIELD(data_02102900, u8 *, 0x28) = 1;
    }

    for (i = 0; i < 3; i++) {
        func_02081eac(this, M2C_FIELD((char *) this + 4 * this->f108 + 0x10C, s32 *, 0) + i);
    }
    func_020831b0(this);
}
