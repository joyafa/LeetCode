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
