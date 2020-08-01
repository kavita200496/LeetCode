class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<long> vec(n);
        
        for (int i = 0; i < n; i++) {
            int mask = 0;
            for (auto c:words[i])
                mask |= (1<<(c-'a'));
            vec[i] = mask;
        }
        
        int ans = 0;
        
        for (int i = 1;i < n; i++) {
            for (int j = 0; j <i; j++) {
                int im = vec[i], jm = vec[j], flag = 1;
                for (int k = 0; k < 26; k++) {
                    if ((im & (1<<k)) && (jm & (1<<k))) {
                        flag = 0; break;
                    }
                }
                if (flag)
                    ans = max(ans, (int)words[i].size()*(int)words[j].size());
            }
        }
        return ans;
    }
};
