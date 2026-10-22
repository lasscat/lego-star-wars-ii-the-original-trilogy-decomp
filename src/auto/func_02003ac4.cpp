typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef long s32;
typedef unsigned long u32;
typedef long long s64;

extern "C" {
s32 func_0208dad8(s32);
void func_0200c834(s32, s32);
void func_02003b5c(s32);
}

class CBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(u16 w, s32 flag);
};

extern "C" void func_02003ac4(CBase *obj) {
    u32 i;
    s32 v;
    u16 *p;
    u16 w;
    u16 *arr = (u16 *) obj;

    for (i = 0; i < 5; i++) {
        v = arr[0x374 + i];
        if (v == 0xfa) {
            continue;
        }
        p = (u16 *) func_0208dad8(v);
        w = *p;
        if (w == 0x276) {
            continue;
        }
        obj->f12(w, 1);
        break;
    }
    if (*(u16 *) ((u8 *) obj + 0x180) == 0xb && *(u16 *) ((u8 *) obj + 0x6e8) == 0x13) {
        *(u8 *) ((u8 *) obj + 0x6f3) = 0;
        func_0200c834((s32) obj, 3);
    }
    func_02003b5c((s32) obj);
}
