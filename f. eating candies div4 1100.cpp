#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        ll leftcount=0;
        ll rightcount=0;
        ll count=0;
        for(int i=0; i<n; i++){
            leftcount += a[i];
            rightcount += a[n-i-1];
            count+=2;
            if (leftcount == rightcount){
                break;
            }
        }
        cout<<count<<endl;
    }
}

// wrong clearly
// its only taking the case of when the first match happens and then stops which is wrong!!!
// not returning the maximum
// question says largestno of candies
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        ll leftcount=0;
        ll rightcount=0;
        ll l=0, r=n-1;
        ll count=0;
        while(l<=r){
            if(leftcount<rightcount){
                leftcount += a[l++];
            }else if(rightcount<leftcount){
                rightcount += a[r--];
            }else{
                count = l + (n-r-1);
                leftcount += a[l++];
            }
        }
        cout<<count<<endl;
    }
}

// did this but testrcase not matching
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        ll leftcount=0;
        ll rightcount=0;
        ll l=0, r=n-1;
        ll count=0;
        while(l<=r){
            if(leftcount==rightcount){
                count = l+(n-r-1);
            }
            if(leftcount<=rightcount){
                leftcount += a[l++];
            }else{
                rightcount += a[r--];
            }
        }
        cout<<count<<endl;
    }
}
// this too fails no difference

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        ll leftcount=a[0];
        ll rightcount=a[n-1];
        ll l=0, r=n-1;
        ll count=0;
        while(l<=r){
            if(leftcount==rightcount){
                count = max(count, (l+1+n-r));
            }
            if(leftcount<=rightcount){
                l++;
                leftcount += a[l];
            }else{
                r--;
                rightcount += a[r--];
            }
        }
        cout<<count<<endl;
    }
}

// fails on some testcase
// here l<=r but !!! They must not eat the same candy.
// still got error after correcting yk why
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        ll leftcount=a[0];
        ll rightcount=a[n-1];
        ll l=0, r=n-1;
        ll count=0;
        while(l<r){
            if(leftcount==rightcount){
                count = max(count, (l+1+n-r));
            }
            if(leftcount<=rightcount){
                l++;
                leftcount += a[l];
            }else{
                r--;
                rightcount += a[r--];// error!!!!!
            }
        }
        cout<<count<<endl;
    }
}
// cux here you did not fix 
