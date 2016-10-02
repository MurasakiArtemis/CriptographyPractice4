#include "des.h"
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
    unsigned char* key = new unsigned char[8];
    generate_key(key);
    key_set* keys = new key_set[17];
    generate_sub_keys(key, keys);
    ofstream fOut(argv[1]);
    fOut << "0x";
    for(int i = 0; i < 8; i++)
    {
	fOut << std::hex << setw(2) << setfill('0') << int(key[i]);
    }
    fOut << endl;
    for(int i = 0; i < 17; i++)
    {
	fOut << "0x";
	for(int j = 0; j < 8; j++)
	{
	    fOut << std::hex << setw(2) << setfill('0') << int(keys[i].k[j]);
	}
	fOut << endl;
    }
    return 0;
}
