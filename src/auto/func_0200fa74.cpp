#include "m2c.h"

class Obj {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    void *f04;
};

extern u8 data_021019f4[];
extern u8 data_02101b38[];
extern u8 data_027e0308[];

extern "C" void func_0205e234(void *);
extern "C" void func_0205d7a4(void *);

extern "C" void func_0200fa74(Obj *self) {
    Obj *node = *(Obj **) ((u8 *) self + 4);

    while (node != 0) {
        Obj *obj = *(Obj **) node;
        if (obj != 0) {
            obj->unknown04();
        }
        node = *(Obj **) ((u8 *) self + 4);
    }
    self->unknown18();
    if (self == (Obj *) data_021019f4) {
        func_0205e234(data_02101b38);
        func_0205d7a4(data_027e0308);
    }
}
