#include <iostream>
using namespace std;

// global variables
int course;
int selectSubject;

void DisplayHeader()
{
    cout << "\033[1;32m[---------------------------------------------------------------------------------------------------------------------------]\033[0m" << endl;
    cout << "\033[1;32m[===========================================================================================================================]\033[0m" << endl;
    cout << "\033[1;32m[===============================================\033[0m";
    cout << "\033[1;33m FEU Alabang Grading System \033[0m";
    cout << "\033[1;32m================================================]\033[0m" << endl;
    cout << "\033[1;32m[===========================================================================================================================]\033[0m" << endl;
    cout << "\033[1;32m[___________________________________________________________________________________________________________________________]\033[0m" << endl;
}

// Display Menu
void DisplayMenu() {

    DisplayHeader();

    // Selecting a course
    cout << "\nPlease select a subject that you would like to calculate.\n";
    cout << "1] GENERAL EDUCATION\n";
    cout << "2] IT SUBJECT 2-1 UNITS (2 LEC / 1 LAB)\n";
    cout << "3] IT SUBJECT 3 UNITS (Pure LEC)\n";
    cout << "4] IT SUBJECT INTEGRATED 3 UNITS (Combined LEC/LAB)\n";
    cout << "5] EXIT\n";

}

// Grade Evaluation function
void GradeEvaluation(double grade) {
    cout << "\nGrade Evaluation:" << endl;
    if (grade >= 97 && grade <= 100) {
        cout << "Your grade: " << grade << " = 4.0" << endl;
    } else if (grade >= 93 && grade < 97) {
        cout << "Your grade: " << grade << " = 3.5" << endl;
    } else if (grade >= 89 && grade < 93) {
        cout << "Your grade: " << grade << " = 3.0" << endl;
    } else if (grade >= 85 && grade < 89) {
        cout << "Your grade: " << grade << " = 2.5" << endl;
    } else if (grade >= 80 && grade < 85) {
        cout << "Your grade: " << grade << " = 2.0" << endl;
    } else if (grade >= 75 && grade < 80) {
        cout << "Your grade: " << grade << " = 1.5" << endl;
    } else if (grade >= 70 && grade < 75) {
        cout << "Your grade: " << grade << " = 1.0" << endl;
    } else if (grade >= 0 && grade < 70) {
        cout << "Your grade: " << grade << " = 0.5" << endl;
    } else {
        cout << "Invalid grade. Please check your input values." << endl;
    }
}

// Choose between Midterm and Final computation
char ChooseGradePeriodType() {
    char choice;
    cout << "\nWould you like to compute for Midterms or Finals first? (M/F): ";
    cin >> choice;

    while (choice != 'M' && choice != 'm' && choice != 'F' && choice != 'f') {
        cout << "Invalid input. Please enter 'M' for Midterms or 'F' for Finals: ";
        cin >> choice;
    }
    return choice;
}


// function for validating inputted grade
bool IsInvalidGrade(double grade)
{
    return grade <= 0 || grade > 100;
}

