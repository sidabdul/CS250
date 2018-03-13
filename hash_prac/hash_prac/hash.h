//
//  hash.h
//  hash_prac
//
//  Created by Sid-Ali Isgow on 3/4/15.
//  Copyright (c) 2015 Sid-Ali Isgow. All rights reserved.
//

#ifndef __hash_prac__hash__
#define __hash_prac__hash__

#include <iostream>
#include <cctype>
#include <fstream>
#include <cstring>



int const TABLE_SIZE = 30;



struct node
{

    int x;
    node * next;


};

class hash
{

    public:
    hash();
    ~hash();
    
    int hashfunc(int key);
    int insert(int num);
    int display();
    int remove(int match);

    
    private:
    
    node ** hash_table;



};












#endif /* defined(__hash_prac__hash__) */
