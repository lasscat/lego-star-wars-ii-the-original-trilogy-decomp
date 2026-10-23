#include "m2c.h"

s32 func_0202c59c(void *, u32 *, u32 *);
void func_0202cbd4(s32 *, void *);
void func_0202cbf4(s32 *, const void *);
s32 func_0202cb44(void *);

#define ENT(self) M2C_FIELD(self, void **, 4)
#define F5FC(self) M2C_FIELD(ENT(self), void **, 0x5fc)
#define F604(self) M2C_FIELD(ENT(self), void **, 0x604)
#define IDX(p) M2C_FIELD(p, u8 *, 8)

void func_02032828(void *self) {
    s32 flag;
    s32 idx;
    s32 v1;
    s32 v2;
    s32 v3;

    if (M2C_FIELD(self, u16 *, 0x18) != 0) {
        M2C_FIELD(self, u16 *, 0x18)--;
        if (M2C_FIELD(self, u16 *, 0x18) == 0) {
            M2C_FIELD(self, u8 *, 0xc) |= 1;
            return;
        }
    }
    M2C_FIELD(self, u16 *, 0x1a)++;
    if (M2C_FIELD(self, u8 *, 0x1c) == 0) {
        return;
    }
    if (F5FC(self) == 0) {
        return;
    }
    if (func_0202cb44((u8 *) ENT(self) + 0x5e0) == 0) {
        return;
    }
    flag = 0;
    idx  = M2C_FIELD(F604(self), s32 *, 8);
    if (IDX(F5FC(self)) == 4) {
        func_0202cbd4(&v1, F5FC(self));
        if (idx < v1) {
            if (M2C_FIELD(self, u16 *, 0x18) > 6) {
                flag = 1;
            }
        }
    } else {
        func_0202cbf4(&v2, F5FC(self));
        if (idx > v2) {
            if (M2C_FIELD(self, u16 *, 0x18) < 15) {
                flag = 1;
            }
        } else {
            func_0202cbd4(&v3, F5FC(self));
            if (idx < v3) {
                if (M2C_FIELD(self, u16 *, 0x18) > 2) {
                    flag = 1;
                }
            }
        }
    }
    if (flag == 0) {
        if (func_0202c59c((u8 *) ENT(self) + 0x5e0, &M2C_FIELD(self, u32 *, 0x10), &M2C_FIELD(self, u32 *, 0x14)) != 0) {
            if (M2C_FIELD(self, u16 *, 0x18) < 15) {
                flag = 1;
            }
        } else if (M2C_FIELD(self, u32 *, 0x10) <= 1 && M2C_FIELD(self, u32 *, 0x14) >= 2 &&
                   M2C_FIELD(self, u16 *, 0x1a) < 15) {
            flag = 1;
        }
    }
    if (flag != 0) {
        M2C_FIELD(self, u8 *, 0xc) |= 1;
    }
}
