#include <stdio.h>
#include <math.h>

int main() {
    int data[10], code[20];
    int m, r = 0, i, j, k = 0, position, parity, error = 0;

    printf("Enter the number of data bits: ");
    scanf("%d", &m);

    printf("Enter the data bits (space-separated): ");
    for (i = 0; i < m; i++)
        scanf("%d", &data[i]);

    while ((int)pow(2, r) < (m + r + 1))
        r++;

    int n = m + r;

    j = 0;
    for (i = 1; i <= n; i++) {
        if (i == (int)pow(2, k)) {
            code[i] = 0;
            k++;
        } else {
            code[i] = data[j];
            j++;
        }
    }

    for (i = 0; i < r; i++) {
        position = (int)pow(2, i);
        parity = 0;
        for (j = position; j <= n; j++) {
            if (((j >> i) & 1) == 1) {
                parity ^= code[j];
            }
        }
        code[position] = parity;
    }

    printf("\nHamming Code (to send): ");
    for (i = n; i >= 1; i--)
        printf("%d", code[i]);
    printf("\n");

    printf("\nEnter the received code bits: ");
    for (i = n; i >= 1; i--)
        scanf("%d", &code[i]);

    for (i = 0; i < r; i++) {
        position = (int)pow(2, i);
        parity = 0;
        for (j = position; j <= n; j++) {
            if (((j >> i) & 1) == 1)
                parity ^= code[j];
        }
        if (parity != 0)
            error += position;
    }

    if (error == 0)
        printf("No error detected!\n");
    else {
        printf("Error detected at bit position: %d\n", error);
        code[error] = (code[error] == 0) ? 1 : 0;
        printf("Corrected code: ");
        for (i = n; i >= 1; i--)
            printf("%d", code[i]);
        printf("\n");
    }

    return 0;
}
