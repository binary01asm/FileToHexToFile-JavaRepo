#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    std::string inputFilePath, outputFilePath;
    std::ifstream inputFile;
    std::ofstream outputFile;
    unsigned char buffer;

    // Get the input file path from the user
    std::cout << "Enter the input file path: ";
    std::cin >> inputFilePath;

    // Get the output file path from the user
    std::cout << "Enter the output file path: ";
    std::cin >> outputFilePath;

    // Open the input file in binary mode
    inputFile.open(inputFilePath, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error opening input file: " << inputFilePath << std::endl;
        return EXIT_FAILURE;
    }

    // Open the output file in write mode
    outputFile.open(outputFilePath);
    if (!outputFile) {
        std::cerr << "Error opening output file: " << outputFilePath << std::endl;
        inputFile.close();
        return EXIT_FAILURE;
    }

    // Read the input file byte by byte and write the hex representation to the output file
    while (inputFile.read(reinterpret_cast<char*>(&buffer), 1)) {
        outputFile << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buffer) << " ";
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    std::cout << "File converted successfully to hexadecimal and saved to " << outputFilePath << std::endl;

    return EXIT_SUCCESS;
}