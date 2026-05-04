#include <algorithm>
#include <vector>   
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	vector <int> sumStore;
	int n = arr.size();

	for (int i = 0; i < n; i++) {

		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());

	return sumStore[sumStore.size() - k];
}