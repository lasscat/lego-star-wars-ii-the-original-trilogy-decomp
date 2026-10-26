#include "m2c.h"

M2C_UNK func_02010a24(void *, u16);           /* extern */
s32 func_0205c324();                          /* extern */
M2C_UNK func_0205c628(s32, M2C_UNK);          /* extern */
s32 func_0205e80c(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0209f55c(s32, u16);              /* extern */
extern M2C_UNK data_020eb7b8;

/* Apply a selected table record: configure the +0xD4 component, ensure the
 * optional 0x30-byte control block, then copy fields from the nested +0xDC
 * record. The meanings of those record fields are not established here.
 */
void func_020100ec(void *self, void *tableEntry, s32 entryIndex) {
    s32 controlBlock;
    void *nestedRecord;
    void *selectedRecord;

    func_0209f55c(self + 0xD4, M2C_FIELD(tableEntry, u16 *, 4));
    if ((M2C_FIELD(self, u16 *, 0xC) != 0x40) && (M2C_FIELD(self, s32 *, 0x190) == 0)) {
        controlBlock = func_0205e80c(0x30, 0, 4);
        if (controlBlock != 0) {
            controlBlock = func_0205c324();
        }
        M2C_FIELD(self, s32 *, 0x190) = controlBlock;
        func_02010a24(self, M2C_FIELD(*((M2C_UNK *) ((s8 *) &data_020eb7b8 + (entryIndex * 8))), u16 *, 4));
        if (M2C_FIELD(self, u16 *, 0xC) & 3) {
            func_0205c628(M2C_FIELD(self, s32 *, 0x190), 1);
        }
    }
    nestedRecord                  = M2C_FIELD(self, void **, 0xDC);
    selectedRecord                = nestedRecord + M2C_FIELD((nestedRecord + M2C_FIELD(nestedRecord, u16 *, 0xE)), s32 *, 0xC);
    M2C_FIELD(self, s32 *, 0x1A4) = (s32) M2C_FIELD(selectedRecord, s32 *, 0x38);
    M2C_FIELD(self, s16 *, 0x198) = (s16) M2C_FIELD(selectedRecord, s16 *, 0x2C);
    M2C_FIELD(self, s16 *, 0x19A) = (s16) M2C_FIELD(selectedRecord, s16 *, 0x2E);
    M2C_FIELD(self, s16 *, 0x19C) = (s16) M2C_FIELD(selectedRecord, s16 *, 0x30);
    M2C_FIELD(self, s16 *, 0x19E) = (s16) M2C_FIELD(selectedRecord, s16 *, 0x32);
    M2C_FIELD(self, s16 *, 0x1A0) = (s16) M2C_FIELD(selectedRecord, s16 *, 0x34);
    M2C_FIELD(self, s16 *, 0x1A2) = (s16) M2C_FIELD(selectedRecord, s16 *, 0x36);
    M2C_FIELD(self, u16 *, 0x1A8) = (u16) (M2C_FIELD(self, u16 *, 0x1A8) | 1);
}
