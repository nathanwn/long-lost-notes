#include <stdio.h>
#include "add.h"
#include "subtract.h"

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d\n", a, b, add(a, b));
    printf("%d - %d = %d\n", a, b, subtract(a, b));
    return 0;
}
