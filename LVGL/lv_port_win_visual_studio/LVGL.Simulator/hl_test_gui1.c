/*
 * @Description: 文件描述
 * @Author: Liu.YF
 * @Date: 2022-07-04 13:08:05
 * @LastEditTime: 2022-07-20 09:25:31
 * @Custom_string_obkoro1_copyright: Copyright (c) ${now_year} by HL, All Rights Reserved.
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include <time.h>
#include <hl_gui_imgsrc.h>
#include "lv_drivers/win32drv/win32drv.h"

#define MAX_SHOW_NUM        7
#define BG_CYCLE_NUM        6

#define SET_BIT(_v, bit) (_v |= (1 << bit))
#define CLR_BIT(_v, bit) (_v &= ~(1 << bit))
#define GET_BIT(_v, bit) ((_v >> bit) & 0x01)
#define REVE_BIT(_v, bit) (_v ^= (1 << bit))




typedef enum
{
    BG_BLUE = 0,
    BG_GREEN,
    BG_ORANGE,
    BG_MAX
}hl_bg_color_e;



typedef enum
{
    MODE_COOL = 0,
    MODE_HEAT,
    MODE_DRY,
    MODE_WIND,
    MODE_AUTO,
    MODE_MAX
}hl_mode_idx_e;

typedef enum
{
    SPEED_AUTO = 0,
    SPEED_LV_1,
    SPEED_LV_2,
    SPEED_LV_3,
    SPEED_LV_4,
    SPEED_LV_5,
    SPEED_LV_6,
    SPEED_LV_7,
    SPEED_MAX
}hl_wind_speed_e;

typedef enum
{
    MODE_BTN = 0,
    WIND_SPEED_BTN,
    WIND_UP_DOWN_BTN,
    WIND_RIGHT_LEFT_BTN,
    ECO_BTN,
    SLEEP_BTN,
    BTN_MAX
}hl_gui_imgbtn_e;

typedef enum
{
    ANIM_SNOW = 0,
    ANIM_LIGHT,
    ANIM_WATER,
    ANIM_WIND,
    ANIM_MAX
}hl_gui_anim_e;

typedef struct
{
    lv_obj_t *show_img[MAX_SHOW_NUM];
    lv_obj_t *show_albel[MAX_SHOW_NUM];
    uint8_t text[MAX_SHOW_NUM][8];
    uint8_t used_cnt;
}hl_gui_show_t;


typedef struct
{
    uint8_t last_mode_tabbar1;
    uint8_t last_mode_tabbar2;
    uint8_t last_mode_tabbar3;
    uint8_t btn_flag;
}hl_btn_flag_t;

typedef struct
{
    lv_obj_t *scr;

    lv_obj_t *open_btn;
    lv_obj_t *close_btn;

    lv_obj_t *temp_img[BG_CYCLE_NUM];
    lv_obj_t *temp_arc;
    lv_obj_t *time_label;
    lv_obj_t *right_img;

    lv_obj_t *tabbar1_img;
    lv_obj_t *tabbar1_imgbtn[MODE_MAX];

    lv_obj_t *tabbar2_img;
    lv_obj_t *tabbar2_imgbtn[2];

    lv_obj_t *speed_ctrl_img;
    lv_obj_t *speed_ctrl_slider;
    lv_obj_t *speed_auto_btn;

    lv_obj_t *imgbtn[BTN_MAX];
    lv_obj_t *label_wind;
    lv_obj_t *label_mode;

    lv_obj_t *anim_img_light;
    lv_obj_t *anim_img_wind[4];
    lv_obj_t *anim_img_water;
    lv_obj_t *anim_img_snow[4];
    uint8_t  init_flag[ANIM_MAX];

    hl_gui_show_t show;
    hl_btn_flag_t btn_flag;
    hl_bg_color_e cur_bg;
    hl_mode_idx_e last_mode;
}hl_gui_mcb_t;



typedef struct
{
    const lv_img_dsc_t *imgsrc;
    uint8_t *text;
}hl_show_src_t;

typedef struct
{
    hl_gui_imgbtn_e id;
    const hl_show_src_t *pshow_src;
}hl_show_data_t;

typedef struct
{
    uint16_t x;
    uint16_t y;
}hl_show_pos_t;

typedef struct
{
    const lv_img_dsc_t *nor_src;
    const lv_img_dsc_t *sel_src;
    uint8_t *text;
    uint8_t *sub_text;
}hl_imgbtn_src_t;


static void hl_gui_show_used_cnt_sub(hl_gui_mcb_t *pgui, hl_gui_imgbtn_e btn_id);
static void hl_gui_show_img_set(hl_gui_mcb_t *pgui, hl_gui_imgbtn_e btn_id);
static void hl_gui_show_img_set_wind(hl_gui_mcb_t *pgui, hl_wind_speed_e speed);
static void hl_gui_show_img_set_mode(hl_gui_mcb_t *pgui, hl_mode_idx_e mode_id);
static void hl_set_wind_speed_img(hl_gui_mcb_t *pgui, uint8_t value);
static void hl_gui_anim_cerat(hl_gui_mcb_t *pgui, hl_gui_anim_e type);
static void hl_gui_anim_start(hl_gui_mcb_t *pgui, hl_gui_anim_e type);
static void hl_gui_anim_del(hl_gui_mcb_t *pgui, hl_gui_anim_e type);

static const lv_img_dsc_t *g_cycle_blue_src[] = {
    &control_cycle_blue_a,
    &control_cycle_blue_b,
    &control_cycle_blue_c,
    &control_cycle_blue_d,
    &control_cycle_blue_e,
    &control_cycle_blue_f,
};

static const lv_img_dsc_t *g_cycle_green_src[] = {
    &control_cycle_green_a,
    &control_cycle_green_b,
    &control_cycle_green_c,
    &control_cycle_green_d,
    &control_cycle_green_e,
    &control_cycle_green_f,
};

static const lv_img_dsc_t *g_cycle_orange_src[] = {
    &control_cycle_orange_a,
    &control_cycle_orange_b,
    &control_cycle_orange_c,
    &control_cycle_orange_d,
    &control_cycle_orange_e,
    &control_cycle_orange_f,
};


static const lv_img_dsc_t **g_cycle_src[BG_MAX] = {
    g_cycle_blue_src,
    g_cycle_green_src,
    g_cycle_orange_src
};


static const lv_img_dsc_t *g_tarbar_bg_src[BG_MAX] = {
    &tabbar_bg_blue,
    &tabbar_bg_green,
    &tabbar_bg_orange,
};


static const hl_imgbtn_src_t g_wind_btn_blue_src[] = {
    {&tab_icon_wind_auto_nor_blue,       &tab_icon_wind_auto_sel_blue,       "speed", "   auto"},
    {&tab_icon_wind_speed_nor_blue_fan1, &tab_icon_wind_speed_sel_blue_fan1, "speed", "   lv.1"},
    {&tab_icon_wind_speed_nor_blue_fan2, &tab_icon_wind_speed_sel_blue_fan2, "speed", "   lv.2"},
    {&tab_icon_wind_speed_nor_blue_fan3, &tab_icon_wind_speed_sel_blue_fan3, "speed", "   lv.3"},
    {&tab_icon_wind_speed_nor_blue_fan4, &tab_icon_wind_speed_sel_blue_fan4, "speed", "   lv.4"},
    {&tab_icon_wind_speed_nor_blue_fan5, &tab_icon_wind_speed_sel_blue_fan5, "speed", "   lv.5"},
    {&tab_icon_wind_speed_nor_blue_fan6, &tab_icon_wind_speed_sel_blue_fan6, "speed", "   lv.6"},
    {&tab_icon_wind_speed_nor_blue_fan7, &tab_icon_wind_speed_sel_blue_fan7, "speed", "   lv.7"},
};

static const hl_imgbtn_src_t g_wind_btn_green_src[] = {
    {&tab_icon_wind_auto_nor_green,       &tab_icon_wind_auto_sel_green,       "speed", "   auto"},
    {&tab_icon_wind_speed_nor_green_fan1, &tab_icon_wind_speed_sel_green_fan1, "speed", "   lv.1"},
    {&tab_icon_wind_speed_nor_green_fan2, &tab_icon_wind_speed_sel_green_fan2, "speed", "   lv.2"},
    {&tab_icon_wind_speed_nor_green_fan3, &tab_icon_wind_speed_sel_green_fan3, "speed", "   lv.3"},
    {&tab_icon_wind_speed_nor_green_fan4, &tab_icon_wind_speed_sel_green_fan4, "speed", "   lv.4"},
    {&tab_icon_wind_speed_nor_green_fan5, &tab_icon_wind_speed_sel_green_fan5, "speed", "   lv.5"},
    {&tab_icon_wind_speed_nor_green_fan6, &tab_icon_wind_speed_sel_green_fan6, "speed", "   lv.6"},
    {&tab_icon_wind_speed_nor_green_fan7, &tab_icon_wind_speed_sel_green_fan7, "speed", "   lv.7"},
};


static const hl_imgbtn_src_t g_wind_btn_orange_src[] = {
    {&tab_icon_wind_auto_nor_orange,       &tab_icon_wind_auto_sel_orange,       "speed", "   auto"},
    {&tab_icon_wind_speed_nor_orange_fan1, &tab_icon_wind_speed_sel_orange_fan1, "speed", "   lv.1"},
    {&tab_icon_wind_speed_nor_orange_fan2, &tab_icon_wind_speed_sel_orange_fan2, "speed", "   lv.2"},
    {&tab_icon_wind_speed_nor_orange_fan3, &tab_icon_wind_speed_sel_orange_fan3, "speed", "   lv.3"},
    {&tab_icon_wind_speed_nor_orange_fan4, &tab_icon_wind_speed_sel_orange_fan4, "speed", "   lv.4"},
    {&tab_icon_wind_speed_nor_orange_fan5, &tab_icon_wind_speed_sel_orange_fan5, "speed", "   lv.5"},
    {&tab_icon_wind_speed_nor_orange_fan6, &tab_icon_wind_speed_sel_orange_fan6, "speed", "   lv.6"},
    {&tab_icon_wind_speed_nor_orange_fan7, &tab_icon_wind_speed_sel_orange_fan7, "speed", "   lv.7"},
};

static const hl_imgbtn_src_t *g_wind_btn_src[] = {
    g_wind_btn_blue_src,
    g_wind_btn_green_src,
    g_wind_btn_orange_src
};

static const hl_imgbtn_src_t g_mode_btn_src[MODE_MAX] = {
    {&tab_icon_mode_cool_nor, &tab_icon_mode_cool_pre, "mode", "  cool"},
    {&tab_icon_mode_heat_nor, &tab_icon_mode_heat_pre, "mode", "  heat"},
    {&tab_icon_mode_dehumidification_nor, &tab_icon_mode_dehumidification_pre, "mode", "   dry"},
    {&tab_icon_mode_wind_nor, &tab_icon_mode_wind_pre, "mode", "  wind"},
    {&tab_icon_mode_auto_nor, &tab_icon_mode_auto_pre, "mode", "  auto"},
};

static const hl_imgbtn_src_t g_mode_bar1_src[MODE_MAX] = {
    {&tab_icon_cool_nor, &tab_icon_cool_blue, "cool"},
    {&tab_icon_heat_nor, &tab_icon_heat_orange, "heat"},
    {&tab_icon_humidification_nor, &tab_icon_humidification_blue, "dry"},
    {&tab_icon_wind_nor, &tab_icon_wind_green, "wind"},
    {&tab_icon_auto_nor, &tab_icon_auto_green, "auto"},
};

static const hl_imgbtn_src_t g_mode_bar2_src[] = {
    {&sleep_diy_pop_icon_cool2, &sleep_diy_pop_icon_cool, "cool"},
    {&bottom_icon_heat1, &bottom_icon_heat2, "heat"},
};

static const hl_imgbtn_src_t g_eco_btn_src[] = {
    {&tab_icon_eco_nor, &cool_tab_icon_eco_sel, "ECO"},
    {&tab_icon_eco_nor, &wind_tab_icon_eco_sel, "ECO"},
    {&tab_icon_eco_nor, &heat_tab_icon_eco_sel, "ECO"},
};


static const hl_imgbtn_src_t g_wind_dir_u_d_btn_src[] = {
    {&tab_icon_wind_direction_up_down_nor, &cool_tab_icon_wind_direction_up_down_sel, "U_D"},
    {&tab_icon_wind_direction_up_down_nor, &wind_tab_icon_wind_direction_up_down_sel, "U_D"},
    {&tab_icon_wind_direction_up_down_nor, &heat_tab_icon_wind_direction_up_down_sel, "U_D"},
};

static const hl_imgbtn_src_t g_wind_dir_l_r_btn_src[] = {
    {&tab_icon_wind_direction_left_right_nor, &cool_tab_icon_wind_direction_left_right_sel, "L_R"},
    {&tab_icon_wind_direction_left_right_nor, &wind_tab_icon_wind_direction_left_right_sel, "L_R"},
    {&tab_icon_wind_direction_left_right_nor, &heat_tab_icon_wind_direction_left_right_sel, "L_R"},
};

static const hl_imgbtn_src_t g_sleep_btn_src[] = {
    {&tab_icon_sleep_nor, &cool_tab_icon_sleep_sel, "sleep"},
    {&tab_icon_sleep_nor, &wind_tab_icon_sleep_sel, "sleep"},
    {&tab_icon_sleep_nor, &heat_tab_icon_sleep_sel, "sleep"},
};

static const lv_img_dsc_t *g_wind_ctrl_sel_src[] = {
    &wind_speed_1,
    &wind_speed_2,
    &wind_speed_3,
    &wind_speed_4,
    &wind_speed_5,
    &wind_speed_6,
    &wind_speed_7,
};


static const hl_show_src_t g_show_wind_u_d_src[] = {
    {&aircondition_control_icon_wind_up_down, "u_d"},
};

static const hl_show_src_t g_show_wind_l_r_src[] = {
    {&aircondition_control_wind_left_right, "l_r"},
};

static const hl_show_src_t g_show_wind_eco_src[] = {
    {&aircondition_control_icon_eco, "eco"},
};

static const hl_show_src_t g_show_wind_sleep_src[] = {
    {&aircondition_control_icon_eco, "sleep"},
};

static const hl_show_src_t g_show_mode_src[] = {
    {&aircondition_control_icon_cool, "cool"},
    {&aircondition_control_icon_heat, "heat"},
    {&aircondition_control_icon_dehumidification, "dry"},
    {&aircondition_control_icon_wind, "wind"},
    {&aircondition_control_icon_auto2, "auto"},
};

static const hl_show_src_t g_show_wind_speed_src[] = {
    {&aircondition_control_icon_auto, "auto"},
    {&aircondition_control_fan1, "lv.1"},
    {&aircondition_control_fan2, "lv.2"},
    {&aircondition_control_fan3, "lv.3"},
    {&aircondition_control_fan4, "lv.4"},
    {&aircondition_control_fan5, "lv.5"},
    {&aircondition_control_fan6, "lv.6"},
    {&aircondition_control_fan7, "lv.7"},
};

static hl_show_data_t g_show_data_addr[] = {
    {MODE_BTN, g_show_mode_src},
    {WIND_SPEED_BTN, g_show_wind_speed_src},
    {WIND_UP_DOWN_BTN, g_show_wind_u_d_src},
    {WIND_RIGHT_LEFT_BTN, g_show_wind_l_r_src},
    {ECO_BTN, g_show_wind_eco_src},
    {SLEEP_BTN, g_show_wind_sleep_src},
};

static const hl_show_pos_t g_show_pos[MAX_SHOW_NUM] = {
    {70, 50},
    {130, 50},
    {190, 50},
    {70, 80},
    {130, 80},
    {190, 80},
    {190, 110},
};



static hl_gui_mcb_t g_hl_gui;
static lv_group_t *g_group;

static hl_show_src_t *hl_get_show_data_addr(hl_gui_imgbtn_e btn_id)
{
    if (g_show_data_addr[btn_id].id != btn_id)
        return NULL;
    return (hl_show_src_t *)(g_show_data_addr[btn_id].pshow_src);
}

static void hl_temperature_changed_event_cb(lv_event_t *e)
{
    lv_obj_t *arc = lv_event_get_target(e);
    lv_obj_t *label = lv_event_get_user_data(e);
    lv_label_set_text_fmt(label, "%d°", lv_arc_get_value(arc));
}

static void hl_timer_cb(struct _lv_timer_t *aaa)
{
    hl_gui_mcb_t *pgui = &g_hl_gui;

    char szCurrentDateTime[32] = {0};
    time_t nowtime;
    struct tm *ptm;
    time(&nowtime);
    ptm = localtime(&nowtime);
    sprintf(szCurrentDateTime, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d",
            ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday,
            ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

    lv_label_set_text_fmt(pgui->time_label, "%s", szCurrentDateTime);
}

static void hl_temperature_arc_init(hl_gui_mcb_t *pgui)
{
    pgui->temp_arc = lv_arc_create(pgui->scr);
    lv_obj_set_size(pgui->temp_arc, 160, 160);
    lv_obj_align_to(pgui->temp_arc, pgui->temp_img[0], LV_ALIGN_CENTER, 0, 0);

    // Write style state: LV_STATE_DEFAULT for style_arc_main
    static lv_style_t style_arc_main;
    lv_style_init(&style_arc_main);
    lv_style_set_arc_opa(&style_arc_main, 0);
    lv_style_set_arc_width(&style_arc_main, 15);
    lv_obj_add_style(pgui->temp_arc, &style_arc_main, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for style_arc_indicator
    static lv_style_t style_arc_indicator;
    lv_style_init(&style_arc_indicator);
    lv_style_set_arc_color(&style_arc_indicator, lv_color_make(255, 255, 255));
    lv_style_set_arc_opa(&style_arc_indicator, 0);
    lv_style_set_arc_width(&style_arc_indicator, 15);
    lv_obj_add_style(pgui->temp_arc, &style_arc_indicator, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // Write style state: LV_STATE_DEFAULT for style_arc_knob
    static lv_style_t style_arc_knob;
    lv_style_init(&style_arc_knob);
    lv_style_set_border_color(&style_arc_knob, lv_color_make(255, 0, 234));
    lv_style_set_border_width(&style_arc_knob, 3);
    lv_style_set_border_side(&style_arc_knob, LV_BORDER_SIDE_FULL);
    lv_style_set_bg_color(&style_arc_knob, lv_color_make(255, 255, 255));
    lv_style_set_bg_opa(&style_arc_knob, 255);
    lv_style_set_pad_all(&style_arc_knob, 5);
    lv_obj_add_style(pgui->temp_arc, &style_arc_knob, LV_PART_KNOB | LV_STATE_DEFAULT);

    lv_arc_set_bg_angles(pgui->temp_arc, 140, 40);
    lv_arc_set_angles(pgui->temp_arc, 140, 40);
    lv_arc_set_range(pgui->temp_arc, 16, 33);
    lv_arc_set_value(pgui->temp_arc, 25);

    lv_obj_t *label = lv_label_create(pgui->temp_arc);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_48, LV_PART_MAIN);
    lv_obj_set_style_text_color(label, lv_color_make(0, 0, 0), LV_PART_MAIN);
    lv_label_set_text_fmt(label, "%d°", 25);
    lv_obj_set_style_radius(label, 360, LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_event_cb(pgui->temp_arc, hl_temperature_changed_event_cb, LV_EVENT_VALUE_CHANGED, label);
}


static void hl_bgimg_set(hl_gui_mcb_t *pgui, hl_bg_color_e bg)
{
    uint8_t value = 0;
    const lv_img_dsc_t **cycle_bg_src = g_cycle_src[bg];
    const lv_img_dsc_t *tarbar_bg = g_tarbar_bg_src[bg];
    const hl_imgbtn_src_t *peco_btn_src = &g_eco_btn_src[bg];
    const hl_imgbtn_src_t *pwind_u_d_btn_src = &g_wind_dir_u_d_btn_src[bg];
    const hl_imgbtn_src_t *pwind_l_r_btn_src = &g_wind_dir_l_r_btn_src[bg];
    const hl_imgbtn_src_t *psleep_btn_src = &g_sleep_btn_src[bg];
    hl_btn_flag_t *pbtn_flag = &pgui->btn_flag;

    //set temperature img
    lv_img_set_src(pgui->temp_img[0], cycle_bg_src[0]);
    lv_img_set_src(pgui->temp_img[1], cycle_bg_src[1]);
    lv_img_set_src(pgui->temp_img[2], cycle_bg_src[2]);
    lv_img_set_src(pgui->temp_img[3], cycle_bg_src[3]);
    lv_img_set_src(pgui->temp_img[4], cycle_bg_src[4]);
    lv_img_set_src(pgui->temp_img[5], cycle_bg_src[5]);


    lv_img_set_src(pgui->tabbar1_img, tarbar_bg);
    lv_img_set_src(pgui->speed_ctrl_img, tarbar_bg);

    // btn
    lv_imgbtn_set_src(pgui->imgbtn[WIND_RIGHT_LEFT_BTN], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, pwind_l_r_btn_src->sel_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[WIND_RIGHT_LEFT_BTN], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, pwind_l_r_btn_src->sel_src, 0);

    lv_imgbtn_set_src(pgui->imgbtn[WIND_UP_DOWN_BTN], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, pwind_u_d_btn_src->sel_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[WIND_UP_DOWN_BTN], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, pwind_u_d_btn_src->sel_src, 0);

    lv_imgbtn_set_src(pgui->imgbtn[ECO_BTN], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, peco_btn_src->sel_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[ECO_BTN], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, peco_btn_src->sel_src, 0);

    lv_imgbtn_set_src(pgui->imgbtn[SLEEP_BTN], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, psleep_btn_src->sel_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[SLEEP_BTN], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, psleep_btn_src->sel_src, 0);

    if(pbtn_flag->last_mode_tabbar3 == 0)
    {
        value = lv_slider_get_value(pgui->speed_ctrl_slider);
    }
    hl_set_wind_speed_img(pgui, value);
}

static void hl_bgimg_change(hl_gui_mcb_t *pgui, hl_mode_idx_e mode)
{
    lv_color_t color;
    hl_bg_color_e bg_color = BG_MAX;

    switch (mode)
    {
        case MODE_COOL:
        case MODE_DRY:
            bg_color = BG_BLUE;
            color = lv_color_make(52, 119, 245);
            break;
        case MODE_WIND:
        case MODE_AUTO:
            bg_color = BG_GREEN;
            color = lv_color_make(94, 184, 176);
            break;
        case MODE_HEAT:
            bg_color = BG_ORANGE;
            color = lv_color_make(204, 144, 43);
            break;        
        default:
            return;
            break;
    }

    if(pgui->cur_bg == bg_color)
        return;

    pgui->cur_bg = bg_color;
    lv_obj_set_style_img_recolor(pgui->right_img, color, LV_PART_MAIN);
    lv_obj_set_style_img_recolor_opa(pgui->right_img, 255, LV_PART_MAIN);

    hl_bgimg_set(pgui, bg_color);


}



static void hl_temperature_img_init(hl_gui_mcb_t *pgui)
{
    pgui->temp_img[0] = lv_img_create(pgui->scr);
    lv_img_set_src(pgui->temp_img[0], g_cycle_blue_src[0]);
    lv_obj_align(pgui->temp_img[0], LV_ALIGN_BOTTOM_LEFT, 30, -30);
    lv_obj_set_style_radius(pgui->temp_img[0], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->temp_img[0], true, 0);
    lv_obj_move_background(pgui->temp_img[0]);

    pgui->temp_img[1] = lv_img_create(pgui->scr);
    lv_img_set_src(pgui->temp_img[1], g_cycle_blue_src[1]);
    lv_obj_align_to(pgui->temp_img[1], pgui->temp_img[0], LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_radius(pgui->temp_img[1], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->temp_img[1], true, 0);

    pgui->temp_img[2] = lv_img_create(pgui->scr);
    lv_img_set_src(pgui->temp_img[2], g_cycle_blue_src[2]);
    lv_obj_align_to(pgui->temp_img[2], pgui->temp_img[0], LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_radius(pgui->temp_img[2], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->temp_img[2], true, 0);

    pgui->temp_img[3] = lv_img_create(pgui->scr);
    lv_img_set_src(pgui->temp_img[3], g_cycle_blue_src[3]);
    lv_obj_align_to(pgui->temp_img[3], pgui->temp_img[0], LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_outline_color(pgui->temp_img[3], lv_color_make(41, 71, 219), 0);
    // lv_obj_set_style_outline_width(pgui->temp_img[3], 3, 0);

    lv_obj_set_style_radius(pgui->temp_img[3], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->temp_img[3], true, 0);

    pgui->temp_img[4] = lv_img_create(pgui->scr);
    lv_img_set_src(pgui->temp_img[4], g_cycle_blue_src[4]);
    lv_obj_align_to(pgui->temp_img[4], pgui->temp_img[0], LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_outline_color(pgui->temp_img[4], lv_color_make(41, 71, 219), 0);
    // lv_obj_set_style_outline_width(pgui->temp_img[4], 3, 0);
    lv_obj_set_style_radius(pgui->temp_img[4], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->temp_img[4], true, 0);

    pgui->temp_img[5] = lv_img_create(pgui->scr);
    lv_img_set_src(pgui->temp_img[5], g_cycle_blue_src[5]);
    lv_obj_align_to(pgui->temp_img[5], pgui->temp_img[0], LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_radius(pgui->temp_img[5], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->temp_img[5], true, 0);
}

static void hl_gui_time_init(hl_gui_mcb_t *pgui)
{
    pgui->time_label = lv_label_create(lv_scr_act());

    lv_obj_set_size(pgui->time_label, 480, 40);
    lv_obj_align_to(pgui->time_label, pgui->scr, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_set_style_text_font(pgui->time_label, &lv_font_montserrat_32, LV_PART_MAIN);
    lv_obj_set_style_text_color(pgui->time_label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_label_set_text(pgui->time_label, " ");

    lv_obj_set_style_bg_opa(pgui->time_label, LV_OPA_70, 0);
    lv_obj_set_style_bg_color(pgui->time_label, lv_color_make(5, 10, 20), LV_PART_MAIN);
    lv_obj_set_style_text_color(pgui->time_label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_timer_create(hl_timer_cb, 1000, 0);
}

static void hl_imgbtn_event_cb(lv_event_t *e)
{
    hl_gui_mcb_t *pgui = &g_hl_gui;
    hl_btn_flag_t *pbtn_flag = &pgui->btn_flag;

    lv_obj_t *pimgbtn = lv_event_get_target(e);
    uint8_t btn_id = (uint8_t)lv_event_get_user_data(e);

    if (lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED)
    {
        if (pimgbtn == pgui->imgbtn[btn_id])
        {
            if (btn_id == MODE_BTN)
            {
                if (GET_BIT(pbtn_flag->btn_flag, btn_id) == 0)
                {
                    SET_BIT(pbtn_flag->btn_flag, btn_id);
                    lv_obj_clear_flag(pgui->tabbar1_img, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(pgui->tabbar2_img, LV_OBJ_FLAG_HIDDEN);
                }
                else
                {
                    CLR_BIT(pbtn_flag->btn_flag, btn_id);
                    lv_obj_add_flag(pgui->tabbar1_img, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(pgui->tabbar2_img, LV_OBJ_FLAG_HIDDEN);
                }
                lv_obj_add_flag(pgui->speed_ctrl_img, LV_OBJ_FLAG_HIDDEN);
                if (GET_BIT(pbtn_flag->btn_flag, WIND_SPEED_BTN) == 1)
                {
                    CLR_BIT(pbtn_flag->btn_flag, WIND_SPEED_BTN);
                    lv_imgbtn_set_state(pgui->imgbtn[WIND_SPEED_BTN], LV_IMGBTN_STATE_RELEASED);
                }
            }
            else if (btn_id == WIND_SPEED_BTN)
            {
                if (GET_BIT(pbtn_flag->btn_flag, btn_id) == 0)
                {
                    SET_BIT(pbtn_flag->btn_flag, WIND_SPEED_BTN);
                    lv_obj_clear_flag(pgui->speed_ctrl_img, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(pgui->tabbar1_img, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(pgui->tabbar2_img, LV_OBJ_FLAG_HIDDEN);
                }
                else
                {
                    CLR_BIT(pbtn_flag->btn_flag, WIND_SPEED_BTN);
                    lv_obj_add_flag(pgui->speed_ctrl_img, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(pgui->tabbar2_img, LV_OBJ_FLAG_HIDDEN);
                }

                if (GET_BIT(pbtn_flag->btn_flag, MODE_BTN) == 1)
                {
                    CLR_BIT(pbtn_flag->btn_flag, MODE_BTN);
                    lv_imgbtn_set_state(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_RELEASED);
                }
            }
            else
                hl_gui_show_img_set(pgui, btn_id);
        }
        else if (pimgbtn == pgui->tabbar1_imgbtn[btn_id])
        {
            if (pbtn_flag->last_mode_tabbar1 == btn_id)
            {
                lv_obj_add_state(pgui->tabbar1_imgbtn[btn_id], LV_STATE_CHECKED);
                if (btn_id < MODE_DRY)
                {
                    lv_obj_add_state(pgui->tabbar2_imgbtn[btn_id], LV_STATE_CHECKED);
                }
            }
            else
            {
                lv_imgbtn_set_state(pgui->tabbar1_imgbtn[pbtn_flag->last_mode_tabbar1], LV_IMGBTN_STATE_RELEASED);
                lv_imgbtn_set_state(pgui->tabbar2_imgbtn[pbtn_flag->last_mode_tabbar2], LV_IMGBTN_STATE_RELEASED);
                if (btn_id < MODE_DRY)
                {
                    lv_obj_add_state(pgui->tabbar2_imgbtn[btn_id], LV_STATE_CHECKED);
                    pbtn_flag->last_mode_tabbar2 = btn_id;
                }
            }

            lv_obj_add_flag(pgui->tabbar1_img, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(pgui->tabbar2_img, LV_OBJ_FLAG_HIDDEN);

            lv_imgbtn_set_state(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_RELEASED);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_RELEASED, 0, g_mode_btn_src[btn_id].nor_src, 0);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_PRESSED, 0, g_mode_btn_src[btn_id].nor_src, 0);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, g_mode_btn_src[btn_id].sel_src, 0);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, g_mode_btn_src[btn_id].sel_src, 0);

            lv_label_set_text_static(pgui->label_mode, g_mode_btn_src[btn_id].sub_text);

            hl_gui_show_img_set_mode(pgui, btn_id);

            pbtn_flag->last_mode_tabbar1 = btn_id;
            REVE_BIT(pbtn_flag->btn_flag, MODE_BTN);

            hl_bgimg_change(pgui, btn_id);
            if(btn_id < MODE_AUTO && pgui->last_mode != btn_id)
            {
                hl_gui_anim_del(pgui, pgui->last_mode);
                hl_gui_anim_start(pgui, btn_id);
            }
            if(btn_id == MODE_AUTO)
            {
                hl_gui_anim_del(pgui, pgui->last_mode);
            }
            pgui->last_mode = btn_id;
        }
        else if (pimgbtn == pgui->tabbar2_imgbtn[btn_id] && btn_id < MODE_DRY)
        {
            if (pbtn_flag->last_mode_tabbar2 == btn_id)
            {
                lv_obj_add_state(pgui->tabbar2_imgbtn[btn_id], LV_STATE_CHECKED);
                lv_obj_add_state(pgui->tabbar1_imgbtn[btn_id], LV_STATE_CHECKED);
                if (pbtn_flag->last_mode_tabbar1 > MODE_HEAT)
                    lv_imgbtn_set_state(pgui->tabbar1_imgbtn[pbtn_flag->last_mode_tabbar1], LV_IMGBTN_STATE_RELEASED);
            }
            else
            {
                lv_imgbtn_set_state(pgui->tabbar2_imgbtn[pbtn_flag->last_mode_tabbar2], LV_IMGBTN_STATE_RELEASED);
                lv_imgbtn_set_state(pgui->tabbar1_imgbtn[pbtn_flag->last_mode_tabbar1], LV_IMGBTN_STATE_RELEASED);
                lv_obj_add_state(pgui->tabbar1_imgbtn[btn_id], LV_STATE_CHECKED);
            }

            lv_imgbtn_set_state(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_RELEASED);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_RELEASED, 0, g_mode_btn_src[btn_id].nor_src, 0);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_PRESSED, 0, g_mode_btn_src[btn_id].nor_src, 0);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, g_mode_btn_src[btn_id].sel_src, 0);
            lv_imgbtn_set_src(pgui->imgbtn[MODE_BTN], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, g_mode_btn_src[btn_id].sel_src, 0);

            lv_label_set_text_static(pgui->label_mode, g_mode_btn_src[btn_id].sub_text);
            hl_gui_show_img_set_mode(pgui, btn_id);

            hl_bgimg_change(pgui, btn_id);
            if(pgui->last_mode != btn_id)
            {
                hl_gui_anim_del(pgui, pgui->last_mode);
                hl_gui_anim_start(pgui, btn_id);
                pgui->last_mode = btn_id;
            }

            pbtn_flag->last_mode_tabbar1 = btn_id;
            pbtn_flag->last_mode_tabbar2 = btn_id;
        }
        else if (pimgbtn == pgui->speed_auto_btn)
        {
            if (pbtn_flag->last_mode_tabbar3 == 0)
            {
                pbtn_flag->last_mode_tabbar3 = 1;
            }
            else
            {
                lv_imgbtn_set_state(pgui->speed_auto_btn, LV_IMGBTN_STATE_CHECKED_PRESSED);
            }

            lv_obj_set_style_bg_img_src(pgui->speed_ctrl_slider, g_wind_ctrl_sel_src[6], LV_PART_MAIN);
            hl_set_wind_speed_img(pgui, 0);
            hl_gui_show_img_set_wind(pgui, SPEED_AUTO);
        }
    }
}

static void hl_imgbtn_init(hl_gui_mcb_t *pgui, hl_gui_imgbtn_e btn_id, const hl_imgbtn_src_t *pimgsrc, lv_align_t align, int16_t x, int16_t y)
{
    pgui->imgbtn[btn_id] = lv_imgbtn_create(pgui->scr);
    lv_obj_set_size(pgui->imgbtn[btn_id], 50, 50);
    lv_obj_align(pgui->imgbtn[btn_id], align, x, y);

    lv_imgbtn_set_src(pgui->imgbtn[btn_id], LV_IMGBTN_STATE_RELEASED, 0, pimgsrc->nor_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[btn_id], LV_IMGBTN_STATE_PRESSED, 0, pimgsrc->nor_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[btn_id], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, pimgsrc->sel_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[btn_id], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, pimgsrc->sel_src, 0);

    lv_obj_add_flag(pgui->imgbtn[btn_id], LV_OBJ_FLAG_CHECKABLE);
    // lv_obj_add_state(pgui->imgbtn[btn_id], LV_STATE_CHECKED);
    lv_obj_set_style_radius(pgui->imgbtn[btn_id], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->imgbtn[btn_id], true, 0);

    lv_obj_add_event_cb(pgui->imgbtn[btn_id], hl_imgbtn_event_cb, LV_EVENT_VALUE_CHANGED, (void *)btn_id);

    if (pimgsrc->text != NULL)
    {
        // label
        lv_obj_t *label = lv_label_create(pgui->scr);
        lv_obj_align_to(label, pgui->imgbtn[btn_id], LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
        lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), LV_PART_MAIN);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
        lv_label_set_text_static(label, pimgsrc->text);
    }

    if (WIND_SPEED_BTN == btn_id)
    {
        // label
        pgui->label_wind = lv_label_create(pgui->scr);
        lv_obj_align_to(pgui->label_wind, pgui->imgbtn[btn_id], LV_ALIGN_BOTTOM_MID, 0, 0);
        lv_obj_set_style_text_font(pgui->label_wind, &lv_font_montserrat_8, LV_PART_MAIN);
        // lv_obj_set_style_text_color(label2, lv_color_make(255, 255, 255), LV_PART_MAIN);
        lv_obj_set_style_text_align(pgui->label_wind, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
        lv_label_set_text_static(pgui->label_wind, pimgsrc->sub_text);
    }
    else if (MODE_BTN == btn_id)
    {
        // label
        pgui->label_mode = lv_label_create(pgui->scr);
        lv_obj_align_to(pgui->label_mode, pgui->imgbtn[btn_id], LV_ALIGN_BOTTOM_MID, 0, 0);
        lv_obj_set_style_text_font(pgui->label_mode, &lv_font_montserrat_8, LV_PART_MAIN);
        // lv_obj_set_style_text_color(label2, lv_color_make(255, 255, 255), LV_PART_MAIN);
        lv_obj_set_style_text_align(pgui->label_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
        lv_label_set_text_static(pgui->label_mode, pimgsrc->sub_text);
    }


    // lv_group_add_obj(g_group, pgui->imgbtn[btn_id]);

}

static void hl_right_img_init(hl_gui_mcb_t *pgui)
{
    pgui->right_img = lv_img_create(pgui->scr);
    lv_obj_set_size(pgui->right_img, 160, 280);
    lv_img_set_src(pgui->right_img, &banner_bg);
    lv_obj_align_to(pgui->right_img, pgui->scr, LV_ALIGN_TOP_RIGHT, 0, 40);
    lv_obj_set_style_outline_width(pgui->right_img, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(pgui->right_img, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_right(pgui->right_img, 0, LV_PART_MAIN);
    lv_obj_move_background(pgui->right_img);

    // lv_obj_set_style_radius(pgui->right_img, 10, LV_PART_MAIN);
    // lv_obj_set_style_clip_corner(pgui->right_img, 1, 0);
}

static void hl_tabbar1_imgbtn_creat(hl_gui_mcb_t *pgui, hl_mode_idx_e mode, const hl_imgbtn_src_t *pimgsrc, lv_align_t align, int16_t x, int16_t y)
{
    pgui->tabbar1_imgbtn[mode] = lv_imgbtn_create(pgui->tabbar1_img);

    lv_obj_set_size(pgui->tabbar1_imgbtn[mode], 25, 25);
    lv_obj_align(pgui->tabbar1_imgbtn[mode], align, x, y);

    lv_imgbtn_set_src(pgui->tabbar1_imgbtn[mode], LV_IMGBTN_STATE_RELEASED, 0, pimgsrc->nor_src, 0);
    lv_imgbtn_set_src(pgui->tabbar1_imgbtn[mode], LV_IMGBTN_STATE_PRESSED, 0, pimgsrc->nor_src, 0);
    lv_imgbtn_set_src(pgui->tabbar1_imgbtn[mode], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, pimgsrc->sel_src, 0);
    lv_imgbtn_set_src(pgui->tabbar1_imgbtn[mode], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, pimgsrc->sel_src, 0);

    if (mode == MODE_COOL)
        lv_obj_add_state(pgui->tabbar1_imgbtn[mode], LV_STATE_CHECKED);

    lv_obj_add_flag(pgui->tabbar1_imgbtn[mode], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_radius(pgui->tabbar1_imgbtn[mode], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->tabbar1_imgbtn[mode], true, 0);

    lv_obj_add_event_cb(pgui->tabbar1_imgbtn[mode], hl_imgbtn_event_cb, LV_EVENT_VALUE_CHANGED, (void *)mode);
    // label

    lv_obj_t *label = lv_label_create(pgui->tabbar1_img);
    lv_obj_align_to(label, pgui->tabbar1_imgbtn[mode], LV_ALIGN_OUT_BOTTOM_MID, 0, 2);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, LV_PART_MAIN);
    // lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_label_set_text(label, pimgsrc->text);
}

static void hl_tabbar1_imgbtn_init(hl_gui_mcb_t *pgui)
{
    pgui->tabbar1_img = lv_img_create(pgui->scr);

    lv_obj_set_size(pgui->tabbar1_img, 60, 280);
    lv_img_set_src(pgui->tabbar1_img, &tabbar_bg_blue);
    lv_obj_align_to(pgui->tabbar1_img, pgui->scr, LV_ALIGN_CENTER, 50, 20);
    lv_obj_set_style_outline_width(pgui->tabbar1_img, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(pgui->tabbar1_img, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_right(pgui->tabbar1_img, 0, LV_PART_MAIN);

    hl_tabbar1_imgbtn_creat(pgui, MODE_COOL, &g_mode_bar1_src[MODE_COOL], LV_ALIGN_TOP_MID, 0, 20);
    hl_tabbar1_imgbtn_creat(pgui, MODE_HEAT, &g_mode_bar1_src[MODE_HEAT], LV_ALIGN_TOP_MID, -7, 70);
    hl_tabbar1_imgbtn_creat(pgui, MODE_DRY, &g_mode_bar1_src[MODE_DRY], LV_ALIGN_CENTER, -10, -10);
    hl_tabbar1_imgbtn_creat(pgui, MODE_WIND, &g_mode_bar1_src[MODE_WIND], LV_ALIGN_BOTTOM_MID, -10, -85);
    hl_tabbar1_imgbtn_creat(pgui, MODE_AUTO, &g_mode_bar1_src[MODE_AUTO], LV_ALIGN_BOTTOM_MID, -5, -30);

    lv_obj_add_flag(pgui->tabbar1_img, LV_OBJ_FLAG_HIDDEN);
}

static void hl_tabbar2_imgbtn_creat(hl_gui_mcb_t *pgui, hl_mode_idx_e mode, const hl_imgbtn_src_t *pimgsrc, lv_align_t align, int16_t x, int16_t y)
{
    if (mode > MODE_HEAT)
        return;

    pgui->tabbar2_imgbtn[mode] = lv_imgbtn_create(pgui->tabbar2_img);

    lv_obj_set_size(pgui->tabbar2_imgbtn[mode], 25, 25);
    lv_obj_align(pgui->tabbar2_imgbtn[mode], align, x, y);

    lv_imgbtn_set_src(pgui->tabbar2_imgbtn[mode], LV_IMGBTN_STATE_RELEASED, 0, pimgsrc->nor_src, 0);
    lv_imgbtn_set_src(pgui->tabbar2_imgbtn[mode], LV_IMGBTN_STATE_PRESSED, 0, pimgsrc->nor_src, 0);
    lv_imgbtn_set_src(pgui->tabbar2_imgbtn[mode], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, pimgsrc->sel_src, 0);
    lv_imgbtn_set_src(pgui->tabbar2_imgbtn[mode], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, pimgsrc->sel_src, 0);

    if (mode == 0)
        lv_obj_add_state(pgui->tabbar2_imgbtn[mode], LV_STATE_CHECKED);

    lv_obj_add_flag(pgui->tabbar2_imgbtn[mode], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_radius(pgui->tabbar2_imgbtn[mode], LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->tabbar2_imgbtn[mode], true, 0);

    lv_obj_add_event_cb(pgui->tabbar2_imgbtn[mode], hl_imgbtn_event_cb, LV_EVENT_VALUE_CHANGED, (void *)mode);
    // label

    lv_obj_t *label = lv_label_create(pgui->tabbar2_img);
    lv_obj_align_to(label, pgui->tabbar2_imgbtn[mode], LV_ALIGN_OUT_BOTTOM_MID, 0, 2);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_16, LV_PART_MAIN);
    // lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_label_set_text(label, pimgsrc->text);
}

static void hl_tabbar2_imgbtn_init(hl_gui_mcb_t *pgui)
{
    pgui->tabbar2_img = lv_img_create(pgui->scr);

    lv_obj_set_size(pgui->tabbar2_img, 50, 150);
    lv_img_set_src(pgui->tabbar2_img, &bottom_upward_bg_03);
    lv_obj_align_to(pgui->tabbar2_img, pgui->scr, LV_ALIGN_CENTER, 40, 20);
    lv_obj_set_style_outline_width(pgui->tabbar2_img, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(pgui->tabbar2_img, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_right(pgui->tabbar2_img, 0, LV_PART_MAIN);

    hl_tabbar2_imgbtn_creat(pgui, MODE_COOL, &g_mode_bar2_src[MODE_COOL], LV_ALIGN_TOP_MID, 3, 10);
    hl_tabbar2_imgbtn_creat(pgui, MODE_HEAT, &g_mode_bar2_src[MODE_HEAT], LV_ALIGN_BOTTOM_MID, 0, -25);

    // lv_obj_add_flag(pgui->tabbar2_img, LV_OBJ_FLAG_HIDDEN);
}

static void hl_set_wind_speed_img(hl_gui_mcb_t *pgui, uint8_t value)
{
    const hl_imgbtn_src_t *pwind_btn_src = g_wind_btn_src[pgui->cur_bg];
    uint8_t *ptext = NULL;
    ptext = pwind_btn_src[value].sub_text;

    lv_imgbtn_set_src(pgui->imgbtn[WIND_SPEED_BTN], LV_IMGBTN_STATE_RELEASED, 0, pwind_btn_src[value].nor_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[WIND_SPEED_BTN], LV_IMGBTN_STATE_PRESSED, 0, pwind_btn_src[value].nor_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[WIND_SPEED_BTN], LV_IMGBTN_STATE_CHECKED_RELEASED, 0, pwind_btn_src[value].sel_src, 0);
    lv_imgbtn_set_src(pgui->imgbtn[WIND_SPEED_BTN], LV_IMGBTN_STATE_CHECKED_PRESSED, 0, pwind_btn_src[value].sel_src, 0);
    lv_label_set_text_static(pgui->label_wind, ptext);
}


static void hl_wind_speed_changed_cb(lv_event_t *e)
{
    hl_gui_mcb_t *pgui = &g_hl_gui;
    hl_btn_flag_t *pbtn_flag = &pgui->btn_flag;

    lv_obj_t *slider = lv_event_get_target(e);
    uint8_t value = lv_slider_get_value(slider);

    pbtn_flag->last_mode_tabbar3 = 0;
    lv_imgbtn_set_state(pgui->speed_auto_btn, LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_bg_img_src(slider, g_wind_ctrl_sel_src[value - 1], LV_PART_MAIN);

    hl_set_wind_speed_img(pgui, value);
    hl_gui_show_img_set_wind(pgui, value);
}

static void hl_wind_speed_ctrl_creat(hl_gui_mcb_t *pgui)
{
    pgui->speed_ctrl_slider = lv_slider_create(pgui->speed_ctrl_img);

    lv_obj_remove_style_all(pgui->speed_ctrl_slider); //删除全部样式，主要是为了删除外框
    lv_obj_set_size(pgui->speed_ctrl_slider, 25, 180);
    lv_obj_align(pgui->speed_ctrl_slider, LV_ALIGN_CENTER, -5, -20);
    lv_slider_set_range(pgui->speed_ctrl_slider, 1, 7);
    lv_slider_set_value(pgui->speed_ctrl_slider, 0, false);

    lv_obj_set_style_bg_opa(pgui->speed_ctrl_slider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(pgui->speed_ctrl_slider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(pgui->speed_ctrl_slider, &wind_speed_1, LV_PART_MAIN);

    lv_obj_set_style_opa(pgui->speed_ctrl_slider, 0, LV_PART_INDICATOR | LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(pgui->speed_ctrl_slider, hl_wind_speed_changed_cb, LV_EVENT_VALUE_CHANGED, 0);
}

static void hl_wind_speed_ctrl_init(hl_gui_mcb_t *pgui)
{
    pgui->speed_ctrl_img = lv_img_create(pgui->scr);

    lv_obj_set_size(pgui->speed_ctrl_img, 60, 280);
    lv_img_set_src(pgui->speed_ctrl_img, &tabbar_bg_blue);
    lv_obj_align_to(pgui->speed_ctrl_img, pgui->scr, LV_ALIGN_CENTER, 50, 20);
    lv_obj_set_style_outline_width(pgui->speed_ctrl_img, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(pgui->speed_ctrl_img, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_right(pgui->speed_ctrl_img, 0, LV_PART_MAIN);

    hl_wind_speed_ctrl_creat(pgui);
    lv_obj_add_flag(pgui->speed_ctrl_img, LV_OBJ_FLAG_HIDDEN);

    pgui->speed_auto_btn = lv_imgbtn_create(pgui->speed_ctrl_img);

    lv_obj_set_size(pgui->speed_auto_btn, 30, 30);
    lv_obj_align(pgui->speed_auto_btn, LV_ALIGN_BOTTOM_MID, 0, -30);

    lv_imgbtn_set_src(pgui->speed_auto_btn, LV_IMGBTN_STATE_RELEASED, 0, &tab_wind_speed_icon_auto_nor, 0);
    lv_imgbtn_set_src(pgui->speed_auto_btn, LV_IMGBTN_STATE_PRESSED, 0, &tab_wind_speed_icon_auto_nor, 0);
    lv_imgbtn_set_src(pgui->speed_auto_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, 0, &tab_wind_speed_icon_auto_sel, 0);
    lv_imgbtn_set_src(pgui->speed_auto_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, 0, &tab_wind_speed_icon_auto_sel, 0);

    lv_obj_add_flag(pgui->speed_auto_btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_radius(pgui->speed_auto_btn, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->speed_auto_btn, true, 0);

    lv_obj_add_event_cb(pgui->speed_auto_btn, hl_imgbtn_event_cb, LV_EVENT_VALUE_CHANGED, (void *)0);
    // label

    lv_obj_t *label = lv_label_create(pgui->speed_ctrl_img);
    lv_obj_align_to(label, pgui->speed_auto_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);
    // lv_obj_set_style_text_font(label, &lv_font_montserrat_16, LV_PART_MAIN);
    // lv_obj_set_style_text_color(label, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
    lv_label_set_text(label, "auto");
}

static void hl_anim_light_set_angle(void *img, int32_t v)
{
    lv_img_set_angle((lv_obj_t *)img, v);
}

static void hl_gui_anim_light_creat(hl_gui_mcb_t *pgui)
{
    lv_anim_t a;
    if(pgui->init_flag[ANIM_LIGHT] == 1)
        return;
    pgui->anim_img_light = lv_img_create(pgui->right_img);
    lv_img_set_src(pgui->anim_img_light, &light_animation);
    lv_obj_align(pgui->anim_img_light, LV_ALIGN_TOP_LEFT, -10, -10);
    lv_img_set_pivot(pgui->anim_img_light, 30, 30); /*Rotate around the top left corner*/

    lv_anim_init(&a);
    lv_anim_set_var(&a, pgui->anim_img_light);
    lv_anim_set_exec_cb(&a, hl_anim_light_set_angle);
    lv_anim_set_values(&a, 0, 3600);
    lv_anim_set_time(&a, 8000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

    lv_obj_add_flag(pgui->anim_img_light, LV_OBJ_FLAG_HIDDEN);
    pgui->init_flag[ANIM_LIGHT] = 1;
}

