#include "m2c.h"

/* Tracker effect dispatch. Record field roles are inferred from their effect behavior. */

typedef struct {
    u8 dirty : 2;
    u8 action : 2;
    u8 rest : 4;
} VoiceFlags;

typedef struct {
    u8 vibrato : 2;
    u8 tremolo : 2;
    u8 pan : 2;
    u8 rest : 2;
} Waveforms;

typedef struct {
    u8 low : 4;
    u8 high : 4;
} Nibbles;

typedef union {
    u8 value;
    struct {
        u8 other : 3;
        u8 release : 1;
        u8 rest : 4;
    } bits;
} VoiceState;

typedef union {
    u8 value;
    struct {
        u8 low : 4;
        u8 tickEffect : 1;
        u8 high : 3;
    } bits;
} TrackFlags;

typedef struct {
    u8 note;
    u8 instrument;
    u8 unk02;
    u8 command;
    u8 param;
    u8 volume;
    u8 channelVolume;
    u8 pan;
    u8 voice;
    u8 loopRow;
    u8 loopCount;
    u8 volumeSlide;
    s32 targetPitch;
    u8 pitchSlide;
    u8 portamento;
    u8 unk12;
    u8 offsetHigh;
    u8 depth;
    u8 rate;
    u8 retrigger;
    u8 unk17;
    u8 channelSlide;
    u8 panSlide;
    u8 extended;
    u8 globalSlide;
    u8 tremor;
    u8 tempo;
    u8 unk1e;
    Nibbles cutMemory;
    u8 retriggerMemory;
    Waveforms waveforms;
    TrackFlags flags;
    u8 unk23;
} Track;

typedef struct {
    u32 pitch;
    u16 unk04;
    u8 volume;
    u8 pan;
    u8 unk08[2];
    u8 track;
    VoiceState state;
    u8 unk0c[4];
    u8 counter;
    VoiceFlags flags;
    u8 unk12[14];
} Voice;

typedef struct {
    u8 unk00[0x14];
    s32 pitch;
    u8 unk18[0xc];
} Sample;

typedef struct {
    u8 unk00[0xc];
    u8 *sampleMap;
    u8 *pitchMap;
    void *release;
    u8 unk18[8];
} Instrument;

typedef struct {
    Sample *samples;
    Instrument *instruments;
    u8 *orders;
    u8 **patterns;
    u8 unk10[0xe];
    u16 row;
    u8 unk20[7];
    u8 initialSpeed;
    u8 order;
    u8 unk29;
    u8 globalVolume;
    u8 unk2b;
    u8 speed;
    u8 flags;
    u8 unk2e[4];
    u8 breakRow;
    u8 breakOrder;
    u8 unk34;
    u8 delay;
    u8 unk36[3];
    u8 playerId;
    u8 unk3a[2];
    Track tracks[32];
    Voice voices[16];
} Player;

typedef struct {
    u8 stop, release, fade;
} Commands;

extern Player *data_0210daf0;
extern s32 *data_0210098c[3];
extern const u32 data_020f79c4[1];
extern s32 func_020b8770(u8 *, s32, u32);
extern s32 func_020b8b1c(s32, s32);
extern void func_020b7f90(u8, u32);
extern void func_020b4520(s32, u32);
extern void func_020b861c(s32);
extern void func_020b5ba8(s32, s32, s32);

/* Voice records follow the 32 track records in the player allocation. */
static inline Voice *GetVoice(Player *player, Track *track) {
    if (track->voice != 0xff) {
        return &player->voices[track->voice];
    }
    return 0;
}

static inline void SetPan(Track *track, Voice *voice, s16 pan) {
    track->pan = pan;
    if (voice != 0) {
        voice->pan = track->pan;
        voice->flags.dirty |= 2;
    }
}

static inline u8 RememberParam(Track *t, u8 *memory) {
    if (t->param == 0) {
        t->param = *memory;
    } else {
        *memory = t->param;
    }
    return t->param;
}

