class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        int cntLeft = 0;
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                cntLeft++;
                ans[i] = cntLeft % 2;
                st.push(ans[i]);
            }
            else {
                int temp = st.top();
                st.pop();
                ans[i] = temp;
                cntLeft--;
            }
        }
        return ans;
    }
};