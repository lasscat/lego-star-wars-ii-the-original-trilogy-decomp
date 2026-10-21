/* Reconstructed from USA ARM9 at 0x02004dec (400 bytes).
 *
 * func_02004dec(obj, other) clears a flag word of obj, marks obj in the global
 * table data_02109104 and, depending on the object's role byte, hands the
 * object's role to the manager behind data_02107860 (a counter bump, a
 * "not found" bump and a release).  It then either plays the object's
 * "active" animation (bit 0x10000000 of obj+0x8) or marks it idle.
 */
#include "m2c.h"

extern M2C_UNK data_02109104;
extern M2C_UNK data_02107860;
extern M2C_UNK data_0210930c;

extern s32 func_02093534();
extern void func_0209bca4(s32, u8);
extern void func_0209bcbc(s32, u8);
extern void func_0209d050(s32, u8);
extern void func_0209cf60(s32, u8);
extern void func_0202c498(void *, u8);
extern void func_0202c500(void *, u8);
extern void func_0202c2fc(s32);
extern void func_02090584(s32, u8, u8);
extern void func_02004b78();

void func_02004dec(void *arg0, void *arg1) {
    u8 v;
    s32 flag;
    s32 role;
    s32 idx;
    u16 kind;
    s32 x;
    /* The manager block is reached through the address of data_02107860; keeping
     * that address in a local lets the compiler keep it in a register. */
    void **sp;

    flag                                   = 1;
    M2C_FIELD(arg0, u16 *, 0x6B6)          = 0;
    v                                      = M2C_FIELD(arg0, u8 *, 0x6BB);
    M2C_FIELD(&data_02109104, u8 *, v * 2) = 1;
    role                                   = M2C_FIELD(arg0, u8 *, 0x5DA);
    if (role != 4) {
        sp = (void **) &data_02107860;
        if (M2C_FIELD(M2C_FIELD(sp, void **, 0), u8 *, 0x50) != 0) {
            if (arg1 != NULL) {
                idx = func_02093534(&data_0210930c, arg1);
                if (idx != -1) {
                    flag = 0;
                    func_0209bca4(M2C_FIELD(sp, void **, 0), (u8) idx);
                } else {
                    kind = M2C_FIELD(arg1, u16 *, 0xC);
                    if (kind == 0x10) {
                        x = M2C_FIELD(arg1, s32 *, 0x1BC);
                        if (x < 4) {
                            flag = 0;
                            func_0209bca4(M2C_FIELD(sp, void **, 0), (u8) x);
                        }
                    } else if (kind == 0x8000) {
                        x = M2C_FIELD(arg1, s32 *, 0x1BC);
                        if (x < 4) {
                            flag = 0;
                            func_0209bca4(M2C_FIELD(sp, void **, 0), (u8) x);
                        }
                    }
                }
            }
            func_0209bcbc(M2C_FIELD(sp, void **, 0), (u8) role);
            if (M2C_FIELD(M2C_FIELD(sp, void **, 0), s32 *, 0x10) != 0) {
                if (flag != 0) {
                    func_0209d050(M2C_FIELD(M2C_FIELD(sp, void **, 0), s32 *, 0x10), (u8) role);
                }
                func_0209cf60(M2C_FIELD(M2C_FIELD(sp, void **, 0), s32 *, 0x10), (u8) role);
            }
        }
    }

    if ((M2C_FIELD(arg0, u32 *, 0x8) & 0x10000000) == 0x10000000) {
        M2C_FIELD(arg0, u16 *, 0x1A8) |= 0x10;
        func_0202c498((u8 *) arg0 + 0x5E0, 0xB);
        func_0202c500((u8 *) arg0 + 0x5E0, 7);
        func_0202c2fc((u8 *) arg0 + 0x5E0);
        func_02090584(M2C_FIELD(&data_0210930c, M2C_UNK *, 0x68), M2C_FIELD(arg0, u8 *, 0x6BD), M2C_FIELD(arg0, u8 *, 0x6BC));
    } else {
        M2C_FIELD(arg0, s32 *, 0x8) |= 0x800;
        func_0202c2fc((u8 *) arg0 + 0x5E0);
        func_02004b78(arg0, 5);
    }
}
