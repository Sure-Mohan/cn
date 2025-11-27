#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int code[10], data[10];
    int m, r = 0, i, j = 0, k = 0, position, parity;
    int error = 0;
    printf("Enter no of data bits: ");
    scanf("%d", &m);
    printf("Enter data bits: ");
    for (i = 1; i <= m; i++)
        scanf("%d", &data[i]);
    while ((int)pow(2, r) < (m + r + 1))
        r++;
    int n = m + r;
    for (i = 1; i <= n; i++) {
        if (i == (int)pow(2, k)) {
            code[i] = 0;
            k++;
        } else {
            code[i] = data[j + 1];
            j++;
        }
    }
    for (i = 0; i < r; i++) {
        position = (int)pow(2, i);
        parity = 0;
        for (j = position; j <= n; j++) {
            if ((j >> i) & 1)
                parity ^= code[j];
        }
        code[position] = parity;
    }
    printf("Hamming code to send: ");
    for (i = 1; i <= n; i++)
        printf("%d ", code[i]);
    printf("\nEnter received code: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &code[i]);
    for (i = 0; i < r; i++) {
        position = (int)pow(2, i);
        parity = 0;
        for (j = position; j <= n; j++) {
            if ((j >> i) & 1)
                parity ^= code[j];
        }
        if (parity)
            error += position;
    }
    if (error == 0)
        printf("No error occurred\n");
    else
        printf("Error occurred at position: %d\n", error);
    return 0;
}
