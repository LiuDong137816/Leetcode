#include <stack>
#include <algorithm>
#include <unordered_map>
#include <set>
#include "StringOperate.h"

namespace Solution
{
	std::string StringOperate::CommonPrefix(std::string& commom, std::string& str)
	{
		std::string tempStr;
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

	std::string StringOperate::longestCommonPrefix(std::vector<std::string>& strs)
	{
		using ivec = std::vector<std::string>::iterator;
		std::string tempStr;

		if (strs.size() == 0)
			return tempStr;
		if (strs.size() == 1)
			return strs[0];
		int strlength = strs[0].length() > strs[1].length() ? strs[1].length() : strs[0].length();
		for (int i = 0; i < strlength; i++) {
			if (strs[0][i] == strs[1][i]) {
				tempStr += strs[0][i];
			}
			else
				break;
		}
		for (ivec it1 = strs.begin() + 2; it1 != strs.end(); it1++)
		{
			tempStr = CommonPrefix(tempStr, *it1);
		}
		return tempStr;
	}

	int StringOperate::lengthOfLastWord(std::string s)
	{
		if (s.size() == 0)
			return 0;
		int StrNum = s.find_last_of(" ");
		if (StrNum == s.size())
			return StrNum;
		return s.size() - StrNum - 1;
	}

	std::string StringOperate::countAndSay(int n)
	{
		std::string resStr;
		std::string lastStr;
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
	std::string StringOperate::convert(std::string s, int numRows)
	{
		std::vector<std::string> res(numRows, "");
		std::string stres;
		int len = s.length();
		if (len <= numRows)
			return s;
		int row = 0, step = 0;
		for (int i = 0; i < len; i++) {
			res[row].push_back(s[i]);
			if (row == 0) {
				step = 1;
			}
			else if (row == (numRows - 1)) {
				step = -1;
			}
			row += step;
		}
		for (int j = 0; j < numRows; j++) {
			stres += res[j];
		}
		return stres;
	}
	std::string StringOperate::longestPalindrome(std::string s)
	{
		int len = s.length();
		int min_start = 0, max_len = 0;
		for (int i = 0; i < len;) {
			if (len - i < max_len / 2) break;
			int k = i, j = i;
			while (s[i] == s[k + 1])
			{
				++k;
			}
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1])
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
	int StringOperate::longestValidParentheses(std::string s)
	{
		int n = s.length(), longest = 0;
		std::stack<int> stc;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				stc.push(i);
			else {
				if (!stc.empty()) {
					if (s[stc.top()] == '(') stc.pop();
					else {
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
				longest = std::max(longest, a - b - 1);
				a = b;
			}
			longest = std::max(longest, a);
		}
		return longest;
	}
	std::string StringOperate::multiply(std::string num1, std::string num2)
	{
		std::string res(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1; i >= 0; i--) {
			int hignIndex = 0;
			for (int j = num2.size() - 1; j >= 0; j--) {
				int tmp = (num1[i] - '0') * (num2[j] - '0') + hignIndex + (res[i + j + 1] - '0');
				res[i + j + 1] = tmp % 10 + '0';
				hignIndex = tmp / 10;
			}
			res[i] += hignIndex;
		}
		size_t startPos = res.find_first_not_of("0");
		if (startPos != std::string::npos) {
			return res.substr(startPos);
		}
		return "0";
	}
	std::vector<int> StringOperate::findSubstring(std::string s, std::vector<std::string>& words)
	{
		std::unordered_map<std::string, int> counts;
		for (std::string word : words)
			counts[word]++;
		std::vector<int> res;
		int n = s.size(), num = words.size();
		if (0 == n || 0 == num)
			return res;
		int len = words[0].size();

		for (int i = 0; i < n - num * len + 1; i++) {
			std::unordered_map<std::string, int> seen;
			int j = 0;
			for (; j < num; j++) {
				std::string word = s.substr(i + j * len, len);
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
	bool StringOperate::isMatch(std::string s, std::string p)
	{
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
	bool StringOperate::isIsomorphic(std::string s, std::string t)
	{
		int sLen = s.size();
		int dataA[256] = { 0 }, dataB[256] = { 0 };
		for (int i = 0; i < sLen; i++) {
			if (dataA[i] != dataB[i])
				return false;
			dataA[s[i]] = i + 1;
			dataB[t[i]] = i + 1;
		}
		return true;
	}
	std::vector<std::vector<std::string>> StringOperate::groupAnagrams(std::vector<std::string>& strs)
	{
		std::unordered_map<std::string, std::multiset<std::string>> mp;
		for (std::string s : strs) {
			std::string t = s;
			sort(t.begin(), t.end());
			mp[t].insert(s);
		}
		std::vector<std::vector<std::string>> sres;
		for (auto m : mp) {
			std::vector<std::string> svec(m.second.begin(), m.second.end());
			sres.push_back(svec);
		}
		return sres;
	}
	int StringOperate::numDistinct(std::string s, std::string t)
	{
		int m = t.length(), n = s.length();
		std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
		for (int j = 0; j <= n; j++) dp[0][j] = 1;
		for (int j = 1; j <= n; j++)
			for (int i = 1; i <= m; i++)
				dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
		return dp[m][n];
	}
	std::string StringOperate::convertToTitle(int n)
	{
		std::string res;
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
}