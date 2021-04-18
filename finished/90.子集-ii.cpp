/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (61.91%)
 * Likes:    527
 * Dislikes: 0
 * Total Accepted:    94.5K
 * Total Submissions: 149.8K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums
 * ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
 *
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0]
 * 输出：[[],[0]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * -10
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// 参考：https://leetcode-cn.com/problems/subsets-ii/solution/90-zi-ji-iiche-di-li-jie-zi-ji-wen-ti-ru-djmf/

// @lc code=start
class Solution {
 public:
  vector<int> path;         // 每个元素
  vector<vector<int>> res;  // 结果

  void backtracking(const vector<int> &nums, int start_ind,
                    vector<bool> &used) {
    res.push_back(path);  // 第一次加的是空集
    for (int i = start_ind; i < nums.size(); i++) {
      // 去重操作
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
        continue;
      }
      path.push_back(nums[i]);
      used[i] = true;
      backtracking(nums, i + 1, used);
      used[i] = false;
      path.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtracking(nums, 0, used);
    return res;
  }
};
// @lc code=end
