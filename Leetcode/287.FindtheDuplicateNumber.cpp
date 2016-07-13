

class Solution {//����ԭ��
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int min = 0, max = nums.size() - 1;
		int middle = 0;
		while (min <= max) {//С�ڵ��ڣ����С��middle��������middle�����ظ���һ����1~middle�С�
			int count = 0;
			int middle = (min + max) / 2;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] <= middle)
					count++;
			}
			if (count > middle) {
				max = middle - 1;
			}
			else {
				min = middle + 1;
			}
		}
		return min;
	}
};

class Solution {//������ⷨһ��142
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		while (fast<nums.size() && nums[fast] < nums.size()) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) {
				int node = 0;

				while (node != slow) {
					node = nums[node];
					slow = nums[slow];
				}
				return node;
			}
		}
		return 0;

	}
};
/*
���
public class Solution {
	public int findDuplicate(int[] nums) {
		int slow = 0;
		int fast = 0;
		// �ҵ�����ָ�������ĵط�
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		int find = 0;
		// ��һ����ָ���ͷ��ʼ��ֱ������ָ������
		while (find != slow) {
			slow = nums[slow];
			find = nums[find];
		}
		return find;
	}
}
*/