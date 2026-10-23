#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity1F00C {
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
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48();
    virtual void unknown4c();
    virtual void unknown50(); // Slot 0x50.
};

/* Four byte aggregate, passed by value. */
typedef struct {
    s32 v;
} UnkVal;

extern u32 data_020f03b2;
extern u32 data_0210930c;

extern "C" void func_0201214c(Entity1F00C *, u8 *);
extern "C" u32 func_0208dad8(u32);
extern "C" void func_0209f948(u8 *, UnkVal);
extern "C" void func_0201f58c(Entity1F00C *, s32);
extern "C" Entity1F00C *func_02017800(Entity1F00C *, s32);
extern "C" void func_020675d8(void *, u8);

extern "C" void func_0201f00c(Entity1F00C *obj, u8 *arg1) {
    u32 v = M2C_FIELD(obj, u16 *, 0x212);
    if (v == 0x165 && (M2C_FIELD(arg1, u32 *, 0x1b8) & 0x600) != 0) {
        func_0201214c(obj, arg1);
        return;
    }
    u8 b6bb   = M2C_FIELD(arg1, u8 *, 0x6bb);
    s32 found = 0;
    switch (v) {
        case 11: {
            u16 t = M2C_FIELD(arg1, u16 *, 0x6e8);
            if (t != 250) {
                u32 p = func_0208dad8(t);
                if (M2C_FIELD(p, u8 *, 0x20) == M2C_FIELD(&data_020f03b2, u8 *, M2C_FIELD(obj, u16 *, 0x212) * 16)) {
                    found = 1;
                }
            } else {
                if (b6bb == 9 || b6bb == 32) {
                    found = 1;
                }
            }
            break;
        }
        case 12:
        case 13:
        case 98:
        case 0x165: {
            u16 t = M2C_FIELD(arg1, u16 *, 0x6ee);
            if (t != 250) {
                u32 p = func_0208dad8(t);
                if (M2C_FIELD(p, u8 *, 0x26) == M2C_FIELD(&data_020f03b2, u8 *, M2C_FIELD(obj, u16 *, 0x212) * 16)) {
                    found = 1;
                }
            }
            break;
        }
        case 36:
        case 0x189: {
            if ((M2C_FIELD(arg1, u32 *, 0x1b8) & 0x80000) != 0) {
                found = 1;
            }
            break;
        }
        case 0x18a: {
            if ((M2C_FIELD(arg1, u32 *, 0x1b8) & 0x10000000) != 0) {
                found = 1;
            }
            break;
        }
        case 0x18b: {
            if ((M2C_FIELD(arg1, u32 *, 0x1b8) & 0x8000000) != 0) {
                found = 1;
            }
            break;
        }
        case 37: {
            if ((M2C_FIELD(arg1, u32 *, 0x1b8) & 0x40000) != 0) {
                found = 1;
            }
            break;
        }
        case 0x111:
        case 288:
            found = 1;
            break;
        default:
            break;
    }
    if (found == 0) {
        return;
    }
    u8 state = M2C_FIELD(obj, u8 *, 0x1bc);
    if (!(state == 1 || state == 2 || state == 0 || state == 5)) {
        return;
    }
    obj->action(0x56, 0, 1, 0);
    u32 p148 = M2C_FIELD(obj, u32 *, 0x148);
    UnkVal val;
    val.v = 4096;
    if (val.v >= (p148 != 0 ? (s32) (M2C_FIELD(M2C_FIELD(p148, u32 *, 8), u16 *, 4) << 12) : 0)) {
        val.v = (p148 != 0 ? (s32) (M2C_FIELD(M2C_FIELD(p148, u32 *, 8), u16 *, 4) << 12) : 0) - 4096;
    }
    func_0209f948((u8 *) obj + 212, val);
    M2C_FIELD(obj, u16 *, 0x14e) = M2C_FIELD(obj, u16 *, 0x14e) & ~1;
    if (M2C_FIELD(obj, u16 *, 0x212) == 0x165) {
        func_0201f58c(obj, 0);
        M2C_FIELD(obj, u8 *, 0x1bc) = 0;
        return;
    }
    Entity1F00C *e               = func_02017800(obj, 0);
    M2C_FIELD(obj, u32 *, 0x21c) = (u32) e;
    if (e != 0) {
        e->unknown50();
    }
    M2C_FIELD(obj, u8 *, 0x1bc) = 3;
    u8 flag                     = M2C_FIELD(obj, u8 *, 0x1d9);
    if (flag == 0) {
        return;
    }
    void *g = M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38c), void **, 4);
    func_020675d8((void *) ((u8 *) g + 0x28), flag);
    M2C_FIELD(obj, u8 *, 0x1bc)  = 6;
    M2C_FIELD(obj, u32 *, 0x194) = 0;
}
