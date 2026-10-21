/* Reconstructed from USA ARM9 at 0x0209444c (452 bytes).
 *
 * Sets up the four texture slots of the object (0xb0, 0xc0, 0xd0, 0xe0),
 * uploads the two texture pages and the palette sizes returned by the
 * string helpers, and finally installs the callback pair of
 * data_020ff810 (slot 1 for mode 1/2, slot 0 otherwise).
 *
 * data_020ff810 holds two {callback, parameter} slots; the pair is copied
 * into the object as one 8-byte aggregate.
 */
#include "m2c.h"

typedef void (*Callback)(void);

typedef struct {
    Callback cb;
    void *param;
} Slot;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
} Tex;

typedef struct {
    u8 pad00[0xa8];
    Slot f_a8;
    Tex f_b0;
    Tex f_c0;
    Tex f_d0;
    Tex f_e0;
    u16 f_f0;
    u8 padf2[5];
    u8 f_f7;
    u8 f_f8;
} Obj;

extern Slot data_020ff810[2];

void func_02064fd0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void *func_0205e818(s32, s32, s32);
s32 func_0205e6e0(s32, s32, s32);
void func_0205e860(s32);
char *func_0205ab30(u32);
s32 func_0205ab58(u32);
void func_0205ab6c(u32);
void func_020651d0(void *, s32, s32, s32);
u8 func_02093fa8(s32);

void func_0209444c(Obj *arg0, s32 arg1) {
    void *buf;
    char *s;
    s32 n;

    func_02064fd0(&arg0->f_b0, 0x2000, 0xc0, 0, 0);
    func_02064fd0(&arg0->f_c0, 0, 0xc0, 0, 0);
    func_02064fd0(&arg0->f_d0, 0, 0xc0, 0, 0);
    func_02064fd0(&arg0->f_e0, 0, 0x40, 0, 0);

    buf = func_0205e818(0x2000, 3, 4);
    s   = func_0205ab30(0xd78);
    func_0205e6e0(buf, s, 0x1000);
    s = func_0205ab30(0xa48);
    func_0205e6e0((s8 *) buf + 0x1000, s, 0x1000);

    n = func_0205ab58(0xd7d);
    func_020651d0(&arg0->f_b0, buf, n, 1);
    func_0205e860(buf);
    n = func_0205ab58(0xd7c);
    func_020651d0(&arg0->f_c0, 0, n, 1);
    n = func_0205ab58(0xd7b);
    func_020651d0(&arg0->f_d0, 0, n, 1);
    n = func_0205ab58(0xa4c);
    func_020651d0(&arg0->f_e0, 0, n, 1);

    func_0205ab6c(0xd78);
    func_0205ab6c(0xa48);

    if (func_02093fa8(arg1) == 1 || func_02093fa8(arg1) == 2) {
        arg0->f_f7 = 1;
        arg0->f_a8 = data_020ff810[1];
    } else {
        arg0->f_a8 = data_020ff810[0];
    }
    arg0->f_f0 = 0;
    arg0->f_f8 = 1;
}
