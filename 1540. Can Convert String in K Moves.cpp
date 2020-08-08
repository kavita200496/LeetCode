class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        unordered_map<int, int> mp;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
           if (s[i] == t[i]) continue;
            int diff = t[i]-s[i] < 0 ? 26 + t[i]-s[i] : t[i]-s[i];
            count = max(count, (mp[diff]*26)+diff);
           // cout<<count<<" ";
            mp[diff]++;
            if (count > k) return false;
        }
        return count <= k;
    }
};
