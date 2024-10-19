#include <vector>
#include <unordered_map> 

class Solution 
{
public:
    
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        // saved value to its index
        std::unordered_map<int, int> cachedValues;

        // also can be optimized with some SSE instructions
        for (int ind = 0; ind < nums.size(); ++ind)
        {
            int value = nums[ind];
            int valueToGetSum = target - value;
            if (auto res = cachedValues.find(valueToGetSum); res != cachedValues.end())
            {
                return std::vector<int>{ind, res->second};
            }
            else
            {
                cachedValues.insert({ value, ind });
            }
        }
        return {};
    }
};

int main()
{
    Solution a;

    std::vector<int> inputNums = { 2, 7, 11, 15 };
    int target = 9;

    a.twoSum(inputNums, target);
    return 0;
}