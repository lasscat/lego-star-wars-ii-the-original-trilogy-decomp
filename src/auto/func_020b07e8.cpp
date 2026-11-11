#include "m2c.h"

enum {
    SLOT_BITMAP     = 0x66, // u16 slot bitmap in the block returned by vtable slot 0x00
    BLOCK_MORE      = 0x6c, // byte that func_020b062c sets when a list does not fit in one pass
    BUFFER_BYTES    = 0x60, // 0x18 words: the most func_020b062c copies in one pass
    SIZE_DEFAULT    = 0xff, // func_020b04f0 size value meaning "use default"
    DEFAULT_PAYLOAD = 0x1c, // payload size func_020b04f0 uses for SIZE_DEFAULT
};

// One record list: 0x340 bytes of records and the count byte, in words, that
// func_020b062c and func_020b070c advance.
struct Slot {
    u8 data[0x340];
    u8 count;
    u8 pad[3];
};

// The object at data_0210794c (same layout as the Obj views in
// func_020b04f0.c and func_020b070c.c).
struct Obj {
    u8 pad0[0x6a];
    u16 mask;    // 0x6a: slot bitmap cached by func_020b07e8
    u8 pad6c[4];
    Slot a[3];   // 0x70: outgoing lists; func_020b04f0 appends to a[0]
    Slot b[4];   // 0xa3c: incoming lists, one per block index
    u8 limit[3]; // 0x174c: words filled in a[0..2]
};

// Partial interface: only the observed vtable slots are declared.
// Declarations only: the original vtable remains in the ROM data.
class DispatcherTile {
public:
    virtual u8 *unknown00(s32 index); // Slot 0x00: returns the block of one index.
    virtual u8 *unknown04();          // Slot 0x04: returns the buffer pointer.
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual s32 unknown1c(); // Slot 0x1c.
};

// The words at data_021092f4: the object pointer, which is all the other
// translation units declare, and at +8 the last func_020b0bdc() result.
struct HolderB07E8 {
    DispatcherTile *obj;
    s32 unk4;
    s32 result;
};

// Only the two words written here are named.
struct TargetB07E8 {
    u8 pad00[0x64];
    s32 unk64;
    u8 pad68[0x1c];
    s32 unk84;
};

