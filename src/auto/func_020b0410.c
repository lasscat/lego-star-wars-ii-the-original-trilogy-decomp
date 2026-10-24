#include "m2c.h"

typedef struct {
    u8 len;
    u8 flag;
    u16 value;
} Record;

typedef union {
    u32 words[0xD1];
    Record rec[0xD1];
} Player;

typedef struct {
    u8 pad0[0x40];
    u8 last[0x9FC];
    Player player[4];
} Mgr;

extern void *data_021092f4;

void func_02001688(s32);
void func_020016c0(void);
s32 func_02073034(void);
void func_020b1248(Mgr *, Record *, u8);

void func_020b0410(Mgr *mgr) {
    u8 pos;
    u8 i;
    s32 j;
    Record *rec;

    func_02001688(0);
    for (i = 0; (s32) i < func_02073034(); i++) {
        pos = 0;
        j   = -1;
        while ((mgr->player[i].words[pos] & 0xFF) != 0) {
            j++;
            rec = &mgr->player[i].rec[pos];
            pos += mgr->player[i].words[pos] & 0xFF;
            if (rec->value != mgr->last[i * 10 + j] && rec->flag != 0) {
                mgr->last[i * 10 + j] = rec->value;
                func_020b1248(mgr, rec, i);
                if (data_021092f4 == 0) {
                    func_020016c0();
                    return;
                }
            }
        }
    }
    func_020016c0();
}
