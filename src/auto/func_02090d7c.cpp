#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class AnimatedNode {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

extern "C" M2C_UNK data_027e0874;
extern "C" M2C_UNK data_027e02a4;
extern "C" M2C_UNK data_021019f4;
extern "C" M2C_UNK data_02101ae4;
extern "C" M2C_UNK data_027e03a0;
extern "C" M2C_UNK data_027e0410;
extern "C" M2C_UNK data_021042d4;

extern "C" void func_020ac680(void *);
extern "C" void G3X_SetFog(M2C_UNK, M2C_UNK, u16, u16);
extern "C" void func_02083a5c(void *);
extern "C" s32 func_020917b4(void *);
extern "C" void func_0208f890(void *);
extern "C" void func_0205e84c(void *);
extern "C" void func_02095f6c(void *, s32);
extern "C" s32 func_02074ffc(void *);
extern "C" void func_0208d458(void *);
extern "C" void func_02094610(void *);
extern "C" void func_0201ce94(void *);
extern "C" void func_020acba8(void *);
extern "C" void func_0200fa74(void *);
extern "C" void func_020184a0(void *, s32);
extern "C" void func_020966e8(void *);
extern "C" void func_0206113c(void *, s32);
extern "C" u16 func_02094010(s32);
extern "C" void func_020612d4(void *, u16, void *);
extern "C" void func_0205df94(void *);
extern "C" void func_0209100c(void *, s32);
extern "C" void func_020184b0(void *);
extern "C" void func_020bbe10(s32);
extern "C" void func_02062890(void *);

extern "C" void func_02090d7c(void *self) {
    func_020ac680(&data_027e0874);
    *(s8 *) ((s8 *) &data_027e0874 + 0x40) = 0;
    G3X_SetFog(0, 0, *(u16 *) ((s8 *) &data_027e0874 + 0x44), *(u16 *) ((s8 *) &data_027e0874 + 0x46));
    func_02083a5c((u8 *) self + 0x1c4 + 0x400);
    u16 value = func_020917b4(self);
    void *obj = *(void **) ((s8 *) self + 0x68);
    if (obj != 0 && obj != 0) {
        func_0208f890(obj);
        func_0205e84c(obj);
    }
    *(u32 *) ((s8 *) self + 0x68) = 0;
    func_02095f6c((u8 *) self + 0x21c + 0x400, 0);
    void *other = *(void **) ((s8 *) self + 0x3c);
    if (other != 0) {
        func_02074ffc(other);
        func_0205e84c(other);
    }
    *(u32 *) ((s8 *) self + 0x3c) = 0;
    func_0208d458((u8 *) self + 0x94);
    func_02094610((u8 *) self + 0xa4);
    func_0201ce94((u8 *) self + 0x74);
    func_020acba8(*(void **) ((s8 *) self + 0x40));
    AnimatedNode *node = *(AnimatedNode **) ((s8 *) self + 0x40);
    if (node != 0) {
        node->unknown04();
    }
    *(u32 *) ((s8 *) self + 0x40) = 0;
    func_0200fa74((u8 *) &data_021019f4 + data_027e02a4 * 0x38);
    for (s32 i = 0; i < 4; i++) {
        ((u32 *) ((u8 *) self + 0x4c))[i] = 0;
    }
    func_020184a0(&data_02101ae4, *(u32 *) ((s8 *) self + 0x44));
    *(u32 *) ((s8 *) self + 0x44) = 0;
    func_020966e8(self);
    func_0206113c(&data_027e03a0, 3);
    u16 result = func_02094010(value);
    if (result != 0xffff) {
        func_020612d4(&data_027e03a0, result, *(void **) ((s8 *) self + 0x6c));
    }
    func_0205df94((u8 *) self + 0x1a0);
    func_0205df94(&data_027e0410);
    func_0209100c(self, 0);
    *(u32 *) ((s8 *) self + 0x5c) = 0;
    func_020184b0(&data_02101ae4);
    func_020bbe10(0);
    func_02062890(&data_021042d4);
}
