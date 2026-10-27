\# 3963. Create Grid With Exactly One Path



🔗 \[View on LeetCode](https://leetcode.com/problems/create-grid-with-exactly-one-path/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 59



\## Problem

Given m and n, construct any m x n grid made of '.' (free cell) and '#' (obstacle) such that there is exactly one valid path from the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1), moving only right or down through free cells. Any grid that satisfies this is accepted.



\*\*Examples:\*\*

\- m = 2, n = 3 → \["..#","#.."] (one valid answer, the only path is (0,0) → (0,1) → (1,1) → (1,2))

\- m = 3, n = 3 → \["..#","#..","##."]

\- m = 1, n = 4 → \["...."]



\*\*Constraints:\*\*

\- 1 <= m, n <= 25



\## Approach

It is enough to keep one simple route free and block every other cell. Choose the route that goes all the way down the first column and then all the way right along the last row. Mark a cell as free when it is in the last row (i == m - 1) or in the first column (j == 0), and mark every other cell as an obstacle.



Since the only moves are right and down, any path from the top-left corner has to leave the first column at some row, and every cell it could step into outside the first column and last row is blocked. The only row where it can move right is the last one, so exactly one path exists.



\## Complexity

\- \*\*Time:\*\* O(m \* n) - every cell of the grid is built once

\- \*\*Space:\*\* O(m \* n) - for the output grid



\## Key Learning

For "construct any valid answer" problems, pick the simplest shape that clearly satisfies the rule instead of searching for one. An L shape works because the movement is restricted to right and down, which leaves no room for alternative routes. The edge cases work out without special handling: when m = 1 the only row is the last row, and when n = 1 the only column is the first column, so the whole grid becomes free, which is correct. Also note that the output can differ from the sample (this solution gives \[".##","..."] for m = 2, n = 3) and still be accepted, because the problem allows any valid grid.

