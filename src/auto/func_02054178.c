/* Reconstructed from USA ARM9 at 0x02054178 (28 bytes).
 * Names and types are inferred from the binary.
 */
typedef struct {
    unsigned short x;
    unsigned short y;
} PackedCoordinates;

typedef struct {
    int x;
    int y;
} FixedCoordinates;

void func_02054178(FixedCoordinates *destination, const PackedCoordinates *source) {
    unsigned int x = source->x;
    unsigned int y = source->y;

    destination->x = x << 12;
    destination->y = y << 12;
}
