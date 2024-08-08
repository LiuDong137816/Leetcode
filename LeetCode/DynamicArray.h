#pragma once
#include <vector>

namespace Solution
{
	struct Interval {
		int start;
		int end;
		Interval() : start(0), end(0) {}
		Interval(int s, int e) : start(s), end(e) {}
	};

	class DynamicArray
	{
	public:
		std::vector<Interval> merge(std::vector<Interval>& intervals);

		DynamicArray() {}
		int searchInsert(std::vector<int>& nums, int target);
		void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
		int maxSubArray(std::vector<int>& nums);
		int minSum(std::vector<std::vector<int>>& grid, int wid, int len);
		int minPathSum(std::vector<std::vector<int>>& grid);
		std::vector<std::vector<int>> generateMatrix(int n);
		void setZeroes(std::vector<std::vector<int>>& matrix);
		int reverse(int x);
		bool isPalindrome(int x);
		std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
		int threeSumClosest(std::vector<int>& nums, int target);
		void permuteRecursive(std::vector<int>& num, int begin, std::vector<std::vector<int>>& result);
		std::vector<std::vector<int>> permute(std::vector<int>& nums);
		std::vector<int> searchRange(std::vector<int>& nums, int target);
		int search(std::vector<int>& nums, int target);
		int firstMissingPositive(std::vector<int>& nums);
		void nextPermutation(std::vector<int>& nums);
		int trap(std::vector<int>& height);
		void combinationTarget(std::vector<int>& candidates, std::vector<std::vector<int>>& res, std::vector<int>& OneElement, int target, int start);
		std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);
		bool canJump(std::vector<int>& nums);
		int jump(std::vector<int>& nums);
		std::vector<int> twoSum(std::vector<int>& numbers, int target);
		std::vector<int> getRow(int rowIndex);
		std::vector<std::vector<int>> generate(int numRows);
		int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost);
		int minimumTotal(std::vector<std::vector<int>>& triangle);
		int numIslands(std::vector<std::vector<char>>& grid);
	private:
		void numIslands_help(std::vector<std::vector<char>>& grid, int i, int j);
	};
}