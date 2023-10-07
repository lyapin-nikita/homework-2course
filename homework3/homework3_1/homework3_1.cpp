
#include "include.h"



int main()
{
    student test1;
    student test2;
    cin >> test1;
    cout << endl;
    cin >> test2;
    //cout << test1;

    studentsGroup testGroup1;
    cout << endl << endl << endl;
    testGroup1.addStudent(test1);
    testGroup1.addStudent(test2);
    testGroup1.delStudent(53);
    cout << endl;
    cout << testGroup1.srhStudent_FullName("Lyapin", "Nikita", "Alex");

    cout << testGroup1;
}

