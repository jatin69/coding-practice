/*
 * Author : Jatin Rohilla
 * Date   :
 *
 * Editor   : Dev c++ 5.11
 * Compiler : g++ 5.1.0
 * flags    : -std=c++11
 *
 */


#include<bits/stdc++.h>
using namespace std;

#define HELLO(x) cout << x ;

int main()
{
	HELLO ("ok");
	return 0;
}

//
//void getMeanStd(std::vector<float> &values, double &mean, double &stddev)
//{
//  // throw an exception when the input array is empty
//  if(values.size() == 0 )
//  {
//    throw std::length_error("Error : Input array must have at least 1 element.");
//  }
//  
//  // when the array has only one element, mean is the number itself and standard dev is 0
//  if(values.size() == 1)
//  {
//	mean = static_cast<double>(values.at(0));
//	stddev = 0;
//	return;
//  }
//  
//
//  double sum = 0, sq_sum = 0;
//
//  for (size_t i = 0; i < values.size (); ++i)
//  {
//    sum += values[i];
//    sq_sum += values[i] * values[i];
//  }
//  mean = sum / static_cast<double>(values.size ());
//  double variance = (sq_sum - sum * sum / static_cast<double>(values.size ())) / (static_cast<double>(values.size ()) - 1);
//  stddev = sqrt (variance);
//  
//}
//
//
//int main(){
//
//
//	vector<float> A = {1.1  } ;
//	
//	double mean = -1;
//	double stddev = -1;
//	getMeanStd(A, mean, stddev);
// cout << "mean : " << mean <<",  "<< stddev;
//    return 0;
//}

