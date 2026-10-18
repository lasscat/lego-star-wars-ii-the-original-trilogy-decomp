/* Reconstructed from USA ARM9 at 0x02064f7c (20 bytes).
 * Names and types are inferred from the binary.
 */
typedef struct {
    unsigned char unknown_00[0x0d];
    unsigned char counter;
} CounterObject;

unsigned char func_02064f7c(CounterObject *object) {
    return --object->counter;
}
