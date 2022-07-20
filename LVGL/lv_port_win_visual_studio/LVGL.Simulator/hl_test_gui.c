/*
 * @Description: 文件描述
 * @Author: Liu.YF
 * @Date: 2022-06-30 07:55:13
 * @LastEditTime: 2022-07-12 10:47:42
 * @Custom_string_obkoro1_copyright: Copyright (c) ${now_year} by HL, All Rights Reserved. 
 */
#include "lvgl/lvgl.h"
#include <stdio.h>
#include <time.h>


typedef enum
{
    SWITCH_BTN = 0,
    AUTO_BTN,
    COOL_BTN,
    DRY_BTN,
    WIND_BTN,
    HEAT_BTN,
    SPEED1_BTN,
    SPEED2_BTN,
    SPEED3_BTN,
    SPEED4_BTN,
    BTN_MAX
}hl_gui_btn_e;

typedef struct
{
    lv_obj_t *scr;
    lv_obj_t *btn_obj[BTN_MAX];

    lv_style_t style_imgbtn[BTN_MAX];
    lv_style_t style_press[BTN_MAX];

    lv_obj_t *ltime_label;
    uint8_t last_sel;
    uint8_t last_speed_sel;
}hl_gui_t;

LV_IMG_DECLARE(auto_50x50)
LV_IMG_DECLARE(cool_50x50)
LV_IMG_DECLARE(dry_50x50)
LV_IMG_DECLARE(heat_50x50)
LV_IMG_DECLARE(sleep_50x50)
LV_IMG_DECLARE(switch_50x50)
LV_IMG_DECLARE(wind_50x50)

LV_IMG_DECLARE(fengsu1_50x50)
LV_IMG_DECLARE(fengsu2_50x50)
LV_IMG_DECLARE(fengsu3_50x50)



typedef struct
{
    hl_gui_btn_e btn_id;
    const lv_img_dsc_t *img_src;
    uint8_t *text;
}hl_gui_img_src_t;


static hl_gui_img_src_t g_img_src[] = {
    // {SWITCH_BTN, &kaiguan11_50x50, "开关"},
    {SWITCH_BTN, &switch_50x50, "close"},
    // {AUTO_BTN,   &auto_50x50, "自动"},
    {AUTO_BTN,   &auto_50x50, "auto"},
    // {COOL_BTN,   &zhileng_50x50, "制冷"},
    {COOL_BTN,   &cool_50x50, "cool"},
    // {DRY_BTN,    &kaiguan11_50x50, "除湿"},
    {DRY_BTN,    &dry_50x50, "dry"},
    // {WIND_BTN,   &songfeng_50x50, "送风"},
    {WIND_BTN,   &wind_50x50, "wind"},
    // {HEAT_BTN,   &zhire_50x50, "暖气"},
    {HEAT_BTN,   &heat_50x50, "warm"},
    {SPEED1_BTN, &fengsu1_50x50, NULL},
    {SPEED2_BTN, &fengsu2_50x50, NULL},
    {SPEED3_BTN, &fengsu3_50x50, NULL},
    {SPEED4_BTN, &auto_50x50, NULL},
};

static hl_gui_t g_hl_gui;




static void set_zoom(void *img, int32_t v)
{
    lv_img_set_zoom((lv_obj_t *)img, v);
}



static void hl_imgbtn_event_cb(lv_event_t *e)
{
    hl_gui_t *phl_gui = &g_hl_gui;
    
    if (lv_event_get_code(e) == LV_EVENT_PRESSED )
    {
        uint8_t btn_id = (uint8_t)lv_event_get_user_data(e);
        lv_obj_set_style_img_recolor_opa(phl_gui->btn_obj[btn_id], 100, 0);
        
        if(btn_id < SPEED1_BTN)
        {
            if(phl_gui->last_sel != btn_id)
            {
                lv_obj_set_style_img_recolor_opa(phl_gui->btn_obj[phl_gui->last_sel], 0, 0);
                phl_gui->last_sel = btn_id;
            }
        }
        else
        {
            if(phl_gui->last_speed_sel != btn_id)
            { 
                lv_obj_set_style_img_recolor_opa(phl_gui->btn_obj[phl_gui->last_speed_sel], 0, 0);
                phl_gui->last_speed_sel = btn_id;
            }
        }
    }
}

