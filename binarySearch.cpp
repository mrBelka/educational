#include <iostream>
#include <vector>
#include <algorithm>

// key is an array element
int key(int x) {
    return x;
}

// Greg
// return -1 if not found key
int binarySearch(int n, int k, int* arr) {
    if(k < key(arr[0]))
        return -1;
    if(k == key(arr[0]))
        return 0;
    if(k > key(arr[n-1]))
        return -1;
    
    int a = 0;
    int b = n - 1;
    while(a + 1 < b) {
        int c = (a + b) / 2;
        if(k > key(arr[c]))
            a = c;
        else
            b = c;
    }

    if(k == key(arr[b]))
        return b;
    return -1;
}

// Function to implement lower_bound
// https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
int lowerBound(int N, int X, int* arr)
{
	int mid;

	// Initialise starting index and
	// ending index
	int low = 0;
	int high = N;

	// Till low is less than high
	while (low < high) {
		mid = low + (high - low) / 2;

		// If X is less than or equal
		// to arr[mid], then find in
		// left subarray
		if (X <= arr[mid]) {
			high = mid;
		}

		// If X is greater arr[mid]
		// then find in right subarray
		else {
			low = mid + 1;
		}
	}

	// if X is greater than arr[n-1]
	if(low < N && arr[low] < X) {
	low++;
	}
	
	// Return the lower_bound index
	return low;
}

// Function to implement upper_bound
int upperBound(int N, int X, int* arr)
{
	int mid;

	// Initialise starting index and
	// ending index
	int low = 0;
	int high = N;

	// Till low is less than high
	while (low < high) {
		// Find the middle index
		mid = low + (high - low) / 2;

		// If X is greater than or equal
		// to arr[mid] then find
		// in right subarray
		if (X >= arr[mid]) {
			low = mid + 1;
		}

		// If X is less than arr[mid]
		// then find in left subarray
		else {
			high = mid;
		}
	}

	// if X is greater than arr[n-1]
	if(low < N && arr[low] <= X) {
	low++;
	}

	// Return the upper_bound index
	return low;
}

int main() {
    int n = 12;
    //int arr[100] = {5, 1, 2, 3, 8, 10, -1, 4, 0, 2, 1, 7};
    int arr[100] = {1, 2, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5};
    std::vector<int> v = {1, 2, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5};

    std::sort(arr, arr + n);

    // returns lower bound of 3
    // std::cout << binarySearch(n, 3, arr);
    // см. https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c/
    // std::cout << lowerBound(n, 3, arr);
    std::cout << upperBound(n, 3, arr);

    // returns true or false
    // std::cout << std::binary_search(arr, arr + n, 3);

    // iterator on first 3
    // std::cout << std::lower_bound(arr, arr + n, 3);
    
    // iterator on 4
    // std::cout << std::upper_bound(arr, arr + n, 3);

    // pose of 4 in arr
    // std::cout << std::upper_bound(arr, arr + n, 3) - arr;

    // returns:
    // 1. iterator on value
    // 2. if all less then value, iterator on begin
    // 3. if all greater then value, iterator on end
    // std::cout << (std::lower_bound(v.begin(), v.end(), 0) == v.end());

    return 0;
}