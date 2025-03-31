/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
        {
            return s;
        }
        int left = 0;
        int right = 0;
        int start = 0;
        int end = 0;
        int maxLen = 0;
        int len = 1;

        for (int i = 0; i < n; i++)
        {
            left = i - 1;
            right = i + 1;

            while (left >= 0 && s[i] == s[left])
            {
                left--;
                len++;
            }

            while (right < n && s[i] == s[right])
            {
                right++;
                len++;
            }

            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
                len += 2;
            }

            if (len > maxLen)
            {
                maxLen = len;
                start = left;
                end = right;
            }
            len = 1;
        }
        return s.substr(start + 1, maxLen);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