// General Education course functionality
void GenEd() {
    double classStanding, midtermExamScore, finalExamScore;

    char periodType = ChooseGradePeriodType();

    if (periodType == 'M' || periodType == 'm') {
        // Midterm computation first
        cout << "\n====================================MIDTERMS==============================================" << endl;
        cout << "Enter Class Standing Score (0-100): ";
        cin >> classStanding;

        // check if valid grade 0-100
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam Score (0-100): ";
        cin >> midtermExamScore;
        if(IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        // calculate and display midterm grade
        double midtermGrade = 0.6 * classStanding + 0.4 * midtermExamScore;
        cout << "\nYour Midterm Grade (MG) is: " << midtermGrade << "%" << endl;
        GradeEvaluation(midtermGrade);


        // option to compute for finals
        char calculateFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calculateFinals;
        if (calculateFinals == 'Y' || calculateFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "Enter Class Standing Score (0-100): ";
            cin >> classStanding;
            if(IsInvalidGrade(classStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "Enter Final Exam Score (0-100): ";
            cin >> finalExamScore;
            if (IsInvalidGrade(finalExamScore))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "\nLIST OF GRADES: " << endl;
            cout << "[1] CLASS STANDING: " << classStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
            cout << "[3] FINAL EXAM SCORE: " << finalExamScore << endl;

            double finalGrade = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalExamScore;
            cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
            GradeEvaluation(finalGrade);
        }
    }
    else if (periodType == 'F' || periodType == 'f') {
        // Finals computation first
        cout << "\n====================================FINALS==============================================" << endl;
        cout << "Enter Class Standing Score (0-100): ";
        cin >> classStanding;
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam Score (0-100): ";
        cin >> midtermExamScore;
        if(IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Final Exam Score (0-100): ";
        cin >> finalExamScore;
        if(IsInvalidGrade(finalExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        cout << "\nLIST OF GRADES: " << endl;
        cout << "[1] CLASS STANDING: " << classStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
        cout << "[3] FINAL EXAM SCORE: " << finalExamScore << endl;

        double FG = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalExamScore;
        cout << "\nYour Final Grade (FG) is: " << FG << "%" << endl;
        GradeEvaluation(FG);
    }
}

// Functionality for IT Subject (2 units: lecture & lab)
void ItSubject2units() {
    double lectureClassStanding, lectureMidtermsExam, labClassStanding, labMidtermsExam, lectureFinalsExam, labFinalsExam;

    char evalType = ChooseGradePeriodType();

    // if user chooses M
    if (evalType == 'M' || evalType == 'm') {
        cout << "\n====================================MIDTERMS==============================================" << endl;
        cout << "--- Lecture Grades ---" << endl;
        cout << "Enter Lecture Class Standing (CS) Score (0-100): ";
        cin >> lectureClassStanding;
        if(IsInvalidGrade(lectureClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Lecture Midterm Exam (ME) Score (0-100): ";
        cin >> lectureMidtermsExam;
        if(IsInvalidGrade(lectureMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double lecMidtermGrade = 0.6 * lectureClassStanding + 0.4 * lectureMidtermsExam;

        cout << "\n--- Laboratory Grades ---" << endl;
        cout << "Enter Laboratory Class Standing (CS) Score (0-100): ";
        cin >> labClassStanding;
        if (IsInvalidGrade(labClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Laboratory Midterm Exam (ME) Score (0-100): ";
        cin >> labMidtermsExam;
        if (IsInvalidGrade(labMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double labMidtermGrade = 0.6 * labClassStanding + 0.4 * labMidtermsExam;

        double midtermGrade = 0.7 * lecMidtermGrade + 0.3 * labMidtermGrade;
        cout << "\nYour Midterm Grade (MG) is: " << midtermGrade << "%" << endl;
        GradeEvaluation(midtermGrade);#include <iostream>
using namespace std;

// global variables
int course;
int selectSubject;

void DisplayHeader()
{
    cout << "\033[1;32m[---------------------------------------------------------------------------------------------------------------------------]\033[0m" << endl;
    cout << "\033[1;32m[===========================================================================================================================]\033[0m" << endl;
    cout << "\033[1;32m[===============================================\033[0m";
    cout << "\033[1;33m FEU Alabang Grading System \033[0m";
    cout << "\033[1;32m================================================]\033[0m" << endl;
    cout << "\033[1;32m[===========================================================================================================================]\033[0m" << endl;
    cout << "\033[1;32m[___________________________________________________________________________________________________________________________]\033[0m" << endl;
}

// Display Menu
void DisplayMenu() {

    DisplayHeader();

    // Selecting a course
    cout << "\nPlease select a subject that you would like to calculate.\n";
    cout << "1] GENERAL EDUCATION\n";
    cout << "2] IT SUBJECT 2-1 UNITS (2 LEC / 1 LAB)\n";
    cout << "3] IT SUBJECT 3 UNITS (Pure LEC)\n";
    cout << "4] IT SUBJECT INTEGRATED 3 UNITS (Combined LEC/LAB)\n";
    cout << "5] EXIT\n";

}

// Grade Evaluation function
void GradeEvaluation(double grade) {
    cout << "\nGrade Evaluation:" << endl;
    if (grade >= 97 && grade <= 100) {
        cout << "Your grade: " << grade << " = 4.0" << endl;
    } else if (grade >= 93 && grade < 97) {
        cout << "Your grade: " << grade << " = 3.5" << endl;
    } else if (grade >= 89 && grade < 93) {
        cout << "Your grade: " << grade << " = 3.0" << endl;
    } else if (grade >= 85 && grade < 89) {
        cout << "Your grade: " << grade << " = 2.5" << endl;
    } else if (grade >= 80 && grade < 85) {
        cout << "Your grade: " << grade << " = 2.0" << endl;
    } else if (grade >= 75 && grade < 80) {
        cout << "Your grade: " << grade << " = 1.5" << endl;
    } else if (grade >= 70 && grade < 75) {
        cout << "Your grade: " << grade << " = 1.0" << endl;
    } else if (grade >= 0 && grade < 70) {
        cout << "Your grade: " << grade << " = 0.5" << endl;
    } else {
        cout << "Invalid grade. Please check your input values." << endl;
    }
}

// Choose between Midterm and Final computation
char ChooseGradePeriodType() {
    char choice;
    cout << "\nWould you like to compute for Midterms or Finals first? (M/F): ";
    cin >> choice;

    while (choice != 'M' && choice != 'm' && choice != 'F' && choice != 'f') {
        cout << "Invalid input. Please enter 'M' for Midterms or 'F' for Finals: ";
        cin >> choice;
    }
    return choice;
}


// function for validating inputted grade
bool IsInvalidGrade(double grade)
{
    return grade <= 0 || grade > 100;
}

// General Education course functionality
void GenEd() {
    double classStanding, midtermExamScore, finalExamScore;

    char periodType = ChooseGradePeriodType();

    if (periodType == 'M' || periodType == 'm') {
        // Midterm computation first
        cout << "\n====================================MIDTERMS==============================================" << endl;
        cout << "Enter Class Standing Score (0-100): ";
        cin >> classStanding;

        // check if valid grade 0-100
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam Score (0-100): ";
        cin >> midtermExamScore;
        if(IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        // calculate and display midterm grade
        double midtermGrade = 0.6 * classStanding + 0.4 * midtermExamScore;
        cout << "\nYour Midterm Grade (MG) is: " << midtermGrade << "%" << endl;
        GradeEvaluation(midtermGrade);


        // option to compute for finals
        char calculateFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calculateFinals;
        if (calculateFinals == 'Y' || calculateFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "Enter Class Standing Score (0-100): ";
            cin >> classStanding;
            if(IsInvalidGrade(classStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "Enter Final Exam Score (0-100): ";
            cin >> finalExamScore;
            if (IsInvalidGrade(finalExamScore))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "\nLIST OF GRADES: " << endl;
            cout << "[1] CLASS STANDING: " << classStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
            cout << "[3] FINAL EXAM SCORE: " << finalExamScore << endl;

            double finalGrade = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalExamScore;
            cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
            GradeEvaluation(finalGrade);
        }
    }
    else if (periodType == 'F' || periodType == 'f') {
        // Finals computation first
        cout << "\n====================================FINALS==============================================" << endl;
        cout << "Enter Class Standing Score (0-100): ";
        cin >> classStanding;
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam Score (0-100): ";
        cin >> midtermExamScore;
        if(IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Final Exam Score (0-100): ";
        cin >> finalExamScore;
        if(IsInvalidGrade(finalExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        cout << "\nLIST OF GRADES: " << endl;
        cout << "[1] CLASS STANDING: " << classStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
        cout << "[3] FINAL EXAM SCORE: " << finalExamScore << endl;

        double FG = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalExamScore;
        cout << "\nYour Final Grade (FG) is: " << FG << "%" << endl;
        GradeEvaluation(FG);
    }
}

// Functionality for IT Subject (2 units: lecture & lab)
void ItSubject2units() {
    double lectureClassStanding, lectureMidtermsExam, labClassStanding, labMidtermsExam, lectureFinalsExam, labFinalsExam;

    char evalType = ChooseGradePeriodType();

    // if user chooses M
    if (evalType == 'M' || evalType == 'm') {
        cout << "\n====================================MIDTERMS==============================================" << endl;
        cout << "--- Lecture Grades ---" << endl;
        cout << "Enter Lecture Class Standing (CS) Score (0-100): ";
        cin >> lectureClassStanding;
        if(IsInvalidGrade(lectureClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Lecture Midterm Exam (ME) Score (0-100): ";
        cin >> lectureMidtermsExam;
        if(IsInvalidGrade(lectureMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double lecMidtermGrade = 0.6 * lectureClassStanding + 0.4 * lectureMidtermsExam;

        cout << "\n--- Laboratory Grades ---" << endl;
        cout << "Enter Laboratory Class Standing (CS) Score (0-100): ";
        cin >> labClassStanding;
        if (IsInvalidGrade(labClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Laboratory Midterm Exam (ME) Score (0-100): ";
        cin >> labMidtermsExam;
        if (IsInvalidGrade(labMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double labMidtermGrade = 0.6 * labClassStanding + 0.4 * labMidtermsExam;

        double midtermGrade = 0.7 * lecMidtermGrade + 0.3 * labMidtermGrade;
        cout << "\nYour Midterm Grade (MG) is: " << midtermGrade << "%" << endl;
        GradeEvaluation(midtermGrade);


        // option to compute for finals
        char calcuFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calcuFinals;
        if (calcuFinals == 'Y' || calcuFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "--- Lecture Grades ---" << endl;
            cout << "Enter Lecture Class Standing (CS) Score (0-100): ";
            cin >> lectureClassStanding;
            if (IsInvalidGrade(lectureClassStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            cout << "Enter Lecture Final Exam (FE) Score (0-100): ";
            cin >> lectureFinalsExam;
            if (IsInvalidGrade(lectureFinalsExam))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            cout << "\n--- Laboratory Grades ---" << endl;
            cout << "Enter Laboratory Class Standing (CS) Score (0-100): ";
            cin >> labClassStanding;
            if(IsInvalidGrade(labClassStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            cout << "Enter Laboratory Final Exam (FE) Score (0-100): ";
            cin >> labFinalsExam;
            if (IsInvalidGrade(labFinalsExam))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            // display list of grades
            cout << "\nLIST OF GRADES: " << endl;
            cout << "====LECTURE=====" << endl;
            cout << "[1] CLASS STANDING: " << lectureClassStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << lectureMidtermsExam << endl;
            cout << "[3] FINAL EXAM SCORE: " << lectureFinalsExam << endl;

            cout << "====LABORATORY=====" << endl;
            cout << "[1] CLASS STANDING: " << labClassStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << labMidtermsExam << endl;
            cout << "[3] FINAL EXAM SCORE: " << labFinalsExam << endl;

            // calculation
            double lecFinalGrade = 0.6 * lectureClassStanding + 0.15 * lectureMidtermsExam + 0.25 * lectureFinalsExam;
            double labFinalGrade = 0.6 * labClassStanding + 0.15 * labMidtermsExam + 0.25 * labFinalsExam;
            double finalGrade = 0.7 * lecFinalGrade + 0.3 * labFinalGrade;

            cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
            GradeEvaluation(finalGrade);
        }
    }
    else if (evalType == 'F' || evalType == 'f') // finals option
    {
        cout << "\n====================================FINALS==============================================" << endl;
        // lecture grades
        cout << "--- Lecture Grades ---" << endl;
        cout << "Enter Lecture Class Standing (CS) Score (0-100): ";
        cin >> lectureClassStanding;
        if (IsInvalidGrade(lectureClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Lecture Midterm Exam (ME) Score (0-100): ";
        cin >> lectureMidtermsExam;
        if (IsInvalidGrade(lectureMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Lecture Final Exam (FE) Score (0-100): ";
        cin >> lectureFinalsExam;
        if (IsInvalidGrade(lectureFinalsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        // laboratory grades
        cout << "\n--- Laboratory Grades ---" << endl;
        cout << "Enter Laboratory Class Standing (CS) Score (0-100): ";
        cin >> labClassStanding;
        if (IsInvalidGrade(labClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Laboratory Midterm Exam (ME) Score (0-100): ";
        cin >> labMidtermsExam;
        if (IsInvalidGrade(labMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Laboratory Final Exam (FE) Score (0-100): ";
        cin >> labFinalsExam;
        if (IsInvalidGrade(labFinalsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        // display grades
        cout << "\nLIST OF GRADES: " << endl;
        cout << "====LECTURE=====" << endl;
        cout << "[1] CLASS STANDING: " << lectureClassStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << lectureMidtermsExam << endl;
        cout << "[3] FINAL EXAM SCORE: " << lectureFinalsExam << endl;

        cout << "====LABORATORY=====" << endl;
        cout << "[1] CLASS STANDING: " << labClassStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << labMidtermsExam << endl;
        cout << "[3] FINAL EXAM SCORE: " << labFinalsExam << endl;

        // calculations
        double lecFinalGrade = 0.6 * lectureClassStanding + 0.15 * lectureMidtermsExam + 0.25 * lectureFinalsExam;
        double labFinalGrade = 0.6 * labClassStanding + 0.15 * labMidtermsExam + 0.25 * labFinalsExam;
        double finalGrade = 0.7 * lecFinalGrade + 0.3 * labFinalGrade;

        cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
        GradeEvaluation(finalGrade);
    }
}

// Functionality for IT Subject (3 units: lecture)
void ItSubject3units() {
    double lecClassStanding, lecMidtermsExam, lecFinalsExam;

    char evalType = ChooseGradePeriodType();

    if (evalType == 'M' || evalType == 'm') {
        cout << "\n====================================MIDTERMS==============================================" << endl;

        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> lecClassStanding;
        if (IsInvalidGrade(lecClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> lecMidtermsExam;
        if (IsInvalidGrade(lecMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double lecMidtermGrade = 0.6 * lecClassStanding + 0.4 * lecMidtermsExam;
        cout << "\nYour Midterm Grade (MG) is: " << lecMidtermGrade << "%" << endl;
        GradeEvaluation(lecMidtermGrade);

        char calcuFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calcuFinals;
        if (calcuFinals == 'Y' || calcuFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "Enter Class Standing Score (0-100): ";
            cin >> lecClassStanding;
            cout << "Enter Final Exam (FE) Score (0-100): ";
            cin >> lecFinalsExam;
            if (IsInvalidGrade(lecFinalsExam))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            // display grades for each requirement
            cout << "\nLIST OF GRADES: " << endl;
            cout << "[1] CLASS STANDING: " << lecClassStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << lecMidtermsExam << endl;
            cout << "[3] FINAL EXAM SCORE: " << lecFinalsExam << endl;

            // Computation for finals in IT Subj 3 units
            double lecFinalGrade = 0.6 * lecClassStanding + 0.15 * lecMidtermsExam + 0.25 * lecFinalsExam;

            // display result & final grade w/ evaluation
            cout << "\nYour Final Grade (FG) is: " << lecFinalGrade << "%" << endl;
            GradeEvaluation(lecFinalGrade);
        }
    }
    else if (evalType == 'F' || evalType == 'f')
    {
        cout << "\n====================================FINALS==============================================" << endl;

        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> lecClassStanding;
        if (IsInvalidGrade(lecClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> lecMidtermsExam;
        if (IsInvalidGrade(lecMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Final Exam (FE) Score (0-100): ";
        cin >> lecFinalsExam;
        if (IsInvalidGrade(lecFinalsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        cout << "\nLIST OF GRADES: " << endl;
        cout << "[1] CLASS STANDING: " << lecClassStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << lecMidtermsExam << endl;
        cout << "[3] FINAL EXAM SCORE: " << lecFinalsExam << endl;

      // computation for finals
        double lecFinalGrade = 0.6 * lecClassStanding + 0.15 * lecMidtermsExam + 0.25 * lecFinalsExam;

        // results and final grades
        cout << "\nYour Final Grade (FG) is: " << lecFinalGrade << "%" << endl;
        GradeEvaluation(lecFinalGrade);
    }
}

// Functionality for IT Subject (integrated, combined lecture & lab)
void ItSubjectIntegrated() {
    double classStanding, midtermExamScore, finalsExamScore;

    char evalType = ChooseGradePeriodType();

    if (evalType == 'M' || evalType == 'm') {
        cout << "\n====================================MIDTERMS==============================================" << endl;

        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> classStanding;
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> midtermExamScore;
        if (IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double midtermGrade = 0.6 * classStanding + 0.4 * midtermExamScore;
        cout << "\nYour Midterm Grade (MG) is: " << midtermGrade << "%" << endl;
        GradeEvaluation(midtermGrade);

        char calcuFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calcuFinals;
        if (calcuFinals == 'Y' || calcuFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "Enter Class Standing (CS) Score (0-100): ";
            cin >> classStanding;
            if (IsInvalidGrade(classStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "Enter Final Exam Score (0-100): ";
            cin >> finalsExamScore;
            if (IsInvalidGrade(finalsExamScore))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "\nLIST OF GRADES: " << endl;
            cout << "[1] CLASS STANDING: " << classStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
            cout << "[3] FINAL EXAM SCORE: " << finalsExamScore << endl;


            double finalGrade = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalsExamScore;
            cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
            GradeEvaluation(finalGrade);
        }
    }
    else if (evalType == 'F' || evalType == 'f') // finals option
    {
        cout << "\n====================================FINALS==============================================" << endl;
        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> classStanding;
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> midtermExamScore;
        if (IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Final Exam (FE) Score (0-100): ";
        cin >> finalsExamScore;
        if (IsInvalidGrade(finalsExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        // display list of grades
        cout << "\nLIST OF GRADES: " << endl;
        cout << "[1] CLASS STANDING: " << classStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
        cout << "[3] FINAL EXAM SCORE: " << finalsExamScore << endl;

        double finalGrade = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalsExamScore;
        // double finalGrade =  0.6 * classStanding + 0.4 * midtermExamPercentage;
        cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
        GradeEvaluation(finalGrade);
    }
}

// Choosing a course
void ChooseSubject() {
    cout << "\nEnter Subject Number: ";
    cin >> course;

    switch (course) {
        case 1:
            GenEd();
            break;
        case 2:
            ItSubject2units();
            break;
        case 3:
            ItSubject3units();
            break;
        case 4:
            ItSubjectIntegrated();
            break;
        case 5:
            // Exit button, terminates the program
            cout << "\033[1mExiting program....\033[0m" << endl;
            cout << "\033[1mThank you for using FEU Alabang Grading System!🔰\033[0m" << endl;
            exit(0);
        default:
            cout << "Invalid input, please choose a number from 1-5 only." << endl;
    }
}

// loop to compute again and to choose another course
void CourseLoop()
{
    char choice;

    do
    {
        DisplayMenu();
        ChooseSubject();

        cout << "\nDo you want to compute again? [Y/N]: ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            cout << "\033[1mExiting program....\033[0m" << endl;
            cout << "\033[1mThank you for using FEU Alabang Grading System!🔰\033[0m" << endl;
            break;
        } else if (choice == 'Y' || choice == 'y') {
            continue;
        } else {
            cout << "Invalid entry. Enter Y or N only." << endl;
        }

    } while (true);
}

// Main function
int main() {
    CourseLoop();
    return 0;
}



        // option to compute for finals
        char calcuFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calcuFinals;
        if (calcuFinals == 'Y' || calcuFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "--- Lecture Grades ---" << endl;
            cout << "Enter Lecture Class Standing (CS) Score (0-100): ";
            cin >> lectureClassStanding;
            if (IsInvalidGrade(lectureClassStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            cout << "Enter Lecture Final Exam (FE) Score (0-100): ";
            cin >> lectureFinalsExam;
            if (IsInvalidGrade(lectureFinalsExam))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            cout << "\n--- Laboratory Grades ---" << endl;
            cout << "Enter Laboratory Class Standing (CS) Score (0-100): ";
            cin >> labClassStanding;
            if(IsInvalidGrade(labClassStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            cout << "Enter Laboratory Final Exam (FE) Score (0-100): ";
            cin >> labFinalsExam;
            if (IsInvalidGrade(labFinalsExam))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            // display list of grades
            cout << "\nLIST OF GRADES: " << endl;
            cout << "====LECTURE=====" << endl;
            cout << "[1] CLASS STANDING: " << lectureClassStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << lectureMidtermsExam << endl;
            cout << "[3] FINAL EXAM SCORE: " << lectureFinalsExam << endl;

            cout << "====LABORATORY=====" << endl;
            cout << "[1] CLASS STANDING: " << labClassStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << labMidtermsExam << endl;
            cout << "[3] FINAL EXAM SCORE: " << labFinalsExam << endl;

            // calculation
            double lecFinalGrade = 0.6 * lectureClassStanding + 0.15 * lectureMidtermsExam + 0.25 * lectureFinalsExam;
            double labFinalGrade = 0.6 * labClassStanding + 0.15 * labMidtermsExam + 0.25 * labFinalsExam;
            double finalGrade = 0.7 * lecFinalGrade + 0.3 * labFinalGrade;

            cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
            GradeEvaluation(finalGrade);
        }
    }
    else if (evalType == 'F' || evalType == 'f') // finals option
    {
        cout << "\n====================================FINALS==============================================" << endl;
        // lecture grades
        cout << "--- Lecture Grades ---" << endl;
        cout << "Enter Lecture Class Standing (CS) Score (0-100): ";
        cin >> lectureClassStanding;
        if (IsInvalidGrade(lectureClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Lecture Midterm Exam (ME) Score (0-100): ";
        cin >> lectureMidtermsExam;
        if (IsInvalidGrade(lectureMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Lecture Final Exam (FE) Score (0-100): ";
        cin >> lectureFinalsExam;
        if (IsInvalidGrade(lectureFinalsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        // laboratory grades
        cout << "\n--- Laboratory Grades ---" << endl;
        cout << "Enter Laboratory Class Standing (CS) Score (0-100): ";
        cin >> labClassStanding;
        if (IsInvalidGrade(labClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Laboratory Midterm Exam (ME) Score (0-100): ";
        cin >> labMidtermsExam;
        if (IsInvalidGrade(labMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Laboratory Final Exam (FE) Score (0-100): ";
        cin >> labFinalsExam;
        if (IsInvalidGrade(labFinalsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        // display grades
        cout << "\nLIST OF GRADES: " << endl;
        cout << "====LECTURE=====" << endl;
        cout << "[1] CLASS STANDING: " << lectureClassStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << lectureMidtermsExam << endl;
        cout << "[3] FINAL EXAM SCORE: " << lectureFinalsExam << endl;

        cout << "====LABORATORY=====" << endl;
        cout << "[1] CLASS STANDING: " << labClassStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << labMidtermsExam << endl;
        cout << "[3] FINAL EXAM SCORE: " << labFinalsExam << endl;

        // calculations
        double lecFinalGrade = 0.6 * lectureClassStanding + 0.15 * lectureMidtermsExam + 0.25 * lectureFinalsExam;
        double labFinalGrade = 0.6 * labClassStanding + 0.15 * labMidtermsExam + 0.25 * labFinalsExam;
        double finalGrade = 0.7 * lecFinalGrade + 0.3 * labFinalGrade;

        cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
        GradeEvaluation(finalGrade);
    }
}

// Functionality for IT Subject (3 units: lecture)
void ItSubject3units() {
    double lecClassStanding, lecMidtermsExam, lecFinalsExam;

    char evalType = ChooseGradePeriodType();

    if (evalType == 'M' || evalType == 'm') {
        cout << "\n====================================MIDTERMS==============================================" << endl;

        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> lecClassStanding;
        if (IsInvalidGrade(lecClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> lecMidtermsExam;
        if (IsInvalidGrade(lecMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double lecMidtermGrade = 0.6 * lecClassStanding + 0.4 * lecMidtermsExam;
        cout << "\nYour Midterm Grade (MG) is: " << lecMidtermGrade << "%" << endl;
        GradeEvaluation(lecMidtermGrade);

        char calcuFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calcuFinals;
        if (calcuFinals == 'Y' || calcuFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "Enter Class Standing Score (0-100): ";
            cin >> lecClassStanding;
            cout << "Enter Final Exam (FE) Score (0-100): ";
            cin >> lecFinalsExam;
            if (IsInvalidGrade(lecFinalsExam))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }
            // display grades for each requirement
            cout << "\nLIST OF GRADES: " << endl;
            cout << "[1] CLASS STANDING: " << lecClassStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << lecMidtermsExam << endl;
            cout << "[3] FINAL EXAM SCORE: " << lecFinalsExam << endl;

            // Computation for finals in IT Subj 3 units
            double lecFinalGrade = 0.6 * lecClassStanding + 0.15 * lecMidtermsExam + 0.25 * lecFinalsExam;

            // display result & final grade w/ evaluation
            cout << "\nYour Final Grade (FG) is: " << lecFinalGrade << "%" << endl;
            GradeEvaluation(lecFinalGrade);
        }
    }
    else if (evalType == 'F' || evalType == 'f')
    {
        cout << "\n====================================FINALS==============================================" << endl;

        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> lecClassStanding;
        if (IsInvalidGrade(lecClassStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> lecMidtermsExam;
        if (IsInvalidGrade(lecMidtermsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Final Exam (FE) Score (0-100): ";
        cin >> lecFinalsExam;
        if (IsInvalidGrade(lecFinalsExam))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        cout << "\nLIST OF GRADES: " << endl;
        cout << "[1] CLASS STANDING: " << lecClassStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << lecMidtermsExam << endl;
        cout << "[3] FINAL EXAM SCORE: " << lecFinalsExam << endl;

      // computation for finals
        double lecFinalGrade = 0.6 * lecClassStanding + 0.15 * lecMidtermsExam + 0.25 * lecFinalsExam;

        // results and final grades
        cout << "\nYour Final Grade (FG) is: " << lecFinalGrade << "%" << endl;
        GradeEvaluation(lecFinalGrade);
    }
}

// Functionality for IT Subject (integrated, combined lecture & lab)
void ItSubjectIntegrated() {
    double classStanding, midtermExamScore, finalsExamScore;

    char evalType = ChooseGradePeriodType();

    if (evalType == 'M' || evalType == 'm') {
        cout << "\n====================================MIDTERMS==============================================" << endl;

        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> classStanding;
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> midtermExamScore;
        if (IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        double midtermGrade = 0.6 * classStanding + 0.4 * midtermExamScore;
        cout << "\nYour Midterm Grade (MG) is: " << midtermGrade << "%" << endl;
        GradeEvaluation(midtermGrade);

        char calcuFinals;
        cout << "Do you also want to compute for finals?[Y/N]: ";
        cin >> calcuFinals;
        if (calcuFinals == 'Y' || calcuFinals == 'y') {
            cout << "\n====================================FINALS==============================================" << endl;
            cout << "Enter Class Standing (CS) Score (0-100): ";
            cin >> classStanding;
            if (IsInvalidGrade(classStanding))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "Enter Final Exam Score (0-100): ";
            cin >> finalsExamScore;
            if (IsInvalidGrade(finalsExamScore))
            {
                cout << "Invalid input. Terminating...";
                exit(0);
            }

            cout << "\nLIST OF GRADES: " << endl;
            cout << "[1] CLASS STANDING: " << classStanding << endl;
            cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
            cout << "[3] FINAL EXAM SCORE: " << finalsExamScore << endl;


            double finalGrade = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalsExamScore;
            cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
            GradeEvaluation(finalGrade);
        }
    }
    else if (evalType == 'F' || evalType == 'f') // finals option
    {
        cout << "\n====================================FINALS==============================================" << endl;
        cout << "Enter Class Standing (CS) Score (0-100): ";
        cin >> classStanding;
        if (IsInvalidGrade(classStanding))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Midterm Exam (ME) Score (0-100): ";
        cin >> midtermExamScore;
        if (IsInvalidGrade(midtermExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }
        cout << "Enter Final Exam (FE) Score (0-100): ";
        cin >> finalsExamScore;
        if (IsInvalidGrade(finalsExamScore))
        {
            cout << "Invalid input. Terminating...";
            exit(0);
        }

        // display list of grades
        cout << "\nLIST OF GRADES: " << endl;
        cout << "[1] CLASS STANDING: " << classStanding << endl;
        cout << "[2] MIDTERM EXAM SCORE: " << midtermExamScore << endl;
        cout << "[3] FINAL EXAM SCORE: " << finalsExamScore << endl;

        double finalGrade = 0.6 * classStanding + 0.15 * midtermExamScore + 0.25 * finalsExamScore;
        // double finalGrade =  0.6 * classStanding + 0.4 * midtermExamPercentage;
        cout << "\nYour Final Grade (FG) is: " << finalGrade << "%" << endl;
        GradeEvaluation(finalGrade);
    }
}

// Choosing a course
void ChooseSubject() {
    cout << "\nEnter Subject Number: ";
    cin >> course;

    switch (course) {
        case 1:
            GenEd();
            break;
        case 2:
            ItSubject2units();
            break;
        case 3:
            ItSubject3units();
            break;
        case 4:
            ItSubjectIntegrated();
            break;
        case 5:
            // Exit button, terminates the program
            cout << "\033[1mExiting program....\033[0m" << endl;
            cout << "\033[1mThank you for using FEU Alabang Grading System!🔰\033[0m" << endl;
            exit(0);
        default:
            cout << "Invalid input, please choose a number from 1-5 only." << endl;
    }
}

// loop to compute again and to choose another course
void CourseLoop()
{
    char choice;

    do
    {
        DisplayMenu();
        ChooseSubject();

        cout << "\nDo you want to compute again? [Y/N]: ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            cout << "\033[1mExiting program....\033[0m" << endl;
            cout << "\033[1mThank you for using FEU Alabang Grading System!🔰\033[0m" << endl;
            break;
        } else if (choice == 'Y' || choice == 'y') {
            continue;
        } else {
            cout << "Invalid entry. Enter Y or N only." << endl;
        }

    } while (true);
}

// Main function
int main() {
    CourseLoop();
    return 0;
}
