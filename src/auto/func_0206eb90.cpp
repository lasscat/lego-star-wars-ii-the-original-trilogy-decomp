#include "m2c.h"

// Provisional partial interface for the class whose vtable is data_020fe990.
// Observed slots: 0x00 func_0206e948, 0x04 func_0206e968, 0x08 func_0206e990,
// 0x0c func_0206ea94, 0x10 func_0206eb64, 0x14 func_0205f160.
// Declarations only: the original vtable remains in the ROM data.
class DsEntity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
};

extern "C" s32 func_0205d0d0(M2C_UNK *, M2C_UNK, M2C_UNK);
extern "C" M2C_UNK data_021027f8;

extern "C" void func_0206eb90(DsEntity *obj) {
    if (func_0205d0d0(&data_021027f8, 1, 4) != 0 || func_0205d0d0(&data_021027f8, 2, 4) != 0) {
        M2C_FIELD(obj, s32 *, 0x68) = 4;
        obj->unknown0c();
    }
}
