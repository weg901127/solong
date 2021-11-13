#include "../header/solong.h"

int charcnt(char *buf)
{
    int cnt;

    cnt = 0;
    while(*buf++)
        cnt++;
    return cnt;
}
