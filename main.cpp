#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

class det
{
public:
    int a, b, c;
    int d, e, f;
    int g, h, i;

    int result;

public:
    void get2x2();

    void get3x3();

    void calc2x2();
    void calc3x3();

    void display2x2();
    void display3x3();
};

void det ::get3x3()
{
    cout << "Enter Your 3 x 3 Determinant" << endl;
    cout << "1,1 = ";
    cin >> a;
    cout << "\n1,2 = ";
    cin >> b;
    cout << "\n1,3 = ";
    cin >> c;

    cout << "\n2,1 = ";
    cin >> d;
    cout << "\n2,2 = ";
    cin >> e;
    cout << "\n2,3 = ";
    cin >> f;

    cout << "\n3,1 = ";
    cin >> g;
    cout << "\n3,2 = ";
    cin >> h;
    cout << "\n3,3 = ";
    cin >> i;
}

void det ::get2x2()
{
    cout << "Enter Your 2 x 2 Determinant" << endl;
    cout << "\n1,1 = ";
    cin >> a;
    cout << "\n1,2 = ";
    cin >> b;
    cout << "\n2,1 = ";
    cin >> d;
    cout << "\n2,2 = ";
    cin >> e;
}

void det ::calc2x2()
{
    result = ((a * e) - (b * d));
}

void det ::calc3x3()
{

    int re1, re2, re3;

    re1 = a * ((e * i) - (h * f));
    re2 = b * ((d * i) - (g * f));
    re3 = c * ((d * h) - (e * g));

    result = re1 - re2 + re3;
}

void det ::display2x2()
{
    cout << " | " << setw(2) << a << setw(2) << b << " | " << endl;
    cout << " | " << setw(2) << d << setw(2) << e << " | " << endl;
}

void det ::display3x3()
{
    cout << " | " << setw(2) << a << setw(2) << b << setw(2) << c << " | " << endl;
    cout << " | " << setw(2) << d << setw(2) << e << setw(2) << f << " | " << endl;
    cout << " | " << setw(2) << g << setw(2) << h << setw(2) << i << " | " << endl;
}

int main()
{
    system("cls");
    cout << "------------------- Determinant Calculator ------------------- ";
    int usr;
    cout << "\nEnter '2' for 2x2 Determinant " << setw(2) << "else '3' for 3x3 determinant = ";
    cin >> usr;

    det obj;
    if (usr == 2)
    {
        obj.get2x2();
        obj.calc2x2();

        cout << "Your Determinant is :- " << endl;
        obj.display2x2();

        cout << "\nResult of your Determinant Is = " << obj.result;
    }
    if (usr == 3)
    {
        obj.get3x3();
        obj.calc3x3();

        cout << "Your Determinant is :- " << endl;
        obj.display3x3();

        cout << "\nResult of your Determinant Is = " << obj.result;
    }
    if (usr != 2 && usr != 3)
    {
        cout << "\nNot a Proper Input";
    }

    if (obj.result == 0)
    {
        cout << "\nThe Matrix formed by this Determinant is a Singular Matrix and can't be inversed";
    }

    if (obj.result != 0)
    {
        cout << "\nThe Matrix formed by this determinant is a non-Singular Matrix and can be inversed";
    }
    return 0;
}