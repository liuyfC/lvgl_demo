/*
 * @Description: 文件描述
 * @Author: Liu.YF
 * @Date: 2022-06-14 14:33:43
 * @LastEditTime: 2022-07-19 15:04:07
 * @Custom_string_obkoro1_copyright: Copyright (c) ${now_year} by HL, All Rights Reserved. 
 */
/*
 * PROJECT:   LVGL PC Simulator using Visual Studio
 * FILE:      LVGL.Simulator.cpp
 * PURPOSE:   Implementation for LVGL ported to Windows Desktop
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */

#include <Windows.h>

#include "resource.h"

#if _MSC_VER >= 1200
// Disable compilation warnings.
#pragma warning(push)
// nonstandard extension used : bit field types other than int
#pragma warning(disable : 4214)
// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable : 4244)
#endif

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"
#include "lv_drivers/win32drv/win32drv.h"
#include <hl_gui_imgsrc.h>

#if _MSC_VER >= 1200
// Restore compilation warnings.
#pragma warning(pop)
#endif

#include <stdio.h>


// typedef struct
// {
//     lv_obj_t *img;
//     lv_obj_t *bar;
//     lv_obj_t *img_btn_open;
//     lv_obj_t *temp_slider;
//     lv_obj_t *dis_time;
//     /* data */
// } hl_gui_t;

// static hl_gui_t g_hl_gui;
// static lv_style_t style_bg;
// static lv_style_t style_indic;

// static void set_angle(void *img, int32_t v)
// {
//     lv_img_set_angle((lv_obj_t *)img, v);
// }

// static void set_zoom(void *img, int32_t v)
// {
//     lv_img_set_zoom((lv_obj_t *)img, v);
// }

// static void hl_temperature_changed_event_cb(lv_event_t *e)
// {
//     lv_obj_t *arc = lv_event_get_target(e);
//     lv_obj_t *label = lv_event_get_user_data(e);
//     lv_label_set_text_fmt(label, "%d°", lv_slider_get_value(arc));
// }

// void hl_temperature_init(hl_gui_t *pgui)
// {
//     pgui->temp_slider = lv_slider_create(pgui->img);
//     lv_obj_align(pgui->temp_slider, LV_ALIGN_BOTTOM_MID, 0, -20);
//     lv_obj_set_size(pgui->temp_slider, 200, 15);

//     // Write style state: LV_STATE_DEFAULT for slider_main
//     static lv_style_t slider_main;
//     lv_style_init(&slider_main);
//     lv_style_set_radius(&slider_main, 10);
//     lv_style_set_bg_color(&slider_main, lv_color_make(0xa8, 0xa8, 0xa8));
//     lv_style_set_outline_color(&slider_main, lv_color_make(0x21, 0x27, 0x2b));
//     lv_style_set_outline_width(&slider_main, 0);
//     lv_style_set_outline_opa(&slider_main, 0);
//     lv_style_set_pad_left(&slider_main, 0);
//     lv_style_set_pad_right(&slider_main, 0);
//     lv_style_set_pad_top(&slider_main, 0);
//     lv_style_set_pad_bottom(&slider_main, 0);
//     lv_obj_add_style(pgui->temp_slider, &slider_main, LV_PART_MAIN);

//     // Write style state: LV_STATE_DEFAULT for slider_indicator
//     static lv_style_t slider_indicator;
//     lv_style_init(&slider_indicator);
//     lv_style_set_radius(&slider_indicator, 10);
//     lv_style_set_bg_color(&slider_indicator, lv_color_make(0x6c, 0xd0, 0x72));
//     lv_style_set_bg_grad_color(&slider_indicator, lv_color_make(250, 251, 193));
//     lv_style_set_bg_grad_dir(&slider_indicator, LV_GRAD_DIR_HOR);
//     lv_style_set_bg_opa(&slider_indicator, 255);
//     lv_obj_add_style(pgui->temp_slider, &slider_indicator, LV_PART_INDICATOR);

