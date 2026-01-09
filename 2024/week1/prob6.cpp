#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    unordered_map<int, bool> myMap;
    for (size_t i = 0; i < nums.size(); )
    {
        if (myMap[nums[i]] == true)
        {
            nums.erase(nums.begin() + i);
        }
        else
        {
            myMap[nums[i]] = true;
            i++;
        }
    }
    return nums.size();
}


 int removeDuplicatesInPlace(vector<int>& nums) {
   if (nums.empty()) return 0;
    
    int index = 1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[index++] = nums[i];
        }
    }
    return index;
    }


int main(int argc, char const *argv[])
{
    std::vector<int> nums = {1,1,2,2};

    int x = removeDuplicates(nums);

    cout << x << endl;
    cout << "Modified vector:" << endl;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
