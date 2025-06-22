#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m = (n*(n-1))/2;
        int b[m];
        for(int i=0; i<m; i++) cin>>b[i];
        sort(b, b+m);
        for(int i=0; i<m; i+=(--n)){
            cout<<b[i]<<" ";
        }
        cout<<1000000000<<endl;
    }
}
/*so basically can i say the core idea is 
in an array, in order to make pairs and see which is min and storing it in anotyher arreay
we see, the min is just ocuring n-1 times and then n-2 and so on
so weven if its like repeating like
4
2 2 2 2 2 2
we see already sorterd 
now min element 2
and it should ideally occur n-1 times i.e 3
so we first print 2 and then we reach to b[3] prints 2 again b[5] 2 and then largest element 100000
it can be anything greater than 2 tho 
but were choosing 100000000 as a safer option right*/
