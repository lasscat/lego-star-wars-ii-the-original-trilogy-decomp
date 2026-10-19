/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02003594 from projets/farm-frenzy/src/donor/func_02003594.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef struct {
    s32 clearImageBank;
    u32 texStartAddr;
    u32 texPlttStartAddr;
    s32 texPlttBank;
    u32 clearImageAddr;
    s32 texBank;
    u32 texStartAddr2;
    u32 texSize1;
} UnkGxLoad3dState;
extern UnkGxLoad3dState sClrImg;
extern const u16 sTexStartAddrTable[16][3];
extern s32 GX_ResetBankForTex(void);
void GX_BeginLoadTex(void) {
    s32 bank              = GX_ResetBankForTex();
    sClrImg.texBank       = bank;
    sClrImg.texStartAddr  = sTexStartAddrTable[bank][0] << 12;
    sClrImg.texStartAddr2 = sTexStartAddrTable[bank][1] << 12;
    sClrImg.texSize1      = sTexStartAddrTable[bank][2] << 12;
}
