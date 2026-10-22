/* C++ hypothesis for USA ARM9 at 0x020af274 (180 bytes) - MATCHES.
 *
 * func_020af274 is the virtual method in slot 0x14 of the class whose vtable
 * lives at data_02100668 (the same class as src/auto/func_020af214.cpp, whose
 * constructor calls this method as its post construction hook).  The method
 * clears four memory blocks of the object, resets several flags, reads the
 * RTC and finally calls the virtual method in slot 0x04 (func_020af328,
 * "self + 0x640") and passes its result together with a value built from the
 * RTC time to the empty function func_020ad218.
 *
 * Partial interface: unknown methods keep their observed vtable slots; the
 * original vtable stays in the ROM data.
 */
#include "m2c.h"

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

extern "C" void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern "C" s32 RTC_GetTime(RTCTime *time);
extern "C" void func_020ad218(void *a, u32 b);
extern "C" u8 data_02104344;

class OwnerAF214 {
public:
    virtual void unknown00();
    virtual OwnerAF214 *unknown04(); /* Slot 0x04: returns self + 0x640. */
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
};

extern "C" void func_020af274(OwnerAF214 *self) {
    u8 *base = (u8 *) self;
    RTCTime rtc;

    MIi_CpuClearFast(0, base + 0x240, 0x200);
    MIi_CpuClearFast(0, base + 0x40, 0x200);
    MIi_CpuClearFast(0, base + 0x640, 0x70);
    MIi_CpuClearFast(0, base + 0x440, 0x200);
    M2C_FIELD(self, u8 *, 0x6B0)  = 0;
    M2C_FIELD(self, u8 *, 0x6B1)  = 0;
    M2C_FIELD(self, s32 *, 0x6FC) = 0;
    M2C_FIELD(self, s32 *, 0x6F8) = 0;
    M2C_FIELD(self, u8 *, 0x6F4)  = 0;
    M2C_FIELD(self, s32 *, 0x700) = 0;
    data_02104344                 = 0;
    RTC_GetTime(&rtc);
    func_020ad218(self->unknown04(), rtc.hour << (rtc.minute + 12) << (rtc.second + 6));
}
