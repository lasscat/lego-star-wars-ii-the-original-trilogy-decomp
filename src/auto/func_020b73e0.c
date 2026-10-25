#include "m2c.h"

/* Tracker tick-effect processing. Record field roles are inferred from their effect behavior. */

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
    u8 columnCommand;
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
    u8 key;
    u8 sample;
    u8 track;
    VoiceState state;
    u8 unk0c[3];
    u8 phase;
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
    u8 unk20[4];
    u8 trackCount;
    u8 unk25[2];
    u8 initialSpeed;
    u8 order;
    u8 unk29;
    u8 globalVolume;
    u8 tempo;
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

extern Player *data_0210daf0;
extern s32 *data_0210098c[3];
extern s32 func_020b8b1c(s32, s32);
extern void func_020b7f90(u8, u32);
extern void func_020b6308(u32);
extern void func_020b4520(s32, u32);
extern void func_020b87f8(volatile u8 *, u32, u32);
extern void func_020b861c(s32);
extern void func_020b8840(u8);
extern void func_020b601c(u8, u8);
extern void func_020b650c(u8);
extern void func_020b5ba8(s32, s32, s32);

static inline Voice *GetVoice(Player *player, Track *track) {
    if (track->voice != 0xff) {
        return &player->voices[track->voice];
    }
    return 0;
}

