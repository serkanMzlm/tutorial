#include <stdio.h>

#define COLOR_BLK "\x1b[30m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GRN "\x1b[32m"
#define COLOR_YLW "\x1b[33m"
#define COLOR_BLE "\x1b[34m"
#define COLOR_MGT "\x1b[35m"
#define COLOR_CYN "\x1b[36m"
#define COLOR_WHT "\x1b[37m"
#define COLOR_RST "\x1b[0m"
#define LINE "=================================================================\n"


int main(){
    printf(COLOR_RST LINE);
    printf(COLOR_BLK "Color: Black\n");
    printf(COLOR_RED "Color: Red\n");
    printf(COLOR_GRN "Color: Green\n");
    printf(COLOR_YLW "Color: Yellow\n");
    printf(COLOR_BLE "Color: Blue\n");
    printf(COLOR_MGT "Color: Magenta\n");
    printf(COLOR_CYN "Color: Cyan\n");
    printf(COLOR_WHT "Color: White\n");
    printf(COLOR_RST LINE);
    return 0;
}