# 3516. Find Closest Person

🔗 [View on LeetCode](https://leetcode.com/problems/find-closest-person/)

- **Platform:** LeetCode
- **Difficulty:** Easy
- **Day:** 75

## Problem
Three people stand on a number line at positions x (Person 1), y (Person 2) and z (Person 3, who does not move). Person 1 and Person 2 both walk toward Person 3 at the same speed. Return 1 if Person 1 arrives first, 2 if Person 2 arrives first, and 0 if they arrive at the same time.

**Examples:**
- x = 2, y = 7, z = 4 → 1 (distances 2 and 3)
- x = 2, y = 5, z = 6 → 2 (distances 4 and 1)
- x = 1, y = 5, z = 3 → 0 (distances 2 and 2)

**Constraints:**
- 1 <= x, y, z <= 100

## Approach
Both people move at the same speed, so the one with the shorter distance to Person 3 arrives first. The distance of Person 1 is abs(x - z) and the distance of Person 2 is abs(y - z). Compare the two: if Person 1's distance is smaller, return 1, if Person 2's distance is smaller, return 2, and if they are equal, return 0.

## Complexity
- **Time:** O(1) - a fixed number of comparisons
- **Space:** O(1) - no extra memory

## Key Learning
With equal speeds, arrival time depends only on distance, so the whole problem reduces to comparing two absolute differences. The absolute value is what makes it work no matter which side of Person 3 each person starts on. The two distances can be stored in variables first (int d1 = abs(x - z), d2 = abs(y - z)) so each one is computed only once and the comparisons read more clearly.
