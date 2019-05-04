package Chapter6;

/*
 * 6.10
 */
public class UseTheIsPrimeMethod {
    public static boolean isPrime(int num) {
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        for (int i = 1; i < 10000; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
    }
}
