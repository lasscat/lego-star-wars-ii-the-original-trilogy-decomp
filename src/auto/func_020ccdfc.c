/* func_0200c4f8 from projets/rayman-rr/src/auto/func_0200c4f8.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
extern void OS_UnlockCartridge();
// clang-format off
asm void OS_UnLockCartridge(void) {
    ldr r1, =OS_UnlockCartridge
    bx r1
}
// clang-format on
