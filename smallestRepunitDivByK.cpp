#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<stdint.h>
using namespace std;

#if 0
class Solution {
public:
    int smallestRepunitDivByK(int K) {

        if ( K < 0 || K > 100000)
        {
            cout << "K:" << K << " is out of scope!" << endl;

            return -1;
        }        

        //1 1结尾,所以不能是偶数,偶数字节pass掉
        if (0 == K % 2)
        {
            cout << "不存在符合要求的能背2整除的只有数字1组成的正整数!" << endl;
            return -1;
        }
        //2数字本身是1组成,那么最小数自然是它自己,如何检查数字全是1组成
        
        //用itoa转换一下
        char numBuffer[120];
        sprintf(numBuffer,"%d",K);
        //itoa(K, numBuffer, 10);

        int nLength = strlen(numBuffer);
        //检查是否全1
        char* p = numBuffer;
        bool bAll1 = true;
        while (*p)
        {
            if (*p++ != '1')
            {
                bAll1 = false;
                break;
            }
        }

        if (bAll1)
        {
            cout << "is self" << endl;

            return nLength;
        }

        //非全1的,需要计算
        //暴力查找,从比他大的地方开始
        //构造出nLength+1个1的数字,然后检查是否整除,100000
        for (int i = nLength + 1;;++i)//不能到6
        {          
            if (i > 64)
        	{
        		break;
			}
            
            char number[128] = {0};
            for (int j=0;j<i;++j)
            {
                strcat(number, "1");
            }

            if ( strtol(number, NULL, 10 ) < 0)
            //if (_atoi64(number) < 0)
            {
                break;
            }

            if ( 0 == strtol(number, NULL, 10 ) % K )
            //if (0 == _atoi64(number) % K)
            {
                //find ok, break
                cout << "Found: " << number << " % " << K << " 0" << endl;

                return i;
            }
        }

        cout << " not found !"  << endl;

        return -1;

    }
};
#endif

class Solution2 {
public:
    int smallestRepunitDivByK(int k) {
        if ( k < 0 || k > 100000)
        {
            cout << "k:" << k << " is out of scope!" << endl;

            return -1;
        }     
        //能被2, 5 整除的直接pass掉
        if (0 == k % 2 || 0 == k % 5) //能被2 , 5 整除的都不是
        {
            cout << "不存在符合要求的能被2,5整除的只有数字1组成的正整数!" << endl;
            
            return -1;
        }
        
        //统计1的个数
        int nCount = 0;
        
        unsigned __int128 llll = 1;
        
        while(true)
        {
            nCount++;
            cout << ">>>>>" << nCount << endl;
            
            if (0 == llll % k)
            {
                //cout << "Found: " << llll << " % " << k << " == 0" << endl;
                cout << "Found: " <<  nCount << endl;
                
                return nCount;
            }
                        
            llll *= 10;
            llll += 1;            
        }
        
        return -1;
    }
};


class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if ( k < 0 || k > 100000)
        {
            cout << "k:" << k << " is out of scope!" << endl;

            return -1;
        }     
        //能被2, 5 整除的直接pass掉
        if (0 == k % 2 || 0 == k % 5) //能被2 , 5 整除的都不是
        {
            cout << "不存在符合要求的能被2,5整除的只有数字1组成的正整数!" << endl;
            
            return -1;
        }
        
        //统计1的个数
        int nCount = 1;
        int remainder = 1;
        int remainderAll = 1;

        while(0 != remainderAll % k )
        {
        	remainder = (remainder * 10) % k;
        	remainderAll += remainder;        	
            nCount++;
            cout << ">>>>>" << nCount << endl;        
        }

        cout << remainderAll << " Found: " <<  nCount << endl;
        
        return nCount;
    }
};


