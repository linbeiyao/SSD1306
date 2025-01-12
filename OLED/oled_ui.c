#include "oled.h"
#include "stdio.h"


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

    OLED_ShowFrame();
		HAL_Delay(1000);

}
void UI_show_data(void)
{
    OLED_NewFrame();
    _UI_ShowSystemName();

    OLED_ShowFrame();
}

// 显示状态
void UI_show_status(void)
{
    OLED_NewFrame();

 
    OLED_ShowFrame();
}



void show_EnvUI(uint8_t env)
{
}

