#include <bits/stdc++.h>
using namespace std;
long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size(); // no of original gas stations
    vector<int> howMany(n-1, 0); // tracks how many extra stations have been inserted between arr[i] and arr[i+1] there are n-1 segments between adjacent stations
    for(int gasStations = 1; gasStations<=k; gasStations++){ // we will place k new gas stations one by one
        long double maxSection = -1;
        /*
        find the segment that currently has the largest subsegment and add one station there 
        to make it shorter
        go through all segments to make it shorter
        go through all segments between adjacent stations
        calculate length of each segment if we divide the sgement into 
        (howMany[i]+1)      add a new station in the worst segment found above with the longest subsegment  */
        int maxInd = -1;
        for(int i=0; i<n-1; i++){
            long double diff = (arr[i+1]-arr[i]);
            long double sectionLengtj = diff / (long double)(howMany[i]+1);
            if(sectionLengtj > maxSection){
                maxSection = sectionLengtj;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    long double maxAns = -1;
    for(int i=0; i<n-1; i++){
        long double diff = (arr[i+1]-arr[i]);
        long double sectionLengtj = diff / (long double) (howMany[i]+1);
        maxAns = max(maxAns, sectionLengtj);
    }
    return maxAns;
    /*after placing all k new stations go through all segments and calculate the final
    max subsegment length*/
}
/*
vector arr containing position of gas stations along a higheay
an integer k the no of new gas stations that u can insert

insert k gas stations between the existing one so that the maximum distance
between any two adjacent gas stations is minimised
greedy strategy
here tc : o(k*n) since for every station insertion it checks all sgegments*/
int main(){
    int n, k;
    cout<<"enter no of existing gas stations: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter positions of the gas stations in increasing order: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"enter no of new gas stations to add (k)";
    cin>>k;
    long double result = minimiseMaxDistance(arr, k);
    cout<<fixed<<setprecision(6);
    cout<<"Minimum possible maximum distance: "<<result<<endl;
    return 0;
}


// SECOND APPROACH

#include <bits/stdc++.h>
using namespace std;
long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size(); // no of original gas stations
    vector<int> howMany(n-1, 0); // tracks how many extra stations have been inserted between arr[i] and arr[i+1] there are n-1 segments between adjacent stations
    priority_queue<pair<long double, int>> pq;
    for(int i=0; i<n-1; i++){
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int gasStations = 1; gasStations<=k; gasStations++){ 
        // we will place k new gas stations one by one
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd+1] - arr[secInd];
        long double newSecLen = iniDiff / (long double) (howMany[i]+1);
        pq.push({newSecLen, secInd});
    //    long double maxSection = -1;
    //    /*
    //    find the segment that currently has the largest subsegment and add one station there 
    //    to make it shorter
    //    go through all segments to make it shorter
    //    go through all segments between adjacent stations
    //    calculate length of each segment if we divide the sgement into 
    //    (howMany[i]+1)      add a new station in the worst segment found above with the longest subsegment  */
    //    int maxInd = -1;
    //    for(int i=0; i<n-1; i++){
    //        long double diff = (arr[i+1]-arr[i]);
    //        long double sectionLengtj = diff / (long double)(howMany[i]+1);
    //        if(sectionLengtj > maxSection){
    //            maxSection = sectionLengtj;
    //            maxInd = i;
    //        }
    //    }
    //    howMany[maxInd]++;
    }
    //for(int i=0; i<n-1; i++){
    //    pq.push({arr[i+1]-arr[i], i});
    //}
    //long double maxAns = -1;
    //for(int i=0; i<n-1; i++){
    //    long double diff = (arr[i+1]-arr[i]);
    //    long double sectionLengtj = diff / (long double) (howMany[i]+1);
    //    maxAns = max(maxAns, sectionLengtj);
    //}
    //return maxAns;
    /*after placing all k new stations go through all segments and calculate the final
    max subsegment length*/
    return pq.top().first;
}
/*
vector arr containing position of gas stations along a higheay
an integer k the no of new gas stations that u can insert

insert k gas stations between the existing one so that the maximum distance
between any two adjacent gas stations is minimised
greedy strategy
here tc : o(k*n) since for every station insertion it checks all sgegments*/
int main(){
    int n, k;
    cout<<"enter no of existing gas stations: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter positions of the gas stations in increasing order: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"enter no of new gas stations to add (k)";
    cin>>k;
    long double result = minimiseMaxDistance(arr, k);
    cout<<fixed<<setprecision(6);
    cout<<"Minimum possible maximum distance: "<<result<<endl;
    return 0;
}



TC: (nlogn + klogn)
  sc : o(n-1)

  not the most optimal sol
can reduce space complexity!!!!
  
