#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// đơn thức, đa thức
#ifndef MONOMIAL_H
#define MONOMIAL_H

class Monomial
{
private:
    // M(x) = a*x^n
    float a; // hệ số
    int n;   // bậc (degree)

public:
    // constructors
    Monomial();
    Monomial(float a, int n);

    // destructor
    ~Monomial();

    // setters
    void setA(float a);
    void setN(int n);

    // getters
    float getA();
    int getN();

    // nhập đơn thức
    friend istream &operator>>(istream &is, Monomial &m);

    // xuất đơn thức
    friend ostream &operator<<(ostream &os, Monomial m);

    // tính giá trị đơn thức
    float getValueAt(float x);

    // cộng, trừ, nhân, chia đơn thức
    Monomial operator+(Monomial m);
    Monomial operator-(Monomial m);
    Monomial operator*(Monomial m);
    Monomial operator/(Monomial m);
};

#endif

// define

// constructors
Monomial::Monomial()
{
    a = 0;
    n = 0;
}

Monomial::Monomial(float a, int n)
{
    this->a = a;
    this->n = n;
}

// destructor
Monomial::~Monomial()
{
    a = 0;
    n = 0;
}

istream &operator>>(istream &is, Monomial &m)
{
    cout << "Nhap don thuc dang: ax^n : ";
    string line;
    fflush(stdin);
    getline(is, line);
    // cout << "line: " << line << endl;
    int pos = line.find("x^");
    if (pos != string::npos)
    {
        m.a = stof(line.substr(0, pos));
        m.n = stoi(line.substr(pos + 2));
    }
    else
    {
        pos = line.find("x");
        if (pos != string::npos)
        {
            m.a = stof(line.substr(0, pos));
            m.n = 1;
        }
        else
        {
            m.a = stof(line);
            m.n = 0;
        }
    }
    return is;
}

// setters
void Monomial::setA(float a)
{
    this->a = a;
}

void Monomial::setN(int n)
{
    this->n = n;
}

// getters
float Monomial::getA()
{
    return a;
}

int Monomial::getN()
{
    return n;
}

ostream &operator<<(ostream &os, Monomial m)
{
    if (m.n == 0)
    {
        os << m.a;
        return os;
    }
    if (m.n == 1)
    {
        os << m.a << "x";
        return os;
    }
    os << m.a << "x^" << m.n;
    return os;
}

// tính giá trị đơn thức
float Monomial::getValueAt(float x)
{
    return a * pow(x, n);
}

// cộng, trừ, nhân, chia đơn thức
Monomial Monomial::operator+(Monomial m)
{
    Monomial result;
    if (n == m.n)
    {
        result.a = a + m.a;
        result.n = n;
    }
    else
    {
        cout << "\nKhong the cong hai don thuc khong cung bac" << endl;
    }
    return result;
}
Monomial Monomial::operator-(Monomial m)
{
    Monomial result;
    if (n == m.n)
    {
        result.a = a - m.a;
        result.n = n;
    }
    else
    {
        cout << "\nKhong the tru hai don thuc khong cung bac" << endl;
    }
    return result;
}
Monomial Monomial::operator*(Monomial m)
{
    Monomial result;
    result.a = a * m.a;
    result.n = n + m.n;
    return result;
}
Monomial Monomial::operator/(Monomial m)
{
    Monomial result;
    if (m.a != 0)
    {
        result.a = a / m.a;
        result.n = n - m.n;
    }
    else
    {
        cout << "\nKhong the chia cho 0" << endl;
    }
    return result;
}

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
private:
    Monomial *list_of_monomial;
    int size;

public:
    // constructors
    Polynomial();

    // destructor
    ~Polynomial();

    // copy constructor
    Polynomial(const Polynomial &src);

    // Nhập đa thức
    friend istream &operator>>(istream &is, Polynomial &src);

    // xuất đa thức
    friend ostream &operator<<(ostream &os, Polynomial src);

    // tính giá trị đa thức
    float getValueAt(float x);

    // cộng, trừ, nhân, chia đa thức
    Polynomial operator+(Polynomial src);
    Polynomial operator-(Polynomial src);
    Polynomial operator*(Polynomial src);
    Polynomial operator/(Polynomial src);

    // overload toán tử gán
    Polynomial &operator=(const Polynomial &src);
};

