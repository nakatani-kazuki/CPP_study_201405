//neko.cpp
#include <iostream>
#include <string>
using namespace std;

class Neco
{
//外部からはアクセスできない
private:
	string name;
//外部からも使ったり表示させたりすることができる
public:
	//ビルドする。class名で同じ名前を定義しないといけないらしい
	Neco(string s){
		name = s;
	}
	//void　は、返り値を必要としない関数。returnとかが含まれない
	void naku(){
		cout<< "にゃあ。俺様は" << name << "だ。" << endl;
	}

};


int main()
{
	//↓perlでやってたところの、ビルドしたものを受け取る変数名みたいな役
	Neco dora("ボス");
	cout << "あなたの名づけた猫がメモリ上に作成されました。" << endl;
	cout << "猫が鳴きます。" << endl;
	//doraはもうobject化されてるから、そいつのもってるnakuを呼び出す
	dora.naku();
}