//     // Write style state: LV_STATE_DEFAULT for slider_knob
//     static lv_style_t slider_knob;
//     lv_style_init(&slider_knob);
//     lv_style_set_radius(&slider_knob, 50);
//     lv_style_set_bg_color(&slider_knob, lv_color_make(0xe9, 0xee, 0xe8));
//     lv_style_set_bg_grad_color(&slider_knob, lv_color_make(0xe9, 0xed, 0xf1));
//     lv_style_set_bg_grad_dir(&slider_knob, LV_GRAD_DIR_VER);
//     lv_style_set_bg_opa(&slider_knob, 255);
//     lv_obj_add_style(pgui->temp_slider, &slider_knob, LV_PART_KNOB);
//     lv_slider_set_range(pgui->temp_slider, 16, 33);
//     lv_slider_set_value(pgui->temp_slider, 20, false);

//     lv_obj_t *label = lv_label_create(pgui->img);
//     lv_obj_set_style_text_font(label, &lv_font_montserrat_48, LV_PART_MAIN);
//     lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), LV_PART_MAIN);
//     lv_label_set_text_fmt(label, "%d°", 25);
//     lv_obj_set_style_radius(label, 360, LV_PART_MAIN);
//     lv_obj_align_to(label, pgui->temp_slider, LV_ALIGN_OUT_TOP_MID, 0, 0);
    
//     lv_obj_add_event_cb(pgui->temp_slider, hl_temperature_changed_event_cb, LV_EVENT_VALUE_CHANGED, label);
// }

// static void hl_timer_cb(struct _lv_timer_t *aaa)
// {
//     hl_gui_t *pgui = &g_hl_gui;
//     static int i = 0;
//     lv_label_set_text_fmt(pgui->dis_time, "%d", 25 + (i++));
// }

// static void hl_dis_time_init(hl_gui_t *pgui)
// {
//     // hl_gui_t *pgui = &g_hl_gui;
    
//     /*Create an Arc*/
//     pgui->dis_time = lv_label_create(lv_scr_act());

//     lv_obj_set_size(pgui->dis_time, 480, 40);
//     lv_obj_align_to(pgui->dis_time, pgui->img, LV_ALIGN_TOP_MID, 0, -20);
//     lv_label_set_text(pgui->dis_time, " ");

//     lv_obj_set_style_bg_opa(pgui->dis_time, LV_OPA_70, 0);
//     lv_obj_set_style_bg_color(pgui->dis_time, lv_color_make(5, 10, 20), LV_PART_MAIN);
//     lv_obj_set_style_text_color(pgui->dis_time, lv_color_make(255, 255, 255), LV_PART_MAIN);
//     lv_timer_create(hl_timer_cb, 1000, 0);
// }




// static void btn_open_event_cb(lv_event_t *e)
// {
//     if (lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED )
//     {
//         hl_gui_t *pgui = (hl_gui_t *)lv_event_get_user_data(e);
//         lv_obj_set_size(pgui->img_btn_open, 50, 50);
//         lv_obj_align(pgui->img_btn_open, LV_ALIGN_LEFT_MID, 0, 0);
//         lv_imgbtn_set_src(pgui->img_btn_open, LV_IMGBTN_STATE_RELEASED, 0, &kaiguan_50x50, 0);
//         hl_temperature_init(pgui);
//         hl_dis_time_init(pgui);
//     }
// }

// static void hl_open_init(hl_gui_t *pgui)
// {
//     // hl_gui_t *pgui = &g_hl_gui;

//     static lv_style_t style_btn_open;

//     static lv_style_t style_def;
//     lv_style_init(&style_def);

//     lv_style_set_border_opa(&style_def, LV_OPA_40);
//     lv_style_set_border_width(&style_def, 2);
//     lv_style_set_border_color(&style_def, lv_color_make(105, 105, 105));

//     lv_style_set_outline_opa(&style_def, LV_OPA_COVER);
//     lv_style_set_outline_color(&style_def, lv_color_make(168, 168, 168));
//     lv_style_set_outline_width(&style_def, 30);
//     lv_style_set_pad_all(&style_def, 30);

//     /*Darken the button when pressed and make it wider*/
//     static lv_style_t style_pr;
//     lv_style_init(&style_pr);

//     lv_style_set_outline_width(&style_pr, 50);
//     lv_style_set_outline_opa(&style_pr, LV_OPA_TRANSP);
//     lv_style_set_translate_y(&style_pr, 5);
//     lv_style_set_shadow_ofs_y(&style_pr, 3);

//     // lv_style_set_img_recolor_opa(&style_pr, 20);
//     // lv_style_set_img_recolor(&style_pr, lv_color_make(71, 168, 68));

