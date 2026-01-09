#include <iostream>
#include <string>
#include <algorithm> // for std::sort
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        return "";
    }


    int i = 0;
    sort(strs.begin(), strs.end());
    while (i < strs[0].size() && i < strs.back().size() && strs[0][i] == strs.back()[i])
    {
        i++;
    }

    return strs[0].substr(0, i);
}

int main(int argc, char const *argv[])
{
    vector<string> arrayOfStrings = {"flower", "flow", "flight"};
    string x = longestCommonPrefix(arrayOfStrings);
    cout << x << std::endl;
    return 0;
}
