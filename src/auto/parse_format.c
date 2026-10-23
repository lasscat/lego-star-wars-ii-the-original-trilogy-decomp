/* Reconstructed from USA ARM9 at 0x020dea20 (1424 bytes).
 * This is the printf format parser of the CodeWarrior C library: it scans one
 * conversion specification, records the flags / width / precision / length
 * modifier / conversion character in a 16 byte descriptor and copies that
 * descriptor to *out.  It returns the first character after the conversion.
 */
#include "m2c.h"

typedef struct {
    u8 fill;    /* 0: left justify, 1: default, 2: zero pad      */
    u8 sign;    /* 0: none, 1: '+', 2: ' '                       */
    u8 precflg; /* a precision was given                        */
    u8 alt;     /* '#' was given                                */
    u8 len;     /* length modifier code                         */
    u8 conv;    /* conversion character, 0xFF when invalid       */
    u8 pad[2];
    s32 width;
    s32 prec;
} FMT;

typedef char *va_list;

extern unsigned short __ctype_mapC[];

/* The library's digit test: characters outside 0..0x7f are never digits. */
#define ISDIGIT(c) ((c) < 0 || (c) >= 0x80 ? 0 : (__ctype_mapC[(c)] & 8))

/* The va_arg macro of the library: it advances the caller's argument list. */
#define VA_ARG(ap, type) (*(type *) (((ap) += sizeof(type)) - (sizeof(type))))

char *parse_format(char *p, va_list *args, FMT *out) {
    FMT f;
    char *q;
    char c;
    int cont;
    int haslen;

    c         = p[1];
    f.fill    = 1;
    f.sign    = 0;
    f.precflg = 0;
    f.alt     = 0;
    f.len     = 0;
    f.width   = 0;
    f.prec    = 0;
    q         = p + 1;

    if (c == '%') {
        f.conv = c;
        *out   = f;
        return q + 1;
    }

    for (;;) {
        cont = 1;
        switch (c) {
            case '-':
                f.fill = 0;
                break;
            case '+':
                f.sign = 1;
                break;
            case ' ':
                if (f.sign != 1) {
                    f.sign = 2;
                }
                break;
            case '#':
                f.alt = 1;
                break;
            case '0':
                if (f.fill != 0) {
                    f.fill = 2;
                }
                break;
            default:
                cont = 0;
                break;
        }
        if (!cont) {
            break;
        }
        c = *++q;
    }

    if (c == '*') {
        f.width = VA_ARG(*args, int);
        if (f.width < 0) {
            f.fill  = 0;
            f.width = -f.width;
        }
        c = *++q;
    } else {
        while (ISDIGIT(c) != 0) {
            f.width = f.width * 10 + (c - '0');
            c       = *++q;
        }
    }

    if (f.width > 509) {
        f.conv = 0xFF;
        *out   = f;
        return q + 1;
    }

    if (c == '.') {
        c         = *++q;
        f.precflg = 1;
        if (c == '*') {
            f.prec = VA_ARG(*args, int);
            c      = *++q;
            if (f.prec < 0) {
                f.precflg = 0;
            }
        } else {
            while (ISDIGIT(c) != 0) {
                f.prec = f.prec * 10 + (c - '0');
                c      = *++q;
            }
        }
    }

    haslen = 1;
    switch (c) {
        case 'h':
            f.len = 2;
            if (q[1] == 'h') {
                f.len = 1;
                c     = *++q;
            }
            break;
        case 'l':
            f.len = 3;
            if (q[1] == 'l') {
                f.len = 4;
                c     = *++q;
            }
            break;
        case 'L':
            f.len = 9;
            break;
        case 'j':
            f.len = 6;
            break;
        case 't':
            f.len = 8;
            break;
        case 'z':
            f.len = 7;
            break;
        default:
            haslen = 0;
            break;
    }
    if (haslen) {
        c = *++q;
    }

    f.conv = c;
    switch (c) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (f.len == 9) {
                f.conv = 0xFF;
            } else if (f.precflg == 0) {
                f.prec = 1;
            } else if (f.fill == 2) {
                f.fill = 1;
            }
            break;
        case 'f':
        case 'F':
            if (f.len == 2 || f.len == 6 || f.len == 7 || f.len == 8 || f.len == 4) {
                f.conv = 0xFF;
            } else if (f.precflg == 0) {
                f.prec = 6;
            }
            break;
        case 'a':
        case 'A':
            if (f.precflg == 0) {
                f.prec = 13;
            }
            if (f.len == 2 || f.len == 6 || f.len == 7 || f.len == 8 || f.len == 4 || f.len == 1) {
                f.conv = 0xFF;
            }
            break;
        case 'g':
        case 'G':
            if (f.prec == 0) {
                f.prec = 1;
            }
        /* fall through */
        case 'e':
        case 'E':
            if (f.len == 2 || f.len == 6 || f.len == 7 || f.len == 8 || f.len == 4 || f.len == 1) {
                f.conv = 0xFF;
            } else if (f.precflg == 0) {
                f.prec = 6;
            }
            break;
        case 'p':
            f.conv = 'x';
            f.alt  = 1;
            f.len  = 3;
            f.prec = 8;
            break;
        case 'c':
            if (f.len == 3) {
                f.len = 5;
            } else if (f.precflg || f.len) {
                f.conv = 0xFF;
            }
            break;
        case 's':
            if (f.len == 3) {
                f.len = 5;
            } else if (f.len != 0) {
                f.conv = 0xFF;
            }
            break;
        case 'n':
            if (f.len == 9) {
                f.conv = 0xFF;
            }
            break;
        default:
            f.conv = 0xFF;
            break;
    }

    *out = f;
    return q + 1;
}
