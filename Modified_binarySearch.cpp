// C++ code to implement the above approach
#include<bits/stdc++.h>
using namespace std;

#define N 3
#define PowerOf2 4

int Numeric_Base_Search(int arr[], int M, 
						int target){
	unsigned long long i, step1, 
	step2 = PowerOf2, times;

	// Find the first power of N 
	// greater than the array size
	for (step1 = 1; step1 < M; step1 *= N);
	
	for (i = 0; step1; step1 /= N)

		// Each time a power can be used
		// count how many times 
		// it can be used
		if (i + step1 < M && arr[i + step1] 
			<= target){
			for (times = 1; step2; 
				step2 >>= 1)
				if (i + 
					(step1 * (times + step2)) 
					< M && 
					arr[i + 
					(step1 * (times + step2))] 
					<= target)
					times += step2;

			step2 = PowerOf2;

			// Add to final result 
			// how many times 
			// can the power be used
			i += times * step1;
		}

	// Return the index 
	// if the element is present in array
	// else return -1
	return arr[i] == target ? i : -1;
}

// Driver code
int main(){
	int arr[10] = 
	{1, 4, 5, 8, 11, 15, 21, 45, 70, 100};
	int target = 45, M = 10;
	int answer = Numeric_Base_Search(arr, M, target);
	cout<<answer;
	return 0;
}
