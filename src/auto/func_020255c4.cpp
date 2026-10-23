#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

/* By-value argument kept in the register save area (variadic tail). */
typedef struct {
    s32 v;
} UnkVal;

/* Halfword at offset 0x14e of the object; bit 1 is the flag tested here. */
typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
} UnkFlags;

extern "C" void func_02012744(void *obj, UnkVal arg1);

extern "C" void func_020255c4(Entity *obj, UnkVal arg1, ...) {
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0:
            if (M2C_FIELD(obj, u16 *, 0x212) == 0x161) {
                if (M2C_FIELD(obj, u8 *, 0x214) == 7) {
                    M2C_FIELD(obj, u8 *, 0x1bc)  = 1;
                    M2C_FIELD(obj, u16 *, 0x1be) = 0x3c;
                }
            }
            break;
        case 1:
            if (M2C_FIELD(obj, u16 *, 0x212) == 0x161) {
                s16 v                        = M2C_FIELD(obj, s16 *, 0x1be);
                M2C_FIELD(obj, s16 *, 0x1be) = v - 1;
                if (v == 0) {
                    obj->action(0x44, 0, 1, 1);
                    M2C_FIELD(obj, u8 *, 0x1bc) = 2;
                }
            }
            break;
        case 2:
            if (M2C_FIELD(obj, u16 *, 0x212) == 0x161) {
                UnkFlags *flags = (UnkFlags *) ((u8 *) obj + 0x14e);
                if (flags->flag_b == 1) {
                    obj->action(0x52, 0, 1, 0);
                    M2C_FIELD(obj, u8 *, 0x1bc)  = 0;
                    M2C_FIELD(obj, s32 *, 0x194) = 0x600;
                    M2C_FIELD(obj, u8 *, 0x214)  = 8;
                }
            }
            break;
    }

    {
        void *area = M2C_FIELD(obj, void **, 0x21c);
        if (area != 0) {
            s32 flag;
            if (M2C_FIELD(obj, void **, 0x3c) != 0) {
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag != 0) {
                void *other = M2C_FIELD(obj, void **, 0x3c);
                s32 t[3];
                s32 *dst;
                s32 z = M2C_FIELD(other, s32 *, 0xc) - M2C_FIELD(area, s32 *, 0xb8);
                s32 y = M2C_FIELD(other, s32 *, 8) - M2C_FIELD(area, s32 *, 0xb4);
                s32 x = M2C_FIELD(other, s32 *, 4) - M2C_FIELD(area, s32 *, 0xb0);
                t[0]  = x;
                t[1]  = y;
                t[2]  = z;
                dst   = (s32 *) ((u8 *) M2C_FIELD(obj, void **, 0x21c) + 0x60);
                if (dst != t) {
                    dst[0] = t[0];
                    dst[1] = t[1];
                    dst[2] = t[2];
                }
            } else {
                s32 *src = (s32 *) ((u8 *) obj + 0xb0);
                s32 flag2;
                if (M2C_FIELD(area, s32 *, 0xb0) != src[0] || M2C_FIELD(area, s32 *, 0xb4) != src[1] ||
                    M2C_FIELD(area, s32 *, 0xb8) != src[2]) {
                    flag2 = 1;
                } else {
                    flag2 = 0;
                }
                if (flag2 != 0) {
                    if ((s32 *) ((u8 *) area + 0xb0) != src) {
                        M2C_FIELD(area, s32 *, 0xb0) = src[0];
                        M2C_FIELD(area, s32 *, 0xb4) = src[1];
                        M2C_FIELD(area, s32 *, 0xb8) = src[2];
                    }
                    M2C_FIELD(area, u8 *, 0xd1) = 1;
                }
            }
        }
    }

    func_02012744(obj, arg1);
}
