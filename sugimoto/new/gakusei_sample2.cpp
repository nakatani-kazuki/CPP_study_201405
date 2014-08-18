//gakusei_sample2.cpp
#include <iostream>
using namespace std;

class Gakusei{
	int sansu;
public:
	// 引数のないコンストラクタ	
	Gakusei(){}
	void set_sansu(int x);
	int get_sansu() const{ return sansu; }
	void input();
};

void Gakusei::set_sansu(int x){
	if(x >= 100){
		// xが100以上のときは一律で100にしてしまう
		x = 100;
	}
	sansu = x;
}

void Gakusei::input(){
	int temp;
	cout << "算数の点を入力してください。" << endl;
	cin >> temp;
	set_sansu(temp);
}

int main(){
	int ninzu, sum = 0;
	Gakusei *pm;
	cout << "学生の人数を入力してください。" << endl;
	cin >> ninzu;

	// ninzuの数の学生が作られ、配列になって保存される
	pm = new Gakusei[ninzu];
	cout << ninzu << "人の学生の点数を入力してください。" << endl;

	for(int i = 0; i < ninzu; i++){
		pm[i].input();
	}
	cout << "それでは平均を計算します。" << endl;
	for (int i = 0; i<ninzu; i++){
		sum += pm[i].get_sansu();
	}
	cout << "平均点は" << sum/ninzu << "です。" << endl;
	delete [] pm;
}


