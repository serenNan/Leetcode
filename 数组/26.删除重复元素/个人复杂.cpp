// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30204
 *
 * [26] 删除有序数组中的重复项
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 1;
        }
        unordered_set<int> set;
        int left = 0, right = 0;
        while (right < n - 1)
        {
            if (!set.count(nums[left]))
            {
                set.insert(nums[left]);
            }
            else
            {
                while (right < n)
                {
                    if (nums[right] == nums[left])
                    {
                        right++;
                    }
                    else
                    {
                        left++;
                        nums[left] = nums[right];
                        break;
                    }
                }
            }
        }
        return left + 1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */
