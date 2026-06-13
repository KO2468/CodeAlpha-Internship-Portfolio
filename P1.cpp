#include <iostream>
#include <vector>
#include <iomanip> // Used for setting decimal precision
#include <string>  // Required for getline

using namespace std;

struct Course
{
    string name;
    double grade;
    int credits;
};

int main()
{
    int numCourses;
    double currentTotalGradePoints = 0.0;
    int currentTotalCredits = 0;

    cout << "--- GPA Calculator ---" << endl;
    cout << "Enter the number of courses taken this semester: ";
    cin >> numCourses;

    // CRITICAL: Clears the newline character from the buffer after typing the number
    cin.ignore();

    vector<Course> courses(numCourses);

    // Input data for each course
    for (int i = 0; i < numCourses; ++i)
    {
        cout << "\nCourse " << (i + 1) << " Name: ";
        // Use getline instead of cin >> to allow spaces (e.g., "Intro to CS")
        getline(cin, courses[i].name);

        cout << "Enter grade (0.0 - 4.0): ";
        cin >> courses[i].grade;
        cout << "Enter credit hours: ";
        cin >> courses[i].credits;

        // CRITICAL: Clears the newline character after typing credit hours
        // so the next getline() doesn't accidentally read an empty line.
        cin.ignore();

        currentTotalGradePoints += (courses[i].grade * courses[i].credits);
        currentTotalCredits += courses[i].credits;
    }

    // Calculate Semester GPA
    double semesterGPA = currentTotalGradePoints / currentTotalCredits;

    // Calculate Cumulative CGPA
    char hasPrevious;
    cout << "\nDo you have previous semester data to calculate CGPA? (y/n): ";
    cin >> hasPrevious;

    double finalCGPA = semesterGPA;
    if (hasPrevious == 'y' || hasPrevious == 'Y')
    {
        double prevPoints;
        int prevCredits;
        cout << "Enter your total accumulated grade points from previous semesters: ";
        cin >> prevPoints;
        cout << "Enter your total accumulated credit hours: ";
        cin >> prevCredits;

        finalCGPA = (currentTotalGradePoints + prevPoints) / (currentTotalCredits + prevCredits);
    }

    // Display Results
    cout << "\n"
         << string(40, '=') << endl;
    cout << "Individual Course Results:" << endl;
    for (const auto &c : courses)
    {
        cout << "Course: " << setw(15) << left << c.name
             << " | Grade: " << c.grade
             << " | Credits: " << c.credits << endl;
    }

    cout << fixed << setprecision(2);
    cout << string(40, '-') << endl;
    cout << "Semester GPA: " << semesterGPA << endl;
    cout << "Final CGPA:   " << finalCGPA << endl;
    cout << string(40, '=') << endl;

    return 0;
}