#include <stdio.h>
#include <stdlib.h>

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);

    if (A <= B && A <= C) {
        if (B <= C) {
            printf("%d %d %d", A, B, C);
        } else {
            printf("%d %d %d", A, C, B);
        }
    } else if (B <= A && B <= C) {
        if (A <= C) {
            printf("%d %d %d", B, A, C);
        } else {
            printf("%d %d %d", B, C, A);
        }
    } else {
        if (A <= B) {
            printf("%d %d %d", C, A, B);
        } else {
            printf("%d %d %d", C, B, A);
        }
    }

    system("pause");
    return 0;
}