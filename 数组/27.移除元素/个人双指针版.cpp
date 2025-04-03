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
// 这里主要思路是把所有等于 val 的值移动到数组的最后
// 但是我这里的操作有些过于繁琐，且要考虑左右指针大小判断条件
// 比较容易出错
class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int right = n - 1;
        int left = 0;
        while (1)
        {
            while (left <= right && nums[left] != val)
            {
                left++;
            }
            if (left >= right)
                break;
            while (right > left && nums[right] == val)
            {
                right--;
            }
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
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
