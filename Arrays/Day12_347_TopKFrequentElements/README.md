# 347. Top K Frequent Elements

🔗 [View on LeetCode](https://leetcode.com/problems/top-k-frequent-elements/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 12

## Problem
Given an integer array nums and an integer k, return the k most frequent elements. The answer can be returned in any order.

**Examples:**
- nums = [1,1,1,2,2,3], k = 2 → [1,2]
- nums = [1], k = 1 → [1]
- nums = [1,2,1,2,1,2,3,1,3,2], k = 2 → [1,2]

**Constraints:**
- 1 <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4
- k is in the range [1, number of unique elements in the array]
- The answer is guaranteed to be unique

**Follow-up:** The algorithm's time complexity must be better than O(n log n).

## Approach
First, build a frequency map counting how many times each number appears in nums. Then, repeat k times: scan the entire map to find the entry with the highest frequency, record its key, and remove that entry from the map so it isn't picked again on the next iteration.

## Complexity
- **Time:** O(n + k * m), where n is the size of nums and m is the number of unique elements, since each of the k iterations scans the remaining map entries
- **Space:** O(m) for the frequency map, where m is the number of unique elements

## Key Learning
This approach works correctly but doesn't meet the follow-up's O(n log n) requirement in the worst case, since repeatedly scanning the map for the max is not asymptotically optimal when k is large. A min-heap of size k, or bucket sort based on frequency (since frequency is bounded by n), would both achieve better complexity by avoiding repeated full scans of the remaining elements. Worth revisiting this one with a heap-based or bucket-sort approach to properly satisfy the follow-up constraint.
