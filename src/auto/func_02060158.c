#include "m2c.h"

/* func_02060158 (0x02060158, 44 bytes)
 *
 * The function is variadic: the "push {r0, r1, r2, r3}" prologue is MWCC's
 * argument home area, which only variadic functions get.  The four named
 * arguments arrive in r0-r3 and are also spilled to that home area, the
 * variadic arguments arrive on the stack.
 *
 * It forwards the four named arguments plus a pointer to the variadic
 * argument list to func_02060084, which walks that list using the count
 * held in the fourth argument.
 *
 * "va_start" is the MWCC/AAPCS form used elsewhere in this project: the
 * variadic list starts at the word following the last named argument, i.e.
 * at the caller's stack pointer.  The "bic #3 / add #4" pair computes that
 * from the address of the fourth parameter.
 */

typedef char *va_list;
extern void func_02060084(s32, s32, s32, s32, void *);

#ifndef va_start
    #define va_start(ap, last)                                                                                            \
        ((ap) = ((va_list) ((char *) ((unsigned int) (&(last)) & ~3U) + ((((unsigned int) (sizeof(last))) + 3U) & ~3U))))
#endif

void func_02060158(s32 a0, s32 a1, s32 a2, s32 a3, ...) {
    va_list ap;
    va_start(ap, a3);
    func_02060084(a0, a1, a2, a3, ap);
}
