#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int firstB = 1;
        for(int i=n-1; i>=1; i--){
            if(k>n-i){
                k-=n-i;
            }else{
                firstB = i;
                break;
            }
        }
        int secondB = n-(k-1);
        string s(n, 'a');
        s[firstB-1] = 'b';
        s[secondB-1] = 'b';
        cout<<s<<"\n";
    }
    return 0;
}

/*
explanation
Take n = 5, the blocks:

First b	Block size	Strings in block	k-range (cumulative)
4	1	aaabb	1
3	2	aabab, aabba	2-3
2	3	abaab, ababa, abbaa	4-6
1	4	baaab, baaba, babaa, bbaaa	7-10

Cumulative k-range = which values of k correspond to this block.

For example:

Block with first b=4 → k=1

Block with first b=3 → k=2,3

Block with first b=2 → k=4,5,6

Block with first b=1 → k=7,8,9,10

Step 2: How we “find the block” for a given k

Suppose k = 8.

Look at blocks from right to left (biggest first b to smallest):

Block firstB=4 → size 1

k = 8 → not in this block (block covers k=1 only)

Subtract size: k = 8 - 1 = 7

Block firstB=3 → size 2

k = 7 → not in this block (block covers k=2-3)

Subtract size: k = 7 - 2 = 5

Block firstB=2 → size 3

k = 5 → not in this block (block covers k=4-6)

Subtract size: k = 5 - 3 = 2

Block firstB=1 → size 4

k = 2 → k ≤ size of block (4) → k is in this block!

This is why we know k is in the block where firstB = 1.

Step 3: Visual analogy

Think of the blocks like steps on a ladder:

Block 4 (size 1) → step 1
Block 3 (size 2) → steps 2,3
Block 2 (size 3) → steps 4,5,6
Block 1 (size 4) → steps 7,8,9,10


k=8 → we climb the ladder: 1 → 2,3 → 4,5,6 → 7,8,9,10 → we stop at block 1.

Inside this block, k = 2 (relative to this block) → pick second b accordingly.

So the trick is:

k is not the absolute position inside the block yet.

As we subtract block sizes, k becomes relative to the current block.

Once k ≤ block size → k-th string in this block = desired string.
*/


  *
