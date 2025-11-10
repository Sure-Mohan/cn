#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sender(int totalFrames);
void receiver(int frame);

int main() {
    int totalFrames;

    printf("=== Stop-and-Wait Protocol Simulation ===\n");
    printf("Enter total number of frames to send: ");
    scanf("%d", &totalFrames);

    sender(totalFrames);

    return 0;
}

void sender(int totalFrames) {
    int i = 1, choice;

    srand(time(NULL));

    while (i <= totalFrames) {
        printf("\nSender: Sending Frame %d", i);

        printf("\nReceiver: Do you want to ACK Frame %d? (1-Yes, 0-No): ", i);
        scanf("%d", &choice);

        if (choice == 1) {
            receiver(i);
            printf("Sender: ACK %d received\n", i);
            i++;
        } else {
            printf("Sender: ACK %d lost. Retransmitting...\n", i);
        }
    }

    printf("\nAll %d frames sent successfully!\n", totalFrames);
}

void receiver(int frame) {
    printf("Receiver: Frame %d received. Sending ACK %d...\n", frame, frame);
}
