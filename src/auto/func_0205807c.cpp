#include "m2c.h"

// Slot table of the spawned node class.  It stays in the ROM data area at
// 0x020ff2a0; only its address is taken here.
extern "C" void *data_020ff2a0[];

// Global pointer table at 0x02106d90.
extern "C" u8 data_02106d90[];

// Position triple.  The assignment operator carries the self check that the
// original code performs before it copies the triple into the node.
class Vec35807C {
public:
    s32 x;
    s32 y;
    s32 z;
    Vec35807C &operator=(const Vec35807C &other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
};

// Partial interface of the spawned node: the methods live in the slot table
// above.  Declarations only, so no vtable is emitted here.  The padding
// reproduces the observed layout of the 0x40 byte object.
class SpawnNode {
public:
    virtual void unknown00();
    virtual void unknown04();
    u8 pad04[0x0c];
    u32 field10;
    u8 pad14[0x14];
    Vec35807C position;
    u32 field34;
    u32 field38;
    u32 field3c;
};

// Partial interface of the scene object; slot 0x24 is the only one used here.
class SceneObject {
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
    virtual void unknown24(u8, int, int, int);
};

extern "C" SceneObject *func_02067080(void *, u8, u8);
extern "C" void *func_0205e80c(s32, s32, s32);
extern "C" void func_0202d934(void *, void *, u8, u8, s32);
extern "C" void func_0207f6b8(void *, void *, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_0207f56c(void *, void *);

extern "C" void func_0205807c(void *obj, void *arg) {
    Vec35807C v;
    SceneObject *scene = func_02067080(obj, M2C_FIELD(arg, u8 *, 6), M2C_FIELD(arg, u8 *, 7));
    s32 vz             = M2C_FIELD(arg, s16 *, 4) << 12;
    s32 vy             = M2C_FIELD(arg, s16 *, 2) << 12;
    s32 vx             = M2C_FIELD(arg, s16 *, 0) << 12;
    v.x                = vx;
    v.y                = vy;
    v.z                = vz;
    if (scene == 0) {
        return;
    }
    if (M2C_FIELD(scene, u16 *, 0xc) & 3) {
        // The original code writes -4096 into a stack slot that it never
        // reads back; volatile keeps the store alive.
        volatile s32 unused = -4096;
        func_0202d934(scene, &v, M2C_FIELD(arg, u8 *, 8), M2C_FIELD(arg, u8 *, 9), -4096);
        return;
    }
    SpawnNode *node = (SpawnNode *) func_0205e80c(64, 3, 4);
    if (node) {
        // The node is built in place: the slot table pointer is stored into
        // the object instead of being emitted by a constructor.
        *(void **) node  = (void *) data_020ff2a0;
        node->field10    = 0;
        node->position.x = 0;
        node->position.y = 0;
        node->position.z = 0;
        node->field34    = 0;
        node->field38    = 0;
        node->field3c    = 0;
    }
    node->unknown04();
    // Same as above: 4096 is written into a stack slot that is not read.
    volatile s32 unused2 = 4096;
    func_0207f6b8(node, scene, -1, 1, -1, 4096, 0, 0, 0, M2C_FIELD(arg, u8 *, 9));
    node->position = v;
    func_0207f56c(*(void **) (data_02106d90 + 0xad8), node);
    if (M2C_FIELD(scene, u32 *, 8) & 0x100000) {
        scene->unknown24(M2C_FIELD(arg, u8 *, 8), 1, 1, 0);
    }
}
