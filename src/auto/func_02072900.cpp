#include "m2c.h"

typedef struct {
    u16 id;
    u16 pad02[3];
    u32 flags;
    u16 pad0c;
    u16 f0e;
    u8 pad10[2];
    u8 f12;
} State;

typedef struct {
    u8 pad00[4];
    u16 name[10];
    u16 length;
    u8 pad1a[0x36];
} OwnerInfo;

// Declaration-only partial interface; unused methods preserve the ROM slots.
class Manager72900 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(s32, u16, s32, s32);
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual s32 unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48();
    virtual void unknown4c();
    virtual void unknown50();
    virtual void unknown54();
    virtual void unknown58();
    virtual void unknown5c();
    virtual void unknown60();
    virtual void unknown64(void *, u32);
};

extern "C" State data_02104d20;
extern "C" Manager72900 *data_0210b348;

extern "C" u32 func_02062b10(s32);
extern "C" s32 func_020ad310(void);
extern "C" void OS_GetOwnerInfo(void *);
extern "C" void func_02066b4c(u16 *, u32, u8 *);
extern "C" void func_0206549c(s32 *);
extern "C" void func_02066168(void *, void *);
extern "C" u8 *func_02066470(void *, s32);
extern "C" s32 func_020e0db0(u8 *);
extern "C" void func_02066b84(u8 *, u32, u16 *);
extern "C" s32 func_020654a8(void *);
extern "C" s32 memset(void *, s32, s32);

enum {
    STATE_INITIALIZED = 1,
    INITIAL_ID_LIMIT  = 0xffff,
    PROCESS_TEXT_MODE = 7,
    SKIP_TEXT_MODE    = 9,
    WIDE_TEXT_BYTES   = 0x30,
    OWNER_BYTE_GROUPS = 6,
    SPECIAL_TEXT_ID   = 0x28d,
    MANAGER_REQUEST   = 4,
    ID_SHIFT          = 2
};

/* Prepare the requested text with the console owner's name substituted for
 * its first text placeholder, then pass its u16 character codes to the manager.
 * Wait for shared mode 7 or 9; mode 9 returns without submitting text. Each
 * submission increments the shared id and packs it above a special-text bit.
 * The manager's request code and returned value have no established meaning.
 */
extern "C" void func_02072900(s32 textId) {
    OwnerInfo ownerInfo;
    u16 wideText[24];
    u8 ownerBytes[24];
    s32 textContext[12];
    u16 characterCount;
    s32 characterIndex;
    u32 specialText;
    s32 managerValue;

    data_02104d20.f12 = 0;
    data_02104d20.f0e = 0;
    if (!(data_02104d20.flags & STATE_INITIALIZED)) {
        data_02104d20.id = func_02062b10(INITIAL_ID_LIMIT);
        data_02104d20.flags |= STATE_INITIALIZED;
    }
    while (func_020ad310() != PROCESS_TEXT_MODE && func_020ad310() != SKIP_TEXT_MODE) {
    }
    if (func_020ad310() != PROCESS_TEXT_MODE) {
        return;
    }
    memset(wideText, 0, WIDE_TEXT_BYTES);
    {
        u32 remainingGroups = OWNER_BYTE_GROUPS;
        u8 *nextByte        = ownerBytes;
        do {
            nextByte[0] = 0;
            nextByte[1] = 0;
            nextByte[2] = 0;
            nextByte[3] = 0;
            nextByte += 4;
        } while (--remainingGroups != 0);
    }
    OS_GetOwnerInfo(&ownerInfo);
    characterCount = ownerInfo.length;
    for (characterIndex = 0; characterIndex < characterCount; characterIndex++) {
        wideText[characterIndex] = ownerInfo.name[characterIndex];
    }
    func_02066b4c(wideText, characterCount, ownerBytes);
    func_0206549c(textContext);
    // The helper writes placeholder entry zero, used by the @1 expansion.
    func_02066168(textContext, ownerBytes);
    characterCount = func_020e0db0(func_02066470(textContext, textId));
    func_02066b84(func_02066470(textContext, textId), characterCount, wideText);
    // Include the terminator in the character-code count sent to slot 0x64.
    data_0210b348->unknown64(wideText, characterCount + 1);
    managerValue = data_0210b348->unknown38();
    data_02104d20.id++;
    specialText = (textId == SPECIAL_TEXT_ID) ? 1 : 0;
    data_0210b348->unknown0c(MANAGER_REQUEST, specialText | (data_02104d20.id << ID_SHIFT), managerValue, 1);
    func_020654a8(textContext);
}
