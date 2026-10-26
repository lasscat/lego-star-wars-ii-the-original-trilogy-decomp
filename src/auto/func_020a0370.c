#include "m2c.h"

M2C_UNK func_020aa7c0(void *, void *);                       /* extern */
void *func_020aa8f0(void *, void *, M2C_UNK, s32, s32, s32); /* extern */

/* Update the manager's entity pointer and cached three-word region, process its
 * prior node, then create a node from entity+0xB0 and copy the manager's 0x2BC
 * vector into it. */
void func_020a0370(void *manager, void *entity) {
    void *newNode;
    void *temp_r1;
    void *newNodeVector;

    temp_r1                            = entity + 0xB0;
    M2C_FIELD(manager, void **, 0x1D0) = entity;
    if ((manager + 0x1D8) != temp_r1) {
        M2C_FIELD(manager, s32 *, 0x1D8) = (s32) M2C_FIELD(temp_r1, s32 *, 0);
        M2C_FIELD(manager, s32 *, 0x1DC) = (s32) M2C_FIELD(temp_r1, s32 *, 4);
        M2C_FIELD(manager, s32 *, 0x1E0) = (s32) M2C_FIELD(temp_r1, s32 *, 8);
    }
    temp_r1 = M2C_FIELD(manager, void **, 0x1D4);
    if (temp_r1 != NULL) {
        func_020aa7c0(manager, temp_r1);
    }
    newNode                            = func_020aa8f0(manager, entity + 0xB0, 6, 0, 0xFF, 0);
    newNodeVector                      = newNode + 0x10;
    M2C_FIELD(manager, void **, 0x1D4) = newNode;
    if (newNodeVector == (manager + 0x2BC)) {
        return;
    }
    M2C_FIELD(newNodeVector, s32 *, 0) = (s32) M2C_FIELD(manager, s32 *, 0x2BC);
    M2C_FIELD(newNodeVector, s32 *, 4) = (s32) M2C_FIELD(manager, s32 *, 0x2C0);
    M2C_FIELD(newNodeVector, s32 *, 8) = (s32) M2C_FIELD(manager, s32 *, 0x2C4);
}
