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

    //my3mVector test1(1, -1, 1);
    //my3mVector test2(2, 3, 2);
    my3mVector test3;
    my3mVector test4;
    cin >> test3;
    cout << endl;
    cin >> test4;
    cout << endl << test3 << endl << test4 << endl << endl;

    cout << test3 + test4 << endl;
    cout << test3 - test4 << endl;
    cout << test3 * test4 << endl;
    try { cout << test3.vectorCos(test4); }
    catch (...) { cout << "error: divide into 0!"; }



}

