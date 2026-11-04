typedef struct decimal {
    char sgn;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal;

enum {
    DECIMAL_BASE = 10
};

/*
 * Converts an unsigned 64-bit integer to a positive decimal: digits are
 * peeled off least significant first (_ull_mod / _ll_udiv by 10), then the
 * digit string is reversed in place so text[0] is the most significant
 * digit, and exp is set to (digit count - 1).
 */
void __ull2dec(decimal *result, unsigned long long integer) {
    result->sgn = 0;

    result->sig.length = 0;

    for (; integer != 0; integer /= DECIMAL_BASE) {
        result->sig.text[result->sig.length++] = (unsigned char) (integer % DECIMAL_BASE);
    }

    {
        unsigned char *p = (unsigned char *) result->sig.text;
        unsigned char *q = (unsigned char *) result->sig.text + result->sig.length - 1;
        unsigned char t;

        for (; p < q; ++p, --q) {
            t  = *p;
            *p = *q;
            *q = t;
        }
    }

    result->exp = result->sig.length - 1;
}
