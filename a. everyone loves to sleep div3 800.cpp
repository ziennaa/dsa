#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin>>n;
        int h, m;
        cin>>h>>m;
        int o = h*60+m;
        int min = 1440;
        for(int i=0; i<n; i++){
            int k, l;
            cin>>k>>l;
            int to = (k*60)+l;
            int dif = (to-o+1440)%1440;
            if(dif < min){
                min = dif;
            }
        }
        int hours = min/60;
        int minut = min%60;
        cout<<hours<<" "<<minut<<endl;
    }
    return 0;
}
// so first 
// n : number of alarms
/*
first thought was : time he sleeps to the last alarm time taken which was wrong cuz you might get an alarm which is earlier before and this indicates what? that youve to find minimum time
we first converted our time to minutes
we couldve ahanfled with that too but that was another way 
we found minimum time among the accepted time
we found min diff of time
and then converted back to hours
h*60+m
to - o = difference in minutes from bedtime to the alarm time, but this can be negative if the alarm is earlier in the day than bedtime
We add 1440 to ensure the value is non-negative. Because times wrap around every 1440 minutes 24 hours adding 1440 doesn’t change the effective difference modulo 1440
Then we take % 1440 modulo 1440 to make sure the difference is within a 24-hour period
*/

  
