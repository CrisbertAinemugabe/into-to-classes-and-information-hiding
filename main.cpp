#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>

using namespace std;

// Class definitions
class College{
public:
    string name, location;
};

class DateOfBirth{
public:
    int day, month, year;
};

class Student{
private:
    string course;
    struct semesterOutcome {
        vector<double> marks;
        vector<int> credit_units;
    } outcome;
    int semester;
    double GPA=4.5, CGPA, Total_CUs;

public:
    string name;
    string regNumber;

    // College and DateOfBirth classes as member attributes
    College college;
    DateOfBirth date_of_birth;

    // Course getter and setter
    string getCourse() {
        return course;
    }
    void setCourse(string course) {
        this->course = course;
    }

    // Marks getter and setter
    vector<double> getMarks() {
        return outcome.marks;
    }
    void setMarks(vector<double> marks) {
        this->outcome.marks = marks;
    }

    // Semester setter and getter
    void setSemester(int semester) {
        this->semester = semester;
    }
    int getSemester(){
        return semester;
    }

    // GPA getter and setter
    double getGPA(){
        return GPA;
    }
    void setGPA(double GPA) {
        this->GPA = GPA;
    }

    // CGPA getter and setter
    double getCGPA() {
        return CGPA;
    }
    void setCGPA(double CGPA) {
        this->CGPA = CGPA;
    }

    // Total credit units getter and setter
    double getTotal_CUs() {
        return Total_CUs;
    }
    void setTotal_CUs(double Total_CUs) {
        this->Total_CUs = Total_CUs;
    }

    // Constructor to populate variables
    Student() {
        cout << "Student's name:" << endl;
        getline(cin >> ws, name);

        // Day, month, and year of birth with input validation
        while (true) {
            cout << "\nDay of birth: (1-31):" << endl;
            cin >> date_of_birth.day;
            // Validate day input
            if (cin.fail() || date_of_birth.day < 1 || date_of_birth.day > 31) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Your input isn't valid. Please enter a day between 1 and 31." << endl;
            } else {
                break; // Exit the loop if input is acceptable
            }
        }
        while (true) {
            cout << "Month of birth: (1-12):" << endl;
            cin >> date_of_birth.month;
            // Validate month input
            if (cin.fail() || date_of_birth.month < 1 || date_of_birth.month > 12) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Your input isn't valid. Please enter a month between 1 and 12." << endl;
            } else {
                break; // Exit the loop if input is acceptable
            }
        }
        while (true) {
            cout << "Year of birth: (1900-2024):" << endl;
            cin >> date_of_birth.year;
            // Validate year input
            if (cin.fail() || date_of_birth.year < 1900 || date_of_birth.year > 2024) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Your input isn't valid. Please enter a year between 1900 and 2024." << endl;
            } else {
                break; // Exit the loop if input is acceptable
            }
        }


        cout << "\nRegistration number:" << endl;
        cin >> regNumber;
        
        cout << "\nCollege name:" << endl;
        getline(cin >> ws, college.name);
        cout << "College location:" << endl;
        getline(cin >> ws, college.location);

        cout << "\nCourse:" << endl;
        // Use course setter fn to access private attribute course
        string course;
        cin >> course;
        setCourse(course);

        while (true) {
            cout << "\nCurrent semester (1-8):" << endl;
            int sem;
            cin >> sem;
            // Validate semester input
            if (cin.fail() || sem < 1 || sem > 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Your input isn't valid. Please enter a semester between 1 and 8." << endl;
            } else {
            setSemester(sem);
            break; // Exit the loop if input is acceptable
            }
        }

    }
};

// Function prototypes
void track_current_sem(Student& student_1);
double grade_semester(Student& student_1);

