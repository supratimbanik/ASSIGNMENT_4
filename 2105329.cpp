#include <iostream>
#include <iomanip>
using namespace std;
// Sample class created to demonstrate constructors
class Sample
{
public:
    int x;
    Sample()
    {
        x = 5;
        cout << "\nDefault Constructor value: " << x;
    }
    Sample(int a)
    {
        x = a;
        cout << "\nParameterised Constructor value: " << x;
    }
    Sample(Sample &o1, Sample &o2)
    {
        x = o1.x + o2.x;
        cout << "\nCopy Constructor value: " << x;
    }
    ~Sample()
    {
        static int c=0;
        c++;
        cout << "\nDestructor called "<<c;
    }
};
// Operator overloading to compare strings
class Overload
{
private:
    string x;

public:
    void Set_Value()
    {
        cout << "\nEnter string :";
        fflush(stdin);
        getline(cin, x);
    }
    int operator==(Overload &o)
    {
        if (x == o.x)
            return 1;
        else
            return 0;
    }
};
// Function overloading to perform arithmetic operattions
void Calc(int a)
{
    cout << "\nSquare : " << a * a;
}
void Calc(int a, int b)
{
    cout << "\nSum : " << a + b;
}
// friend function concept used to convert decimal to binary
class Conversion
{
protected:
    int n, b = 0;

public:
    Conversion()
    {
        cout << "Enter Decimal  Number :";
        cin >> n;
    }
    friend void convert(Conversion &a);
};
void convert(Conversion &a)
{
    int i = 1, j = a.n;
    for (j = a.n; j > 0; j = j / 2)
    {
        a.b = a.b + (a.n % 2) * i;
        i = i * 10;
        a.n = a.n / 2;
    }
    cout << "Binary number =" << a.b << endl;
}
// Demonstration of Inheritance
class A
{
protected:
    int a;

public:
    A()
    {
        a = 5;
    }
    virtual void Show_Value() = 0;
};
class B : virtual public A
{
protected:
    int b;

public:
    B()
    {
        b = 6;
    }
};
class C : virtual public A
{
protected:
    int c;

public:
    C()
    {
        c = 7;
    }
};
class D : public B, public C
{
protected:
    int d;

public:
    D()
    {
        d = 8;
    }
    void Show_Value()
    {
        cout << "\nA: " << a;
        cout << "\nB: " << b;
        cout << "\nC: " << c;
        cout << "\nD: " << d;
    }
};
// Template class to carry out bubble sort
template <class T>
class Template
{
private:
    T *a;

public:
    void BubbleSort(T *x, int n)
    {
        a=x;
        int i, j;
        T temp;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        cout << "\nSorted Array: ";
        for (i = 0; i < n; i++)
            cout << setw(4) << a[i];
    }
};
// Exception handling to carry out division by zero error
void Error()
{
    int a, b;
    cout << "\nEnter two numbers :";
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw -1;
        else
            cout << "\nResult: " << (a / b);
    }
    catch (int)
    {
        cout << "\nDividion not possible!";
    }
}
int main()
{
    int c;
    while (1)
    {
        cout << "\n\n----------OPTIONS---------\n\n";
        cout << "\n1.Constructor and Destructor";
        cout << "\n2.Operator Overloading";
        cout << "\n3.Function Overloading";
        cout << "\n4.Friend Function";
        cout << "\n5.Inheritance";
        cout << "\n6.Template";
        cout << "\n7.Exception Handling";
        cout << "\n8.Quit";
        cout << endl;
        cout << endl;
        cout << "Enter choice: ";
        cin >> c;
        if (c == 1)
        {
            Sample s1, s2(10), s3(s1, s2);
        }
        else if (c == 2)
        {
            Overload o1, o2;
            cout << "\nFirst string: ";
            o1.Set_Value();
            cout << "\nSecond string: ";
            o2.Set_Value();
            if (o1 == o2)
                cout << "\nStrings are equal";
            else
                cout << "\nStrings are unequal";
        }
        else if (c == 3)
        {
            int x, a, b;
            cout << "Enter number to find square: ";
            cin >> x;
            cout << "Enter two numbers to find sum: ";
            cin >> a >> b;
            Calc(x);
            Calc(a, b);
        }
        else if (c == 4)
        {
            Conversion c1;
            convert(c1);
        }
        else if (c == 5)
        {
            D d;
            cout << "\nValue at classes hierarchically: ";
            d.Show_Value();
        }
        else if (c == 6)
        {
            int a[5];
            cout << "\nEnter 5 numbers to carry out bubble sort: ";
            cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
            Template<int> t;
            t.BubbleSort(a, 5);
        }
        else if (c == 7)
        {
            cout << "\nDivision by Exception Handling: ";
            Error();
        }
        else if (c == 8)
        {
            exit(0);
        }
        else
        {
            cout << "\nInvalid Choice!";
        }
    }
    return 0;
}