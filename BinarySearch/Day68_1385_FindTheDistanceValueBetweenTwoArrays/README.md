\# 1385. Find the Distance Value Between Two Arrays



🔗 \[View on LeetCode](https://leetcode.com/problems/find-the-distance-value-between-two-arrays/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 68



\## Problem

Given two integer arrays arr1 and arr2 and an integer d, return the distance value between the two arrays. The distance value is the number of elements arr1\[i] for which there is no element arr2\[j] such that |arr1\[i] - arr2\[j]| <= d.



\*\*Examples:\*\*

\- arr1 = \[4,5,8], arr2 = \[10,9,1,8], d = 2 → 2 (only 4 and 5 have no element of arr2 within distance 2)

\- arr1 = \[1,4,2,3], arr2 = \[-4,-3,6,10,20,30], d = 3 → 2

\- arr1 = \[2,1,100,3], arr2 = \[-5,-2,10,-3,7], d = 6 → 1



\*\*Constraints:\*\*

\- 1 <= arr1.length, arr2.length <= 500

\- -1000 <= arr1\[i], arr2\[j] <= 1000

\- 0 <= d <= 100



\## Approach

An element x of arr1 counts only if every element of arr2 is farther than d from it. That is the same as saying the element of arr2 closest to x is farther than d, so only the nearest neighbors of x matter.



Sort arr2 first. For each x in arr1, use lower\_bound to find j, the first index where arr2\[j] >= x. The closest elements are then arr2\[j] (the nearest one on the right) and arr2\[j - 1] (the nearest one on the left), and the code handles three cases:

\- j == 0: every element of arr2 is on the right, so only arr2\[0] needs to be checked.

\- j == n: every element of arr2 is on the left, so only arr2\[n - 1] needs to be checked.

\- Otherwise: both arr2\[j] and arr2\[j - 1] must be farther than d.



When the nearest neighbors are all farther than d, x is counted.



\## Complexity

\- \*\*Time:\*\* O((n + m) log m), where n = arr1.length and m = arr2.length. Sorting arr2 costs O(m log m), and each of the n lookups costs O(log m)

\- \*\*Space:\*\* O(1) extra, since the sort is done in place on arr2



\## Key Learning

"No element within distance d" sounds like it needs a comparison against every element, but only the closest elements can possibly be within distance d. Sorting turns that into a binary search problem: lower\_bound finds the insertion point, and the two elements around it are the only candidates. The brute force version with two nested loops is O(n \* m), which is also fast enough here because both arrays have at most 500 elements, so this problem is a good place to practice the faster pattern even though it is not strictly required.

