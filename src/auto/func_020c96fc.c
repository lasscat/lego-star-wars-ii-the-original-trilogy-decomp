/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* GX_Init from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/gx/calls/GX_Init.c (license: CC0-1.0), reused by
 * tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed long s32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
extern void func_020c999c(void);
extern s32 func_020ccec8(void);
extern void func_020cea74(void);
extern void func_020ceaa0(u32 dmaNo, void *dest, u32 data, u32 size);
extern void func_020cf1d8(u32 data, void *dest, u32 size);
extern vu16 data_02115364[];
extern u32 data_02101538[];
void func_020c96fc(void) {
    s32 lockId;

    (*(vu16 *) 0x04000304) |= 0x8000;
    (*(vu16 *) 0x04000304) = (u16) (((*(vu16 *) 0x04000304) & ~0x20e) | 0x20e);
    (*(vu16 *) 0x04000304) = (u16) ((*(vu16 *) 0x04000304) | 0x0001);

    func_020c999c();

    while (data_02115364[1] == 0) {
        lockId = func_020ccec8();
        if (lockId == (-3)) {
            func_020cea74();
        }
        data_02115364[1] = (u16) lockId;
    }

    (*(vu16 *) 0x04000004) = 0;
    (*(vu32 *) 0x04000000) = 0;

    if (data_02101538[1] != (u32) -1) {
        func_020ceaa0(data_02101538[1], ((void *) 0x04000008), 0, 0x60);
        (*(vu16 *) 0x0400006c) = 0;
        func_020ceaa0(data_02101538[1], ((void *) 0x04001000), 0, 0x70);
    } else {
        func_020cf1d8(0, ((void *) 0x04000008), 0x60);
        (*(vu16 *) 0x0400006c) = 0;
        func_020cf1d8(0, ((void *) 0x04001000), 0x70);
    }

    *(vu16 *) 0x04000020 = 0x100;
    *(vu16 *) 0x04000026 = 0x100;
    *(vu16 *) 0x04000030 = 0x100;
    *(vu16 *) 0x04000036 = 0x100;
    *(vu16 *) 0x04001020 = 0x100;
    *(vu16 *) 0x04001026 = 0x100;
    *(vu16 *) 0x04001030 = 0x100;
    *(vu16 *) 0x04001036 = 0x100;
}
