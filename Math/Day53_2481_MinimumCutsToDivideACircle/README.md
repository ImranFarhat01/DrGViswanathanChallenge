\# 2481. Minimum Cuts to Divide a Circle



🔗 \[View on LeetCode](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 53



\## Problem

A valid cut is a straight line that either touches two points on the edge of the circle and passes through its center (a full diameter), or touches one point on the edge and the center (a single radius). Given n, return the minimum number of cuts needed to divide the circle into n equal slices.



\*\*Examples:\*\*

\- n = 4 → 2 (two diameter cuts make 4 equal slices)

\- n = 3 → 3 (three radius cuts are needed for 3 equal slices)



\*\*Constraints:\*\*

\- 1 <= n <= 100



\## Approach

Handle the three cases separately.



\- \*\*n = 1:\*\* The circle is already one slice, so no cut is needed. The answer is 0.

\- \*\*n is even:\*\* One diameter cut creates 2 slices, so each diameter gives two slices at once. The answer is n / 2.

\- \*\*n is odd (and greater than 1):\*\* A diameter cut always splits the circle into two halves of equal area, and with equal slices that would force an even total. So an odd count cannot use diameters, and every slice boundary needs its own radius cut. The answer is n.



\## Complexity

\- \*\*Time:\*\* O(1) - a couple of comparisons

\- \*\*Space:\*\* O(1) - no extra memory used



\## Key Learning

The logic is simple, but the edge case n = 1 is easy to miss and is the reason this problem has a low acceptance rate for an easy problem. The odd case would return 1 for n = 1, but the correct answer is 0 because the circle needs no cut at all. Reading the constraints (1 <= n) before writing code is what points to that boundary. The order of the checks in the code works because n = 1 is odd, so it skips the even branch and reaches the n == 1 check before the general odd case.

