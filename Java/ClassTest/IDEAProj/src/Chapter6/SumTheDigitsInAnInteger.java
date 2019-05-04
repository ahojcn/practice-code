package Chapter6;

import java.util.Scanner;

/*
 * 6.2
 */
public class SumTheDigitsInAnInteger {
    public static int sumDigits(long n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        System.out.println(sumDigits(n));
    }
}
