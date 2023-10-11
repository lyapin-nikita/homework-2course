
#include "include.h"



int main()
{
    //student test1;
    //student test2;
    //cin >> test1;
    //cout << endl;
    //cin >> test2;
    ////cout << test1;

    //studentsGroup testGroup1;
    //cout << endl << endl << endl;
    //testGroup1.addStudent(test1);
    //testGroup1.addStudent(test2);
    //testGroup1.delStudent(53);
    //cout << endl;
    //cout << testGroup1.srhStudent_FullName("Lyapin", "Nikita", "Alex");

    //cout << testGroup1;
     studentsGroup testGroup1;
     cout << endl << testGroup1.getSize() << endl;
     cout << testGroup1 << endl;

    // student testStd1;
    // cin >> testStd1;

     cout << endl << "the adding of new student";
     //testGroup1.addStudent(testStd1);
     testGroup1.delStudent(testGroup1.srhStudent_DayOfBirth(1, 1, 1));
     
     cout << endl << testGroup1.srhStudent_FullName("z", "x", "c") << endl;
     cout << testGroup1.srhStudent_DayOfBirth(1, 1, 1);
}

