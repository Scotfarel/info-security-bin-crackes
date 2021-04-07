#include <iostream>

using namespace std;

void crackme_2(char* username)
{
  char v2[4];           // [esp+10h] [ebp-18h]
  signed int v3;        // [esp+14h] [ebp-14h]
  int v4;               // [esp+18h] [ebp-10h]
  char* v5;             // [esp+1Ch] [ebp-Ch]

  v5 = username;
  v4 = 3;
  v3 = 18;
  v2[2] = 7;
  v2[1] = 31;
  v2[3] = 0;
  while ( *v5 )
  {
    v2[0] = *v5;
    v3 += 16 * v2[3];
    v4 = (v3 - *v5) ^ 0x1F;
    v2[3] = *v5++;
  }
  printf("%u-%u\n", abs(v4), abs(v3));
}