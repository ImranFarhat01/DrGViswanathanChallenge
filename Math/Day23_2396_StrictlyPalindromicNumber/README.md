# 2396. Strictly Palindromic Number

🔗 [View on LeetCode](https://leetcode.com/problems/strictly-palindromic-number/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 23

## Problem
An integer n is strictly palindromic if, for every base b between 2 and n-2 inclusive, the representation of n in base b is a palindrome. Given n, return true if n is strictly palindromic, false otherwise.

**Examples:**
- n = 9 → false (in base 3, 9 = "100", not a palindrome)
- n = 4 → false (in base 2, 4 = "100", not a palindrome)

**Constraints:**
- 4 <= n <= 10^5

**Hints given:**
- Consider the representation of n in base n-2.
- n in base n-2 is always "12", which is never palindromic.

## Approach
This problem has a purely mathematical shortcut hidden in the constraints. Any integer n can be written as n = 1*(n-2) + 2 for n >= 4, meaning n's representation in base (n-2) is always the two digits "1" followed by "2", i.e., "12". Since "12" reversed is "21", it's never a palindrome (as long as n >= 4, which the constraints guarantee). Since base n-2 always falls within the required range [2, n-2] for n >= 4, this single base is always checked, and it always fails. Therefore, no integer n >= 4 can ever be strictly palindromic, so the function can simply return false unconditionally, no actual base conversion or loop needed.

## Complexity
- **Time:** O(1) - no computation needed at all
- **Space:** O(1) - no extra data structures used

## Key Learning
Sometimes a problem that looks like it needs simulation across many bases has a mathematical proof hiding underneath that eliminates the need for any computation whatsoever. The given hints pointed directly at this: showing that base n-2 always produces "12" (a guaranteed non-palindrome) proves the answer is always false for every valid n in the constraint range, turning what looks like an O(n log n) or worse simulation problem into a trivial O(1) return statement.
