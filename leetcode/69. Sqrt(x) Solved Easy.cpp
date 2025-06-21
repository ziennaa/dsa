class Solution {
public:
    int mySqrt(long long x) {
        long long low = 1;
        long long high = x;
        long long found = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mid <= x / mid) { 
                found = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return found;
    }
};
