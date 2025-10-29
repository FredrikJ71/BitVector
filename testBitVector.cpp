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
    //create a bitvector of length 128
    myVec= fj71cpp::BitVector(128);
    //set all bits with a position a prime number to 1
    myVec.set(2,1);
    myVec.set(3,1);
    myVec.set(5,1);
    myVec.set(7,1);
    myVec.set(11,1);
    myVec.set(13,1);
    myVec.set(17,1);
    myVec.set(19,1);
    myVec.set(23,1);
    myVec.set(29,1);
    myVec.set(31,1);
    myVec.set(37,1);
    myVec.set(41,1);
    myVec.set(43,1);
    myVec.set(47,1);
    myVec.set(53,1);
    myVec.set(59,1);
    myVec.set(61,1);
    myVec.set(67,1);
    myVec.set(71,1);
    myVec.set(73,1);
    myVec.set(79,1);
    myVec.set(83,1);
    myVec.set(89,1);
    myVec.set(97,1);
    myVec.set(101,1);
    myVec.set(103,1);
    myVec.set(107,1);
    myVec.set(109,1);
    myVec.set(113,1);
    myVec.set(127,1);
    
    //print all bits
    for(int i=0;i<128;++i){
        int bit = myVec.get(i);
        std::cout << i << ", " << bit << '\n';
    }
    std::cout << "\n";

    // set all bits to 1
    for(int k=0;k<128;++k){
        myVec.set(k,1);
    }

    //print all bits
    for(int i=0;i<128;++i){
        int bit = myVec.get(i);
        std::cout << i << ", " << bit << '\n';
    }
    std::cout << "\n";

    // set all bits to 0
    for(int k=0;k<128;++k){
        myVec.set(k,0);
    }

    //print all bits
    for(int i=0;i<128;++i){
        int bit = myVec.get(i);
        std::cout << i << ", " << bit << '\n';
    }
    std::cout << "\n";

}
