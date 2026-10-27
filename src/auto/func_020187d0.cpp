#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class C187D0Object {
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
    // Slot 0x24. Its base implementation, func_020107c8, looks the first argument up as a key in
    // the data_020eb7b8 entry chosen by the u16 at +0x180 and forwards a hit to slot 0x28 with
    // the other three arguments.
    virtual void unknown24(s32, s32, s32, u8);
};

typedef struct {
    u16 v;
} Angle;

// Three 16-bit angles built on the stack; only the third one is passed on.
typedef struct {
    Angle a, b, c;
} Rot;

extern "C" {
M2C_UNK func_02001990(void *, M2C_UNK);
void *func_0200fe94(void *, M2C_UNK, s32, M2C_UNK, s32);
void func_020107c8(void *, s32, s32, s32, s32);
void *func_02018420(void *, s32);
void func_020186ec(void *, void *, Angle);

// Per-type records in .rodata: a u16 data_020eb7b8 index at +0 and a flag byte at +0xA
// (data_020f4d16). const matters: the base call's stack argument may then be stored after the
// record load, as in the original prologue.
extern const u8 data_020f4d0c[];
extern const u8 data_020f4d16[];
extern M2C_UNK data_020fd060;
extern u8 data_02101ae4[];
extern M2C_UNK func_02019418;
extern M2C_UNK func_02019450;
extern M2C_UNK func_02019498;
}

enum {
    RECORD_SIZE = 12, // stride of the per-type records at data_020f4d0c
};

/* Constructor-shaped initializer for the class whose vtable is data_020fd060. recordIndex selects
 * the per-type record at data_020f4d0c (kept at +0x1C3, where func_02018ad8 reads the same
 * records). The shared base initializer func_0200fe94 gets the record's data_020eb7b8 index
 * (applied unless it is 0x276) and forwards initialConfig to func_02017908, which copies it into
 * the transform at +0x8C. Then this class's defaults are set, three of the base's no-op hooks are
 * replaced, func_02001990(self, 1) hands the object once to slot 0x08 of the manager selected by
 * data_027e02a4, and two record flag bits are copied into the +8 flags. Some records acquire
 * entries from the data_02101ae4 pool: func_02018420 reuses an existing entry of that kind
 * (raising its u16 use count) unless byte 0 of the kind's data_020e5d08 record is set, else it
 * creates one. Finally the base slot-0x24 routine func_020107c8 runs with key 0x2C for record 8,
 * else 0. Returns self.
 */
extern "C" void *func_020187d0(C187D0Object *self, s32 recordIndex, s32 arg2, s32 flag, M2C_UNK a4, s32 initialConfig,
                               s32 a6) {
    func_0200fe94(self, 0x10, *(const u16 *) &data_020f4d0c[recordIndex * RECORD_SIZE], a4, initialConfig);
    M2C_FIELD(self, M2C_UNK **, 0) = &data_020fd060;
    // The func_02019498 hook ignores other objects whose byte at +0x5DA equals this value.
    M2C_FIELD(self, s32 *, 0x1bc) = 4;
    M2C_FIELD(self, u8 *, 0x1c0)  = 0;
    M2C_FIELD(self, u8 *, 0x1c1)  = 0; // all three hooks below return early while this is set
    M2C_FIELD(self, u8 *, 0x1c2)  = flag != 0; // the func_02019450 hook branches on it
    M2C_FIELD(self, u8 *, 0x1c3)  = recordIndex;
    M2C_FIELD(self, u8 *, 0x1c4)  = arg2;
    // Declared here, not at the switch: the placement decides the register allocation.
    s32 lookupKey                 = 0;
    M2C_FIELD(self, u16 *, 0x1c6) = 0;
    // +0x1C8/+0x1CC receive pool entries in the switch; +0x1D0 receives a6 for record 8.
    M2C_FIELD(self, s32 *, 0x1c8) = 0;
    M2C_FIELD(self, s32 *, 0x1cc) = 0;
    M2C_FIELD(self, s32 *, 0x1d0) = 0;
    M2C_FIELD(self, s32 *, 0x84)  = flag != 0 ? 5 : 6; // base default (func_02017908) is 0x1D
    M2C_FIELD(self, u16 *, 0x1a8) = M2C_FIELD(self, u16 *, 0x1a8) | 0x1000;
    // func_02017908 put the empty func_020179b0 in all four hooks; the +0x14 one stays empty.
    M2C_FIELD(self, M2C_UNK **, 0x10) = &func_02019418;
    M2C_FIELD(self, M2C_UNK **, 0x18) = &func_02019450;
    M2C_FIELD(self, M2C_UNK **, 0x1c) = &func_02019498;
    func_02001990(self, 1);
    if (data_020f4d16[M2C_FIELD(self, u8 *, 0x1c3) * RECORD_SIZE] & 4) {
        M2C_FIELD(self, u32 *, 8) |= 0x100;
    }
    if (data_020f4d16[recordIndex * RECORD_SIZE] & 2) {
        M2C_FIELD(self, u32 *, 8) |= 0x20;
    }
    switch (recordIndex) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 10:
        case 12:
            M2C_FIELD(self, void **, 0x1c8) = func_02018420(data_02101ae4, 0);
            break;
        case 7:
            M2C_FIELD(self, void **, 0x1c8) = func_02018420(data_02101ae4, 1);
            M2C_FIELD(self, void **, 0x1cc) = func_02018420(data_02101ae4, 2);
            self->unknown24(0x8a, 1, 1, 0); // through the vtable, unlike the final call
            break;
        case 8:
            M2C_FIELD(self, s32 *, 0x1d0) = a6;
            lookupKey                     = 0x2c;
            break;
        case 9: {
            Rot rot;
        // Place the kind-3 entry at the transform position (+0xB0) with an angle of
        // rotation[1] (+0xCA) minus 0x4000; func_020186ec copies both into the entry's state,
        // flagging the ones that change.
            M2C_FIELD(self, void **, 0x1c8) = func_02018420(data_02101ae4, 3);
            rot.c.v                         = M2C_FIELD(self, u16 *, 0xca) - 0x4000;
            rot.b.v                         = 0x4000;
            rot.a.v                         = 0x4000;
            func_020186ec(M2C_FIELD(self, void **, 0x1c8), (u8 *) self + 0xb0, rot.c);
            break;
        }
    }
    func_020107c8(self, lookupKey, 1, 1, 0);
    return self;
}
