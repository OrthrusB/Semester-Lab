#include <iostream>
#include <cmath> // For floor and ceil functions

int flr(float x);
int cei(float y);

int main()
{
    float value;
    int a = 0, b = 0;
    std::cout << "Enter a number: ";
    std::cin >> value;

    a = flr(value);
    b = cei(value);

    std::cout << "Floor=" << a << " and Ceiling=" << b << std::endl;
    return 0;
}

int flr(float y)
{
    if (y < 0)
    {
        int t = static_cast<int>(y) - 1;
        return t;
    }
    else
    {
        return static_cast<int>(y);
    }
}

int cei(float x)
{
    if (x - static_cast<int>(x) == 0)
    {
        return static_cast<int>(x);
    }
    else
    {
        return flr(x) + 1;
    }
}
