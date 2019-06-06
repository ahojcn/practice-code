package Chapter11;

abstract class A {
    abstract void fun();
}

public class Test extends A {

    public static void main(String[] args) {
        System.out.println("aaa");

        Test t = new Test();

        t.fun();
    }

    @Override
    void fun() {
        System.out.println("func");
    }
}
