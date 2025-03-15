#include <stdio.h>
#include <stdlib.h>

int main() {

    char hexFilePath[256];
    char outputFilePath[256];
    FILE *hexFile, *outputFile;
    int bytesRead;
    unsigned char byte;

    // Input hex file path
    printf("Enter the hex file path: ");
    scanf("%s", hexFilePath);

    // Input output file path
    printf("Enter the output file path: ");
    scanf("%s", outputFilePath);

    // Open the hex file for reading
    hexFile = fopen(hexFilePath, "r");
    if (hexFile == NULL) {
        perror("Error opening hex file");
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    outputFile = fopen(outputFilePath, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(hexFile);
        return EXIT_FAILURE;
    }

    // Read hex file and convert to binary
    while (fscanf(hexFile, "%02x", &byte) == 1) {
        fwrite(&byte, sizeof(byte), 1, outputFile);
    }

    // Close files
    fclose(hexFile);
    fclose(outputFile);

    printf("File decoded successfully.\n");

    return EXIT_SUCCESS;
}