static void hl_gui_anim_wind_creat(hl_gui_mcb_t *pgui)
{
    lv_anim_t a1;
    lv_anim_t a2;

    if(pgui->init_flag[ANIM_WIND] == 1)
        return;

    pgui->anim_img_wind[0] = lv_img_create(pgui->right_img);
    pgui->anim_img_wind[1] = lv_img_create(pgui->right_img);
    pgui->anim_img_wind[2] = lv_img_create(pgui->right_img);
    pgui->anim_img_wind[3] = lv_img_create(pgui->right_img);

    lv_img_set_src(pgui->anim_img_wind[0], &windmill_rod_big);
    lv_obj_align(pgui->anim_img_wind[0], LV_ALIGN_BOTTOM_RIGHT, -20, 0);

    lv_img_set_src(pgui->anim_img_wind[1], &windmill_fan_big);
    lv_obj_align_to(pgui->anim_img_wind[1], pgui->anim_img_wind[0], LV_ALIGN_OUT_TOP_MID, 0, 20);
    lv_img_set_pivot(pgui->anim_img_wind[1], 20, 20); /*Rotate around the top left corner*/

    lv_anim_init(&a1);
    lv_anim_set_var(&a1, pgui->anim_img_wind[1]);
    lv_anim_set_exec_cb(&a1, hl_anim_light_set_angle);
    lv_anim_set_values(&a1, 0, 3600);
    lv_anim_set_time(&a1, 8000);
    lv_anim_set_repeat_count(&a1, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a1);

    // wind_small
    lv_img_set_src(pgui->anim_img_wind[2], &windmill_rod_small);
    lv_obj_align(pgui->anim_img_wind[2], LV_ALIGN_BOTTOM_MID, 0, 0);

    lv_img_set_src(pgui->anim_img_wind[3], &windmill_fan_samll);
    lv_obj_align_to(pgui->anim_img_wind[3], pgui->anim_img_wind[2], LV_ALIGN_OUT_TOP_MID, 0, 15);
    lv_img_set_pivot(pgui->anim_img_wind[3], 15, 15); /*Rotate around the top left corner*/

    lv_anim_init(&a2);
    lv_anim_set_var(&a2, pgui->anim_img_wind[3]);
    lv_anim_set_exec_cb(&a2, hl_anim_light_set_angle);
    lv_anim_set_values(&a2, 0, 3600);
    lv_anim_set_time(&a2, 8000);
    lv_anim_set_repeat_count(&a2, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a2);

    lv_obj_add_flag(pgui->anim_img_wind[0], LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(pgui->anim_img_wind[1], LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(pgui->anim_img_wind[2], LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(pgui->anim_img_wind[3], LV_OBJ_FLAG_HIDDEN);

    pgui->init_flag[ANIM_WIND] = 1;
}

static void hl_anim_set_y_cb(void *var, int32_t v)
{
    lv_obj_set_y(var, v);
}

static void hl_gui_anim_water_creat(hl_gui_mcb_t *pgui)
{
    lv_anim_t a;

    if(pgui->init_flag[ANIM_WATER] == 1)
        return;
    pgui->anim_img_water = lv_img_create(pgui->right_img);
    lv_img_set_src(pgui->anim_img_water, &water);
    lv_obj_align(pgui->anim_img_water, LV_ALIGN_TOP_MID, 0, 0);

    lv_anim_init(&a);
    lv_anim_set_var(&a, pgui->anim_img_water);

    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
    lv_anim_set_exec_cb(&a, hl_anim_set_y_cb);
    lv_anim_set_values(&a, 0, 280);
    lv_anim_set_time(&a, 10000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);

    lv_anim_start(&a);

    lv_obj_add_flag(pgui->anim_img_water, LV_OBJ_FLAG_HIDDEN);
    pgui->init_flag[ANIM_WATER] = 1;
}

uint8_t cnt = 0;
int16_t pos[] = {-20, -10, -20, -30, -40, - 50, -60};
static void anim_ready_cb(struct _lv_anim_t *a)
{
    hl_gui_mcb_t *pgui = &g_hl_gui;

    lv_obj_align(pgui->anim_img_snow[1], LV_ALIGN_TOP_RIGHT, pos[cnt], 0);
    cnt++;
    cnt %= 7;
}

static void hl_gui_anim_snow_creat(hl_gui_mcb_t *pgui)
{
    lv_anim_t a;
    lv_anim_t a1;

    if(pgui->init_flag[ANIM_SNOW] == 1)
    {
        return;
    }
    pgui->anim_img_snow[0] = lv_img_create(pgui->right_img);
    pgui->anim_img_snow[1] = lv_img_create(pgui->right_img);
    // pgui->anim_img_snow[2] = lv_img_create(pgui->right_img);
    // pgui->anim_img_snow[3] = lv_img_create(pgui->right_img);

    lv_img_set_src(pgui->anim_img_snow[0], &tab_snow1);
    lv_obj_align(pgui->anim_img_snow[0], LV_ALIGN_TOP_LEFT, 0, 0);

    lv_anim_init(&a);
    lv_anim_set_var(&a, pgui->anim_img_snow[0]);

    lv_anim_set_path_cb(&a, lv_anim_path_ease_in_out);
    lv_anim_set_exec_cb(&a, hl_anim_set_y_cb);
    lv_anim_set_values(&a, 0, 280);
    lv_anim_set_time(&a, 10000);
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);

    lv_img_set_src(pgui->anim_img_snow[1], &tab_snow2);
    lv_obj_align(pgui->anim_img_snow[1], LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_anim_init(&a1);
    lv_anim_set_var(&a1, pgui->anim_img_snow[1]);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_in_out);
    lv_anim_set_exec_cb(&a1, hl_anim_set_y_cb);
    lv_anim_set_values(&a1, 0, 280);
    lv_anim_set_time(&a1, 10000);
    // lv_anim_set_delay(&a1, 500);
    // lv_anim_set_start_cb(&a1, anim_ready_cb);
    lv_anim_set_repeat_delay(&a1, 500);
    lv_anim_set_repeat_count(&a1, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a1);

    pgui->init_flag[ANIM_SNOW] = 1;
}


static void hl_gui_anim_del(hl_gui_mcb_t *pgui, hl_gui_anim_e type)
{
    // lv_obj_add_flag(pgui->tabbar2_img, LV_OBJ_FLAG_HIDDEN);

    if(type == ANIM_LIGHT)
        lv_obj_add_flag(pgui->anim_img_light, LV_OBJ_FLAG_HIDDEN);
    else if(type == ANIM_SNOW)
    {
        lv_obj_add_flag(pgui->anim_img_snow[0], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(pgui->anim_img_snow[1], LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(pgui->anim_img_snow[2], LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(pgui->anim_img_snow[3], LV_OBJ_FLAG_HIDDEN);
    }
    else if(type == ANIM_WIND)
    {
        lv_obj_add_flag(pgui->anim_img_wind[0], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(pgui->anim_img_wind[1], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(pgui->anim_img_wind[2], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(pgui->anim_img_wind[3], LV_OBJ_FLAG_HIDDEN);
    }
    else if(type == ANIM_WATER)
    {
        lv_obj_add_flag(pgui->anim_img_water, LV_OBJ_FLAG_HIDDEN);
    }
}

static void hl_gui_anim_start(hl_gui_mcb_t *pgui, hl_gui_anim_e type)
{
    if(type == ANIM_LIGHT)
        lv_obj_clear_flag(pgui->anim_img_light, LV_OBJ_FLAG_HIDDEN);
    else if(type == ANIM_SNOW)
    {
        lv_obj_clear_flag(pgui->anim_img_snow[0], LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(pgui->anim_img_snow[1], LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(pgui->anim_img_snow[2], LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(pgui->anim_img_snow[3], LV_OBJ_FLAG_HIDDEN);
    }
    else if(type == ANIM_WIND)
    {
        lv_obj_clear_flag(pgui->anim_img_wind[0], LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(pgui->anim_img_wind[1], LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(pgui->anim_img_wind[2], LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(pgui->anim_img_wind[3], LV_OBJ_FLAG_HIDDEN);
    }
    else if(type == ANIM_WATER)
    {
        lv_obj_clear_flag(pgui->anim_img_water, LV_OBJ_FLAG_HIDDEN);
    }
}



static void hl_gui_anim_cerat(hl_gui_mcb_t *pgui, hl_gui_anim_e type)
{
    switch (type)
    {
        case ANIM_LIGHT:
            hl_gui_anim_light_creat(pgui);
            break;
        case ANIM_SNOW:
            hl_gui_anim_snow_creat(pgui);
            break;
        case ANIM_WIND:
            hl_gui_anim_wind_creat(pgui);
            break;
        case ANIM_WATER:
            hl_gui_anim_water_creat(pgui);
            break;
        default:
            break;
    }
}

static void hl_gui_anim_init(hl_gui_mcb_t *pgui)
{
    hl_gui_anim_cerat(pgui, ANIM_LIGHT);
    hl_gui_anim_cerat(pgui, ANIM_SNOW);
    hl_gui_anim_cerat(pgui, ANIM_WIND);
    hl_gui_anim_cerat(pgui, ANIM_WATER);
}

static void hl_gui_show_img_set(hl_gui_mcb_t *pgui, hl_gui_imgbtn_e btn_id)
{
    uint8_t i, used_cnt = 0;
    hl_gui_show_t *pshow = &pgui->show;
    hl_btn_flag_t *pbtn_flag = &pgui->btn_flag;
    hl_show_src_t *show_src = NULL;

    if (GET_BIT(pbtn_flag->btn_flag, btn_id) == 1)
    {
        lv_obj_add_flag(pshow->show_img[btn_id], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(pshow->show_albel[btn_id], LV_OBJ_FLAG_HIDDEN);
        CLR_BIT(pbtn_flag->btn_flag, btn_id);
    }
    else
    {
        SET_BIT(pbtn_flag->btn_flag, btn_id);
    }

    used_cnt = 2;
    for (i = 2; i < BTN_MAX; i++)
    {
        if ((GET_BIT(pbtn_flag->btn_flag, i) == 1))
        {
            show_src = hl_get_show_data_addr(i);
            if (lv_obj_has_flag(pshow->show_img[i], LV_OBJ_FLAG_HIDDEN))
            {
                lv_obj_clear_flag(pshow->show_img[i], LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(pshow->show_albel[i], LV_OBJ_FLAG_HIDDEN);
            }

            lv_img_set_src(pshow->show_img[i], show_src[0].imgsrc);
            lv_obj_set_pos(pshow->show_img[i], g_show_pos[used_cnt].x, g_show_pos[used_cnt].y);
            lv_obj_align_to(pshow->show_albel[i], pshow->show_img[i],
                            LV_ALIGN_OUT_RIGHT_MID, 0, 0);
            lv_label_set_text(pshow->show_albel[i], show_src[0].text);
            used_cnt++;
        }
    }
}

static void hl_gui_show_img_creat(hl_gui_mcb_t *pgui, hl_gui_imgbtn_e btn_id)
{
    hl_gui_show_t *pshow = &pgui->show;
    hl_show_src_t *show_src = hl_get_show_data_addr(btn_id);

    pshow->show_img[btn_id] = lv_img_create(pgui->scr);
    pshow->show_albel[btn_id] = lv_label_create(pgui->scr);

    if (btn_id <= WIND_SPEED_BTN)
    {
        lv_img_set_src(pshow->show_img[btn_id], show_src[0].imgsrc);
        lv_obj_set_pos(pshow->show_img[btn_id], g_show_pos[btn_id].x, g_show_pos[btn_id].y);
        lv_obj_align_to(pshow->show_albel[btn_id], pshow->show_img[btn_id],
                        LV_ALIGN_OUT_RIGHT_MID, 0, 0);
        lv_label_set_text(pshow->show_albel[btn_id], show_src[0].text);
    }
    else
    {
        lv_obj_add_flag(pshow->show_img[btn_id], LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(pshow->show_albel[btn_id], LV_OBJ_FLAG_HIDDEN);
    }
}

static void hl_gui_show_img_set_wind(hl_gui_mcb_t *pgui, hl_wind_speed_e speed)
{
    hl_gui_show_t *pshow = &pgui->show;
    hl_show_src_t *show_src = hl_get_show_data_addr(WIND_SPEED_BTN);

    lv_img_set_src(pshow->show_img[WIND_SPEED_BTN], show_src[speed].imgsrc);
    lv_label_set_text(pshow->show_albel[WIND_SPEED_BTN], show_src[speed].text);
}

static void hl_gui_show_img_set_mode(hl_gui_mcb_t *pgui, hl_mode_idx_e mode_id)
{
    hl_gui_show_t *pshow = &pgui->show;
    hl_show_src_t *show_src = hl_get_show_data_addr(MODE_BTN);

    lv_img_set_src(pshow->show_img[MODE_BTN], show_src[mode_id].imgsrc);
    lv_label_set_text(pshow->show_albel[MODE_BTN], show_src[mode_id].text);
}

static void hl_gui_show_img_init(hl_gui_mcb_t *pgui)
{
    hl_gui_show_img_creat(pgui, MODE_BTN);
    hl_gui_show_img_creat(pgui, WIND_SPEED_BTN);
    hl_gui_show_img_creat(pgui, WIND_UP_DOWN_BTN);
    hl_gui_show_img_creat(pgui, WIND_RIGHT_LEFT_BTN);
    hl_gui_show_img_creat(pgui, ECO_BTN);
    hl_gui_show_img_creat(pgui, SLEEP_BTN);
}



static void hl_switch_btn_event_cb(lv_event_t *e)
{
    lv_obj_t *imgbtn = lv_event_get_target(e);
    hl_gui_mcb_t *pgui = (hl_gui_mcb_t *)lv_event_get_user_data(e);

    if (lv_event_get_code(e) == LV_EVENT_RELEASED)
    {
        if(pgui->close_btn == imgbtn)
        {
            printf("close\r\n");
        }
        else if (pgui->open_btn == imgbtn)
        {
            /* code */
        }
    }
}

static void hl_close_btn_img_init(hl_gui_mcb_t *pgui)
{
    pgui->close_btn = lv_imgbtn_create(pgui->scr);
    lv_obj_set_size(pgui->close_btn, 47, 47);
    lv_obj_align(pgui->close_btn, LV_ALIGN_TOP_LEFT, 10, 60);

    lv_imgbtn_set_src(pgui->close_btn, LV_IMGBTN_STATE_RELEASED, 0, &nav_icon_switch, 0);
    lv_imgbtn_set_src(pgui->close_btn, LV_IMGBTN_STATE_PRESSED, 0, &nav_icon_switch, 0);
    lv_imgbtn_set_src(pgui->close_btn, LV_IMGBTN_STATE_CHECKED_RELEASED, 0, &nav_icon_switch, 0);
    lv_imgbtn_set_src(pgui->close_btn, LV_IMGBTN_STATE_CHECKED_PRESSED, 0, &nav_icon_switch, 0);

    lv_obj_set_style_radius(pgui->close_btn, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(pgui->close_btn, true, 0);

    lv_obj_add_event_cb(pgui->close_btn, hl_switch_btn_event_cb, LV_EVENT_RELEASED, pgui);
}





lv_obj_t *src1;
lv_obj_t *src2;
lv_obj_t *btn1;
lv_obj_t *btn2;

LV_IMG_DECLARE(test_bg)

///////////////////// FUNCTIONS ////////////////////
static void ui_event_ImgButton1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);

    if(event == LV_EVENT_RELEASED)
    {
        // lv_scr_load_anim(g_hl_gui.scr, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
        if(ta == btn1)
        {
            lv_scr_load_anim(src2, LV_SCR_LOAD_ANIM_FADE_ON, 1000, 0, false);
        }
        else if(ta == btn2)
        {
            lv_scr_load_anim(src1, LV_SCR_LOAD_ANIM_FADE_ON, 1000, 0, false);
        }
    }
}


static void test2(hl_gui_mcb_t *pgui)
{
    // src2 = lv_obj_create(lv_scr_act());
    src2 = lv_obj_create(NULL);
    lv_obj_set_size(src2, 480, 320);

    lv_obj_set_style_bg_img_src(src2, &test_bg, 0);
    lv_obj_set_style_outline_width(src2, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(src2, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_right(src2, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(src2, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(src2, 0, LV_PART_MAIN);
    lv_obj_center(src2);

    btn2 = lv_btn_create(src2);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn2, ui_event_ImgButton1, LV_EVENT_RELEASED, NULL);
}


static void test1(hl_gui_mcb_t *pgui)
{
    src1 = lv_obj_create(NULL);
    // src1 = lv_obj_create(lv_scr_act());

    lv_obj_set_size(src1, 480, 320);
    lv_obj_set_style_bg_img_src(src1, &bg_pic, 0);
    // lv_obj_set_style_outline_width(src1, 0, LV_PART_MAIN);
    // lv_obj_set_style_border_width(src1, 0, LV_PART_MAIN);
    // lv_obj_set_style_pad_right(src1, 0, LV_PART_MAIN);
    // lv_obj_set_style_pad_all(src1, 0, LV_PART_MAIN);
    // lv_obj_set_style_radius(src1, 0, LV_PART_MAIN);
    lv_obj_center(src1);

    btn1 = lv_btn_create(src1);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn1, ui_event_ImgButton1, LV_EVENT_RELEASED, NULL);

    lv_scr_load(src1);
}









void hl_scr_load1(void)
{
    memset(&g_hl_gui, 0, sizeof(hl_gui_mcb_t));

    g_group = lv_group_create();
    lv_group_set_default(g_group);
    lv_indev_set_group(lv_win32_encoder_device_object, g_group);

    g_hl_gui.scr = lv_obj_create(lv_scr_act());
    lv_obj_set_size(g_hl_gui.scr, 480, 320);

    lv_obj_set_style_bg_img_src(g_hl_gui.scr, &bg_pic, 0);
    lv_obj_set_style_outline_width(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_right(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(g_hl_gui.scr, 0, LV_PART_MAIN);
    lv_obj_center(g_hl_gui.scr);

    hl_gui_time_init(&g_hl_gui);
    hl_temperature_img_init(&g_hl_gui);
    hl_temperature_arc_init(&g_hl_gui);
    hl_right_img_init(&g_hl_gui);
    hl_tabbar1_imgbtn_init(&g_hl_gui);
    hl_tabbar2_imgbtn_init(&g_hl_gui);

    hl_wind_speed_ctrl_init(&g_hl_gui);

    hl_gui_anim_init(&g_hl_gui);
    // hl_gui_anim_cerat(&g_hl_gui, ANIM_SNOW);

    hl_gui_show_img_init(&g_hl_gui);

    hl_close_btn_img_init(&g_hl_gui);

    hl_imgbtn_init(&g_hl_gui, WIND_SPEED_BTN, &g_wind_btn_blue_src[4], LV_ALIGN_TOP_RIGHT, -90, 50);
    hl_imgbtn_init(&g_hl_gui, MODE_BTN, &g_mode_btn_src[0], LV_ALIGN_TOP_RIGHT, -90, 140);
    hl_imgbtn_init(&g_hl_gui, ECO_BTN, &g_eco_btn_src[0], LV_ALIGN_TOP_RIGHT, -90, 230);

    hl_imgbtn_init(&g_hl_gui, WIND_UP_DOWN_BTN, &g_wind_dir_u_d_btn_src[0], LV_ALIGN_TOP_RIGHT, -20, 50);
    hl_imgbtn_init(&g_hl_gui, WIND_RIGHT_LEFT_BTN, &g_wind_dir_l_r_btn_src[0], LV_ALIGN_TOP_RIGHT, -20, 140);
    hl_imgbtn_init(&g_hl_gui, SLEEP_BTN, &g_sleep_btn_src[0], LV_ALIGN_TOP_RIGHT, -20, 230);


    return;
}
