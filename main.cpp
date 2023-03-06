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

    void cofactor2x2();
    void cofactor3x3();

    void adjacent2x2();
    void adjacent3x3();

    void inverse2x2();
    void inverse3x3();
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
    cout << " | " << setw(2) << a << setw(3) << b << setw(2) << " | " << endl;
    cout << " | " << setw(2) << d << setw(3) << e << setw(2) << " | " << endl;
}

void det ::display3x3()
{
    cout << " | " << setw(3) << a << setw(4) << b << setw(4) << c << setw(3) << " | " << endl;
    cout << " | " << setw(3) << d << setw(4) << e << setw(4) << f << setw(3) << " | " << endl;
    cout << " | " << setw(3) << g << setw(4) << h << setw(4) << i << setw(3) << " | " << endl;
}
void det ::cofactor2x2()
{
    int tempa;
    tempa = a;
    a = e;
    int tempb;
    tempb = b;
    b = -d;
    d = -tempb;
    e = tempa;
}
void det ::cofactor3x3()
{
    int tempa = a;
    int tempb = b;
    int tempc = c;
    int tempd = d;
    int tempe = e;
    int tempf = f;
    int tempg = g;
    int temph = h;
    int tempi = i;
    a = ((tempe * tempi) - (temph * tempf));
    b = ((tempd * tempi) - (tempg * tempf)) * -1;
    c = ((tempd * temph) - (tempg * tempe));
    d = ((tempb * tempi) - (temph * tempc)) * -1;
    e = ((tempa * tempi) - (tempg * tempc));
    f = ((tempa * temph) - (tempg * tempb)) * -1;
    g = ((tempf * tempb) - (tempc * tempe));
    h = ((tempa * tempf) - (tempd * tempc)) * -1;
    i = ((tempa * tempe) - (tempd * tempb));
}

void det ::adjacent2x2()
{
    cout << " | " << setw(2) << a << setw(3) << d << setw(2) << " | " << endl;
    cout << " | " << setw(2) << b << setw(3) << e << setw(2) << " | " << endl;
}

void det ::adjacent3x3()
{
    cout << " | " << setw(3) << a << setw(4) << d << setw(4) << g << setw(3) << " | " << endl;
    cout << " | " << setw(3) << b << setw(4) << e << setw(4) << h << setw(3) << " | " << endl;
    cout << " | " << setw(3) << c << setw(4) << f << setw(4) << i << setw(3) << " | " << endl;
}

void det ::inverse2x2()
{
    cout << "= 1 / " << result;
    cout << " | " << setw(2) << a << setw(3) << d << setw(2) << " | " << endl;
    cout << setw(11) << " | " << setw(2) << b << setw(3) << e << setw(2) << " | " << endl;
}

void det::inverse3x3()
{
    cout << "= 1 / " << result;
    cout << " | " << setw(3) << a << setw(4) << d << setw(4) << g << setw(3) << " | " << endl;
    cout << setw(12) << " | " << setw(3) << b << setw(4) << e << setw(4) << h << setw(3) << " | " << endl;
    cout << setw(12) << " | " << setw(3) << c << setw(4) << f << setw(4) << i << setw(3) << " | " << endl;
}
int main()
{
    system("cls");
    cout << "------------------- Determinant Calculator ------------------- ";
    int usr;
    char usr1;
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

        cout << "\nYour Determinant is :- " << endl;
        obj.display3x3();

        cout << "\nResult of your Determinant Is = " << obj.result;
    }
    if (usr != 2 && usr != 3)
    {
        cout << "\n\nNot a Proper Input";
    }

    if (obj.result == 0)
    {
        cout << "\n\n*** The Matrix formed by this Determinant is a Singular Matrix and can't be inversed ***";
    }

    // ------------------------------------

    if (obj.result != 0)
    {
        cout << "\n\n*** The Matrix formed by this determinant is a non-Singular Matrix and can be inversed ***";
        cout << "\n\nEnter 'Y' to get Inverse of it.... Else Press 'N' : ";
        cin >> usr1;

        if (usr == 2 && usr1 == 'y')
        {
            cout << "\nCo-Factor Matrix is :- " << endl;
            obj.cofactor2x2();
            obj.display2x2();
            cout << "\nAdjacent Matrix is Transverse of Co-Factor Matrix " << endl;
            cout << "Therefore,";
            cout << "\n\nAdjacent Matrix is :-" << endl;
            obj.adjacent2x2();
            cout << "\n\nInverse of Matrix is :-" << endl;
            obj.inverse2x2();
        }
        if (usr == 2 && usr1 == 'Y')
        {
            cout << "\nCo-Factor Matrix is :- " << endl;
            obj.cofactor2x2();
            obj.display2x2();
            cout << "\nAdjacent Matrix is Transverse of Co-Factor Matrix " << endl;
            cout << "Therefore,";
            cout << "\n\nAdjacent Matrix is :-" << endl;
            obj.adjacent2x2();
            cout << "\n\nInverse of Matrix is :-" << endl;
            obj.inverse2x2();
        }
        if (usr == 3 && usr1 == 'y')
        {
            cout << "\nCo-Factor Matrix is :- " << endl;
            obj.cofactor3x3();
            obj.display3x3();
            cout << "\nAdjacent Matrix is Transverse of Co-Factor Matrix " << endl;
            cout << "Therefore,";
            cout << "\n\nAdjacent Matrix is :-" << endl;
            obj.adjacent3x3();
            cout << "\n\nInverse of Matrix is :-" << endl;
            obj.inverse3x3();
        }
        if (usr == 3 && usr1 == 'Y')
        {
            cout << "\nCo-Factor Matrix is :- " << endl;
            obj.cofactor3x3();
            obj.display3x3();
            cout << "\nAdjacent Matrix is Transverse of Co-Factor Matrix " << endl;
            cout << "Therefore,";
            cout << "\n\nAdjacent Matrix is :-" << endl;
            obj.adjacent3x3();
            cout << "\n\nInverse of Matrix is :-" << endl;
            obj.inverse3x3();
        }
    }

    cout << "\n\nThank You for Trying it :)" << endl;
    cout << "Follow me on GitHub : github.com/kunalshah017\n\n";

    return 0;
}