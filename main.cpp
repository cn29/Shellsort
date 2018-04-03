#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<time.h>

using namespace std;

int SEED = time(NULL);
int N = 100;

vector<int> shellsort(vector<int> arr, vector<int> gap_seq) {
	int n = arr.size(), temp;
	int i, j, gap, g;
	for (g = 0; g < gap_seq.size(); g++) {
		gap = gap_seq[g];
		if (gap >= n)
			continue;
		for (i = gap; i < n; i++) {
			temp = arr[i];
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
	return arr;
}

vector<int> arr_gen(int arr_size) {
	vector<int> res(arr_size, 0);
	srand(SEED);
	//cout << "SEED: " << SEED << endl;
	for (int i = 0; i != arr_size; i++) {
		res[i] = rand() % 1000000;
	}
	return res;
}

int main() {
	vector<int> gap1, gap2, gap3;
	gap1 = { 1750, 701, 301, 132, 57, 23, 10, 4, 1 };
	gap2 = { 265720, 88573, 29524, 9841, 1093, 364, 121, 40, 13, 4, 1 };
	gap3 = { 153401, 68178, 30301, 13467, 5985, 2660, 1182, 525, 233, 103, 46, 20, 9, 4, 1,};
	vector<int> arr1, arr2, res1, res2;
	int gen_size = 400000;
	arr1 = arr_gen(gen_size);

	clock_t tStart = clock();
	clock_t t1 = 0;

	for (int i = 0; i < N; i++) {
		arr1 = arr_gen(gen_size);
		clock_t t11 = clock();
		res1 = shellsort(arr1, gap3);
		//cout << res1[rand() % gen_size];
		t1 += clock() - t11;
	}
	clock_t t2 = 0;
	for (int i = 0; i < N; i++) {
		arr1 = arr_gen(gen_size);
		clock_t t22 = clock();
		res2 = shellsort(arr1, gap2);
		t2 += clock() - t22;
		//cout << res2[rand() % gen_size];
	}
	clock_t t3 = clock();


	cout << "\n-------- First Application --------\n";
	cout << "Time elapsed: " << float(t2 - tStart) / CLOCKS_PER_SEC << " sec" << endl;
	cout << "Time elapsed: " << float(t1) / CLOCKS_PER_SEC << " sec" << endl;
	cout << "\n-------- Second Application --------\n";
	cout << "Time elapsed: " << float(t3 - t2) / CLOCKS_PER_SEC << " sec" << endl;
	cout << "Time elapsed: " << float(t2) / CLOCKS_PER_SEC << " sec" << endl;
	for (int i = 0; i < 100; i++) {
		cout << res1[i] << "," << res2[i] << " ";
		if (i % 10 == 9)
			cout << endl;
	}
	cin.get();
	return 0;
}