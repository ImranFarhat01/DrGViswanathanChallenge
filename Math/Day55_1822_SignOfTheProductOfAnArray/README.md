# 1822. Sign of the Product of an Array

🔗 [View on LeetCode](https://leetcode.com/problems/sign-of-the-product-of-an-array/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 55

## Problem
Define signFunc(x) as 1 if x is positive, -1 if x is negative, and 0 if x is zero. Given an integer array nums, let product be the product of all its values. Return signFunc(product).

**Examples:**
- nums = [-1,-2,-3,-4,3,2,1] → 1 (the product is 144)
- nums = [1,5,0,2,-3] → 0 (a zero makes the whole product zero)
- nums = [-1,1,-1,1,-1] → -1

**Constraints:**
- 1 <= nums.length <= 1000
- -100 <= nums[i] <= 100

## Approach
The actual product is never needed, only its sign. A single zero makes the product zero, so return 0 immediately when one is found. Otherwise, the sign depends only on how many negative numbers there are: an even count gives a positive product and an odd count gives a negative one. Track this with a variable that starts at 1 and flips its sign each time a negative number appears. At the end, that variable is exactly the answer.

## Complexity
- **Time:** O(n) - a single pass, which exits early if a zero appears
- **Space:** O(1) - only one integer variable

## Key Learning
Multiplying all the values directly would overflow any integer type, since the product can reach 100^1000. Reducing the problem to what is actually asked (just the sign) avoids the overflow completely and keeps the code short. Whenever a question asks about a property of a huge result, such as its sign, parity or remainder, it is worth checking whether that property can be tracked on its own without computing the result.
