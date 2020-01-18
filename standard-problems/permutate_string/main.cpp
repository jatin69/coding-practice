#include <iostream>
using namespace std;

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */

//   bool was[256]={false};
void permute(string str , int l, int r)
{
   if (l == r)
        cout << str<< "\n";
   else
   {
       for (int i = l; i <= r; i++)
       {
  //         if(!was[str[i]]){
           swap(str[l],str[i]);
            permute(str, l+1, r);
           swap(str[i],str[l]);
    //       was[str[i]]=true; }
           }
   }
}

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    cout << endl << "The permutations of the given string : " << endl;
    permute(s, 0, s.length() - 1);
    cout << endl;
}


/*
#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

void print_all_permutations(const string& s)
{
    string s1 = s;
    sort(s1.begin(), s1.end());
    do {
        cout << s1 << endl;
    } while (next_permutation(s1.begin(), s1.end()));
}

int main()
{
    print_all_permutations("AAB");
}
*/
