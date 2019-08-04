// addTwoNumber.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
//
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/add-two-numbers
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。




 //Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : 
		val(x), next(NULL) 
	{
	}
};

typedef struct ListNode* PLINSTNODE;

PLINSTNODE AddNewNode(PLINSTNODE& pHead, int val)
{
	if (nullptr == pHead)
	{
		pHead = new struct ListNode(val);
		return pHead;
	}
	//尾部追加
	PLINSTNODE pNewNode = new struct ListNode(val);
	//找到链表的尾节点,然后追加新的节点
	PLINSTNODE p = pHead;
	while (p->next)
	{
		p = p->next;
	}
	p->next = pNewNode;

	return pHead;
}


void PrintNode(const PLINSTNODE& pHead)
{
	PLINSTNODE p = pHead;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

#define null NULL


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;//为1则需要进位
		int sum = 0;
		PLINSTNODE p = l1;
		PLINSTNODE q = l2;
		PLINSTNODE pRetLink = nullptr;//返回接口链表
		while (nullptr != p || nullptr != q)
		{
			//这个节点可能是空
			sum = ((nullptr != p) ? p->val : 0) + ((nullptr != q) ? q->val : 0);			
			//增加节点
			AddNewNode(pRetLink, (sum + carry) % 10);
			/*if ((sum + carry) / 10)
			{
				carry = 1;
			}
			else
			{
				carry = 0;
			}*/
			carry = (sum + carry) / 10;
			//链表后移,进入下一个节点
			if (nullptr != p)
			{
				p = p->next;
			}
			if (nullptr != q)
			{
				q = q->next;
			}
		}

		//尾部还要追加一个节点
		if (1 == carry)
		{
			//增加节点
			AddNewNode(pRetLink, carry);
		}

		return pRetLink;
	}

	PLINSTNODE addTwoNumbers1(PLINSTNODE l1, PLINSTNODE l2) {
		PLINSTNODE dummyHead = new ListNode(0);
		PLINSTNODE p = l1, q = l2, curr = dummyHead;
		int carry = 0;
		while (p != null || q != null) {
			int x = (p != null) ? p->val : 0;
			int y = (q != null) ? q->val : 0;
			int sum = carry + x + y;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			if (p != null) p = p->next;
			if (q != null) q = q->next;
		}
		if (carry > 0) {
			curr->next = new ListNode(carry);
		}
		return dummyHead->next;
	}

};




int main()
{
	//create to link for testing
	PLINSTNODE l1 = nullptr, l2 = nullptr;
	
	AddNewNode(l1, 9);
	AddNewNode(l1, 0);
	AddNewNode(l1, 8);

	cout << "link1:";
	PrintNode(l1);

	AddNewNode(l2, 5);
	AddNewNode(l2, 6);
	AddNewNode(l2, 4);

	cout << "link2:";
	PrintNode(l2);
	Solution s;
	PLINSTNODE pNode = s.addTwoNumbers(l1, l2);
	PrintNode(pNode);
	PLINSTNODE pNode1 = s.addTwoNumbers1(l1, l2);
	PrintNode(pNode1);
	return 1;
}
