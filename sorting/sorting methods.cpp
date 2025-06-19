/*
| Type             | What it Means                                                                |
| ---------------- | ---------------------------------------------------------------------------- |
| `vector<int> a`  |  A **copy** of the vector is made. Changes **don't affect** original data. |
| `vector<int> &a` |  You work with the **original vector**. Changes **directly affect** it.    |
*/

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
int partition(vector<int> &a, int low, int high){
     int pivot = a[low];
     int i = low;
     int j = high;
     while(i<j){
        while(a[i]<=pivot && i<=high-1){
            i++;
        }
        while(a[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(a[i], a[j]);
     }
     swap(a[low], a[j]);
     return j;
}
void quick_sort(vector<int> &a, int low, int high, int n){
    if(low<high){
        int pindex = partition(a, low, high);
        quick_sort(a, low, pindex-1, n);
        quick_sort(a, pindex+1, high, n);
    }
}
void counting_sort(int a[], int n){
    int maxv = a[0];
    for(int i=0; i<n; i++){
        if(a[i]>maxv){
            maxv=a[i];
        }
    }
    int freq[maxv+1]={0};
    for(int i=0; i<n; i++){
        freq[a[i]]++;
    }
    int index=0;
    for(int i=0; i<=maxv; i++){
        while(freq[i]>0){
            a[index++] = i;
            freq[i]--;
        }
    }
    cout << "Sorted array (Counting Sort): ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (a[left] < a[right]) temp.push_back(a[left++]);
        else temp.push_back(a[right++]);
    }

    while (left <= mid) temp.push_back(a[left++]);
    while (right <= high) temp.push_back(a[right++]);

    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

void MS(vector<int>& a, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    MS(a, low, mid);
    MS(a, mid + 1, high);
    merge(a, low, mid, high);
}

void merge_sort(vector<int>& a, int n) {
    MS(a, 0, n - 1);
    cout << "Merge Sort" << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    bubble_Sort(a, n);
    selection_Sort(a, n);
    insertion_Sort(a,n);
    vector<int> v(a, a+n);
    quick_sort(v, 0, v.size()-1, n);
    cout << "Quick Sort" << endl;
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    counting_sort(a, n);
    merge_sort(v, n);
    //printer();
    //cout<<endl;
}
