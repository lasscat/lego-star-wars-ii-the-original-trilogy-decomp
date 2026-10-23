#include "m2c.h"

typedef struct MatchStruct MatchStruct;
typedef struct MatchKey MatchKey;

typedef void (*MatchFunc)(MatchStruct *, MatchKey *, void *);

typedef struct {
    u8 id;
    u8 id2;
    u16 code;
    MatchFunc func;
} MatchEntry;

struct MatchStruct {
    u32 unk0;
    u32 unk4;
    void *unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u8 unk18;
};

struct MatchKey {
    u8 id;
    u16 code;
};

extern u32 data_021012fc;
extern MatchEntry data_02101320[];

void func_020c38f0(MatchStruct *arg0, MatchKey *arg1, void *arg2, void *arg3) {
    u32 i;

    arg0->unk0  = 0;
    arg0->unk8  = arg1;
    arg0->unk10 = 0;
    arg0->unk18 = 0x7F;
    arg0->unk4  = 0x1000;
    arg0->unk14 = arg3;
    for (i = 0; i < data_021012fc; i++) {
        if (arg1->id == data_02101320[i].id && arg1->code == data_02101320[i].code) {
            data_02101320[i].func(arg0, arg1, arg2);
            return;
        }
    }
}
