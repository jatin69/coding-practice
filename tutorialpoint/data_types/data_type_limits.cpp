/*
@ref - geeksforgeeks
*/

/*
Using Macros of limits.h to define proper limits
*/

#include<iostream>
#include<limits.h> // for int,char macros
#include<float.h> // for float,double macros
#include<iomanip> // for setw

using namespace std;
int main()
{
// Displaying ranges with the help of macros

cout << "\t\tRanges of various data types using MACROS from limits.h and floats.h " << "\n";

cout << "\n\n";
cout << setw(30) << "Data type "               << setw(21) << "MIN"     << setw(6) << ""    << setw(22) <<  "MAX"      << "\n";
cout << "\t---------------------------------------------------------------------------------------\n";
cout << setw(30) << "char : "                    << setw(21) << CHAR_MIN  << setw(6) << "to " << setw(22) <<  CHAR_MAX   << "\n";
cout << setw(30) << "short char : "              << setw(21) << SCHAR_MIN << setw(6) << "to " << setw(22) <<  SCHAR_MAX  << "\n";
cout << setw(30) << "unsigned char : "           << setw(21) <<        0  << setw(6) << "to " << setw(22) <<  UCHAR_MAX  << "\n";

cout << "\n\n";
cout << setw(30) << "short int : "               << setw(21) << SHRT_MIN  << setw(6) << "to " << setw(22) <<  SHRT_MAX   << "\n";
cout << setw(30) << "unsigned short int : "      << setw(21) <<        0  << setw(6) << "to " << setw(22) <<  USHRT_MAX  << "\n";
cout << setw(30) << "int : "                     << setw(21) << INT_MIN   << setw(6) << "to " << setw(22) <<  INT_MAX    << "\n";
cout << setw(30) << "unsigned int : "            << setw(21) <<        0  << setw(6) << "to " << setw(22) <<  UINT_MAX   << "\n";

cout << "\n\n";
cout << setw(30) << "long int : "                << setw(21) << LONG_MIN  << setw(6) << "to " << setw(22) <<  LONG_MAX   << "\n";
cout << setw(30) << "unsigned long int : "       << setw(21) <<        0  << setw(6) << "to " << setw(22) <<  ULONG_MAX  << "\n";
cout << setw(30) << "long long int : "           << setw(21) << LLONG_MIN << setw(6) << "to " << setw(22) <<  LLONG_MAX  << "\n";
cout << setw(30) << "unsigned long long int : "  << setw(21) <<        0  << setw(6) << "to " << setw(22) <<  ULLONG_MAX << "\n";

cout << "\n\n";
cout << setw(30) << "float : "                   << setw(21) <<  FLT_MIN  << setw(6) << "to " << setw(22) <<  FLT_MAX    << "\n";
cout << setw(30) << "negative float : "          << setw(21) << -FLT_MIN  << setw(6) << "to " << setw(22) << -FLT_MAX    << "\n";
cout << setw(30) << "double : "                  << setw(21) <<  DBL_MIN  << setw(6) << "to " << setw(22) <<  DBL_MAX    << "\n";
cout << setw(30) << "negative double : "         << setw(21) << -DBL_MIN  << setw(6) << "to " << setw(22) << +DBL_MAX    << "\n";

return 0;

}
