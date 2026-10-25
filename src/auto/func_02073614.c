#include "m2c.h"

extern M2C_UNK data_0210794c;

typedef struct {
    u16 offset;
    u16 size;
    u8 data[0x58];
} Packet_0x5C;

typedef struct {
    s32 f00;
    u16 f04;
    u8 pad[0x16];
} Packet_0x1C_3;

typedef struct {
    s32 size;
    u8 pad[0x18];
} Packet_0x1C_6;

typedef struct {
    u8 pad0[0xA0];
    u8 *fA0;
    u32 fA4;
    u8 pad1[0xE0A8 - 0xA8];
    u8 fE0A8;
    u8 pad2;
    u16 fE0AA;
    u16 fE0AC;
    u8 fE0AE;
    u8 fE0AF;
    u8 fE0B0;
    u8 fE0B1;
    u16 fE0B2;
} Obj_02073614;

static inline void setup_pkt(Packet_0x5C *pkt, u16 offset, u8 *base, u16 *p_off) {
    pkt->offset = offset;
    memcpy(pkt->data, base + *p_off, pkt->size);
}

void func_02073614(Obj_02073614 *arg0) {
    Packet_0x5C dst_pkt;
    Packet_0x5C src_pkt;
    Packet_0x1C_6 pkt6;
    Packet_0x1C_3 pkt3;

    if (arg0->fE0B0 == 0) {
        pkt6.size = arg0->fA4;
        func_020b04f0(&data_0210794c, 6, &pkt6, 0xFF);
        arg0->fE0B0 = 1;
        return;
    }

    if (arg0->fE0AA < arg0->fA4) {
        u32 rem = arg0->fA4 - arg0->fE0AA;
        if (rem > 0x58) {
            src_pkt.size = 0x58;
        } else {
            src_pkt.size = rem;
        }
        setup_pkt(&src_pkt, arg0->fE0AA, arg0->fA0, &arg0->fE0AA);
        arg0->fE0AA += src_pkt.size;
        memcpy(&dst_pkt, &src_pkt, 0x5C);
        func_020b04f0(&data_0210794c, 2, &dst_pkt, 0x5C);
        arg0->fE0AE = 1;
        return;
    }

    if (arg0->fE0A8 == 0) {
        pkt3.f04    = func_02062ae4(5000);
        arg0->fE0B2 = pkt3.f04;
        func_020b04f0(&data_0210794c, 3, &pkt3, 0xFF);
        arg0->fE0AE = 1;
        arg0->fE0A8 = 1;
    }
}
