// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=30204
 *
 * [55] 跳跃游戏
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
// 每次先判断当前位置是否可达
// 若能到达，就判断当前位置的下标的值和当前位置的值是否大于最远可达距离
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return true;
        }
        int maxStep = nums[0];
        for (int i = 1; i < n; i++)
        {
            int step = nums[i];
            if (i <= maxStep)
            {
                maxStep = max(i + nums[i], maxStep);
            }
            if (maxStep >= n - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */
