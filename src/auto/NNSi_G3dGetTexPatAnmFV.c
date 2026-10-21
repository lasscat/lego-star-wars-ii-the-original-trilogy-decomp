/* Reconstructed from USA ARM9 at 0x020c6620 (116 bytes).
 *
 * Looks up the texture-pattern animation frame that covers the requested
 * value and returns its record.  The frame table is a table of 4-byte records
 * (u16 value, u8 texture index, u8 palette index) stored inside the
 * texture-pattern animation object; the per-index data block provides the
 * number of records, a 4.12 fixed point scale and the byte offset of the
 * table inside the animation object.
 */
#include "m2c.h"

/* One frame record of the texture-pattern animation table (4 bytes). */
typedef struct {
    u16 value;
    u8 texIdx;
    u8 plttIdx;
} NNSi_G3dTexPatAnmFrame;

/* Per-index animation data (8 bytes). */
typedef struct {
    u16 count;
    u16 unk2;
    s16 scale;
    u16 offset;
} NNSi_G3dTexPatAnmData;

extern s32 NNSi_G3dGetTexPatAnmDataByIdx(void *arg0, s32 arg1);

NNSi_G3dTexPatAnmFrame *NNSi_G3dGetTexPatAnmFV(void *arg0, s32 arg1, u32 arg2) {
    NNSi_G3dTexPatAnmData *data;
    NNSi_G3dTexPatAnmFrame *entries;
    u32 idx;
    u16 count;

    data    = (NNSi_G3dTexPatAnmData *) NNSi_G3dGetTexPatAnmDataByIdx(arg0, arg1);
    entries = (NNSi_G3dTexPatAnmFrame *) ((u8 *) arg0 + data->offset);
    idx     = (data->scale * arg2) >> 12;
    while (idx != 0 && entries[idx].value >= arg2) {
        idx--;
    }
    count = data->count;
    while (idx + 1 < count && entries[idx + 1].value <= arg2) {
        idx++;
    }
    return &entries[idx];
}
