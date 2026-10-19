/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* FX_Divide64 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_division.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long long u64;
typedef unsigned short u16;
typedef long long s64;
typedef int s32;
typedef volatile u16 vu16;
extern s64 FX_InvFx64c(s32 denom);
extern void func_020c9344(s32 denom);
s64 FX_InvFx64c(s32 denom) {
    func_020c9344(denom);
    while ((*(vu16 *) 0x04000280) & 0x8000) {
    }
    return (*(u64 *) 0x040002A0);
}
void func_020c9344(s32 denom);