static void hl_imgbtn_init(hl_gui_btn_e btn_id, lv_align_t align, int16_t x, int16_t y)
{
    hl_gui_t *phl_gui = &g_hl_gui;

    phl_gui->btn_obj[btn_id] = lv_imgbtn_create(phl_gui->scr);
    lv_obj_align(phl_gui->btn_obj[btn_id], align, x, y);
    lv_obj_set_size(phl_gui->btn_obj[btn_id], 50, 50);
    lv_imgbtn_set_src(phl_gui->btn_obj[btn_id], LV_IMGBTN_STATE_RELEASED, 0, g_img_src[btn_id].img_src, 0);

    lv_style_init(&phl_gui->style_imgbtn[btn_id]);
    lv_style_set_radius(&phl_gui->style_imgbtn[btn_id], LV_RADIUS_CIRCLE);
    lv_style_set_clip_corner(&phl_gui->style_imgbtn[btn_id], true);

    lv_style_set_img_recolor(&phl_gui->style_imgbtn[btn_id], lv_color_make(255, 0, 0));
    if(btn_id == SWITCH_BTN || btn_id == SPEED1_BTN)
    {
        lv_style_set_img_recolor_opa(&phl_gui->style_imgbtn[btn_id], 100);
    }
    else
    {
        lv_style_set_img_recolor_opa(&phl_gui->style_imgbtn[btn_id], 0);
    }

    lv_style_init(&phl_gui->style_press[btn_id]);
    lv_style_set_outline_width(&phl_gui->style_press[btn_id], 10);
    lv_style_set_outline_opa(&phl_gui->style_press[btn_id], LV_OPA_TRANSP);
    lv_style_set_translate_y(&phl_gui->style_press[btn_id], 2);

    static lv_style_prop_t tr_prop[] = {LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA, 0};
    static lv_style_transition_dsc_t tr;

    lv_style_transition_dsc_init(&tr, tr_prop, lv_anim_path_ease_out, 300, 0, NULL);
    lv_style_set_transition(&phl_gui->style_press[btn_id], &tr);
    lv_obj_add_style(phl_gui->btn_obj[btn_id], &phl_gui->style_imgbtn[btn_id], 0);
    lv_obj_add_style(phl_gui->btn_obj[btn_id], &phl_gui->style_press[btn_id], LV_STATE_PRESSED);

    if(g_img_src[btn_id].text)
    {
        lv_obj_t *lable = lv_label_create(phl_gui->scr);
        
        lv_obj_set_style_text_font(lable, &lv_font_simsun_16_cjk, LV_PART_MAIN);
        lv_obj_set_style_text_color(lable, lv_color_make(255, 255, 255), LV_PART_MAIN);
        lv_obj_align_to(lable, phl_gui->btn_obj[btn_id], LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
        lv_label_set_text(lable, g_img_src[btn_id].text);
    }

    lv_obj_add_event_cb(phl_gui->btn_obj[btn_id], hl_imgbtn_event_cb, LV_EVENT_PRESSED, (void *)btn_id);
    // lv_obj_add_event_cb(phl_gui->btn_obj[btn_id], hl_imgbtn_event_cb, LV_EVENT_RELEASED, (void *)btn_id);

    // lv_anim_t a;
    // lv_anim_init(&a);
    // lv_anim_set_var(&a, phl_gui->btn_obj[btn_id]);
    // lv_anim_set_exec_cb(&a, set_zoom);
    // lv_anim_set_values(&a, 50, 70);
    // lv_anim_set_playback_time(&a, 1000);
    // lv_anim_set_ready_cb(&a, anim_ready_cb);
    // lv_anim_start(&a);
}



static void hl_temperature_changed_event_cb(lv_event_t *e)
{
    lv_obj_t *arc = lv_event_get_target(e);
    lv_obj_t *label = lv_event_get_user_data(e);
    lv_label_set_text_fmt(label, "%d°", lv_slider_get_value(arc));
}


static void hl_temperature_init(hl_gui_t *pgui)
{
    lv_obj_t *silder = lv_slider_create(pgui->scr);
    lv_obj_align(silder, LV_ALIGN_TOP_RIGHT, -60, 60);
    lv_obj_set_size(silder, 230, 10);

    // Write style state: LV_STATE_DEFAULT for slider_main
    static lv_style_t slider_main;
    lv_style_init(&slider_main);
    lv_style_set_radius(&slider_main, 10);
    lv_style_set_bg_color(&slider_main, lv_color_make(0xa8, 0xa8, 0xa8));
    lv_obj_add_style(silder, &slider_main, LV_PART_MAIN);

    // Write style state: LV_STATE_DEFAULT for slider_indicator
    static lv_style_t slider_indicator;
    lv_style_init(&slider_indicator);
    lv_style_set_radius(&slider_indicator, 10);
    lv_style_set_bg_color(&slider_indicator, lv_color_make(0x6c, 0xd0, 0x72));
    lv_style_set_bg_grad_color(&slider_indicator, lv_color_make(250, 251, 193));
    lv_style_set_bg_grad_dir(&slider_indicator, LV_GRAD_DIR_HOR);
    lv_style_set_bg_opa(&slider_indicator, 255);
    lv_obj_add_style(silder, &slider_indicator, LV_PART_INDICATOR);

    // Write style state: LV_STATE_DEFAULT for slider_knob
    static lv_style_t slider_knob;
    lv_style_init(&slider_knob);
    lv_style_set_radius(&slider_knob, 50);
    lv_style_set_bg_color(&slider_knob, lv_color_make(0xe9, 0xee, 0xe8));
    lv_style_set_bg_grad_color(&slider_knob, lv_color_make(0xe9, 0xed, 0xf1));
    lv_style_set_bg_grad_dir(&slider_knob, LV_GRAD_DIR_VER);
    lv_style_set_bg_opa(&slider_knob, 255);
    lv_obj_add_style(silder, &slider_knob, LV_PART_KNOB);
    lv_slider_set_range(silder, 16, 33);
    lv_slider_set_value(silder, 20, false);

    lv_obj_t *label = lv_label_create(pgui->scr);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_48, LV_PART_MAIN);
    lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_label_set_text_fmt(label, "%d°", 20);
    lv_obj_set_style_radius(label, 360, LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 20, -30);
    
    lv_obj_add_event_cb(silder, hl_temperature_changed_event_cb, LV_EVENT_VALUE_CHANGED, label);
}



