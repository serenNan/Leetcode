// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30204
 *
 * [189] 轮转数组
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
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        for (int i = 0; i < k; i++)
        {
            int temp = nums[n - 1];
            int j = n - 1;
            while (j > 0)
            {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[0] = temp;
        }
        return;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
