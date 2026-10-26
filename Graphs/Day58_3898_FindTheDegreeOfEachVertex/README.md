\# 3898. Find the Degree of Each Vertex



🔗 \[View on LeetCode](https://leetcode.com/problems/find-the-degree-of-each-vertex/)



\- \*\*Platform:\*\* LeetCode

\- \*\*Difficulty:\*\* Easy

\- \*\*Day:\*\* 58



\## Problem

Given an n x n adjacency matrix of an undirected graph with vertices labeled 0 to n - 1, where matrix\[i]\[j] = 1 means there is an edge between i and j and 0 means there is none, return an array ans where ans\[i] is the degree of vertex i (the number of edges connected to it).



\*\*Examples:\*\*

\- matrix = \[\[0,1,1],\[1,0,1],\[1,1,0]] → \[2,2,2]

\- matrix = \[\[0,1,0],\[1,0,0],\[0,0,0]] → \[1,1,0]

\- matrix = \[\[0]] → \[0]



\*\*Constraints:\*\*

\- 1 <= n == matrix.length == matrix\[i].length <= 100

\- matrix\[i]\[i] == 0

\- matrix\[i]\[j] is either 0 or 1

\- matrix\[i]\[j] == matrix\[j]\[i]



\## Approach

In an adjacency matrix, row i marks every vertex that vertex i is connected to, so the degree of vertex i is just the sum of row i. Go through each row, add up its entries, and push the total into the answer array.



\## Complexity

\- \*\*Time:\*\* O(n^2) - every cell of the matrix is read once

\- \*\*Space:\*\* O(1) extra - only the output array is created



\## Key Learning

The representation of a graph decides how a question is answered. With an adjacency matrix, the degree is a row sum and costs O(n) per vertex. With an adjacency list, the degree would be the size of the list, available in O(1). Because the graph is undirected, the matrix is symmetric, so a column sum would give the same answer. The diagonal is always 0, so there are no self-loops to worry about, which is why a plain row sum is exactly right.

