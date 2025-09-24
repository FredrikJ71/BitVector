//some tests of BitVector
#include"BitVector.h"
#include<iostream>

int main(){
    std::cout << "Testing BitVector\n";
    std::cout << "Create using default constructor\n";
    fj71cpp::BitVector myVec;
    std::cout << "Testing to create bitvectors of different length\n";
    for(int i=0;i<200;++i){
        myVec = fj71cpp::BitVector(i);
    }
    //create a bitvector of length 64
    //get all bits and one extra to trigger exception
    myVec= fj71cpp::BitVector(64);
    for(int i=0;i<=64;++i){
        int bit = myVec.get(i);
        std::cout << i << ", " << bit << '\n';
    }
    std::cout << "\n";
}
