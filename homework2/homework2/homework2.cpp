#include "stdafx.h"



int main()
{
    /*my3mVector test1(3, 4, 5);
    test1.printVector();
    cout << endl;
    test1.printLength();


    my3mVector test2(4, -3, 2);
    my3mVector test3;
    test3 = test2 + test1;
    cout << endl;
    test3.printVector();
    cout << endl;
    test3.printLength();


    long test4 = test1 * test2;
    cout << endl << test4;

    
    test3 = test2 - test1;
    cout << endl;
    test3.printVector();*/

    my3mVector test1(1, -1, 1);
    my3mVector test2(2, 3, 2);
    test1.printLength();
    cout << endl;
    test2.printLength();
    cout << endl << test1 * test2;

    cout << endl << test2.vectorCos(test1);
}

