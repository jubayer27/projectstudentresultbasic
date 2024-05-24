#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Subject
{
    int count;

    string code;
    int credit;
    double score;
    double total;
    string grade;
    double point;
    double totalPoint;
    int totalCredit;

public:
    string name;
    void setSubject(string name, string code, int credit, double score)
    {
        this->name = name;
        this->code = code;
        this->credit = credit;
        this->score = score;
    }

    void calculateGradePoint()
    {
        total = credit * score;
        if (score >= 90)
        {
            grade = "A+";
            point = 4.0;
        }
        else if (score >= 85)
        {
            grade = "A";
            point = 4.0;
        }
        else if (score >= 80)
        {
            grade = "A-";
            point = 3.7;
        }
        else if (score >= 75)
        {
            grade = "B+";
            point = 3.3;
        }
        else if (score >= 70)
        {
            grade = "B";
            point = 3.0;
        }
        else if (score >= 65)
        {
            grade = "B-";
            point = 2.7;
        }
        else if (score >= 60)
        {
            grade = "C+";
            point = 2.3;
        }
        else if (score >= 55)
        {
            grade = "C";
            point = 2.0;
        }
        else if (score >= 50)
        {
            grade = "C-";
            point = 1.7;
        }
        else if (score >= 45)
        {
            grade = "D+";
            point = 1.3;
        }
        else if (score >= 40)
        {
            grade = "D";
            point = 1.0;
        }
        else
        {
            grade = "F";
            point = 0.0;
        }
    }

    // last number of code is credit. its a integer number
    void getCredit()
    {
        credit = code.back() - '0';
    }
    void calculateGPA(Subject *subjects, int n)
    {
        totalPoint = 0.0;
        totalCredit = 0;

        for (int i = 0; i < n; i++)
        {
            totalPoint += subjects[i].point * subjects[i].credit;
            totalCredit += subjects[i].credit;
        }

        double gpa = totalPoint / totalCredit;

        cout << "Total Point: " << totalPoint << endl;
        cout << "Total Credit: " << totalCredit << endl;
        cout << "GPA: " << gpa << endl;
    }
    bool operator<(const Subject &other) const
    {
        return score < other.score;
    }
    Subject &getSmallestSubject(Subject &subject1, Subject &subject2)
    {
        if (subject1 < subject2)
        {
            return subject1;
        }
        else
        {
            return subject2;
        }
    }
    friend void readSubjects(Subject *subjects, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the subject details for subject #" << i + 1 << endl;
            string name, code;
            int credit;
            double score;
            cout << "Subject Name: ";
            cin >> name;
            cout << "Subject Code: ";
            cin >> code;
            cout << "ubject Score: ";
            cin >> score;
            subjects[i].setSubject(name, code, credit, score);
            subjects[i].getCredit();
            subjects[i].calculateGradePoint();
        }
    }

    void displayResult()
    {
        cout << "Subject Code" << setw(15) << "Subjec Name" << setw(15) << "Credit" << setw(15) << "Score" << setw(15) << "Grade" << setw(15) << "Point" << setw(15) << "Total Point" << endl;
        cout << code << setw(15) << name << setw(15) << credit << setw(15) << score << setw(15) << grade << setw(15) << point << setw(15) << point * credit << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of subjects: ";
    cin >> n;
    Subject sub[n];

    readSubjects(sub, n);
    cout << "Result: \n";
    for (int i = 0; i < n; i++)
    {
        sub[i].displayResult();
    }

    sub[0].calculateGPA(sub, n);

    Subject smallest = sub[0];
    for (int i = 1; i < n; i++)
    {
        smallest = smallest.getSmallestSubject(smallest, sub[i]);
    }
    cout << "The smallest subject is: " << smallest.name << endl;

    return 0;
}