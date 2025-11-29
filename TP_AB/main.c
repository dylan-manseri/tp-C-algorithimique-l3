#include "structure.h"

int main(void) {
    char* exp = "(23.5+22.6)";
    ArbreExp ae = consA(exp);
    double d = evalAExp(ae);
    printf("%f", d);
}