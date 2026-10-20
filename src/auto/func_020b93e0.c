/* Reconstructed from USA ARM9 at 0x020b93e0 (84 bytes).
 *
 * The function walks one group of the entry table at 0x02100d98.
 * The group descriptor table at 0x02100a74 holds 4-byte records:
 *
 *   0x02100a74 + 4 * group:  u16 count; u16 first;
 *
 * (0x02100a76 is the "first" field of the same records) and the entry
 * table at 0x02100d98 holds 4-byte records:
 *
 *   0x02100d98 + 4 * index:  u16 id;    u16 flags;
 */
#include "m2c.h"

extern u8 data_02100a74[];
extern u8 data_02100a76[];
extern u8 data_02100d98[];

void func_020ba948(s32);

typedef struct {
    u16 id;
    u16 flags;
} Entry;

void func_020b93e0(s32 a0) {
    u32 i;
    u32 count = *(u16 *) (data_02100a74 + a0 * 4);
    u32 first = *(u16 *) (data_02100a76 + a0 * 4);

    for (i = 0; i < count; i++) {
        func_020ba948(((Entry *) data_02100d98)[first + i].id);
    }
}
