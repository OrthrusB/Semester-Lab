#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a, b;
    int k, l, i, j;

    std::cout << "Enter the number of elements of set A: ";
    std::cin >> k;

    std::cout << "Enter the elements of set A: ";
    for (i = 0; i < k; i++)
    {
        int element;
        std::cin >> element;
        a.push_back(element);
    }

    std::cout << "Enter the number of elements of Set B: ";
    std::cin >> l;

    std::cout << "Enter the elements of set B: ";
    for (i = 0; i < l; i++)
    {
        int element;
        std::cin >> element;
        b.push_back(element);
    }

    std::cout << "\nCartesian Product = { ";
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < l; j++)
        {
            std::cout << "(" << a[i] << "," << b[j] << ")";
            if (i != k - 1 || j != l - 1)
                std::cout << ", ";
        }
    }
    std::cout << " }" << std::endl;

    return 0;
}