#endif

// define
// constructors
Polynomial::Polynomial()
{
    list_of_monomial = NULL;
    size = 0;
}

// destructor
Polynomial::~Polynomial()
{
    delete[] list_of_monomial;
    size = 0;
}

// Nhập đa thức
istream &operator>>(istream &is, Polynomial &src)
{
    cout << "\nNhap so luong don thuc: ";
    is >> src.size;
    src.list_of_monomial = new Monomial[src.size * sizeof(Monomial)];
    for (int i = 0; i < src.size; i++)
    {
        cout << "\nNhap don thuc thu " << i + 1 << endl;
        is >> src.list_of_monomial[i];
    }

    return is;
}

// xuất đa thức
ostream &operator<<(ostream &os, Polynomial src)
{
    // cout << "\n*** Da thuc: ";
    for (int i = 0; i < src.size; i++)
    {
        if (src.list_of_monomial[i].getA() == 0)
        {
            continue;
        }
        if (src.list_of_monomial[i].getA() < 0)
        {
            os << " - " ;
            if (src.list_of_monomial[i].getN() == 0)
            {
                os << -src.list_of_monomial[i].getA();
            }
            else if (src.list_of_monomial[i].getN() == 1)
            {
                os << -src.list_of_monomial[i].getA() << "x";
            } else 
                os << -src.list_of_monomial[i].getA() << "x^" << src.list_of_monomial[i].getN();
        }
        else
        {
            os << src.list_of_monomial[i];
        }
        if (i < src.size - 1 && src.list_of_monomial[i + 1].getA() < 0)
        {
            continue;
        }
        else if (i < src.size - 1 && src.list_of_monomial[i + 1].getA() > 0)
        {
            os << " + ";
        }
    }
    return os;
}

// copy constructors
Polynomial::Polynomial(const Polynomial &src)
{
    size = src.size;
    list_of_monomial = new Monomial[size];
    for (int i = 0; i < size; i++)
    {
        list_of_monomial[i] = src.list_of_monomial[i];
    }
}

// tính giá trị đa thức
float Polynomial::getValueAt(float x)
{
    float result = 0;
    for (int i = 0; i < size; i++)
    {
        result += list_of_monomial[i].getValueAt(x);
    }
    return result;
}

Polynomial &Polynomial::operator=(const Polynomial &src)
{
    if (this == &src)
    {
        return *this;
    }
    if (list_of_monomial != NULL)
    {
        delete[] list_of_monomial;
    }
    size = src.size;
    list_of_monomial = new Monomial[size];
    for (int i = 0; i < size; i++)
    {
        list_of_monomial[i] = src.list_of_monomial[i];
    }
    return *this;
}

