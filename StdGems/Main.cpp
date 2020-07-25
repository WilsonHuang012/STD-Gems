#include <iostream>
#include <map>
#include <string>

class MyClass
{
public:
    MyClass(int x)
        : x(x)
    {

    }
    ~MyClass() = default;

public:
    int x;
};

struct MyClassCompare
{
    bool operator()(const MyClass& lhs, const MyClass& rhs) const
    {
        return lhs.x > rhs.x;
    }
};

int main()
{
    std::multimap<MyClass, std::string, MyClassCompare> multiMap;
    multiMap.emplace(MyClass(1), "aaa");
    multiMap.emplace(MyClass(3), "gg");
    multiMap.emplace(MyClass(5), "r");
    multiMap.emplace(MyClass(1), "bbb");
    multiMap.emplace(MyClass(6), "uu");
    multiMap.emplace(MyClass(1), "ccc");
    multiMap.emplace(MyClass(9), "df");

    auto result = multiMap.equal_range(1);
    for (auto i = result.first; i != result.second; i++)
    {
        std::cout << i->second << std::endl;
    }
    return 0;
}
