#include <iostream>
#include <vector>

using namespace std;

bool isPalVec(int val)
{
    bool is;
    if (val < 0)
    {
        return false;
    }
    std::vector<int> pal;
    int x = val;
    while (x > 0)
    {
        int mod = x % 10;
        pal.push_back(mod);
        x = x / 10;
    }
    int count = pal.size();
    for (size_t i = 0; i < count;)
    {
        if ((pal.at(i) == pal.at(count - 1 - i)))
        {
            is = true;
            i++;
        }
        else
        {
            is = false;
            return is;
        }
    }
    return is;
}

bool isPal(int val)
{
    if (val < 0)
    {
        return false;
    }

    int count = 0;
    bool is;
    int x = val;
    while (x > 0)
    {
        x = x / 10;
        count++;
    }

    int y = val;
    int *pal = new int[count];
    for (size_t i = 0; i < count; i++)
    {
        pal[i] = y % 10;
        y = y / 10;
        // cout << pal[i] << endl;
    }

    for (size_t i = 0; i < count;)
    {
        if ((pal[i] == pal[count - 1 - i]))
        {
            is = true;
            i++;
        }
        else
        {
            is = false;
            return is;
        }
    }
    return is;
}

int main(int argc, char const *argv[])
{
    int val = 121;
    cout << isPalVec(val) << endl;
    return 0;
}
