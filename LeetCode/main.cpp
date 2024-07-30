#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <stdio.h>
#include <fstream>  
#include <algorithm>
#include "LeetCode.h"

using namespace std;

string CommonPrefix(string& commom, string& str) {
	string tempStr;
	int strlength = commom.length() > str.length() ? str.length() : commom.length();
	for (int i = 0; i < strlength; i++) {
		if (commom[i] == str[i]) {
			tempStr += commom[i];
		}
		else
			break;
	}
	return tempStr;
}

string longestCommonPrefix(vector<string>& strs) {
	string tempStr;
	
	if (strs.size() == 0)
		return tempStr;
	if (strs.size() == 1)
		return strs[0];
	int strlength = strs[0].length() > strs[1].length() ? strs[1].length():strs[0].length();
	for (int i = 0; i < strlength; i++) {
		if (strs[0][i] == strs[1][i]) {
			tempStr += strs[0][i];
		}
		else
			break;
	}
	for (vector<string>::iterator it1 = strs.begin() + 2; it1 != strs.end(); it1++)
	{
		tempStr = CommonPrefix(tempStr, *it1);
	}
	return tempStr;
}

int searchInsert(vector<int>& nums, int target) {
	int flag1 = 0;
	if (nums.size() == 0)
		return 0;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
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

string countAndSay(int n) {
	string resStr;
	string lastStr;
	if (1 == n) {
		resStr = "1";
		return resStr;
	}
	if (2 == n) {
		resStr = "11";
		return resStr;
	}
	lastStr = countAndSay(n - 1);
	int sameNum = 1;
	char numStr[10] = { 0 };
	for (int i = 0; i < lastStr.size() - 1; i++) {
		memset(numStr, 0, sizeof(numStr));
		if (lastStr[i] == lastStr[i + 1]) {
			++sameNum;		
			if (i == (lastStr.size() - 2)) {
				sprintf_s(numStr, "%d", sameNum);
				//_itoa_s(sameNum, numStr, 10);
				resStr += numStr;
				resStr += lastStr[i];
			}
		}
		else
		{
			sprintf_s(numStr, "%d", sameNum);
			resStr += numStr;
			resStr += lastStr[i];
			sameNum = 1;
			if (i == (lastStr.size() - 2)) {
				resStr += "1";
				resStr += lastStr[i + 1];
			}
		}
	}
	return resStr;
}

int lengthOfLastWord(string s) {
	if (s.size() == 0)
		return 0;
	int StrNum = s.find_last_of(" ");
	if (StrNum == s.size())
		return StrNum;
	return s.size() - StrNum -1;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int length = m + n - 1;
	int i = m - 1, j = n - 1;
	while ((i + j) > -2)
	{
		if (i == -1) {
			nums1[length] = nums2[j];
			--j;
		}
		else if (j == -1){
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

int maxSubArray(vector<int>& nums) {
	int len = nums.size();
	int ans = nums[0], sum = 0;
	for (int i = 0; i < len; i++) {
		sum += nums[i];
		ans = max(sum, ans);
		sum = max(sum, 0);
	}
	return ans;
}

int minSum(vector<vector<int>>& grid, int wid, int len) {
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
	return min(minSum(grid, wid - 1, len), minSum(grid, wid, len - 1));
}

int minPathSum(vector<vector<int>>& grid) {
	int wid = grid.size();
	if (0 == wid) {
		return 0;
	}
	int len = grid[0].size();
	return minSum(grid, wid, len);
}

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ivec(n, vector<int>(n, 0));
	int ival = 1;
	int h = 0, l = 0, hm = n-1, lm = n-1, hb = 0, lb = 0;
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

void setZeroes(vector<vector<int>>& matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	int flag = 1;
	for (int i = 0; i < row; i++) {
		if (matrix[i][0] == 0) flag = 0;
		for (int j = 1; j < col; j++) {
			if(matrix[i][j] == 0)
			   matrix[i][0] = matrix[0][j] = 0;
		}
	}
	for (int i = row -1; i >= 0; i--) {
		for (int j = col -1; j > 0 ; j--) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		}
	}
	if (flag == 0) {
		for (int i = 0; i < row; i++)
			matrix[i][0] = 0;
	}
}

string convert(string s, int numRows){
	vector<string> res(numRows, "");
	string stres;
	int len = s.length();
	if (len <= numRows)
		return s;
	int row = 0, step = 0;
	for (int i = 0; i < len; i++) {
		res[row].push_back(s[i]);
		if (row == 0) {
			step = 1;
		}
		else if(row == (numRows - 1)){
			step = -1;
		}
		row += step;
	}
	for (int j = 0; j < numRows; j++) {
		stres += res[j];
	}
	return stres;
}

int reverse(int x) {
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

string longestPalindrome(string s) {
	int len = s.length();
	int min_start = 0, max_len = 0;
	for (int i = 0; i < len;) {
		if(len - i < max_len/2) break;
		int k = i, j = i;
		while (s[i] == s[k + 1])
		{
			++k;
		}
		i = k + 1;
		while (k < s.size()-1 && j > 0 && s[k+1] == s[j-1])
		{
			++k; --j;
		}
		int new_len = k - j + 1;
		if (new_len > max_len) {
			min_start = j;
			max_len = new_len;
		}
	}
	return s.substr(min_start, max_len);
}

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	vector<int> ivec;
	int oneData = 0;
	while (x)
	{
		ivec.push_back(x%10);
		x /= 10;
	}
	for (int i = 0, j = ivec.size() -1; i < ivec.size()/2; ++i, --j) {
		if (ivec[i] != ivec[j])
			return false;
	}
	return true;
}

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> SumRes;
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
				vector<int> ThreeSum(3, 0);
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

int threeSumClosest(vector<int>& nums, int target) {
	int goalTar = nums[0] + nums[1] + nums[2] - target;
	sort(nums.begin(), nums.end());
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

//vector<int> findSubstring(string s, vector<string>& words) {
//	vector<int> ivec;
//	return ivec;
//}

vector<int> findSubstring(string s, vector<string>& words) {
	unordered_map<string, int> counts;
	for (string word : words)
		counts[word]++;
	vector<int> res;
	int n = s.size(), num = words.size();
	if (0 == n || 0 == num)
		return res;
	int len = words[0].size();
	
	for (int i = 0; i < n - num * len + 1; i++) {
		unordered_map<string, int> seen;
		int j = 0;
		for (; j < num; j++) {
			string word = s.substr(i + j * len, len);
			if (counts.find(word) != counts.end()) {
				seen[word]++;
				if (seen[word] > counts[word]) {
					break;
				}
			}
			else
				break;
		}
		if (j == num)  res.push_back(i);
	}
	return res;
}

void permuteRecursive(vector<int> &num, int begin, vector<vector<int>> &result) {
	if (begin >= num.size()) {
		result.push_back(num);
		return;
	}
	for (int i = begin; i < num.size(); i++) {
		swap(num[begin], num[i]);
		permuteRecursive(num, begin + 1, result);
		swap(num[i], num[begin]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> res;
	permuteRecursive(nums, 0, res);
	return res;
}

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ivec;
	vector<int>::iterator it = find(nums.begin(), nums.end(), target);
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

int search(vector<int>& nums, int target) {
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

int firstMissingPositive(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	if (nums.size() == 0 || nums[nums.size() - 1] <= 0 || find(nums.begin(), nums.end(), 1) == nums.end()) {
		return 1;
	}
	int resVal = nums[nums.size() - 1] + 1;
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] <= 0)
			break;
		else if (nums[i+1] == nums[i]) {
			continue;;
		}else{
			if (nums[i + 1] != (nums[i] + 1))
				resVal = nums[i] + 1;
		}
	}
	return resVal;
}

void nextPermutation(vector<int>& nums) {
	int k = -1;
	int numsLen = nums.size();
	for (int i = numsLen - 2; i >= 0; --i) {
		if (nums[i] < nums[i + 1]) {
			k = i;
			break;
		}
	}
	if (k == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}
	int l = numsLen -1;
	for (int j = numsLen - 1; j > k; j--) {
		if (nums[j] > nums[k]) {
			l = j;
			break;
		}
	}
	swap(nums[k], nums[l]);
	reverse(nums.begin()+ k + 1, nums.end());
}

int longestValidParentheses(string s) {
	int n = s.length(), longest = 0;
	stack<int> stc;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			stc.push(i);
		else {
			if (!stc.empty()) {
				if (s[stc.top()] == '(') stc.pop();
				else{
					stc.push(i);
				}
			}
			else {
				stc.push(i);
			}
		}
	}
	if (stc.empty()) 
		return n;
	else {
		int a = n, b = 0;
		while (!stc.empty())
		{
			b = stc.top(); stc.pop();
			longest = max(longest, a - b - 1);
			a = b;
		}
		longest = max(longest, a);
	}
	return longest;
}

int trap(vector<int>& height) {
	int res = 0;
	int left = 0, right = height.size()-1;
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

string multiply(string num1, string num2) {
	string res(num1.size() + num2.size(), '0');
	for (int i = num1.size() - 1; i >= 0; i--) {
		int hignIndex = 0;
		for (int j = num2.size() - 1; j >= 0; j--) {
			int tmp = (num1[i] - '0')*(num2[j] - '0') + hignIndex + (res[i+j+1]-'0');
			res[i + j + 1] = tmp % 10 + '0';
			hignIndex = tmp/10;
		}
		res[i] += hignIndex;
	}
	size_t startPos = res.find_first_not_of("0");
	if (startPos != string::npos) {
		return res.substr(startPos);
	}
	return "0";
}

void combinationTarget(vector<int>& candidates, vector<vector<int>>& res, vector<int> &OneElement, int target, int start) {
	if (!target) {
		res.push_back(OneElement);
		return;
	}
	for (int i = start; i < candidates.size() && target >= candidates[i]; i++) {
		if(i > start && candidates[i] == candidates[i-1])
			continue;
		OneElement.push_back(candidates[i]);
		combinationTarget(candidates, res, OneElement, target - candidates[i], i + 1);
		OneElement.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> ires;
	vector<int> OneRes;
	combinationTarget(candidates, ires, OneRes, target, 0);
	return ires;
}


bool canJump(vector<int>& nums) {
	int i = 0;
	for (int reach = 0; i < nums.size() && i <= reach; ++i) {
		reach = max(i + nums[i], reach);
	}
	return i == nums.size();
}

bool isMatch(string s, string p) {
	int sLen = s.length(), pLen = p.length(), i = 0, j = 0, iStart = -1, jStart = -1;
	for (i = 0, j = 0; i < s.length(); i++, j++) {
		if (p[j] == '*') {
			iStart = i;
			jStart = j;
			--i;
		}
		else {
			if (s[i] != p[j] && p[j] != '?') {
				if (iStart >= 0) {
					i = iStart++;
					j = jStart;
				}
				else return false;
			}
		}
	}
	while (p[j] == '*')
	{
		++j;
	}
	return j == pLen;
}

int jump(vector<int>& nums) {
	int numsLen = nums.size();
	if (numsLen < 2) return 0;
	int MaxThisStep = 0, i = 0, NextStep = 0, Step = 0;
	while (MaxThisStep - numsLen + 1 < 0) {
		++Step;
		for (; i <= MaxThisStep; i++)
		{
			NextStep = max(NextStep, nums[i] + i);
			if (NextStep >= numsLen - 1) return Step;
		}
		MaxThisStep = NextStep;
	}
	return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, multiset<string>> mp;
	for (string s : strs) {
		string t = s;
		sort(t.begin(), t.end());
		mp[t].insert(s);
	}
	vector<vector<string>> sres;
	for (auto m:mp) {
		vector<string> svec(m.second.begin(), m.second.end());
		sres.push_back(svec);
	}
	return sres;
}

//struct BiTNode {
//	char data;
//	struct BiTNode* lchild, *rchild; // 左右孩子
//};
//void CreatBiTree(BiTNode* &T) { // 先序递归创建二叉树
//								// 先按顺序驶入二叉树中节点的值(一个字符),空格字符代表空树
//	char ch;
//	cin >> ch;
//	if (ch == '#') // getchar() 为逐个读入标准库函数
//		T = NULL;
//	else {
//		T = new BiTNode; // 产生新的子树
//		T->data = ch; // 由getchar()逐个读进来
//		CreatBiTree(T->lchild); // 递归创建左子树
//		CreatBiTree(T->rchild); // 递归创建右子树
//	}
//}

typedef struct BiTNode {
	int val;
	BiTNode *lchild;
	BiTNode *rchild;
	BiTNode(int x) : val(x), lchild(NULL), rchild(NULL) {}
}TreeNode;

void CreateTree(TreeNode* &T){
	int val;
	cin >> val;
	if (val == 0) {
		T = NULL;
	}
	else {
		T = new TreeNode(val);
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
}

void PrintTree(BiTNode *T) {
	if (T == NULL) {
		cout << " NULL ";
	}
	else {
		cout << T->val<< " ";
		PrintTree(T->lchild);
		PrintTree(T->rchild);
	}
}

//bool isSymmetric(TreeNode* root) {
//	if (root == NULL)
//		return true;
//	if (root->left != NULL && root->right == NULL)
//		return false;
//	else if (root->left == NULL && root->right != NULL) {
//		return false;
//	}else if (root->left == NULL && root->right == NULL) {
//		return true;
//	}
//	else {
//		if (root->left->val != root->right->val)
//			return false;
//	}
//	return isSymmetric(root->left) && isSymmetric(root->right);
//}

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> resInt;
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

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	if (0 == numRows)
		return res;
	vector<int> tmpVec{1};
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

vector<int> getRow(int rowIndex) {
	vector<int> ResVec{ 1 };
	if (0 == rowIndex) {
		return ResVec;
	}
	vector<int> tmpVec = getRow(rowIndex - 1);
	ResVec.resize(rowIndex + 1);
	for (int i = 1; i < rowIndex; i++) {
		ResVec[i] = tmpVec[i - 1] + tmpVec[i];
	}
	ResVec[rowIndex] = 1;
	return ResVec;
}

int minimumTotal(vector<vector<int>>& triangle) {
	int row = triangle.size();
	vector<int> minLen(triangle.back());
	for (int i = row - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			minLen[j] = min(minLen[j], minLen[j+1]) + triangle[i][j];
	return minLen[0];
}
stack<int> input, output;
void push(int x) {
	input.push(x);
}

/** Removes the element from in front of queue and returns that element. */
void pop() {
	//peek();
	output.pop();
}

/** Get the front element. */
int peek() {
	if(output.empty())
		while (input.size())
		{
			output.push(input.top()), input.pop();
		}
	return output.top();
}

/** Returns whether the queue is empty. */
bool empty() {
	return input.empty() && output.empty();
}

bool isIsomorphic(string s, string t) {
	int sLen = s.size();
	int dataA[256] = { 0 }, dataB[256] = {0};
	for (int i = 0; i < sLen; i++) {
		if (dataA[i] != dataB[i])
			return false;
		dataA[s[i]] = i + 1;
		dataB[t[i]] = i + 1;
	}
	return true;
}



int rangeBitwiseAnd(int m, int n) {
	if (m == n)
		return m;
	else
		return rangeBitwiseAnd(m / 2, n / 2) << 1;
}

int countPrimes(int n) {
	if (n < 2)
		return 0;
	int sum = 1;
	vector<int>  ivec(n + 1, 0);
	int dataVal = sqrt(n);
	for (int i = 3; i <= n; i++) {
		if (!ivec[i]) {
			++sum;
			//if()
		}
	}
	return sum;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> ires;
	if (root == NULL)
		return ires;
	vector<int> ivec;
	vector<TreeNode*> Tvec{root};
	int i = 1;
	while (!Tvec.empty())
	{
		vector<TreeNode*> Tmpvec = Tvec;
		Tvec.clear();
		ivec.clear();
		for (vector<TreeNode*>::reverse_iterator it = Tmpvec.rbegin(); it != Tmpvec.rend(); it++) {
			ivec.push_back((*it)->val);
			if (i % 2 == 1) {
				if ((*it)->lchild != NULL)
					Tvec.push_back((*it)->lchild);
				if ((*it)->rchild != NULL)
					Tvec.push_back((*it)->rchild);
			}
			else {
				if ((*it)->rchild != NULL)
					Tvec.push_back((*it)->rchild);
				if ((*it)->lchild != NULL)
					Tvec.push_back((*it)->lchild);
			}
		}
		++i;
		ires.push_back(ivec);
	}
	return ires;
}

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root) {
	if (NULL == root)  return;
	TreeLinkNode* pre = root;
	TreeLinkNode* cur = NULL;
	while (pre->left)
	{
		cur = pre;
		while (cur)
		{
			cur->left->next = cur->right;
			if (cur->next) cur->right->next = cur->next->left;
			cur = cur->next;
		}
		pre = pre->left;
	}
}

void connect1(TreeLinkNode *root) {
	while (root != NULL)
	{
		TreeLinkNode* tmpNode = new TreeLinkNode(0);
		TreeLinkNode* currNode = tmpNode;
		while (root != NULL)
		{
			if (root->left != NULL) {
				currNode->next = root->left;
				currNode = currNode->next;
			}
			if (root->right != NULL) {
				currNode->next = root->right;
				currNode = currNode->next;
			}
			root = root->next;
		}
		root = tmpNode->next;
	}
}

int numDistinct(string s, string t) {
	int m = t.length(), n = s.length();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
	for (int j = 0; j <= n; j++) dp[0][j] = 1;
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= m; i++)
			dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
	return dp[m][n];
}
float c(float x, float y, float r, float p)
{ return powf(powf(fabsf(x), p) + powf(fabsf(y), p), 1 / p) - r; }

int f(float x, float y) {
	float a = fmaxf(c(x, y, 15, 2), c(x, y + 25, 30, 2)), b = c(x, y - 7, 10, 4);
	if (a < -1) // cap pattern 
		return c(fmodf(x + 20 + 3 * floorf((y + 20) / 6), 6) - 3, fmodf(y + 20, 6) - 3, 2, 2) >= 0; 
	else if (a < 0.0f) // cap 
		return 1; 
	else if (b < -2) // face
		return c(fabsf(x) - 2.5f, y - 7.5f, 1.25f, 2) < 0 || (y > 10 && fabsf(c(x, y - 9, 4, 2)) < 0.5f); 
	else // body 
		return b < 0;
} 
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
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
		}else
			continue;
	}
	return -1;
}

vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ivec;
	if (NULL != root)
		ivec.push_back(root->val);
	if(root->lchild != NULL)
		preorderTraversal(root->lchild);
	if (root->rchild != NULL)
		preorderTraversal(root->rchild);
	return ivec;
}

vector<int> postorderTraversal(TreeNode* root) {
	vector<int> ivec;
	if (root->lchild != NULL)
		preorderTraversal(root->lchild);
	if (root->rchild != NULL)
		preorderTraversal(root->rchild);
	if (NULL != root)
		ivec.push_back(root->val);
	return ivec;
}

void rightSideView_Help(TreeNode* root, vector<int> &res, int level) {
	if (NULL == root) {
		return;
	}
	if (res.size() == level)
		res.push_back(root->val);
	rightSideView_Help(root->rchild, res, level + 1);
	rightSideView_Help(root->lchild, res, level + 1);
}

vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	rightSideView_Help(root, res, 0);
	return res;
}