void func_020b73e0(void) {
    s32 index;
    for (index = data_0210daf0->trackCount - 1; index >= 0; index--) {
        Track *t = &data_0210daf0->tracks[index];
        Voice *v = GetVoice(data_0210daf0, t);
        if (t->flags.value & 0x10) {
            if (v != 0) {
                switch (t->command) {
                    case 5:
                        v->pitch = func_020b8b1c(v->pitch, -(t->param << 2));
                        if (v->pitch < 0x20U) {
                            func_020b7f90(t->voice, 0);
                        }
                        v->flags.dirty |= 1;
                        break;
                    case 6:
                        v->pitch = func_020b8b1c(v->pitch, t->param << 2);
                        if (v->pitch > 0x3fff800U) {
                            func_020b7f90(t->voice, 0);
                        }
                        v->flags.dirty |= 1;
                        break;
                    case 9:
                        if (--v->counter == 0) {
                            v->counter = (t->param & 15) | 0x80;
                            v->flags.dirty |= 2;
                        } else if (v->counter == 0x80) {
                            v->counter = t->param >> 4;
                            v->flags.dirty |= 2;
                        }
                        break;
                    case 10:
                        switch (v->counter) {
                            case 0:
                                v->counter = 1;
                                v->pitch   = (data_0210daf0->samples[v->sample].pitch / 64) *
                                           (data_0210098c[2][v->key + (t->param & 15)] / 64) / 16;
                                break;
                            case 1:
                                v->counter = 2;
                                v->pitch   = (data_0210daf0->samples[v->sample].pitch / 64) *
                                           (data_0210098c[2][v->key + (t->param >> 4)] / 64) / 16;
                                break;
                            case 2:
                                v->counter = 0;
                                v->pitch =
                                    (data_0210daf0->samples[v->sample].pitch / 64) * (data_0210098c[2][v->key] / 64) / 16;
                                break;
                        }
                        v->flags.dirty |= 1;
                        break;
                    case 17:
                        if (--v->counter == 0) {
                            u32 mode;
                            v->counter = t->param & 15;
                            func_020b6308((u8) index);
                            mode = t->param >> 4;
                            if (mode < 8) {
                                if (mode != 0) {
                                    if (mode <= 5) {
                                        t->volume -= (u8) (1 << (mode - 1));
                                    } else if (mode == 6) {
                                        t->volume = (t->volume * 0xaaaa) >> 16;
                                    } else {
                                        t->volume >>= 1;
                                    }
                                    if (t->volume > 64) {
                                        t->volume = 0;
                                    }
                                }
                            } else if (mode != 8) {
                                if (mode <= 13) {
                                    t->volume += (u8) (1 << (mode - 13));
                                } else if (mode == 14) {
                                    t->volume += (u8) (t->volume >> 1);
                                } else {
                                    t->volume <<= 1;
                                }
                                if (t->volume > 64) {
                                    t->volume = 64;
                                }
                            }
                            v->volume = t->volume;
                            v->flags.dirty |= 3;
                        }
                        break;
                    case 18:
                        v->counter++;
                        v->flags.dirty |= 2;
                        break;
                    case 19:
                        if ((t->param >> 4) == 12 && data_0210daf0->initialSpeed != data_0210daf0->speed) {
                            if (--v->counter == 0) {
                                t->flags.value &= ~0x10;
                                func_020b7f90(t->voice, 0);
                            }
                        }
                        break;
                    case 20:
                        if (t->param < 0x10) {
                            func_020b4520(data_0210daf0->playerId, (u16) (data_0210daf0->tempo + t->param));
                        } else {
                            func_020b4520(data_0210daf0->playerId, (u16) (data_0210daf0->tempo - (t->param - 0x10)));
                        }
                        break;
                    case 23:
                        func_020b87f8(&data_0210daf0->globalVolume, t->param, 0x80);
                        func_020b861c(2);
                        break;
                    case 25:
                        v->counter++;
                        v->flags.dirty |= 2;
                        break;
                }
                if (t->command == 7 || t->command == 12) {
                    func_020b8840((u8) index);
                }
                if (t->command == 8 || t->command == 21 || t->command == 11) {
                    v->phase += t->depth;
                    v->flags.dirty |= 1;
                }
            }
            switch (t->command) {
                case 4:
                case 11:
                case 12:
                    func_020b87f8(&t->volume, t->volumeSlide, 64);
                    if (v != 0) {
                        v->volume = t->volume;
                        v->flags.dirty |= 2;
                    }
                    break;
                case 14:
                    func_020b87f8(&t->channelVolume, t->param, 64);
                    if (v != 0) {
                        v->flags.dirty |= 2;
                    }
                    break;
                case 16:
                    func_020b87f8(&t->pan, t->param, 64);
                    if (v != 0) {
                        v->pan = t->pan;
                        v->flags.dirty |= 2;
                    }
                    break;
                case 19:
                    if ((t->param >> 4) == 13 && data_0210daf0->initialSpeed != data_0210daf0->speed) {
                        if ((--t->param & 15) == 0) {
                            u8 release;
                            t->flags.value &= ~0x10;
                            release = (t->flags.value & 0x20) && t->columnCommand >= 0xc1 && t->columnCommand <= 0xca;
                            func_020b601c((u8) index, (u8) release);
                            func_020b650c((u8) index);
                        }
                    }
                    break;
                case 26:
                    func_020b5ba8(4, t->param, 0);
                    break;
            }
        }
        if (t->flags.value & 0x20) {
            if (t->columnCommand <= 0x5e) {
                t->volume += t->columnCommand - 0x55;
                if (t->volume > 64) {
                    t->volume = 64;
                }
                if (v != 0) {
                    v->volume = t->volume;
                    v->flags.dirty |= 2;
                }
            } else if (t->columnCommand <= 0x68) {
                t->volume -= t->columnCommand - 0x5f;
                if (t->volume > 64) {
                    t->volume = 0;
                }
                if (v != 0) {
                    v->volume = t->volume;
                    v->flags.dirty |= 2;
                }
            } else if (v != 0) {
                if (t->columnCommand <= 0x72) {
                    v->flags.dirty |= 1;
                    v->pitch = func_020b8b1c(v->pitch, -(t->pitchSlide << 2));
                    if (v->pitch < 0x20U) {
                        func_020b7f90(t->voice, 0);
                    }
                } else if (t->columnCommand <= 0x7c) {
                    v->flags.dirty |= 1;
                    v->pitch = func_020b8b1c(v->pitch, t->pitchSlide << 2);
                    if (v->pitch > 0x3fff800U) {
                        func_020b7f90(t->voice, 0);
                    }
                } else if (t->columnCommand <= 0xca) {
                    func_020b8840((u8) index);
                } else if (t->columnCommand <= 0xd4) {
                    v->flags.dirty |= 1;
                    v->phase += t->depth;
                }
            }
        }
    }
}
