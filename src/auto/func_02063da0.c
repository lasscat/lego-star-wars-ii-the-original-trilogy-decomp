/* Reconstructed from USA ARM9 at 0x02063da0 (88 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef void (*ManagerMethod)(void *, void *);

/* Global manager object; its vtable slot 3 is the virtual callback. */
typedef struct {
    ManagerMethod *vtable;
} Manager;

extern Manager data_02104434;

void func_02063cc4(Manager *a0, u32 a1); /* extern */
void func_020b973c(void *a0);            /* extern */

void *func_02063da0(void *arg0) {
    u8 slot;

    slot = M2C_FIELD(arg0, u8 *, 0x1d);
    if (slot != 0) {
        func_02063cc4(&data_02104434, slot);
    } else {
        if (M2C_FIELD(arg0, void **, 0) != NULL) {
            func_020b973c(M2C_FIELD(arg0, void **, 0));
            M2C_FIELD(arg0, void **, 0) = NULL;
        }
    }
    data_02104434.vtable[3](&data_02104434, arg0);
    return arg0;
}
