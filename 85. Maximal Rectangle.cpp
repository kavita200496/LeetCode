class Solution {
public:
    vector<int> nearest_smaller_to_left(vector<int> v, int n) {
        vector<int> left;
        stack<pair<int, int>> s;
        int pseudo_index = -1;
        
        for (int i = 0; i < n; i++) {
            if (s.empty()) left.push_back(pseudo_index);
            else if (!s.empty() && s.top().first < v[i]) left.push_back(s.top().second);
             else if (!s.empty() && s.top().first >= v[i]) {
                 while (!s.empty() && s.top().first >= v[i]) s.pop();
                  if (s.empty()) left.push_back(pseudo_index);
                else  left.push_back(s.top().second);
             }
            s.push({v[i], i});
        }
        return left;
    }
    
    vector<int> nearest_smaller_to_right (vector<int> v, int n) {
        vector<int> left;
        stack<pair<int, int>> s;
        int pseudo_index = n;
        
        for (int i = n-1; i >= 0; i--) {
            if (s.empty()) left.push_back(pseudo_index);
            else if (!s.empty() && s.top().first < v[i]) left.push_back(s.top().second);
             else if (!s.empty() && s.top().first >= v[i]) {
                 while (!s.empty() && s.top().first >= v[i]) s.pop();
                  if (s.empty()) left.push_back(pseudo_index);
                else  left.push_back(s.top().second);
             }
            s.push({v[i], i});
        }
        reverse(left.begin(), left.end());
        return left;
    }
    
    int max_area_in_histogram(vector<int> v, int n) {
        vector<int> left = nearest_smaller_to_left (v, n);
        vector<int> right = nearest_smaller_to_right (v, n);
        
        int maxi = 0;
        
      /*  for (int i = 0; i < n; i++) {
            cout<<left[i]<<" ";
        }
        cout<<endl;*/
        for (int i = 0; i < n; i++) {
            int width = right[i]-left[i]-1;
            maxi = max(maxi, width*v[i]);
            //cout<<maxi<<" ";
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        vector<int> v;
        
        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == '0') v.push_back(0);
            else v.push_back(1);
        }
        int max_area = max_area_in_histogram(v, col);
        
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') v[j] = 0;
                else v[j] += 1;
            }
            //cout<<max_area<<" ";
             max_area = max(max_area, max_area_in_histogram(v, col));
        }
        
        return max_area;
    }
};
