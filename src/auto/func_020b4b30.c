#include "m2c.h"

/* Load tracker instruments, key maps and shared envelopes from the current stream. */
typedef struct {
    u16 *ticks;
    s8 *values;
    u8 flags;
    u8 pointCount;
    u8 loopStart;
    u8 loopEnd;
    u8 sustainStart;
    u8 sustainEnd;
    u8 unknown0e[2];
} Envelope;
typedef struct {
    u8 volume;
    u8 pan;
    u8 flags;
    u8 ownedData;
    u16 fadeout;
    s8 pitch;
    u8 vibratoType;
    u8 vibratoSweep;
    u8 vibratoDepth;
    u8 vibratoRate;
    u8 unknown0b;
    u8 *sampleMap;
    s8 *pitchMap;
    Envelope *envelopes[3];
} Instrument;
typedef struct {
    void *samples;
    Instrument *instruments;
    u8 unknown08[0x27];
    u8 instrumentCount;
} Player;
typedef struct {
    Player *player;
    u32 unknown04;
    u8 *arena;
    u8 unknown0c[0xc];
    u32 used;
    u32 capacity;
} LoaderState;
typedef struct {
    u8 unknown00[0x20];
    u32 envelopeTicks;
    u32 envelopeValues;
    u32 unknown28;
    u32 instruments;
    u8 unknown30[0xc];
    u32 envelopes;
    u32 sampleMaps;
    u32 pitchMaps;
} FileTables;
typedef struct {
    u8 volume;
    u8 pan;
    u8 flags;
    u8 unknown03;
    u16 fadeout;
    s8 pitch;
    u8 vibratoType;
    u8 vibratoSweep;
    u8 vibratoDepth;
    u8 vibratoRate;
    u8 unknown0b;
    u16 sampleMap;
    u16 pitchMap;
    u16 envelopes[3];
} InstrumentHeader;
typedef struct {
    u8 flags;
    u8 pointCount;
    u8 loopStart;
    u8 loopEnd;
    u8 sustainStart;
    u8 sustainEnd;
    u16 ticks;
    u16 values;
} EnvelopeHeader;

/* The original loader records span several separately named BSS fragments.
 * Keep the owning symbols' declarations and view their observed field layouts. */
extern LoaderState data_0210daf0;
extern FileTables data_0210dbd0;
extern u32 data_027e02a8[1];
extern u32 data_02101d7c[1];

extern void *func_020ba798(void *, u32);
extern void func_020ba778(u32, s32);
extern u32 func_020ba7c8(void);
extern void *func_0205e540(u32, s32, s32);
extern void *func_0205e624(void *, u32, u32);
extern void MIi_LockCard(void);
extern u32 CARDi_ReadRomID(void);
extern void MIi_UnlockCard(void);
extern void func_02054e78(s32);

static inline s32 cardChanged(void) {
    if (data_027e02a8[0] & 0x800) {
        u32 id;
        MIi_LockCard();
        id = CARDi_ReadRomID();
        MIi_UnlockCard();
        if (id != data_02101d7c[0]) {
            return 1;
        }
    }
    return 0;
}
static inline void allocationFailure(void) {
    if (cardChanged()) {
        func_02054e78(0);
        for (;;) {
        }
    }
}

