/*******************************************************************************
 * Size: 8 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_FONT_SOURCEHANSANSCN_8
#define LV_FONT_SOURCEHANSANSCN_8 1
#endif

#if LV_FONT_SOURCEHANSANSCN_8

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x11, 0x11, 0x10, 0x10,

    /* U+0022 "\"" */
    0x48, 0x10, 0x0,

    /* U+0023 "#" */
    0x11, 0x4, 0x42, 0x60, 0x40, 0x69, 0x5, 0x0,
    0x40,

    /* U+0024 "$" */
    0x0, 0x4, 0x25, 0x10, 0x20, 0x5, 0x1, 0x15,
    0x4, 0x0,

    /* U+0025 "%" */
    0x14, 0x1, 0x11, 0x4, 0x45, 0x11, 0x51, 0x15,
    0x44, 0x11, 0x10, 0x41, 0x40,

    /* U+0026 "&" */
    0x14, 0x1, 0x0, 0x14, 0x2, 0x4, 0x48, 0x44,
    0x30, 0x25, 0x80,

    /* U+0027 "'" */
    0x40, 0x0,

    /* U+0028 "(" */
    0x0, 0x41, 0x4, 0x0, 0x1, 0x4, 0x10, 0x0,

    /* U+0029 ")" */
    0x4, 0x11, 0x11, 0x11, 0x40,

    /* U+002A "*" */
    0x10, 0xd0, 0x0,

    /* U+002B "+" */
    0x0, 0x4, 0x59, 0x4, 0x4,

    /* U+002C "," */
    0x11, 0x0,

    /* U+002D "-" */
    0x50,

    /* U+002E "." */
    0x0,

    /* U+002F "/" */
    0x4, 0x4, 0x4, 0x10, 0x10, 0x10, 0x0, 0x40,
    0x40,

    /* U+0030 "0" */
    0x28, 0x41, 0x41, 0x41, 0x41, 0x41, 0x28,

    /* U+0031 "1" */
    0x28, 0x4, 0x4, 0x4, 0x4, 0x4, 0x19,

    /* U+0032 "2" */
    0x18, 0x1, 0x1, 0x4, 0x8, 0x10, 0x65,

    /* U+0033 "3" */
    0x14, 0x1, 0x1, 0x18, 0x2, 0x2, 0x55,

    /* U+0034 "4" */
    0x8, 0x2, 0x1, 0x41, 0x10, 0x5a, 0x1, 0x0,
    0x40,

    /* U+0035 "5" */
    0x25, 0x0, 0x68, 0x2, 0x2, 0x2, 0x58,

    /* U+0036 "6" */
    0x15, 0x10, 0x54, 0x42, 0x41, 0x51, 0x15,

    /* U+0037 "7" */
    0x56, 0x1, 0x4, 0x4, 0x4, 0x10, 0x10,

    /* U+0038 "8" */
    0x18, 0x1, 0x21, 0x2c, 0x41, 0x41, 0x29,

    /* U+0039 "9" */
    0x28, 0x41, 0x41, 0x42, 0x15, 0x1, 0x24,

    /* U+003A ":" */
    0x0, 0x0, 0x0,

    /* U+003B ";" */
    0x0, 0x0, 0x11, 0x0,

    /* U+003C "<" */
    0x0, 0x5, 0x50, 0x14, 0x1,

    /* U+003D "=" */
    0x55, 0x0, 0x55,

    /* U+003E ">" */
    0x0, 0x54, 0x2, 0x14, 0x40,

    /* U+003F "?" */
    0x54, 0x4, 0x4, 0x4, 0x10, 0x0, 0x10,

    /* U+0040 "@" */
    0x5, 0x50, 0x40, 0x10, 0x14, 0x51, 0x11, 0x44,
    0x45, 0x5, 0x41, 0x0, 0x1, 0x50,

    /* U+0041 "A" */
    0x8, 0x5, 0x1, 0x10, 0x44, 0x26, 0x10, 0x44,
    0x4,

    /* U+0042 "B" */
    0x25, 0x4, 0x11, 0x10, 0xa8, 0x10, 0x44, 0x22,
    0x50,

    /* U+0043 "C" */
    0x16, 0x4, 0x4, 0x1, 0x0, 0x40, 0x4, 0x1,
    0xa0,

    /* U+0044 "D" */
    0x26, 0x4, 0x11, 0x4, 0x41, 0x10, 0x84, 0x12,
    0x60,

    /* U+0045 "E" */
    0x25, 0x4, 0x1, 0x0, 0x94, 0x10, 0x4, 0x2,
    0x50,

    /* U+0046 "F" */
    0x25, 0x4, 0x1, 0x0, 0x94, 0x10, 0x4, 0x1,
    0x0,

    /* U+0047 "G" */
    0x19, 0x44, 0x4, 0x1, 0x5, 0x40, 0x44, 0x11,
    0x94,

    /* U+0048 "H" */
    0x10, 0x44, 0x11, 0x4, 0x96, 0x10, 0x44, 0x11,
    0x4,

    /* U+0049 "I" */
    0x11, 0x11, 0x11, 0x10,

    /* U+004A "J" */
    0x1, 0x1, 0x1, 0x1, 0x1, 0x4, 0x68,

    /* U+004B "K" */
    0x11, 0x44, 0x41, 0x80, 0x90, 0x12, 0x4, 0x41,
    0x8,

    /* U+004C "L" */
    0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x25,

    /* U+004D "M" */
    0x20, 0x52, 0x5, 0x10, 0x51, 0x41, 0x15, 0x11,
    0x51, 0x10, 0x10,

    /* U+004E "N" */
    0x20, 0x48, 0x11, 0x44, 0x51, 0x11, 0x44, 0x51,
    0x8,

    /* U+004F "O" */
    0x16, 0x1, 0x8, 0x40, 0x44, 0x1, 0x40, 0x41,
    0x8, 0x1a, 0x0,

    /* U+0050 "P" */
    0x26, 0x4, 0x11, 0x14, 0x94, 0x10, 0x4, 0x1,
    0x0,

    /* U+0051 "Q" */
    0x16, 0x1, 0x8, 0x40, 0x44, 0x1, 0x40, 0x41,
    0x4, 0x15, 0x40, 0x10, 0x1, 0x40,

    /* U+0052 "R" */
    0x26, 0x4, 0x11, 0x4, 0xa4, 0x11, 0x4, 0x81,
    0x4,

    /* U+0053 "S" */
    0x15, 0x4, 0x2, 0x0, 0x24, 0x1, 0x0, 0x42,
    0xa0,

    /* U+0054 "T" */
    0x59, 0x1, 0x0, 0x40, 0x10, 0x4, 0x1, 0x0,
    0x40,

    /* U+0055 "U" */
    0x10, 0x44, 0x11, 0x4, 0x41, 0x10, 0x44, 0x11,
    0xa0,

    /* U+0056 "V" */
    0x81, 0x10, 0x44, 0x10, 0x44, 0x14, 0x5, 0x0,
    0x80,

    /* U+0057 "W" */
    0x42, 0x5, 0x8, 0x14, 0x51, 0x5, 0x14, 0x14,
    0x50, 0x51, 0x42, 0x5, 0x0,

    /* U+0058 "X" */
    0x41, 0x4, 0x41, 0x40, 0x20, 0x14, 0x4, 0x44,
    0x10,

    /* U+0059 "Y" */
    0x81, 0x41, 0x14, 0x14, 0x4, 0x0, 0x0,

    /* U+005A "Z" */
    0x16, 0x0, 0x40, 0x40, 0x10, 0x10, 0x4, 0x6,
    0x50,

    /* U+005B "[" */
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10,

    /* U+005C "\\" */
    0x40, 0x40, 0x0, 0x10, 0x10, 0x10, 0x4, 0x4,
    0x4,

    /* U+005D "]" */
    0x51, 0x11, 0x11, 0x11, 0x10,

    /* U+005E "^" */
    0x14, 0x14, 0x10, 0x41,

    /* U+005F "_" */
    0x55, 0x0,

    /* U+0060 "`" */
    0x41, 0x0,

    /* U+0061 "a" */
    0x19, 0x1, 0x16, 0x41, 0x26,

    /* U+0062 "b" */
    0x10, 0x4, 0x2, 0x60, 0x44, 0x10, 0x44, 0x42,
    0x50,

    /* U+0063 "c" */
    0x29, 0x40, 0x40, 0x40, 0x25,

    /* U+0064 "d" */
    0x1, 0x0, 0x42, 0x61, 0x4, 0x81, 0x10, 0x42,
    0x60,

    /* U+0065 "e" */
    0x29, 0x41, 0x56, 0x40, 0x15,

    /* U+0066 "f" */
    0x10, 0x41, 0x18, 0x10, 0x41, 0x4,

    /* U+0067 "g" */
    0x1a, 0x10, 0x42, 0x40, 0x0, 0x25, 0x10, 0x41,
    0x50,

    /* U+0068 "h" */
    0x10, 0x4, 0x2, 0x50, 0x44, 0x11, 0x4, 0x41,
    0x10,

    /* U+0069 "i" */
    0x0, 0x11, 0x11, 0x10,

    /* U+006A "j" */
    0x0, 0x0, 0x41, 0x4, 0x10, 0x40, 0x20,

    /* U+006B "k" */
    0x10, 0x4, 0x1, 0x10, 0x50, 0x28, 0x4, 0x41,
    0x20,

    /* U+006C "l" */
    0x11, 0x11, 0x11, 0x10,

    /* U+006D "m" */
    0x25, 0x60, 0x48, 0x11, 0x10, 0x44, 0x41, 0x11,
    0x4,

    /* U+006E "n" */
    0x25, 0x4, 0x41, 0x10, 0x44, 0x11, 0x0,

    /* U+006F "o" */
    0x25, 0x10, 0x44, 0x5, 0x4, 0x25, 0x0,

    /* U+0070 "p" */
    0x26, 0x4, 0x41, 0x4, 0x44, 0x25, 0x4, 0x1,
    0x0,

    /* U+0071 "q" */
    0x26, 0x10, 0x48, 0x11, 0x4, 0x26, 0x0, 0x40,
    0x10,

    /* U+0072 "r" */
    0x14, 0x41, 0x4, 0x10,

    /* U+0073 "s" */
    0x18, 0x40, 0x14, 0x4, 0x54,

    /* U+0074 "t" */
    0x0, 0x46, 0x44, 0x10, 0x42, 0x40,

    /* U+0075 "u" */
    0x41, 0x41, 0x41, 0x12, 0x26,

    /* U+0076 "v" */
    0x41, 0x41, 0x14, 0x14, 0x14,

    /* U+0077 "w" */
    0x45, 0x14, 0x51, 0x15, 0x11, 0x48, 0x20, 0x80,

    /* U+0078 "x" */
    0x44, 0x14, 0x24, 0x14, 0x41,

    /* U+0079 "y" */
    0x41, 0x41, 0x14, 0x14, 0x14, 0x10, 0x50,

    /* U+007A "z" */
    0x18, 0x4, 0x10, 0x10, 0x94,

    /* U+007B "{" */
    0x10, 0x41, 0x4, 0x40, 0x41, 0x4, 0x10,

    /* U+007C "|" */
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+007D "}" */
    0x50, 0x41, 0x4, 0x20, 0x41, 0x4, 0x40,

    /* U+007E "~" */
    0x10, 0x5,

    /* U+4E0A "上" */
    0x1, 0x0, 0x1, 0x0, 0x1, 0x0, 0x1, 0x54,
    0x1, 0x0, 0x1, 0x0, 0x1, 0x0, 0x55, 0x54,

    /* U+4E0B "下" */
    0x56, 0x54, 0x1, 0x0, 0x1, 0x40, 0x1, 0x14,
    0x1, 0x0, 0x1, 0x0, 0x1, 0x0,

    /* U+51B7 "冷" */
    0x0, 0x40, 0x10, 0x50, 0x1, 0x4, 0x4, 0x0,
    0x1, 0x54, 0x10, 0x10, 0x40, 0x80, 0x0, 0x10,

    /* U+5236 "制" */
    0x14, 0x1, 0x29, 0x11, 0x44, 0x11, 0x4, 0x11,
    0x19, 0x51, 0x4, 0x41, 0x4, 0x41, 0x4, 0x5,

    /* U+52A8 "动" */
    0x0, 0x10, 0x15, 0x10, 0x0, 0x65, 0x25, 0x11,
    0x10, 0x11, 0x11, 0x11, 0x65, 0x41, 0x0, 0x54,
    0x0, 0x0,

    /* U+53F3 "右" */
    0x0, 0x0, 0x1, 0x0, 0x16, 0x55, 0x4, 0x0,
    0x19, 0x58, 0x4, 0x4, 0x5, 0x58, 0x4, 0x4,

    /* U+5DE6 "左" */
    0x0, 0x0, 0x4, 0x0, 0x19, 0x54, 0x4, 0x0,
    0x15, 0x94, 0x10, 0x40, 0x40, 0x40, 0x5, 0x54,

    /* U+5F0F "式" */
    0x0, 0x40, 0x0, 0x44, 0x55, 0x94, 0x15, 0x40,
    0x4, 0x10, 0x4, 0x10, 0x9, 0x11, 0x50, 0x4,

    /* U+6446 "摆" */
    0x10, 0x0, 0x11, 0x95, 0x25, 0x55, 0x10, 0x64,
    0x24, 0x10, 0x11, 0x95, 0x10, 0x44, 0x22, 0x55,
    0x0, 0x0,

    /* U+6A21 "模" */
    0x10, 0x44, 0x11, 0x98, 0x25, 0x54, 0x25, 0x54,
    0x21, 0x54, 0x51, 0x64, 0x10, 0x50, 0x12, 0x5,
    0x0, 0x0,

    /* U+6E7F "湿" */
    0x0, 0x0, 0x12, 0x58, 0x2, 0x58, 0x11, 0x54,
    0x0, 0x0, 0x0, 0x50, 0x11, 0x54, 0x5, 0xa4,
    0x0, 0x0,

    /* U+70ED "热" */
    0x0, 0x0, 0x10, 0x40, 0x25, 0x90, 0x10, 0x44,
    0x25, 0x84, 0x10, 0x54, 0x11, 0x4, 0x10, 0x44,
    0x0, 0x0,

    /* U+7720 "眠" */
    0x55, 0x58, 0x55, 0x58, 0x45, 0x10, 0x55, 0x64,
    0x45, 0x10, 0x51, 0x11, 0x2, 0x44, 0x0, 0x0,

    /* U+7761 "睡" */
    0x0, 0x4, 0x55, 0x50, 0x55, 0x64, 0x45, 0x24,
    0x55, 0x14, 0x46, 0x68, 0x50, 0x10, 0x1, 0x64,

    /* U+81EA "自" */
    0x0, 0x5, 0x95, 0x40, 0x15, 0x56, 0x40, 0x15,
    0x56, 0x55, 0x64, 0x1,

    /* U+9001 "送" */
    0x0, 0x0, 0x11, 0x10, 0x1, 0x94, 0x21, 0x94,
    0x10, 0x50, 0x11, 0x4, 0x24, 0x0, 0x45, 0x54,
    0x0, 0x0,

    /* U+901F "速" */
    0x0, 0x40, 0x21, 0x94, 0x1, 0x94, 0x20, 0x44,
    0x11, 0xe4, 0x11, 0x44, 0x14, 0x0, 0x45, 0x55,
    0x0, 0x0,

    /* U+9664 "除" */
    0x0, 0x0, 0x54, 0x54, 0x52, 0x54, 0x44, 0x10,
    0x45, 0x64, 0x40, 0x14, 0x42, 0x10, 0x40, 0x50,
    0x0, 0x0,

    /* U+9759 "静" */
    0x4, 0x10, 0x18, 0x58, 0x19, 0x94, 0x15, 0x66,
    0x15, 0x11, 0x25, 0x25, 0x11, 0x10, 0x11, 0x10,

    /* U+97F3 "音" */
    0x1, 0x0, 0x15, 0x64, 0x4, 0x10, 0x55, 0x54,
    0x15, 0x50, 0x15, 0x50, 0x10, 0x0, 0x15, 0x50,

    /* U+98CE "风" */
    0x15, 0x54, 0x10, 0x4, 0x11, 0x44, 0x11, 0x44,
    0x11, 0x44, 0x14, 0x14, 0x40, 0x5, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 28, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 38, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 53, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 7, .adv_w = 68, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 68, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 26, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 83, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 32, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 52, .adv_w = 40, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 60, .adv_w = 40, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 65, .adv_w = 57, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 68, .adv_w = 68, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 73, .adv_w = 32, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 75, .adv_w = 43, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 76, .adv_w = 32, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 50, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 86, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 68, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 68, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 32, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 32, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 165, .adv_w = 68, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 170, .adv_w = 68, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 173, .adv_w = 68, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 178, .adv_w = 58, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 116, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 199, .adv_w = 75, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 82, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 86, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 73, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 68, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 86, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 91, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 35, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 66, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 67, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 101, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 90, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 93, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 78, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 93, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 352, .adv_w = 78, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 74, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 75, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 90, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 70, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 110, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 69, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 64, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 76, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 40, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 442, .adv_w = 50, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 451, .adv_w = 40, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 456, .adv_w = 68, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 460, .adv_w = 71, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 462, .adv_w = 76, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 464, .adv_w = 70, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 478, .adv_w = 64, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 483, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 69, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 38, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 70, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 512, .adv_w = 75, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 33, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 525, .adv_w = 33, .box_w = 3, .box_h = 9, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 532, .adv_w = 67, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 34, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 116, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 76, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 76, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 577, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 586, .adv_w = 46, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 58, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 45, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 76, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 63, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 98, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 59, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 63, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 631, .adv_w = 58, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 636, .adv_w = 40, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 643, .adv_w = 33, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 648, .adv_w = 40, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 655, .adv_w = 68, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 657, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 673, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 687, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 703, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 719, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 737, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 753, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 769, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 785, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 803, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 821, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 839, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 857, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 873, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 889, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 901, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 919, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 937, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 955, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 971, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 987, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x1, 0x3ad, 0x42c, 0x49e, 0x5e9, 0xfdc, 0x1105,
    0x163c, 0x1c17, 0x2075, 0x22e3, 0x2916, 0x2957, 0x33e0, 0x41f7,
    0x4215, 0x485a, 0x494f, 0x49e9, 0x4ac4
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 19978, .range_length = 19141, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 21, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 2, 0, 0, 0, 3, 4, 3,
    5, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 6, 6, 0, 0, 0,
    0, 0, 7, 8, 9, 10, 11, 12,
    13, 0, 0, 14, 15, 16, 0, 0,
    10, 17, 10, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 2, 27, 0, 0,
    0, 0, 28, 29, 30, 0, 31, 32,
    33, 34, 0, 0, 35, 36, 34, 34,
    29, 29, 37, 38, 39, 40, 37, 41,
    42, 43, 44, 45, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 0, 0, 0,
    2, 0, 3, 4, 0, 5, 6, 7,
    8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 10, 0, 0, 0,
    11, 0, 12, 0, 13, 0, 0, 0,
    13, 0, 0, 14, 0, 0, 0, 0,
    13, 0, 13, 0, 15, 16, 17, 18,
    19, 20, 21, 22, 0, 23, 3, 0,
    0, 0, 24, 0, 25, 25, 25, 26,
    27, 0, 28, 29, 0, 0, 30, 30,
    25, 30, 25, 30, 31, 32, 33, 34,
    35, 36, 37, 38, 0, 0, 3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, 0, 0, -15, 0, -15, 0,
    0, 0, 0, -7, 0, -12, -1, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    -5, 0, 0, 0, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 11, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -12, 0, -18,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -14, -2, -9, -4, 0,
    -12, 0, 0, 0, -2, 0, 0, 0,
    3, 0, 0, -5, 0, -3, -2, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -2, -6, 0, -3, -1, -3, -9, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 0, -1, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, -1, -11, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    -5, 0, -1, 5, 5, 0, 0, 2,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -7, 0, -14,
    0, 0, 0, 0, 0, 0, -3, -1,
    -1, 0, 0, -7, -2, -2, 0, 1,
    -2, -1, -6, 4, 0, -1, 0, 0,
    0, 0, 4, -2, -1, -1, 0, 0,
    -1, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -2, -3, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -2, -1, -1, -2, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, -3, -1, -3, -3,
    -2, 0, 0, 0, -1, -1, 0, 0,
    0, 0, -3, 0, 0, 0, 0, -3,
    -1, -2, -1, 0, -2, 0, 0, 0,
    0, -5, 0, 0, 0, -3, 0, 0,
    0, -1, 0, -5, 0, -3, 0, -1,
    -1, -2, -3, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, -3, 0, -1, 0, -3,
    -1, 0, 0, 0, 0, 0, -9, 0,
    -9, -11, 0, 0, 0, -5, -1, -20,
    -2, 0, 0, 1, 1, -3, 1, -4,
    0, -4, -2, 0, -3, 0, 0, -3,
    -2, -1, -2, -2, -2, -3, -2, -3,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, -3, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, -6,
    0, -3, 0, 0, 0, 0, -1, -1,
    -2, 0, -1, -2, -2, -1, -1, 0,
    -2, 0, 0, 0, -1, 0, 0, 0,
    -1, 0, 0, -3, -2, -2, -2, -2,
    -2, -2, 0, -9, 0, -20, 0, -8,
    0, 0, 0, 0, -3, 1, -3, 0,
    -3, -17, -3, -11, -8, 0, -10, 0,
    -11, 0, -2, -2, 0, 0, 0, 0,
    0, -2, -1, -4, -4, 0, -4, 0,
    0, 0, 0, 0, -15, -5, -15, -12,
    0, 0, 0, -7, 0, -21, -1, -4,
    0, 0, 0, -3, -1, -13, 0, -7,
    -4, 0, -5, 0, 0, 0, -1, 0,
    0, 0, 0, -2, 0, -3, 0, 0,
    0, -1, 0, -4, 0, 0, 0, 0,
    0, 0, 0, -3, -2, -2, 0, 2,
    1, 0, 1, -1, 0, 0, -1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -1, 0, 0, 0, -3,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, -2, -2, -3, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, -14, -11,
    -14, -14, -3, -3, 0, -6, -3, -18,
    -6, 0, 0, 0, 0, -3, -2, -8,
    0, -11, -9, -3, -11, 0, 0, -7,
    -8, -3, -7, -5, -5, -6, -5, -11,
    0, 0, 0, 0, -2, 0, -2, -5,
    0, 0, 0, -3, 0, -6, -1, 0,
    0, 0, 0, -1, -2, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, -9, -3, -9, -8, 0, 0,
    0, -2, -1, -11, -1, 0, -1, 1,
    0, 0, 0, -3, 0, -2, -2, 0,
    -3, 0, 0, -3, -1, 0, -4, -1,
    -1, -2, -1, -4, 0, 0, 0, 0,
    -4, -1, -4, -6, 0, 0, 0, 0,
    -1, -10, -1, 0, 0, 0, 0, 0,
    0, -1, 0, -3, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -1, 0, -1, 0, -3,
    0, 0, 0, 0, 0, 1, -2, 1,
    -2, -3, -1, 0, 0, 0, 0, 0,
    0, -1, -1, -2, 0, 0, 0, 0,
    0, -2, -1, -2, -2, -1, -2, -2,
    0, 0, 0, 0, -12, -9, -12, -11,
    -3, -3, -1, -2, -2, -14, -2, -2,
    -1, 0, 0, 0, 0, -4, 0, -9,
    -5, 0, -8, 0, 0, -6, -5, -3,
    -4, -2, -3, -4, -2, -6, 0, 0,
    0, 0, 0, -5, 0, 0, 0, 0,
    0, -1, -3, -5, -4, 0, -1, -1,
    -1, 0, -2, -3, 0, -3, -4, -3,
    -2, 0, 0, 0, 0, -2, -4, -3,
    -3, -3, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -13, -5, -8, -5, 0,
    -11, 0, 0, 0, 0, 0, 5, 0,
    11, 0, 0, 0, 0, -3, -1, 0,
    2, 0, 0, 0, 0, -8, 0, 0,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, -3, 0, -2, 0, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, -5, 0, -5, -1, 1, -1, 0,
    0, 0, -1, 0, 0, 0, 0, -8,
    0, -3, 0, 0, -6, 0, -3, -2,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, -2,
    0, 0, -3, 0, 0, -1, -3, 0,
    -1, 0, 0, 0, 0, -1, 0, 1,
    1, 2, 1, 0, 0, 0, 0, -5,
    0, 1, 0, 0, 0, 0, -1, 0,
    0, -3, -3, -3, 0, -2, -1, 0,
    -3, 0, -2, -2, 0, 0, -1, 0,
    0, 0, 0, -1, 0, 1, 1, -1,
    1, 1, 3, 6, 8, 0, -6, -2,
    -6, -3, 0, 0, 4, 0, 0, 0,
    0, 7, 0, 10, 7, 5, 9, 0,
    11, -3, -1, 0, -2, 0, -1, 0,
    0, 0, 0, 2, 0, 0, 0, -2,
    0, 0, 3, -5, 0, 0, 0, 8,
    0, 0, -4, 0, 0, 0, 0, -3,
    0, 0, 0, 0, -2, 0, 0, -2,
    -2, 0, 0, 0, 5, 0, 0, 0,
    0, 0, 0, 0, 3, -2, 0, 0,
    0, -5, 0, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, -3, 0, -1,
    0, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    2, -4, 2, 0, 2, 2, -1, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    -1, 0, 0, -1, -2, 0, -1, 0,
    -1, 0, 0, -2, -2, 0, 0, -1,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, -2, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -6, -3, -6, -5, 5, 5,
    0, -2, 0, -7, 0, 0, 0, 0,
    0, 0, 0, -1, 2, -3, -1, 0,
    -1, 0, 0, 0, 0, 0, 0, 5,
    4, 0, 5, 0, 0, 0, 0, -8,
    0, 1, 0, 0, 0, 0, -1, 0,
    0, 0, 0, -3, 0, -1, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, -3,
    2, 2, 3, 3, -3, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, -3, -2, 0, -1, 0, 0, 0,
    -1, -3, 0, 0, 0, -3, 0, 0,
    0, 0, 0, -2, -3, -1, -3, -3,
    0, 0, 0, -2, 0, -6, 0, -3,
    0, -1, 0, 0, -2, -1, 0, -3,
    0, 0, 0, 0, -1, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 0, 0,
    0, -2, -3, 0, -3, -1, 0, 0,
    0, 0, 0, -4, 0, -3, 0, -1,
    0, -2, -3, 0, 0, -1, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -2, 0, 0, -3,
    1, -2, -1, 0, 0, 1, 0, 0,
    -1, 0, 0, -5, 0, -2, 0, -1,
    -4, 0, 0, -1, -2, 0, 0, 0,
    0, 0, 0, -3, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, -3, 0,
    -3, -3, 0, 0, 0, 0, 0, -6,
    0, -3, 0, 0, 0, 0, -1, 0,
    0, -3, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, -2, 0, -3,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -4,
    0, 0, 0, 0, -5, 0, 0, -4,
    -1, 0, -1, 0, 0, 0, 0, 0,
    -1, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 45,
    .right_class_cnt     = 38,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 2,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_font_sourcehansansCN_8 = {
#else
lv_font_t lv_font_sourcehansansCN_8 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 11,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_FONT_SOURCEHANSANSCN_8*/

