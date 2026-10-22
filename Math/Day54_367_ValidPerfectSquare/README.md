# 367. Valid Perfect Square

🔗 [View on LeetCode](https://leetcode.com/problems/valid-perfect-square/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 54

## Problem
Given a positive integer num, return true if num is a perfect square, or false otherwise. A perfect square is the product of some integer with itself. Built-in library functions such as sqrt must not be used.

**Examples:**
- num = 16 → true (4 * 4 = 16)
- num = 14 → false (no integer multiplied by itself gives 14)

**Constraints:**
- 1 <= num <= 2^31 - 1

## Approach
Try every integer i starting from 0 and compute i * i. If it equals num, num is a perfect square. If i * i grows past num without ever matching, no integer can work, since the squares only keep increasing, so the answer is false.

The products are computed with 1LL * i * i so they are done in 64-bit arithmetic. For num close to 2^31 - 1, the loop reaches i = 46341, and 46341 * 46341 is larger than the maximum value of a 32-bit int, so a plain int multiplication would overflow.

## Complexity
- **Time:** O(sqrt(num)) - the loop stops once i * i exceeds num, which is at most about 46341 iterations for the largest input
- **Space:** O(1) - only the loop variable is used

## Key Learning
The linear scan is simple and fast enough here, but binary search on the answer is the cleaner approach: search i between 1 and num, compare i * i with num, and move left or right, which brings the time down to O(log num). Newton's method is another option and converges even faster. In every version, the overflow detail matters: the multiplication has to be done in a 64-bit type, because the square of a number near sqrt(2^31) crosses the 32-bit limit.
