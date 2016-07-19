//如果能把计算放入构造器中，最好放入构造器中，这就查询的时间就很快了。




class NumArray {
public:
	NumArray(vector<int> &nums) :nums(nums) {

	}

	int sumRange(int i, int j) {
		int length = nums.size();
		int res;
		if (i<0 || j>length - 1)
			return -1;
		//for (int index = i; index <= j; index++)
		//	res += nums[index];
		return accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
		//return res;
	}
private:
	vector<int> nums;
};

class NumArray {
public:
	NumArray(vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0)
				num.push_back(nums[i]);
			else
				num.push_back(num.back() + nums[i]);
		}
	}

	int sumRange(int i, int j) {
		if (i == 0)
			return num[j];
		return num[j] - num[i - 1];
	}
private:
	vector<int> num;
};






class NumArray {
public:
	map<int, int> mp;
	NumArray(vector<int> &nums) {
		mp[-1] = 0;
		int sum = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			sum += nums[i];
			mp[i] = sum;
		}
	}

	int sumRange(int i, int j) {
		return (mp[j] - mp[i - 1]);
	}
};