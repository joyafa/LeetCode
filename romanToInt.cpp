#include <string>
#include <map>
#include <iostream>
using namespace std;

//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000

//I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。


class Solution {
public:
	int romanToInt(string s) {
		//construct table
		map<string, int>mci{
			{"I", 1},
			{"V",5},
			{"X",10},
			{"L",50},
			{"C",100},
			{"D",500},
			{"M",1000},
			{"IV", 4},
			{"IX", 9},
			{"XL", 40},
			{"XC", 90},
			{"CD", 400},
			{"CM", 900}
		};

		int sum = 0;
		const char* p = s.c_str();
        char key[3] = { 0 };
		while (*p)
		{
            string key;
			key.push_back(*p++);
			if (*p)
			{
				key.push_back(*p++);
				auto it = mci.find(key);
				if (it != mci.end())
				{
					sum += it->second;
				}
				else
				{
					p--;
					key.pop_back();
					it = mci.find(key);
					sum += it->second;
				}
			}
			else
			{
				auto it = mci.find(key);
				if (it != mci.end())
				{
					sum += it->second;
				}
			}
            
            /*
			key[0] = *p++;
            key[1] = 0;
            key[1] = 0;
			if (*p)
			{
				key[1] = *p++;
				auto it = mci.find(key);
				if (it != mci.end())
				{
					sum += it->second;
				}
				else
				{
					p--;
					key[1] = 0;
					it = mci.find(key);
					sum += it->second;
				}
			}
			else
			{
				auto it = mci.find(key);
				if (it != mci.end())
				{
					sum += it->second;
				}
			}*/
		}


		return sum;
	}
};

void testRomaInt()
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
		cout << s.romanToInt(str) << endl;
	}
}
