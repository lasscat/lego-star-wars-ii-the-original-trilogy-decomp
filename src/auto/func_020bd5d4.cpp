#include "m2c.h"

extern "C" {
M2C_UNK func_0205e80c(s32 size, s32 align, s32 flags);
void func_020bd534(void *obj, s32 idx);
}

struct VTableSlots {
    void *m0;
    void *m1;
    void *m2;
};

extern "C" {
extern VTableSlots data_02101140;
extern VTableSlots data_02101154;
extern VTableSlots data_0210117c;
extern VTableSlots data_02101190;
}

class Obj {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2(void *arg);
    u8 pad[0x64];
    u32 f68;
    u32 f6c;
    u32 f70;
};

extern "C" void *func_020bd5d4(void *arg0) {
    Obj *obj;

    switch (*(u16 *) arg0) {
        case 0:
            obj = (Obj *) func_0205e80c(0x68, 3, 4);
            if (obj == 0) {
                break;
            }
            func_020bd534(obj, 0);
            *(void **) obj = (void *) &data_0210117c;
            break;
        case 1:
            obj = (Obj *) func_0205e80c(0x74, 3, 4);
            if (obj == 0) {
                break;
            }
            func_020bd534(obj, 3);
            *(void **) obj = (void *) &data_02101154;
            obj->f68       = 0;
            obj->f6c       = 0;
            obj->f70       = 0;
            break;
        case 2:
            obj = (Obj *) func_0205e80c(0x70, 3, 4);
            if (obj == 0) {
                break;
            }
            func_020bd534(obj, 0);
            *(void **) obj = (void *) &data_02101190;
            obj->f68       = 0;
            obj->f6c       = 0;
            break;
        case 3:
            obj = (Obj *) func_0205e80c(0x78, 3, 4);
            if (obj == 0) {
                break;
            }
            func_020bd534(obj, 3);
            *(void **) obj = (void *) &data_02101140;
            obj->f68       = 0;
            obj->f6c       = 0;
            obj->f70       = 0;
            break;
    }
    obj->m2(arg0);
    return obj;
}
