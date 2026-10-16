# 509. Fibonacci Number

🔗 [View on LeetCode](https://leetcode.com/problems/fibonacci-number/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 48

## Problem
The Fibonacci numbers F(n) form a sequence where each number is the sum of the two before it, starting from F(0) = 0 and F(1) = 1. Given n, return F(n).

**Examples:**
- n = 2 → 1 (F(2) = F(1) + F(0) = 1 + 0)
- n = 3 → 2
- n = 4 → 3

**Constraints:**
- 0 <= n <= 30

## Approach
The plain recursive definition recomputes the same values again and again and takes exponential time. Since each value only depends on the two before it, there is no need to store the whole sequence. Keep just two variables, a and b, holding the previous two Fibonacci numbers, and slide them forward one step at a time.

Start with a = F(0) = 0 and b = F(1) = 1. In each iteration, compute c = a + b, then shift: a takes the old value of b, and b takes c. After n iterations, a holds F(n). The cases n = 0 and n = 1 are returned directly.

## Complexity
- **Time:** O(n) - one loop that runs n times
- **Space:** O(1) - only three integer variables

## Key Learning
This is the simplest example of space optimization in dynamic programming: when a state depends only on the last few states, the full table can be replaced by a few rolling variables. The loop here runs n times, so b ends up holding F(n + 1) and a holds F(n), which is why a is returned. Even for n = 30, b only reaches F(31) = 1346269, so int never overflows. Other approaches for comparison: plain recursion is O(2^n), memoization brings it to O(n) time and O(n) space, and matrix exponentiation or fast doubling reaches O(log n).
