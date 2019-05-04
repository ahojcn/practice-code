package Chapter7;

import java.util.Scanner;

public class FindTheSmallestElement {
    public static double min(double[] array) {
        double min = array[0];
        for(double i : array) {
            if (i < min) {
                min = i;
            }
        }
        return min;
    }

    public static void main(String[] args) {
        int n = 10;
        double[] array = new double[n];
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter ten numbers: ");
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextDouble();
        }
        System.out.printf("The minimum number is: %f\n", min(array));
    }
}
