
#include"BitVector.h"

namespace fj71cpp {

//Default constructor, defines Binary Vector with 1 bit, with value 0
BitVector::BitVector(){
    // set all length equal to 1 and value to 0
    mLength = 1;
    mLength64 = 1;
    mLastWord = 1;
    mMask = 1;
    mBitVector = std::vector<unsigned long long>{0};
}

//Create a BitVector that can store n bits
BitVector::BitVector(int n){
    //set length 
    mLength = n;
    //calculate how many 64-bit words that are required for n bits
    mLength64 = 1 + (n-1)/64; // at least 1, then + 1 for each group of 64 bits
    //find how many bits that are in the final word that does not need to be exactly 64 bits
    //initiate to full length, then subtract 64 until we have at most 64 bits
    mLastWord = mLength;
    while(mLastWord > 64){
        mLastWord-=64;
    }
    //calculate mask
    mMask = (1ULL << mLastWord) -1 ;
    //create vector to store bits
    mBitVector = std::vector<unsigned long long>(mLength64); 
}

} //namespace
