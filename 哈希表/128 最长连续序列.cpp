/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30204
 *
 * [128] 最长连续序列
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
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        for (auto num : nums)
        {
            num_set.insert(num);
        }

        int longstreak = 0;

        for (auto num : num_set)
        {
            if (!num_set.count(num - 1))
            {
                int curstreak = 1;
                int nextnum = num + 1;
                while (num_set.count(nextnum))
                {
                    curstreak++;
                    nextnum++;
                }
                longstreak = max(longstreak, curstreak);
            }
        }
        return longstreak;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,2]\n
// @lcpr case=end

 */
