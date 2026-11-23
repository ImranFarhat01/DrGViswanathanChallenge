\# 2798. Number of Employees Who Met the Target



🔗 \[View on LeetCode](https://leetcode.com/problems/number-of-employees-who-met-the-target/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 85



\## Problem

There are n employees numbered from 0 to n - 1, and employee i has worked hours\[i] hours. The company requires every employee to work at least target hours. Given the array hours and the integer target, return the number of employees who worked at least target hours.



\*\*Examples:\*\*

\- hours = \[0,1,2,3,4], target = 2 → 3 (employees 2, 3 and 4 met the target)

\- hours = \[5,1,4,2,2], target = 6 → 0



\*\*Constraints:\*\*

\- 1 <= n == hours.length <= 50

\- 0 <= hours\[i], target <= 10^5



\## Approach

Go through the array once and count every employee whose hours are greater than or equal to the target. The comparison uses >= because working exactly target hours counts as meeting the target, which is the detail the first example checks (employee 2 worked exactly 2 hours).



\## Complexity

\- \*\*Time:\*\* O(n) - one pass over the array

\- \*\*Space:\*\* O(1) - only a counter



\## Key Learning

The only trap is the boundary: "at least target" means >= and not >. The same count can be written in one line with the standard library as count\_if(hours.begin(), hours.end(), \[\&](int h) { return h >= target; }), which reads closer to the problem statement. A sorted array would let binary search find the first qualifying employee in O(log n), but sorting costs more than the single pass, so the plain loop is the right choice for a one-time count.

