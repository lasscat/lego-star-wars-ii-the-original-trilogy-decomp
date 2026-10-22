#include "m2c.h"

typedef struct {
    u8 color;
    u8 len;
    u16 name[10];
} ParentName;

typedef struct {
    u8 language;
    u8 favoriteColour;
    u8 birthday[2];
    u16 nickName[10];
    u16 nickNameLength;
    u16 comment[26];
    u16 commentLength;
} OSOwnerInfo;

typedef struct {
    u32 unk0;
    void *buf;
    s16 state;
    u16 flags;
} ManagerState;

extern void OS_GetOwnerInfo(OSOwnerInfo *info);
extern void MI_CpuCopy8(const void *src, void *dst, u32 len);
extern void func_0205e624(void *ptr, s32 value, s32 size);
extern void *func_0205e838(u32 size);
extern s32 func_020dc470(void *buf, ParentName *name, void *arg0, void *arg1, u16 flags);
extern void OS_Terminate(void);
extern void MB_SetParentCommParam(u32 a, u32 b);
extern void MB_CommSetParentStateCallback(void *cb);
extern void func_020afcac(s16 v);
extern void func_020af9a0(void);
extern ManagerState data_0210da80;
extern u8 data_0210da88[14];

void func_020afcbc(void *arg0, void *arg1) {
    ParentName name;
    OSOwnerInfo info;

    OS_GetOwnerInfo(&info);
    name.color = (name.color & ~0xF) | (info.favoriteColour & 0x0F);
    name.len   = info.nickNameLength;
    MI_CpuCopy8(info.nickName, name.name, info.nickNameLength * 2);
    func_0205e624(data_0210da88, 0, 0xE);
    data_0210da80.buf = func_0205e838(0xB100);
    if (func_020dc470(data_0210da80.buf, &name, arg0, arg1, 2) != 0) {
        OS_Terminate();
    }
    MB_SetParentCommParam(0x100, 3);
    MB_CommSetParentStateCallback(func_020af9a0);
    func_020afcac(1);
}
