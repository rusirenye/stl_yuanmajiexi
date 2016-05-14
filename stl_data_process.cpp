#include<iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

template <class T>
struct dispaly{
	void operator()(const T &x){
		cout<< x <<endl;
	}
};

template <class T>
struct even{
	bool operator ()(const T &x)
	{
		return x%2==0? true : false;
	}
};

class even_by_two{
public: 
	int operator ()(){
		_x+=2;
		return _x;
	}
	static int _x;
};
int even_by_two::_x=0;
int main(){
	int ia[]={0,1,2,3,4,5,6,6,7,8};
	vector<int> va(ia,ia+sizeof(ia)/sizeof(int));
	//查找第一个邻接相等的元素
	cout<< *adjacent_find(va.begin(),va.end())<<endl;
	//查找第一个邻接相等的元素(使用指定比较器)
	cout<< *adjacent_find(va.begin(),va.end(),equal_to<int>())<<endl;
	//计算vector 中6的数量
	cout<<count(va.begin(),va.end(),6)<<endl;
	//计算vector中比6小的数量
	cout<<count_if(va.begin(),va.end(),(less_equal<int>(),6))<<endl;
	//查找vector中元素6所在位置
	cout<<*find(va.begin(),va.end(),6)<<endl;
	//查找va中比刘
	system("pause");
	return 0;
}