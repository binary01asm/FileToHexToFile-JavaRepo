#include <stdio.h>
#include <stdlib.h>

int main() {
    char inputFilePath[256];
    char outputFilePath[256];
    FILE *inputFile, *outputFile;
    unsigned char buffer;
    int bytesRead;

    // Get the input file path from the user
    printf("Enter the input file path: ");
    scanf("%s", inputFilePath);

    // Get the output file path from the user
    printf("Enter the output file path: ");
    scanf("%s", outputFilePath);

    // Open the input file in binary mode
    inputFile = fopen(inputFilePath, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file in write mode
    outputFile = fopen(outputFilePath, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Read the input file byte by byte and write the hex representation to the output file
    while ((bytesRead = fread(&buffer, 1, 1, inputFile)) > 0) {
        fprintf(outputFile, "%02X ", buffer);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File converted successfully to hexadecimal and saved to %s\n", outputFilePath);

    return EXIT_SUCCESS;
}