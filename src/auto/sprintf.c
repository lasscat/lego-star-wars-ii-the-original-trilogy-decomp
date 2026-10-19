/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* sprintf from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/printf.c (license: none), reused by
 * tools/donor_match.py */
typedef char *va_list;
int vsnprintf(char *s, unsigned int n, const char *format, va_list arg);
int sprintf(char *s, const char *format, ...) {
    return vsnprintf(
        s, 0xffffffffUL, format,
        ((va_list) ((char *) ((unsigned int) (&format) & ~3U) + ((((unsigned int) (sizeof(format))) + 3U) & ~3U))));
}
