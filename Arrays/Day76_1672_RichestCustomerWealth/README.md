# 1672. Richest Customer Wealth

🔗 [View on LeetCode](https://leetcode.com/problems/richest-customer-wealth/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 76

## Problem
Given an m x n integer grid accounts, where accounts[i][j] is the amount of money the i-th customer has in the j-th bank, return the wealth of the richest customer. A customer's wealth is the total amount of money across all of their bank accounts.

**Examples:**
- accounts = [[1,2,3],[3,2,1]] → 6 (both customers have wealth 6)
- accounts = [[1,5],[7,3],[3,5]] → 10 (the second customer has 7 + 3)
- accounts = [[2,8,7],[7,1,3],[1,9,5]] → 17

**Constraints:**
- m == accounts.length
- n == accounts[i].length
- 1 <= m, n <= 50
- 1 <= accounts[i][j] <= 100

## Approach
Each row is one customer, so a customer's wealth is the sum of their row. Go through the rows one by one, add up each row's values, and after finishing a row compare its total with the best total seen so far, keeping the larger one. The best total after the last row is the answer.

## Complexity
- **Time:** O(m * n) - every cell of the grid is read once
- **Space:** O(1) - only a running row total and a running maximum

## Key Learning
The problem is "maximum of row sums". The comparison belongs after the inner loop, once the whole row has been added, because only the full row total is a customer's wealth. Updating the maximum inside the inner loop also gives the right answer here, but only because every value is positive, so partial sums never exceed the final total. Keeping the update outside the loop avoids relying on that and does less work. With at most 50 * 50 cells of value 100, the largest total is 5000, so int is safe.
