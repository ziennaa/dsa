class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> c= nums1;
        c.insert(c.end(), nums2.begin(), nums2.end());
        sort(c.begin(), c.end());
        int n = c.size();
        if(n%2!=0){
            return c[n/2];
        }else{
            int h = float(n);
            return float((c[(h/2.0)-1]) + c[h/2.0])/2.0;
        }
    }
};

// not optimal question clearly says tc should be OlogOn+m)
// and here it is O(n+m)log(n+m);
