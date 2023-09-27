#include "stdafx.h"



int main()
{


    my3mVector test3;
    my3mVector test4;
    cout << "enter the vector: ";
    cin >> test3;
    cout << endl;
    cout << "enter the vector: ";
    cin >> test4;
    cout << endl << test3 << endl << test4 << endl << endl;

    cout << test3 + test4 << endl;
    cout << test3 - test4 << endl;
    cout << test3 * test4 << endl;
    cout << test3.getLength() << endl;
    cout << test4.getLength() << endl;
    try { cout << test3.vectorCos(test4); }
    catch (...) { cout << "error: divide into 0!"; }



}

