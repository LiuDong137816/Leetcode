#pragma once
#include <string>
#include <vector>

namespace Solution
{
	class StringOperate
	{
	public:
		StringOperate() {};
		~StringOperate() {};
		std::string CommonPrefix(std::string& commom, std::string& str);
		std::string longestCommonPrefix(std::vector<std::string>& strs);
		int lengthOfLastWord(std::string s);
		std::string countAndSay(int n);
		std::string convert(std::string s, int numRows);
		std::string longestPalindrome(std::string s);
		int longestValidParentheses(std::string s);
		std::string multiply(std::string num1, std::string num2);
		std::vector<int> findSubstring(std::string s, std::vector<std::string>& words);
		bool isMatch(std::string s, std::string p);
		bool isIsomorphic(std::string s, std::string t);
		std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);
		int numDistinct(std::string s, std::string t);
		std::string convertToTitle(int n);
	private:

	};
}