# 3876. Construct Uniform Parity Array II

🔗 [View on LeetCode](https://leetcode.com/problems/construct-uniform-parity-array-ii/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 5

## Problem
Given an array nums1 of n distinct integers, construct another array nums2 of length n such that all elements in nums2 are either all odd or all even. For each index i, either nums2[i] = nums1[i], or nums2[i] = nums1[i] - nums1[j] for some other index j, as long as the result is at least 1. Return true if such an array can be constructed, false otherwise.

**Examples:**
- nums1 = [1,4,7] → true (nums2 = [1,3,7], all odd)
- nums1 = [2,3] → false
- nums1 = [4,6] → true (nums2 = [4,6], all even, no subtraction needed)

**Constraints:**
- 1 <= n == nums1.length <= 10^5
- 1 <= nums1[i] <= 10^9
- nums1 consists of distinct integers

## Approach
The key insight is parity math: subtracting two numbers of the same parity gives an even result, while subtracting two numbers of different parity gives an odd result.

To make every element even: pick the smallest even number in the array as a "base," and for every odd number, subtract the smallest even number from it (odd - even = odd... actually the reverse: subtract an odd number from itself isn't needed, since same-parity elements can just be kept as-is, and different-parity elements need to become the same parity via subtraction).

The simpler working rule: find the minimum odd value and the minimum even value in the array.
- If there are no odd numbers at all, the array is already uniform (all even) → true.
- Otherwise, check whether minEven > minOdd. If the smallest even number is larger than the smallest odd number, every even number can be converted to odd by subtracting the smallest odd number from it (even - odd = odd, and since minEven > minOdd, the result stays >= 1). This makes the whole array uniformly odd.
- If minEven is not greater than minOdd, there's no valid way to unify parity, so return false.

## Complexity
- **Time:** O(n) - single pass to find the minimum odd and minimum even values
- **Space:** O(1) - only two tracking variables used

## Key Learning
Parity problems often reduce to a simple property: subtracting a number of one parity from a number of the other parity always flips the result to odd, while same-parity subtraction always gives even. Once framed this way, the problem becomes about finding the right "anchor" values (the minimums) rather than simulating actual subtractions across the array.
