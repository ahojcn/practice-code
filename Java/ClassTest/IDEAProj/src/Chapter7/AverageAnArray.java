package Chapter7;
/*
 * 7.8
 */

import java.util.Scanner;

public class AverageAnArray {
    public static int average(int[] array) {
        int sum = 0;
        for (int i : array) {
            sum += i;
        }
        return sum / array.length;
    }

    public static double average(double[] array) {
        double sum = 0;
        for (double d : array) {
            sum += d;
        }
        return sum / array.length;
    }

    public static void main(String[] args) {
        int n = 3;
        Scanner sc = new Scanner(System.in);

        System.out.print("int arr[3] : ");
        int[] i_arr = new int[n];
        for (int i = 0; i < n; i++) {
            i_arr[i] = sc.nextInt();
        }
        System.out.printf("average int arr : %d\n", average(i_arr));

        System.out.print("double arr[3] : ");
        double[] d_arr = new double[n];
        for (int i = 0; i < n; i++) {
            d_arr[i] = sc.nextDouble();
        }
        System.out.printf("average double arr : %f\n", average(d_arr));
    }
}
