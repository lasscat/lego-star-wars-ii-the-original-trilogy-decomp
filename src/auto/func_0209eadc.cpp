#include "m2c.h"

/* The vtable of the class destroyed here lives in the ROM data; only its
 * address point is referenced (data_020ffb64 = slot 0x00 = func_0209ea20,
 * slot 0x04 = func_0209eadc, slot 0x08 = func_0209eba0).  The vptr is stored
 * by hand, so no vtable is emitted.
 */
extern "C" s32 data_020ffb64;
extern "C" s32 data_02101b98;

/* A two byte structure, passed by value to func_0205353c: the original copies
 * it into a stack slot below sp and loads it back with a word load.
 */
typedef struct {
    u16 value;
} UnkShort;

extern "C" void func_02053f24(void *, s32);
extern "C" void func_020536a8(void *, s32);
extern "C" void func_0205353c(void *, UnkShort);
extern "C" void func_02053ff8(void *, s32, s32);
extern "C" void func_02054080(void *, s32, s32);
extern "C" void func_02088198(void *);
/* The destructor of the base class of this object. */
extern "C" void func_0205e84c(void *);

/* The five children at +0x18 and the child at +0x14 are released through the
 * second vtable slot of their own class.
 */
class Child {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data.
 *
 * The data members reproduce the observed layout of the object:
 *   +0x00 vtable   +0x04 owner      +0x08 a half word
 *   +0x0c graphics  +0x10 a half word +0x14 a child
 *   +0x18 five children
 */
class Owner9EADC {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();

    void *owner;
    u16 field_08;
    void *graphics;
    UnkShort field_10;
    Child *child;
    Child *children[5];
};

extern "C" void *func_0209eadc(Owner9EADC *obj) {
    u32 i;

    M2C_FIELD(obj, void **, 0) = (void *) &data_020ffb64;
    for (i = 0; i < 5; i++) {
        Child *child = obj->children[i];
        if (child != 0) {
            child->unknown04();
        }
    }
    if (obj->child != 0) {
        obj->child->unknown04();
    }
    func_02053f24((void *) &data_02101b98, 0);
    func_020536a8(obj->graphics, 0);
    func_0205353c(obj->graphics, obj->field_10);
    func_02053ff8((void *) &data_02101b98, 1, 1);
    func_02054080((void *) &data_02101b98, 0, 0);
    func_02088198(obj->owner);
    func_0205e84c(obj);
    return obj;
}
