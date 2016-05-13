#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace  std;
template <class T>
struct display{
	void operator ()(const T &x){
		cout<<x<<' ';
	}
};

int main (){
	int ia[]={1,3,5,7,9};
	int ib[]={2,4,6,8,0};
	multiset <int>S1(ia,ia+5);
	multiset <int>S2(ib,ib+5);
	for_each(S1.begin(),S1.end(),display<int>());
	cout<<endl;
	for_each(S2.begin(),S2.end(),display<int>());
	cout<<endl;

	set_union(S1.begin(),S1.end(),S2.begin(),S2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	set_intersection(S1.begin(),S1.end(),S2.begin(),S2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	set_difference(S1.begin(),S1.end(),S2.begin(),S2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	set_symmetric_difference(S1.begin(),S1.end(),S2.begin(),S2.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	system("pause");
	return 0;
}