//     // lv_style_set_bg_opa(&style_pr, LV_OPA_TRANSP);
//     // lv_style_set_bg_img_recolor(&style_pr, lv_color_make(171, 168, 168));

//     static lv_style_prop_t tr_prop[] = {LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA, 0};
//     static lv_style_transition_dsc_t tr;
//     lv_style_transition_dsc_init(&tr, tr_prop, lv_anim_path_linear, 300, 0, NULL);

//     lv_style_set_transition(&style_pr, &tr);

//     /*Create an image button*/
//     pgui->img_btn_open = lv_imgbtn_create(pgui->img);
//     lv_imgbtn_set_src(pgui->img_btn_open, LV_IMGBTN_STATE_RELEASED, 0, &kaiguan_120x120, 0);
//     lv_obj_add_flag(pgui->img_btn_open, LV_OBJ_FLAG_CHECKABLE);
//     lv_obj_set_size(pgui->img_btn_open, 120, 120);
//     lv_obj_add_style(pgui->img_btn_open, &style_def, 0);
//     lv_obj_add_style(pgui->img_btn_open, &style_pr, LV_STATE_PRESSED);
//     lv_obj_align(pgui->img_btn_open, LV_ALIGN_CENTER, 0, 0);

//     lv_obj_add_event_cb(pgui->img_btn_open, btn_open_event_cb, LV_EVENT_ALL, pgui);



//     static lv_style_t img_style1;
//     lv_obj_t *img11 = lv_img_create(pgui->img);
//     lv_obj_align(img11, LV_ALIGN_BOTTOM_LEFT, 50, 0);
//     lv_img_set_src(img11, &fengsu2_50x50);
//     lv_style_init(&img_style1);
//     lv_style_set_radius(&img_style1, 50);
//     lv_style_set_img_recolor(&img_style1, lv_color_make(2, 168, 2));
//     lv_style_set_img_recolor_opa(&img_style1, 0);
//     // lv_style_set_bg_opa(&img_style1, 255);
//     lv_obj_add_style(img11, &img_style1, 0);

//     static lv_style_t btn_style1;
//     lv_obj_t *btn11 = lv_btn_create(pgui->img);
//     lv_obj_align(btn11, LV_ALIGN_BOTTOM_LEFT, 50, 0);
//     lv_obj_move_foreground(btn11);

//     lv_style_init(&btn_style1);
//     lv_style_set_radius(&btn_style1, 50);
//     lv_style_set_size(&btn_style1, 50);
//     lv_style_set_bg_opa(&btn_style1, 0);
//     lv_obj_add_style(btn11, &btn_style1, 0);

// }

// static void hl_gui_main_page(hl_gui_t *pgui)
// {
//     // hl_gui_t *pgui = pgui_t;

//     pgui->img = lv_obj_create(lv_scr_act());
//     lv_obj_set_size(pgui->img, 480, 320);
//     lv_obj_set_style_bg_color(pgui->img, lv_color_make(168, 168, 168), LV_PART_MAIN);
//     // lv_obj_set_style_bg_grad_color(pgui->img, lv_color_make(104, 163, 154), LV_PART_MAIN);
//     // lv_obj_set_style_bg_grad_dir(pgui->img, LV_GRAD_DIR_HOR, 0);

//     lv_obj_set_style_outline_width(pgui->img, 0, LV_PART_MAIN);
//     lv_obj_set_style_border_width(pgui->img, 0, LV_PART_MAIN);
//     lv_obj_set_style_radius(pgui->img, 0, LV_PART_MAIN);
//     lv_obj_center(pgui->img);

//     // temperature
//     hl_open_init(pgui);
//     // hl_temperature_init(pgui);
//     // hl_dis_time_init(pgui);
// }

// static void anim_ready_cb(struct _lv_anim_t *a)
// {
//     hl_gui_t *pgui = &g_hl_gui;

//     lv_obj_del(pgui->bar);
//     lv_obj_del(pgui->img);
//     hl_gui_main_page(pgui);
// }

// static void hl_gui_init(void)
// {
//     memset(&g_hl_gui, 0, sizeof(hl_gui_t));
// }

// void hl_gui_power_up(void)
// {
//     lv_anim_t a;
//     hl_gui_t *pgui = &g_hl_gui;

