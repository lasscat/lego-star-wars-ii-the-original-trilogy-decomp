/* Reconstructed from USA ARM9 at 0x0207567c (28 bytes).
 * Names and types are inferred from the binary.
 */
int func_0207567c(const unsigned int *words, unsigned int bit_index) {
    return (words[bit_index >> 5] & (1U << (bit_index & 31))) != 0;
}
