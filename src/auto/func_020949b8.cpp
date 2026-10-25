#include "m2c.h"

// Partial interface: only the observed vtable slot is declared; the original vtable stays in ROM data.
class Owner {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(u8 *);
};

extern "C" u8 func_020917b4(void *);
extern "C" s32 func_02062a7c(s32, s32);
extern "C" void *func_0205e80c(s32, s32, s32);
extern "C" u8 *func_0201cd3c(u8 *, s32 *, s32);
extern "C" u8 data_0210930c[];
extern "C" u16 data_02107700[];
extern "C" u32 data_02107798[];

static inline bool IsSet(s32 idx) {
    if (data_02107798[idx >> 5] & (1 << (idx & 31))) {
        return true;
    }
    return false;
}

static inline bool HasRoom(s32 cnt) {
    s32 lim = (data_02107700 + 1)[func_020917b4(data_0210930c)];
    if (lim == 0xffff) {
        return true;
    }
    return IsSet(lim + cnt) == false;
}

extern "C" u8 *func_020949b8(u8 *self, s32 *pos, s32 kind, u32 flag) {
    if (M2C_FIELD(self, u8 *, 0xf8) != 0) {
        if (!HasRoom(M2C_FIELD(self, u16 *, 0xf0))) {
            M2C_FIELD(self, u16 *, 0xf0) += 1;
            return 0;
        }
    }
    if (kind == 5) {
        s32 r                          = func_02062a7c(0, 0x7fff);
        (*(volatile u16 *) 0x04000280) = 0;
        (*(volatile s32 *) 0x04000290) = r;
        (*(volatile s32 *) 0x04000298) = 2;
        (*(volatile s32 *) 0x0400029c) = 0;
        while ((*(volatile u16 *) 0x04000280) & 0x8000) {
        }
        kind = *(volatile s32 *) 0x040002a8;
    }
    u8 *obj = (u8 *) func_0205e80c(0x28, 0, 4);
    if (obj != 0) {
        obj = func_0201cd3c(obj, pos, kind);
    }
    if (flag != 0) {
        obj[0x24] = func_02062a7c(0, M2C_FIELD(self, u8 *, kind + 0xf2) - 1);
    }
    if (M2C_FIELD(self, u8 *, 0xf8) == 0) {
        M2C_FIELD(obj, u16 *, 0x1c) = 0xffff;
    } else {
        u16 c                        = M2C_FIELD(self, u16 *, 0xf0);
        M2C_FIELD(self, u16 *, 0xf0) = c + 1;
        M2C_FIELD(obj, u16 *, 0x1c)  = c;
    }
    ((Owner *) self)->unknown08(obj);
    return obj;
}
