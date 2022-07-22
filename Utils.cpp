#include "Utils.h"

//computing distance is long because of sqrt.
long Utils::squareDistance(int x1, int y1, int x2, int y2){
  int x = x2 - x1;
  int y = y2 - y1;
  return x*x+y*y;
}

/*float Utils::findSQRT(int number)
{
    int start = 0, end = number;
    int mid;
 
    float ans;
 
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }
 
        if (mid * mid < number) {
            ans=start;
            start = mid + 1;
        }
 
        else {
            end = mid - 1;
        }
    }
 
    float increment = 0.1;
    for (int i = 0; i < 3; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }
 
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}*/