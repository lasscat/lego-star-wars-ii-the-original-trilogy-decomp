#include "m2c.h"

extern u32 data_0210930c;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad_000[4];
    void *field_4;
    u8 pad_008[4];
    u8 field_c;
    u8 field_d;
    u8 pad_00e[0x1c - 0x0e];
    s32 field_1c;
    u8 pad_020[4];
    s32 field_24;
    u8 pad_028[1];
    u8 field_29;
    u8 pad_02a[1];
    u8 field_2b;
    u8 field_2c;
    u8 pad_02d[2];
    u8 field_2f;
    u8 field_30;
    u8 field_31;
} Obj;

void func_020906a8(void *, void *, s32, s32);
void *func_02090688(void *, s32, s32);
void *func_020906ec(void *, s32);
void func_0202d934(void *, void *, s32, u8, s32);
void func_0202c01c(void *, void *);
void func_02004b68(void *, s32, void *, s32);
s32 func_02033810(Obj *);
void func_02033770(Obj *);

void func_0203351c(Obj *obj) {
    Vec3 buf;
    void *p;
    u32 limit;

    switch (obj->field_d) {
        case 0:
            func_020906a8(&buf, M2C_FIELD(&data_0210930c, void **, 0x68), obj->field_29, obj->field_30);
            p = func_02090688(M2C_FIELD(&data_0210930c, void **, 0x68), obj->field_29, obj->field_30);
            func_0202d934(obj->field_4, &buf, obj->field_24, M2C_FIELD(p, u8 *, 6), obj->field_1c);
            obj->field_d  = 1;
            obj->field_2f = obj->field_2b;
            return;
        case 1:
            if (obj->field_2f != 0) {
                obj->field_2f = obj->field_2f - 1;
                return;
            }
            limit = (u32) func_020906ec(M2C_FIELD(&data_0210930c, void **, 0x68), obj->field_29);
            switch (obj->field_2c) {
                case 3:
                    if (func_02033810(obj) != 0) {
                        obj->field_c = obj->field_c | 1;
                        func_0202c01c(obj->field_4 + 0x5e0, obj->field_4);
                        func_02004b68(obj->field_4, 1, obj->field_4, 2);
                        return;
                    }
                case 0:
                    obj->field_30 = obj->field_30 + 1;
                    if (obj->field_30 >= limit) {
                        obj->field_30 = 0;
                    }
                    break;
                case 4:
                    if (func_02033810(obj) != 0) {
                        obj->field_c = obj->field_c | 1;
                        func_0202c01c(obj->field_4 + 0x5e0, obj->field_4);
                        func_02004b68(obj->field_4, 1, obj->field_4, 2);
                        return;
                    }
                case 1:
                    obj->field_30 = obj->field_30 + 1;
                    if (obj->field_30 >= limit) {
                        func_02033770(obj);
                    }
                    break;
                case 5:
                    if (func_02033810(obj) != 0) {
                        obj->field_c = obj->field_c | 1;
                        func_0202c01c(obj->field_4 + 0x5e0, obj->field_4);
                        func_02004b68(obj->field_4, 1, obj->field_4, 2);
                        return;
                    }
                case 2:
                    if (obj->field_31 != 0) {
                        obj->field_30 = obj->field_30 + 1;
                        if (obj->field_30 >= limit) {
                            obj->field_30 = limit - 1;
                            obj->field_31 = 0;
                        }
                    } else {
                        obj->field_30 = obj->field_30 - 1;
                        if (obj->field_30 >= limit) {
                            obj->field_30 = 1;
                            obj->field_31 = 1;
                        }
                    }
                    break;
            }
            obj->field_d = 0;
            return;
    }
}
