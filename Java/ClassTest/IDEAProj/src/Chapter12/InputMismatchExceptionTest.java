package Chapter12;

import java.util.InputMismatchException;
import java.util.Scanner;

// 12.2 input miss match exception
public class InputMismatchExceptionTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input 2 number : ");
        while (true) {
            try {
                int a = sc.nextInt();
                int b = sc.nextInt();
                System.out.println("sum = " + (a + b));
                break;
            } catch (InputMismatchException e) {
                sc.nextLine();
                System.out.println("input miss match exception.");
            }
        }
        sc.close();
    }
}
