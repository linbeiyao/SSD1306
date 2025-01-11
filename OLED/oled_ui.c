#include "oled.h"
#include "stdio.h"

#define system_file "SmartCup.h" // 不同的系统需要不同的头文件
#include system_file

// 定义系统名称
#define SystemName "Smart_cups" // 不同的系统需要不同的名称

#define OLED_WIDTH 128
#define OLED_HEIGHT 64

/// 定义字体大小
#define font_size1 font8x6
#define font_size2 font12x6
#define font_size3 font16x8
#define font_size4 font24x12

#define center_x(str, font_size) ((OLED_WIDTH - strlen(str) * (font_size).w) / 2)

// 定义居中显示在指定区域的宏函数
#define center_x_region(region_count, region_index, str, font_size) \
    ((OLED_WIDTH / (region_count) * (region_index-1) + (OLED_WIDTH / (region_count) - strlen(str) * (font_size).w) / 2))

#define LINE_SPACING 16 // 每行之间的间距
// 定义每行的位置
const uint8_t line_positions[] = {
    0 * LINE_SPACING, // Line_1
    1 * LINE_SPACING, // Line_2
    2 * LINE_SPACING, // Line_3
    3 * LINE_SPACING  // Line_4
};

// 便利的宏函数
#define _UI_ShowSystemName() OLED_PrintString(center_x(SystemName, font_size3), 8, SystemName, &font_size3, OLED_COLOR_NORMAL); // 语音灯光控制

void UI_main(void)
{

    OLED_NewFrame();
    _UI_ShowSystemName();
    // 打印欢迎信息
    OLED_PrintString(center_x("Welcome", font_size3), line_positions[2], "Welcome", &font_size3, OLED_COLOR_NORMAL);
    
    OLED_ShowFrame();
		HAL_Delay(1000);

}
void UI_show_data(void)
{
    OLED_NewFrame();
    _UI_ShowSystemName();

    // 计算并打印 "temp" 和 "water" 标签
    OLED_PrintString(center_x_region(2, 1, "temp", font_size3), line_positions[2], "temp", &font_size3, OLED_COLOR_NORMAL);
    OLED_PrintString(center_x_region(2, 2, "water", font_size3), line_positions[2], "water", &font_size3, OLED_COLOR_NORMAL);

    uint8_t temp = SmartCup_get_temperature();
    uint16_t water = SmartCup_get_water_level();

    char temp_str[4];  // 增加长度以容纳更大的数值
    char water_str[7]; // 增加长度以容纳更大的数值

    sprintf(temp_str, "%d", temp);
    sprintf(water_str, "%d", water);

    // 计算并打印实际的温度和水位值
    OLED_PrintString(center_x_region(2, 1, temp_str, font_size3), line_positions[3], temp_str, &font_size3, OLED_COLOR_NORMAL);
    OLED_PrintString(center_x_region(2, 2, water_str, font_size3), line_positions[3], water_str, &font_size3, OLED_COLOR_NORMAL);

    OLED_ShowFrame();
}

// 显示状态
void UI_show_status(void)
{
    OLED_NewFrame();
    _UI_ShowSystemName();

    // 加热 杯盖
    // 计算并打印 "" 和 "water" 标签
    OLED_PrintString(center_x_region(2, 1, "heat", font_size3), line_positions[2], "heat", &font_size3, OLED_COLOR_NORMAL);
    OLED_PrintString(center_x_region(2, 2, "lid", font_size3), line_positions[2], "lid", &font_size3, OLED_COLOR_NORMAL);

    char temp_str[6];
    if (SmartCup_get_heater_state() == 1)
    {
        strcpy(temp_str, "YES");
    }
    else if (SmartCup_get_heater_state() == 0)
    {
        strcpy(temp_str, "NO");
    }
    // 计算并打印实际的温度和水位值
    OLED_PrintString(center_x_region(2, 1, temp_str, font_size3), line_positions[3], temp_str, &font_size3, OLED_COLOR_NORMAL);
    

    if (SmartCup_get_lid_state() == 1)
    {
        strcpy(temp_str, "YES");
    }
    else if (SmartCup_get_lid_state() == 0)
    {
        strcpy(temp_str, "NO");
    }
    // 计算并打印实际的温度和水位值
    OLED_PrintString(center_x_region(2, 2, temp_str, font_size3), line_positions[3], temp_str, &font_size3, OLED_COLOR_NORMAL);

    OLED_ShowFrame();
}



void show_EnvUI(uint8_t env)
{
}

