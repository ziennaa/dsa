// Write your code here
#include <bits/stdc++.h>
using namespace std;
bool islucky(long long n){
    while(n>0){
        int digit = n%10;
        if(digit != 4 && digit != 7){
            return false;
        }
        n /=10;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long A, B;
    cin>>A>>B;
    bool found = false;
    for(int i=A; i<=B; i++){
        if(islucky(i)){
            if(found) cout<<" ";
            cout<<i;
            found = true;
        }
    }
    if(!found) cout<<-1;
    cout<<"\n";
}
/*So the role of found is only to control spaces between numbers.
Without it, you’d either:

print an extra space at the start (" 4 7") or

print an extra space at the end ("4 7 ").*/

/*
Description
Given two numbers 
A
A and 
B
B. Print all lucky numbers between 
A
A and 
B
B inclusive.

Note:

A lucky number is any positive number whose decimal representation contains only the digits 
4
4 and 
7
7.

For example: numbers 
4
4, 
7
7, 
47
47, and 
744
744 are lucky, whereas numbers 
5
5, 
17
17, and 
174
174 are not.

Input Format
A single line containing two integers 
A
A and 
B
B.

Output Format
Print all lucky numbers between 
A
A and 
B
B inclusive, separated by a space, in increasing order.
If there are no lucky numbers, print 
−
1
−1.

Constraints
1
≤
A
≤
B
≤
1
0
5
1≤A≤B≤10 
5
 

Sample Input 1
4 20
Sample Output 1
4 7
Sample Input 2
8 15
Sample Output 2
-1
Note
Sample Input 1:

The lucky numbers between 
4
4 and 
20
20 are 
4
4 and 
7
7.
Sample Input 2:
There are no lucky numbers between 
8
8 and 
15
15.*/
