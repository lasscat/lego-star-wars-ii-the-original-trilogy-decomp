#include "m2c.h"

/* func_02063cc4 (0x02063cc4, 72 bytes)
 *
 * Releases the object that is registered in slot `index` of the global
 * controller object (&data_02104434) once its reference count runs out:
 * the byte counter at +0x48 is decremented, and when it reaches zero the
 * object pointer at +0x38 is destroyed with func_020b973c and cleared.
 *
 * The original code addresses both arrays through the base pointer and the
 * index (base + 0x48 + index for the counter, base + 0x38 + index * 4 for the
 * object pointer), which is reproduced by accessing them as members of the
 * enclosing structure.
 */

extern void func_020b973c(void *object);

typedef struct {
    u8 pad[0x38];
    void *objects[4];
    u8 counters[4];
} Unk_02063cc4;

void func_02063cc4(Unk_02063cc4 *obj, s32 index) {
    u8 counter;

    counter = --obj->counters[index];
    if (counter != 0) {
        return;
    }
    if (obj->objects[index] == NULL) {
        return;
    }
    func_020b973c(obj->objects[index]);
    obj->objects[index] = NULL;
}
