//gakusei_sample.cpp
#include <iostream>
using namespace std;

class Gakusei{
	int sansu; //算数の点数。あとから入力する。
public:
	//引数なしのコンストラクタ。引数が渡ってこない（配列の数だけ、先にハコを用意する場合など）はこっちが呼ばれる。
	Gakusei(){} //とりあえず何もしないで入れ物だけ作る。空のsansuと、機能だけ持ったハコができる
	//引数ありのコンストラクタ。こちらは処理された数字がsansuに入って生まれる。
	Gakusei(int x){ set_sansu(x); }
	//一定のフィルタを掛けた上でxをコンストラクタに渡し、このxがsansuにセットされてビルドされる
	void set_sansu(int x);
	int get_sansu() const{ return sansu; }
	//数字を入れてね、と表示する関数
	//ここはちょっと改造して、「●番目の生徒の数を…」と表示できるようにした
	void input(int num);
};

void Gakusei::set_sansu(int x){
	//100以上の数が入ってきたら強制的にxを100に置き換える
	if(x >= 100){
		x = 100;
	}
	//Gakuseiのsansuにxを突っ込む
	sansu = x;
}

void Gakusei::input(int num){
	int temp;
	cout << num << "番の生徒の算数の点を入力してください。";
	cin >> temp;
	set_sansu(temp);
}

//この形で10個の学生の入れ物をとりあえず作る
Gakusei mine[10];

int main(){
	int sum = 0;
	cout << "10人の学生の点数を入力してください。" << endl;

	//10人までの学生に、ひとりずつ点数を入力させる
	for(int i = 0; i < 10; i++){
		//配列の番号＋1を「生徒の番号」としてユーザに表示。
		mine[i].input(i + 1);
	}

	cout << "それでは平均点を計算します。" << endl;

	//平均する
	for(int i = 0; i < 10; i++){
		sum += mine[i].get_sansu();
	}
	cout << "平均点は" << sum/10 << "です。" << endl;
}
