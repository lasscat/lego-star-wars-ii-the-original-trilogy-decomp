#include "m2c.h"

enum {
    VOICE_SLOTS           = 5,
    VOICE_NONE            = 0xFA,
    COORD_NONE            = 0xFFFF,
    MSG_KIND_PLAY         = 0x65,
    LISTENER_STRIDE       = 0x28,
    LISTENERS_OFFSET      = 0x1D0,
    LISTENER_DIRTY_OFFSET = 0x1DE,
    VOICE_IDS_OFFSET      = 0x6E8,
};

typedef struct MsgBuf {
    u16 v[5];
} MsgBuf;

typedef struct Voice {
    u8 pad0[8];
    u8 kind;
    u8 slot;
    u8 pad1[0x18];
    u16 x;
    u16 y;
    u8 pad2[1];
    u8 mode;
} Voice;

typedef struct Listener Listener;
struct Listener {
    void (**vtbl)(Listener *, void *, int, int, int);
};

extern const u16 data_020e5c9c[];
extern Voice *func_0208dad8(u32);

/* Scans the 5 voice ids of an object for a position source (kind 0) and a target (kind 3), then
 * sends the position message to the target's listener (virtual slot 2). Names guessed from callers. */
void func_02003b5c(u8 *arg0) {
    MsgBuf buf;
    MsgBuf init;
    u16 y, x;
    Voice *target;
    u8 i;

    init.v[0] = data_020e5c9c[0x1a / 2];
    init.v[1] = data_020e5c9c[0x1c / 2];
    init.v[2] = data_020e5c9c[0x1e / 2];
    init.v[3] = data_020e5c9c[0x20 / 2];
    init.v[4] = data_020e5c9c[0x22 / 2];
    target    = 0;
    x = y = COORD_NONE;
    for (i = 0; i < VOICE_SLOTS; i++) {
        u16 id = *(u16 *) (arg0 + VOICE_IDS_OFFSET + i * 2);
        if (id != VOICE_NONE) {
            Voice *v = func_0208dad8(id);
            if (v->kind == 0) {
                x = v->x;
                y = v->y;
            } else if (v->kind == 3) {
                target = v;
            }
        }
        if ((x != COORD_NONE || y != COORD_NONE) && target != 0) {
            Listener *sink;
            buf      = init;
            buf.v[1] = x;
            if (target->mode == 2 || target->mode == 0) {
                buf.v[1] = x;
            } else if (target->mode == 1) {
                buf.v[0] = MSG_KIND_PLAY;
                buf.v[1] = y;
            }
            sink = *(Listener **) (arg0 + target->slot * LISTENER_STRIDE + LISTENERS_OFFSET);
            if (sink != 0) {
                sink->vtbl[2](sink, &buf, 0, 1, 0);
                arg0[target->slot * LISTENER_STRIDE + LISTENER_DIRTY_OFFSET] = 1;
            }
        }
    }
}
