// A C++ program uses transform() in STL to add 
// 1 to all elements of arr[]
#include <bits/stdc++.h>
using namespace std;
  
int increment(int x) {  return (x+1); }

// this is a functor
struct add_x {
  add_x(int x) : x(x) {}
  int operator()(int y) const { return x + y; }

private:
  int x;
};
  
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    // Apply increment to all elements of
    // arr[] and store the modified elements
    // back in arr[]
    transform(arr, arr+n, arr, increment);
    vector<int> in[5]; // assume this contains a bunch of values)
    in[0]=1;
    in[1]=2;
    in[2]=3;
    in[3]=4;
    in[4]=5;
	vector<int> out(in.size());
	// Pass a functor to std::transform, which calls the functor on every element 
	// in the input sequence, and stores the result to the output sequence
	transform(in.begin(), in.end(), out.begin(), add_x(1)); 
	//assert(out[i] == in[i] + 1); // for all i
  
    for (int i=0; i<out.size(); i++)
        cout << out[i] << " ";
  
    return 0;
}

