/* Reconstructed from USA ARM9 at 0x0200c724 (184 bytes).
 *
 * The object keeps a table of 0x28 byte records at self + 0x1D0; record
 * "index" holds an object pointer.  When the slot is still empty a new object
 * is allocated (0xBC bytes) and constructed, otherwise the old object is
 * destroyed first.  Afterwards the record is flagged (0x1DF), the object is
 * registered (func_0209f53c) and gets its model (func_020ab40c), and the
 * record's counter byte (0x1E1) is updated.
 */
#include "m2c.h"

extern void *func_0205e80c(s32, s32, s32);
extern void *func_0209f404(void *);
extern void func_0209f590(void *);
extern s32 func_0209f53c(s32, u32);
extern u16 func_0201ca1c(u16);
extern s32 func_020ab40c(s32, u16);
extern void func_0200c894(s32, s32);
extern void func_0200c868(s32, s32);

void func_0200c724(u8 *self, s32 index, s32 idx, s32 arg3) {
    s32 v = arg3;
    void *obj;

    if (idx == 3) {
        v = 2;
    }
    if (*(void **) (self + 0x1D0 + idx * 0x28) == NULL) {
        obj = func_0205e80c(0xBC, 0, 4);
        if (obj != NULL) {
            obj = func_0209f404(obj);
        }
        *(void **) (self + 0x1D0 + idx * 0x28) = obj;
    } else {
        func_0209f590(*(void **) (self + 0x1D0 + idx * 0x28));
        func_0200c894(self, M2C_FIELD(self + 0x100 + idx * 0x28, s8 *, 0xE1));
    }
    M2C_FIELD(self + idx * 0x28, u8 *, 0x1DF) = 1;
    func_0209f53c(*(void **) (self + 0x1D0 + idx * 0x28), index);
    obj = *(void **) (self + 0x1D0 + idx * 0x28);
    func_020ab40c((u8 *) obj + 4, func_0201ca1c(*(u16 *) ((u8 *) obj + 0xAC)));
    func_0200c868(self, v);
    M2C_FIELD(self + 0x100 + idx * 0x28, s8 *, 0xE1) = v;
}
