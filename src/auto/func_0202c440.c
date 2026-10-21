/* Reconstructed from USA ARM9 at 0x0202c440 (88 bytes).
 *
 * The object owns a "light" pointer at +0x18.  When it is set, the light is
 * released through the second slot of its vtable (vtable[1]) and the field is
 * cleared.  A type of 5 leaves the object without a light; any other type
 * creates a new light from the configuration at +0x20 and hands it to
 * func_0202c698 together with the object and a flag of 1.
 *
 * The new light is stored into +0x18 and the very same value is passed on to
 * func_0202c698; mwccarm forwards the stored value into r1 instead of
 * reloading the field, which is what the original code does.
 */
#include "m2c.h"

s32 func_0202f790(s32, s32);     /* extern */
void func_0202c698(s32, s32, s32); /* extern */

typedef void (*VFunc)(void *);

typedef struct VTable {
    void *unk0;
    VFunc vfunc1;
} VTable;

typedef struct Light {
    VTable *vtable;
} Light;

void func_0202c440(s32 *arg0, s32 arg1) {
    Light *var_r0;

    var_r0 = (Light *) M2C_FIELD(arg0, s32 *, 0x18);
    if (var_r0 != NULL) {
        var_r0->vtable->vfunc1(var_r0);
    }
    M2C_FIELD(arg0, s32 *, 0x18) = NULL;
    if (arg1 == 5) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x18) = (s32 *) func_0202f790(M2C_FIELD(arg0, s32 *, 0x20), arg1);
    func_0202c698(arg0, M2C_FIELD(arg0, s32 *, 0x18), 1);
}
