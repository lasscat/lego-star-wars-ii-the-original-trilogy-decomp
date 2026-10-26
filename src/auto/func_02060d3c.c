#include "m2c.h"

extern u32 data_027e02a8;
extern u8 data_021041bc[];
void func_02060e6c(void *);
u32 func_02060f24(u16 *, s32);
void func_02055b84(M2C_UNK, M2C_UNK, M2C_UNK, s32);

enum {
    OBJ_FLAG_REGISTERED    = 0x80000, /* object already holds a table cell */
    OBJ_FLAG_ALT_BANK      = 0x80000000, /* set: use table row 0 */
    GLOBAL_FLAG_FORCE_ROW0 = 0x200,
    INFO_SLOT_MASK         = 0xF000, /* cell index in bits 12..15 of the info word */
    ROW_SIZE               = 0x84,
    CELL_ID_OFFSET         = 4,
    CELL_COUNT_OFFSET      = 5,
    CELL_PTR_OFFSET        = 8,
    NOTIFY_SIZE            = 0x10,
};

/* Picks the table row (0 or 1) for an object. */
static inline u32 get_row(void *obj) {
    if ((data_027e02a8 & GLOBAL_FLAG_FORCE_ROW0) != 0) {
        return 0;
    }
    if ((M2C_FIELD(obj, u32 *, 0x8) & OBJ_FLAG_ALT_BANK) != 0) {
        return 0;
    }
    return 1;
}

/* Registers key arg1 for object arg0: finds a free/matching cell in the row table,
 * records the cell index in the object, bumps the cell's use count and stores the key. */
void func_02060d3c(void *arg0, u16 *arg1) {
    u32 slot;
    u32 v;
    u32 row;

    if ((M2C_FIELD(arg0, u32 *, 0x8) & OBJ_FLAG_REGISTERED) == OBJ_FLAG_REGISTERED) {
        func_02060e6c(arg0);
    }
    slot                                                        = func_02060f24(arg1, get_row(arg0));
    v                                                           = M2C_FIELD(arg0, u32 *, 0x14);
    M2C_FIELD(arg0, u32 *, 0x14)                                = (v & ~0xF000u) | ((u16) (slot << 12));
    row                                                         = get_row(arg0);
    (data_021041bc + CELL_ID_OFFSET + row * ROW_SIZE)[slot * 8] = M2C_FIELD(arg0, u16 *, 0xc);
    (data_021041bc + CELL_COUNT_OFFSET + row * ROW_SIZE)[slot * 8]++;
    *(u32 *) (data_021041bc + CELL_PTR_OFFSET + row * ROW_SIZE + slot * 8) = (u32) arg1;
    func_02055b84(arg1[data_021041bc[row * ROW_SIZE]], slot << 4, NOTIFY_SIZE, row);
    M2C_FIELD(arg0, u32 *, 0x8) = M2C_FIELD(arg0, u32 *, 0x8) | OBJ_FLAG_REGISTERED;
}