void func_020b67f8(s32 index) {
    Track *t = &data_0210daf0->tracks[index];
    Voice *v = GetVoice(data_0210daf0, t);
    if (!(t->flags.value & 8)) {
        return;
    }
    if (t->command == 4 || t->command == 11 || t->command == 12) {
        if (t->param == 0) {
            t->param = t->volumeSlide;
        } else {
            t->volumeSlide = t->param;
        }
        if (t->param != 0) {
            t->flags.value |= func_020b8770(&t->volume, t->param, 64);
            if (v != 0) {
                v->volume = t->volume;
                v->flags.dirty |= 2;
            }
        }
    }
    switch (t->command) {
        case 1:
            if (t->param != 0) {
                data_0210daf0->speed        = t->param;
                data_0210daf0->initialSpeed = data_0210daf0->speed;
            }
            break;
        case 2:
            data_0210daf0->breakOrder = t->param;
            data_0210daf0->breakRow   = 0;
            data_0210daf0->row        = 0;
            break;
        case 3:
            data_0210daf0->breakRow = t->param;
            data_0210daf0->row      = 0;
            break;
        case 5:
            if (t->param == 0) {
                t->param = t->pitchSlide;
            } else {
                t->pitchSlide = t->param;
            }
            if ((t->param >> 4) == 15) {
                if (v != 0) {
                    v->pitch = func_020b8b1c(v->pitch, -4 * (t->param & 15));
                    if (v->pitch < 32) {
                        func_020b7f90(t->voice, 0);
                    }
                    v->flags.dirty |= 1;
                }
            } else if ((t->param >> 4) == 14) {
                if (v != 0) {
                    v->pitch = func_020b8b1c(v->pitch, -(t->param & 15));
                    if (v->pitch < 32) {
                        func_020b7f90(t->voice, 0);
                    }
                    v->flags.dirty |= 1;
                }
            } else {
                t->flags.value |= 16;
            }
            break;
        case 6:
            if (t->param == 0) {
                t->param = t->pitchSlide;
            } else {
                t->pitchSlide = t->param;
            }
            if ((t->param >> 4) == 15) {
                if (v != 0) {
                    v->pitch = func_020b8b1c(v->pitch, (t->param & 15) << 2);
                    if (v->pitch > 0x3fff800) {
                        func_020b7f90(t->voice, 0);
                    }
                    v->flags.dirty |= 1;
                }
            } else if ((t->param >> 4) == 14) {
                if (v != 0) {
                    v->pitch = func_020b8b1c(v->pitch, t->param & 15);
                    if (v->pitch > 0x3fff800) {
                        func_020b7f90(t->voice, 0);
                    }
                    v->flags.dirty |= 1;
                }
            } else {
                t->flags.value |= 16;
            }
            break;
        case 7:
            t->flags.value |= 16;
            if (t->param == 0) {
                t->param = t->portamento;
            } else {
                t->portamento = t->param;
            }
        /* fall through */
        case 12: {
            u8 instrument = t->instrument;
            u8 note;
            Instrument *ins;
            s32 a, b;
            if (instrument == 0) {
                return;
            }
            note = t->note;
            if (note >= 120) {
                return;
            }
            ins            = &data_0210daf0->instruments[instrument];
            a              = data_0210daf0->samples[ins->pitchMap[note]].pitch;
            b              = data_0210098c[2][ins->sampleMap[note]];
            t->targetPitch = ((a / 64) * (b / 64)) / 16;
            break;
        }
        case 8:
            t->flags.value |= 16;
            if (t->param & 15) {
                t->rate = (t->param & 15) << 2;
            }
            if (!(t->param & 0xf0)) {
                return;
            }
            t->depth = (t->param >> 4) << 2;
            break;
        case 9:
            t->flags.value |= 16;
            if (v != 0) {
                v->counter = 0;
            }
            break;
        case 10:
            t->flags.value |= 16;
            if (t->param == 0) {
                t->param = t->tremor;
            } else {
                t->tremor = t->param;
            }
            if (v != 0) {
                if (data_0210daf0->flags & 16) {
                    v->counter = 0;
                } else {
                    v->counter = 2;
                }
            }
            break;
        case 11:
            t->flags.value |= 16;
            break;
        case 13:
            t->channelVolume = t->param > 64 ? 64 : t->param;
            if (v != 0) {
                v->flags.dirty |= 2;
            }
            break;
        case 14:
            if (t->param == 0) {
                t->param = t->channelSlide;
            } else {
                t->channelSlide = t->param;
            }
            if (t->param != 0) {
                t->flags.value |= func_020b8770(&t->channelVolume, t->param, 64);
                if (v != 0) {
                    v->flags.dirty |= 2;
                }
            }
            break;
        case 16:
            if (t->param == 0) {
                t->param = t->panSlide;
            } else {
                t->panSlide = t->param;
            }
            if (t->param != 0) {
                t->flags.value |= func_020b8770(&t->pan, t->param, 64);
                if (v != 0) {
                    v->pan = t->pan;
                    v->flags.dirty |= 2;
                }
            }
            break;
        case 17:
            t->flags.value = 16;
            if (t->param == 0) {
                t->param = t->retriggerMemory;
            } else {
                t->retriggerMemory = t->param;
            }
            if (t->param != 0 && v != 0) {
                v->counter = t->param & 15;
            }
            break;
        case 18:
            t->flags.value = 16;
            if (t->param & 15) {
                t->retrigger = (t->retrigger & 0xf0) | (t->param & 15);
            }
            if (t->param & 0xf0) {
                t->retrigger = (t->retrigger & 15) | (t->param & 0xf0);
            }
            break;
        case 19:
            if (t->param == 0) {
                t->param = t->extended;
            } else {
                t->extended = t->param;
            }
            switch (t->param >> 4) {
                case 3:
                    if ((t->param & 15) < 4) {
                        t->waveforms.vibrato = (u8) (t->param & 15);
                    }
                    break;
                case 4:
                    if ((t->param & 15) < 4) {
                        t->waveforms.tremolo = (u8) (t->param & 15);
                    }
                    break;
                case 5:
                    if ((t->param & 15) < 4) {
                        t->waveforms.pan = (u8) (t->param & 15);
                    }
                    break;
                case 6:
                    data_0210daf0->delay = t->param & 15;
                    break;
                case 7:
                    switch (t->param & 15) {
                        case 0:
                        case 1:
                        case 2: {
                            Commands commands;
                            s32 i;
                            commands = *(const Commands *) data_020f79c4;
                            for (i = 15; i >= 0; i--) {
                                if (data_0210daf0->voices[i].track == index) {
                                    /* The original indexes this local table with the full parameter byte. */
                                    func_020b7f90((u8) i, ((u8 *) &commands)[t->param]);
                                }
                            }
                            break;
                        }
                        case 3:
                        case 4:
                        case 5:
                        case 6:
                            if (v != 0) {
                                v->flags.action = (u8) ((t->param & 15) - 3);
                            }
                            break;
                        case 7:
                            if (v == 0) {
                                return;
                            }
                            v->state.value &= ~8;
                            break;
                        case 8:
                            if (v == 0) {
                                return;
                            }
                            if (data_0210daf0->instruments[t->instrument].release == 0) {
                                return;
                            }
                            v->state.bits.release = 1;
                            break;
                    }
                    break;
                case 8:
                    /* Four integer pan units per nibble step, evaluated in 16.16 fixed point. */
                    SetPan(t, v, ((t->param & 15) * 0x40000) >> 16);
                    break;
                case 10:
                    t->offsetHigh = t->param & 15;
                    break;
                case 11:
                    if ((t->param & 15) == 0) {
                        t->loopRow =
                            data_0210daf0->patterns[data_0210daf0->orders[data_0210daf0->order]][0] - data_0210daf0->row;
                    } else if (t->loopCount == 0) {
                        t->loopCount = (t->param & 15) + 1;
                    } else if (--t->loopCount == 0) {
                        data_0210daf0->breakRow   = t->loopRow;
                        data_0210daf0->breakOrder = data_0210daf0->order;
                        data_0210daf0->row        = 0;
                    }
                    break;
                case 12:
                    if (v == 0) {
                        return;
                    }
                    v->counter = t->param & 15;
                    if (v->counter == 0) {
                        t->param |= t->cutMemory.low;
                        v->counter = t->cutMemory.low;
                    } else {
                        t->cutMemory.low = v->counter;
                    }
                    t->flags.bits.tickEffect = 1;
                    break;
            }
            break;
        case 20: {
            u32 param = RememberParam(t, &t->tempo);
            if (param < 32) {
                t->flags.value |= 16;
                break;
            }
            func_020b4520(data_0210daf0->playerId, param);
        } break;
        case 21:
            t->flags.value |= 16;
            if (t->param & 15) {
                t->rate = (t->param & 15) << 2;
            }
            if (t->param & 0xf0) {
                t->depth = t->param >> 4;
            }
            break;
        case 23:
            if (t->param == 0) {
                t->param = t->globalSlide;
            } else {
                t->globalSlide = t->param;
            }
            t->flags.value |= func_020b8770(&data_0210daf0->globalVolume, t->param, 128);
            func_020b861c(2);
            break;
        case 24:
            t->pan = ((u32) t->param * 0x10101) >> 18;
            if (v != 0) {
                v->pan = t->pan;
                v->flags.dirty |= 2;
            }
            break;
        case 26:
            t->flags.value |= 16;
            func_020b5ba8(4, t->param, 1);
            break;
    }
}
