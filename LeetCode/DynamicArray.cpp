#include "DynamicArray.h"
#include <algorithm>

namespace Solution
{
	std::vector<Interval> DynamicArray::merge(std::vector<Interval>& intervals)
	{
		std::vector<Interval> resInt;
		if (intervals.empty() || intervals.size() == 1)
			return intervals;
		//sort(intervals.begin(), intervals.end());
		Interval tmpInter = intervals[0];
		for (int i = 0; i < intervals.size(); i++) {
			if (intervals[i].start <= tmpInter.end) {
				tmpInter = Interval(tmpInter.start, intervals[i].end);
				resInt.push_back(tmpInter);
			}
			else {
				resInt.push_back(intervals[i]);
				tmpInter = intervals[i];
			}
		}
		return resInt;
	}

	int DynamicArray::searchInsert(std::vector<int>& nums, int target)
	{
		int flag1 = 0;
		if (nums.size() == 0)
			return 0;
		for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			if (*it == target) {
				return it - nums.begin();
			}
			else if (*it > target) {
				flag1 = 1;
				return it - nums.begin();
			}
		}
		return nums.end() - nums.begin();
	}
	void DynamicArray::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
	{
		int length = m + n - 1;
		int i = m - 1, j = n - 1;
		while ((i + j) > -2)
		{
			if (i == -1) {
				nums1[length] = nums2[j];
				--j;
			}
			else if (j == -1) {
				nums1[length] = nums1[i];
				--i;
			}
			else
			{
				if (nums1[i] < nums2[j]) {
					nums1[length] = nums2[j];
					--j;
				}
				else {
					nums1[length] = nums1[i];
					--i;
				}
			}
			--length;
		}
	}
	int DynamicArray::maxSubArray(std::vector<int>& nums)
	{
		int len = nums.size();
		int ans = nums[0], sum = 0;
		for (int i = 0; i < len; i++) {
			sum += nums[i];
			ans = std::max(sum, ans);
			sum = std::max(sum, 0);
		}
		return ans;
	}
	int DynamicArray::minSum(std::vector<std::vector<int>>& grid, int wid, int len)
	{
		int sum = 0;
		if (1 == wid) {
			for (int i = 0; i < len; i++) {
				sum += grid[0][i];
			}
			return sum;
		}
		if (1 == len) {
			for (int i = 0; i < wid; i++) {
				sum += grid[i][0];
			}
			return sum;
		}
		return std::min(minSum(grid, wid - 1, len), minSum(grid, wid, len - 1));
	}
	int DynamicArray::minPathSum(std::vector<std::vector<int>>& grid)
	{
		int wid = grid.size();
		if (0 == wid) {
			return 0;
		}
		int len = grid[0].size();
		return minSum(grid, wid, len);
	}
	std::vector<std::vector<int>> DynamicArray::generateMatrix(int n)
	{
		std::vector<std::vector<int>> ivec(n, std::vector<int>(n, 0));
		int ival = 1;
		int h = 0, l = 0, hm = n - 1, lm = n - 1, hb = 0, lb = 0;
		while (ival <= n * n) {
			while (l <= lm)
			{
				ivec[h][l++] = ival++;
			}
			--lm;
			++h;
			--l;
			while (h <= hm) {
				ivec[h++][l] = ival++;
			}
			--h;
			--l;
			while (l >= lb) {
				ivec[h][l--] = ival++;
			}
			--h;
			++l;
			++hb;
			while (h >= hb) {
				ivec[h--][l] = ival++;
			}
		}
		return ivec;
	}
	void DynamicArray::setZeroes(std::vector<std::vector<int>>& matrix)
	{
		int row = matrix.size();
		int col = matrix[0].size();
		int flag = 1;
		for (int i = 0; i < row; i++) {
			if (matrix[i][0] == 0) flag = 0;
			for (int j = 1; j < col; j++) {
				if (matrix[i][j] == 0)
					matrix[i][0] = matrix[0][j] = 0;
			}
		}
		for (int i = row - 1; i >= 0; i--) {
			for (int j = col - 1; j > 0; j--) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
		}
		if (flag == 0) {
			for (int i = 0; i < row; i++)
				matrix[i][0] = 0;
		}
	}
	int DynamicArray::reverse(int x)
	{
		long long res = 0;
		while (x)
		{
			int tempData = x % 10;
			res *= 10;
			res += tempData;
			x /= 10;
		}
		if ((res > 2147483647) || (res < -2147483647))
			return 0;
		return (int)res;
	}
	bool DynamicArray::isPalindrome(int x)
	{
		if (x < 0)
			return false;
		std::vector<int> ivec;
		int oneData = 0;
		while (x)
		{
			ivec.push_back(x % 10);
			x /= 10;
		}
		for (int i = 0, j = ivec.size() - 1; i < ivec.size() / 2; ++i, --j) {
			if (ivec[i] != ivec[j])
				return false;
		}
		return true;
	}
	std::vector<std::vector<int>> DynamicArray::threeSum(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> SumRes;
		int vecLen = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < vecLen; i++) {
			int front = i + 1;
			int back = vecLen - 1;
			int target = -nums[i];
			while (front < back) {
				int TwoSum = nums[front] + nums[back];
				if (TwoSum > target) {
					--back;
				}
				else if (TwoSum < target) {
					++front;
				}
				else
				{
					std::vector<int> ThreeSum(3, 0);
					ThreeSum[0] = nums[i];
					ThreeSum[1] = nums[front];
					ThreeSum[2] = nums[back];
					SumRes.push_back(ThreeSum);

					while (front < back && nums[front] == ThreeSum[1]) ++front;
					while (front < back && nums[back] == ThreeSum[2]) ++back;
				}
			}
			while (i + 1 < vecLen && nums[i + 1] == nums[i]) ++i;
		}
		return SumRes;
	}
	int DynamicArray::threeSumClosest(std::vector<int>& nums, int target)
	{
		int goalTar = nums[0] + nums[1] + nums[2] - target;
		std::sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			int front = i + 1;
			int rear = nums.size() - 1;
			while (front < rear) {
				int tempTar = nums[i] + nums[front] + nums[rear] - target;
				if (tempTar >= abs(goalTar)) --rear;
				else if (tempTar <= -abs(goalTar)) ++front;
				else {
					goalTar = nums[i] + nums[front] + nums[rear] - target;
					++front;
				}
			}
		}
		return goalTar + target;
	}
	void DynamicArray::permuteRecursive(std::vector<int>& num, int begin, std::vector<std::vector<int>>& result)
	{
		if (begin >= num.size()) {
			result.push_back(num);
			return;
		}
		for (int i = begin; i < num.size(); i++) {
			std::swap(num[begin], num[i]);
			permuteRecursive(num, begin + 1, result);
			std::swap(num[i], num[begin]);
		}
	}
	std::vector<std::vector<int>> DynamicArray::permute(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> res;
		permuteRecursive(nums, 0, res);
		return res;
	}
	std::vector<int> DynamicArray::searchRange(std::vector<int>& nums, int target)
	{
		std::vector<int> ivec;
		std::vector<int>::iterator it = find(nums.begin(), nums.end(), target);
		if (it == nums.end()) {
			ivec.push_back(-1);
			ivec.push_back(-1);
			return ivec;
		}
		else {
			int val = it - nums.begin();
			ivec.push_back(val);
			ivec.push_back(val);
			while ((++it) != nums.end() && (*it) == target)
			{
				ivec[1] = (++val);
			}
		}
		return ivec;
	}
	int DynamicArray::search(std::vector<int>& nums, int target)
	{
		int beg = 0, rear = nums.size() - 1;
		while (beg <= rear)
		{
			int mid = (beg + rear) / 2;
			if (nums[mid] > target)
				rear = mid - 1;
			else if (nums[mid] > target)
				beg = mid + 1;
			else
				return mid;
		}
		return -1;
	}

	int DynamicArray::firstMissingPositive(std::vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		if (nums.size() == 0 || nums[nums.size() - 1] <= 0 || find(nums.begin(), nums.end(), 1) == nums.end()) {
			return 1;
		}
		int resVal = nums[nums.size() - 1] + 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] <= 0)
				break;
			else if (nums[i + 1] == nums[i]) {
				continue;;
			}
			else {
				if (nums[i + 1] != (nums[i] + 1))
					resVal = nums[i] + 1;
			}
		}
		return resVal;
	}
	void DynamicArray::nextPermutation(std::vector<int>& nums)
	{
		int k = -1;
		int numsLen = nums.size();
		for (int i = numsLen - 2; i >= 0; --i) {
			if (nums[i] < nums[i + 1]) {
				k = i;
				break;
			}
		}
		if (k == -1) {
			std::reverse(nums.begin(), nums.end());
			return;
		}
		int l = numsLen - 1;
		for (int j = numsLen - 1; j > k; j--) {
			if (nums[j] > nums[k]) {
				l = j;
				break;
			}
		}
		std::swap(nums[k], nums[l]);
		std::reverse(nums.begin() + k + 1, nums.end());
	}

	int DynamicArray::trap(std::vector<int>& height)
	{
		int res = 0;
		int left = 0, right = height.size() - 1;
		int leftMax = 0, rightMax = 0;
		while (left <= right) {
			if (height[left] <= height[right]) {
				if (leftMax < height[left]) leftMax = height[left];
				else res += leftMax - height[left];
				++left;
			}
			else {
				if (rightMax < height[right]) rightMax = height[right];
				else res += rightMax - height[right];
				--right;
			}
		}
		return res;
	}

	void DynamicArray::combinationTarget(std::vector<int>& candidates, std::vector<std::vector<int>>& res, std::vector<int>& OneElement, int target, int start)
	{
		if (!target) {
			res.push_back(OneElement);
			return;
		}
		for (int i = start; i < candidates.size() && target >= candidates[i]; i++) {
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			OneElement.push_back(candidates[i]);
			combinationTarget(candidates, res, OneElement, target - candidates[i], i + 1);
			OneElement.pop_back();
		}
	}

	std::vector<std::vector<int>> DynamicArray::combinationSum2(std::vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int>> ires;
		std::vector<int> OneRes;
		combinationTarget(candidates, ires, OneRes, target, 0);
		return ires;
	}

	bool DynamicArray::canJump(std::vector<int>& nums)
	{
		int i = 0;
		for (int reach = 0; i < nums.size() && i <= reach; ++i) {
			reach = std::max(i + nums[i], reach);
		}
		return i == nums.size();
	}

	int DynamicArray::jump(std::vector<int>& nums)
	{
		int numsLen = nums.size();
		if (numsLen < 2) return 0;
		int MaxThisStep = 0, i = 0, NextStep = 0, Step = 0;
		while (MaxThisStep - numsLen + 1 < 0) {
			++Step;
			for (; i <= MaxThisStep; i++)
			{
				NextStep = std::max(NextStep, nums[i] + i);
				if (NextStep >= numsLen - 1) return Step;
			}
			MaxThisStep = NextStep;
		}
		return 0;
	}

	std::vector<int> DynamicArray::twoSum(std::vector<int>& numbers, int target)
	{
		std::vector<int> ivec;
		int VecLen = numbers.size();
		for (int i = 0; i < VecLen; i++) {
			for (int j = i + 1; j < VecLen; j++) {
				if ((numbers[i] + numbers[j]) == target) {
					ivec.push_back(i + 1);
					ivec.push_back(j + 1);
					break;
				}
				else if ((numbers[i] + numbers[j]) > target) {
					break;
				}
			}
		}
		return ivec;
	}

	std::vector<int> DynamicArray::getRow(int rowIndex)
	{
		std::vector<int> ResVec{ 1 };
		if (0 == rowIndex) {
			return ResVec;
		}
		std::vector<int> tmpVec = getRow(rowIndex - 1);
		ResVec.resize(rowIndex + 1);
		for (int i = 1; i < rowIndex; i++) {
			ResVec[i] = tmpVec[i - 1] + tmpVec[i];
		}
		ResVec[rowIndex] = 1;
		return ResVec;
	}

	std::vector<std::vector<int>> DynamicArray::generate(int numRows)
	{
		std::vector<std::vector<int>> res;
		if (0 == numRows)
			return res;
		std::vector<int> tmpVec{ 1 };
		if (1 == numRows) {
			res.push_back(tmpVec);
			return res;
		}
		res = generate(numRows - 1);
		tmpVec.resize(numRows);
		for (int i = 1; i < numRows - 1; i++) {
			tmpVec[i] = res[numRows - 2][i - 1] + res[numRows - 2][i];
		}
		tmpVec[numRows - 1] = 1;
		res.push_back(tmpVec);
		return res;
	}

	int DynamicArray::canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
	{
		int gasLen = gas.size();
		for (int i = 0; i < gasLen; i++) {
			if (gas[i] >= cost[i]) {
				int gasSum = gas[i] - cost[i];
				for (int j = i + 1; j < gasLen; j++) {
					gasSum = gasSum + gas[j] - cost[j];
					if (gasSum < 0) {
						break;
					}
				}
				if (gasSum < 0) {
					continue;
				}
				for (int k = 0; k < i; k++) {
					gasSum = gasSum + gas[k] - cost[k];
					if (gasSum < 0)
						break;
				}
				if (gasSum < 0)
					continue;
				else
					return i;
			}
			else
				continue;
		}
		return -1;
	}

	int DynamicArray::minimumTotal(std::vector<std::vector<int>>& triangle)
	{
		int row = triangle.size();
		std::vector<int> minLen(triangle.back());
		for (int i = row - 2; i >= 0; i--)
			for (int j = 0; j <= i; j++)
				minLen[j] = std::min(minLen[j], minLen[j + 1]) + triangle[i][j];
		return minLen[0];
	}

	int DynamicArray::numIslands(std::vector<std::vector<char>>& grid)
	{
		int lineLen = grid.size();
		if (lineLen == 0)  return 0;
		int colSize = grid[0].size();
		int goalNum = 0;
		for (int i = 0; i < lineLen; i++) {
			for (int j = 0; j < colSize; j++) {
				if (grid[i][j] == '1') {
					numIslands_help(grid, i, j);
					++goalNum;
				}
			}
		}
		return goalNum;
	}

	void DynamicArray::numIslands_help(std::vector<std::vector<char>>& grid, int i, int j)
	{
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;
		grid[i][j] = '0';
		numIslands_help(grid, i + 1, j);
		numIslands_help(grid, i, j + 1);
		numIslands_help(grid, i - 1, j);
		numIslands_help(grid, i, j - 1);
	}

}