// cộng, trừ, nhân, chia đa thức
Polynomial Polynomial::operator+(Polynomial src)
{
    // get max degree
    int max_degree = 0;

    for (int i = 0; i < size; i++)
    {
        // cout << "\nDegree  " << i << ": " << list_of_monomial[i].getN() << endl;
        if (list_of_monomial[i].getN() > max_degree)
        {
            max_degree = list_of_monomial[i].getN();
        }
    }
    for (int i = 0; i < src.size; i++)
    {
        if (src.list_of_monomial[i].getN() > max_degree)
        {
            max_degree = src.list_of_monomial[i].getN();
        }
    }
    // cout << "\nMax degree: " << max_degree << endl;

    // create result polynomial
    Polynomial result;
    result.size = max_degree + 1;
    result.list_of_monomial = new Monomial[result.size * sizeof(Monomial)];

    // init result polynomial
    for (int i = 0; i < max_degree + 1; i++)
    {
        result.list_of_monomial[i].setA(0);
        result.list_of_monomial[i].setN(i);
    }

    // add the first polynomial
    for (int i = 0; i < size; i++)
    {
        int degree = list_of_monomial[i].getN();
        int coef = list_of_monomial[i].getA();
        result.list_of_monomial[degree].setA(coef);
    }

    // add the second polynomial
    for (int i = 0; i < src.size; i++)
    {
        int degree = src.list_of_monomial[i].getN();
        int coef = src.list_of_monomial[i].getA() + result.list_of_monomial[degree].getA();
        result.list_of_monomial[degree].setA(coef);
    }
    // cout << "\n*** Ket qua: " << result;
    return result;
}
Polynomial Polynomial::operator-(Polynomial src)
{
    // get max degree
    int max_degree = 0;
    for (int i = 0; i < size; i++)
    {
        if (list_of_monomial[i].getN() > max_degree)
        {
            max_degree = list_of_monomial[i].getN();
        }
    }
    for (int i = 0; i < src.size; i++)
    {
        if (src.list_of_monomial[i].getN() > max_degree)
        {
            max_degree = src.list_of_monomial[i].getN();
        }
    }

    // create result polynomial
    Polynomial result;
    result.size = max_degree + 1;
    result.list_of_monomial = new Monomial[result.size * sizeof(Monomial)];

    // init result polynomial
    for (int i = 0; i < max_degree + 1; i++)
    {
        result.list_of_monomial[i].setA(0);
        result.list_of_monomial[i].setN(i);
    }

    // add the first polynomial
    for (int i = 0; i < size; i++)
    {
        int degree = list_of_monomial[i].getN();
        int coef = list_of_monomial[i].getA();
        result.list_of_monomial[degree].setA(coef);
    }

    // sub for the second polynomial
    for (int i = 0; i < src.size; i++)
    {
        int degree = src.list_of_monomial[i].getN();
        int coef = result.list_of_monomial[degree].getA() - src.list_of_monomial[i].getA();
        result.list_of_monomial[degree].setA(coef);
    }
    return result;
}
Polynomial Polynomial::operator*(Polynomial src)
{
    // get max degree
    int first_max_degree = 0;
    for (int i = 0; i < size; i++)
    {
        if (list_of_monomial[i].getN() > first_max_degree)
        {
            first_max_degree = list_of_monomial[i].getN();
        }
    }
    int second_max_degree = 0;
    for (int i = 0; i < src.size; i++)
    {
        if (src.list_of_monomial[i].getN() > second_max_degree)
        {
            second_max_degree = src.list_of_monomial[i].getN();
        }
    }
    int max_degree = first_max_degree + second_max_degree;

    // create result polynomial
    Polynomial result;
    result.size = max_degree + 1;
    result.list_of_monomial = new Monomial[result.size * sizeof(Monomial)];

    // init result polynomial
    for (int i = 0; i < max_degree + 1; i++)
    {
        result.list_of_monomial[i].setA(0);
        result.list_of_monomial[i].setN(i);
    }

    // multiply
    for (int i = 0; i < size; i++)
    {
        int coef1 = list_of_monomial[i].getA();
        int degree1 = list_of_monomial[i].getN();
        for (int j = 0; j < src.size; j++)
        {
            int coef2 = src.list_of_monomial[j].getA();
            int degree2 = src.list_of_monomial[j].getN();
            int coef = coef1 * coef2;
            int degree = degree1 + degree2;
            result.list_of_monomial[degree].setA(coef);
        }
    }

    return result;
}
Polynomial Polynomial::operator/(Polynomial src)
{
}

int main()
{
    // test Monomial
    Monomial m1(2, 3);
    Monomial m2(3, 2);
    Monomial m3(4, 1);

    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;

    cout << m1 + m2 << endl;
    cout << m1 - m2 << endl;
    cout << m1 * m2 << endl;
    cout << m1 / m2 << endl;

    // test Polynomial
    Polynomial p1;
    cin >> p1;
    cout << p1 << endl;

    fflush(stdin);
    Polynomial p2;
    cin >> p2;
    cout << p2 << endl;
    Polynomial p3;
    p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;
    p3 = p1 - p2;
    cout << "p1 - p2 = " << p3 << endl;
    p3 = p1 * p2;
    cout << "p1 * p2 = " << p3 << endl;

    return 225;
}