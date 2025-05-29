
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; // testcases input
    cin>>t;
    while(t--){
        int n; // length of string
        cin>>n;
        if(n<4) cout<<"NO\n"; // if it has to be MEOW in any possible way, it must have atleast 4 letters min.
        string s; // string
        cin>>s;
        for(int i=0; i<n; i++){
            s[i] = tolower(s[i]);
            if(s[i]!='m'){
                cout<<"NO\n";
                return 0;
            }
            else if(s[i+1]!='e' || s[i+1]!='m'){
                cout<<"NO\n";
                return 0;
            }
            else if (s[i+2]!='e' || s[i+2]!='o')
            {
                cout<<"NO\n";
                return 0;
            }
            else if (s[i+3]!='o' || s[i+3]!='w')
            {
                cout<<"NO\n";
                return 0;
            }else{
                cout<<"YES\n";
                return 0;
            }
            
        }

    }
}


// ABOVE CODE WRONG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; // testcases input
    cin>>t;
    while(t--){
        int n; // length of string
        cin>>n;
        if(n<4) cout<<"NO\n"; // if it has to be MEOW in any possible way, it must have atleast 4 letters min.
        string s; // string
        cin>>s;
        if(s[0] != 'M' || s[0] != 'm') cout<<"No\n";
        for(int i=0; i<n; i++){
            s[i] = tolower(s[i]);
            if(s[i]=='m'){
                if(s[i+1] == 'm' || s[i+1] == 'e'){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO"<<endl;
                }
            }else if (s[i]=='e')
            {
                if(s[i+1] == 'e' || s[i+1] == 'o'){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }
            else if (s[i]=='o')
            {
                if(s[i+1] == 'o' || s[i+1] == 'w'){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }
            else if (s[i]=='w')
            {
                if(s[i+1] == 'w'){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }else{
                cout<<"NO\n";
            }
        }
    }
}


// above code is wrong


// right sol
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>> n; 
    string s;
    cin>>s;
    int i=0;
    int m=0, e=0, o=0, w=0;
    for(int j=0; j<n; j++){
        s[j] = tolower(s[j]);
    }
    if (s[i] == 'm')
            while ((s[i] == 'm') and i < n)
            {
                m = 1;
                i++;
            }
        else
        {
            cout << "NO" << endl;
            return;
        }

        if (s[i] == 'e')
            while ((s[i] == 'e') and i < n)
            {
                e = 1;
                i++;
            }
        else
        {
            cout << "NO" << endl;
            return;
        }

        if (s[i] == 'o')
            while ((s[i] == 'o') and i < n)
            {
                o = 1;
                i++;
            }
        else
        {
            cout << "NO" << endl;
            return;
        }

        if (s[i] == 'w')
            while ((s[i] == 'w') and i < n)
            {
                w = 1;
                i++;
            }
        else
        {
            cout << "NO" << endl;
            return;
        }

        if (m == 1 and e == 1 and o == 1 and w == 1 and i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

/*
first here
1. input t : number of testcases
2. make solve function
3. input n : length of string
4. input s : string
5. if s[i] = m or M ( you can make lowercase first, the whole string that would be ideal ) i is not the loop it is an integer which we 're updating after every while conddiion
6. then you check whilw condition i.e if m and i<n
7. we make m = 1
8. and update i i.e i++
9. now we saw m occurs ( we dont really have to check how many times it occurs we just saw it occurs first and once that condiotion is satisified only then we move to next condition if this is itself not satisified its gonna print no
10. then we do the same thing with e, o and w
11. we make another condition to see if all occuring once and if this is true then yes otherwise no
12. done 
*/
