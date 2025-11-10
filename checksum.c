#include <stdio.h>

void main() {
    int data[100], length, i, sum = 0, checksum;

    printf("Enter length of data: ");
    scanf("%d", &length);

    printf("Enter %d data integers:\n", length);
    for (i = 0; i < length; i++) {
        scanf("%d", &data[i]);
        sum += data[i];
    }

    checksum = ~sum;
    printf("Checksum (sender side): %d\n", checksum);

    int receivedSum = 0;
    for (i = 0; i < length; i++) {
        receivedSum += data[i];
    }
    receivedSum += checksum;

    if (receivedSum == -1)
        printf("No error: Data received correctly.\n");
    else
        printf("Error detected in received data.\n");
}
