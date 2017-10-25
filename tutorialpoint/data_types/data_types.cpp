/*
@author - Jatin Rohilla
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define u unsigned
#define i int
#define s short
#define l long
#define f float
#define d double

/*
* Can be used to print ranges of data types - upto a certain limit
* For extended limits, use limit.h
*/
void printUnsignedRange(u i bytes)
{
    i bits=bytes*8;
    u l i to;
    // to prevent overflow by excess shifting, we form this addition logic
    to = ((1<<(bits-1)))+((1<<(bits-1))-1);
    cout << setw(30) << "Range : " << to << "\n\n";
}

void printSignedRange(i bytes)
{
    i bits=bytes*8;
    l l i to,from;
    from= - (1<<(bits-1));
    to = (1<<(bits-1))-1;
    cout << setw(30) << "Range : " << from << " to " << to << "\n\n";
}

int main(){
    cout<<right;
    cout << setw(50) << " >>>> Data types with sizes and Ranges" << "\n";

    cout << "\n\t\t >>>>> Integers\n" << "\n";

    cout << setw(30) << "short int : "<< sizeof(s i) << "\n";
    printSignedRange(sizeof(s i));
    cout << setw(30) << "unsigned short int : "<< sizeof(u s i) << "\n";
    printUnsignedRange(sizeof(u s i));
    cout << setw(30) << "int : "<< sizeof(i) << "\n";
    printSignedRange(sizeof(i));
    cout << setw(30) << "unsigned int : "<< sizeof(u i) << "\n";
    printUnsignedRange(sizeof(u i));

    /// Range estimation fails after this, for ranges use limits.h
    cout << setw(30) << "long int : "<< sizeof(l i) << "\n";
    cout << setw(30) << "unsigned long int : "<< sizeof(u l i) << "\n";
    cout << setw(30) << "long long int : "<< sizeof(l l i) << "\n";
    cout << setw(30) << "unsigned long long int : "<< sizeof(u l l i) << "\n";

    cout << "\n\t\t >>>>> Floating points \n" << "\n";
    cout << setw(30) << "float : "<< sizeof(f) << "\n";
    cout << setw(30) << "unsigned float : " << "not allowed" << "\n";
    cout << setw(30) << "short float : " << "not allowed" << "\n";
    cout << setw(30) << "long float : " << "not allowed" << "\n";

    cout << "\n";
    cout << setw(30) << "short double : " << "not allowed" << "\n";
    cout << setw(30) << "unsigned double : " << "not allowed" << "\n";
    cout << setw(30) << "double : "<< sizeof(d) << "\n";
    cout << setw(30) << "long double : " << sizeof(l d) << "\n";

    cout << "\n\t\t >>>>> Character \n" << "\n";
    cout << setw(30) << "char : "<< sizeof(char) << "\n";
    cout << setw(30) << "wchar_t : "<< sizeof(wchar_t) << "\n";

    cout << "\n\t\t >>>>> Bool \n" << "\n";
    cout << setw(30) << "bool : "<< sizeof(bool) << "\n";

    return 0;
}
