#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Class representing a job
class Job {
public:
    int id;
    int deadline;
    int profit;

    Job(int i, int d, int p) {
        id = i;
        deadline = d;
        profit = p;
    }
};

// Find the maximum deadline among all jobs
int maxDeadline(vector<Job> jobs) {
    int maxDL = 0;

    for (int i = 0; i < jobs.size(); i++) {
        maxDL = max(maxDL, jobs[i].deadline);
    }

    return maxDL;
}

// Sort jobs by profit in descending order
// If profits are equal, schedule the one with the smaller deadline first
bool cmp(Job a, Job b) {

    if (a.profit == b.profit)
        return a.deadline < b.deadline;

    return a.profit > b.profit;
}

// Returns:
// first  -> Number of jobs scheduled
// second -> Maximum profit earned
pair<int, int> jobSequence(vector<Job> jobs) {

    int n = jobs.size();

    int maxProfit = 0;
    int jobCount = 0;

    // Process jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), cmp);

    // Find the maximum deadline to create time slots
    int maxDL = maxDeadline(jobs);

    // days[i] stores the job scheduled on day i
    // -1 means the slot is free
    vector<int> days(maxDL + 1, -1);

    // Try to schedule every job
    for (int i = 0; i < n; i++) {

        int day = jobs[i].deadline;

        // Find the latest available slot before its deadline
        while (day > 0) {

            if (days[day] == -1) {

                // Assign the job to this slot
                days[day] = jobs[i].id;

                jobCount++;
                maxProfit += jobs[i].profit;

                break;
            }

            day--;
        }
    }

    return {jobCount, maxProfit};
}

int main() {

    vector<Job> jobs = {

        // {id, deadline, profit}

        Job{1, 2, 30},
        Job{2, 4, 80},
        Job{3, 1, 40},
        Job{4, 1, 20}
    };

    pair<int, int> completedJobs = jobSequence(jobs);

    cout << "Job Count : " << completedJobs.first << endl;
    cout << "Max Profit: " << completedJobs.second << endl;

    return 0;
}
