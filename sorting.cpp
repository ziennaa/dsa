#include <bits/stdc++.h>
using namespace std;
void bubble_Sort(int a[], int n){
    for(int i=0; i<=n-2; i++){
        for(int j=0; j<n-1-i; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    cout<<"Bubble Sort"<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void selection_Sort(int a[], int n){
    for(int i=0; i<=n-2; i++){
        int mini=0;
        for(int j=i; j<n; j++){
            if(a[j]<a[mini]){
                swap(a[j], a[mini]);
            }
        }
    }
    cout<<"Selection Sort"<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void insertion_Sort(int a[], int n){
    for(int i=0; i<=n-1; i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            swap(a[j], a[j-1]);
            j--;
        }
    }
    cout<<"Insertion Sort"<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    bubble_Sort(a, n);
    selection_Sort(a, n);
    insertion_Sort(a,n);
    //printer();
    //cout<<endl;
}
