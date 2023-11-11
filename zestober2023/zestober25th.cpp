
//Author:S.Thameem Ansari
//Including necessary header file 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent a task with start time, end time, and priority
struct Task {
    int start, end, priority;
};
// Function to compare tasks based on their start times
bool compareTasks(const Task& task1, const Task& task2) {
    return task1.start < task2.start;
}

// Function to prioritize tasks considering their start times and priorities
vector<Task> prioritizeTasks(vector<Task>& tasks) {
    // Sort tasks based on their start times
    sort(tasks.begin(), tasks.end(), compareTasks);
    vector<Task> scheduledTasks;

    for (const Task& task : tasks) {
        bool overlap = false;

        // Check for overlap with previously scheduled tasks
        for (int i = 0; i < scheduledTasks.size(); ++i) {
            if (task.start < scheduledTasks[i].end) {
                overlap = true;
                // If the current task has higher priority, replace the overlapping task
                if (task.priority > scheduledTasks[i].priority) {
                    scheduledTasks[i] = task;
                }
                break;
            }
        }

        // If no overlap, add the task to scheduledTasks
        if (!overlap) {
            scheduledTasks.push_back(task);
        }
    }

    return scheduledTasks;
}

int main() {
    // Example tasks: start time, end time, and priority
    vector<Task> tasks = {{1, 3, 3}, {2, 4, 2}, {5, 7, 1}, {6, 8, 4}, {10, 12, 2}};
    // Get the scheduled tasks considering priorities and dangerous overlaps
    vector<Task> scheduledTasks = prioritizeTasks(tasks);

    // Print the scheduled tasks
    cout << "Scheduled tasks: ";
    for (const Task& task : scheduledTasks) {
        cout << "(" << task.start << ", " << task.end << ", " << task.priority << ") ";
    }
    cout << endl;

    return 0;
}
