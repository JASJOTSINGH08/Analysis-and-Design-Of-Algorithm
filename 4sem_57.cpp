#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool activityCompare(Activity a, Activity b) {
    return (a.finish < b.finish);
}

void generateRandomActivities(Activity activities[], int n) {
    srand(time(0)); 

    for (int i = 0; i < n; ++i) {
        activities[i].start = rand() % 24;
        activities[i].finish = activities[i].start + rand() % (24 - activities[i].start); // Random finish time after start time
    }
}

void printMaxActivities(Activity activities[], int n, ofstream& outfile) {
    sort(activities, activities + n, activityCompare);

    outfile << "Start,Finish,ExecutionTime" << endl; // Write CSV header

    cout << "The following activities are selected:\n";

    int i = 0;
    cout << "(" << activities[i].start << ", " << activities[i].finish << "), ";

    clock_t start_time = clock(); // Start time of activity selection process

    outfile << activities[i].start << "," << activities[i].finish << "," << 0 << endl; // Write initial activity

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            cout << "(" << activities[j].start << ", " << activities[j].finish << "), ";
            i = j;
            outfile << activities[j].start << "," << activities[j].finish << "," << double(clock() - start_time) / CLOCKS_PER_SEC << endl; // Write activity and its execution time
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    Activity activities[n]; 

    generateRandomActivities(activities, n); 

    cout << "Randomly generated activities:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Activity " << i + 1 << ": (" << activities[i].start << ", " << activities[i].finish << ")\n";
    }

    ofstream outfile("activity_selection_execution_times.csv");
    if (!outfile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    printMaxActivities(activities, n, outfile); 

    outfile.close();
    return 0;
}
