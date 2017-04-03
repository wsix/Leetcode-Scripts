class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int occur[256];
        for (auto &num : occur)
            num = -1;
        int count = 0, start = -1;
        for (int i=0; i < s.size(); i++) {
            if (occur[s[i]] > start)
                start = occur[s[i]];
            occur[s[i]] = i;
            count = max(count, i - start);
        }
        return count;
    }
};
