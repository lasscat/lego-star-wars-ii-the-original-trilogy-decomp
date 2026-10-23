#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02061f40 (0x108 bytes).
 *
 * The function fills a 0x2c byte object (the caller allocates 44 bytes with
 * func_0205e80c(44,3,4)) and bumps the byte counter data_021042c4.
 */

// Vector with the copy assignment operator of the original class: the
// self check is what the ROM shows as "cmp / beq" around the three word
// copies. Declarations only, the original vtables stay in the ROM data.
class Vec361F40 {
public:
    s32 x, y, z;

    Vec361F40 &operator=(const Vec361F40 &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
};

class Obj61F40 {
public:
    u32 ptr; // 0x00
    u16 a;   // 0x04
    u16 b;   // 0x06
    u32 c;   // 0x08
    u16 d;   // 0x0c
    u8 e;    // 0x0e
    Vec361F40 v1; // 0x10
    Vec361F40 v2; // 0x1c
    u32 f;   // 0x28
};

// Partial interface of the global object whose vtable slot 0x08 is used.
class Global61F40 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *); // Slot 0x08.
};

extern "C" u8 data_027e03a0[];
extern "C" u8 data_027e0410[];
extern "C" u8 data_021042c4;

extern "C" void func_02055700(void *a, void *b);

// The result (the object pointer) is returned in r0; the caller ignores it.
extern "C" Obj61F40 *func_02061f40(Obj61F40 *obj, u32 p, u16 x, u16 y, u32 z) {
    obj->v1.x = 0;
    obj->v1.y = 0;
    obj->v1.z = 0;
    obj->v2.x = 0;
    obj->v2.y = 0;
    obj->v2.z = 0;
    obj->f    = 0;

    if (data_021042c4 > 100) {
        return obj;
    }

    obj->d   = y;
    obj->c   = z;
    obj->a   = x;
    obj->b   = 0;
    obj->ptr = p;
    obj->e   = 0;

    Vec361F40 tmp;
    tmp.x        = 0;
    tmp.y        = 0;
    tmp.z        = 0;
    Vec361F40 &t = tmp;
    obj->v1      = t;

    Vec361F40 *q = (Vec361F40 *) (obj->ptr + obj->b * 44);
    obj->v2      = *q;

    ((Global61F40 *) data_027e03a0)->unknown08(obj);
    func_02055700(&data_027e0410, obj);
    data_021042c4++;
    return obj;
}
