//sisanneko.cpp
#include <iostream>
#include <string>
using namespace std;

//ここから基本のねこ---------------
class Neco
{
private:
	string name;
	string call;
//外部からも使ったり表示させたりすることができる
public:
	//ビルドする。class名で同じ名前を定義しないといけないらしい
	Neco (string, string);
	//void は、返り値を必要としない関数。returnとかが含まれない
	void naku() const; //constは「この関数はread onlyですよ」という宣言みたいなもの
};

Neco::Neco (string s, string c) {
	name = s;
	call = c;
}

void Neco::naku() const {
	cout<< "猫が鳴きます。" << endl;
	cout<< call << endl;
}

// ここまで基本のねこ---------------

// ここから資産ねこ---------------
class SisanNeco : public Neco{
	// 資産
	int money;
public:
	// コンストラクタ
	SisanNeco (string s, string c, int x) : Neco(s,c) {
		money = x;
	}
	int get_nensyu() const { return money * 2 / 100; }
};

int main()
{
	string cin_name; //猫の名前を入力してもらう入れもの
	int cin_money; //猫の資産を入力してもらう入れもの
	string cin_call; //猫の鳴き声を入力してもらう入れもの

	cout << "資産家猫を生成します。名前を入力してください。" << endl;
	cin >> cin_name;

	cout << "資産を決めて入力してください。（単位：万）" << endl;
	cout << "半角整数で入力してください" << endl;
	cin >> cin_money;

	cout << "鳴き声を入力してください。" << endl;
	cin >> cin_call;
	// ここまで入力したらねこを作る
	SisanNeco dora(cin_name, cin_call, cin_money);
	cout << "資産家猫が誕生しました" << endl;

	//ループ。抜けるには1、2以外の数字を入れる
	while (1) { //基本無限ループにするやり方。抜けるコマンドを内側に設定しておく
		cout << "どうしますか？" << endl;
		cout << "1.鳴かせる 2.年収を表示 3.終了する" << endl;
		int ans;
		cin >> ans;
		//1を選んだらnakuコマンドで鳴かせる
		if (ans == 1) { 
			dora.naku();
		}
		// 2を選んだらget_nensyuで年収表示
		else if (ans == 2) {
			cout << "現在の年収は" << dora.get_nensyu() << "です。" << endl;
		}
		// 上記のどの数字でもなかったらループから抜ける
		else {
			break;
		}
		cout << endl;
	}
	cout << "あばよ！" << endl;
}


