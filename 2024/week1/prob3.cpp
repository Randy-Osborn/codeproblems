#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
int romanToNum(string s)
{
    map<char, int> romans{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int total = 0;
    int currentNum;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                currentNum = 4;
                i++;
            }
            else if (s[i + 1] == 'X')
            {
                currentNum = 9;
                i++;
            }
            else
            {
                currentNum = romans[s[i]];
            }
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                currentNum = 40;
                i++;
            }
            else if (s[i + 1] == 'C')
            {
                currentNum = 90;
                i++;
            }
            else
            {
                currentNum = romans[s[i]];
            }
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                currentNum = 400;
                i++;
            }
            else if (s[i + 1] == 'M')
            {
                currentNum = 900;
                i++;
            }
            else
            {
                currentNum = romans[s[i]];
            }
        }
        else
        {
            currentNum = romans[s[i]];
        }
        total += currentNum;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    string s = "MCMXCIV";
    int x = romanToNum(s);

    std::cout << x << std::endl;
    return 0;
}
