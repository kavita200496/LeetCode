

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
         if (A.size() > B.size()) 
             return findMedianSortedArrays(B, A);
        int x = A.size(), y = B.size();
        int l = 0, h = x;
        
        while (l <= h) {
            int partitionx = (l+h)/2;
            int partitiony = (x+y+1)/2 - partitionx;
            
            int max_leftx = (partitionx == 0)?INT_MIN:A[partitionx - 1];
            int min_rightx = (partitionx == x)?INT_MAX:A[partitionx];
            
            int max_lefty = (partitiony == 0)?INT_MIN:B[partitiony - 1];
            int min_righty = (partitiony == y)?INT_MAX:B[partitiony];
            
            if (max_leftx <= min_righty && max_lefty <= min_rightx) {
                if ((x+y)%2 == 0)
                    return ((double)(max(max_leftx, max_lefty) + min(min_rightx, min_righty)))/2;
                else return max(max_leftx, max_lefty);
            }
            if (max_leftx > min_righty) h = partitionx - 1;
            else l = partitionx + 1;
        }
        return 0.0;
    }
};
