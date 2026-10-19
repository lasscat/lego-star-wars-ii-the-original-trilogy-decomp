/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020031cc from projets/farm-frenzy/src/donor/func_020031cc.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef struct {
    s32 subBgExtPltt;
    u32 objExtPlttAddr;
    s32 objExtPltt;
    u32 bgExtPlttOffset;
    u32 bgExtPlttAddr;
    s32 bgExtPltt;
    s32 subObjExtPltt;
} UnkGxExtPlttState;
extern UnkGxExtPlttState sSubBGExtPltt;
extern s32 GX_ResetBankForBGExtPltt(void);
void GX_BeginLoadBGExtPltt(void) {
    sSubBGExtPltt.bgExtPltt = GX_ResetBankForBGExtPltt();

    switch (sSubBGExtPltt.bgExtPltt) {
        case 0x00:
            break;
        case 0x10:
            sSubBGExtPltt.bgExtPlttAddr   = 0x6880000;
            sSubBGExtPltt.bgExtPlttOffset = 0;
            break;
        case 0x40:
            sSubBGExtPltt.bgExtPlttAddr   = 0x6894000;
            sSubBGExtPltt.bgExtPlttOffset = 0x4000;
            break;
        case 0x20:
        case 0x60:
            sSubBGExtPltt.bgExtPlttAddr   = 0x6890000;
            sSubBGExtPltt.bgExtPlttOffset = 0;
            break;
        default:
            break;
    }
}
