#include "m2c.h"

extern "C" void func_020af3a8(void *);
extern "C" void *func_020ad1a4(void *);
extern "C" M2C_UNK data_02100668;

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data.
 *
 * Class of the object built by func_020af214.  Its vtable lives at
 * data_02100668 (ten slots, 0x00..0x24); slot 0x04 returns the sub object
 * at offset 0x640 and slot 0x14 is the post construction hook.
 */
class OwnerAF214 {
public:
    virtual void unknown00();
    virtual OwnerAF214 *unknown04(); // SlotAF214 0x04.
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14(); // SlotAF214 0x14.
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
};

/* SlotAF214 entry of the array at offset 0x6b4. */
struct SlotAF214 {
    u32 head;
    u32 tail;
};

extern "C" OwnerAF214 *func_020af214(OwnerAF214 *self) {
    /* Install the vtable of the original class by hand. */
    M2C_FIELD(self, void **, 0) = (void *) &data_02100668;
    /* Construct the two sub objects of this class. */
    func_020af3a8((u8 *) self + 4);
    func_020ad1a4((u8 *) self + 0x640);
    /* Clear the tail word of the eight slots at offset 0x6b4. */
    SlotAF214 *p = (SlotAF214 *) ((u8 *) self + 0x6b4);
    do {
        p->tail = 0;
        p++;
    } while (p < (SlotAF214 *) ((u8 *) self + 0x6f4));
    self->unknown14();
    return self;
}
