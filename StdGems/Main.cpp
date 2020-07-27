#include <iostream>
#include <unordered_map>
#include <string>
#include <functional>

class CaseSwitch
{
public:
    std::function<void()>& Case(std::string string)
    {
        return map[string];
    }

    std::function<void()>& Default()
    {
        return def;
    }

    void operator[] (const std::string string) const
    {
        auto func = map.find(string);
        if (func != map.end())
        {
            func->second();
        }
        else
        {
            NotFound();
        }
    }
private:
    std::unordered_map<std::string, std::function<void()>> map;
    std::function<void()> NotFound = []() { std::cout << "Not Found!" << std::endl; };
    std::function<void()> def = []() { std::cout << "Default" << std::endl; };
};

int main()
{
    CaseSwitch sw;
    sw.Case("foo") = []() { std::cout << "This is foo" << std::endl; };
    sw.Case("bar") = []() { std::cout << "This is bar" << std::endl; };
    sw["foo"];
    sw["fff"];
    sw.Default()();
    return 0;
}
