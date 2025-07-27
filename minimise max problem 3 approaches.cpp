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



//TC: (nlogn + klogn)
  //sc : o(n-1)



// binary search sol

#include <bits/stdc++.h>
using namespace std;
int numberOfGasStationsRequired(long double dist, vector<int> &arr){
    int count =0;
    for(int i=1; i<arr.size(); i++){
        int numberInBetween = ((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist == numberInBetween*dist){
            numberInBetween--;
        }
        count += numberInBetween;
    }
    return count;
}
/* for each segment it calculates 
the length of the segment
divide the segment into smaller section of length<=dist 
no of extra stations req in this smaller section of length is
(arr[i] - arr[i-1]) / dist
If the segment divides perfectly into equal parts (e.g., 10/2 = 5 + 5), then we only need (parts - 1) stations.
Otherwise, floor() works naturally.
loop starts from i=1 and not i=0 otherwise arr[i-1] causes out of bounds*/
long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size(); // no of original gas stations
    long double low = 0;
    long double high = 0;
    for(int i=0; i<n-1; i++){
        high = max(high, (long double)(arr[i+1]-arr[i]));
        // max distance between any 2 consecutive stations segment cannot be larger than that
    }
    long double diff = 1e-6;
    while(high -low>diff){
        long double mid = (low+high)/(2.0);
        int count = numberOfGasStationsRequired(mid, arr);
        if(count>k){
            low = mid;
        }else{
            high = mid;
        }
    }
    return high;
}
/*
guess a vlue mid
check how many stations would be req if we want no segment to be longer than mid
if u need more station than allowed mid is too small
keep doing untill high-low is very small*/
/*
check that how many gas stations would be needed so that no segment is longer than mid
if that mid is less than or equal to k then this mid is valid sol
or maybe we can do bettwe i.e reduce the max distances
otheriwse increase mid
*/
/*tc is o(n*log(maxlength/e))*/
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

optimal sol
