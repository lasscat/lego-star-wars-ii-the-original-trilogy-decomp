#include "m2c.h"

typedef void (*OSIrqFunction)(void);

typedef struct {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

extern OSIrqFunction OS_IRQTable[];
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[(7 + 1)];

void OS_SetIrqFunction(u32 intrBit, OSIrqFunction function) {
    int i;
    for (i = 0; i < 22; i++, intrBit >>= 1) {
        if (intrBit & 1) {
            OSIrqCallbackInfo *info = NULL;
            if (i >= 8 && i <= 11) {
                info = &OSi_IrqCallbackInfo[i - 8];
            } else if (i >= 3 && i <= 6) {
                info = &OSi_IrqCallbackInfo[i + 1];
            } else {
                OS_IRQTable[i] = function;
            }
            if (info != NULL) {
                info->func   = (void (*)(void *)) function;
                info->arg    = NULL;
                info->enable = 1;
            }
        }
    }
}
