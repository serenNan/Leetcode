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
// 设置一个饱食度,遍历数组,每走一步饱食度-1,如果当前值比当前饱食度大,
// 就吃东西使饱食度达到当前值,如果能撑到数组结尾,说明可达.
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int food = 0;
        int i;
        for (i = 0; i < nums.size(); i++)
        {
            if (--food < nums[i])
            {
                food = nums[i];
            }
            if (food == 0)
                break;
        }
        return i >= nums.size() - 1 ? true : false;
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

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,2]\n
// @lcpr case=end

 */
