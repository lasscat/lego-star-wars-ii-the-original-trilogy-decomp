#include "m2c.h"

// Position triple.  The assignment operator carries the self check that the
// original code performs before it copies the triple.
class V3 {
public:
    s32 x;
    s32 y;
    s32 z;
    V3 &operator=(const V3 &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
};

// Partial interface: the object lives in the ROM data area, only its address
// is taken here.
class Object {
public:
    u32 vptr; // 0x00, set by the constructor
    V3 v1;   // 0x04
    V3 v2;   // 0x10
    u8 type; // 0x1c
    u8 pad1D[3];
    u8 a;    // 0x20
    u8 b;    // 0x21
};

// Partial interface of the factory; slot 0x08 is the only one used here.
class Factory {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void create(Object *); // Slot 0x08.
};

extern "C" void *func_0205e80c(s32, s32, s32);
extern "C" void *func_020962e8();
extern "C" void *func_02096b78();
extern "C" void *func_020974b4();
extern "C" void *func_02097524();
extern "C" void *func_02097590();
extern "C" void *func_02097640();
extern "C" void *func_02097b28();
extern "C" void *func_020982a0();
extern "C" void *func_020981ac();
extern "C" void *func_02098344();
extern "C" void *func_02096018();
extern "C" void *func_02098240();
extern "C" void *func_02097944();

extern "C" void *func_02096828(Factory *factory, V3 v1, V3 v2, int type, u8 a, u8 b) {
    Object *obj;

    switch (type) {
        case 1:
            obj = (Object *) func_0205e80c(0x30, 0, 4);
            if (obj) {
                obj = (Object *) func_02096b78();
            }
            break;
        case 2:
            obj = (Object *) func_0205e80c(0x34, 0, 4);
            if (obj) {
                obj = (Object *) func_020974b4();
            }
            break;
        case 3:
            obj = (Object *) func_0205e80c(0x40, 0, 4);
            if (obj) {
                obj = (Object *) func_02097524();
            }
            break;
        case 4:
            obj = (Object *) func_0205e80c(0x34, 0, 4);
            if (obj) {
                obj = (Object *) func_02097590();
            }
            break;
        case 5:
            obj = (Object *) func_0205e80c(0x3c, 0, 4);
            if (obj) {
                obj = (Object *) func_02097640();
            }
            break;
        case 6:
            obj = (Object *) func_0205e80c(0x40, 0, 4);
            if (obj) {
                obj = (Object *) func_02097b28();
            }
            break;
        case 7:
            obj = (Object *) func_0205e80c(0x40, 0, 4);
            if (obj) {
                obj = (Object *) func_020982a0();
            }
            break;
        case 12:
            obj = (Object *) func_0205e80c(0x34, 0, 4);
            if (obj) {
                obj = (Object *) func_020981ac();
            }
            break;
        case 9:
            obj = (Object *) func_0205e80c(0x3c, 0, 4);
            if (obj) {
                obj = (Object *) func_02098344();
            }
            break;
        case 8:
            obj = (Object *) func_0205e80c(0x3c, 0, 4);
            if (obj) {
                obj = (Object *) func_02096018();
            }
            break;
        case 11:
            obj = (Object *) func_0205e80c(0x30, 0, 4);
            if (obj) {
                obj = (Object *) func_02098240();
            }
            break;
        case 10:
            obj = (Object *) func_0205e80c(0x3c, 0, 4);
            if (obj) {
                obj = (Object *) func_02097944();
            }
            break;
        default:
            obj = (Object *) func_0205e80c(0x2c, 0, 4);
            if (obj) {
                obj = (Object *) func_020962e8();
            }
            break;
    }
    if (obj != 0) {
        obj->type = (u8) type;
        obj->v1   = v1;
        obj->v2   = v2;
        obj->b    = b;
        obj->a    = a;
        factory->create(obj);
    }
    return obj;
}
