class Solution {
public:
    bool checkEqual(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return 0;
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {0};

        for (int i = 0; i < s1.length(); i++) {
            arr1[s1[i] - 'a']++;
        }

        int i = 0;
        int windowSize = s1.length();
        int arr2[26] = {0};

        if (s1.length() > s2.length())
            return 0;

        while (i < windowSize) {
            arr2[s2[i] - 'a']++;
            i++;
        }
        if (checkEqual(arr1, arr2))
            return 1;

        while (i < s2.length()) {
            char newChar = s2[i];
            arr2[newChar - 'a']++;
            char oldChar = s2[i - windowSize];
            arr2[oldChar - 'a']--;

            i++;

            if (checkEqual(arr1, arr2))
                return 1;
        }
        return 0;
    }
};