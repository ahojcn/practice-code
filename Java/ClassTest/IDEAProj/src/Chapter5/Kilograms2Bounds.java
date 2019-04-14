/**
 * 5.5
 * 千克和磅的互相转换
 * 1千克(kg) = 2.2046226磅(lb)
 */
package Chapter5;

import java.util.Scanner;

public class Kilograms2Bounds {
    public static float m = 2.2046226f;
    public static void main(String[] args) {
        System.out.printf("Kilograms\tPounds\t|\tPounds\tKilograms\n");
        int k = 1;
        int p = 20;
        while (true) {
            if (k == 199 && p == 515) {
                break;
            } else {
                System.out.printf("%d\t\t\t%5.1f\t|\t%d\t\t\t%5.2f\n", k,k*m,p,p/m);
                k+=2;
                p+=5;
            }
        }
    }
}
