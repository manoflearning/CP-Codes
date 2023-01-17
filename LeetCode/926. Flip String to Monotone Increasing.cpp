class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt0 += s[i] == '0';
        }

        int ans = cnt0 + cnt1;
        for (int i = 0; i < s.size(); i++) {
            cnt0 -= s[i] == '0';
            cnt1 += s[i] == '1';
            ans = min(ans, cnt0 + cnt1);
        }

        return ans;
    }
};