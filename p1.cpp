#include <iostream>
#include <iomanip>
using namespace std;

void print_marksheet();
string convert_to_grade(int marks);
int convert_to_grade_point(int marks);

int main() {
    print_marksheet();
    return 0;
}

void print_marksheet() {
    string name, s_id;
    int sem, i, theory[3], pract[3], t_credit[3] = {2, 2, 2}, p_credit[3] = {1, 1, 1};
    float sum = 0, total_cr = 0, cgpa;
    string subject[3], grade1[3], grade2[3];

    cout << "Enter student id  :";
    cin >> s_id;
    cout << "Enter student name :";
    cin >> name;
    cout << "Enter student semester :";
    cin >> sem;

    cout << "Enter 3 subject names :\n";
    for (i = 0; i < 3; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> subject[i];
    }

    cout << "\nEntered subjects:\n";
    for (i = 0; i < 3; i++) {
        cout << "Subject " << i + 1 << ": " << subject[i] << "\n";
    }

    for (i = 0; i < 3; i++) {
        cout << "\nEnter theory and practical marks of " << subject[i] << "\n";
        cout << "Theory: ";
        cin >> theory[i];
        cout << "Practical: ";
        cin >> pract[i];
    }

    for (i = 0; i < 3; i++) {
        grade1[i] = convert_to_grade(theory[i]);
        grade2[i] = convert_to_grade(pract[i]);
    }

    cout << "\nEntered student details" << "\n";
    cout << left << setw(20) << "Student ID" << left << ":" << s_id << "\n";
    cout << left << setw(20) << "Student Name" << left << ":" << name << "\n";
    cout << left << setw(20) << "Student Semester" << left << ":" << sem << "\n\n";

    cout << "\nGrades for each subject:\n";
    cout << left << setw(20) << "Subject" << setw(15) << "Grade Theory" << setw(15) << "Grade Practical" << "\n";
    for (i = 0; i < 3; i++) {
        cout << left << setw(20) << subject[i] << setw(15) << grade1[i] << setw(15) << grade2[i] << "\n";
    }

    for (i = 0; i < 3; i++) {
        sum += (convert_to_grade_point(theory[i]) * t_credit[i]) + (convert_to_grade_point(pract[i]) * p_credit[i]);
        total_cr += t_credit[i] + p_credit[i];
    }

    cgpa = sum / total_cr;

    cout << "\nCGPA is: " << setw(20) << setprecision(3) << cgpa << endl;
}

string convert_to_grade(int marks) {
    if (marks >= 80) {
        return "AA";
    } else if (marks >= 73 && marks < 80) {
        return "AB";
    } else if (marks >= 66 && marks < 73) {
        return "BB";
    } else if (marks >= 60 && marks < 66) {
        return "BC";
    } else if (marks >= 55 && marks < 60) {
        return "CC";
    } else if (marks >= 50 && marks < 55) {
        return "CD";
    } else if (marks >= 45 && marks < 50) {
        return "DD";
    } else {
        return "FF";
    }
}

int convert_to_grade_point(int marks) {
    if (marks >= 80) {
        return 10;
    } else if (marks >= 73 && marks < 80) {
        return 9;
    } else if (marks >= 66 && marks < 73) {
        return 8;
    } else if (marks >= 60 && marks < 66) {
        return 7;
    } else if (marks >= 55 && marks < 60) {
        return 6;
    } else if (marks >= 50 && marks < 55) {
        return 5;
    } else if (marks >= 45 && marks < 50) {
        return 4;
    } else {
        return 0;
    }
}