void numIslands_help(vector<vector<char>>& grid, int i, int j) {
	if (i < 0 || j < 0 || i >=grid.size() || j >= grid[0].size() || grid[i][j] =='0') return;
	grid[i][j] = '0';
	numIslands_help(grid, i + 1, j);
	numIslands_help(grid, i, j + 1);
	numIslands_help(grid, i - 1, j);
	numIslands_help(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
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

string convertToTitle(int n) {
	string res;
	while (n)
	{
		int tmp = n % 26;
		if (0 == tmp) {
			tmp = 25;
			n /= 26;
			--n;
		}
		else {
			--tmp;
			n /= 26;
		}			
		
		res += ('A' + tmp);
	}
	reverse(res.begin(), res.end());
	return res;
}

vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> ivec;
	int VecLen = numbers.size();
	for (int i = 0; i < VecLen; i++) {
		for (int j = i + 1; j < VecLen; j++) {
			if ((numbers[i] + numbers[j]) == target) {
				ivec.push_back(i + 1);
				ivec.push_back(j + 1);
				break;
			}else if ((numbers[i] + numbers[j]) > target) {
				break;
			}	
		}
	}
	return ivec;
}

#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型
typedef enum { DG, DN, UDG, UDN }GraphKind;       //枚举图的 4 种类型
typedef struct {
	VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
	InfoType * info;                        //弧或边额外含有的信息指针
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
	AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
	int vexnum, arcnum;                      //记录图的顶点数和弧（边）数
	GraphKind kind;                         //记录图的种类
}MGraph;
//根据顶点本身数据，判断出顶点在二维数组中的位置
int LocateVex(MGraph * G, VertexType v) {
	int i = 0;
	//遍历一维数组，找到变量v
	for (; i<G->vexnum; i++) {
		if (G->vexs[i] == v) {
			break;
		}
	}
	//如果找不到，输出提示语句，返回-1
	if (i>G->vexnum) {
		printf("no such vertex.\n");
		return -1;
	}
	return i;
}
//构造有向图
void CreateDG(MGraph *G) {
	//输入图含有的顶点数和弧的个数
	cin >> G->vexnum >> G->arcnum;
	//scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	//依次输入顶点本身的数据
	for (int i = 0; i<G->vexnum; i++) {
		cin >> G->vexs[i];
		//scanf("%d", &(G->vexs[i]));
	}
	//初始化二维矩阵，全部归0，指针指向NULL
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	//在二维数组中添加弧的数据
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2;
		//输入弧头和弧尾
		cin >> v1 >> v2;
		//scanf("%d,%d", &v1, &v2);
		//确定顶点位置
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		//排除错误数据
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		//将正确的弧的数据加入二维数组
		G->arcs[n][m].adj = 1;
	}
}
//构造无向图
void CreateDN(MGraph *G) {
	scanf_s("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i<G->vexnum; i++) {
		scanf_s("%d", &(G->vexs[i]));
	}
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2;
		scanf_s("%d,%d", &v1, &v2);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = 1;
		G->arcs[m][n].adj = 1;//无向图的二阶矩阵沿主对角线对称
	}
}
//构造有向网，和有向图不同的是二阶矩阵中存储的是权值。
void CreateUDG(MGraph *G) {
	scanf_s("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i<G->vexnum; i++) {
		scanf_s("%d", &(G->vexs[i]));
	}
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2, w;
		scanf_s("%d,%d,%d", &v1, &v2, &w);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = w;
	}
}
//构造无向网。和无向图唯一的区别就是二阶矩阵中存储的是权值
void CreateUDN(MGraph* G) {
	scanf_s("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i<G->vexnum; i++) {
		scanf_s("%d", &(G->vexs[i]));
	}
	for (int i = 0; i<G->vexnum; i++) {
		for (int j = 0; j<G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	for (int i = 0; i<G->arcnum; i++) {
		int v1, v2, w;
		scanf_s("%d,%d,%d", &v1, &v2, &w);
		int m = LocateVex(G, v1);
		int n = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = w;
		G->arcs[m][n].adj = w;//矩阵对称
	}
}
void CreateGraph(MGraph *G) {
	//选择图的类型
	scanf_s("%d", &(G->kind));
	//根据所选类型，调用不同的函数实现构造图的功能
	switch (G->kind) {
	case DG:
		return CreateDG(G);
		break;
	case DN:
		return CreateDN(G);
		break;
	case UDG:
		return CreateUDG(G);
		break;
	case UDN:
		return CreateUDN(G);
		break;
	default:
		break;
	}
}
//输出函数
void PrintGrapth(MGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}
int main_2() {
	MGraph G;//建立一个图的变量
	CreateGraph(&G);//调用创建函数，传入地址参数
	PrintGrapth(G);//输出图的二阶矩阵
	getchar();
	getchar();
	return 0;
}

int main_1()
{
	vector<int> ivec{ 2,7,11,15 };
	twoSum(ivec, 9);
	TreeNode *root;
	CreateTree(root);
	vector<int> res= rightSideView(root);
	//PrintTree(root);
	system("pause");
	return 0;
}
#define N 5
int maze[N][N] = {
{ 0, 1, 1, 0, 0 },
{ 0, 0, 1, 1, 0 },
{ 0, 1, 1, 1, 0 },
{ 1, 0, 0, 0, 0 },
{ 0, 0, 1, 1, 0 }
};
int visited[N + 1] = { 0, };
void BFS(int start)
{
	queue<int> Q;
	Q.push(start);
	visited[start] = 1;
	while (!Q.empty())
	{
		int front = Q.front();
		cout << front << " ";
		Q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i] && maze[front - 1][i - 1] == 1)
			{
				visited[i] = 1;
				Q.push(i);
			}
		}
	}
}

int main() {
	BFS(1);
	getchar();
	return 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;
		BFS(i);
	}
	getchar();
	return 0;
}