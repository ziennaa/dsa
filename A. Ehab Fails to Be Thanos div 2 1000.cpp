#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(2*n);
    for(int i=0; i<(2*n); i++){
        cin>>a[i];
    }
    bool allEqual = true;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[0]) {
            allEqual = false;
            break;
        }
    }
    if(allEqual){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0; i<(2*n); i+=2){
        cout<<a[i]<<" ";
    }
    for(int i=1; i<(2*n); i+=2){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// new idea
// sort arr
// print 1st n and then last n


#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(2*n);
    for(int i=0; i<(2*n); i++){
        cin>>a[i];
    }
    bool allEqual = true;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] != a[0]) {
            allEqual = false;
            break;
        }
    }
    if(allEqual){
        cout<<-1<<endl;
        return 0;
    }
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    for(int i=n; i<(2*n); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
