/* Reconstructed from USA ARM9 at 0x0202d620 (308 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern void func_0202d560(void *, s32);
extern void func_0202d754(void *, char **);
extern void func_0202d790(void *, char *);

/* Two word list anchor: the first link and the link in front of it. */
typedef struct {
    char *f0;
    char *f4;
} Link;

/* The list of a structure is anchored at the two words that hold its links.
 * RELINK replaces the link that points back at the anchor with the anchor's
 * second word. */
#define RELINK(h)                                         \
    do {                                                  \
        char *link = M2C_FIELD((h), char **, 0);          \
        if (link != NULL) {                               \
            char *nxt = *(char **) link;                  \
            if (nxt != (char *) (h)) {                    \
                do {                                      \
                    link = (char *) ((char *) nxt + 4);   \
                    nxt  = *(char **) ((char *) nxt + 4); \
                } while (nxt != (char *) (h));            \
            }                                             \
            *(char **) link = M2C_FIELD((h), char **, 4); \
        }                                                 \
    } while (0)

void func_0202d620(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    Link sp8;
    Link sp0;
    char *v;

    M2C_FIELD(arg0, s16 *, 4) += arg2;

    v = M2C_FIELD(arg0, char **, 0xc);
    if (v != 0) {
        v -= 4;
    }
    if (v == 0) {
        func_0202d790(&sp8, arg3);
        func_0202d754(&sp0, &sp8.f0);

        {
            char *w = sp0.f0;
            if (w != 0) {
                w -= 4;
            }
            if (w != 0) {
                w += 4;
            }
            RELINK((char *) arg0 + 0xc);
            if (w != 0) {
                M2C_FIELD(arg0, char **, 0xc)  = w;
                M2C_FIELD(arg0, char **, 0x10) = *(char **) w;
                *(char **) w                   = (char *) arg0 + 0xc;
            } else {
                M2C_FIELD(arg0, char **, 0xc)  = NULL;
                M2C_FIELD(arg0, char **, 0x10) = NULL;
            }
        }
        RELINK(&sp0);
        RELINK(&sp8);
    }
    func_0202d560(arg0, arg1);
}
