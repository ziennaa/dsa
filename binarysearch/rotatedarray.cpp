#include <bits/stdc++.h>
using namespace std;
int checker(vector<int>& a, int mid){
    if(mid == a.size()-1) return 1;
    return (a[mid] > a[mid+1]) ? 1: 0;
}
int PeakIndex(vector<int>& a){
    int n = a.size();
    int low = 0;
    int high = n-1;
    int ans = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(checker(a, mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}
int binsearch_asc(vector<int>& a, int l, int r, int k){
    while(l<=r){
        int m = l+(r-l)/2;
        if(a[m] == k) return m;
        if(a[m] < k) l = m+1;
        else r = m-1;
    }
    return -1;
}
int binsearch_desc(vector<int>& a, int l, int r, int k){
    while(l<=r){
        int m = l+(r-l)/2;
        if(a[m] == k) return m;
        if(a[m] > k) l = m+1;
        else r = m-1;
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        int peak = PeakIndex(a);
        while(q--){
            int k;
            cin>>k;
            int left = binsearch_asc(a, 0, peak, k);
            int right = binsearch_desc(a, peak+1, n-1, k);
            if (left != -1 && right != -1){
                cout << (left + 1) << ' ' << (right + 1) << '\n';
            }
            else if (left != -1){
                cout << (left + 1) << '\n';
            }
            else{
                cout << (right + 1) << '\n';
            }
        }
    }
}