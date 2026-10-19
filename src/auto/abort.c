#include "engine.h"
#include "m2c.h"

void exit(M2C_UNK);
void raise(M2C_UNK);

extern M2C_UNK __console_exit;

void abort(void) {
    raise(1);
    M2C_FIELD(&__console_exit, s32 *, 0xC) = 1;
    exit(1);
}
