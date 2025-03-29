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
        if (strs.empty())
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        string commonPrefix = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            commonPrefix = getCommonPrefix(commonPrefix, strs[i]);
            if (commonPrefix.empty())
            {
                break; // 如果公共前缀为空，提前退出
            }
        }
        return commonPrefix;
    }

    string getCommonPrefix(const string &str1, const string &str2)
    {
        size_t minLen = std::min(str1.size(), str2.size()); // 由于字符串没有负数，使用 size_t 避免出现负数情况
        size_t i = 0;

        while (i < minLen && str1[i] == str2[i])
        {
            i++;
        }

        return str1.substr(0, i); // 直接截取公共前缀，避免字符的创建和复制
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
