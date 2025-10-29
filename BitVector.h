#ifndef BIT_VECTOR
#define BIT_VECTOR

#include<vector>
#include<cstdint>
#include<stdexcept>

namespace fj71cpp {
//A class for binary vectors. 
class BitVector {

public:

//Default constructor, defines Binary Vector with 1 bit, with value 0
BitVector();

//Create a BitVector that can store n bits
BitVector(int n);

//get the value at position k
//if k is not in the range, throws out_of_range exception
int get(int k);

//set the value at position k to val 
//note! all non-zero values of val are interpreted as 1
//if k is not in the range, throws out_of_range exception
void set(int k, int val);


private:
static const int mBitInWord = 64; //64-bit words are used to store bits
std::vector<uint64_t> mBitVector; //the storage of the bits
int mLength; //the number of bits in the vetor
int mLength64; //the number of 64-bit words needed to store mLength bits
int mLastWord; //the number of bits stored in last word of the array
uint64_t mMask; //the last mLastWord bits are 1 rest is 0

//when length is set use this method to update other size dependent variables
void updateLengthParam();

}; //class

} //namespace

#endif //BIT_VECTOR
