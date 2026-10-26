#include "m2c.h"

struct Sub23978 {
    virtual void u00();
    virtual void u04();
    virtual void u08();
    virtual void u0c();
    virtual void u10();
    virtual void u14();
    virtual void u18();
    virtual void u1c();
    virtual void u20();
    virtual void u24();
    virtual void u28();
    virtual void u2c();
    virtual void u30();
    virtual void u34();
    virtual void u38();
    virtual void u3c();
    virtual void u40();
    virtual void u44();
    virtual void u48();
    virtual void u4c();
    virtual void u50();
    virtual void u54();
};

class Obj23978 {
public:
    virtual void u00();
    virtual void u04();
    virtual void u08();
    virtual void u0c();
    virtual void u10();
    virtual void u14();
    virtual void u18();
    virtual void u1c();
    virtual void u20();
    virtual void u24(s32, s32, s32, s32);
};

typedef struct {
    s32 v;
} UnkVal;
extern "C" u8 data_0210930c[];
extern "C" void func_02012744(Obj23978 *, UnkVal);
extern "C" Sub23978 *func_02017800(Obj23978 *, s32);
extern "C" void func_020675d8(void *, s32);
extern "C" void func_020b8f70(s32, s32);

extern "C" void func_02023978(Obj23978 *self, UnkVal arg1, ...) {
    u8 *s = (u8 *) self;
    Sub23978 *p;
    switch (s[0x1bc]) {
        case 0:
            if (*(s32 *) (s + 0x218) != *(s32 *) (s + 0x21c)) {
                if (*(s32 *) (s + 0x218) >= 1) {
                    u16 v;
                    func_020b8f70(0x32, 0);
                    self->u24(0x8c, 0, 1, 0);
                    v = *(u16 *) (s + 0x212);
                    if (v == 0x14 || v == 0x126) {
                        s[0x1bc] = 1;
                    } else {
                        s[0x1bc] = 2;
                    }
                    if (s[0x221] != 0) {
                        func_020675d8(*(u8 **) (*(u8 **) (*(u8 **) (data_0210930c + 0x68) + 0x38c) + 4) + 0x28, s[0x221]);
                    }
                    p = func_02017800(self, 0);
                    if (p != 0) {
                        p->u50();
                    }
                }
                *(s32 *) (s + 0x218) = *(s32 *) (s + 0x21c);
            }
            break;
        case 1:
            break;
        case 2:
            if (*(s32 *) (s + 0x218) != *(s32 *) (s + 0x21c)) {
                *(s32 *) (s + 0x218) = *(s32 *) (s + 0x21c);
            } else {
                func_020b8f70(0x32, 0);
                *(s32 *) (s + 0x21c) = 0;
                *(s32 *) (s + 0x218) = 0;
                self->u24(0x8b, 0, 1, 0);
                s[0x1bc] = 0;
                if (s[0x222] != 0) {
                    func_020675d8(*(u8 **) (*(u8 **) (*(u8 **) (data_0210930c + 0x68) + 0x38c) + 4) + 0x28, s[0x222]);
                }
                p = func_02017800(self, 0);
                if (p != 0) {
                    p->u54();
                }
            }
            break;
    }
    func_02012744(self, arg1);
}
