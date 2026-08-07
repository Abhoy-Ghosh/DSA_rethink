

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Class representing a meeting
class Meeting {
public:
    int meetID;
    int start;
    int end;

    Meeting(int id, int s, int e) {
        meetID = id;
        start = s;
        end = e;
    }
};

// Sort meetings according to their finishing time
bool cmpForEnd(Meeting a, Meeting b) {
    return a.end < b.end;
}

// Returns the maximum set of non-overlapping meetings
vector<Meeting> nMeetingInARoom(vector<Meeting> meetings) {

    // Sort meetings by increasing end time
    sort(meetings.begin(), meetings.end(), cmpForEnd);

    vector<Meeting> possibleMeetings;

    // Always select the first meeting (earliest finishing)
    Meeting lastMeeting = meetings[0];
    possibleMeetings.push_back(meetings[0]);

    // Check the remaining meetings
    for (int i = 1; i < meetings.size(); i++) {

        // Select the meeting only if it starts
        // after the previously selected meeting ends
        if (lastMeeting.end <= meetings[i].start) {

            lastMeeting = meetings[i];
            possibleMeetings.push_back(meetings[i]);
        }
    }

    return possibleMeetings;
}

int main() {

    vector<Meeting> meetings = {

        // {Meeting ID, Start Time, End Time}

        {2, 1, 7},
        {3, 2, 6},
        {1, 7, 9}
    };

    vector<Meeting> ans = nMeetingInARoom(meetings);

    cout << "Selected Meetings: ";

    for (auto meeting : ans) {
        cout << meeting.meetID << " ";
    }

    return 0;
}


// ### Greedy Idea

// > **Always choose the meeting that finishes the earliest.**
// >
// > By selecting the earliest finishing meeting, we leave the maximum possible time available for scheduling the remaining meetings. After choosing a meeting, ignore all overlapping meetings and repeat the same process for the rest. This locally optimal choice leads to the maximum number of non-overlapping meetings.
