#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Class for Student marks
class Student
{
    private:
        string name;
        int quiz1, quiz2, midTermExam, finalExam;

    public:
        // Constructor
        Student() {
            name = "";
            quiz1 = 0;
            quiz2 = 0;
            midTermExam = 0;
            finalExam = 0;
        }

        // Setter for name
        void setName(const string& newName) {
            name = newName;
        }

        // Getter for name
        string getName() const {
            return name;
        }

        // Setter for quiz1
        void setQuiz1Result(const int& value) {
            quiz1 = value;
        }

        // Getter for quiz1
        int getQuiz1() const {
            return quiz1;
        }

        // Setter for quiz2
        void setQuiz2Result(const int& value) {
            quiz2 = value;
        }

        // Getter for quiz2
        int getQuiz2() const {
            return quiz2;
        }

        // Setter for midTermExam
        void setMidTermExamResult(const int& value) {
            midTermExam = value;
        }

        // Getter for midTermExam
        int getMidTermExam() const {
            return midTermExam;
        }

        // Setter for finalExam
        void setFinalExamResult(const int& value) {
            finalExam = value;
        }

        // Getter for finalExam
        int getFinalExam() const {
            return finalExam;
        }

        // Member function that calculates and returns the student�s weighted average
        double calculateWeightAverage() const {
            double quizAverage, quizWeightResult, finalExamWeightResult, midTermWeightResult, weightedAverage;
            // The final exam counts for 50% of the grade
            finalExamWeightResult = finalExam * 0.50;

            // The midterm counts for 25%
            midTermWeightResult = midTermExam * 0.25;

            double quiz1Double = quiz1;
            quizAverage = ((quiz1Double + quiz2) / 20) * 100;
            quizWeightResult = quizAverage * 0.25;

            // Calculate the weighted average
            weightedAverage = finalExamWeightResult + midTermWeightResult + quizWeightResult;
            return weightedAverage;
        }

        friend istream& operator>>(istream& in, Student& student);
        friend ostream& operator<<(ostream& os, const Student &student);
};

istream& operator>>(istream& in, Student& student) {
    string line;
    getline(in, line);
    istringstream iss(line);
    string name, surname, fullname;
    int quiz1, quiz2, midTermExam, finalExam;

    iss >> name >> surname >> quiz1 >> quiz2 >> midTermExam >> finalExam;

    fullname = name + " " + surname;
    student.setName(fullname);
    student.setQuiz1Result(quiz1);
    student.setQuiz2Result(quiz2);
    student.setMidTermExamResult(midTermExam);
    student.setFinalExamResult(finalExam);

    return in;
}

ostream& operator<<(ostream& os, const Student &student) {
    os << "Student name: " << student.name << "\n"
        << "Applemac Quiz 1: " << student.quiz1 << "\n"
        << "Quiz 2: " << student.quiz2 << "\n"
        << "Midterm exam: " << student.midTermExam << "\n"
        << "Final exam: " << student.finalExam << "\n"
        << "Average numeric score: " << student.calculateWeightAverage() << "%" << "\n";
    return os;
};

int main()
{
    int curr_count = 0, max_students = 20;
    Student students[max_students];

    ifstream inStream;
    inStream.open("Student.dat");
    if (!inStream) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    if (inStream.is_open()) {
        while (curr_count < max_students && inStream >> students[curr_count]) {
            ++curr_count;
        }
        inStream.close();
    }

    double totalAverage = 0.0;

    for (int i = 0; i < curr_count; ++i) {
        cout << students[i] << endl;
        totalAverage += students[i].calculateWeightAverage();
    }

    if (curr_count > 0) {
        double classAverage = totalAverage / curr_count;
        cout << "Class Average: " << classAverage << "%" << endl;
    }

    return 0;
}
