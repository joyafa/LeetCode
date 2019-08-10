/*
我们提供了一个类：

public class Foo {
  public void one() { print("one"); }
  public void two() { print("two"); }
  public void three() { print("three"); }
}
三个不同的线程将会共用一个 Foo 实例。

线程 A 将会调用 one() 方法
线程 B 将会调用 two() 方法
线程 C 将会调用 three() 方法
请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。

 

示例 1:

输入: [1,2,3]
输出: "onetwothree"
解释: 
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
正确的输出是 "onetwothree"。
示例 2:

输入: [1,3,2]
输出: "onetwothree"
解释: 
输入 [1,3,2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
正确的输出是 "onetwothree"。
 

注意:

尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。

你看到的输入格式主要是为了确保测试的全面性。

在真实的面试中遇到过这道题？



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/print-in-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <thread>
#include <iostream>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <atomic>

class Foo {
public:
	Foo() :
       count(0)
    {
        
    }

	void first(function<void()> printFirst) {
		std::unique_lock<std::mutex> lck(_mtx);
		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		count++;
		_cv.notify_one();
	}

	void second(function<void()> printSecond) {
		std::unique_lock<std::mutex> lck(_mtx);
		_cv.wait(lck, [this]() {return count.load(std::memory_order_relaxed) == 1; });
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
     	count++;

		_cv2.notify_one();
	}

	void third(function<void()> printThird) {
		std::unique_lock<std::mutex> lck(_mtx);
		_cv2.wait(lck, [this] {return count.load(std::memory_order_relaxed) == 2; });
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
private:
	  std::mutex _mtx;
	  std::condition_variable _cv, _cv2;
	  std::atomic<int> count;
};

#if 0
void  printFirst()
{
	cout << " First " << endl;
}

void  printSecond()
{
	cout << " Second " << endl;
}

void  printThird()
{
	cout << " Third " << endl;
}

void TestMultiThread()
{
	Foo f;
	////绑定函数对象,实例,以及参数
	auto fun1 = std::bind(&Foo::first, f, printFirst);// std::placeholders::_1);
	thread t1(fun1, printFirst);
	auto fun2 = std::bind(&Foo::second, f, printSecond);// std::placeholders::_1);
	thread t2(fun2, printSecond);//此时设置参数已经没有用了,因为bind的时候已经指定了
	//参数使用占位符,后面再次设置参数
	auto fun3 = std::bind(&Foo::third, f, printThird);// std::placeholders::_1);
	thread t3(fun3, printThird);
	t1.join();
	t3.join();
	t2.join();

	//thread t2(f.second, printSecond);
	//thread t3(f.third, printThird);
}
#endif
