#include <iostream>
#include <vector>
using namespace std;
class Array1D {
	private:
		vector<int> vec;
	public:
		void push_back(int data) {
			vec.push_back(data);
		}
		int& operator[](int index) {
			return vec[index];
		} 
		const int & operator[](int index)const {
			return vec[index];
		}
};
class Array2D {
	private:
		vector<Array1D> vec;
	public:
		void push_back(const Array1D& a) {
			vec.push_back(a);
		}
		Array1D& operator[](int index) {
			return vec[index];
		}
		const Array1D& operator[](int index)const {
			return vec[index];
		}
};
int main() {
	Array2D aa;
	for(int i=0; i<3; ++i) {
		Array1D a;
		for(int j=0; j<4; ++j)
			a.push_back(j+i);
		aa.push_back(a);
	}
	for(int i=0; i<3; ++i) {
		for(int j=0; j<4; ++j) cout<<aa[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
/*0 1 2 3
1 2 3 4
2 3 4 5*/
