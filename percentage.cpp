#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double totalMarks, obtainedMarks, percentage;

    // Input total and obtained marks
    cout << "Enter total marks: ";
    cin >> totalMarks;

    cout << "Enter obtained marks: ";
    cin >> obtainedMarks;

    // Calculate percentage
    percentage = (obtainedMarks / totalMarks) * 100;

    // Display the result
    cout << "Percentage: " << percentage << "%" << endl;

    return 0;
}
