

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Interval{
    public:
    int start;
    int end;
    
    Interval(int s, int e){
        start = s;
        end = e;
    }
};


bool cmpforStartEnd(Interval a, Interval b){
    if(a.start == b.start)
        return a.end < b.end;
    
    return a.start < b.start;
}


int removeOverlappingIntervals(vector<Interval> intervals){
    int n  = intervals.size();
    int numOfRemovals = 0;
    sort(intervals.begin(),intervals.end(),cmpforStartEnd);
    
    Interval lastInterval = intervals[0];
    
    for(int i = 1; i < n; i++){
        if(lastInterval.end > intervals[i].start){
            numOfRemovals++;
             // Keep the interval with smaller end time
            if(intervals[i].end < lastInterval.end)
                lastInterval= intervals[i];
        }
        else {
            lastInterval = intervals[i];
        }
    }
    return numOfRemovals;
}


int main(){
    
    vector<Interval> intervals = {
    {1,10},
    {2,3},
    {3,4}
};

    int ans = removeOverlappingIntervals(intervals);
    
    cout << ans;
    
    return 0;
}


// ```cpp
// class Solution {
// public:

//     // Sort intervals by starting time.
//     // If starting times are equal, sort by ending time.
//     static bool cmpforStartEnd(vector<int>& a, vector<int>& b) {

//         if (a[0] == b[0])
//             return a[1] < b[1];

//         return a[0] < b[0];
//     }

//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {

//         int n = intervals.size();
//         int numOfRemovals = 0;

//         // Sort intervals before processing
//         sort(intervals.begin(), intervals.end(), cmpforStartEnd);

//         // Assume the first interval is selected
//         vector<int> lastInterval = intervals[0];

//         // Traverse all remaining intervals
//         for (int i = 1; i < n; i++) {

//             // If the intervals overlap
//             if (lastInterval[1] > intervals[i][0]) {

//                 // One interval must be removed
//                 numOfRemovals++;

//                 // Keep the interval that ends earlier
//                 if (intervals[i][1] < lastInterval[1])
//                     lastInterval = intervals[i];
//             }
//             else {

//                 // No overlap, safely include this interval
//                 lastInterval = intervals[i];
//             }
//         }

//         return numOfRemovals;
//     }
// };
// ```

// ---

// ### Key Greedy Idea

// > **Whenever two intervals overlap, keep the interval that finishes earlier and remove the one that finishes later.**
// >
// > An interval with a smaller ending time occupies less space on the timeline, leaving more room for future intervals. By always preserving the earliest finishing interval, we maximize the number of intervals that can coexist, which minimizes the total number of removals.
