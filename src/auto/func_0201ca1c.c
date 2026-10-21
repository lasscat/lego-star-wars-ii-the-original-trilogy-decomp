/* Reconstructed from USA ARM9 at 0x0201ca1c (396 bytes).
 * Maps an object "type" id to a model id; 0xFFFF means "no model".
 */
#include "m2c.h"

u16 func_0201ca1c(u16 arg0) {
    switch ((u32) arg0) {
        case 0:
        case 1:
        case 5:
        case 8:
        case 11:
        case 12:
        case 14:
        case 423:
        case 513:
        case 514:
        case 515:
        case 516:
        case 517:
        case 521:
        case 525:
            return 2837;
        case 424:
        case 429:
        case 438:
        case 440:
        case 441:
        case 450:
        case 460:
        case 466:
        case 473:
        case 476:
            return 1222;
        default:
            return 65535;
    }
}
