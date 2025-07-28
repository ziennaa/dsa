// brute force sol for maximum avg in a given segment
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    double maxavg = -1.0; // max avg found
    int start=-1, end=-1; // best segment 1 based indexing
    for(int i=0; i<n; i++){
        double sum=0;
        for(int j=i; j<n; j++){
            sum += a[j];
            int len = j-i+1;
            // current sub array length
            if(len>=d){
                double avg = sum/len;
                if(avg>maxavg){
                    maxavg = avg;
                    start = i+1;
                    end=j+1;
                }
            }
        }
    }
    cout<<start<<" "<<end<<endl;
    return 0;
}
// TLE HAPPENED
// BRUTE FORCING!!!!!
// TC??? O(n2)
// obviously TLE!!!!
/*
Space Complexity = O(n)
Why?
Because you're only storing the array a of n elements — all other variables are constant in size.*/


// approach prefix sum , tc: o(n2) only
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    //
    vector<ll> prefix(n+1, 0); // n+1 elements all initialsed to 0
    // why n+1 elements?? and not n??
    // prefix[i] stores sum of first i elements of array a
    // to find the sum of elements from l to r 0 based we can simply dp
    // sum=prefix[r+1]-prefix[l]
    for(int i=0; i<n; i++){
        prefix[i+1] = prefix[i] + a[i];
    }
    double maxavg = -1.0; // max avg found
    int start=-1, end=-1; // best segment 1 based indexing
    //for(int i=0; i<n; i++){
    //    double sum=0;
    //    for(int j=i; j<n; j++){
    //        sum += a[j];
    //        int len = j-i+1;
    //        // current sub array length
    //        if(len>=d){
    //            double avg = sum/len;
    //            if(avg>maxavg){
    //                maxavg = avg;
    //                start = i+1;
    //                end=j+1;
    //            }
    //        }
    //    }
    //}
    for(int i=0; i<=n-d; i++){
        // try segments lengths>=d
        for(int len=d; i+len<=n; len++){
            long long sum = prefix[i+len]-prefix[i];
            double avg = (double) sum/len;
            if(avg>maxavg){
                maxavg = avg;
                start=i+1;
                end=i+len;
            }
        }
    }
    cout<<start<<" "<<end<<endl;
    return 0;
}

// tle again!!!!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, d;
vector<int> a;

// returns true if there exists a subarray of length ≥ d with average ≥ mid
// and writes its [start…end] (1‑based) into start/end
bool check(double mid, int &start, int &end) {
    vector<double> prefix(n+1, 0.0);
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + (a[i] - mid);
    }

    double minprefix = prefix[0];
    int best = 0;
    for (int i = d; i <= n; i++) {
        if (prefix[i] - minprefix >= 0) {
            start = best + 1;
            end   = i;
            return true;
        }
        if (prefix[i-d] < minprefix) {
            minprefix = prefix[i-d];
            best = i - d;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double low = 0.0, high = 1e6, mid;
    int astart = -1, aend = -1;

    // binary search for the maximum average
    while (high - low > 1e-7) {
        mid = (low + high) / 2.0;
        int s, e;
        if (check(mid, s, e)) {
            low = mid;
            astart = s;
            aend   = e;
        } else {
            high = mid;
        }
    }

    // final check at 'low' to ensure indices even if max_avg == 0
    {
        int s, e;
        check(low, s, e);
        astart = s;
        aend   = e;
    }

    cout << astart << " " << aend << "\n";
    return 0;
}


//chatgpt sol
//this alos
// approach binary seach o(nlogn)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d;
vector<int> a;
bool check(double mid, int &start, int &end){
    vector<double> prefix(n+1, 0.0);
    for(int i=0; i<n; i++){
        prefix[i+1] = prefix[i] + (a[i]-mid);
        // prefix sum of first i elements in modified array a[i]-mid
        // checking if subarray of length>=d whose sum>=0
        // minprefix minimum value of prefix[j] seen so for where j<=i-d
        // prefix[i]-minprefix>=0 we dound a valid subarray
        // whenever we update minprefix we save best = j which is the index such that
        // prefix[j] = minprefix 
        // start = best+1;
        // end=i;
        // gives actua; subarray start and end indices
    }
    double minprefix = prefix[0];
    int best=0;
    for(int i=d; i<=n; i++){
        if(prefix[i]-minprefix>=0){
            start = best+1;
            end=i;
            return true;
        }
        if(prefix[i-d]<minprefix){
            minprefix = prefix[i-d];
            best = i-d;
        }
    }
    return false;
}
int main(){
    //int n, d;
    cin>>n>>d;
    //vector<int> a(n);
    a.resize(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    double low=0.0;
    double high=1e6;
    double mid;
    int astart=-1; 
    int aend=-1;
    while(high-low>1e-7){
        mid = (low+high)/2.0;
        int start = -1, end=-1;
        if(check(mid, start, end)){
            low = mid;
            astart = start;
            aend = end;
        }else{
            high = mid;
        }
    }
    cout << fixed << setprecision(10);
    cout<<astart<<" "<<aend<<endl;
    return 0;
}
/*
array of n elements
a number d which is the minimum length of a subarray
your goal is to find a subarray of atleast length d that gives max avg

mid = (low+high)/2 is our guess at max avg
we then check if there exists a subarray of length atleast d whose avg is greater or equal to mid

convert array a into modified array by doing a[i]-mid
subarray of length at least d. whose sum >=0 in this new array then it means the 
average in original array is >=mid

why're doing &start and &end
pass by reference
so inside check we can modify start and end 
and the main function will get updated with new value of start and end after check() return


start and end are temp variables returned by check() function
if check(mid) sujccessful we store these values in astart and aend ehich will be our final result
*/
