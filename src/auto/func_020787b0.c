#include "m2c.h"

typedef struct {
    u8 f00[0x145];
    s8 f145[6];
} Obj;

extern M2C_UNK data_020fed9c;
extern M2C_UNK data_02104d90;
extern M2C_UNK data_02104d94;
extern M2C_UNK data_02102900;
extern u8 data_020eedac[];

extern void func_02086308(M2C_UNK);
extern void func_02086278(M2C_UNK);
extern void func_020862b8(M2C_UNK);
extern void func_020862e0(M2C_UNK);
extern void func_020855ac(M2C_UNK, s32);
extern s32 func_02086534(M2C_UNK *, s32);
extern void func_02086458(M2C_UNK *, s32);
extern void func_02086558(M2C_UNK *, s32);
extern void func_02086654(M2C_UNK *, s32);
extern void func_020b8f70(M2C_UNK, s32);
extern s32 func_02085cb0(M2C_UNK *, M2C_UNK);
extern void func_02087044(M2C_UNK);
extern void func_0205ecc4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);

void func_020787b0(Obj *arg0) {
    s8 result = -1;
    s32 i;
    s32 ok;
    s32 j;
    u8 *p = &data_020fed9c;

    for (i = 0; i < 0x6C; i++) {
        ok = 1;

        for (j = 0; j < 6; j++) {
            if (arg0->f145[j] != p[j]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            result = i;
            break;
        }
        p += 6;
    }

    switch (result + 1) {
        case 1:
            func_02086308(&data_02104d90);
            break;
        case 2:
            func_02086278(&data_02104d90);
            break;
        case 3:
            func_020862b8(&data_02104d90);
            break;
        case 4:
            func_020862e0(&data_02104d90);
            break;
        case 5:
            func_020855ac(&data_02104d94, 0x7a120);
            break;
        case 6:
            func_020855ac(&data_02104d94, 10);
            break;
        case 7:
            if (func_02086534(&data_02104d90, 0) == 0) {
                if (data_020eedac[1] == 1) {
                    func_02086458(&data_02104d90, 0);
                } else if (data_020eedac[1] == 0) {
                    func_02086558(&data_02104d90, 0);
                }
            }
            break;
        case 8:
            if (func_02086534(&data_02104d90, 1) == 0) {
                if (data_020eedac[21] == 1) {
                    func_02086458(&data_02104d90, 1);
                } else if (data_020eedac[21] == 0) {
                    func_02086558(&data_02104d90, 1);
                }
            }
            break;
        case 9:
            if (func_02086534(&data_02104d90, 2) == 0) {
                if (data_020eedac[41] == 1) {
                    func_02086458(&data_02104d90, 2);
                } else if (data_020eedac[41] == 0) {
                    func_02086558(&data_02104d90, 2);
                }
            }
            break;
        case 10:
            if (func_02086534(&data_02104d90, 7) == 0) {
                if (data_020eedac[141] == 1) {
                    func_02086458(&data_02104d90, 7);
                } else if (data_020eedac[141] == 0) {
                    func_02086558(&data_02104d90, 7);
                }
            }
            break;
        case 11:
            if (func_02086534(&data_02104d90, 8) == 0) {
                if (data_020eedac[161] == 1) {
                    func_02086458(&data_02104d90, 8);
                } else if (data_020eedac[161] == 0) {
                    func_02086558(&data_02104d90, 8);
                }
            }
            break;
        case 12:
            if (func_02086534(&data_02104d90, 9) == 0) {
                if (data_020eedac[181] == 1) {
                    func_02086458(&data_02104d90, 9);
                } else if (data_020eedac[181] == 0) {
                    func_02086558(&data_02104d90, 9);
                }
            }
            break;
        case 13:
            if (func_02086534(&data_02104d90, 10) == 0) {
                if (data_020eedac[201] == 1) {
                    func_02086458(&data_02104d90, 10);
                } else if (data_020eedac[201] == 0) {
                    func_02086558(&data_02104d90, 10);
                }
            }
            break;
        case 14:
            if (func_02086534(&data_02104d90, 11) == 0) {
                if (data_020eedac[221] == 1) {
                    func_02086458(&data_02104d90, 11);
                } else if (data_020eedac[221] == 0) {
                    func_02086558(&data_02104d90, 11);
                }
            }
            break;
        case 15:
            if (func_02086534(&data_02104d90, 12) == 0) {
                if (data_020eedac[241] == 1) {
                    func_02086458(&data_02104d90, 12);
                } else if (data_020eedac[241] == 0) {
                    func_02086558(&data_02104d90, 12);
                }
            }
            break;
        case 16:
            if (func_02086534(&data_02104d90, 13) == 0) {
                if (data_020eedac[261] == 1) {
                    func_02086458(&data_02104d90, 13);
                } else if (data_020eedac[261] == 0) {
                    func_02086558(&data_02104d90, 13);
                }
            }
            break;
        case 17:
            if (func_02086534(&data_02104d90, 14) == 0) {
                if (data_020eedac[281] == 1) {
                    func_02086458(&data_02104d90, 14);
                } else if (data_020eedac[281] == 0) {
                    func_02086558(&data_02104d90, 14);
                }
            }
            break;
        case 18:
            if (func_02086534(&data_02104d90, 15) == 0) {
                if (data_020eedac[301] == 1) {
                    func_02086458(&data_02104d90, 15);
                } else if (data_020eedac[301] == 0) {
                    func_02086558(&data_02104d90, 15);
                }
            }
            break;
        case 19:
            if (func_02086534(&data_02104d90, 16) == 0) {
                if (data_020eedac[321] == 1) {
                    func_02086458(&data_02104d90, 16);
                } else if (data_020eedac[321] == 0) {
                    func_02086558(&data_02104d90, 16);
                }
            }
            break;
        case 20:
            if (func_02086534(&data_02104d90, 17) == 0) {
                if (data_020eedac[341] == 1) {
                    func_02086458(&data_02104d90, 17);
                } else if (data_020eedac[341] == 0) {
                    func_02086558(&data_02104d90, 17);
                }
            }
            break;
        case 21:
            if (func_02086534(&data_02104d90, 18) == 0) {
                if (data_020eedac[361] == 1) {
                    func_02086458(&data_02104d90, 18);
                } else if (data_020eedac[361] == 0) {
                    func_02086558(&data_02104d90, 18);
                }
            }
            break;
        case 22:
            if (func_02086534(&data_02104d90, 21) == 0) {
                if (data_020eedac[421] == 1) {
                    func_02086458(&data_02104d90, 21);
                } else if (data_020eedac[421] == 0) {
                    func_02086558(&data_02104d90, 21);
                }
            }
            break;
        case 23:
            if (func_02086534(&data_02104d90, 22) == 0) {
                if (data_020eedac[441] == 1) {
                    func_02086458(&data_02104d90, 22);
                } else if (data_020eedac[441] == 0) {
                    func_02086558(&data_02104d90, 22);
                }
            }
            break;
        case 24:
            if (func_02086534(&data_02104d90, 23) == 0) {
                if (data_020eedac[461] == 1) {
                    func_02086458(&data_02104d90, 23);
                } else if (data_020eedac[461] == 0) {
                    func_02086558(&data_02104d90, 23);
                }
            }
            break;
        case 25:
            if (func_02086534(&data_02104d90, 24) == 0) {
                if (data_020eedac[481] == 1) {
                    func_02086458(&data_02104d90, 24);
                } else if (data_020eedac[481] == 0) {
                    func_02086558(&data_02104d90, 24);
                }
            }
            break;
        case 26:
            if (func_02086534(&data_02104d90, 25) == 0) {
                if (data_020eedac[501] == 1) {
                    func_02086458(&data_02104d90, 25);
                } else if (data_020eedac[501] == 0) {
                    func_02086558(&data_02104d90, 25);
                }
            }
            break;
        case 27:
            if (func_02086534(&data_02104d90, 26) == 0) {
                if (data_020eedac[521] == 1) {
                    func_02086458(&data_02104d90, 26);
                } else if (data_020eedac[521] == 0) {
                    func_02086558(&data_02104d90, 26);
                }
            }
            break;
        case 28:
            if (func_02086534(&data_02104d90, 27) == 0) {
                if (data_020eedac[541] == 1) {
                    func_02086458(&data_02104d90, 27);
                } else if (data_020eedac[541] == 0) {
                    func_02086558(&data_02104d90, 27);
                }
            }
            break;
        case 29:
            if (func_02086534(&data_02104d90, 28) == 0) {
                if (data_020eedac[561] == 1) {
                    func_02086458(&data_02104d90, 28);
                } else if (data_020eedac[561] == 0) {
                    func_02086558(&data_02104d90, 28);
                }
            }
            break;
        case 30:
            if (func_02086534(&data_02104d90, 29) == 0) {
                if (data_020eedac[581] == 1) {
                    func_02086458(&data_02104d90, 29);
                } else if (data_020eedac[581] == 0) {
                    func_02086558(&data_02104d90, 29);
                }
            }
            break;
        case 31:
            if (func_02086534(&data_02104d90, 31) == 0) {
                if (data_020eedac[621] == 1) {
                    func_02086458(&data_02104d90, 31);
                } else if (data_020eedac[621] == 0) {
                    func_02086558(&data_02104d90, 31);
                }
            }
            break;
        case 32:
            if (func_02086534(&data_02104d90, 32) == 0) {
                if (data_020eedac[641] == 1) {
                    func_02086458(&data_02104d90, 32);
                } else if (data_020eedac[641] == 0) {
                    func_02086558(&data_02104d90, 32);
                }
            }
            break;
        case 33:
            if (func_02086534(&data_02104d90, 33) == 0) {
                if (data_020eedac[661] == 1) {
                    func_02086458(&data_02104d90, 33);
                } else if (data_020eedac[661] == 0) {
                    func_02086558(&data_02104d90, 33);
                }
            }
            break;
        case 34:
            if (func_02086534(&data_02104d90, 34) == 0) {
                if (data_020eedac[681] == 1) {
                    func_02086458(&data_02104d90, 34);
                } else if (data_020eedac[681] == 0) {
                    func_02086558(&data_02104d90, 34);
                }
            }
            break;
        case 35:
            if (func_02086534(&data_02104d90, 36) == 0) {
                if (data_020eedac[721] == 1) {
                    func_02086458(&data_02104d90, 36);
                } else if (data_020eedac[721] == 0) {
                    func_02086558(&data_02104d90, 36);
                }
            }
            break;
        case 36:
            if (func_02086534(&data_02104d90, 37) == 0) {
                if (data_020eedac[741] == 1) {
                    func_02086458(&data_02104d90, 37);
                } else if (data_020eedac[741] == 0) {
                    func_02086558(&data_02104d90, 37);
                }
            }
            break;
        case 37:
            if (func_02086534(&data_02104d90, 38) == 0) {
                if (data_020eedac[761] == 1) {
                    func_02086458(&data_02104d90, 38);
                } else if (data_020eedac[761] == 0) {
                    func_02086558(&data_02104d90, 38);
                }
            }
            break;
        case 38:
            if (func_02086534(&data_02104d90, 39) == 0) {
                if (data_020eedac[781] == 1) {
                    func_02086458(&data_02104d90, 39);
                } else if (data_020eedac[781] == 0) {
                    func_02086558(&data_02104d90, 39);
                }
            }
            break;
        case 39:
            if (func_02086534(&data_02104d90, 40) == 0) {
                if (data_020eedac[801] == 1) {
                    func_02086458(&data_02104d90, 40);
                } else if (data_020eedac[801] == 0) {
                    func_02086558(&data_02104d90, 40);
                }
            }
            break;
        case 40:
            if (func_02086534(&data_02104d90, 41) == 0) {
                if (data_020eedac[821] == 1) {
                    func_02086458(&data_02104d90, 41);
                } else if (data_020eedac[821] == 0) {
                    func_02086558(&data_02104d90, 41);
                }
            }
            break;
        case 41:
            if (func_02086534(&data_02104d90, 42) == 0) {
                if (data_020eedac[841] == 1) {
                    func_02086458(&data_02104d90, 42);
                } else if (data_020eedac[841] == 0) {
                    func_02086558(&data_02104d90, 42);
                }
            }
            break;
        case 42:
            if (func_02086534(&data_02104d90, 43) == 0) {
                if (data_020eedac[861] == 1) {
                    func_02086458(&data_02104d90, 43);
                } else if (data_020eedac[861] == 0) {
                    func_02086558(&data_02104d90, 43);
                }
            }
            break;
        case 43:
            if (func_02086534(&data_02104d90, 44) == 0) {
                if (data_020eedac[881] == 1) {
                    func_02086458(&data_02104d90, 44);
                } else if (data_020eedac[881] == 0) {
                    func_02086558(&data_02104d90, 44);
                }
            }
            break;
        case 44:
            if (func_02086534(&data_02104d90, 46) == 0) {
                if (data_020eedac[921] == 1) {
                    func_02086458(&data_02104d90, 46);
                } else if (data_020eedac[921] == 0) {
                    func_02086558(&data_02104d90, 46);
                }
            }
            break;
        case 45:
            if (func_02086534(&data_02104d90, 47) == 0) {
                if (data_020eedac[941] == 1) {
                    func_02086458(&data_02104d90, 47);
                } else if (data_020eedac[941] == 0) {
                    func_02086558(&data_02104d90, 47);
                }
            }
            break;
        case 46:
            if (func_02086534(&data_02104d90, 48) == 0) {
                if (data_020eedac[961] == 1) {
                    func_02086458(&data_02104d90, 48);
                } else if (data_020eedac[961] == 0) {
                    func_02086558(&data_02104d90, 48);
                }
            }
            break;
        case 47:
            if (func_02086534(&data_02104d90, 50) == 0) {
                if (data_020eedac[1001] == 1) {
                    func_02086458(&data_02104d90, 50);
                } else if (data_020eedac[1001] == 0) {
                    func_02086558(&data_02104d90, 50);
                }
            }
            break;
        case 48:
            if (func_02086534(&data_02104d90, 51) == 0) {
                if (data_020eedac[1021] == 1) {
                    func_02086458(&data_02104d90, 51);
                } else if (data_020eedac[1021] == 0) {
                    func_02086558(&data_02104d90, 51);
                }
            }
            break;
        case 49:
            if (func_02086534(&data_02104d90, 52) == 0) {
                if (data_020eedac[1041] == 1) {
                    func_02086458(&data_02104d90, 52);
                } else if (data_020eedac[1041] == 0) {
                    func_02086558(&data_02104d90, 52);
                }
            }
            break;
        case 50:
            if (func_02086534(&data_02104d90, 53) == 0) {
                if (data_020eedac[1061] == 1) {
                    func_02086458(&data_02104d90, 53);
                } else if (data_020eedac[1061] == 0) {
                    func_02086558(&data_02104d90, 53);
                }
            }
            break;
        case 51:
            if (func_02086534(&data_02104d90, 54) == 0) {
                if (data_020eedac[1081] == 1) {
                    func_02086458(&data_02104d90, 54);
                } else if (data_020eedac[1081] == 0) {
                    func_02086558(&data_02104d90, 54);
                }
            }
            break;
        case 52:
            if (func_02086534(&data_02104d90, 58) == 0) {
                if (data_020eedac[1161] == 1) {
                    func_02086458(&data_02104d90, 58);
                } else if (data_020eedac[1161] == 0) {
                    func_02086558(&data_02104d90, 58);
                }
            }
            break;
        case 53:
            if (func_02086534(&data_02104d90, 59) == 0) {
                if (data_020eedac[1181] == 1) {
                    func_02086458(&data_02104d90, 59);
                } else if (data_020eedac[1181] == 0) {
                    func_02086558(&data_02104d90, 59);
                }
            }
            break;
        case 54:
            if (func_02086534(&data_02104d90, 60) == 0) {
                if (data_020eedac[1201] == 1) {
                    func_02086458(&data_02104d90, 60);
                } else if (data_020eedac[1201] == 0) {
                    func_02086558(&data_02104d90, 60);
                }
            }
            break;
        case 55:
            if (func_02086534(&data_02104d90, 61) == 0) {
                if (data_020eedac[1221] == 1) {
                    func_02086458(&data_02104d90, 61);
                } else if (data_020eedac[1221] == 0) {
                    func_02086558(&data_02104d90, 61);
                }
            }
            break;
        case 56:
            if (func_02086534(&data_02104d90, 62) == 0) {
                if (data_020eedac[1241] == 1) {
                    func_02086458(&data_02104d90, 62);
                } else if (data_020eedac[1241] == 0) {
                    func_02086558(&data_02104d90, 62);
                }
            }
            break;
        case 57:
            if (func_02086534(&data_02104d90, 63) == 0) {
                if (data_020eedac[1261] == 1) {
                    func_02086458(&data_02104d90, 63);
                } else if (data_020eedac[1261] == 0) {
                    func_02086558(&data_02104d90, 63);
                }
            }
            break;
        case 58:
            if (func_02086534(&data_02104d90, 64) == 0) {
                if (data_020eedac[1281] == 1) {
                    func_02086458(&data_02104d90, 64);
                } else if (data_020eedac[1281] == 0) {
                    func_02086558(&data_02104d90, 64);
                }
            }
            break;
        case 59:
            if (func_02086534(&data_02104d90, 65) == 0) {
                if (data_020eedac[1301] == 1) {
                    func_02086458(&data_02104d90, 65);
                } else if (data_020eedac[1301] == 0) {
                    func_02086558(&data_02104d90, 65);
                }
            }
            break;
        case 60:
            if (func_02086534(&data_02104d90, 66) == 0) {
                if (data_020eedac[1321] == 1) {
                    func_02086458(&data_02104d90, 66);
                } else if (data_020eedac[1321] == 0) {
                    func_02086558(&data_02104d90, 66);
                }
            }
            break;
        case 61:
            if (func_02086534(&data_02104d90, 67) == 0) {
                if (data_020eedac[1341] == 1) {
                    func_02086458(&data_02104d90, 67);
                } else if (data_020eedac[1341] == 0) {
                    func_02086558(&data_02104d90, 67);
                }
            }
            break;
        case 62:
            if (func_02086534(&data_02104d90, 68) == 0) {
                if (data_020eedac[1361] == 1) {
                    func_02086458(&data_02104d90, 68);
                } else if (data_020eedac[1361] == 0) {
                    func_02086558(&data_02104d90, 68);
                }
            }
            break;
        case 63:
            if (func_02086534(&data_02104d90, 69) == 0) {
                if (data_020eedac[1381] == 1) {
                    func_02086458(&data_02104d90, 69);
                } else if (data_020eedac[1381] == 0) {
                    func_02086558(&data_02104d90, 69);
                }
            }
            break;
        case 64:
            if (func_02086534(&data_02104d90, 70) == 0) {
                if (data_020eedac[1401] == 1) {
                    func_02086458(&data_02104d90, 70);
                } else if (data_020eedac[1401] == 0) {
                    func_02086558(&data_02104d90, 70);
                }
            }
            break;
        case 65:
            if (func_02086534(&data_02104d90, 71) == 0) {
                if (data_020eedac[1421] == 1) {
                    func_02086458(&data_02104d90, 71);
                } else if (data_020eedac[1421] == 0) {
                    func_02086558(&data_02104d90, 71);
                }
            }
            break;
        case 66:
            if (func_02086534(&data_02104d90, 85) == 0) {
                if (data_020eedac[1701] == 1) {
                    func_02086458(&data_02104d90, 85);
                } else if (data_020eedac[1701] == 0) {
                    func_02086558(&data_02104d90, 85);
                }
            }
            break;
        case 67:
            if (func_02086534(&data_02104d90, 87) == 0) {
                if (data_020eedac[1741] == 1) {
                    func_02086458(&data_02104d90, 87);
                } else if (data_020eedac[1741] == 0) {
                    func_02086558(&data_02104d90, 87);
                }
            }
            break;
        case 68:
            if (func_02086534(&data_02104d90, 88) == 0) {
                if (data_020eedac[1761] == 1) {
                    func_02086458(&data_02104d90, 88);
                } else if (data_020eedac[1761] == 0) {
                    func_02086558(&data_02104d90, 88);
                }
            }
            break;
        case 69:
            if (func_02086534(&data_02104d90, 89) == 0) {
                if (data_020eedac[1781] == 1) {
                    func_02086458(&data_02104d90, 89);
                } else if (data_020eedac[1781] == 0) {
                    func_02086558(&data_02104d90, 89);
                }
            }
            break;
        case 70:
            if (func_02086534(&data_02104d90, 90) == 0) {
                if (data_020eedac[1801] == 1) {
                    func_02086458(&data_02104d90, 90);
                } else if (data_020eedac[1801] == 0) {
                    func_02086558(&data_02104d90, 90);
                }
            }
            break;
        case 71:
            if (func_02086534(&data_02104d90, 91) == 0) {
                if (data_020eedac[1821] == 1) {
                    func_02086458(&data_02104d90, 91);
                } else if (data_020eedac[1821] == 0) {
                    func_02086558(&data_02104d90, 91);
                }
            }
            break;
        case 72:
            if (func_02086534(&data_02104d90, 92) == 0) {
                if (data_020eedac[1841] == 1) {
                    func_02086458(&data_02104d90, 92);
                } else if (data_020eedac[1841] == 0) {
                    func_02086558(&data_02104d90, 92);
                }
            }
            break;
        case 73:
            if (func_02086534(&data_02104d90, 93) == 0) {
                if (data_020eedac[1861] == 1) {
                    func_02086458(&data_02104d90, 93);
                } else if (data_020eedac[1861] == 0) {
                    func_02086558(&data_02104d90, 93);
                }
            }
            break;
        case 74:
            if (func_02086534(&data_02104d90, 94) == 0) {
                if (data_020eedac[1881] == 1) {
                    func_02086458(&data_02104d90, 94);
                } else if (data_020eedac[1881] == 0) {
                    func_02086558(&data_02104d90, 94);
                }
            }
            break;
        case 75:
            if (func_02086534(&data_02104d90, 95) == 0) {
                if (data_020eedac[1901] == 1) {
                    func_02086458(&data_02104d90, 95);
                } else if (data_020eedac[1901] == 0) {
                    func_02086558(&data_02104d90, 95);
                }
            }
            break;
        case 76:
            if (func_02086534(&data_02104d90, 96) == 0) {
                if (data_020eedac[1921] == 1) {
                    func_02086458(&data_02104d90, 96);
                } else if (data_020eedac[1921] == 0) {
                    func_02086558(&data_02104d90, 96);
                }
            }
            break;
        case 77:
            if (func_02086534(&data_02104d90, 97) == 0) {
                if (data_020eedac[1941] == 1) {
                    func_02086458(&data_02104d90, 97);
                } else if (data_020eedac[1941] == 0) {
                    func_02086558(&data_02104d90, 97);
                }
            }
            break;
        case 78:
            if (func_02086534(&data_02104d90, 98) == 0) {
                if (data_020eedac[1961] == 1) {
                    func_02086458(&data_02104d90, 98);
                } else if (data_020eedac[1961] == 0) {
                    func_02086558(&data_02104d90, 98);
                }
            }
            break;
        case 79:
            if (func_02086534(&data_02104d90, 99) == 0) {
                if (data_020eedac[1981] == 1) {
                    func_02086458(&data_02104d90, 99);
                } else if (data_020eedac[1981] == 0) {
                    func_02086558(&data_02104d90, 99);
                }
            }
            break;
        case 80:
            func_02086654(&data_02104d90, 0);
            break;
        case 81:
            func_02086654(&data_02104d90, 1);
            break;
        case 82:
            func_02086654(&data_02104d90, 2);
            break;
        case 83:
            func_02086654(&data_02104d90, 3);
            break;
        case 84:
            func_02086654(&data_02104d90, 4);
            break;
        case 85:
            func_02086654(&data_02104d90, 5);
            break;
        case 86:
            func_02086654(&data_02104d90, 6);
            break;
        case 87:
            func_02086654(&data_02104d90, 7);
            break;
        case 88:
            func_02086654(&data_02104d90, 8);
            break;
        case 89:
            func_02086654(&data_02104d90, 9);
            break;
        case 90:
            func_02086654(&data_02104d90, 10);
            break;
        case 91:
            func_02086654(&data_02104d90, 11);
            break;
        case 92:
            func_02086654(&data_02104d90, 12);
            break;
        case 93:
            func_02086654(&data_02104d90, 13);
            break;
        case 94:
            func_02086654(&data_02104d90, 14);
            break;
        case 95:
            func_02086654(&data_02104d90, 15);
            break;
        case 96:
            func_02086654(&data_02104d90, 16);
            break;
        case 97:
            func_02086654(&data_02104d90, 17);
            break;
        case 98:
            func_02086654(&data_02104d90, 18);
            break;
        case 99:
            func_02086654(&data_02104d90, 19);
            break;
        case 100:
            func_02086654(&data_02104d90, 20);
            break;
        case 101:
            func_02086654(&data_02104d90, 21);
            break;
        case 102:
            func_02086654(&data_02104d90, 22);
            break;
        case 103:
            func_02086654(&data_02104d90, 23);
            break;
        case 104:
            func_02086654(&data_02104d90, 24);
            break;
        case 105:
            func_02086654(&data_02104d90, 25);
            break;
        case 106:
            func_02086654(&data_02104d90, 26);
            break;
        case 107:
            func_02086654(&data_02104d90, 27);
            break;
        case 108:
            func_02086654(&data_02104d90, 28);
            break;
        default:
            break;
    }

    if (result != -1) {
        func_020b8f70(0x6D, 0);
        if (func_02085cb0(&data_02104d90, 0) == 0) {
            return;
        }
        func_02087044(&data_02104d90);
        func_0205ecc4(&data_02102900, 0x30, 1, 0, 1, 0);
    } else {
        func_020b8f70(0x70, 0);
    }
}
