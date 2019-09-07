#include "pch.h"
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const char* p = s.c_str();
		vector<char>vc;
		int max_len = 0;
		while (*p)
		{
			//abcabcbb
			auto it = find(vc.begin(), vc.end(), *p);
			//begin
			if (it == vc.begin() && it != vc.end())
			{
				vc.erase(vc.begin());
			}
			//mid | end
			else if (it != vc.end())
			{
				//max_len = max_len > vc.size() ? max_len : vc.size();
				vc.erase(vc.begin(), it + 1);
			}
			vc.push_back(*p);

			max_len = max_len > vc.size() ? max_len : vc.size();
			p++;
		}
		
		return max_len;
	}

#if 0
	int lengthOfLongestSubstring(string s) {
		const char* p = s.c_str();
		string str;
		int max_len = 0;
		while (*p)
		{
			//abcabcbb
			size_t pos = str.find(*p);
			//begin
			if (0 == pos)
			{
				str = str.substr(1);
			}
			//mid | end
			else if (pos != string::npos)
			{
				str = str.substr(pos + 1);
			}
			str.append(1, *p);

			max_len = max_len > str.size() ? max_len : str.size();
			p++;
		}

		return max_len;
	}
#endif
};


void testlengthOfLongestSubstring()
{
	while (1)
	{
		char str[128];
		cout << "请输入字串:";
		cin >> str;
		if (strchr(str, 'q'))
		{
			cout << "bye bye..." << endl;
			break;
		}

		cout << "input:" << str << endl;
		Solution s;
		cout << s.lengthOfLongestSubstring(str) << endl;
	}
}
