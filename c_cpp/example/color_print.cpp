#include <iostream>

using namespace std;

///////////////////////////////
#define COLOR_BLK "\x1b[30m"
#define COLOR_RED "\x1b[31m"
#define COLOR_GRN "\x1b[32m"
#define COLOR_YLW "\x1b[33m"
#define COLOR_BLE "\x1b[34m"
#define COLOR_MGT "\x1b[35m"
#define COLOR_CYN "\x1b[36m"
#define COLOR_WHT "\x1b[37m"
#define COLOR_RST "\x1b[0m"

#define BLACK_STRIPE "\x1b[40m"
#define RED_STRIPE "\x1b[41m"
#define GREEN_STRIPE "\x1b[42m"
#define YELLOW_STRIPE "\x1b[43m"
#define BLUE_STRIPE "\x1b[44m"
#define MAGENTA_STRIPE "\x1b[45m"
#define CYAN_STRIPE "\x1b[46m"
#define WHITE_STRIPE "\x1b[47m"

#define UNDERLINE "\x1b[21m"
#define LINE "=================================================================\n"


int main(){
    cout << COLOR_BLK << " Blue " << COLOR_RED << " Red " << endl
         << COLOR_GRN << " Green " << COLOR_YLW << " Yellow " << endl
         << COLOR_BLE << " Blue " << COLOR_MGT << " Magenta " << endl
         << COLOR_CYN << " Cyan " << COLOR_WHT << " White " << endl;

    cout << BLACK_STRIPE << " Blue " << RED_STRIPE << " Red " << COLOR_RST << endl
         << GREEN_STRIPE << " Green " << YELLOW_STRIPE << " Yellow " << COLOR_RST << endl
         << BLUE_STRIPE << " Blue " << MAGENTA_STRIPE << " Magenta " << COLOR_RST << endl
         << CYAN_STRIPE << " Cyan " << WHITE_STRIPE << " White " << COLOR_RST << endl;

    cout << UNDERLINE << " Underline " << COLOR_RST << endl;
    return 0;
}