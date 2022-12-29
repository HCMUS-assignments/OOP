// Đồ án học tập: 
// Lớp số phức: ComplexNumber
// Bài toán: xây dựng lớp số phức có thể thực hiện các phép toán số học thông qua toán tử: + - * / == !=

#include <iostream>
using namespace std;

class ComplexNumber {
    private:
        double r;   // real part
        double i;   // imaginary part
    public:
        // constructor
        ComplexNumber(double r = 0, double i = 0) ;
        ComplexNumber(const ComplexNumber &c) ;
        
        // destructor
        ~ComplexNumber() {};

        // methods

        void setReal(double r);

        void setImaginary(double i);

        double getReal() const;

        double getImaginary() const;

        double getModun() const;

        // operator overloading
        ComplexNumber operator + (const ComplexNumber c) const;

        ComplexNumber operator += (ComplexNumber c);

        ComplexNumber operator - (const ComplexNumber c) const;
        
        ComplexNumber operator -= (ComplexNumber c);

        ComplexNumber operator * (const ComplexNumber c) const;

        ComplexNumber operator *= (ComplexNumber c);

        ComplexNumber operator / (const ComplexNumber c) const;

        ComplexNumber operator /= (ComplexNumber c);

        bool operator == (const ComplexNumber c) const;

        bool operator != (const ComplexNumber c) const;

        // friend function
        friend ostream &operator << (ostream &out, const ComplexNumber &c); 

        friend istream &operator >> (istream &in, ComplexNumber &c);

};
