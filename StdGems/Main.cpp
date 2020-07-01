#include <iostream>
#include <sstream>
#include <optional>

std::optional<int> Search(int target)
{
    int array[5] = { 4, 1, 3, 2, 5 };
    for (int i = 0; i < 5; i++)
    {
        if (array[i] == target)
        {
            return array[i];
        }
    }
    return {};
}

int main()
{
    std::optional<int> x;
    x = Search(7);
    if (x)
    {
        std::cout << *x;
    }
    else
    {
        std::cout << "Not Found";
    }
    return 0;
}
