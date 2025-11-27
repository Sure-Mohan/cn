CRC-12:
#include <stdio.h>
int main() {
    int data[100], recv[200], crc[12]={0};
    int gen[13]={1,1,0,0,0,0,0,0,0,0,0,1,1};
    int n,i,j,error=0;
    printf("Enter number of data bits: ");
    scanf("%d",&n);
    printf("Enter data bits: ");
    for(i=0;i<n;i++)
        scanf("%d",&data[i]);
    for(i=0;i<n;i++) {
        int bit = crc[0] ^ data[i];
        for(j=0;j<11;j++)
            crc[j] = crc[j+1] ^ (bit & gen[j+1]);
        crc[11] = bit & gen[12];
    }
    printf("CRC bits: ");
    for(i=0;i<12;i++)
        printf("%d",crc[i]);
    printf("\nTransmitted codeword: ");
    for(i=0;i<n;i++)
        printf("%d",data[i]);
    for(i=0;i<12;i++)
        printf("%d",crc[i]);
    printf("\nEnter received codeword: ");
    for(i=0;i<n+12;i++)
        scanf("%d",&recv[i]);
    for(i=0;i<12;i++)
        crc[i]=0;
    for(i=0;i<n+12;i++) {
        int bit = crc[0] ^ recv[i];
        for(j=0;j<11;j++)
            crc[j] = crc[j+1] ^ (bit & gen[j+1]);
        crc[11] = bit & gen[12];
    }
    for(i=0;i<12;i++)
        if(crc[i]!=0) error=1;
    if(error)
        printf("Error detected\n");
    else
        printf("No error\n");
    return 0;
}
CRC-16:
#include <stdio.h>
int main() {
    int data[100], recv[120], crc[16], poly[17] = {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1};
    int n, i, j, bit, error = 0;
    printf("Enter number of data bits: ");
    scanf("%d", &n);
    printf("Enter data bits: ");
    for(i = 0; i < n; i++) scanf("%d", &data[i]);
    for(i = 0; i < 16; i++) crc[i] = 0;
    for(i = 0; i < n; i++) {
        bit = data[i] ^ crc[0];
        for(j = 0; j < 15; j++)
            crc[j] = crc[j+1] ^ (bit & poly[j+1]);
        crc[15] = bit & poly[16];
    }
    printf("\nCRC-16: ");
    for(i = 0; i < 16; i++) printf("%d", crc[i]);
    printf("\nTransmitted codeword: ");
    for(i = 0; i < n; i++) printf("%d", data[i]);
    for(i = 0; i < 16; i++) printf("%d", crc[i]);
    printf("\n\nEnter received codeword: ");
    for(i = 0; i < n + 16; i++) scanf("%d", &recv[i]);
    for(i = 0; i < 16; i++) crc[i] = 0;
    for(i = 0; i < n + 16; i++) {
        bit = recv[i] ^ crc[0];
        for(j = 0; j < 15; j++)
            crc[j] = crc[j+1] ^ (bit & poly[j+1]);
        crc[15] = bit & poly[16];
    }
    for(i = 0; i < 16; i++)
        if(crc[i] != 0) error = 1;
    if(error)
        printf("\nError detected in received data.\n");
    else
        printf("\nNo error. Data received correctly.\n");
    return 0;
}
