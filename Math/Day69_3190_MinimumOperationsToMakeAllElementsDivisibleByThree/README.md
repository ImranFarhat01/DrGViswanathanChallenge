# 3190. Find Minimum Operations to Make All Elements Divisible by Three

🔗 [View on LeetCode](https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 69

## Problem
Given an integer array nums, in one operation you can add 1 to or subtract 1 from any element. Return the minimum number of operations needed to make every element divisible by 3.

**Examples:**
- nums = [1,2,3,4] → 3 (subtract 1 from 1, add 1 to 2, subtract 1 from 4)
- nums = [3,6,9] → 0

**Constraints:**
- 1 <= nums.length <= 50
- 1 <= nums[i] <= 50

## Approach
Look at the remainder of each number when divided by 3.
- Remainder 0: the number is already divisible by 3, so it needs no operation.
- Remainder 1: subtracting 1 gives a multiple of 3, so it needs exactly 1 operation.
- Remainder 2: adding 1 gives a multiple of 3, so it needs exactly 1 operation.

So every number that is not divisible by 3 costs exactly one operation, and every number that is divisible costs none. The answer is simply the count of elements where nums[i] % 3 != 0.

## Complexity
- **Time:** O(n) - one pass over the array
- **Space:** O(1) - only a counter

## Key Learning
The hint suggests min(r, 3 - r) for each element, where r is the remainder. That formula looks like it needs real work, but since r can only be 1 or 2 when the number is not already divisible, it always evaluates to 1. The cost is the distance to the nearest multiple of 3, and no number is ever more than 1 away from one, because multiples of 3 are spaced only 3 apart. Checking the possible remainders by hand before writing code is what collapses the formula into a simple count.
