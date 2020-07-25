#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
    std::map<std::string, int> map;
    map.emplace("d", 4);
    map.emplace("e", 5);
    map.emplace_hint(map.find("d"), "h", 6);
    map.insert({ "a", 1 });
    map.insert({ "c", 3 });
    map.insert({ "b", 2 });
    //access an element doesn't exist
    map["i"]; //insert the element with default value

    for (auto m : map)
    {
        std::cout << m.first << " : " << m.second << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "insert a existed key : a" << std::endl;
    auto target = map.emplace("a", 0);
    if (!target.second) //insert failed
    {
        std::cout << "key \"a\" is existed { "
            << target.first->first << " : " << target.first->second
            << " }"
            << std::endl;
    }
    
    std::cout << std::endl << "Remove value greater than 2" << std::endl;
    for (auto i = map.begin(); i != map.end(); )
    {
        if (i->second > 2)
        {
            i = map.erase(i);
        }
        else
        {
            i++;
        }
    }

    for (auto m : map)
    {
        std::cout << m.first << " : " << m.second << std::endl;
    }

    return 0;
}
