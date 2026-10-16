/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* MTX_Transpose44_ from https://github.com/ntrtwl/NitroSDK libraries/fx/src/fx_mtx44.c (license: none), reused by
 * tools/donor_match.py */
typedef signed long s32;
typedef s32 fx32;
typedef union {
    struct {
        fx32 _00, _01, _02, _03;
        fx32 _10, _11, _12, _13;
        fx32 _20, _21, _22, _23;
        fx32 _30, _31, _32, _33;
    };
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;
extern void func_020c8bd0(register const MtxFx44 *pSrc, register MtxFx44 *pDst);
// clang-format off
asm void func_020c8bd0 (register const MtxFx44 *pSrc, register MtxFx44 *pDst)
{
	stmfd sp !, {r4 - r11}
	ldr r12, [r0, #48]
	ldmia r0 !, {r2 - r11}
	stmia r1 !, {r2, r6, r10, r12}
	ldr r12, [r0, #12]
	stmia r1 !, {r3, r7, r11, r12}
	ldmia r0, {r10 - r11}
	ldr r12, [r0, #16]
	stmia r1 !, {r4, r8, r10, r12}
	ldr r12, [r0, #20]
	stmia r1 !, {r5, r9, r11, r12}
	ldmfd sp !, {r4 - r11}
	bx lr
}
// clang-format on
