#include "m2c.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad[0x29];
    u16 f2a;
    u16 f2c;
} Data;

typedef struct {
    u8 pad00[0xbc];
    u16 fbc;
    u16 fbe;
    u8 padc0[0x28];
    s32 fe8;
    s32 fec;
} Obj;

extern Data data_021044a4;

void func_0209adb4(void *, s32, s32, s32, s32, s32, s32);
void func_0209a824(void *);

void func_0209a40c(Obj *self) {
    if (data_021044a4.b4) {
        self->fbc = data_021044a4.f2a;
        self->fbe = data_021044a4.f2c;
        self->fec = 2;
        if (self->fbc >= 0x70 && self->fbc <= 0xa0 && self->fbe >= 0x90 && self->fbe <= 0xb8) {
            self->fec = 0;
        } else if (self->fbc >= 0xb8 && self->fbc <= 0xe8 && self->fbe >= 0x90 && self->fbe <= 0xb8) {
            self->fec = 1;
        }
        if (self->fec == 0) {
            func_0209adb4(self, 0x60, 0xd0, 0x70, 0x90, 0x30, 0x28);
        } else if (self->fec == 1) {
            func_0209adb4(self, 0x60, 0xf8, 0xb8, 0x90, 0x30, 0x28);
        }
    }
    if (data_021044a4.b2 && self->fec != 2) {
        self->fbc = data_021044a4.f2a;
        self->fbe = data_021044a4.f2c;
        if (self->fec == 0) {
            if (self->fbc >= 0x70 && self->fbc <= 0xa0 && self->fbe >= 0x90 && self->fbe <= 0xb8) {
                func_0209adb4(self, 0x60, 0xd0, 0x70, 0x90, 0x30, 0x28);
            } else {
                if (self->fe8 == 0) {
                    func_0209adb4(self, 0, 0xd0, 0x70, 0x90, 0x30, 0x28);
                } else {
                    func_0209adb4(self, 0x30, 0xd0, 0x70, 0x90, 0x30, 0x28);
                }
            }
        } else if (self->fec == 1) {
            if (self->fbc >= 0xb8 && self->fbc <= 0xe8 && self->fbe >= 0x90 && self->fbe <= 0xb8) {
                func_0209adb4(self, 0x60, 0xf8, 0xb8, 0x90, 0x30, 0x28);
            } else {
                if (self->fe8 == 1) {
                    func_0209adb4(self, 0, 0xf8, 0xb8, 0x90, 0x30, 0x28);
                } else {
                    func_0209adb4(self, 0x30, 0xf8, 0xb8, 0x90, 0x30, 0x28);
                }
            }
        }
    }
    if (!data_021044a4.b5) {
        return;
    }
    {
        s32 old = self->fe8;
        if (self->fec == 0) {
            if (self->fbc >= 0x70 && self->fbc <= 0xa0 && self->fbe >= 0x90 && self->fbe <= 0xb8) {
                self->fe8 = 0;
            }
        } else if (self->fec == 1) {
            if (self->fbc >= 0xb8 && self->fbc <= 0xe8 && self->fbe >= 0x90 && self->fbe <= 0xb8) {
                self->fe8 = 1;
            }
        }
        if (old != self->fe8) {
            func_0209a824(self);
        }
    }
    self->fec = 2;
    if (self->fe8 == 0) {
        func_0209adb4(self, 0, 0xd0, 0x70, 0x90, 0x30, 0x28);
        func_0209adb4(self, 0x30, 0xf8, 0xb8, 0x90, 0x30, 0x28);
    } else if (self->fe8 == 1) {
        func_0209adb4(self, 0x30, 0xd0, 0x70, 0x90, 0x30, 0x28);
        func_0209adb4(self, 0, 0xf8, 0xb8, 0x90, 0x30, 0x28);
    }
}
