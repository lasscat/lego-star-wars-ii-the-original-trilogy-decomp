#include "m2c.h"

extern u8 data_020f02bc[];
extern u8 data_020f02bd[];
extern u8 data_020f02be[];
extern u8 data_020f02bf[];
extern u8 data_020f02c0[];
extern u8 data_020f02c1[];
extern u8 data_020f02c2[];
extern u8 data_020f02c3[];

void func_020b9204(void *);

void func_020b37c0(void *arg0, u32 arg1) {
    switch (arg1) {
        case 0:
            M2C_FIELD(arg0, u8 *, 0x12) = data_020f02bc[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x15) = data_020f02bd[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x14) = 1;
            M2C_FIELD(arg0, u8 *, 0x13) = 0;
            break;
        case 3:
            M2C_FIELD(arg0, u8 *, 0x12) = data_020f02be[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x15) = data_020f02bf[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x14) = 0xa;
            if (data_020f02be[M2C_FIELD(arg0, u8 *, 0) * 8] != data_020f02bc[M2C_FIELD(arg0, u8 *, 0) * 8]) {
                M2C_FIELD(arg0, u8 *, 0x13) = 1;
            }
            break;
        case 4:
            M2C_FIELD(arg0, u8 *, 0x12) = data_020f02c0[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x15) = data_020f02c1[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x14) = 0xa;
            if (data_020f02c0[M2C_FIELD(arg0, u8 *, 0) * 8] != data_020f02bc[M2C_FIELD(arg0, u8 *, 0) * 8]) {
                M2C_FIELD(arg0, u8 *, 0x13) = 1;
            }
            break;
        case 1:
            M2C_FIELD(arg0, u8 *, 0x12) = M2C_FIELD(arg0, u8 *, 0x3a);
            M2C_FIELD(arg0, u8 *, 0x15) = M2C_FIELD(arg0, u8 *, 0x3c);
            M2C_FIELD(arg0, u8 *, 0x14) = 1;
            M2C_FIELD(arg0, u8 *, 0x13) = 0;
            break;
        case 2:
            M2C_FIELD(arg0, u8 *, 0x12) = M2C_FIELD(arg0, u8 *, 0x3b);
            M2C_FIELD(arg0, u8 *, 0x15) = M2C_FIELD(arg0, u8 *, 0x3d);
            M2C_FIELD(arg0, u8 *, 0x14) = 1;
            M2C_FIELD(arg0, u8 *, 0x13) = 0;
            break;
        case 5:
            M2C_FIELD(arg0, u8 *, 0x12) = data_020f02c2[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x15) = data_020f02c3[M2C_FIELD(arg0, u8 *, 0) * 8];
            M2C_FIELD(arg0, u8 *, 0x14) = 1;
            if (data_020f02c0[M2C_FIELD(arg0, u8 *, 0) * 8] != data_020f02bc[M2C_FIELD(arg0, u8 *, 0) * 8]) {
                M2C_FIELD(arg0, u8 *, 0x13) = 1;
            }
            break;
        case 6:
            M2C_FIELD(arg0, u8 *, 0x12) = M2C_FIELD(arg0, u8 *, 0x40);
            M2C_FIELD(arg0, u8 *, 0x15) = 1;
            M2C_FIELD(arg0, u8 *, 0x14) = 1;
            if (M2C_FIELD(arg0, u8 *, 0x12) != 0x1d) {
                M2C_FIELD(arg0, u8 *, 0x13) = 1;
            } else {
                M2C_FIELD(arg0, u8 *, 0x13) = 0;
                M2C_FIELD(arg0, u8 *, 0x16) = 0;
                func_020b9204(arg0);
            }
            break;
    }
}
