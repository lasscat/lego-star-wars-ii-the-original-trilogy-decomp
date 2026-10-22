#include "m2c.h"

class Entity {
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
    virtual void action(int, int, int, int); // Slot 0x24
    virtual void unknown28();
    virtual void interact(Entity *, int, int); // Slot 0x2c
};

extern "C" u32 data_020fdae8[16];
extern "C" void func_02011384(void *self, int a1, int a2, int a3);
extern "C" u32 func_02062ae4(int arg0);
extern "C" void func_02026364(void *self, void *arg);

extern "C" Entity *func_0202600c(Entity *obj, int a1, int a2, int a3) {
    func_02011384(obj, a1, a2, a3);
    *(void **) obj = (void *) &data_020fdae8;
    obj->action(0x8a, 1, 1, 0);
    M2C_FIELD(obj, u8 *, 0x1bc) = 0;
    M2C_FIELD(obj, u8 *, 0x217) = 1;
    M2C_FIELD(obj, s8 *, 0x216) = -1;
    M2C_FIELD(obj, s8 *, 0x218) = -1;
    if (a1 == 0x162) {
        if (func_02062ae4(1) == 1) {
            M2C_FIELD(obj, u8 *, 0x219) = 1;
            obj->action(0x8b, 1, 1, 0);
        } else {
            M2C_FIELD(obj, u8 *, 0x219) = 0;
            obj->action(0x8a, 1, 1, 0);
        }
    } else if (M2C_FIELD(obj, u16 *, 0x212) == 0xed) {
        M2C_FIELD(obj, int *, 0x84)       = 0x1b;
        M2C_FIELD(obj, void (**)(), 0x18) = (void (*)()) func_02026364;
    }
    M2C_FIELD(obj, u8 *, 0x21a) = 0;
    return obj;
}
