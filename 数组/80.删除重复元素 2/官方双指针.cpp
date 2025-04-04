// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30204
 *
 * [80] 删除有序数组中的重复项 II
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
// 这题自己想得解法太复杂了，设计到的变量太多，导致最后根本解答不了
// 这题使用双指针就能轻松解答
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return n;
        }

        int slow = 2, fast = 2; // 指针从第二个位置开始
        while (fast < n)
        {
            if (nums[slow - 2] == nums[fast])
            {
                fast++;
            }
            else
            {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

 */
