#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define BIT_SIZE  1250000
#define NUM_SIZE  1000000
#define MAX_NUM 10000000

void gen_random_num( unsigned int *num )
{
    ofstream out( "rand_num_file.txt" );
    /*
    srand( (unsigned)time(0) );

    for (int i=0; i<NUM_SIZE; ++i)
        num[i] = rand() % MAX_NUM;
    */
    for (int i=0; i<NUM_SIZE; ++i)
        num[i] = MAX_NUM - i;
    for (int i=0; i<NUM_SIZE; ++i)  //35
        out <<num[i] <<",";

    out.close();
}

void zero_bit( unsigned char *bit)
{
    for (int i=0; i<BIT_SIZE; ++i)
        bit[i] &= 0x00;
    /*
    printf ("In initialization: ");
    for (int i=0; i<BIT_SIZE; ++i)
        printf( "%x ", bit[i] );
    printf( "/n" );
    */
}

void pro_bit( unsigned char *bit, unsigned int *num )
{
    unsigned int j, k;
    unsigned char s = 0x80;

    for (int i=0; i<NUM_SIZE; ++i)   //58
    {
        j = num[i] / 8;
        k = num[i] % 8;

        if (k == 0)
            bit[j-1] |= 0x01;
        else
            bit[j] |= ( s>>(k-1) );
    }
    /*
    printf ("In processing: ");
    for (int i=0; i<BIT_SIZE; ++i)
        printf( "%x ", bit[i] );
    */
}

void output_to_file( unsigned char *bit )
{
    unsigned char s = 0x80;
    ofstream fp( "sorted_num.txt" );

    for ( int i=0; i<BIT_SIZE; ++i )
    {
        for ( int j=1; j<=8; ++j )
        {
            if ( bit[i] & (s>>(j-1)) )
                fp <<8*i+j <<"/n";
        }
    }
    fp.close();
}

int main()
{
    //char bit[ BIT_SIZE ];
    unsigned char *bit = ( unsigned char * )malloc( BIT_SIZE * sizeof(char) );
    //int num[ NUM_SIZE ];
    unsigned int *num = ( unsigned int * )malloc( NUM_SIZE * sizeof(int) );

    // Initialization
    gen_random_num( num );
    zero_bit( bit );

    // processing
    pro_bit( bit, num );

    // output to file
    output_to_file( bit );

    return 0;
}