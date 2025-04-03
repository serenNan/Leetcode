/*
 * @lc app=leetcode.cn id=27 lang=cpp
 * @lcpr version=30204
 *
 * [27] 移除元素
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
// 官方的题解就很清晰明确了，只要左边出现一个 val 值，那就直接拿右边的值过来，不用交换，毕竟 val 本身就要被删除，我们只要保证需要留下的元素都留在左边就行。
class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            if (nums[left] == val)
            {
                nums[left] = nums[right];
                right--;
            }
            else
            {
                left++;
            }
        }
        return left;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,2,2,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,2,3,0,4,2]\n 3 \n
// @lcpr case=end

 */
