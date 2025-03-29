/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30204
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() < 2)
        {
            return strs[0];
        }
        string str1 = strs[0], str2 = strs[1];
        int minLen = min(str1.size(), str2.size());
        string commonPrefix;
        for (int i = 0; i < minLen; i++)
        {
            if (str1[i] == str2[i])
            {
                commonPrefix.push_back(str1[i]);
            }
            else
            {
                break;
            }
        }

        if (strs.size() == 2)
        {
            return commonPrefix;
        }

        for (int i = 2; i < strs.size(); i++)
        {
            string str = strs[i];
            string newPrefix;

            minLen = min(commonPrefix.size(), str.size());

            for (int j = 0; j < minLen; j++)
            {
                if (commonPrefix[j] == str[j])
                {
                    newPrefix.push_back(str[j]);
                }
            }
            commonPrefix = newPrefix;
        }
        return commonPrefix;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
