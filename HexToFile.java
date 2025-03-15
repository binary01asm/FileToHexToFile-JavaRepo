import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

public class HexToFileConverter {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input hex file path
        System.out.print("Enter the hex file path: ");
        String hexFilePath = scanner.nextLine();

        // Input output file path
        System.out.print("Enter the output file path: ");
        String outputFilePath = scanner.nextLine();

        FileInputStream hexFile = null;
        FileOutputStream outputFile = null;

        try {
            // Open the hex file for reading
            hexFile = new FileInputStream(new File(hexFilePath));

            // Open the output file for writing
            outputFile = new FileOutputStream(new File(outputFilePath));

            // Read hex file and convert to binary
            int byteRead;
            while ((byteRead = hexFile.read()) != -1) {
                // Convert the byte to a hexadecimal string
                String hexByte = String.format("%02x", byteRead & 0xFF);
                // Parse the hexadecimal string to an integer
                int byteValue = Integer.parseInt(hexByte, 16);
                // Write the byte to the output file
                outputFile.write(byteValue);
            }

            System.out.println("File decoded successfully.");
        } catch (IOException e) {
            System.err.println("Error: " + e.getMessage());
        } finally {
            // Close files
            try {
                if (hexFile != null) hexFile.close();
                if (outputFile != null) outputFile.close();
            } catch (IOException e) {
                System.err.println("Error closing files: " + e.getMessage());
            }
        }
    }
}