// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 4  - ap_continue (Read/Write/SC)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/COR)
//        bit 0 - ap_done (Read/COR)
//        bit 1 - ap_ready (Read/COR)
//        others - reserved
// 0x10 : Data signal of image_rgb
//        bit 31~0 - image_rgb[31:0] (Read/Write)
// 0x14 : Data signal of image_rgb
//        bit 31~0 - image_rgb[63:32] (Read/Write)
// 0x18 : reserved
// 0x1c : Data signal of image_gray
//        bit 31~0 - image_gray[31:0] (Read/Write)
// 0x20 : Data signal of image_gray
//        bit 31~0 - image_gray[63:32] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of temp_buf
//        bit 31~0 - temp_buf[31:0] (Read/Write)
// 0x2c : Data signal of temp_buf
//        bit 31~0 - temp_buf[63:32] (Read/Write)
// 0x30 : reserved
// 0x34 : Data signal of filter
//        bit 31~0 - filter[31:0] (Read/Write)
// 0x38 : Data signal of filter
//        bit 31~0 - filter[63:32] (Read/Write)
// 0x3c : reserved
// 0x40 : Data signal of output_r
//        bit 31~0 - output_r[31:0] (Read/Write)
// 0x44 : Data signal of output_r
//        bit 31~0 - output_r[63:32] (Read/Write)
// 0x48 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define CONTROL_ADDR_AP_CTRL         0x00
#define CONTROL_ADDR_GIE             0x04
#define CONTROL_ADDR_IER             0x08
#define CONTROL_ADDR_ISR             0x0c
#define CONTROL_ADDR_IMAGE_RGB_DATA  0x10
#define CONTROL_BITS_IMAGE_RGB_DATA  64
#define CONTROL_ADDR_IMAGE_GRAY_DATA 0x1c
#define CONTROL_BITS_IMAGE_GRAY_DATA 64
#define CONTROL_ADDR_TEMP_BUF_DATA   0x28
#define CONTROL_BITS_TEMP_BUF_DATA   64
#define CONTROL_ADDR_FILTER_DATA     0x34
#define CONTROL_BITS_FILTER_DATA     64
#define CONTROL_ADDR_OUTPUT_R_DATA   0x40
#define CONTROL_BITS_OUTPUT_R_DATA   64