// Main function
int main() {
    Student student_1;

    //Calculate age
    // Get current time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int years = (1900 + ltm->tm_year) - student_1.date_of_birth.year;
    int months = (1 + ltm->tm_mon) - student_1.date_of_birth.month;
    int days = ltm->tm_mday - student_1.date_of_birth.day;

    // Adjust if the current date is before the birthday in the current year
    if (months < 0 || (months == 0 && days < 0)) {
        years--;
        months += 12;
    }
    if (days < 0) {
        months--;
        days += 30; // Approximate days in a month
    }

    cout << "\nStudent's age: " << years << " years, " << months << " months, and " << days << " days" << endl;
    track_current_sem(student_1);
    return 0;
}

// Current semester tracker and updater
void track_current_sem(Student& student_1) {
    //int current_semester;
    cout << "\n\nGrading semester 1" << endl;
    double newGPA = grade_semester(student_1);
    student_1.setGPA(newGPA);
    for(int i=2; student_1.getSemester() >=2 && i <= student_1.getSemester(); i++){
        cout << "Grading for semester " << i << endl;
        newGPA = student_1.getGPA() + grade_semester(student_1);
        i++;
        //Update gpa for each semester
        student_1.setGPA(newGPA);
    }


    //Bug here
    //Calculate CGPA
    double cgpa = newGPA / student_1.getSemester();
    student_1.setCGPA(cgpa);

    cout << "\nThe student's CGPA is: " << student_1.getCGPA() << endl;

}

// Semester grading function
double grade_semester(Student& student_1) {
    int num_course_units, credit_unit;
    cout << "\nNumber of course units: (1-6)" << endl;
    while (true) {
        cin >> num_course_units;
        //validate input
        if (cin.fail() || num_course_units < 1 || num_course_units > 6) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Your input isn't valid. Please enter a number between 1 and 6." << endl;
        } else {
            break; // Exit the loop if input is acceptable
        }
    }
    vector<int> grade_point(num_course_units);
    vector<double> GP_times_CU(num_course_units);
    double mark, semester_CU = 0, total_GP_times_CU = 0, gpa;

    for (int i = 0; i < num_course_units; i++) {
        cout << "Marks for course unit " << i + 1 << " (0-100):" << endl;
        while (true) {
            cin >> mark;
            // Validate input
            if (cin.fail() || mark < 0 || mark > 100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nYour input isn't valid. Please enter a number between 0 and 100." << endl;
            } else {
            break; // Exit the loop if input is acceptable
            }
        }
        vector<double> marks = student_1.getMarks();
        marks.push_back(mark);
        student_1.setMarks(marks);

        //Capture Credit Units
        cout << "Credit units for course unit (3-5)" << i + 1 << ":" << endl;
        while (true) {
            cin >> credit_unit;
            // Validate input
            if (cin.fail() || credit_unit < 3 || credit_unit > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nYour input isn't valid. Please enter a number between 0 and 5." << endl;
            } else {
            break; // Exit the loop if input is acceptable
            }
        }
        
        // Obtain grade point for every mark entered
        if (mark >= 90) {
            grade_point[i] = 5.0;
        } else if (mark >= 80) {
            grade_point[i] = 5.0;
        } else if (mark >= 75) {
            grade_point[i] = 4.5;
        } else if (mark >= 70) {
            grade_point[i] = 4.0;
        } else if (mark >= 65) {
            grade_point[i] = 3.5;
        } else if (mark >= 60) {
            grade_point[i] = 3.0;
        } else if (mark >= 55) {
            grade_point[i] = 2.5;
        } else if (mark >= 50) {
            grade_point[i] = 2.0;
        } else if (mark >= 45) {
            grade_point[i] = 1.5;
        } else {
            grade_point[i] = 0.0; // for marks below 45
        }
        // Calculate GP times CU for each course unit
        GP_times_CU[i] = grade_point[i] * credit_unit;
        // Accumulate total GP times CU for each semester
        total_GP_times_CU += GP_times_CU[i];
        // Accumulate total credit units for each semester
        semester_CU += credit_unit;
    }
    // Calculate GPA
    gpa = total_GP_times_CU / semester_CU;
    cout << "\nThe semester's GPA: " << gpa << endl;
    return gpa;
}
