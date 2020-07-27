#include <iostream>
#include <unordered_map>
#include <string>
#include "Vec2.h"

struct MyStruct
{
    std::string str;
    Vei2 vec;
    int n;
    char m;
};

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

    template<> struct hash<MyStruct>
    {
        size_t operator()(const MyStruct& myStruct) const
        {
            std::hash<Vei2> vhasher;
            auto hv = vhasher(myStruct.vec);
            std::hash<string> shasher;
            auto hs = shasher(myStruct.str);
            std::hash<int> ihasher;
            auto is = ihasher(myStruct.n);
            std::hash<char> chasher;
            auto cs = chasher(myStruct.m);
            hv ^= hs + (is >> 4) ^ (cs << 8);
            return hv;
        }
    };

    template<> struct equal_to<MyStruct>
    {
        bool operator()(const MyStruct& lhs, const MyStruct& rhs) const
        {
            return lhs.str == rhs.str &&
                lhs.m == rhs.m &&
                lhs.n == rhs.n &&
                lhs.vec == rhs.vec;
        }
    };
}
int main()
{
    std::unordered_map<MyStruct, std::string> unordered_map =
    {
        { {"2" , {2, 23}, 12, 4}, "two"},
        { {"1" , {1, 23}, 14, 8}, "one"},
        { {"1" , {10, 43}, 16, 16}, "ten"},
        { {"2" , {55, 53}, 18, 32}, "fifty five"},
        { {"2" , {99, 63}, 20, 64}, "ninety nine" }
    };
    std::cout << unordered_map[{"2", { 55, 53 }, 18, 32}];
    return 0;
}
