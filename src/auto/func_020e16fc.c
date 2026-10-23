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

extern void __str2dec(decimal *d, const char *s, short exp);
extern void __timesdec(decimal *result, const decimal *x, const decimal *y);

extern const char data_021018d0[];
extern const char data_02101900[];
extern const char data_02101928[];
extern const char data_02101940[];
extern const char data_02101950[];
extern const char data_02101958[];
extern const char data_02101960[];
extern const char data_02101968[];
extern const char data_02101970[];
extern const char data_02101974[];
extern const char data_02101978[];
extern const char data_0210197c[];
extern const char data_02101980[];
extern const char data_02101984[];
extern const char data_02101988[];
extern const char data_0210198c[];
extern const char data_02101990[];
extern const char data_02101994[];
extern const char data_02101998[];
extern const char data_0210199c[];
extern const char data_021019a0[];

void func_020e16fc(decimal *result, long exp) {
    switch (exp) {
        case -64:
            __str2dec(result, data_021018d0, -20);
            return;
        case -53:
            __str2dec(result, data_02101900, -16);
            return;
        case -32:
            __str2dec(result, data_02101928, -10);
            return;
        case -16:
            __str2dec(result, data_02101940, -5);
            return;
        case -8:
            __str2dec(result, data_02101950, -3);
            return;
        case -7:
            __str2dec(result, data_02101958, -3);
            return;
        case -6:
            __str2dec(result, data_02101960, -2);
            return;
        case -5:
            __str2dec(result, data_02101968, -2);
            return;
        case -4:
            __str2dec(result, data_02101970, -2);
            return;
        case -3:
            __str2dec(result, data_02101974, -1);
            return;
        case -2:
            __str2dec(result, data_02101978, -1);
            return;
        case -1:
            __str2dec(result, data_0210197c, -1);
            return;
        case 0:
            __str2dec(result, data_02101980, 0);
            return;
        case 1:
            __str2dec(result, data_02101984, 0);
            return;
        case 2:
            __str2dec(result, data_02101988, 0);
            return;
        case 3:
            __str2dec(result, data_0210198c, 0);
            return;
        case 4:
            __str2dec(result, data_02101990, 1);
            return;
        case 5:
            __str2dec(result, data_02101994, 1);
            return;
        case 6:
            __str2dec(result, data_02101998, 1);
            return;
        case 7:
            __str2dec(result, data_0210199c, 2);
            return;
        case 8:
            __str2dec(result, data_021019a0, 2);
            return;
    }

    {
        decimal x2, temp;

        func_020e16fc(&x2, ((long) ((0x80000000UL & exp) >> 31) + exp) >> 1);
        __timesdec(result, &x2, &x2);

        if (exp & 1) {
            temp = *result;
            if (exp > 0) {
                __str2dec(&x2, data_02101984, 0);
            } else {
                __str2dec(&x2, data_0210197c, -1);
            }
            __timesdec(result, &temp, &x2);
        }
    }
}
