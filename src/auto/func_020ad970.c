#include "m2c.h"

extern void func_020ad7a4(s32);
extern void func_020ad528(const char *fmt, ...);
extern u16 WM_GetDispersionBeaconPeriod(void);
extern void OS_GetOwnerInfo(void *);
extern u16 *func_0205e818(u32 size, s32 a, s32 b);
extern void *func_0205e6e0(void *dst, const void *src, u32 len);
extern s32 func_020ae0d8(void);
extern char data_020fffe8[];
extern char data_02100014[];
extern u16 data_0210b3e0[];

typedef struct {
    u8 f00;
    u8 pad01[0x43];
    s32 mode;
    u8 pad48[0x38];
    u16 *nameBuf;      /* name guessed from callers */
    u16 nameBufSize;   /* bytes */
    u8 pad86[6];
    u16 f8c;
    u16 f8e;
    u16 f90;
    u16 f92;
    u16 f94;
    u16 f96;
    u16 beaconPeriod;
    u8 pad9a[0x18];
    u16 fb2;
    u16 fb4;
    u16 fb6;
    u8 padb8[8];
    u16 userName[1];   /* first char of the name stored by func_020ad540 (data_0210b3e0) */
} State;

typedef struct {
    u8 pad[4];
    u16 nickName[10];
    u16 nickNameLength;
    u8 rest[0x36];
} OwnerInfo;

enum {
    NAME_BUF_ALIGN = 0x20, /* name guessed from callers */
};

extern u8 data_0210b320[];

static inline State *get_work(void) {
    return (State *) data_0210b320;
}

static inline u16 read_u16(const void *p, int i) {
    return ((const u16 *) p)[i];
}

static inline int is_less(int a, int b) {
    if (a < b) {
        return 1;
    }
    return 0;
}

static inline int is_nonzero(u16 c) {
    if (c == 0) {
        return 0;
    }
    return 1;
}

static inline int wstr_len(const u16 *s) {
    int n = 0;
    while (is_nonzero(s[n])) {
        n++;
    }
    return n;
}

/* Set up the work area for a session in the given mode (beacon parameters), then copy the user name
   (owner nickname, or the name stored at data_0210b3e0) into a newly allocated buffer. */
s32 func_020ad970(s32 arg0, s32 mode, u16 arg2, u16 arg3, u8 arg4) {
    OwnerInfo owner;
    int i;

    get_work()->mode = mode;
    get_work()->f00  = arg4;
    func_020ad7a4(3);
    get_work()->f8c          = arg2;
    get_work()->fb2          = arg3;
    get_work()->beaconPeriod = WM_GetDispersionBeaconPeriod();
    get_work()->fb4          = 0x200;
    get_work()->fb6          = 0x7c;
    get_work()->f90          = 3;
    get_work()->f96          = 0;
    get_work()->f92          = 0;
    get_work()->f8e          = 1;
    get_work()->f94          = (mode == 2);
    func_020ad528(data_020fffe8);
    if (get_work()->userName[0] == 0) {
        OS_GetOwnerInfo(&owner);
        get_work()->nameBuf     = func_0205e818(owner.nickNameLength * sizeof(u16), 3, NAME_BUF_ALIGN);
        get_work()->nameBufSize = owner.nickNameLength * 2;
        for (i = 0; is_less(i, owner.nickNameLength); i++) {
            get_work()->nameBuf[i] = read_u16(owner.nickName, i);
        }
    } else {
        int n                   = wstr_len(data_0210b3e0);
        get_work()->nameBuf     = func_0205e818(n * sizeof(u16), 3, NAME_BUF_ALIGN);
        get_work()->nameBufSize = n * 2;
        func_0205e6e0(get_work()->nameBuf, data_0210b3e0, n * 2);
    }
    if (mode == 0 || mode == 2 || mode == 4) {
        return func_020ae0d8();
    }
    func_020ad528(data_02100014, mode);
    return 0;
}
