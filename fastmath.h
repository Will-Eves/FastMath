#include <math.h>

double Math_Cos(double x) {
    if (x < 0) {
        int q = -x / 6.28318;
        q += 1;
        double y = q * 6.28318;
        x = -(x - y);
    }
    if (x >= 6.28318) {
        int q = x / 6.28318;
        double y = q * 6.28318;
        x = x - y;
    }
    int s = 1;
    if (x >= 3.14159) {
        s = -1;
        x -= 3.14159;
    }
    if (x > 1.57079) {
        x = 3.14159 - x;
        s = -s;
    }
    double z = x * x;
    double r = z * (z * (0.04158 - 0.00129 * z) - 0.5) + 1.0;
    if (r > 1.0) r = r - 2.0;
    if (s > 0) return r;
    else return -r;
}

double Math_Sin(double a){
    return Math_Cos(a - 1.57079);
}

float Math_Sqrt(float x){
    unsigned int i = *(unsigned int*) &x;
    i  += 127 << 23;
    i >>= 1;
    return *(float*) &i;
}
