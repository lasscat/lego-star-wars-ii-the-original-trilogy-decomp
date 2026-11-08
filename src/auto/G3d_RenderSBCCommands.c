#include "m2c.h"

typedef struct RS RS;
typedef void (*SbcFunc)(RS *rs, u32 opt);

struct RS {
    u8 *c;          /* 0x00 */
    void *pRenderObj; /* 0x04 */
    u32 flag;       /* 0x08 */
};

enum {
    RSFLAG_END   = 0x20, /* set by the slot-1 handler func_01ffb680 */
    RSFLAG_SKIP  = 0x40,
    SBC_OP_MASK  = 0x1f,
    SBC_OPT_MASK = 0xe0,
};

extern SbcFunc data_02101498[32];

/*
 * SBC (structure byte code) interpreter loop: clears the skip flag, reads the
 * current command byte, and dispatches its low 5 bits through the SBC command
 * table (data_02101498), passing the high 3 bits as the option. Repeats until
 * a handler sets the end flag (0x20).
 */
void G3d_RenderSBCCommands(RS *rs) {
    do {
        u8 cmd;
        rs->flag &= ~RSFLAG_SKIP;
        cmd = *rs->c;
        data_02101498[cmd & SBC_OP_MASK](rs, cmd & SBC_OPT_MASK);
    } while (!(rs->flag & RSFLAG_END));
}
