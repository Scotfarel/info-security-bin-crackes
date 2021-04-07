#include <iostream>

using namespace std;

void crackme_1(char* username)
{
  char v2;          // [esp+6h] [ebp-1Ah]
  char v3;          // [esp+17h] [ebp-9h]
  char* i;          // [esp+18h] [ebp-8h]
  signed int v5;    // [esp+1Ch] [ebp-4h]

  v5 = 0x455FAD;
  for ( i = username; *i; ++i )
  {
    v2 = *i;
    if (*i <= 109) {
      v3 = v2 ^ 0x13;
    }
    else {
      v3 = v2 ^ 0x88;
    }
    v5 += (char)(v3 + 1);
  }
  printf("%d\n", v5 ^ 0x2A47D56);
}