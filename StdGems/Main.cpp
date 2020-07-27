#include <iostream>
#include <unordered_map>
#include <string>
#include "Vec2.h"

namespace std
{
    template<> struct hash<Vei2>
    {
        size_t operator()(const Vei2& vec2) const
        {
            std::hash<int> hasher;
            auto hashX = hasher(vec2.x);
            auto hashY = hasher(vec2.y);
            hashX ^= hashY + (hashX >> 4) ^ (hashY << 8);
            return hashX;
        }
    };
}
int main()
{
    std::unordered_map<Vei2, std::string> unordered_map =
    {
        { {2, 23}, "two"},
        { {1, 20}, "one"},
        { {10, 33}, "ten"},
        { {55, 555}, "fifty five"},
        { { 99, 3300 }, "ninety nine" }
    };
    std::cout << unordered_map[{ 55, 555 }];
    return 0;
}
