/*简单空间分配器*/
#ifndef _JJALLOC_H_
#define  _JJALLOC_H_
#include <iostream>
#include <new>// placement new 
#include <cstddef>//size_t
#include <cstdlib>//exit
#include <climits>
//using namespace  std;
namespace JJ{
	template <class T>
	inline T* _allocate(ptrdiff_t size,T*){
		set_new_handler(0);//空间分配失败下的错误处理函数_PNH _set_new_handler( _PNH pNewHandler );pNewHandler函数指针参数（size_t）
		T* tmp=(T*)(::operator new(size_t(size*sizeof(T))));
		if (tmp==NULL)
		{
			cer<<"out of memory"<<endl;
			exit(0);
		}
		return tmp;
	}

	template<class T>
	inline void _deallocate(T *buffer){
		::operator delete(buffer);
	}
	template <class T1,class T2>
	inline void _construct(T1*p,const T2& value){
		new(p) T2(value); //new 头文件中 new placement 方式 : new placement new-type-name new-initializer
	}
	template <class T>
	inline void _destory(T *ptr){
		ptr->~T();
	}

	//allocate class declaration

	template <class T>
	class allocator{
	public: 
		typedef T			value_type;
		typedef T *		pointer;
		typedef const T* const_pointer;
		typedef T&		reference;
		typedef const T& const_reference;
		typedef size_t	size_type;
		typedef ptrdiff_t  difference_type;


		//rebind allocator of type U
		template <class U>
		struct rebind{
			typedef allocator<U> other;
		};


		//allocate function
		pointer allocate(size_type n,const void * hint=0){
			return _allocate((difference_type)n,(pointer)0);
		}	
		//deallocate
		void deallocate(pointer p,size_type n){
			_destory(p);
		}
		void construt(pointer p,const T &value){
			construt(p,value);
		}
		pointer address(reference x){
			return (pointer)&x;
		}
		const_pointer address(const_reference x){
			return (const_pointer)&x;
		}
		size_type max_size()const{
			return size_type(UINT_MAX/sizeof(T));
		}
	};
}
#endif