#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::string inputFilePath, outputFilePath;
    std::ifstream inputFile;
    std::ofstream outputFile;
    unsigned int hexValue;

    // Prompt user for input file path
    std::cout << "Enter the input hex file path: ";
    std::cin >> inputFilePath;

    // Prompt user for output file path
    std::cout << "Enter the output file path: ";
    std::cin >> outputFilePath;

    // Open the input hex file for reading
    inputFile.open(inputFilePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << inputFilePath << std::endl;
        return EXIT_FAILURE;
    }

    // Open the output file for writing in binary mode
    outputFile.open(outputFilePath, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << outputFilePath << std::endl;
        inputFile.close();
        return EXIT_FAILURE;
    }

    // Read hex values from the input file and write binary data to the output file
    while (inputFile >> std::hex >> hexValue) {
        outputFile.put(static_cast<unsigned char>(hexValue));
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "File decoded successfully." << std::endl;

    return EXIT_SUCCESS;
}