/* Reconstructed from USA ARM9 at 0x020aeed0 (248 bytes).
 * WH_StateInMeasureChannel: pick the first usable radio channel.
 */
#include "m2c.h"

extern M2C_UNK data_021003ec; /* "WH_STATEINMEASURECHANNEL - WM_ERRCODE_ILLEGAL_STATE" */
extern M2C_UNK data_02100424; /* "WH_STATEINMEASURECHANNEL - WH_ERRCODE_NO_RADIO" */
extern M2C_UNK data_02100454; /* "WH_STATEINMEASURECHANNEL - %d" */
extern M2C_UNK data_02100474; /* "Exiting WH_StateInMeasureChannel" */
extern M2C_UNK data_0210b320;

u16 WM_GetAllowedChannel(void);
void func_020ad7a4(s32);
void func_020ad8b4(s32);
void func_020ad528(void *, ...);
s32 func_020af088(void *, u16);
void func_020aefc8(void *);

u16 func_020aeed0(u16 channel) {
    u32 allowed;
    u16 ch;
    s32 measured;

    M2C_FIELD(&data_0210b320, s32 *, 0x48) = 0x18;
    allowed                                = WM_GetAllowedChannel();
    if (allowed == 0x8000) {
        func_020ad8b4(3);
        func_020ad528(&data_021003ec);
        func_020ad7a4(9);
        return 3;
    }
    if (allowed == 0) {
        func_020ad8b4(0x16);
        func_020ad528(&data_02100424);
        func_020ad7a4(9);
        return 0x18;
    }
    ch = channel;
    while ((allowed & (1 << (ch - 1))) == 0) {
        ch = ch + 1;
        if (ch > 0x10) {
            return 0x18;
        }
    }
    measured = func_020af088(func_020aefc8, ch);
    if (measured != 2) {
        func_020ad528(&data_02100454, measured);
        return measured;
    }
    func_020ad528(&data_02100474);
    return measured;
}
