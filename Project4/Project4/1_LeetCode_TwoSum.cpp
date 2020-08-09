#include<iostream>
using namespace std;
#include<vector>

vector<int> twoSum(vector<int> &nums, int target);

int main() 
{

	vector<int> nums;
	nums.push_back(2);
	nums.push_back(11);
	nums.push_back(15);
	nums.push_back(7);
	
	twoSum(nums, 9);

	system("pause");
	return 0;
}

vector<int> twoSum(vector<int> &nums, int target)
{
	int pos = 0;
	int end = 0;
	bool isFound = false;
	vector<int> position;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++, pos++)
	{
		for (end = 0; end < nums.size() - pos - 1; end++)
		{
			if (*it + *(it + end + 1) == target)
			{
				isFound= true;
				break;
			}
		}
		if (isFound)
		{
			break;
		}
	}
	printf("[%d,%d] \n", pos, end + pos + 1);

	position.push_back(pos);
	position.push_back(pos+end+1);

	return position;
}