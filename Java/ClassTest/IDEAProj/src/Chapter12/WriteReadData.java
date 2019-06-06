package Chapter12;

import java.io.*;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class WriteReadData {
    public static void main(String[] args) throws IOException {
        File file = new File("Exercise12_15.txt");
        PrintWriter output = new PrintWriter(file);
        if (!file.exists()) {
            output = new PrintWriter(file);
        }
        Random random = new Random(7);
        for (int i = 0; i < 100; i++) {
            output.print(random.nextInt(100) + " ");
        }

        output.close();

        Scanner input = new Scanner(file);
        int[] numbers = new int[100];
        int index = 0;
        while (input.hasNext()) {
            numbers[index++] = input.nextInt();
            input.skip(" ");
        }
        input.close();

        Arrays.sort(numbers);

        for (int number : numbers) {
            System.out.println(number);
        }
    }
}