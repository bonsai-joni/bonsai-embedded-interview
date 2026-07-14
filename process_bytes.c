#include <stdint.h>
#include <stddef.h>

/*
 * Frame format
 *
 *   Byte 0:     0xAA (start marker)
 *   Byte 1:     LEN  (number of payload bytes, 0-255)
 *   Byte 2..N:  Payload (LEN bytes)
 *
 * Example:
 *   Input:  {0x00, 0xFF, 0xAA, 0x03, 0x10, 0x20, 0x30, 0x00}
 *   Result: len=3, payload={0x10, 0x20, 0x30}
 */

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
