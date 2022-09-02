/*
 * @Description: 文件描述
 * @Author: Liu.YF
 * @Date: 2022-06-14 14:36:15
 * @LastEditTime: 2022-06-29 11:42:31
 * @Custom_string_obkoro1_copyright: Copyright (c) ${now_year} by HL, All Rights Reserved. 
 */
#include "../lv_examples.h"
#if LV_BUILD_EXAMPLES && LV_USE_ARC

/**
 * Using the Arc style properties
 */
void lv_example_style_7(void)
{
    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_arc_color(&style, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_arc_width(&style, 4);

    /*Create an object with the new style*/
    lv_obj_t * obj = lv_arc_create(lv_scr_act());
    lv_obj_add_style(obj, &style, 0);
    lv_obj_center(obj);
}
#endif

