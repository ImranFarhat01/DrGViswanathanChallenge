class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);
        if (start > end)
            return 0;
        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};
        int m1 = stoi(start.substr(0, 2));
        int d1 = stoi(start.substr(3, 2));
        int m2 = stoi(end.substr(0, 2));
        int d2 = stoi(end.substr(3, 2));
        for (int i = 0; i < m1 - 1; i++)
            d1 += days[i];
        for (int i = 0; i < m2 - 1; i++)
            d2 += days[i];
        return d2 - d1 + 1;
    }
};