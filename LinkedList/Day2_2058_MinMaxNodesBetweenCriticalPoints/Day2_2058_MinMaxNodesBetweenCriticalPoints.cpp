/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head -> next;

        int currCPposn = 1;
        int prevCPposn = 0;
        int firstCPposn = 0;

        int minDist = INT_MAX;

        while (curr -> next != NULL) {
            if ( (curr -> val < curr -> next -> val && curr -> val < prev -> val) ||
                (curr -> val > curr -> next -> val && curr -> val > prev -> val) ) {
                    if (prevCPposn == 0) {
                        prevCPposn = currCPposn;
                        firstCPposn = currCPposn;
                    }
                    else {
                        minDist = min(minDist, currCPposn - prevCPposn);
                        prevCPposn = currCPposn;
                    }

                }
                currCPposn++;
                prev = curr;
                curr = curr -> next;
        }
        if (minDist == INT_MAX)
            return {-1, -1};
        return {minDist, prevCPposn - firstCPposn};
        
    }
};
