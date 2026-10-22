/* func_0208adb8 (USA ARM9, 0x0208adb8, 292 bytes).
 * Maps the characters of a string to font table entries (0x2000 is added to both
 * tables) and writes the two u16 results per character into the output buffer. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef signed char s8;

extern const u16 data_020f0280[];
extern const u16 data_020f029e[];

s32 func_020e0db0(s8 *);

void func_0208adb8(s32 arg0, u16 *out, s8 *str) {
    u32 len;
    u32 i;
    s8 c;
    s32 val;
    u16 *p;
    u16 a;
    u16 b;

    len = (u32) func_020e0db0(str);
    p   = out;
    i   = 0;
    for (; i < len; i++) {
        c   = str[i];
        val = 0xa;
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                val = (u16) (c - '0');
                break;
            case '/':
                val = 0xb;
                break;
            case '.':
                val = 0xc;
                break;
            case ' ':
                val = 0xe;
                break;
            case ':':
                val = 0xd;
                break;
            default:
                break;
        }
        a       = data_020f0280[val];
        b       = data_020f029e[val];
        p[0]    = a + 0x2000;
        p[0x20] = b + 0x2000;
        p++;
    }
}
