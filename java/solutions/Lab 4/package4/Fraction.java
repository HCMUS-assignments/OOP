package package4;

public class Fraction {
    private int numerator;
    private int denominator;

    public Fraction() {
        this.numerator = 0;
        this.denominator = 1;
    }

    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    public Fraction(Fraction f) {
        this.numerator = f.numerator;
        this.denominator = f.denominator;
    }

    public Fraction add(Fraction f) {
        int newNumerator = this.numerator * f.denominator + this.denominator * f.numerator;
        int newDenominator = this.denominator * f.denominator;
        return new Fraction(newNumerator, newDenominator);
    }

    public Fraction sub(Fraction f) {
        int newNumerator = this.numerator * f.denominator - this.denominator * f.numerator;
        int newDenominator = this.denominator * f.denominator;
        return new Fraction(newNumerator, newDenominator);
    }

    public Fraction mul(Fraction f) {
        int newNumerator = this.numerator * f.numerator;
        int newDenominator = this.denominator * f.denominator;
        return new Fraction(newNumerator, newDenominator);
    }

    public Fraction div(Fraction f) {
        int newNumerator = this.numerator * f.denominator;
        int newDenominator = this.denominator * f.numerator;
        return new Fraction(newNumerator, newDenominator);
    }

    public int gcd(int a, int b) {
        // tìm ước chung lớn nhất của a và b
        while (a != b) {
            if (a > b) {
                a = a - b;
            } else {
                b = b - a;
            }
        }
        return a;
    }

    public void reduce() {
        if (this.numerator != 0) {
            int gcd = gcd(this.numerator, this.denominator);
            this.numerator /= gcd;
            this.denominator /= gcd;
        }
    }

    public String toString() {
        return "Fraction [ " + this.numerator + " / " + this.denominator + " ]";
    }
}
