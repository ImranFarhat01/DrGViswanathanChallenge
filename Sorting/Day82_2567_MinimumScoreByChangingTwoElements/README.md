# 2567. Minimum Score by Changing Two Elements

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-score-by-changing-two-elements/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 82

## Problem
Given an integer array nums, the low score is the minimum absolute difference between any two elements, the high score is the maximum absolute difference between any two elements, and the score of nums is the sum of the high and low scores. Return the minimum score achievable after changing exactly two elements of nums to any values.

**Examples:**
- nums = [1,4,7,8,5] → 3 (change nums[0] and nums[1] to 6, giving [6,6,7,8,5], where the low score is 0 and the high score is 3)
- nums = [1,4,3] → 0 (change nums[1] and nums[2] to 1)

**Constraints:**
- 3 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^9

## Approach
The low score can always be made 0. Since at least one element stays untouched (n >= 3), a changed element can be set equal to an untouched one, which creates a pair with difference 0. So the real job is to minimize the high score, which is the largest value minus the smallest value of the whole array.

Changing two elements to match existing values effectively removes them from the range calculation. After sorting, there are only three sensible ways to remove two elements:
- Remove the two smallest: the range becomes nums[n - 1] - nums[2].
- Remove the two largest: the range becomes nums[n - 3] - nums[0].
- Remove the smallest and the largest: the range becomes nums[n - 2] - nums[1].

Removing anything from the middle never shrinks the range, so these three cases cover everything. The answer is the smallest of the three differences.

## Complexity
- **Time:** O(n log n) - dominated by the sort
- **Space:** O(1) extra - the array is sorted in place

## Key Learning
The two parts of the score do not fight each other here. Once you see that the low score can always be driven to 0, the problem collapses into "shrink the range by dropping two extreme elements". Sorting makes the candidates easy to read off as fixed positions, so no loop is needed after the sort. Because the array is sorted, every difference is already non-negative and abs is unnecessary. An O(n) version is possible too: instead of sorting, find just the three smallest and three largest values in a single pass and use the same three formulas on them.
