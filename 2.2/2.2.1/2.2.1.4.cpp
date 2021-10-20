#include <iostream>
#include <vector>
using namespace std;
class Test {
	public:
		Test():a(1) {
			cout<<a<<endl;
		}
		Test(int a) {
			cout<<this->a<<endl;
			this->a=a;
			cout<<this->a<<endl;
		}
	private:
		int a=3;
};
int main() {
	Test t1;
	Test t2(10);
	return 0;
}
/*
1
3
10*/
