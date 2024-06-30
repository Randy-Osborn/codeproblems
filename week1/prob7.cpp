#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool hasRepeatedCharacters(const std::string &str)
{
    unordered_set<char> charSet;
    for (char c : str)
    {
        if (charSet.find(c) != charSet.end())
        {
            return true;
        }
        charSet.insert(c);
    }
    return false;
}

int lengthOfLongestSubstring(string s)
{
    if (s.empty())
    {
        return 0;
    }
    unordered_set<char> charSet;
    int maxUniqueChars = 0;
    for (char c : s)
    {
        if (charSet.find(c) == charSet.end())
        {
            charSet.insert(c);
            maxUniqueChars++;
        }
    }
    int length = 0;
    vector<string> myVec;
    for (size_t i = 0; i < s.size(); i++)
    {
        for (size_t j = 1; j <= s.size() - i; j++)
        {
            string substring = s.substr(i, j);
            if (substring.size() >= length && !hasRepeatedCharacters(substring))
            {
                myVec.push_back(substring);
                if (length < substring.size())
                {
                    length = substring.size();
                }
            }
            if (substring.size() >= maxUniqueChars)
            {
                break;
            }
        }
    }
    return length;
};

int main(int argc, char const *argv[])
{
    int x = lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzzwxyz");
    cout << x << endl;
    return 0;
}
