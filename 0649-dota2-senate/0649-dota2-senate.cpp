class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int n = senate.size();

        // Fill queues with the indices of Radiant (R) and Dire (D) senators
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        // Process bans in rounds
        while (!r.empty() && !d.empty()) {
            int r_idx = r.front(), d_idx = d.front();
            r.pop(), d.pop();

            // The senator with the lower index bans the other
            if (r_idx < d_idx)
                r.push(r_idx + n);
            else
                d.push(d_idx + n);
        }

        return r.empty() ? "Dire" : "Radiant";
    }
};
