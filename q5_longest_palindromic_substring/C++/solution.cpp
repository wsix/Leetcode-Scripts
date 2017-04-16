Class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int start = 0, max_len = 1;
        for (int i = 0; i < s.size(); ) {
            if (s.size() - i <= max_len / 2) break;
            int j = i, k = i;
            while (k < s.size() && s[k] == s[k+1]) k++;
            i = k + 1;
            while (k < s.size() && j > 0 && s[k+1] == s[j-1]) {
                k++; j--;
            }
            int new_len = k - j + 1;
            if (new_len > max_len) {
                start = j;
                max_len = new_len;
            }
        }

        return s.substr(start, max_len);
    }
}
