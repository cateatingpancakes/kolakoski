/*
 * 
 * This is an implementation of the space-efficient Kolakoski algorithm given by
 * Johan Nilsson @ the Faculty of Mathemathics, Bielefeld University in his paper
 * published in the Journal of Integer Sequences, 2012
 * 
 * https://www.emis.de/journals/JIS/VOL15/Nilsson/nilsson5.pdf
 *  
 */

#include <iostream>
#include <cstdint>

const int BUF_SIZE = 200; // For this TERM_CNT, only 46 of the 200 allocated
                          // integers will actually be used by IncrementPointer
const int_fast64_t TERM_CNT = 300000000;

int P[BUF_SIZE];

int IncrementPointer(int k)
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

int main()
{
    int_fast64_t ones = 1; // Count the term K_1 = 1
    std::cout << "Kolakoski sequence, O(log n) space:\n";

    for(int_fast64_t i = 3; i <= TERM_CNT; i++)
        ones += (IncrementPointer(0) == 1);

    std::cout << "Found " << ones << " ones (n=" << TERM_CNT << ")\n";

    return 0;
}