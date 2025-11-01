/*Azriel Sakti Raja Manihuruk 22/500292/TK/54826 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Fungsi a: Membaca data mahasiswa
void getData(studentType s[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter first name, last name, and test score for student " << i + 1 << ": ";
        cin >> s[i].studentFName >> s[i].studentLName >> s[i].testScore;
    }
}

// Fungsi b: Menentukan grade berdasarkan skor
void assignGrade(studentType s[], int size) {
    for (int i = 0; i < size; i++) {
        if (s[i].testScore >= 90)
            s[i].grade = 'A';
        else if (s[i].testScore >= 80)
            s[i].grade = 'B';
        else if (s[i].testScore >= 70)
            s[i].grade = 'C';
        else if (s[i].testScore >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';
    }
}

// Fungsi c: Menemukan nilai tertinggi
int highestScore(const studentType s[], int size) {
    int highest = s[0].testScore;
    for (int i = 1; i < size; i++) {
        if (s[i].testScore > highest)
            highest = s[i].testScore;
    }
    return highest;
}

// Fungsi d: Mencetak nama siswa dengan nilai tertinggi
void printHighest(const studentType s[], int size, int highest) {
    cout << "\nStudents with the highest test score (" << highest << "):\n";
    for (int i = 0; i < size; i++) {
        if (s[i].testScore == highest)
            cout << s[i].studentLName << ", " << s[i].studentFName << endl;
    }
}

// Fungsi untuk mencetak semua data
void printAll(const studentType s[], int size) {
    cout << left << setw(15) << "Last Name"
         << setw(15) << "First Name"
         << setw(10) << "Score"
         << setw(6) << "Grade" << endl;
    cout << "-------------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << s[i].studentLName
             << setw(15) << s[i].studentFName
             << setw(10) << s[i].testScore
             << setw(6) << s[i].grade << endl;
    }
}

// Fungsi utama
int main() {
    studentType studentList[SIZE];
    int highest;

    getData(studentList, SIZE);
    assignGrade(studentList, SIZE);
    highest = highestScore(studentList, SIZE);

    cout << "\nStudent Results:\n";
    printAll(studentList, SIZE);
    printHighest(studentList, SIZE, highest);

    return 0;
}
