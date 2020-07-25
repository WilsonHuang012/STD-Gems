#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::vector<int> list = { 1,1,2,4,5,6,7,7,8,8,0,0,12,11,11,15,77,100 };
    std::set<int> set;
    for (int i : list)
    {
        auto existed = set.insert(i);
        if (existed.second)
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
    std::cout << "set:\n";
    for (int i : set)
        std::cout << i << " ";
    return 0;
}
