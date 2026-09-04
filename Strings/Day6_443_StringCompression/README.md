# 443. String Compression

🔗 [View on LeetCode](https://leetcode.com/problems/string-compression/)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 6

## Problem

Given an array of characters `chars`, compress it in place:

- For each group of consecutive repeating characters, write the character.
- If the group length is greater than `1`, append the group's length.
- If the group length is `1`, write only the character.
- Group lengths of `10` or more are represented using multiple digits.
- Return the new length of the compressed array.
- The compression must be done **in-place**.

### Examples

**Example 1:**

    Input:  chars = ["a","a","b","b","c","c","c"]
    Output: 6
    chars becomes ["a","2","b","2","c","3"]

**Example 2:**

    Input:  chars = ["a"]
    Output: 1
    chars remains ["a"]

**Example 3:**

    Input:  chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    Output: 4
    chars becomes ["a","b","1","2"]

## Constraints

- `1 <= chars.length <= 2000`
- `chars[i]` is a lowercase English letter, uppercase English letter, digit, or symbol.

## Approach

Walk through `chars` once and count how many times each character repeats consecutively.

Whenever a different character is encountered:

1. Write the previous character to the result.
2. If its count is greater than `1`, write the count as digits.
3. Move to the next group.

After the loop ends, handle the **final group separately**, because there is no next character to trigger the group-processing condition.

In this implementation, a separate result string is used to store the compressed result. Finally, copy the compressed result back into the original `chars` array.

> **Important:** A count of `1` should **not** be written. For example, `"a"` remains `"a"`, not `"a1"`.

## Complexity

- **Time:** `O(n)`
  - One pass to process the groups.
  - One additional pass to copy the compressed result back into `chars`.
- **Space:** `O(n)`
  - The intermediate result string can contain up to `n` characters.

> **Note:** The problem officially requires `O(1)` extra space. Therefore, using a separate result string does **not** satisfy the strict in-place requirement. An optimal solution should write directly into `chars` using read/write pointers.

## Key Learning

The trickiest part is handling the **last group**.

The loop processes a group when it detects that the **next character is different**. But for the final group, there is no next character, so that condition never occurs.

Therefore, the final group must be processed **after the loop**.

### Main Idea

    Count consecutive characters
            ↓
    Character changes?
            ↓
    Write character + count (if count > 1)
            ↓
    Process final group
            ↓
    Return compressed length
