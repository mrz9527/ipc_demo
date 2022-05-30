#include <iostream>
#include <iostream>

using namespace std;

void* myAlloc(size_t size)
{	return malloc(size);   }
void myFree(void* ptr)
{	return free(ptr);      }

inline void* operator new(size_t size)
{ cout <<  "global new() size = "<<size<<endl;	return myAlloc( size ); }
//重载operator new[]
inline void* operator new[](size_t size)
{ cout <<  "global new[]() size = "<<size<<endl;	  return myAlloc( size ); }
//重载operator delete
inline void operator delete(void* ptr)
{ cout << "global delete() \n"; 	myFree( ptr ); }
//重载operator delete[]
inline void operator delete[](void* ptr)
{ cout << "global delete[]() \n"; 	myFree( ptr ); }

class A {
public:
    A():val(0) {
        printf("构造A()，addr = %p\n", this);
    };

    A(int n) : val(n) {
        printf("构造A(int n)，addr = %p\n", this);
    };

    A(const A& a):val(a.val) {
        printf("拷贝构造A(const A& a)，addr = %p\n", this);
    };

    A(A&& a):val(a.val){
        printf("移动构造A(A&& a)，addr = %p\n", this);
    };

    ~A() {
        printf("析构，addr = %p\n", this);
    }

    void* operator new( size_t size){
        cout <<  "member new() size = "<<size<<endl;
        return myAlloc(size);
    };

    void* operator new[](size_t size) {
        cout <<  "member new[]() size = "<<size<<endl;
        return myAlloc(size);
    }

    void operator delete(void* ptr){
        cout << "member delete()，addr = " << ptr; 	myFree( ptr );
    }

    void operator delete[](void* ptr, size_t size){
        cout << "member delete()，addr = " << ptr; 	myFree( ptr );
    }

    int val;
};


int main()
{
    printf("sizeof(size_t) = %d\n", sizeof(size_t));
    printf("sizeof(A) = %d\n", sizeof(A));
    A* a = new A;
    printf("a.val = %d\n",a->val);
    delete a;

    A* b = new A[8];
    delete[] b;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
