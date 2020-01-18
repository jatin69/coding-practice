#include <iostream>

using namespace std;

int main()
{
    int i=4;
    double d=4.0;
    string s="hackerRank ";


    // Declare second integer, double, and String variables.
    int a;
    double b;
    // Read and save an integer, double, and String to your variables.
    cin>>a;
    cin>>b;
    string inputString; // declare a variable to hold our input

 /*
    cin.get();      /// to eat whitespace
    getline(cin,inputString);
*/
/// a better ways is:
///  ws : white spaces
     if(getline(cin>>ws, inputString))
    {
        getline(cin,inputString);
    }

    // Print the sum of both integer variables on a new line.
    cout<<(i+a)<<"\n";
    cout.precision(1);
    // Print the sum of the double variables on a new line.
    cout<<fixed<<(b+d)<<"\n";
    // Concatenate and print the String variables on a new line
    cout<<s<<inputString;
    // The 's' variable above should be printed first.

    return 0;
}
