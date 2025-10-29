
#include"BitVector.h"
#include<iostream>

namespace fj71cpp {

//Default constructor, defines Binary Vector with 1 bit, with value 0
BitVector::BitVector(){
    // set all length equal to 1 and value to 0
    mLength = 1;
    mLength64 = 1;
    mLastWord = 1;
    mMask = 1;
    mBitVector = std::vector<uint64_t>{0};
}

//Create a BitVector that can store n bits
BitVector::BitVector(int n){
    //set length 
    mLength = n;
    updateLengthParam();
    //create vector to store bits
    mBitVector = std::vector<uint64_t>(mLength64);    
}

//get the value at position k
//if k is not in the range, throws out_of_range exception
int BitVector::get(int k){
    if(k<0 || k>= mLength ) {
        throw std::out_of_range("k not in range of BitVector");
    }
    int word = k/mBitInWord;
    int pos = k % mBitInWord;
    uint64_t mask = 1ULL << pos;
    if((mBitVector[word]&mask) == 0)
        return 0;
    return 1;
}

//set the value at position k to val 
//note! all non-zero values of val are interpreted as 1
//if k is not in the range, throws out_of_range exception
void BitVector::set(int k, int val){
    if(k<0 || k>= mLength ) {
        throw std::out_of_range("k not in range of BitVector");
    }
    int word = k/mBitInWord;
    int pos = k % mBitInWord;
    uint64_t mask = 1ULL << pos;
    if(val == 0){
        // set bit to 0
        mBitVector[word]&=~mask;
    }
    else {
        //set bit to 1
        mBitVector[word]|= mask;

    }
}

//when length is set use this method to update other size dependent variables
void BitVector::updateLengthParam(){
    //calculate how many 64 bit words that are needed to store mLength bit,
    //and how many bits are in the last word
    mLength64 = 1 + (mLength-1)/mBitInWord;
    mLastWord = mLength % mBitInWord;
    if(mLastWord == 0){
        mLastWord=64;
    }
    //set mask to filter last word
    if(mLastWord==64){
        mMask = 0xffffffffffffffffULL;
    }
    else {
         mMask = (1ULL << mLastWord) -1 ;
    }
   
}


} //namespace
