#include <iostream>
#include <vector>

using namespace std;

// Struct to represent a job with its deadline and processing time
struct Job
{
    int deadline;
    int processingTime;
};

// Function to sort jobs based on deadlines in descending order using bubble sort
void bubbleSort(vector<Job> &jobs)
{
    int n = jobs.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            // Compare jobs based on deadlines
            if (jobs[j].deadline < jobs[j + 1].deadline)
            {
                // Swap jobs if they are in the wrong order
                swap(jobs[j], jobs[j + 1]);
            }
        }
    }
}

// Function to find the minimum value between two integers without using min
int findMin(int a, int b)
{
    return (a < b) ? a : b;
}

// Function to schedule jobs to maximize completed tasks before deadlines
void scheduleJobs(vector<Job> &jobs)
{
    // Sort jobs based on deadlines in descending order using bubble sort
    bubbleSort(jobs);

    // Array to keep track of time slots, initially all set to false (not scheduled)
    vector<bool> timeSlots(jobs.size(), false);

    // Iterate through each job and schedule it if possible
    for (const Job &job : jobs)
    {
        for (int i = findMin(job.deadline - 1, static_cast<int>(jobs.size()) - 1); i >= 0; --i)
        {
            // Find the latest available time slot before the deadline
            if (!timeSlots[i])
            {
                // Schedule the job
                timeSlots[i] = true;
                cout << "Scheduled Job " << job.deadline << " with processing time " << job.processingTime << endl;
                break;
            }
        }
    }
}

int main()
{
    vector<Job> jobs = {{1, 2}, {2, 1}, {3, 3}};

    // Schedule the jobs
    scheduleJobs(jobs);

    return 0;
}
