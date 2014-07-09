//quiz.cpp
#include <iostream>
using namespace std;

int main(){
	int i;
	while(1){
		cout << "日本一高い山はどれでしょう？" << endl;
		cout << "数字を入力してください。" << endl;
		cout << "1.ヒマラヤ 2.富士山 3.ロッキー" << endl;
		cin >> i;
		if(i == 2){
			break;
		}
		cout << "ブァーーーーカ！！やりなおし！！！" << endl;
	}
	cout << "正解かよ…終了〜" << endl;
}


