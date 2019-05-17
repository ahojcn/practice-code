package Chapter10;

/**
 * 10.3
 */
public class MyInteger {
    private int data;

    public MyInteger(int d) {
        this.data = d;
    }

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    /**
     * 判断是否为偶数
     *
     * @return 是返回true，否则为false
     */
    public boolean isEven() {
        return isEven(this.data);
    }

    /**
     * 判断是否为奇数
     *
     * @return 是返回true，否返回false
     */
    public boolean isOdd() {
        return isOdd(this.data);
    }

    /**
     * 判断是否为素数
     *
     * @return 是返回true，否返回false
     */
    public boolean isPrime() {
        return isPrime(this.data);
    }

    public static boolean isEven(int d) {
        boolean ret = false;
        if (d % 2 == 0) {
            ret = true;
        }
        return ret;
    }

    public static boolean isOdd(int d) {
        boolean ret = false;
        if (d % 2 == 1) {
            ret = true;
        }
        return ret;
    }

    public static boolean isPrime(int d) {
        if (d == 1 || d == 2) {
            return true;
        }
        boolean ret = true;
        for (int i = 2; i <= Math.sqrt(d); i++) {
            if (d % i == 0) {
                ret = false;
                break;
            }
        }
        return ret;
    }

    public static boolean isEven(MyInteger m) {
        return m.isEven();
    }

    public static boolean isOdd(MyInteger m) {
        return m.isOdd();
    }

    public static boolean isPrime(MyInteger m) {
        return m.isPrime();
    }

    private boolean equals(int d) {
        return this.data == d;
    }

    private boolean equals(MyInteger m) {
        return this.data == m.data;
    }

    public static int parseInt(char[] c) {
        int ret = 0;
        for (char c1 : c) {
            ret *= 10;
            ret += c1 - '0';
        }
        return ret;
    }

    public static int parseInt(String s) {
        return parseInt(s.toCharArray());
    }
}

class Test {
    public static void main(String[] args) {
        MyInteger m = new MyInteger(7);
        System.out.println(m.isEven());
        System.out.println(m.isOdd());
        System.out.println(m.isPrime());
        System.out.println("------");
        System.out.println(MyInteger.isPrime(4));
        System.out.println("------");
        System.out.println(m.equals(8));
        System.out.println("------");
        System.out.println(MyInteger.parseInt("123"));
    }
}
