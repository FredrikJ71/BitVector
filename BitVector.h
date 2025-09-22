#ifndef BIT_VECTOR
#define BIT_VECTOR
namespace fj71cpp {
#include<vector>

//A class for binary vectors. 
class BitVector {

public:

//Default constructor, defines Binary Vector with 1 bit, with value 0
BitVector();



private:
std::vector<unsigned long long> mBitVector; //the storage of the bits
int mLength; //the number of bits in the vetor
int mLength64; //the number of 64-bit words needed to store mLength bits
int mLastWord; //the number of bits stored in last word of the array
unsigned long long mMask; //the last mLastWord bits are 1 rest is 0

}; //class


} //namespace
#endif //BIT_VECTOR
