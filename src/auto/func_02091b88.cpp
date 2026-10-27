#include "m2c.h"

extern "C" {
void *func_0205e80c(s32, s32, s32);
void *func_0200d6f4(void *, s32, s32, s32, s32, void *);
void func_020accac(void *, s32, void *, void *);
s32 func_0204a880(void *);
void func_0202c498(void *, u8);
void func_0202c500(void *, s32);
void func_0202c440(void *, s32);
void *func_020aaeb4(void);
void func_020a0370(void *, void *);

extern u8 data_020ee898[];
extern u8 data_020ee899[];
typedef struct Entry {
    u8 pad[2];
    u8 auxiliary_selector;
    u8 pad2[0x15];
} Entry;
extern Entry data_020ef57c[];
extern u8 data_020ff064[];
extern void **data_021092f4;
extern u32 data_027e02a8;
}
class Obj {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void fn24(s32, s32, s32, s32);
};

static inline void dispatch_setup(Obj *o) {
    o->fn24(0, 1, 1, 0);
}

enum {
    ENTITY_BYTES                = 0x834,
    ENTITY_ALIGNMENT            = 4,
    CONSTRUCTION_UNIT_COMPONENT = 0x1000,
    PRIOR_ENTITY_FLAG           = 2,
    AUXILIARY_A_DISABLED        = 0xB,
    AUXILIARY_B_DISABLED        = 7,
    SELECTED_SLOT_MODE          = 0x40,
    SPECIAL_ENTITY_BASE         = 0x54,
    SPECIAL_ENTITY_STRIDE       = 12
};

typedef struct Holder {
    u8 pad[0x4C];
    void *slots[4];
} Holder;

/* Create an entity in the requested holder slot, optionally replacing its prior
 * occupant. Callers pass a position vector and an entity selector; the returned
 * pointer is also installed in the slot. Replacement preserves the value returned
 * by the old entity's slot-0x08 method, marks that entity with flag 2, and detaches
 * it from the holder before construction. The preserved value becomes the new
 * entity's field at +0x1B4; the method and field's precise purpose remain unknown.
 *
 * Configure the new entity's auxiliary objects from its type tables, select it in
 * the shared manager when this slot is active, then invoke its slot-0x24 setup
 * method. The caller must provide a valid slot and usable allocation; subsequent
 * setup dereferences the allocation even if the allocation helper returned NULL.
 */
extern "C" void *func_02091b88(Holder *holder, s32 slot_index, s32 entity_selector, s32 source_position, u8 replace_existing) {
    u16 zero_components[3];
    s32 unit_components[3];
    u8 construction_record[0x48];
    s32 preserved_value;
    void *entity;
    s32 use_selected_slot;
    s32 auxiliary_selector;
    void *related_object;

    preserved_value = -1;
    if (holder->slots[slot_index] != NULL && replace_existing != 0) {
        func_020aaeb4();
        related_object  = holder->slots[slot_index];
        preserved_value = M2C_FIELD(*(void **) related_object, s32(**)(void *), 8)(related_object);
        related_object  = holder->slots[slot_index];
        M2C_FIELD(related_object, s32 *, 8) |= PRIOR_ENTITY_FLAG;
        holder->slots[slot_index] = NULL;
    }
    entity = func_0205e80c(ENTITY_BYTES, 0, ENTITY_ALIGNMENT);
    if (entity != NULL) {
        unit_components[0] = CONSTRUCTION_UNIT_COMPONENT;
        unit_components[1] = CONSTRUCTION_UNIT_COMPONENT;
        unit_components[2] = CONSTRUCTION_UNIT_COMPONENT;
        zero_components[0] = 0;
        zero_components[1] = 0;
        zero_components[2] = 0;
        func_020accac(construction_record, source_position, zero_components, unit_components);
        entity = func_0200d6f4(entity, 1, entity_selector, slot_index, 0, construction_record);
    }
    if (func_0204a880((u8 *) entity + 0x5CE) != 0) {
        func_0202c498((u8 *) entity + 0x5E0, AUXILIARY_A_DISABLED);
        func_0202c500((u8 *) entity + 0x5E0, AUXILIARY_B_DISABLED);
    } else {
        func_0202c498((u8 *) entity + 0x5E0, data_020ee898[M2C_FIELD(entity, u8 *, 0x6BB) * 4]);
        func_0202c500((u8 *) entity + 0x5E0, data_020ee899[M2C_FIELD(entity, u8 *, 0x6BB) * 4]);
        related_object = M2C_FIELD(entity, void **, 0x5FC);
        if (related_object != NULL) {
            M2C_FIELD(related_object, u8 *, 0xA) = 0;
        }
    }
    /* The base table selects which entities use the secondary table's zero test
     * to choose auxiliary configuration 1 instead of 0. */
    auxiliary_selector = 0;
    if (data_020ef57c[M2C_FIELD(entity, u8 *, 0x6BB)].auxiliary_selector == 2) {
        if (data_020ff064[(M2C_FIELD(entity, u8 *, 0x6BB) - SPECIAL_ENTITY_BASE) * SPECIAL_ENTITY_STRIDE] == 0) {
            auxiliary_selector = 1;
        }
    }
    func_0202c440((u8 *) entity + 0x5E0, auxiliary_selector);
    /* Mode bit 0x40 selects the global slot query; otherwise slot zero is active. */
    use_selected_slot = (data_027e02a8 & SELECTED_SLOT_MODE) != 0;
    if ((use_selected_slot != 0 && slot_index == M2C_FIELD(*data_021092f4, s32(**)(void *), 0x1C)(data_021092f4)) ||
        (use_selected_slot == 0 && slot_index == 0)) {
        func_020a0370(func_020aaeb4(), entity);
    }
    dispatch_setup((Obj *) entity);
    holder->slots[slot_index] = entity;
    if (preserved_value != -1) {
        M2C_FIELD(holder->slots[slot_index], s32 *, 0x1B4) = preserved_value;
    }
    return entity;
}
