#include "DigiKeyboard.h"
#ifndef DIGIKEYBOARDHU_H
#define DIGIKEYBOARDHU_H

#define HU_MOD_CONTROL_LEFT    (1<<8)
#define HU_MOD_SHIFT_LEFT      (1<<9)
#define HU_MOD_ALT_LEFT        (1<<10)
#define HU_MOD_GUI_LEFT        (1<<11)
#define HU_MOD_CONTROL_RIGHT   (1<<12)
#define HU_MOD_SHIFT_RIGHT     (1<<13)
#define HU_MOD_ALT_RIGHT       (1<<14)
#define HU_MOD_GUI_RIGHT       (1<<15)

const uint16_t _ascii_hu_map[128] PROGMEM =
{
    0x00,             // NUL
    0x00,             // SOH
    0x00,             // STX
    0x00,             // ETX
    0x00,             // EOT
    0x00,             // ENQ
    0x00,             // ACK
    0x00,             // BEL
    0x2a,     // BS Backspace
    0x2b,     // TAB  Tab
    0x28,     // LF Enter
    0x00,             // VT
    0x00,             // FF
    0x00,             // CR
    0x00,             // SO
    0x00,             // SI
    0x00,             // DEL
    0x00,             // DC1
    0x00,             // DC2
    0x00,             // DC3
    0x00,             // DC4
    0x00,             // NAK
    0x00,             // SYN
    0x00,             // ETB
    0x00,             // CAN
    0x00,             // EM
    0x00,             // SUB
    0x00,             // ESC
    0x00,             // FS
    0x00,             // GS
    0x00,             // RS
    0x00,             // US

    0x2c,      //  ' '
    0x1e|HU_MOD_SHIFT_LEFT,    // !
    0x34|HU_MOD_SHIFT_LEFT,    // "
    0x20|HU_MOD_ALT_RIGHT,     // #
    0x21|HU_MOD_SHIFT_LEFT,    // $
    0x22|HU_MOD_SHIFT_LEFT,    // %
    0x24|HU_MOD_SHIFT_LEFT,    // &
    0x34,                      // '
    0x26|HU_MOD_SHIFT_LEFT,    // (
    0x27|HU_MOD_SHIFT_LEFT,    // )
    0x25|HU_MOD_SHIFT_LEFT,    // *
    0x30,                      // +
    0x36,                      // ,
    0x2d,                      // -
    0x37,                      // .
    0x38,                      // /
    0x27,                      // 0
    0x1e,                      // 1
    0x1f,                      // 2
    0x20,                      // 3
    0x21,                      // 4
    0x22,                      // 5
    0x23,                      // 6
    0x24,                      // 7
    0x25,                      // 8
    0x26,                      // 9
    0x33|HU_MOD_SHIFT_LEFT,    // :
    0x33,                      // ;
    0x36|HU_MOD_SHIFT_LEFT,    // <
    0x2e,                      // =
    0x37|HU_MOD_SHIFT_LEFT,    // >
    0x38|HU_MOD_SHIFT_LEFT,    // ?
    0x14|HU_MOD_ALT_RIGHT,     // @
    0x04|HU_MOD_SHIFT_LEFT,    // A
    0x05|HU_MOD_SHIFT_LEFT,    // B
    0x06|HU_MOD_SHIFT_LEFT,    // C
    0x07|HU_MOD_SHIFT_LEFT,    // D
    0x08|HU_MOD_SHIFT_LEFT,    // E
    0x09|HU_MOD_SHIFT_LEFT,    // F
    0x0a|HU_MOD_SHIFT_LEFT,    // G
    0x0b|HU_MOD_SHIFT_LEFT,    // H
    0x0c|HU_MOD_SHIFT_LEFT,    // I
    0x0d|HU_MOD_SHIFT_LEFT,    // J
    0x0e|HU_MOD_SHIFT_LEFT,    // K
    0x0f|HU_MOD_SHIFT_LEFT,    // L
    0x10|HU_MOD_SHIFT_LEFT,    // M
    0x11|HU_MOD_SHIFT_LEFT,    // N
    0x12|HU_MOD_SHIFT_LEFT,    // O
    0x13|HU_MOD_SHIFT_LEFT,    // P
    0x14|HU_MOD_SHIFT_LEFT,    // Q
    0x15|HU_MOD_SHIFT_LEFT,    // R
    0x16|HU_MOD_SHIFT_LEFT,    // S
    0x17|HU_MOD_SHIFT_LEFT,    // T
    0x18|HU_MOD_SHIFT_LEFT,    // U
    0x19|HU_MOD_SHIFT_LEFT,    // V
    0x1a|HU_MOD_SHIFT_LEFT,    // W
    0x1b|HU_MOD_SHIFT_LEFT,    // X
    0x1d|HU_MOD_SHIFT_LEFT,    // Y
    0x1c|HU_MOD_SHIFT_LEFT,    // Z
    0x2f,                      // [
    0x31,                      // bslash
    0x30|HU_MOD_SHIFT_LEFT,    // ]
    0x23|HU_MOD_ALT_RIGHT,     // ^
    0x38|HU_MOD_SHIFT_LEFT,    // _
    0x32,                      // `
    0x04,                      // a
    0x05,                      // b
    0x06,                      // c
    0x07,                      // d
    0x08,                      // e
    0x09,                      // f
    0x0a,                      // g
    0x0b,                      // h
    0x0c,                      // i
    0x0d,                      // j
    0x0e,                      // k
    0x0f,                      // l
    0x10,                      // m
    0x11,                      // n
    0x12,                      // o
    0x13,                      // p
    0x14,                      // q
    0x15,                      // r
    0x16,                      // s
    0x17,                      // t
    0x18,                      // u
    0x19,                      // v
    0x1a,                      // w
    0x1b,                      // x
    0x1d,                      // y
    0x1c,                      // z
    0x24|HU_MOD_ALT_RIGHT,     // {
    0x64|HU_MOD_ALT_RIGHT,     // |
    0x27|HU_MOD_ALT_RIGHT,     // }
    0x30|HU_MOD_ALT_RIGHT,     // ~
    0                          // DEL
};

class DigiKeyboardDeviceHu : public DigiKeyboardDevice {
public:
    size_t write(uint8_t chr) {
        unsigned int temp = pgm_read_word_near(_ascii_hu_map + chr);
        unsigned char low = temp & 0xFF;
        unsigned char high = (temp >> 8) & 0xFF;
        sendKeyStroke(low, high);
        return 1;
    }
    
    void sendKeyReport(uchar *array, const unsigned int size) {
        while (!usbInterruptIsReady()) {
            // Note: We wait until we can send keyPress
            //       so we know the previous keyPress was
            //       sent.
            usbPoll();
            _delay_ms(5);
        }

        usbSetInterrupt(array, size);
    }
};

DigiKeyboardDeviceHu DigiKeyboardHu = DigiKeyboardDeviceHu();

#endif //DIGIKEYBOARDHU_H
