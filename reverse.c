/*给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
int reverse(int x)
{	
	int val = 0;
	
	while (0 != x)
	{
		int re = x % 10; //取余,得到低位 
		
		if (val > INT_MAX / 10 || (val == INT_MAX / 10 && re > 7)) 
		{
			//超出上限 
		    return 0;	
		}
        
        if (val < INT_MIN / 10 || (val == INT_MIN / 10 && re < -8)) 
        {
            //低于下限
            return 0;
        }
 
        val *= 10;		
		val += re;
		
		x = x / 10; //取商,得到剩余的高位 		 
	}
	
	return val;
}
