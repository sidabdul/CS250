//
//  main.cpp
//  Pointer_prac
//
//  Created by Sid-Ali Isgow on 3/4/15.
//  Copyright (c) 2015 Sid-Ali Isgow. All rights reserved.
//

#include <iostream>


using namespace std;


int main() {
    // insert code here...
    
    
    int x = 5;
    
    int * p = &x;
    
    //*p = 6;
    
    int ** q = &p;
    
    int  *** r = &q;
    
    
    
    
    cout << p <<endl << x <<endl << &x <<endl;
    
    
    
    
    
    
    return 0;
}
