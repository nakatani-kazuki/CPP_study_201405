//ransu.cpp
#include <iostream>
#include <cstdlib>  //rand()を使うために必要な宣言
#include <ctime>  //現在の時刻をもとに乱数を生成する＝毎度違う乱数が出せるようになる
using namespace std;

int main(){
	srand( (unsigned)time( NULL ) );
	cout << rand()%10+1 << endl;
	cout << rand()%10+1 << endl;
	cout << rand()%10+1 << endl;

}