extern "C" {
extern HolderB07E8 data_021092f4;
extern Obj data_0210794c;
extern s32 data_027e02a4;
extern s32 data_027e02a8;
extern TargetB07E8 data_02102900;

extern s32 func_0207300c(void);
extern s32 func_02073034(void);
extern s32 func_02073044(void);
extern void func_02073054(s32 arg0);
extern s32 func_020ad1c8(void *arg0);
extern void func_020ad30c(void *arg0);
extern void func_02072cd0(void);
extern void func_020b02c8(void *arg0);
extern void func_020b04f0(void *obj, u8 id, void *src, u8 size);
extern void func_020b062c(void *unused, u8 *list, u8 *limit);
extern void func_020b070c(Obj *self);
extern s32 func_020b0bdc(void);
extern void *func_0205e624(void *dst, u32 value, u32 size);
extern s32 func_0205e6e0(void *dst, void *src, u32 size);
extern void func_0205ecc4(void *arg0, u32 arg1, u32 arg2, u32 arg3, s32 arg4, s32 arg5);

// Runs one exchange pass on the record lists of `self`; func_020013a4 calls it
// with &data_0210794c.
//
// a[] are the outgoing lists.  func_020b04f0 appends records to a[0] and counts
// the words written in limit[0]; func_020b062c copies a list into the buffer
// of vtable slot 0x04, at most 0x18 words per call, and counts the words
// copied in the list's count byte.  b[] are the incoming lists, which
// func_020b070c fills from the blocks that vtable slot 0x00 returns.
//
// 1. Empty the four b[] lists.  Nothing else happens without an object in
//    data_021092f4.
// 2. If func_0207300c() is nonzero, count the set bits among the low four of
//    the slot bitmap and store that count through func_02073054() when it is
//    below func_02073044().  If func_02073034() changed and vtable slot 0x1c
//    returns zero, queue a record of kind 0x13 holding func_02073034() and
//    func_02073044().  The bitmap is then cached in self->mask.
// 3. Copy the next part of one a[] list into the buffer: the highest list that
//    is partly copied, else a[0].  The func_020b0bdc() result (the return
//    value of vtable slot 0x0c) is kept at data_021092f4 + 8, func_020b070c()
//    collects the incoming records, and the first 0x60 bytes and byte 0x6c of
//    the buffer are cleared.  The pass is repeated while the object exists and
//    any block up to the highest bitmap bit has its byte 0x6c set
//    (func_020b062c sets the same byte in the buffer when a list does not fit
//    in one pass).
// 4. Age the a[] lists: a[2] is emptied, a list that was not copied out
//    completely moves up one place, a finished one is emptied, and a[0] is
//    always left empty.
// 5. If the last func_020b0bdc() result was nonzero, clear bit data_027e02a4
//    of data_027e02a8, call func_02072cd0() (its callee func_02072bc8 releases
//    the object and zeroes data_021092f4), make two func_0205ecc4 calls on
//    data_02102900 and set its words at 0x84 and 0x64 to 1.
void func_020b07e8(Obj *self) {
    for (u8 i = 0; i < 4; i++) {
        func_020b02c8(&self->b[i]);
    }
    if (data_021092f4.obj == 0) {
        return;
    }
    if (func_0207300c() != 0) {
        u8 i;
        u8 bits = 0;
        u8 old  = func_02073034();
        for (i = 0; i < 4; i++) {
            if (*(u16 *) (data_021092f4.obj->unknown00(0) + SLOT_BITMAP) & (1 << i)) {
                bits++;
            }
        }
        if (bits < func_02073044()) {
            func_02073054(bits);
        }
        if (old != func_02073034()) {
            if (data_021092f4.obj->unknown1c() == 0) {
                u8 payload[DEFAULT_PAYLOAD];
                payload[1] = func_02073044();
                payload[0] = func_02073034();
                func_020b04f0(&data_0210794c, 0x13, payload, SIZE_DEFAULT);
            }
        }
        self->mask = *(u16 *) (data_021092f4.obj->unknown00(0) + SLOT_BITMAP);
    }
    u8 again;
    do {
        again = 0;
        for (s8 k = 2; k >= 0; k--) {
            if ((self->a[k].count != 0 && self->a[k].count < self->limit[k]) || k == 0) {
                func_020b062c(self, self->a[k].data, &self->limit[k]);
                break;
            }
        }
        // func_020ad30c is an empty function.
        func_020ad30c(data_021092f4.obj->unknown04());
        data_021092f4.result = func_020b0bdc();
        func_020ad30c(data_021092f4.obj->unknown00(0));
        func_020b070c(self);
        if (data_021092f4.obj != 0) {
            func_0205e624(data_021092f4.obj->unknown04(), 0, BUFFER_BYTES);
            data_021092f4.obj->unknown04()[BLOCK_MORE] = 0;
        }
        for (u8 i = 0; i <= func_020ad1c8(data_021092f4.obj->unknown00(0)); i++) {
            if (data_021092f4.obj->unknown00(i)[BLOCK_MORE] != 0) {
                again = 1;
            }
        }
    } while (data_021092f4.obj != 0 && again != 0);

    self->limit[2] = 0;
    func_020b02c8(&self->a[2]);
    for (s8 k = 1; k >= 0; k--) {
        if (self->a[k].count < self->limit[k]) {
            self->limit[k + 1] = self->limit[k];
            func_0205e6e0(&self->a[k + 1], &self->a[k], sizeof(Slot));
        } else {
            self->limit[k] = 0;
            func_020b02c8(&self->a[k]);
        }
    }
    self->limit[0] = 0;
    func_020b02c8(&self->a[0]);

    if (data_021092f4.result == 0) {
        return;
    }
    data_027e02a8 &= ~(1 << data_027e02a4);
    func_02072cd0();
    func_0205ecc4(&data_02102900, 0xf, 0, 0, 0, 0);
    func_0205ecc4(&data_02102900, 0x26, 1, 0, 3, 0);
    data_02102900.unk84 = 1;
    data_02102900.unk64 = 1;
}
}
