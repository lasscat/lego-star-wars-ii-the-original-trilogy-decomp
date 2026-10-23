/* compiler: 2.0/sp1p5 -O4,p -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft
 * -inline noauto -Cpp_exceptions off -RTTI off -interworking -w off -sym on -gccinc -nolink
 * -msgstyle gcc -lang=c */
/* ldexp: natural C reconstruction of the MSL ldexp (Sun s_ldexp), see
 * https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/math/s_ldexp.c (license: none) */

extern int __fpclassifyd(double x);
extern int _deq(double x, double y);
extern double _dmul(double x, double y);
extern double _dadd(double x, double y);
extern double copysign(double x, double y);

double ldexp(double x, int n) {
    int k, hx, lx;

    /* class <= FP_INFINITE covers NaN and infinity; zero is handled separately */
    if (__fpclassifyd(x) <= 2 || x == 0.0) {
        return x;
    }
    hx = ((int *) (&x))[1];
    lx = ((int *) (&x))[0];
    k  = (hx & 0x7FF00000) >> 20;
    if (k == 0) {
        if ((lx | (hx & 0x7FFFFFFF)) == 0) {
            return x;
        }
        x *= 0x1.0p54;
        hx = ((int *) (&x))[1];
        k  = ((hx & 0x7FF00000) >> 20) - 54;
        if (n < -50000) {
            return 1e-300 * x;
        }
    }
    if (k == 0x7FF) {
        return x + x;
    }
    k = k + n;
    if (k > 0x7FE) {
        return 1e300 * copysign(1e300, x);
    }
    if (k > 0) {
        ((int *) (&x))[1] = (hx & 0x800FFFFF) | (k << 20);
        return x;
    }
    if (k <= -54) {
        if (n > 50000) {
            return 1e300 * copysign(1e300, x);
        } else {
            return 1e-300 * copysign(1e-300, x);
        }
    }
    k += 54;
    ((int *) (&x))[1] = (hx & 0x800FFFFF) | (k << 20);
    return 0x1.0p-54 * x;
}
