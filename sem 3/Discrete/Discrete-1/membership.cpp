#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ages(5);
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Enter the age of person " << i + 1 << ": ";
        std::cin >> ages[i];
    }

    for (int i = 0; i < 5; i++)
    {
        if (ages[i] <= 20)
            std::cout << "Degree of Membership of person " << i + 1 << " is 1" << std::endl;
        else if (ages[i] > 20 && ages[i] <= 30)
            std::cout << "Degree of Membership of person " << i + 1 << " is " << (30.00 - static_cast<float>(ages[i])) / 30.00 << std::endl;
        else
            std::cout << "Degree of Membership of person " << i + 1 << " is 0" << std::endl;
    }

    return 0;
}
