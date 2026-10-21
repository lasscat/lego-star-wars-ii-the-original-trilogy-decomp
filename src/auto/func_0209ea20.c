/* Reconstructed from USA ARM9 at 0x0209ea20 (188 bytes).
 *
 * func_0209ea20 is the destructor of the class whose vtable is
 * data_020ffb64; its constructor is func_0209e7dc.  It puts the class
 * vtable back, runs the destructor of the five children held at +0x18 and
 * of the child held at +0x14 (both through the second vtable slot), tears
 * the graphics state of the object down and finally returns the object.
 *
 * The object layout (from the constructor) is
 *
 *     +0x00  vtable            +0x0c  graphics state
 *     +0x04  owner            +0x10  a two byte value
 *     +0x08  a halfword        +0x14  a child object
 *                              +0x18  five child objects
 *
 * The second argument of func_0205353c is taken by value as a two byte
 * structure: the original copies it into a stack slot below sp and loads
 * it back with a word load, which is how mwccarm passes such an argument.
 */
#include "m2c.h"

extern u32 data_020ffb64[];
extern M2C_UNK data_02101b98;

/* A two byte structure, passed by value to func_0205353c. */
typedef struct {
    u16 value;
} UnkShort;

extern void func_02053f24();
extern void func_020536a8();
extern void func_0205353c(void *, UnkShort);
extern void func_02053ff8();
extern void func_02054080();
extern void func_02088198();

/* The second slot of the vtable is the destructor of the object. */
typedef void (*UnkVfunc)(void *);

typedef struct {
    UnkVfunc *vtable;
    void *owner;
    u16 field_08;
    void *graphics;
    UnkShort field_10;
    void *child;
    void *children[5];
} UnkObj;

s32 func_0209ea20(s32 a0) {
    UnkObj *self = (UnkObj *) a0;
    u32 i;

    self->vtable = (UnkVfunc *) data_020ffb64;
    for (i = 0; i < 5; i++) {
        UnkObj *child = (UnkObj *) self->children[i];
        if (child != NULL) {
            child->vtable[1](child);
        }
    }
    if (self->child != NULL) {
        UnkObj *child = (UnkObj *) self->child;
        child->vtable[1](child);
    }
    func_02053f24(&data_02101b98, 0);
    func_020536a8(self->graphics, 0);
    func_0205353c(self->graphics, self->field_10);
    func_02053ff8(&data_02101b98, 1, 1);
    func_02054080(&data_02101b98, 0, 0);
    /* func_02088198 does not use its argument. */
    func_02088198(self->owner);
    return (s32) self;
}
