#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2!=0){
            for(int i=1; i<=n; i+=2){
                cout<<i<<" ";
            }
            for(int i=n-1; i>0; i-=2){
                cout<<i<<" ";
            }
        }else{
            for(int i=2; i<=n; i+=2){
                cout<<i<<" ";
            }
            for(int i=n-1; i>0; i-=2){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}

// /* QUESTION TEST CASE EXAMPLE
/*Note
In the first test case:

We choose p=[1,3,2]
.
Choose index 2
, and remove p2
 from the array. The array becomes p=[1,2]
.
It can be shown that the maximum number of operations we can perform is 1
. Another valid answer is p=[2,3,1]
.

In the second test case:

We choose p=[2,3,6,4,5,1]
.
Choose index 5
, and remove p5
 from the array. The array becomes p=[2,3,6,4,1]
.
Choose index 3
, and remove p3
 from the array. The array becomes p=[2,3,4,1]
.
Choose index 3
, and remove p3
 from the array. The array becomes p=[2,3,1]
.
Choose index 2
, and remove p2
 from the array. The array becomes p=[2,1]
.
The maximum number of operations we can perform is 4
. Any permutation with a score of 4
 is valid.

you cant do ascending descending here cuz you basically everytime have to remnove the middle element and it should be greater than its pre and succesive number 
what you can do is arrange alternatively any way 
and it works
all youve to print is permutation no number so its straight away*/
