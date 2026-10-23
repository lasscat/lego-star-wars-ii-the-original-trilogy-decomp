#include "m2c.h"

typedef volatile u32 vu32;
typedef volatile s32 vs32;

typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc;
    char unk_40[0x20];
} OSContext;
typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;
typedef void (*OSThreadDestructor)(void *);
typedef struct OSThreadLinkedList {
    OSThread *prev;
    OSThread *next;
} OSThreadLinkedList;
typedef struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;
typedef struct OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;
typedef struct OSThread {
    OSContext context;
    s32 state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSThreadQueue *queue;
    OSThreadLinkedList list;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackOffset;
    OSThreadQueue joinQueue;
    void *unk_A4[3];
    void *unk_B0;
    OSThreadDestructor destructor;
    void *userParam;
    s32 error;
} OSThread;
typedef struct OSThreadInfo {
    u16 isSchedulerWaiting;
    u16 irqDepth;
    OSThread *current;
    OSThread *list;
    void *switchCallback;
} OSThreadInfo;
typedef struct UnkCardCmd {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3c;
    u32 unk_40;
    u32 unk_44;
    u8 unk_48;
    u8 unk_49[3];
    u32 unk_4c;
    u8 unk_50[0x10];
} UnkCardCmd;
struct UnkCardCommon;
typedef void (*UnkCardTask)(struct UnkCardCommon *common);
typedef void (*UnkCardCallback)(void *arg);
typedef struct UnkCardCommon {
    UnkCardCmd *unk_000;
    u32 unk_004;
    vs32 unk_008;
    vs32 unk_00c;
    OSThreadQueue unk_010;
    u32 unk_018;
    u32 unk_01c;
    void *unk_020;
    u32 unk_024;
    u32 unk_028;
    u32 unk_02c;
    u32 unk_030;
    u32 unk_034;
    UnkCardCallback unk_038;
    void *unk_03c;
    UnkCardTask unk_040;
    OSThread unk_044;
    OSThread *unk_104;
    u32 unk_108;
    OSThreadQueue unk_10c;
    vu32 unk_114;
    u32 unk_118[2];
    u8 unk_120[0x100];
} UnkCardCommon;
typedef struct UnkCardRom {
    void (*unk_000)(struct UnkCardRom *rom);
    u32 unk_004;
    u32 unk_008;
    u32 unk_00c[5];
    u32 unk_020[0x80];
} UnkCardRom;

extern UnkCardCommon cardi_common;
extern UnkCardRom rom_stat;
extern u32 cardi_rom_base;
extern OSThreadInfo OSi_ThreadInfo;

extern void CARD_CheckEnabled(void);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32 irq_flag);
extern void OS_SleepThread(OSThreadQueue *queue);
extern void MI_StopDma(u32 dmaNo);
extern s32 CARDi_TryReadCardDma(UnkCardRom *rom);
extern void CARD_WaitRomAsync(void);
extern void CARDi_SetTask(UnkCardTask task);
extern void CARDi_ReadRomSyncCore(UnkCardCommon *common);

#pragma opt_rotateloops off
void CARDi_ReadRom(u32 dma, u32 src, void *dst, u32 len, UnkCardCallback callback, void *arg, s32 async) {
    UnkCardRom *const rom  = &rom_stat;
    UnkCardCommon *const p = &cardi_common;
    u32 irq_flag;

    CARD_CheckEnabled();
    irq_flag = OS_DisableInterrupts();
    while (p->unk_114 & 4) {
        OS_SleepThread(&p->unk_10c);
    }
    p->unk_114 |= 4;
    p->unk_038 = callback;
    p->unk_03c = arg;
    OS_RestoreInterrupts(irq_flag);

    p->unk_028 = dma;
    p->unk_01c = src + cardi_rom_base;
    p->unk_020 = dst;
    p->unk_024 = len;

    if (dma <= 3) {
        MI_StopDma(dma);
    }
    if (CARDi_TryReadCardDma(rom) != 0) {
        if (async != 0) {
            return;
        }
        CARD_WaitRomAsync();
        return;
    }
    if (async != 0) {
        CARDi_SetTask(CARDi_ReadRomSyncCore);
        return;
    }
    p->unk_104 = OSi_ThreadInfo.current;
    CARDi_ReadRomSyncCore(p);
}
