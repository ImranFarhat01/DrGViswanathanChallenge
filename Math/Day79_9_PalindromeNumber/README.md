# 9. Palindrome Number

🔗 [View on LeetCode](https://leetcode.com/problems/palindrome-number/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 79

## Problem
Given an integer x, return true if x is a palindrome (it reads the same from left to right and from right to left), and false otherwise.

**Examples:**
- x = 121 → true
- x = -121 → false (it reads 121- from right to left)
- x = 10 → false (it reads 01 from right to left)

**Constraints:**
- -2^31 <= x <= 2^31 - 1

**Follow-up:** Can it be solved without converting the integer to a string?

## Approach
A negative number is never a palindrome because of its minus sign, so return false right away. For everything else, build the reverse of the number digit by digit: take the last digit with % 10, append it to the reversed number with rev * 10 + digit, and drop it from the original with / 10. When no digits are left, the number is a palindrome exactly when its reverse equals the original.

Edge cases work out on their own. For x = 0 the loop never runs, rev stays 0, and 0 == 0 gives true. For x = 10 the reverse is 1, which is not 10, so the answer is false, and the same logic rejects every positive number that ends in 0 (except 0 itself).

## Complexity
- **Time:** O(log x) - one step per digit, at most 10 digits for a 32-bit integer
- **Space:** O(1) - only a few variables, and no string conversion

## Key Learning
The reverse of a 10 digit number can be larger than the int range (for example, the reverse of 1999999999 is 9999999991), so rev is stored in a long long. Writing 1LL * rev * 10 is not enough on its own, because the result still gets stored back into an int variable and the extra width is lost. A different way to avoid the problem is to reverse only half of the number: keep moving digits from x into rev until rev is no longer smaller than what is left of x, then compare the two halves. That never overflows, and it needs a separate check for numbers that end in 0, which can never be palindromes unless they are 0.
