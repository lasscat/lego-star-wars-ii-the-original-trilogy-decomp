/* OSi_RescheduleThread - reconstructed from USA ARM9 at 0x020cd59c (200 bytes).
 * Names and types are inferred from the binary.
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

typedef struct OSThread OSThread;
typedef void (*OSThreadCallback)(OSThread *current, OSThread *next);

/* Global scheduler state at 0x02115424. */
typedef struct OSThreadSystemState {
    OSThreadCallback callback;       /* 0x00 */
    u32 rescheduleCount;             /* 0x04 */
    OSThread **currentThreadPtr;     /* 0x08 */
    u32 reserved_0c;
    u32 reserved_10;
    u32 reserved_14;
    u32 reserved_18;
    u32 reserved_1c;
    u32 reserved_20;
    u32 reserved_24;
    OSThread *nextThread;            /* 0x28 */
} OSThreadSystemState;

/* Thread info at 0x02115448. */
typedef struct OSiThreadInfo {
    u16 state;                       /* 0x00 */
    u16 flag;                        /* 0x02 */
    u32 reserved_04;
    u32 reserved_08;
    OSThreadCallback switchCallback; /* 0x0c */
} OSiThreadInfo;

struct OSThread {
    u8 context[0x64];
    s32 state;
};

extern OSThreadSystemState OSi_SystemCallbackInSwitchThread;
extern OSiThreadInfo OSi_ThreadInfo;

extern OSThread *OS_SelectThread(void);
extern s32 OS_SaveContext(void *);
extern void OS_LoadContext(void *);
extern s32 func_020ce85c(void);

void OSi_RescheduleThread(void) {
    OSThread *current;
    OSThread *next;
    OSiThreadInfo *info = &OSi_ThreadInfo;

    if (OSi_SystemCallbackInSwitchThread.rescheduleCount != 0) {
        return;
    }
    if (info->flag != 0 || func_020ce85c() == 0x12) {
        info->state = 1;
        return;
    }
    current = *OSi_SystemCallbackInSwitchThread.currentThreadPtr;
    next    = OS_SelectThread();
    if (current == next || next == 0) {
        return;
    }
    if (current->state != 2) {
        if (OS_SaveContext(current) != 0) {
            return;
        }
    }
    if (OSi_SystemCallbackInSwitchThread.callback != 0) {
        OSi_SystemCallbackInSwitchThread.callback(current, next);
    }
    if (info->switchCallback != 0) {
        info->switchCallback(current, next);
    }
    OSi_SystemCallbackInSwitchThread.nextThread = next;
    OS_LoadContext(next);
}
