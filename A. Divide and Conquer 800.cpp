/*
if sum of array even in first case itself print 0
now if odd, then any one number has to perform the function ai/2 and that should be the minimum number 
ig
and check sum everytime after doing operation
maintain a count for how many times weve to do the operations
and sum to check if sum is even

this is brute forcing and its not effecient at all!*/
#include <bits/stdc++.h>
using namespace std;
int steps_to_flip(int x) {
    int steps = 0;
    int original_parity = x % 2;
    while ((x % 2) == original_parity) {
        x /= 2;
        steps++;
    }
    return steps;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int sum = accumulate(a.begin(), a.end(), 0);
        if(sum%2==0){
            cout<<0<<endl;
            continue;
        }
        int minn=INT_MAX;
        for(int i=0; i<a.size(); i++){
            minn = min(minn, steps_to_flip(a[i]));
        }
        cout<<minn<<endl;
    }
}


/*
IF SUM EVEN FIRST PRINT 0
IF ODD
THEN SET UP A NUMBER
WE FIND MIN OF THE STEPS TO FLIP FOR EACH NUMBER */