//     /*Now create the actual image*/
//     pgui->img = lv_img_create(lv_scr_act());
//     lv_img_set_src(pgui->img, &light_animation);
//     // lv_img_set_src(pgui->img, &windmill_fan_big);
//     lv_obj_align(pgui->img, LV_ALIGN_TOP_LEFT, 0, 0);
//     lv_img_set_pivot(pgui->img, 30, 30); /*Rotate around the top left corner*/

//     lv_anim_init(&a);
//     lv_anim_set_var(&a, pgui->img);
//     lv_anim_set_exec_cb(&a, set_angle);
//     lv_anim_set_values(&a, 0, 3600);
//     lv_anim_set_time(&a, 3000);
//     lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
//     lv_anim_start(&a);

    // lv_anim_set_exec_cb(&a, set_zoom);
    // lv_anim_set_values(&a, 240, 256);
    // lv_anim_set_playback_time(&a, 1000);
    // lv_anim_set_ready_cb(&a, anim_ready_cb);
    // lv_anim_start(&a);

    // lv_style_init(&style_bg);
    // // lv_style_set_border_color(&style_bg, lv_palette_main(LV_PALETTE_LIME));
    // lv_style_set_border_width(&style_bg, 1);
    // lv_style_set_pad_all(&style_bg, 0); /*To make the indicator smaller*/
    // lv_style_set_radius(&style_bg, 6);
    // lv_style_set_anim_time(&style_bg, 1500);

    // lv_style_init(&style_indic);
    // lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    // lv_style_set_bg_color(&style_indic, lv_palette_main(LV_PALETTE_GREY));
    // lv_style_set_radius(&style_indic, 3);

    // pgui->bar = lv_bar_create(lv_scr_act());
    // lv_obj_remove_style_all(pgui->bar); /*To have a clean start*/
    // lv_obj_add_style(pgui->bar, &style_bg, 0);
    // lv_obj_add_style(pgui->bar, &style_indic, LV_PART_INDICATOR);

    // lv_obj_set_size(pgui->bar, 200, 15);
    // lv_obj_align_to(pgui->bar, pgui->img, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    // lv_bar_set_value(pgui->bar, 100, LV_ANIM_ON);
// }



extern void hl_scr_load(void);
extern void hl_scr_load1(void);
extern void hl_scr_load11(void);

int main()
{
    lv_init();
    if (!lv_win32_init(
            GetModuleHandleW(NULL),
            SW_SHOW,
            1200,
            800,
            LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL))))
    {
        return -1;
    }

    lv_win32_add_all_input_devices_to_group(NULL);
    // hl_scr_load();
