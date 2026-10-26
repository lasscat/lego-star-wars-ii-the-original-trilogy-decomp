#include "m2c.h"

extern u16 func_020b01cc(s32);
extern void func_02072404(void *, s32);
extern void func_02053c2c(void *, s32, s32, s32, s32, s32);
extern void func_02065600(void *, s32);
extern void func_0206574c(void *, s32, s32);
extern s32 func_02073044(void);
extern void OS_GetOwnerInfo(void *);
extern u8 *MB_CommGetChildUser(s32);
extern void func_0209bd08(void *, s32, void *, s32);
extern void func_02065be8(void *, s32, s32, s32, void *, s32);

extern u8 data_02104d2c[];
extern u8 *data_02107860;
extern s16 data_020ee008[];

enum {
    CACHE_SLOT_MASK  = 0x2,   /* u16 in data_02104d2c: mask the list was last built for */
    CACHE_SLOT_COUNT = 0x6,  /* u8 in data_02104d2c: slots listed by that build */
    SLOT_ARG_FIRST   = 0x141,  /* second func_02065be8 argument for slot 0 */
    SLOT_ARG_STEP    = 0x2d,    /* added per slot index */
    SLOT_NAME        = 0x51,        /* name buffer of slot 0 in *data_02107860 */
    SLOT_STRIDE      = 0x18,      /* bytes between slot records */
};

/*
 * Rebuild the per-slot name list shown through the object at arg0 + 0x64, but only when the slot
 * bitmap changed. The bitmap comes from func_020b01cc(0); bit 0 (the local console) is always
 * forced on, and bit i selects slot i. The result is cached in data_02104d2c (mask at +2, count at
 * +6); an unchanged mask returns the cached count without touching anything.
 *
 * For each listed slot the name is stored into the slot record (func_0209bd08 copies `len` bytes to
 * *data_02107860 + 0x51 + slot * 0x18): slot 0 takes the console owner's name from OS_GetOwnerInfo,
 * other slots take the name of child `slot` from MB_CommGetChildUser. A slot whose stored name is
 * empty is not drawn and clears the cached mask, so the next call rebuilds the list again.
 * Otherwise the slot is passed to func_02065be8 with its s16 pair from data_020ee008 and a value
 * that steps by 0x2d per slot (role of that value and of the pair not established).
 * Returns the number of listed slots, drawn or not.
 *
 * Unknown: what func_02072404 does when only the local console is present, and what the setup
 * calls on arg0 + 0x28 / arg0 + 0x64 configure. The block-local `slots` alias (pointer to the
 * global pointer) is the form that gives the original register assignment.
 */
u8 func_02072250(void *arg0) {
    u16 slot_arg;
    u8 count;
    s32 i;
    u32 mask;
    u8 owner[0x50];

    slot_arg = SLOT_ARG_FIRST;
    mask     = func_020b01cc(0) | 1;
    mask &= 0xffff;
    if (*(u16 *) (data_02104d2c + CACHE_SLOT_MASK) == mask) {
        return data_02104d2c[CACHE_SLOT_COUNT];
    }
    if (mask == 1) {
        func_02072404(arg0, 1);
    }
    *(u16 *) (data_02104d2c + CACHE_SLOT_MASK) = mask;
    func_02053c2c((u8 *) arg0 + 0x28, 0, 4, 0x20, 0xD, 0);
    func_02065600((u8 *) arg0 + 0x64, 3);
    func_0206574c((u8 *) arg0 + 0x64, 9, -2);
    count = 0;
    for (i = 0; i < func_02073044(); i++) {
        if (i == 0 || (mask & (1 << i))) {
            u8 **slots = &data_02107860;
            u8 *name;
            s16 slot;
            if (i == 0) {
                /* owner record: name at +4, its length (u16) at +0x18 */
                OS_GetOwnerInfo(owner);
                func_0209bd08(*slots, (u8) i, owner + 4, (u8) * (u16 *) (owner + 0x18));
            } else {
                /* child user record: length at +1, name at +2 */
                u8 *user = MB_CommGetChildUser((u16) i);
                func_0209bd08(*slots, (u8) i, user + 2, user[1]);
            }
            slot = (u8) i;
            name = *slots + SLOT_NAME + slot * SLOT_STRIDE;
            if (*name != 0) {
                func_02065be8((u8 *) arg0 + 0x64, slot_arg, data_020ee008[i * 2], data_020ee008[i * 2 + 1], name, 0);
            } else {
                *(u16 *) (data_02104d2c + CACHE_SLOT_MASK) = 0;
            }
            count++;
        }
        slot_arg = (u16) (slot_arg + SLOT_ARG_STEP);
    }
    data_02104d2c[CACHE_SLOT_COUNT] = count;
    return count & 0xff;
}
