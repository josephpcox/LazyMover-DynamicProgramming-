#include <stdlib.h>
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int bestNumber(map<int, int>& mapBoxes){
	map<int, int>::reverse_iterator it = mapBoxes.rbegin();
	map<int, int>::reverse_iterator end = mapBoxes.rend();

	int max_value = it->second;
	int key = it ->first;
	for(;it != end; ++it)
	{
		if(it->second >= max_value)
		{
			max_value = it->second;
			key = it->first;
		}
	}
	return max_value;
}

int findKey(map<int, int>& mapBoxes, int value){
	map<int, int>::iterator it = mapBoxes.begin();
	map<int, int>::iterator end = mapBoxes.end();

	int match_key = 0;
	while(it != end){
		if(it->second == value){
			match_key = it->first;
		}
		it++;
	}
	return match_key;
}

int findGreatest(int array[], int size, map<int, int>& mapBoxes, int index)
{
	if(index < size - 1){
			findGreatest(array, size, mapBoxes, index + 1);
	}

	int topBox = 0;
	int max_count = 0;
	int count = 0;
	topBox = array[index];

	if(array[index + 1] == NULL){
		max_count = max_count + 1;
		mapBoxes.insert({array[index], max_count});
	}

	if(array[index] < array[index + 1]){
		max_count = max_count + 1;
		mapBoxes.insert({array[index], max_count});
	}

	map<int,int>::iterator it;
	it = mapBoxes.find(array[index + 1]);
	if(it != mapBoxes.end())
	{
		map<int, int>::reverse_iterator it = mapBoxes.rbegin();
		map<int, int>::reverse_iterator end = mapBoxes.rend();

		int max_value = array[index];

		for(;it != end; ++it)
		{
			if(it->first <= max_value)
			{
				max_count = it->second + 1;
				break;
			}
		}
		mapBoxes.insert({array[index], max_count});
	}

	return bestNumber(mapBoxes);
}

int main(int argc, char const *argv[])
{
  /* code */
  int array1[10] = {29, 20, 30, 18, 35, 26, 28, 40, 8, 39};
  int size1 = 10;

	map<int, int> maxBoxMap;
	map<int, int> numberOfBoxes;
	numberOfBoxes.insert({2,15});
	numberOfBoxes.insert({1,25});
	numberOfBoxes.insert({3,8});

	cout << "Testing bestNumber function: " << bestNumber(numberOfBoxes) << endl;
	int value = findKey(numberOfBoxes, 25);
	cout << "Finding key for value 25: " << value << endl;
	int array2[20] = {38, 35, 45, 39, 23, 16, 26, 28, 20, 5, 8, 17, 12, 10, 13, 42, 6, 34, 33, 37};
	int size2 = 20;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;

	int array3[5] = {26, 25, 24, 24, 23};
	int size3 = 5;

	int array4[6] = {10, 11, 5, 9, 8, 7};
	int size4 = 6;

	count4 = findGreatest(array4, size4, maxBoxMap, 0);
 	cout << "Count of boxes: " << count4 << endl;

	cout << "What is stored in map after iteration: " << endl;
	for(map<int, int>::iterator it = maxBoxMap.begin(); it != maxBoxMap.end(); ++it){
		cout << "{ " << it->first << "," << it->second << "}" << "\n";
	}

	return 0;
}
