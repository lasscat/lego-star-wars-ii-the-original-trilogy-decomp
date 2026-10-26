#include "m2c.h"

M2C_UNK func_02003728(void *); /* extern */
M2C_UNK func_0200ee24();       /* extern */
extern M2C_UNK data_020fcf28;

/* Tears down the two embedded lists, marks three referenced entries with bit 1,
 * then runs the shared object cleanup. */
void *func_0200d954(void *object) {
    void **link_slot_828;
    void **link_slot_820;
    void *sentinel_828;
    void *sentinel_820;
    void *entry_810;
    void *entry_814;
    void *entry_818;
    void *node_828;
    void *node_820;

    M2C_FIELD(object, M2C_UNK **, 0) = &data_020fcf28;
    func_0200ee24();
    entry_810 = M2C_FIELD(object, void **, 0x810);
    if (entry_810 != NULL) {
        M2C_FIELD(entry_810, s32 *, 8) = (s32) (M2C_FIELD(entry_810, s32 *, 8) | 2);
    }
    entry_814 = M2C_FIELD(object, void **, 0x814);
    if (entry_814 != NULL) {
        M2C_FIELD(entry_814, s32 *, 8) = (s32) (M2C_FIELD(entry_814, s32 *, 8) | 2);
    }
    entry_818 = M2C_FIELD(object, void **, 0x818);
    if (entry_818 != NULL) {
        M2C_FIELD(entry_818, s32 *, 8) = (s32) (M2C_FIELD(entry_818, s32 *, 8) | 2);
    }
    link_slot_828 = M2C_FIELD(object, void ***, 0x828);
    if (link_slot_828 != NULL) {
        node_828     = *link_slot_828;
        sentinel_828 = object + 0x828;
        if (node_828 != sentinel_828) {
            do {
                link_slot_828 = node_828 + 4;
                node_828      = M2C_FIELD(node_828, void **, 4);
            } while (node_828 != sentinel_828);
        }
        *link_slot_828 = M2C_FIELD(object, void **, 0x82C);
    }
    link_slot_820 = M2C_FIELD(object, void ***, 0x820);
    if (link_slot_820 != NULL) {
        node_820     = *link_slot_820;
        sentinel_820 = object + 0x820;
        if (node_820 != sentinel_820) {
            do {
                link_slot_820 = node_820 + 4;
                node_820      = M2C_FIELD(node_820, void **, 4);
            } while (node_820 != sentinel_820);
        }
        *link_slot_820 = M2C_FIELD(object, void **, 0x824);
    }
    func_02003728(object);
    return object;
}
