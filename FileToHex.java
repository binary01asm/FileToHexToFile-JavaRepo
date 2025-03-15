import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class FileToHexConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get the input file path from the user
        System.out.print("Enter the input file path: ");
        String inputFilePath = scanner.nextLine();

        // Get the output file path from the user
        System.out.print("Enter the output file path: ");
        String outputFilePath = scanner.nextLine();

        FileInputStream inputFile = null;
        FileOutputStream outputFile = null;

        try {
            // Open the input file in binary mode
            inputFile = new FileInputStream(inputFilePath);

            // Open the output file in write mode
            outputFile = new FileOutputStream(outputFilePath);

            // Read the input file byte by byte and write the hex representation to the output file
            int buffer;
            while ((buffer = inputFile.read()) != -1) {
                String hex = String.format("%02X ", buffer);
                outputFile.write(hex.getBytes());
            }

            System.out.println("File converted successfully to hexadecimal and saved to " + outputFilePath);

        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        } finally {
            // Close the files
            try {
                if (inputFile != null) inputFile.close();
                if (outputFile != null) outputFile.close();
            } catch (IOException e) {
                System.err.println("Error closing files: " + e.getMessage());
            }
        }

        scanner.close();
    }
}