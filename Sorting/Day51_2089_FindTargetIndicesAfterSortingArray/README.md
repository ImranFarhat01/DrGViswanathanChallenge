# 2089. Find Target Indices After Sorting Array

🔗 [View on LeetCode](https://leetcode.com/problems/find-target-indices-after-sorting-array/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 51

## Problem
Given a 0-indexed integer array nums and a target value, a target index is an index i such that nums[i] == target after nums has been sorted in non-decreasing order. Return the list of target indices in increasing order, or an empty list if the target does not appear.

**Examples:**
- nums = [1,2,5,2,3], target = 2 → [1,2] (sorted array is [1,2,2,3,5])
- nums = [1,2,5,2,3], target = 3 → [3]
- nums = [1,2,5,2,3], target = 5 → [4]

**Constraints:**
- 1 <= nums.length <= 100
- 1 <= nums[i], target <= 100

## Approach
Sort the array, then scan it once from left to right. Every index i where nums[i] equals the target is added to the answer. Because the array is sorted and the scan moves left to right, the indices come out already in increasing order, so no extra sorting of the result is needed.

## Complexity
- **Time:** O(n log n) - dominated by the sort, followed by an O(n) scan
- **Space:** O(1) extra - the array is sorted in place, and only the output list is created

## Key Learning
Sorting is not actually required here. After sorting, the target occupies one continuous block, so only two counts are needed: how many elements are smaller than the target, and how many equal it. If there are `less` smaller elements and `equal` matching ones, the answer is every index from `less` to `less + equal - 1`. Counting both in a single pass brings the time down to O(n), which is a useful pattern whenever the question asks about positions after sorting rather than the sorted array itself.
