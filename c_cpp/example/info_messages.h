#define COLOR_RED "\x1b[31m"
#define COLOR_GRN "\x1b[32m"
#define COLOR_YLW "\x1b[33m"
#define COLOR_BLE "\x1b[34m"
#define COLOR_WHT "\x1b[37m"
#define COLOR_RST "\x1b[0m"

#define ERROR(X) printf("\n"COLOR_RED"%s"COLOR_RST"\n",X)
#define WARN(X)  printf("\n"COLOR_YLW"%s"COLOR_RST"\n",X)
#define DEBUG(X) printf("\n"COLOR_GRN"%s"COLOR_RST"\n",X)
#define INFO(X)  printf("\n"COLOR_WHT"%s"COLOR_RST"\n",X)