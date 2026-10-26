#include "m2c.h"

M2C_UNK *func_0205e818(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0205e860(M2C_UNK *);              /* extern */
M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);                                    /* extern */
M2C_UNK func_02088b84(M2C_UNK *, u8);                          /* extern */
M2C_UNK func_020917b4(M2C_UNK *);                              /* extern */
s32 func_020cf708(M2C_UNK *, s32, M2C_UNK *, M2C_UNK, void *); /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104df4;
extern void **data_021092f4;
extern M2C_UNK data_0210930c;

/* Resets the resource state on the screen object, tries to set up the
 * 0x2A6C-byte component, and falls back to the shared resource on failure. */
void func_020733b4(void *screen) {
    s32 setup_result;

    M2C_FIELD(screen, s32 *, 0x98)      = 0;
    M2C_FIELD(screen, s8 *, 0xE0AE)     = 0;
    M2C_FIELD(screen, s8 *, 0xE0AF)     = 0;
    M2C_FIELD(screen, s8 *, 0xE0A8)     = 0;
    M2C_FIELD(screen, s16 *, 0xE0AA)    = 0;
    M2C_FIELD(screen, s16 *, 0xE0AC)    = 0;
    M2C_FIELD(screen, M2C_UNK **, 0xA0) = NULL;
    M2C_FIELD(screen, M2C_UNK **, 0x9C) = &data_02104df4;
    if (M2C_FIELD(*data_021092f4, s32(**)(), 0x1C)(data_021092f4) == 0) {
        func_02088b84(&data_02104df4, func_020917b4(&data_0210930c));
        M2C_FIELD(screen, s32 *, 0xA4)      = 0x2A6C;
        M2C_FIELD(screen, M2C_UNK **, 0xA0) = func_0205e818(0x2A6C, 3, 4);
        setup_result                   = func_020cf708(M2C_FIELD(screen, M2C_UNK **, 0x9C), M2C_FIELD(screen, s32 *, 0xA4),
                                                       M2C_FIELD(screen, M2C_UNK **, 0xA0), 4, screen + 0xA8);
        M2C_FIELD(screen, s32 *, 0xA4) = setup_result;
        if (setup_result == 0) {
            func_0205e860(M2C_FIELD(screen, M2C_UNK **, 0xA0));
            M2C_FIELD(screen, M2C_UNK **, 0xA0) = (M2C_UNK *) M2C_FIELD(screen, M2C_UNK **, 0x9C);
            M2C_FIELD(screen, s32 *, 0xA4)      = 0x2A6C;
        }
    }
    func_0205ecc4(&data_02102900, 0xF, 0, 0, 0, 0);
}
