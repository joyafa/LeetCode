#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

//1 暴力方式,计算复杂度 O(n2)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vi;
        vi.resize(2);
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int val = target - nums[i];
            vi[0] = i; 
            for (size_t j = i + 1; j < nums.size(); ++j)
            {
                if (val == nums[j])
                {
                    vi[1] = j;
                    return vi;
                }
            }
        }
        
        return vi;
    }
};

//2 times hash map
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vi;
        
        unordered_map<int, int> mapNums;
        int nIndex = 0;
        for_each(nums.begin(), nums.end(),[&](int val)
        {
            mapNums.insert(pair<int, int>(val, nIndex++));                     
        });
        for (int i = 0;i<nums.size();++i)
        {
            int nFind = target - nums[i];
            auto it = mapNums.find(nFind);
            if (it != mapNums.end() && it->second != i)//只能是位置不相等
            {
                vi.push_back(i);
                vi.push_back(it->second);
                break;
            }
        }
                
        return vi;
    }
};


//3 once  for loop
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vi;
        vi.resize(2);

        unordered_map<int, int> uii;
        int nIndex = 0;
        for_each(nums.begin(), nums.end(),[&](int val)
        {
        	int nFind = target - val;
        	auto it = uii.find(nFind);
        	if (it != uii.end() && nIndex != it->second)
        	{
              vi[0] = nIndex;
              vi[1] = it->second;
        	}
            uii.insert(pair<int, int>(val, nIndex++));                     
        });
                
        return vi;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> nums;
    cout << "请输入值:" ;
    for(;;)
    {
        int val = 0;
        cin >> val;
        if (9999 == val)
        {
            for_each(nums.begin(),nums.end(),[](int val)->void{
                cout << val << ",";
            });
            cout << endl;
            break;
        }
        nums.push_back(val);
        cout << "请输入下一个值,跳出请按q:" ;
    }
    
    cout << "请输入目标值:";
    int target = 0;
    cin >> target;
    
    vector<int>vi = s.twoSum(nums, target);
    cout << "[" << vi[0] << "] + [" << vi[1] << "] == " << target << " --->Congurations!!!" << endl;
    
    return 1;
}
