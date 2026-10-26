#include "m2c.h"

/* One-word by-value wrapper: the original takes the step in r1 and reads it
 * back from the argument home area (push {r0-r3} prologue). */
typedef struct {
    s32 v;
} Step;

enum {
    FLAG_KEEP_ACTIVE = 0x2,         /* on expiry clear the active byte instead of setting DONE */
    FLAG_DONE        = 0x80000000,  /* timer finished; also stops the per-step update loop */
};

extern void func_020bc568(void *self, Step dt);
extern s32 func_020bd720(void *obj, Step dt);
extern void func_020bca64(void *self);

/* Advances an object by one step (dt): runs func_020bc568, then repeats the
 * per-item update func_020bca64 (items * steps from func_020bd720) while the
 * active byte is set, and counts down the timer at +0x398; on expiry it
 * either clears the active byte or marks the object done. */
void func_020bc3cc(void *self, Step dt) {
    s32 n;
    s32 i;
    s32 j;
    s32 timer;
    u32 flags;

    if (M2C_FIELD(self, void **, 0x48) == NULL) {
        return;
    }
    func_020bc568(self, dt);
    if (M2C_FIELD(self, u8 *, 0x39c) != 0 && !(M2C_FIELD(self, u32 *, 0x384) & FLAG_DONE)) {
        n = func_020bd720(M2C_FIELD(self, void **, 0x48), dt);
        for (i = 0; i < n; i++) {
            for (j = 0; j < M2C_FIELD(M2C_FIELD(self, s32 **, 0x48), s32 *, 4); j++) {
                func_020bca64(self);
            }
        }
    }
    timer = M2C_FIELD(self, s32 *, 0x398);
    if (timer == 0) {
        return;
    }
    timer -= dt.v;
    M2C_FIELD(self, s32 *, 0x398) = timer;
    if (timer > 0) {
        return;
    }
    flags = M2C_FIELD(self, u32 *, 0x384);
    if (flags & FLAG_KEEP_ACTIVE) {
        M2C_FIELD(self, u8 *, 0x39c) = 0;
    } else {
        M2C_FIELD(self, u32 *, 0x384) = flags | FLAG_DONE;
    }
    M2C_FIELD(self, s32 *, 0x398) = 0;
}
