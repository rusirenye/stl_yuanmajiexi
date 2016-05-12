/*
*** 仿函数
*/
#include <iostream>
#include <vector>
using  namespace std;


template <class T>
struct myplus{
	void  operator()(T & x){//重载()操作符，调用方式：类型（）；
		x+=2;
		cout<<x<<endl;
	}
};
template <class _InputIter, class _Function>
_Function for_each(_InputIter __first, _InputIter __last, _Function __f) {
	for ( ; __first != __last; ++__first)
		__f(*__first);
	return __f;
}

int main(){
	int a[]={1,2,3,4,5};
	vector<int> v(a,a+5);
	for_each(v.begin(),v.end(),myplus<int>());
	system("pause");
	return 0;
}