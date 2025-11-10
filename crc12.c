#include <stdio.h>

int main() {
    int data[50], crc[12], n, i, j, error = 0;
    int generator[13] = {1,1,0,0,0,0,0,0,0,0,0,1,1};

    printf("Enter number of data bits: ");
    scanf("%d", &n);

    printf("Enter data bits (0 or 1): ");
    for(i = 0; i < n; i++)
        scanf("%d", &data[i]);

    for(i = 0; i < 12; i++)
        crc[i] = 0;

    for(i = 0; i < n; i++) {
        int bit = data[i] ^ crc[0];
        for(j = 0; j < 11; j++)
            crc[j] = crc[j+1] ^ (bit & generator[j+1]);
        crc[11] = bit & generator[12];
    }

    printf("\nCRC bits: ");
    for(i = 0; i < 12; i++)
        printf("%d", crc[i]);

    printf("\nTransmitted codeword: ");
    for(i = 0; i < n; i++)
        printf("%d", data[i]);
    for(i = 0; i < 12; i++)
        printf("%d", crc[i]);

    printf("\n\nEnter received codeword (data + CRC): ");
    int received[62];
    for(i = 0; i < n + 12; i++)
        scanf("%d", &received[i]);

    for(i = 0; i < n; i++) {
        int bit = received[i] ^ crc[0];
        for(j = 0; j < 11; j++)
            crc[j] = crc[j+1] ^ (bit & generator[j+1]);
        crc[11] = bit & generator[12];
    }

    for(i = 0; i < 12; i++) {
        if(crc[i] != 0)
            error = 1;
    }

    if(error)
        printf("Error detected in received data!\n");
    else
        printf("No error detected. Data received correctly.\n");

    return 0;
}
