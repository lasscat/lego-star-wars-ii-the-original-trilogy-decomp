#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s16 f00;
    s16 f02;
} ShortPair;

typedef struct {
    u8 f00[8];
} Byte8;

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
} Byte4;

extern const u16 data_020ee258[]; /* .rodata */
extern const u16 data_020ee260[]; /* .rodata */
extern u8 data_02101b98[];

extern void func_02053ee8(void *, s32, s32);
extern void func_020534e0(void *);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_02054c80(void *, void *, u16, u32, u32, u32, u32, u32, void *, Byte4);
extern void func_0206549c(void *);
extern void func_020654a8(void *);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern u16 func_02065be8(void *, u32, s32, s32, void *, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void *func_02066708(s32);

enum {
    ENTRY_FIRST_HALFWORD = 3,    /* entries start at halfword 3 of data_020ee258 */
    ENTRY_HALFWORDS      = 2,    /* {id for func_02054c80, string id} */
    TEXT_FONT_SET        = 3,    /* func_02065600: font pair at data_021047fc + 3 * 0x38 */
    TEXT_X               = 0x80,
    TEXT_Y               = 0xa8,
    TEXT_ALIGN_CENTRE_X  = 1,    /* func_02065be8 mode 1: x -= (width + 1) / 2 */
    SKIP_VALUE           = 7,    /* func_0206653c ignores arguments equal to 7 */
};

/* For table entry `entry_index`, pass its id to func_02054c80 and lay out its
 * string with a text context.
 *
 * data_020ee258 (.rodata) holds three header halfwords followed by
 * two-halfword entries {id, string id}; the string id is read through
 * data_020ee260, the symbol that starts at entry 0's second halfword.
 *
 * 1. func_02053ee8 updates the word at data_02101b98 + 4 (arguments 0, 0).
 * 2. entry_slot selects record (1, 1) and gets header halfword 2
 *    (func_020534f4); it goes to func_02054c80 with the entry's id, the
 *    zeroed pair/bytes arguments and 0x100. What func_02054c80 does with them
 *    is not established (no matched source).
 * 3. text_slot selects record (1, 0) and gets header halfword 1; the text
 *    context is configured from it with font set 3 and value 0 for both
 *    func_0206574c fields. func_0206653c sets only its first argument (6).
 * 4. func_02066708 decodes string #id into the shared 0x400-byte buffer
 *    data_02104918 (NULL if decoding fails); func_02065be8 centres it
 *    horizontally on x = 0x80 at y = 0xa8 by its measured width and hands it
 *    to func_02065c90 (no matched source).
 * 5. func_020654a8 clears the context's font set again (func_020655d8 resets
 *    it to 5, the value func_0206549c starts with).
 *
 * The first parameter is not used.
 */
void func_020768fc(void *self, s32 entry_index) {
    s32 text_ctx[12]; /* fonts at +4/+8 measure the string (func_02065840) */
    s32 entry_slot[2]; /* {row, column} of a data_02101bb8 record (func_020531d8) */
    s32 text_slot[2];  /* same kind of selector; func_02065658 configures text_ctx from it */
    Byte8 out;
    ShortPair pair;
    Byte4 bytes;

    func_02053ee8(data_02101b98, 0, 0);
    func_020534e0(entry_slot);
    func_020534f4(entry_slot, 1, 1, *(const HalfWord *) &data_020ee258[2]);
    pair.f00  = 0;
    pair.f02  = 0;
    bytes.f00 = 0;
    bytes.f01 = 0;
    bytes.f02 = 0;
    bytes.f03 = 0;
    func_02054c80(&out, entry_slot, data_020ee258[ENTRY_FIRST_HALFWORD + entry_index * ENTRY_HALFWORDS], 0, 0, 0, 0, 0x100,
                  &pair, bytes);
    func_020534e0(text_slot);
    func_020534f4(text_slot, 1, 0, *(const HalfWord *) &data_020ee258[1]);
    func_0205365c(text_slot, 0);
    func_0206549c(text_ctx);
    func_02065600(text_ctx, TEXT_FONT_SET);
    func_02065658(text_ctx, text_slot);
    func_0206574c(text_ctx, 0, 0);
    func_0206653c(1, 6, SKIP_VALUE, SKIP_VALUE, SKIP_VALUE, SKIP_VALUE, 0);
    func_02065be8(text_ctx, 1, TEXT_X, TEXT_Y, func_02066708(data_020ee260[entry_index * ENTRY_HALFWORDS]),
                  TEXT_ALIGN_CENTRE_X);
    func_020654a8(text_ctx);
}
