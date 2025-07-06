class Solution {
public:
    int arrangeCoins(int n) {
        long long r = 1;
        while((r*(r+1))/2<=n){
            r++;
        }
        return r-1;
    }
};
// r*(r+1)/2 formula for calculating the no of coins till a row r
// do optimal sol  above not optimal

optimal 
class Solution {
public:
    int arrangeCoins(int n) {
        long long left=1;
        long long right=n;
        long long mid=0;
        long long curr=0;
        while(left<=right){
            mid=left+(right-left)/2;
            curr=mid*(mid+1)/2;
            if(curr==n) return mid;
            else if(curr>n) right=mid-1;
            else left=mid+1;
        }
        return right;
    }
};
