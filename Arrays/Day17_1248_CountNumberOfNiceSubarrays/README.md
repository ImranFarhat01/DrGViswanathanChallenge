\# 1248. Count Number of Nice Subarrays



🔗 \[View on LeetCode](https://leetcode.com/problems/count-number-of-nice-subarrays/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Medium

\- \*\*Day:\*\* 17



\## Problem

Given an array of integers nums and an integer k, a continuous subarray is called nice if it contains exactly k odd numbers. Return the number of nice subarrays.



\*\*Examples:\*\*

\- nums = \[1,1,2,1,1], k = 3 → 2

\- nums = \[2,4,6], k = 1 → 0 (no odd numbers at all)

\- nums = \[2,2,2,1,2,2,1,2,2,2], k = 2 → 16



\*\*Constraints:\*\*

\- 1 <= nums.length <= 50000

\- 1 <= nums\[i] <= 10^5

\- 1 <= k <= nums.length



\## Approach

Directly counting subarrays with exactly k odd numbers is tricky with a sliding window, since a window's odd count can jump around as it expands and shrinks. Instead, reduce "exactly k" to a difference of two easier subproblems: count subarrays with at most k odd numbers, and subtract subarrays with at most k-1 odd numbers. The difference gives exactly the subarrays with exactly k odd numbers.



The atMost() helper uses a standard sliding window: expand the window with r, tracking the running count of odd numbers (sum). Whenever sum exceeds k, shrink from the left until it's valid again. At each valid window, r - l + 1 gives the number of subarrays ending at r with at most k odd numbers, which gets added to the total.



\## Complexity

\- \*\*Time:\*\* O(n) - atMost() itself is O(n) since l only moves forward, and it's called twice

\- \*\*Space:\*\* O(1) - only a few counters used



\## Key Learning

"Exactly k" is often harder to handle directly in a sliding window than "at most k," because a window satisfying an exact count doesn't shrink or grow monotonically in an easy way. Converting "exactly k" into atMost(k) - atMost(k-1) is a reusable trick: at most k is monotonic (adding elements can only increase or keep the odd count), making the standard sliding window technique directly applicable.

