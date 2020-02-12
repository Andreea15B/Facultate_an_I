#include "Triunghi.h"
#include <cmath>

Triunghi::Triunghi(int x1, int y1, int x2, int y2, int x3, int y3) {
    X1 = x1;
    Y1 = y1;
    X2 = x2;
    Y2 = y2;
    X3 = x3;
    Y3 = y3;
}

double Triunghi::ComputeArea() {
    int AB, BC, AC;
    AB = sqrt(pow(X2-X1, 2) + pow(Y2-Y1, 2));
    BC = sqrt(pow(X2-X3, 2) + pow(Y2-Y3, 2));
    AC = sqrt(pow(X3-X1, 2) + pow(Y3-Y1, 2));
    int semip = (AB + BC + AC)/2;
    return sqrt(semip*(semip-AB)*(semip-AC)*(semip-BC));
}

const char * Triunghi::GetName() {
    return "Triunghi";
}
