/* Reconstructed from USA ARM9 at 0x0202cc80 (32 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"
typedef struct {
    u32 unknown;
    s32 data;
    u8 pad;
    u8 value;
} Object;
extern u32 func_0202cca0(Object *);
extern void func_02004b78(s32, u8);
void func_0202cc80(Object *object) {
    object->value = func_0202cca0(object);
    func_02004b78(object->data, (u8) object->value);
}
