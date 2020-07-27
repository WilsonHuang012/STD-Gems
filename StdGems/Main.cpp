#include <iostream>
#include <unordered_map>
#include <string>
#include "Vec2.h"

struct HashVec2
{
    template<typename T>
    size_t operator()(const Vec2_<T>& vec2) const
    {
        std::hash<T> hasher;
        auto hashX = hasher(vec2.x);
        auto hashY = hasher(vec2.y);
        hashX ^= hashY + (hashX >> 4) ^ (hashY << 8);
        return hashX;
    }
};

int main()
{
    std::unordered_map<Vec2, std::string, HashVec2> unordered_map =
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
