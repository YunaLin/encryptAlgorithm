#include <string>
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef char BYTE;

class MD5 {
private:
	UINT32 s[4][4] = {
		{ 7,12,17,22 },{ 5,9,14,20 },{ 4,11,16,23 },{ 6,10,15,21 }
	};
	UINT32 IV[4] = {
		0x67452301,0xEFCDAB89,0x98BADCFE,0x10325476
	};
	UINT32 T[64];
	string message;
public:
	UINT32 result[4];   //  the final result
public:
	MD5(string str);
	// expand the initial message to be times of 512 bits
	void generateT();
	BYTE* expand();
	//  the index of X[j]
	UINT32 getIndexOfX(UINT32 j, UINT32 k);
	//  get result of function FGHI
	UINT32 getFunctionRes(UINT32 cycleN, UINT32 B, UINT32 C, UINT32 D);
	UINT32 shiftLeft(UINT32 src, UINT32 shiftN);
	void rotate(UINT32 &A, UINT32 &B, UINT32 &C, UINT32 &D);
	void getResult();
	// little endian int32 to byte at the last
	void processEndian();
	UINT32 F(UINT32 B, UINT32 C, UINT32 D);
	UINT32 G(UINT32 B, UINT32 C, UINT32 D);
	UINT32 H(UINT32 B, UINT32 C, UINT32 D);
	UINT32 I(UINT32 B, UINT32 C, UINT32 D);
};
