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

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = (n+m+1)/2 - cut1;
            int l1=(cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if (l1 > r2){
                high = cut1 - 1;
            }
            else{
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

//works and tc is correct acc to question now
