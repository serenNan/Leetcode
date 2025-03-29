// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 * @lcpr version=30204
 *
 * [49] 字母异位词分组
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
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 自定义哈希函数，用于处理array<int, 26>类型的键
        auto arrayHash = [fn = hash<int>{}](const array<int, 26> &arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num); // 累积计算哈希值
            });
        };

        // 使用自定义哈希函数的unordered_map，键为字符计数数组
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);

        // 遍历每个字符串，统计字符频率并分组
        for (string &str : strs)
        {
            array<int, 26> counts{}; // 初始化计数数组为0
            for (char c : str)
            {
                counts[c - 'a']++; // 统计字符出现次数
            }
            mp[counts].emplace_back(str); // 将字符串添加到对应的分组
        }

        // 提取分组结果
        vector<vector<string>> ans;
        for (auto &pair : mp)
        {
            ans.emplace_back(pair.second);
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["eat", "tea", "tan", "ate", "nat", "bat"]\n
// @lcpr case=end

// @lcpr case=start
// [""]\n
// @lcpr case=end

// @lcpr case=start
// ["a"]\n
// @lcpr case=end

 */
