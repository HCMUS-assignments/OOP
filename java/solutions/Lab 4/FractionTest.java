import package4.Fraction;

public class FractionTest {
    public static void main(String[] args) {
        Fraction f1 = new Fraction();
        Fraction f2 = new Fraction(17, 19);
        Fraction f3 = new Fraction(12, 24);
        Fraction f4 = new Fraction(f2);
        Fraction f5 = new Fraction(1, 2);

        System.out.println("f1 = " + f1);
        System.out.println("f2 = " + f2);
        System.out.println("f3 = " + f3);
        System.out.println("f4 = " + f4);
        System.out.println("f5 = " + f5);

        System.out.println("f1 + f2 = " + f1.add(f2));
        System.out.println("f2 - f3 = " + f2.sub(f3));
        System.out.println("f3 * f4 = " + f3.mul(f4));
        System.out.println("f4 / f5 = " + f4.div(f5));

        f1.reduce();
        f2.reduce();
        f3.reduce();
        f4.reduce();
        f5.reduce();

        System.out.println(f1.toString());
        System.out.println(f2.toString());
        System.out.println(f3.toString());
        System.out.println(f4.toString());
        System.out.println(f5.toString());
        
    }
}