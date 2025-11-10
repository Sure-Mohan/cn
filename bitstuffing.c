#include <stdio.h>
#include <string.h>

void main() {
    char input[100], stuffed[200];
    int i, j = 0, count = 0;

    printf("Enter binary data (0s and 1s): ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++) {
        stuffed[j++] = input[i];
        if (input[i] == '1') {
            count++;
            if (count == 5) {
                stuffed[j++] = '0';
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    stuffed[j] = '\0';
    printf("Stuffed Data: %s\n", stuffed);
}
