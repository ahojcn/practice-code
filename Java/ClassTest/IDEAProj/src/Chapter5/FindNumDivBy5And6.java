package Chapter5;

public class FindNumDivBy5And6 {
    public static void main(String[] args) {
        for (int i = 100; i <= 200; i++) {
            if ((i % 5 == 0 || i % 6 == 0) && (i % 30 != 0)) {
                System.out.println(i);
            }
        }
    }
}
