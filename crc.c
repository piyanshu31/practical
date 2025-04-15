#include <stdio.h>

int main() {
    int data[20], divisor[10], temp[30], remainder[10];
    int data_bits, divisor_bits, i, j;

    printf("Enter number of data bits: ");
    scanf("%d", &data_bits);
    printf("Enter the data bits (0 or 1): ");
    for(i = 0; i < data_bits; i++)
        scanf("%d", &data[i]);

    printf("Enter number of divisor bits: ");
    scanf("%d", &divisor_bits);
    printf("Enter the divisor bits (0 or 1): ");
    for(i = 0; i < divisor_bits; i++)
        scanf("%d", &divisor[i]);

    // Copy data and append 0s
    for(i = 0; i < data_bits; i++)
        temp[i] = data[i];
    for(i = data_bits; i < data_bits + divisor_bits - 1; i++)
        temp[i] = 0;

    // Perform division (XOR)
    for(i = 0; i < data_bits; i++) {
        if(temp[i] == 1) {
            for(j = 0; j < divisor_bits; j++)
                temp[i + j] = temp[i + j] ^ divisor[j];
        }
    }

    // Remainder is CRC
    printf("CRC Remainder: ");
    for(i = data_bits; i < data_bits + divisor_bits - 1; i++) {
        printf("%d", temp[i]);
        remainder[i - data_bits] = temp[i];
    }

    // Append remainder to data to get transmitted data
    printf("\nTransmitted data: ");
    for(i = 0; i < data_bits; i++)
        printf("%d", data[i]);
    for(i = 0; i < divisor_bits - 1; i++)
        printf("%d", remainder[i]);

    return 0;
}
