#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            // unordered_map<int, int>::iterator
            auto it = map.find(target - nums[i]);
            if (it != map.end())
            {
                return {it->second,i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};