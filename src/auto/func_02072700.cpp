#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Manager72700 {
public:
    virtual void unknown00();
    virtual void unknown04();          // Slot 0x08.
    virtual void unknown08();
    virtual void unknown0c();
    virtual s32 unknown10(int, u32, int); // Slot 0x10.
};

// Callback table reached through the global link.
struct Callback72700 {
    void *(*fn)(void *, int); // 0x00
};

struct Link72700 {
    Callback72700 *cb; // 0x00
};

class Obj72700 {
public:
    u8 pad00[0x2c];
    u32 f2c; // 0x2c
    u8 pad30[0x3];
    u8 f30; // 0x30
};

extern "C" Manager72700 *data_0210b348;
extern "C" Link72700 *data_021092f4;
extern "C" u8 data_02102900[];
extern "C" u8 data_021027f8[];

extern "C" void func_02072cd0(void);
extern "C" s32 func_0207300c(void);
extern "C" void func_020730d0(s32);
extern "C" void func_02073054(s32);
extern "C" void func_0205ce5c(void *, s8);
extern "C" void func_0205ecc4(void *, u32, u32, u32, s32, s32);

extern "C" void func_02072700(Obj72700 *self) {
    if (M2C_FIELD(self, u8 *, 0x30) == 0) {
        if (data_0210b348->unknown10(5, M2C_FIELD(self, u32 *, 0x2c), 1) != 0) {
            M2C_FIELD(self, u8 *, 0x30) = 1;
            return;
        }
        func_02072cd0();
        func_0205ecc4(data_02102900, 38, 1, 0, 1, 0);
        return;
    }
    Link72700 *link = data_021092f4;
    void *result    = link->cb->fn(link, 0);
    if (M2C_FIELD(result, u16 *, 0x66) & 1) {
        if (func_0207300c() != 0) {
            return;
        }
        func_0205ce5c(data_021027f8, 2);
        func_020730d0(2);
        func_02073054(2);
        return;
    }
    data_0210b348->unknown08();
    func_02072cd0();
    func_0205ecc4(data_02102900, 38, 1, 0, 1, 0);
}
