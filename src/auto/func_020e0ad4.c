/* compiler: 2.0/sp1p5 -O2,p */
typedef struct Thr {
    unsigned char pad[0x6C];
    int id;
} Thr;
typedef struct TInfo {
    int w0;
    Thr *cur;
} TInfo;
typedef struct Cs {
    int w[3];
    int v;
} Cs;
extern int func_020e0f50(void *, int);
extern int OS_TryLockMutex(void *);
extern void OS_LockMutex(void *);
extern void OS_UnlockMutex(void *);
extern int __pformatter(void *, void *, char *, void *);
extern unsigned char data_021015dc[];
extern unsigned char data_0211ebf0[];
extern TInfo OSi_ThreadInfo;
extern Cs __cs_id;
extern Cs __cs_ref;
extern unsigned char func_020e0a64;

int func_020e0ad4(char *fmt, ...) {
    int r;
    if (func_020e0f50(data_021015dc, -1) >= 0) {
        return -1;
    }
    if (OS_TryLockMutex(data_0211ebf0) == 0) {
        __cs_id.v  = OSi_ThreadInfo.cur->id;
        __cs_ref.v = 1;
    } else if (__cs_id.v == OSi_ThreadInfo.cur->id) {
        __cs_ref.v = __cs_ref.v + 1;
    } else {
        OS_LockMutex(data_0211ebf0);
        __cs_id.v  = OSi_ThreadInfo.cur->id;
        __cs_ref.v = 1;
    }
    r          = __pformatter(&func_020e0a64, data_021015dc, fmt, (void *) ((((unsigned int) &fmt) & ~3) + 4));
    __cs_ref.v = __cs_ref.v - 1;
    if (__cs_ref.v == 0) {
        OS_UnlockMutex(data_0211ebf0);
    }
    return r;
}
