# 1748. Sum of Unique Elements

🔗 [View on LeetCode](https://leetcode.com/problems/sum-of-unique-elements/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 89

## Problem
Given an integer array nums, the unique elements are the ones that appear exactly once in the array. Return the sum of all the unique elements of nums.

**Examples:**
- nums = [1,2,3,2] → 4 (the unique elements are 1 and 3)
- nums = [1,1,1,1,1] → 0 (there are no unique elements)
- nums = [1,2,3,4,5] → 15 (every element is unique)

**Constraints:**
- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

## Approach
Every value is between 1 and 100, so a frequency array of size 101 can be indexed directly by the value. Go through nums once and increase the count at freq[nums[i]]. Then scan the frequency array, and for every value whose count is exactly 1, add that value to the answer. Values that appear twice or more are skipped, and values that never appear have a count of 0, so they are skipped too.

## Complexity
- **Time:** O(n + M), where M = 100 is the range of values (one pass over nums and one pass over the frequency array)
- **Space:** O(M) - the frequency array has a fixed size of 101

## Key Learning
The loop adds the index i, not the count, because the index is the value itself. That is what lets a plain array replace a hash map when the values live in a small known range. A single pass version is also possible: add a value to the answer the first time it is seen, subtract it the second time it is seen, and ignore it from the third time on. That avoids the second scan, and it is a nice trick to remember for "appears exactly once" questions.
