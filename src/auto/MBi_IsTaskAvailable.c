#include "m2c.h"

extern s32 mbi_task_work;

s32 MBi_IsTaskAvailable(void) {
    if (mbi_task_work != 0) {
        return 1;
    }
    return 0;
}
