#include "m2c.h"

extern u8 data_021027f8[];

typedef struct {
    u8 a : 2;
    u8 flag : 1;
    u8 b : 5;
    u8 pad[0x29];
    u16 x;
    u16 y;
} Tbl;

extern Tbl data_021044a4;

s32 func_0205cfe8(void *, s32 *, s32, s32, s32);
s32 func_0205d0d0(void *, s32, s32);
void func_020b8f70(s32, s32);
void func_020743c4(void *, s32);
void func_020742a4(void *, s32);
s32 func_02064a58(void *, void *);

typedef struct {
    u16 a;
    u16 b;
} Pair;

typedef struct {
    u8 f0;
    u8 flag;
    u16 value;
    u8 pad[8];
} Entry;

typedef struct {
    u8 pad0[0x70];
    s32 sel;
    Entry entries[3];
} Obj;

void func_0207411c(Obj *this) {
    Pair p;
    u32 i;

    if (func_0205cfe8(data_021027f8, &this->sel, 0, 3, 0) != 0) {
        func_020b8f70(0xb6, 0);
        func_020743c4(this, this->sel & 0xff);
        return;
    }
    if (func_0205d0d0(data_021027f8, 1, 4) != 0) {
        func_020b8f70(0xb4, 0);
        func_020742a4(this, this->sel);
        return;
    }

    p.a = 0;
    p.b = 0;
    if (data_021044a4.flag) {
        p.a = data_021044a4.x;
        p.b = data_021044a4.y;
    }

    for (i = 0; i < 3; i++) {
        if (!func_02064a58(&this->entries[i], &p)) {
            continue;
        }
        if ((this->sel == i && this->entries[i].flag != 0) || (s32) this->entries[i].value >= 10) {
            func_020b8f70(0xb4, 0);
            func_020742a4(this, this->sel);
            return;
        }
        if (this->sel == i || this->entries[i].flag == 0) {
            return;
        }
        this->sel = i;
        func_020b8f70(0xb6, 0);
        func_020743c4(this, this->sel & 0xff);
        return;
    }
}
