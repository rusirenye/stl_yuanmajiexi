#include <iostream>
using namespace std;

class alloc{
};

template<class T,class Alloc=alloc> //类模板
class vector{
public: 
	typedef T valueType;
	typedef valueType* iterator;

	template<class I>//类内的函数模板
	void insert(iterator pos,I first,I last){
		cout<<"insert ()"<<endl;
	}
};

int main(){
	int ia[5]={0,1,2,3,4};
	vector<int> x;
	vector<int>::iterator it=NULL; //stl 源码解析
	x.insert(it,ia,ia+4);
	system("pause");
	return 0;
}