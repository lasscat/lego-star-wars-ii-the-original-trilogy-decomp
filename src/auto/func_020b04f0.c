#include "m2c.h"

typedef struct {
    s8 len;
    u8 flag;
    u16 value;
} Record;

enum {
    REC_LONG_SIZE   = 0x5c,     /* payload size that selects the long record */
    SIZE_DEFAULT    = 0xff,      /* size value meaning "use default" */
    DEFAULT_PAYLOAD = 0x1c,   /* payload size used for SIZE_DEFAULT */
    SHORT_LIMIT     = 0x20,       /* capacity of a short record, bytes */
    LONG_LIMIT      = 0x60,        /* capacity of a long record, bytes */
};

typedef struct {
    u8 pad0[0x68];
    u8 counter; /* running sequence number */
    u8 pad69[3];
    u8 skip;
    u8 pad6d[3];
    u32 words[0x5B7];
    u8 pos; /* write offset into words, in words */
} Obj;

int func_020b3280(void *, u32);
int func_020b33b4(void *, int);

/* Appends a tagged record (kind id, payload src/size) to the obj's record
   buffer, padding it to a word multiple; len is stored in words. */
void func_020b04f0(Obj *obj, u8 id, /* name guessed from callers */ void *src, u8 size) {
    Record *short_rec;
    Record *long_rec;
    u32 pad_room;
    u32 len;

    if (func_020b3280(obj, id) != 0 && obj->skip == 0) {
        return;
    }
    obj->counter++;
    short_rec = NULL;
    long_rec  = NULL;
    if (size == REC_LONG_SIZE) {
        long_rec = (Record *) &obj->words[obj->pos];
    } else {
        short_rec = (Record *) &obj->words[obj->pos];
    }
    if (size == SIZE_DEFAULT) {
        size = DEFAULT_PAYLOAD;
    }
    if (long_rec != NULL) {
        pad_room       = (u16) (LONG_LIMIT - size);
        long_rec->flag = id;
    } else {
        pad_room        = (u16) (SHORT_LIMIT - size);
        short_rec->flag = id;
    }
    if (func_020b33b4(obj, id) != 0) {
        if (long_rec != NULL) {
            memcpy((u8 *) long_rec + 4, src, size);
        } else {
            memcpy((u8 *) short_rec + 4, src, size);
        }
    }
    size = (u8) (size + pad_room);
    if (size % 4 != 0) {
        size = (u8) (size + (4 - size % 4));
    }
    len = (u32) size >> 2;
    if (long_rec != NULL) {
        long_rec->len = len;
        obj->pos += (u8) len;
        long_rec->value = obj->counter;
    } else {
        short_rec->len = len;
        obj->pos += (u8) len;
        short_rec->value = obj->counter;
    }
}
