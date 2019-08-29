#include "pch.h"
#include <vector>
#include <string>

using namespace std;

//1 暴力方法
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string strPrefix;
		if (strs.empty())
		{
			return strPrefix;
		}
		string str0 = strs[0];
		if (str0.empty())
		{
			return strPrefix;
		}
		int idx = 0;
		const char* p = str0.c_str();
		bool bExcept = false;
		for (idx = 0, p = str0.c_str(); *p; ++p, ++idx)
		{
			for (size_t pos = 1; pos < strs.size(); ++pos)
			{
				//长度超出
				if (idx > strs[pos].length() - 1)
				{
					bExcept = true;
					break;
				}
				const char* p1 = strs[pos].c_str();
				if (*p == p1[idx])
				{
					continue;
				}
				else
				{
					bExcept = true;
					break;
				}
			}
			if (bExcept)
			{
				break;
			}
			strPrefix.append(1, *p);
		}

		return strPrefix;
	}
};
void teslongestCommonPrefix()
{
	Solution s;
	vector<string> vs{"Hello", "HelloWorld", "HellGood"};
	s.longestCommonPrefix(vs);
}
