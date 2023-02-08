
#include <iostream>

enum figure {
    figure_square,
    figure_triangle
};

class Figure
{
private:
    double aSide;
    double bSide;
    double cSide;
    figure pass;

    static int countFig;
    static int countArea;
public:
    Figure()
    {
        aSide = 10;
        bSide = 10;
        cSide = 10;
        pass = figure(1);
        countFig++;
    }
    Figure(int _a, int _b)
    {
        this->aSide = _a;
        this->bSide = _b;
        this->cSide = 0;
        pass = figure(0);
        countFig++;
    }
    Figure(int _a, int _b, int _c)
    {
        this->aSide = _a;
        this->bSide = _b;
        this->cSide = _c;
        pass = figure(1);
        countFig++;
    }
    
    static int retCount()
    {
        return countFig;
    }
    static int retArea()
    {
        return countArea;
    }

    static double triaArea1(const Figure &figure, double h)
    {
        double area = 0;
        if (int(figure.pass) == 1)
        {
            area = figure.aSide / 2 * figure.bSide * h;
            countArea++;
        }
        return area;
    }
    static double triaArea2(const Figure &figure, double sinA)
    {
        double area = 0;
        if (int(figure.pass) == 1)
        {
            area = figure.aSide / 2 * figure.bSide * sinA;
            countArea++;
        }
        return area;
    }
    static double squareArea(const Figure& figure)
    {
        double area = 0;
        if (figure.pass == 0)
        {
            area = figure.aSide * figure.aSide;
            countArea++;
        }
        return area;
    }
    static double rectArea(const Figure& figure)
    {
        double area = 0;
        if (int(figure.pass == 1))
        {
            area = figure.aSide * figure.bSide;
            countArea++;
        }
        return area;
    }
    static double rhombusArea(const Figure& figure, double h_A)
    {
        double area = 0;
        if (int(figure.pass == 1))
        {
            area = figure.aSide * h_A;
            countArea++;
        }
        return area;
    }

};
/*Task 2 Start ->*/
class Student
{
private:
    char* name;
    int grade;

    static int count;
public:
    Student()
    {
        name = nullptr;
        grade = 0;
    }
    Student(char* _name)
    {
        int size = strlen(_name);
        name = new char[size];
        for (int i = 0; i < size; i++)
        {
            name[i] = _name[i];
        }
        name[size] = '\n';
    }
    Student(char* _name, int _grade) : Student(_name)
    {
        grade = _grade;
    }

    static int retCount()
    {
        return count;
    }

    ~Student()
    {
        if (name != nullptr)
        {
            delete[] name;
        }
    }
};
class Point
{
private:
    int x;
    int y;

    static int count;
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int _x)
    {
        x = _x;
    }
    Point(int _x, int _y) : Point(_x)
    {
        y = _y;
    }

    static int retCount()
    {
        return count;
    }
};
class Fraction
{
private:
    int numerator;
    int denominator;

    static int count;
public:
    Fraction()
    {
        numerator = 0;
        denominator = 0;
    }
    Fraction(int _numerator)
    {
        numerator = _numerator;
    }
    Fraction(int _numerator, int _denominator) : Fraction(_numerator)
    {
        denominator = _denominator;
    }

    static int retCount()
    {
        return count;
    }
};
/*Task 2 end <-*/
int Figure::countFig = 0;
int Figure::countArea = 0;
int main()
{
    Figure test1(10, 20, 10);
    std::cout << Figure::triaArea1(test1, 10) << std::endl;
    Figure test2(10, 10);
    std::cout << Figure::squareArea(test2) << std::endl;
    std::cout << Figure::retCount() << std::endl;
}