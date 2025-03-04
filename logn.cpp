/*
 * 
 * This is an implementation of the space-efficient Kolakoski algorithm given by
 * Johan Nilsson @ the Faculty of Mathemathics, Bielefeld University in his paper
 * published in the Journal of Integer Sequences, 2012
 * 
 * https://www.emis.de/journals/JIS/VOL15/Nilsson/nilsson5.pdf
 * 
 * 
 */

#include <iostream>
#include <fstream>

#define BUF_SIZE 100000 // 0,76 MiB overhead
#define TERM_CNT 300000000 // First value of n used for a publication

long long P[BUF_SIZE];

long long IncrementPointer(long long k)
{
    if(P[k] == 0)
    {
        P[k] = 22;
    }
    
    if(P[k] == 11)
    {
        P[k] = 1;
        return 1;
    }
    else if(P[k] == 22)
    {
        P[k] = 2;
        return 2;
    }
    else if(P[k] == 1)
    {
        P[k] = (IncrementPointer(k + 1) == 1) ? 2 : 22;
        return 2;
    }
    else
    {
        P[k] = (IncrementPointer(k + 1) == 1) ? 1 : 11;
        return 1;
    }
}

using namespace std;

int main()
{
    long long ones = 1; // Count the term K_1 = 1
    cout << "Kolakoski sequence, O(log n) space:\n";

    for(long long i = 3; i <= TERM_CNT; i++)
        ones += (IncrementPointer(0) == 1);

    cout << "Found " << ones << " ones (n=" << TERM_CNT << ")\n";

    return 0;
}