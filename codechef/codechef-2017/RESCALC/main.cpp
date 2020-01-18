#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    int t;
    cin>>t;

    while(t>0)              // t test cases
    {
        vector<vector<int> > A;    // declare 2D array for No of players
        int N;
        cin>>N;
        A.resize(N);        // making rows - one for each member
        vector< int > score;
        score.resize(N);    // making score array for storing score of members
        int noOfCookies=0;

        for(int i=0; i<N; i++)      // performing operations for each member
        {
            bool isdiff[6]= {false};       // array for watching which type of cookie has occurred

            cin>>noOfCookies;
            A[i].resize(noOfCookies); // making columns for each member
            for(int j=0; j<noOfCookies; j++)            // entering type of cookies
            {
                cin>>A[i][j];
                isdiff[A[i][j] -1]=true;        // marking true when that type of cookie has been encountered
            }
            int diffcookiescore=0;
            int diffcookies=0;

            for(int kk=0; kk<6; ++kk)
            {
                if(isdiff[kk]==true)
                {
                    diffcookies++;   // checking how many types of cookies has occurred
                }
            }

            // marking scores based on how many diff types of cookie are present
            if(diffcookies==4)
            {
                diffcookiescore=1;
            }
            else if(diffcookies==5)
            {
                diffcookiescore=2;
            }
            else if(diffcookies==6)
            {
                diffcookiescore=4;
            }
            // making final score
            score[i]= noOfCookies+diffcookiescore;
        }

        // we now have marks of each member
        // find max
        int maximum=score[0];
        int maxAt=0;
        for(int m=1; m<score.size(); ++m)
        {
            if(score[m]>maximum)
            {
                maximum=score[m];
                maxAt=m;
            }
        }
        // see if two MAX scores are equal
        bool tie=false;

        for(int mm=0; mm<score.size(); ++mm)
        {
            if(mm==maxAt)
            {
                continue;
            }
            if(score[mm]==maximum)
            {
                tie=true;
                break;
            }
        }

        int winnerindex=maxAt+1;

        if(tie==true)
        {
            cout<<"tie\n";
            break;
        }

        if(winnerindex==1)
        {
            cout<<"chef\n";
        }
        else
        {
            cout<<winnerindex<<"\n";
        }
    t--;
    }

    return 0;
}
