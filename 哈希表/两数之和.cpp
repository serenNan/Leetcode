class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
     {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/two-sum/solutions/
