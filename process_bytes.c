#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    uint8_t payload[256];
    uint8_t len;
} frame_t;

/**
 * Process a buffer of raw bytes and extract a frame.
 *
 * @param[in]   input           Raw input buffer
 * @param[in]   input_len       Total length of input buffer
 * @param[out]  output_frame    Output frame
 * @returns     Return code,    0 on success
 */
uint8_t process_bytes(uint8_t *input, size_t input_len, frame_t *output_frame) {
    // TODO
}
