# 2109. Adding Spaces to a String

🔗 [View on LeetCode](https://leetcode.com/problems/adding-spaces-to-a-string)

- **Platform:** LeetCode
- **Difficulty:** Medium
- **Day:** 1

## Problem
You're given a string `s` and an array `spaces` containing indices in the original string. A space must be inserted immediately before the character sitting at each of those indices, and the resulting string is returned.

For example, with `s = "EnjoyYourCoffee"` and `spaces = [5, 9]`, spaces go in before the characters at index 5 (`'Y'`) and index 9 (`'C'`), giving `"Enjoy Your Coffee"`.

**Examples:**
- `s = "LeetcodeHelpsMeLearn"`, `spaces = [8,13,15]` → `"Leetcode Helps Me Learn"`
- `s = "icodeinpython"`, `spaces = [1,5,7,9]` → `"i code in py thon"`
- `s = "spacing"`, `spaces = [0,1,2,3,4,5,6]` → `" s p a c i n g"` (a space can go before the very first character)

**Constraints:**
- 1 <= s.length <= 3 * 10^5
- s consists only of lowercase and uppercase English letters
- 1 <= spaces.length <= 3 * 10^5
- 0 <= spaces[i] <= s.length - 1
- Values in spaces are strictly increasing

## My Approach - Evolution

**First instinct (rejected):** Repeatedly call `insert()` at each target index. Works logically, but every insert shifts all characters after it - with up to 3×10^5 insertions on a 3×10^5-length string, that's O(n×m) in the worst case, way too slow for the constraints.

**Better idea:** Build the output in a single linear pass instead of mutating in place. Walk through `s` and `spaces` together using two pointers - `i` for the string, `j` for the next space position - and insert a space whenever `i` matches `spaces[j]`.

**Bugs hit along the way:**
1. Tried `ans.reserve(...)` followed by direct indexing (`ans[i] = ...`). `reserve()` only bumps capacity, not actual size - `ans` was still logically empty, so indexing into it was undefined behavior.
2. Tried `ans.resize(...)` followed by `ans += ...`. `resize()` actually sets the string's size and fills it with null characters upfront. Appending after that just tacks characters on after those nulls instead of replacing them - corrupting the output.

**Fix - match the tool to the technique:**
- `reserve()` pairs with `+=` (appending)
- `resize()` pairs with direct indexing (`ans[i] = ...`)
- Never mix the two.

## Final Solution

```cpp
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        ans.resize(s.size() + spaces.size());
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                ans[i + j] = ' ';
                j++;
            }
            ans[i + j] = s[i];
        }
        return ans;
    }
};
```

## Complexity
- **Time:** O(n + m) - one pass through s and spaces
- **Space:** O(n + m) - for the output string (unavoidable, it's the return value)

## Key Learning
A correct algorithm can still produce garbage output if the underlying data structure isn't managed the way you think it is. reserve() vs resize() looks like a minor detail, but mixing them silently breaks correctness - worth understanding exactly what your tools do, not just what they're named.
