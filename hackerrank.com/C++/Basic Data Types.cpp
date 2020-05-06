#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a;
    long b;
    char c;
    float d;
    double e;
    // remember space vefore reading char
    scanf("%d%ld %c%f%lf", &a, &b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%.3f\n%.3lf\n", a, b, c, d, e);

    return 0;
}
