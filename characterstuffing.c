#include <stdio.h>
#include <string.h>

void main() {
    int i = 0, j = 0, n;
    char a[50], b[100];

    printf("Enter string: ");
    scanf("%s", a);

    n = strlen(a);

    b[0] = 'd';
    b[1] = '1';
    b[2] = 'e';
    b[3] = 's';
    b[4] = 't';
    b[5] = 'x';
    j = 6;

    while (i < n) {
        if (a[i] == 'd' && a[i + 1] == '1' && a[i + 2] == 'e') {
            b[j++] = 'd';
            b[j++] = '1';
            b[j++] = 'e';
            b[j++] = 'd';
            b[j++] = '1';
            b[j++] = 'e';
            i += 3;
        } else {
            b[j++] = a[i++];
        }
    }

    b[j++] = 'd';
    b[j++] = '1';
    b[j++] = 'e';
    b[j++] = 'e';
    b[j++] = 't';
    b[j++] = 'x';
    b[j] = '\0';

    printf("\nFrame after stuffing:\n");
    printf("%s\n", b);
}
