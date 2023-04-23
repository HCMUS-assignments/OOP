#include "header.h"


// ----------------------------------------
// define methods here

// 1. Viết các hàm dựng và hàm hủy và hàm sao chép các lớp Shape, Circle, Rectangle, ComplexShape

// 2. Viết các hàm thành phần khác đã cho trong thiết kế lớp, IsSelected() và Clone() của các lớp con Circle, Rectangle

// 3. Cài đặt phương thức IsSelected và CLone cho lớp ComplexShape

// 4. Viết hàm nhập xuất cho lớp ComplexShape để nhập danh sách các hình tròn và hình chữ nhật

// 5. Viết hàm tính số lượng các hình tròn, hình chữ nhật có trong mảng các hình đã nhập 

// 6. Viết hàm tính tổng diện tích các hình trong danh sách các hình đã nhập 'Children

// ---------------------------------------

// 1. constructors, destructors and copy constructors
Shape::Shape() {
    cout << "\nConstructor of shape called ! \n";
}

Shape::~Shape() {
    cout << "\nDestructor of shape called ! \n";
}

Shape::Shape(const Shape &other) {
    cout << "\nCopy constructor of shape called !\n";
}


Circle::Circle() {
    cout << "\nConstructor of circle called ! \n";
    R = 0;
}

Circle::Circle(Point p, double r) {
    cout << "\nConstructor with params of circle called ! \n";
    C.X = p.X;
    C.Y = p.Y;
    R = r;
}

Circle::~Circle() {
    cout << "\nDestructor of circle called ! \n";
}

Circle::Circle(const Circle &other) {
    cout << "\nCopy constructor of circle called ! \n";
    C.X = other.C.X;
    C.Y = other.C.Y;
    R = other.R;
}


Rectangle::Rectangle() {
    cout << "\nConstructor of rectangle called !\n";
    W = 0;
    H = 0;
}

Rectangle::Rectangle(Point p, double w, double h) {
    cout << "\nConstructor with params of rectangle called!\n";
    X.X = p.X;
    X.Y = p.Y;
    W = w;
    H = h;
}

Rectangle::~Rectangle() {
    cout << "\nDestructor of rectangle called!\n";
}

Rectangle::Rectangle(const Rectangle &other) {
    cout << "\nCopy constructor of rectangle called !\n";
    X.X = other.X.X;
    X.Y = other.X.Y;
    W = other.W;
    H = other.H;
}

ComplexShape::ComplexShape() {
    cout << "Constructor of complexShape called !\n";
    sz = 0;
    Children = NULL;
}

ComplexShape::~ComplexShape() {
    cout << "\nDestructor of complex shape called !\n";
    if (sz > 0) {
        for (int i = 0; i < sz; i++) {
            delete Children[i];
        }
        delete[] Children;
    }
    Children = NULL;
}

ComplexShape::ComplexShape(const ComplexShape &other) {
    cout << "Copy constructor of complex shape called !\n";
    sz = other.sz;
    Children = new Shape* [sz];
    for (int i = 0; i < sz; i++) {
        Children[i] = other.Children[i]->Clone();
    }
}


// 2. IsSelected, Clone cho Circle and Rectangle
bool Circle::IsSelected(Point p) {
    return pow(p.X - C.X, 2) + pow(p.Y - C.Y, 2) <= R*R;
}

Shape* Circle::Clone() {
    Circle *c = new Circle();
    c->C.X = C.X;
    c->C.Y = C.Y;
    c->R = R;
    return c;
}

bool Rectangle::IsSelected(Point p) {
    if (p.X >= X.X  && p.X <= X.X + W && p.Y >= X.Y - H && p.Y <= X.Y) {
        return true;
    }
    return false;
}

Shape* Rectangle::Clone() {
    Rectangle *r = new Rectangle();
    r->X.X = X.X;
    r->X.Y = X.Y;
    r->W = W;
    r->H = H;
    return r;
}

// 3. Cài đặt phương thức IsSelected và CLone cho lớp ComplexShape
bool ComplexShape::IsSelected(Point p) {
    for (int i = 0; i < sz; i++) {
        if ( ! Children[i]->IsSelected(p)) {
            return false;
        }
    }
    return true;
}

Shape* ComplexShape::Clone() {
    ComplexShape* temp ;
    temp->sz = sz;
    temp->Children = new Shape*[sz];
    for (int i = 0; i < sz; i++) {
        temp->Children[i] = Children[i]->Clone();
    }
    return temp;
}

// 4. Viết hàm nhập xuất cho lớp ComplexShape để nhập danh sách các hình tròn và hình chữ nhật
void Circle::input() {
    cout << "Nhap thong tin hinh tron...\n";
    cout << "Nhap toa do tam (x y): ";
    fflush(stdin);
    cin >> C.X >> C.Y;
    cout << "Nhap ban kinh R: ";
    fflush(stdin);
    cin >> R;

}
void Circle::print(){
    cout << "Thong tin hinh tron: I(" << C.X << ", " << C.Y << "), R = " << R << endl; 

}

void Rectangle::input() {
    cout << "Nhap thong tin hinh chu nhat..." << endl;
    cout << "Nhap toa do diem trai tren (x y): ";
    fflush(stdin);
    cin >> X.X >> X.Y;
    cout << "Nhap chieu dai va chieu rong: ";
    fflush(stdin);
    cin >> W >> H;
}

void Rectangle::print() {
    cout << "Thong tin hinh chu nhat: TL(" << X.X << ", " << X.Y << "), W = " << W << ", H = " << H << endl;
}

void ComplexShape::input() {
    cout << "Nhap so hinh : ";
    fflush(stdin);
    cin >> sz;
    Children = new Shape*[sz];
    for (int i = 0; i < sz; i++) {
        cout << "Hinh chu nhat(1) hay hinh tron(2) ? ";
        fflush(stdin);
        int choice;
        cin >> choice;
        if (choice == 1) {
            Rectangle *temp = new Rectangle();
            temp->input();
            Children[i] = temp->Clone();
        } else {
            Circle *temp = new Circle();
            temp->input();
            Children[i] = temp->Clone();
        }
    }

}

void ComplexShape::print( ) {
    cout << "Thong tin complex shapes : " << endl;
    for (int i = 0; i < sz; i++) {
        Children[i]->print();
    }

}

// 5. Viết hàm tính số lượng các hình tròn, hình chữ nhật có trong mảng các hình đã nhập 
string Circle::getName() {
    return "Circle";
}

string Rectangle::getName() {
    return "Rectangle";
}

string ComplexShape::getName() {
    return "ComplexShape";
}

int ComplexShape::circle_Num() {
    int count = 0;
    for (int i = 0; i < sz; i++) {
        if (Children[i]->getName() == "Circle") {
            count ++;
        }
    }
    return count;

}
int ComplexShape::rectangle_Num() {
    return sz - circle_Num();
}

// 6. Viết hàm tính tổng diện tích các hình trong danh sách các hình đã nhập 'Children
double Circle::area() {
    return R*R*PI;
}

double Rectangle::area() {
    return W*H;
}

double ComplexShape::area() {
    double sum = 0;
    for (int i = 0; i < sz; i++) {
        sum += Children[i]->area();
    }
    return sum;
}