lv_demo_keypad_encoder();
    // hl_scr_load1();
    // hl_scr_load11();
    // hl_gui_init();
    // hl_gui_power_up();
    /*
     * Demos, benchmarks, and tests.
     *
     * Uncomment any one (and only one) of the functions below to run that
     * item.
     */

    // ----------------------------------
    // my freetype application
    // ----------------------------------

    ///*Init freetype library
    // *Cache max 64 faces and 1 size*/
    // lv_freetype_init(64, 1, 0);

    ///*Create a font*/
    // static lv_ft_info_t info;
    // info.name = "./lvgl/src/extra/libs/freetype/arial.ttf";
    // info.weight = 36;
    // info.style = FT_FONT_STYLE_NORMAL;
    // lv_ft_font_init(&info);

    ///*Create style with the new font*/
    // static lv_style_t style;
    // lv_style_init(&style);
    // lv_style_set_text_font(&style, info.font);

    ///*Create a label with the new style*/
    // lv_obj_t* label = lv_label_create(lv_scr_act());
    // lv_obj_add_style(label, &style, 0);
    // lv_label_set_text(label, "FreeType Arial Test");

    // ----------------------------------
    // my Win32 filesystem driver application
    // ----------------------------------

    /*::lv_fs_win32_init();

    lv_fs_dir_t d;
    if (lv_fs_dir_open(&d, "/") == LV_FS_RES_OK)
    {
        char b[MAX_PATH];
        memset(b, 0, MAX_PATH);
        while (lv_fs_dir_read(&d, b) == LV_FS_RES_OK)
        {
            printf("%s\n", b);
        }

        lv_fs_dir_close(&d);
    }*/

    // ----------------------------------
    // Demos from lv_examples
    // ----------------------------------

    // lv_demo_widgets();           // ok
    // lv_demo_benchmark();
    // lv_demo_keypad_encoder();    // ok
    // lv_demo_music();             // removed from repository
    // lv_demo_printer();           // removed from repository
    // lv_demo_stress();            // ok

    // ----------------------------------
    // LVGL examples
    // ----------------------------------

    /*
     * There are many examples of individual widgets found under the
     * lvgl\exampless directory.  Here are a few sample test functions.
     * Look in that directory to find all the rest.
     */

    // lv_ex_get_started_1();
    // lv_ex_get_started_2();
    // lv_ex_get_started_3();

    // lv_example_flex_1();
    // lv_example_flex_2();
    // lv_example_flex_3();
    // lv_example_flex_4();
    // lv_example_flex_5();
    // lv_example_flex_6();        // ok

    // lv_example_grid_1();
    // lv_example_grid_2();
    // lv_example_grid_3();
    // lv_example_grid_4();
    // lv_example_grid_5();
    // lv_example_grid_6();

    // lv_port_disp_template();
    // lv_port_fs_template();
    // lv_port_indev_template();

    // lv_example_scroll_1();
    // lv_example_scroll_2();
    // lv_example_scroll_3();

    // lv_example_style_1();
    // lv_example_style_2();
    // lv_example_style_3();
    // lv_example_style_4();        // ok
    // lv_example_style_6();        // file has no source code
    // lv_example_style_7();
    // lv_example_style_8();
    // lv_example_style_9();
    // lv_example_style_10();
    // lv_example_style_11();       // ok

    // ----------------------------------
    // LVGL widgets examples
    // ----------------------------------

    // lv_example_arc_1();
    // lv_example_arc_2();

    // lv_example_bar_1();          // ok
    // lv_example_bar_2();
    // lv_example_bar_3();
    // lv_example_bar_4();
    // lv_example_bar_5();
    // lv_example_bar_6();          // issues

    // lv_example_btn_1();
    // lv_example_btn_2();
    // lv_example_btn_3();

    // lv_example_btnmatrix_1();
    // lv_example_btnmatrix_2();
    // lv_example_btnmatrix_3();

    // lv_example_calendar_1();

    // lv_example_canvas_1();
    // lv_example_canvas_2();

    // lv_example_chart_1();        // ok
    // lv_example_chart_2();        // ok
    // lv_example_chart_3();        // ok
    // lv_example_chart_4();        // ok
    // lv_example_chart_5();        // ok
    // lv_example_chart_6();        // ok

    // lv_example_checkbox_1();
    // lv_example_checkbox_2();
    // lv_example_colorwheel_1();   // ok

    // lv_example_dropdown_1();
    // lv_example_dropdown_2();
    // lv_example_dropdown_3();

    // lv_example_img_1();
    // lv_example_img_2();
    // lv_example_img_3();
    // lv_example_img_4();         // ok

    // lv_example_imgbtn_1();

    // lv_example_keyboard_1();    // ok

    // lv_example_label_1();
    // lv_example_label_2();       // ok

    // lv_example_led_1();

    // lv_example_line_1();

    // lv_example_list_1();

    // lv_example_meter_1();
    // lv_example_meter_2();
    // lv_example_meter_3();
    // lv_example_meter_4();       // ok

    // lv_example_msgbox_1();

    // lv_example_obj_1();         // ok

    // lv_example_roller_1();
    // lv_example_roller_2();      // ok

    // lv_example_slider_1();      // ok
    // lv_example_slider_2();      // issues
    // lv_example_slider_3();      // issues

    // lv_example_spinbox_1();

    // lv_example_spinner_1();     // ok

    // lv_example_switch_1();      // ok

    // lv_example_table_1();
    // lv_example_table_2();       // ok

    // lv_example_tabview_1();

    // lv_example_textarea_1();    // ok
    // lv_example_textarea_2();
    // lv_example_textarea_3();    // ok, but not all button have functions

    // lv_example_tileview_1();    // ok

    // lv_example_win_1();         // ok

    // ----------------------------------
    // Task handler loop
    // ----------------------------------

    while (!lv_win32_quit_signal)
    {
        lv_task_handler();
        Sleep(1);
    }

    return 0;
}
