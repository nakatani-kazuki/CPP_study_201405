//mugenloop.cpp
#include <iostream>
using namespace std;

int main(){
	int i = 0;
	while(1){
		cout << "好きな数字を入力してください" << endl;
		cin >> i;
		if(i == 100){
			break;
		}
	}
	cout << "終了しました。多分。" << endl; 
}

