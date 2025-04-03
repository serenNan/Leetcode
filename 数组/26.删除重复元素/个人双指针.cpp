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
        if (n < 1)
        {
            return 1;
        }
        int slow = 1, fast = 1;
        int maxNum = nums[0];
        while (fast < n)
        {
            if (maxNum < nums[fast])
            {
                maxNum = nums[fast];
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
            else
            {
                fast++;
            }
        }
        return slow;
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
