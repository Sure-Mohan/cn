#include <stdio.h>
#include <stdlib.h>

int main() {
    int bucketSize, outputRate, n, incoming;
    int stored = 0;

    printf("=== Leaky Bucket Algorithm Simulation ===\n");
    printf("Enter bucket capacity (in packets): ");
    scanf("%d", &bucketSize);

    printf("Enter output rate (packets per second): ");
    scanf("%d", &outputRate);

    printf("Enter number of incoming packets (time slots): ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("\nTime %d: Enter number of incoming packets: ", i);
        scanf("%d", &incoming);
        printf("Incoming packets: %d\n", incoming);

        stored += incoming;

        if (stored > bucketSize) {
            int dropped = stored - bucketSize;
            stored = bucketSize;
            printf("Bucket overflow! Dropped packets: %d\n", dropped);
        }

        int transmitted;
        if (stored >= outputRate) {
            transmitted = outputRate;
            stored -= outputRate;
        } else {
            transmitted = stored;
            stored = 0;
        }

        printf("Transmitted: %d | Packets left in bucket: %d\n", transmitted, stored);
    }

    while (stored > 0) {
        int transmitted;
        if (stored >= outputRate) {
            transmitted = outputRate;
            stored -= outputRate;
        } else {
            transmitted = stored;
            stored = 0;
        }
        printf("\nTransmitted: %d | Packets left in bucket: %d\n", transmitted, stored);
    }

    printf("\nAll packets transmitted successfully!\n");
    return 0;
}