void func_020b4b30(s32 heap) {
    u16 instrumentIndices[100];
    u16 sampleMapIndices[100];
    u16 pitchMapIndices[100];
    u16 envelopeIndices[100][3];
    InstrumentHeader instrumentHeader;
    EnvelopeHeader envelopeHeader;
    u32 offset;
    u32 savedPosition;
    s32 i, k, slot;
    Instrument *instrument;
    s32 envelopeSlot;
    Envelope *envelope;

    func_020ba798(instrumentIndices, data_0210daf0.player->instrumentCount * 2);
    savedPosition = func_020ba7c8();
    for (i = 0; i < 100; i++) {
        sampleMapIndices[i] = 0xffff;
        pitchMapIndices[i]  = 0xffff;
        for (k = 0; k < 3; k++) {
            envelopeIndices[i][k] = 0xffff;
        }
    }
    if (heap) {
        data_0210daf0.player->instruments =
            func_0205e540((data_0210daf0.player->instrumentCount + 1) * sizeof(Instrument), 3, 4);
        if (data_0210daf0.player->instruments == NULL) {
            allocationFailure();
        }
    } else {
        data_0210daf0.player->instruments = (Instrument *) (data_0210daf0.arena + data_0210daf0.used);
        data_0210daf0.used += (((data_0210daf0.player->instrumentCount + 1) * sizeof(Instrument)) + 3) & ~3;
        if (data_0210daf0.used >= data_0210daf0.capacity) {
            allocationFailure();
        }
    }
    func_0205e624(data_0210daf0.player->instruments, 0, (data_0210daf0.player->instrumentCount + 1) * sizeof(Instrument));
    for (i = 1; i < data_0210daf0.player->instrumentCount + 1; i++) {
        offset = data_0210dbd0.instruments + instrumentIndices[i - 1] * 0x18;
        func_020ba778(offset, 0);
        func_020ba798(&instrumentHeader, sizeof(instrumentHeader));
        instrument               = &data_0210daf0.player->instruments[i];
        instrument->volume       = instrumentHeader.volume;
        instrument->pan          = instrumentHeader.pan;
        instrument->flags        = instrumentHeader.flags;
        instrument->fadeout      = instrumentHeader.fadeout;
        instrument->pitch        = instrumentHeader.pitch;
        instrument->vibratoType  = instrumentHeader.vibratoType;
        instrument->vibratoSweep = instrumentHeader.vibratoSweep;
        instrument->vibratoDepth = instrumentHeader.vibratoDepth;
        instrument->vibratoRate  = instrumentHeader.vibratoRate;
        instrument->unknown0b    = instrumentHeader.unknown0b;
        sampleMapIndices[i]      = instrumentHeader.sampleMap;
        pitchMapIndices[i]       = instrumentHeader.pitchMap;
        for (k = 0; k < 3; k++) {
            envelopeIndices[i][k] = instrumentHeader.envelopes[k];
        }

        instrument->sampleMap = NULL;
        for (k = i - 1; k >= 1; k--) {
            if (sampleMapIndices[i] == sampleMapIndices[k]) {
                instrument->sampleMap = data_0210daf0.player->instruments[k].sampleMap;
                break;
            }
        }
        if (instrument->sampleMap == NULL) {
            instrument->ownedData |= 1;
            if (heap) {
                instrument->sampleMap = func_0205e540(120, 3, 4);
                if (instrument->sampleMap == NULL) {
                    allocationFailure();
                }
            } else {
                instrument->sampleMap = (u8 *) (data_0210daf0.arena + data_0210daf0.used);
                data_0210daf0.used += 120;
                if (data_0210daf0.used >= data_0210daf0.capacity) {
                    allocationFailure();
                }
            }
            offset = data_0210dbd0.sampleMaps + sampleMapIndices[i] * 120;
            func_020ba778(offset, 0);
            instrument->sampleMap = func_020ba798(instrument->sampleMap, 120);
        }

        instrument->pitchMap = NULL;
        for (k = i - 1; k >= 1; k--) {
            if (pitchMapIndices[i] == pitchMapIndices[k]) {
                instrument->pitchMap = data_0210daf0.player->instruments[k].pitchMap;
                break;
            }
        }
        if (instrument->pitchMap == NULL) {
            instrument->ownedData |= 2;
            if (heap) {
                instrument->pitchMap = func_0205e540(120, 3, 4);
                if (instrument->pitchMap == NULL) {
                    allocationFailure();
                }
            } else {
                instrument->pitchMap = (s8 *) (data_0210daf0.arena + data_0210daf0.used);
                data_0210daf0.used += 120;
                if (data_0210daf0.used >= data_0210daf0.capacity) {
                    allocationFailure();
                }
            }
            offset = data_0210dbd0.pitchMaps + pitchMapIndices[i] * 120;
            func_020ba778(offset, 0);
            instrument->pitchMap = func_020ba798(instrument->pitchMap, 120);
        }

        for (envelopeSlot = 2; envelopeSlot >= 0; envelopeSlot--) {
            instrument->envelopes[envelopeSlot] = NULL;
            if (envelopeIndices[i][envelopeSlot] != 0xffff) {
                for (k = i - 1; k >= 1; k--) {
                    for (slot = 2; slot >= 0; slot--) {
                        if (envelopeIndices[i][envelopeSlot] == envelopeIndices[k][slot]) {
                            instrument->envelopes[envelopeSlot] = data_0210daf0.player->instruments[k].envelopes[slot];
                            slot                                = 0;
                            k                                   = 0;
                        }
                    }
                }
                if (instrument->envelopes[envelopeSlot] == NULL) {
                    instrument->ownedData |= 4 << envelopeSlot;
                    offset = data_0210dbd0.envelopes + envelopeIndices[i][envelopeSlot] * 12;
                    func_020ba778(offset, 0);
                    func_020ba798(&envelopeHeader, sizeof(envelopeHeader));
                    if (heap) {
                        instrument->envelopes[envelopeSlot] = func_0205e540(16 + (envelopeHeader.pointCount + 1) * 3, 3, 4);
                        if (instrument->envelopes[envelopeSlot] == NULL) {
                            allocationFailure();
                        }
                    } else {
                        instrument->envelopes[envelopeSlot] = (Envelope *) (data_0210daf0.arena + data_0210daf0.used);
                        data_0210daf0.used += (16 + (envelopeHeader.pointCount + 1) * 3 + 3) & ~3;
                        if (data_0210daf0.used >= data_0210daf0.capacity) {
                            allocationFailure();
                        }
                    }
                    envelope               = instrument->envelopes[envelopeSlot];
                    envelope->flags        = envelopeHeader.flags;
                    envelope->pointCount   = envelopeHeader.pointCount;
                    envelope->loopStart    = envelopeHeader.loopStart;
                    envelope->loopEnd      = envelopeHeader.loopEnd;
                    envelope->sustainStart = envelopeHeader.sustainStart;
                    envelope->sustainEnd   = envelopeHeader.sustainEnd;
                    envelope->ticks        = (u16 *) (envelope + 1);
                    envelope->values       = (s8 *) (envelope->ticks + envelope->pointCount + 1);
                    func_020ba778(data_0210dbd0.envelopeTicks + envelopeHeader.ticks * 4, 0);
                    func_020ba798(&offset, 4);
                    func_020ba778(offset, 0);
                    func_020ba798(envelope->ticks, envelope->pointCount * 2);
                    envelope->ticks[envelope->pointCount] = envelope->ticks[envelope->pointCount - 1] + 1;
                    func_020ba778(data_0210dbd0.envelopeValues + envelopeHeader.values * 4, 0);
                    func_020ba798(&offset, 4);
                    func_020ba778(offset, 0);
                    func_020ba798(envelope->values, envelope->pointCount);
                    envelope->values[envelope->pointCount] = envelope->values[envelope->pointCount - 1];
                }
            }
        }
    }
    func_020ba778(savedPosition, 0);
}
