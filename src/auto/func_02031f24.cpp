#include "m2c.h"

// Result of the virtual call; the non-trivial copy constructor makes the
// compiler return this class type through an invisible reference (r0).
class AnalyzeResult {
public:
    s32 value;
    AnalyzeResult(const AnalyzeResult &other);
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class AnalyzeEntity {
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
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual AnalyzeResult unknown3c(u16 flag); // Slot 0x3c.
};

// The constructed object; the vtable pointer is written directly.
struct ConstructedObject {
    u32 *vptr;     // 0x00.
    void *field04; // 0x04.
    u8 pad08[4];   // 0x08..0x0b.
    u8 field0c;    // 0x0c.
    u8 field0d;    // 0x0d.
    u8 pad0e[2];   // 0x0e..0x0f.
    void *field10; // 0x10.
    void *field14; // 0x14.
    s32 field18;   // 0x18.
    u16 field1c;   // 0x1c.
    u16 field1e;   // 0x1e.
    u16 field20;   // 0x20.
};

extern "C" u32 data_020fdbc4[];
extern "C" u32 data_020fddcc[];

extern "C" ConstructedObject *func_02031f24(ConstructedObject *self, void *a1, s32 a2, void *a3, s32 a4, s32 a5, u16 a6, ...) {
    self->vptr           = data_020fdbc4;
    self->field04        = a1;
    self->field0c        = 0;
    self->field0d        = 0;
    self->vptr           = data_020fddcc;
    self->field10        = (void *) a2;
    self->field14        = *(void **) &a3;
    self->field18        = 0;
    self->field1c        = a6;
    self->field1e        = (u16) a4;
    self->field20        = (u16) a5;
    AnalyzeResult result = ((AnalyzeEntity *) self->field04)->unknown3c(self->field20);
    self->field18        = result.value;
    return self;
}
