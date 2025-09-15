#include <math.h>
#include <stdio.h>
#include <assert.h>

#define EPS 1e-9

double z1(double alpha) {
    return 1.0 - 0.25 * pow(sin(2 * alpha), 2) + cos(2 * alpha);
}

double z2(double alpha) {
    return pow(cos(alpha), 2) + pow(cos(alpha), 4);
}

int main() {
    // Tests for z1:
    // 1 - 0.25 * sin(0)^2 + cos(0) = 1 - 0 + 1 = 2
    assert(fabs(z1(0) - 2.0) < EPS);
    printf("z1(0) = %f\n", z1(0));

    // 1 - 0.25 * sin(pi)^2 + cos(pi) = 1 - 0 - 1 = 0
    assert(fabs(z1(M_PI / 2) - 0.0) < EPS);
    printf("z1(pi/2) = %f\n", z1(M_PI / 2));

    // 1 - 0.25 * sin(pi / 2)^2 + cos(pi / 2) = 1 - 0.25 * 1 + 0 = 0.75
    assert(fabs(z1(M_PI / 4) - 0.75) < EPS);
    printf("z1(pi/4) = %f\n", z1(M_PI / 4));

    // 1 - 0.25 * sin(2 * pi)^2 + cos(2 * pi) = 1 - 0 + 1 = 2
    assert(fabs(z1(M_PI) - 2.0) < EPS);
    printf("z1(pi) = %f\n\n", z1(M_PI));

    // Tests for z2:
    // cos(0)^2 + cos(0)^4 = 1 + 1 = 2
    assert(fabs(z2(0) - 2.0) < EPS);
    printf("z2(0) = %f\n", z2(0));

    // cos(pi/2)^2 + cos(pi/2)^4 = 0 + 0 = 0
    assert(fabs(z2(M_PI / 2) - 0.0) < EPS);
    printf("z2(pi/2) = %f\n", z2(M_PI / 2));

    // cos(pi/4)^2 + cos(pi/4)^4 = (√2/2)^2 + (√2/2)^4 = 0.5 + 0.25 = 0.75
    assert(fabs(z2(M_PI / 4) - 0.75) < EPS);
    printf("z2(pi/4) = %f\n", z2(M_PI / 4));

    // cos(pi)^2 + cos(pi)^4 = 1 + 1 = 2
    assert(fabs(z2(M_PI) - 2.0) < EPS);
    printf("z2(pi) = %f\n\n", z2(M_PI));

    printf("All tests passed!\n");
    return 0;
}
