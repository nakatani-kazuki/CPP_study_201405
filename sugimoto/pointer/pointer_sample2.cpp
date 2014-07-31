//pointer_sample.cpp
#include <iostream>
using namespace std;

int main(){
	int x = 3;
	int y = 4;
	int* p1 = &x;
	int* p2 = &y;

cout << "xのアドレスは" << p1 << endl;
cout << "yのアドレスは" << p2 << endl;
}


// ↓*p1、と書くと「その場所にある値」を返す。つまりxが返ってくる。
// int main(){
// 	int x = 3;
// 	int y = 4;
// 	int* p1 = &x;
// 	int* p2 = &y;

// cout << "xは" << *p1 << endl;
// cout << "yは" << *p2 << endl;
// }

