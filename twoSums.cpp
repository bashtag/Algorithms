#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

// my first cpp attempts
int main(void)
{
	string name = "bilal";
	int age;
	bool isMale = true;

	age = 20;
	cout << "Hello World" << endl;
	cout << name << "llss " << age << "\n"; 
	cout << "string length: " << name.length() << endl;

	vector<int> result;
	result.push_back(5);
	cout << result[0] << " " << result.capacity() << endl;
	cout << endl << "--------------------------------" << endl << endl;

	vector<int> nums = {3,2,4};
	vector<int> sum_res = twoSum(nums, 6);
	for (int i = 0; i < sum_res.size(); i++)
		cout << sum_res[i] << " ";
}

// the sum of two terms must be equal to target
// return this two indeces
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	bool flag = true;
	int len = nums.size();

	for (int i = 0; i < len && flag; i++)
    {
        for (int j = i + 1; j < len && flag; j++)
        {
            if (nums[i] + nums[j] == target) 
            {
                result.push_back(i);
                result.push_back(j);
                flag = false;
            }
        }
    }
    return result;
}