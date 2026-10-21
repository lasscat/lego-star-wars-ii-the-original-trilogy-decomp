#include "m2c.h"

/* Partial interfaces: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtables remain in the ROM data. */
class ObjectB0CD4 {
public:
    virtual void *unknown00(int); /* Slot 0x00. */
    virtual void *unknown04();     /* Slot 0x04. */
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(int); /* Slot 0x18. */
    virtual int unknown1c();     /* Slot 0x1c. */
};

class ObjectB348 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48();
    virtual void unknown4c(int); /* Slot 0x4c. */
};

class NodeB0CD4 {};

extern "C" ObjectB0CD4 *data_021092f4;
extern "C" ObjectB348 *data_0210b348;
extern "C" M2C_UNK data_02102900;
extern "C" M2C_UNK data_0210930c;
extern "C" M2C_UNK data_02104d2c;
extern "C" M2C_UNK data_02104d90;
extern "C" M2C_UNK data_02104df4;
extern "C" M2C_UNK data_0210794c;
extern "C" M2C_UNK data_021027f8;
extern "C" s32 data_027e02a8;

extern "C" void func_020b10f4(void *);
extern "C" void func_020b10a8(void *);
extern "C" void func_020b111c(void *, s32);
extern "C" s32 func_020b0c60(s32, s32);
extern "C" M2C_UNK func_02060198(void *);
extern "C" M2C_UNK func_0205ecc4(M2C_UNK *, u8, u8, u8, s32, s32);
extern "C" u32 func_020917b4(M2C_UNK *);
extern "C" M2C_UNK func_02088b84(M2C_UNK *, u8);
extern "C" void func_02093c9c(void *);
extern "C" M2C_UNK func_02087088(M2C_UNK *);
extern "C" u32 func_02062ae4(s32);
extern "C" M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, u8 *, M2C_UNK);
extern "C" s32 func_02073044();
extern "C" M2C_UNK func_02073054(M2C_UNK);
extern "C" M2C_UNK func_0205ce5c(M2C_UNK *, u8);

extern "C" void func_020b0cd4(NodeB0CD4 *self) {
    u32 world;
    u16 id;
    s32 i;
    u32 count;
    u8 c;
    u8 bufB[0x1c];
    u8 bufA[0x1c];

    if (M2C_FIELD(self, u8 *, 6) != 0) {
        if (M2C_FIELD(self, s8 *, 12) > 0) {
            M2C_FIELD(self, s8 *, 12) = M2C_FIELD(self, s8 *, 12) - 1;
            if (M2C_FIELD(self, s8 *, 12) == 0) {
                func_020b10f4(self);
            }
        }
    }
    world = M2C_FIELD(&data_0210930c, u32 *, 0x4c);
    if (M2C_FIELD(self, u8 *, 7) == 0) {
        return;
    }
    if (M2C_FIELD(&data_02102900, u32 *, 0x48) != 0 || M2C_FIELD(&data_02102900, u32 *, 0x68) != 0) {
        return;
    }
    id = M2C_FIELD(data_021092f4->unknown00(0), u16 *, 0x66);
    if (id == M2C_FIELD(&data_02104d2c, u16 *, 2)) {
        u32 p;
        if (M2C_FIELD(self, u32 *, 0x10) == 0) {
            return;
        }
        p = M2C_FIELD(&data_02102900, u32 *, 4);
        if ((p ? M2C_FIELD(p, u32 *, 4) : 0) != 0x23) {
            u32 q;
            if (M2C_FIELD(&data_02102900, u32 *, 0x48) == 0 && M2C_FIELD(&data_02102900, u32 *, 0x68) == 0) {
                q = M2C_FIELD(&data_02102900, u32 *, 0);
                if ((q ? M2C_FIELD(q, u32 *, 4) : 0) == 4) {
                    if ((data_027e02a8 & 0x40) == 0 && M2C_FIELD(self, u8 *, 8) == 0 && M2C_FIELD(self, u8 *, 13) == 0) {
                        if (func_02060198(&data_02102900) == 0 && M2C_FIELD(world, u8 *, 0x5d6) == 0) {
                            func_0205ecc4(&data_02102900, 0x23, 1, 0, 0, 0);
                            data_0210b348->unknown4c(0);
                        }
                    }
                }
            }
        }
        if (M2C_FIELD(self, u8 *, 13) == 1) {
            if (M2C_FIELD(self, u8 *, 8) == 0 && M2C_FIELD(&data_02104d2c, u8 *, 6) > 1) {
                func_02087088(&data_02104d90);
                M2C_FIELD(bufB, u16 *, 4) = (u16) func_02062ae4(5000);
                bufB[6]                   = 0;
                func_020b04f0(&data_0210794c, 10, bufB, 255);
                data_021092f4->unknown18(0);
                M2C_FIELD(self, u8 *, 8) = 1;
            }
            M2C_FIELD(self, u8 *, 13) = 0;
            return;
        }
        if (M2C_FIELD(self, u8 *, 13) == 2) {
            func_020b111c(self, 0);
            func_020b10a8(self);
            M2C_FIELD(self, u32 *, 0x10) = 0;
            M2C_FIELD(self, u8 *, 13)    = 0;
            func_02093c9c(&data_0210930c);
            return;
        }
        return;
    } else {
        if (M2C_FIELD(self, u32 *, 0x10) == 0) {
            for (i = 0; i < 16; i++) {
                if (func_020b0c60(id, i) != 0) {
                    if (func_020b0c60(M2C_FIELD(&data_02104d2c, u16 *, 2), i) == 0) {
                        M2C_FIELD(self, u32 *, 0x10) = i;
                        break;
                    }
                }
            }
        } else {
            if (M2C_FIELD(&data_0210930c, u32 *, 0x68) != 0) {
                func_02088b84(&data_02104df4, (u8) func_020917b4(&data_0210930c));
                func_0205ecc4(&data_02102900, 4, 0, 14, (s32) func_020917b4(&data_0210930c), 0);
                func_0205ecc4(&data_02102900, 0x30, 1, 0, 0, 0);
            }
            func_020b111c(self, 0);
            func_020b10a8(self);
            M2C_FIELD(self, u32 *, 0x10) = 0;
            M2C_FIELD(self, u8 *, 13)    = 0;
            return;
        }
    }
    M2C_FIELD(&data_02104d2c, u16 *, 2) = id;
    count                               = 0;
    for (i = 0; i < func_02073044(); i++) {
        if (id & (1 << i)) {
            count = (count + 1) & 0xff;
        }
    }
    M2C_FIELD(&data_02104d2c, u8 *, 6) = count;
    c                                  = count & 0xff;
    if (c > 1 && M2C_FIELD(self, u8 *, 14) != c) {
        func_0205ce5c(&data_021027f8, count & 0xff);
        func_02073054(M2C_FIELD(&data_02104d2c, u8 *, 6));
        bufA[1] = (u8) func_02073044();
        bufA[0] = M2C_FIELD(&data_02104d2c, u8 *, 6);
        func_020b04f0(&data_0210794c, 19, bufA, 255);
    }
    M2C_FIELD(self, u8 *, 14) = M2C_FIELD(&data_02104d2c, u8 *, 6);
}
