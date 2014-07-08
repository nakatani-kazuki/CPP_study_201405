//omikuji3.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Omikuji{
	int un; //ラッキーナンバー
public:
	Omikuji();
	void hiku();
};

//コンストラクタ
Omikuji::Omikuji(){
	srand((unsigned) time(NULL));
	cout << "ラッキーナンバー（1〜5）を入力してください" << endl;
	cin >> un; //ラッキーナンバーを入力させる	
}

//おみくじを引く
void Omikuji::hiku(){
	int x;
	x = rand()%5+1; //1〜5の乱数をxに代入
	cout << "あなたの運勢は";
	if(x == un){
		cout << "大吉です！" << endl;
	}else{
		cout << "そこそこです" << endl;
	}
}

int main(){
	Omikuji ok; //おみくじをビルド
	cout << "向こう1週間の運勢は！？" << endl;
	for(int i = 0; i<7; i++){
		cout << "今日から" << i+1 << "日後" << endl;
		ok.hiku(); //おみくじからhikuを実行
	}
}

