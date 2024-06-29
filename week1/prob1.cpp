#include <vector>
#include <map>
#include <iostream>
using std::vector;
using std::map;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> solution;
    int newTarget;
    int currentIndex;
    for (size_t i = 0; i < nums.size(); i++)
    {
        currentIndex = i;
        newTarget = target - nums.at(currentIndex);
        for (size_t j = i + 1; j < nums.size(); j++)
        {
            if (nums.at(j) == newTarget)
            {

                solution.push_back(currentIndex);
                solution.push_back(j);
                return solution;
            }
        }
    }
    return solution;
}


vector<int> twoSumMap(vector<int> &nums, int target)
{
    vector<int> solution;
    int newTarget;
    map<int, int> myMap;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (myMap.count(nums.at(i)))
        {
            solution.push_back(myMap[nums.at(i)]);
            solution.push_back(i);
        }
        
        newTarget = target - nums.at(i);
        myMap[newTarget] = i;


    }
     return solution;
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> solution;
    vector<int> solution2;
    solution = twoSum(nums, target);
    solution2 = twoSumMap(nums, target);
    for (int i = 0; i < 2; i++)
    {
        std::cout << solution.at(i) << std::endl;
    }
 for (int i = 0; i < 2; i++)
    {
        std::cout << solution2.at(i) << std::endl;
    }
    return 0;
}
