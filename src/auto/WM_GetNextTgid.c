/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */

typedef unsigned short u16;
typedef unsigned long u32;
typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;
extern void RTC_Init(void);
extern int RTC_GetTime(RTCTime *time);
extern u32 data_0210155c;

/* Ov105_WM_GetNextTgid from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/wm/calls/Ov105_WM_GetNextTgid.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
u16 WM_GetNextTgid(void) {
    enum {
        TGID_DEFAULT = (1 << 16)
    };

    if (data_0210155c == (u32) TGID_DEFAULT) {
        RTCTime rt[1];
        RTC_Init();
        if (RTC_GetTime(rt) == 0) {
            data_0210155c = (u16) (rt->second + (rt->minute << 8));
        }
    }

    data_0210155c = (u16) (data_0210155c + 1);
    return (u16) data_0210155c;
}
