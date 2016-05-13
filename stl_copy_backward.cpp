#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

template <class T>
struct display{
	void operator ()(const T& x){
		cout<<x<<' ';
	}
};

int main(){
	int ia[]={0,1,2,3,4,5,6,7,8};
	copy_backward(ia+2,ia+7,ia+9);
	for_each(ia,ia+9,display<int>());
	system("pause");
	return 0;
}