#include "m2c.h"

/* Partial layout of the multiboot parent work structure.
 * Only the per-child communication state array is needed here; it starts
 * at offset 0x14E8 (the function pointer of the parent callback is at
 * offset 0x14E4). */
typedef struct {
    u8 pad[0x14E8];
    s32 p_comm_state[15];
} MB_CommPWork;

extern MB_CommPWork *mbc;
extern void MIi_CpuClear16(u16 value, void *dest, u32 size);
extern int func_020d9540(u8 type, u16 pollbmp);
extern int MBi_CommParentSendDLFileInfo(void);
extern int func_020d97ac(void);

int MBi_CommParentSendData(void) {
    u16 bmp[5];
    u16 i;
    s32 res;

    MIi_CpuClear16(0, bmp, sizeof(bmp));

    for (i = 1; i <= 15; i++) {
        switch (mbc->p_comm_state[i - 1]) {
            case 2:
                bmp[0] |= 1 << i;
                break;
            case 5:
                bmp[1] |= 1 << i;
                break;
            case 4:
                bmp[2] |= 1 << i;
                break;
            case 8:
                bmp[3] |= 1 << i;
                break;
            case 11:
                bmp[4] |= 1 << i;
                break;
            default:
                break;
        }
    }

    if (bmp[3]) {
        res = func_020d9540(5, bmp[3]);
    } else if (bmp[0]) {
        res = func_020d9540(1, bmp[0]);
    } else if (bmp[4]) {
        res = func_020d9540(6, bmp[4]);
    } else if (bmp[2]) {
        res = func_020d9540(2, bmp[2]);
    } else if (bmp[1]) {
        res = MBi_CommParentSendDLFileInfo();
    } else {
        res = func_020d97ac();
    }

    if (res != 0x15) {
        return res;
    }

    return func_020d9540(0, 0xFFFF);
}
