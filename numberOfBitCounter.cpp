// numberOfChar.cpp
//
// 1のあるビットの数を数えるプログラム
//

#include "stdafx.h"

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// 1のあるビットの数を数えます
int32_t numberOfBitOfChar( uint8_t a ) 
{ 
	printf("%08x," ,a);
	a = ( a & 0x55 ) + ( ( a >> 1 ) & 0x55 ); 
	printf("%08x," ,a);
    a = ( a & 0x33 ) + ( ( a >> 2 ) & 0x33 ); 
	printf("%08x," ,a);
    a = ( a & 0x0f ) + ( ( a >> 4 ) & 0x0f ); 
	printf("%08x\n" ,a);

    return ( int32_t )a; 
} 

// 1のあるビットの数を数えます
int32_t numberOfBitOfUi32( uint32_t a ) 
{ 
	printf("%08x," ,a);
    a = ( a & 0x55555555 ) + ( ( a >> 1 ) & 0x55555555 ); 
	printf("%08x," ,a);
    a = ( a & 0x33333333 ) + ( ( a >> 2 ) & 0x33333333 ); 
	printf("%08x," ,a);
	a = ( a & 0x0f0f0f0f ) + ( ( a >> 4 ) & 0x0f0f0f0f ); 
	printf("%08x," ,a);
	a = ( a & 0x00ff00ff ) + ( ( a >> 8 ) & 0x00ff00ff ); 
	printf("%08x," ,a);
	a = ( a & 0x0000ffff ) + ( ( a >> 16 ) & 0x0000ffff ); 
	printf("%08x\n" ,a);
	return ( int32_t )a; 
}

int _tmain(int argc, _TCHAR* argv[])
{
	int i;

	srand(time(NULL));

	printf("numberOfBitOfChar() Test\n");
	for(i=0;i<60;i++){
		numberOfBitOfChar(rand()); 
	}

	printf("numberOfBitOfUi32() Test\n");
	for(i=0;i<30;i++){
		numberOfBitOfUi32(rand() | (rand()<<16)); 
	}

	getchar();

	return 0;
}

