#include "m2c.h"

typedef struct {
    u8 order[7];
} SlotOrder;

typedef struct {
    u8 pad0[0xC];
    s32 dataOffset;
    u8 pad10[2];
} ResInfo;

typedef struct {
    u8 pad0[0xE];
    u16 infoOffset;
} ResHeader;

typedef struct {
    void *unk0;
    void *unk4;
    ResHeader *res;
} SlotModel;

typedef struct {
    SlotModel *model;
    u8 pad4[0x24];
} Slot;

typedef struct {
    u8 pad0[0xDC];
    ResHeader *res;
    u8 padE0[0x1D0 - 0xE0];
    Slot slots[8];
} Owner;

extern SlotOrder data_020e5ca4;
void func_020c61e0(void *data, s32 mode, s32 flag);

static inline void set_res_mode(ResHeader *res, s32 mode) {
    ResInfo *info = (ResInfo *) ((u8 *) res + res->infoOffset);
    func_020c61e0((u8 *) res + info->dataOffset, mode, 0x400);
}

static inline void set_all_modes(Owner *owner, const u8 *order, s32 mode) {
    u32 i;

    set_res_mode(owner->res, mode);
    for (i = 0; i < 7; i++) {
        SlotModel *model = owner->slots[order[i]].model;
        if (model != NULL) {
            set_res_mode(model->res, mode);
        }
    }
}

void func_02005514(Owner *owner, s32 hide) {
    SlotOrder order = data_020e5ca4;

    if (hide != 0) {
        set_all_modes(owner, order.order, 0);
    } else {
        set_all_modes(owner, order.order, 1);
    }
}
