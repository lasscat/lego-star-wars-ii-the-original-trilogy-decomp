#include "m2c.h"

extern void OS_GetMacAddress(u8 *mac);

u32 MBi_GetBeaconPeriodDispersion(void) {
    u8 mac[6];
    u32 sum;
    s32 i;

    OS_GetMacAddress(mac);
    for (i = 0, sum = 0; i < 6; i++) {
        sum += mac[i];
    }
    sum += *(volatile u32 *) 0x027ffc3c;
    sum *= 7;
    return sum % 20;
}