static void hl_timer_cb(struct _lv_timer_t *aaa)
{
    hl_gui_t *pgui = &g_hl_gui;

    char szCurrentDateTime[32] = {0};
    time_t nowtime;
    struct tm* ptm;
    time(&nowtime);
    ptm = localtime(&nowtime);
    sprintf(szCurrentDateTime, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d",
        ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
        ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

    lv_label_set_text_fmt(pgui->ltime_label, "%s", szCurrentDateTime);
}



void hl_scr_load(void)
{
    memset(&g_hl_gui, 0, sizeof(hl_gui_t));

    g_hl_gui.last_speed_sel = SPEED1_BTN;
    g_hl_gui.scr = lv_obj_create(lv_scr_act());
    lv_obj_set_size(g_hl_gui.scr, 480, 320);
    lv_obj_set_style_bg_color(g_hl_gui.scr, lv_color_make(86, 94, 100), LV_PART_MAIN);

    lv_obj_set_style_outline_width(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_center(g_hl_gui.scr);

    g_hl_gui.ltime_label = lv_label_create(lv_scr_act());

    lv_obj_set_size(g_hl_gui.ltime_label, 480, 40);
    lv_obj_align_to(g_hl_gui.ltime_label, g_hl_gui.scr, LV_ALIGN_TOP_MID, 0, -20);

    lv_obj_set_style_text_font(g_hl_gui.ltime_label, &lv_font_montserrat_32, LV_PART_MAIN);
    lv_obj_set_style_text_color(g_hl_gui.ltime_label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_label_set_text(g_hl_gui.ltime_label, " ");

    lv_obj_set_style_bg_opa(g_hl_gui.ltime_label, LV_OPA_70, 0);
    lv_obj_set_style_bg_color(g_hl_gui.ltime_label, lv_color_make(5, 10, 20), LV_PART_MAIN);
    lv_obj_set_style_text_color(g_hl_gui.ltime_label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_timer_create(hl_timer_cb, 1000, 0);


    hl_imgbtn_init(SWITCH_BTN, LV_ALIGN_BOTTOM_LEFT, 20, -25);
    hl_imgbtn_init(AUTO_BTN, LV_ALIGN_BOTTOM_LEFT, 90, -25);
    hl_imgbtn_init(COOL_BTN, LV_ALIGN_BOTTOM_LEFT, 160, -25);
    hl_imgbtn_init(DRY_BTN, LV_ALIGN_BOTTOM_LEFT, 230, -25);
    hl_imgbtn_init(WIND_BTN, LV_ALIGN_BOTTOM_LEFT, 300, -25);
    hl_imgbtn_init(HEAT_BTN, LV_ALIGN_BOTTOM_LEFT, 370, -25);
    hl_imgbtn_init(SPEED1_BTN, LV_ALIGN_CENTER, -50, 0);
    hl_imgbtn_init(SPEED2_BTN, LV_ALIGN_CENTER, 20, 0);
    hl_imgbtn_init(SPEED3_BTN, LV_ALIGN_CENTER, 90, 0);
    hl_imgbtn_init(SPEED4_BTN, LV_ALIGN_CENTER, 160, 0);


    static lv_point_t line_points[] = { {120, 30}, {120, 180}};

    lv_obj_t *line1 = lv_line_create(g_hl_gui.scr);
    
    lv_obj_set_style_line_width(line1, 2, 0);
    lv_obj_set_style_line_color(line1, lv_palette_main(LV_PALETTE_GREY), 0);
    lv_obj_set_style_line_rounded(line1, true, 0);
    lv_line_set_points(line1, line_points, 2);     /*Set the points*/

    hl_temperature_init(&g_hl_gui);
}


























