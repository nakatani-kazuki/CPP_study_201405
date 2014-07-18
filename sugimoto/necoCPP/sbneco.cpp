//sbneko.cpp
#include <iostream>
#include <string>
using namespace std;


//ここから基本のねこ---------------
class Neco
{
private:
	string name;
public:
	Neco (string);
	//void は、返り値を必要としない関数。returnとかが含まれない
	void naku() const; //constは「この関数はread onlyですよ」という宣言みたいなもの
};

Neco::Neco (string s) {
	name = s;
}

void Neco::naku() const {
	cout<< "にゃあ。俺様は" << name << "だ。" << endl;
}
// ここまで基本のねこ---------------

//ここからサラリーねこ---------------
class SalaryNeco : public Neco{
	int gekkyu;
public:
	//コンストラクタ
SalaryNeco(string s,int x) : Neco(s), gekkyu(x){}
//年収を戻す関数。年収はgekkyuの12倍
int get_nensyu() const{ return gekkyu * 12; }
//月給を1万増やす関数
void syoukyu() { gekkyu++;}
//月給がいくらかを戻す関数
int get_gekkyu() const{ return gekkyu; }
};
//ここまでサラリーねこ---------------

//ここからボーナスねこ---------------
class BonusNeco : public SalaryNeco{
	int bonus; //月給の数カ月分をボーナスにする
public:
	//コンストラクタ。
	//名前,月給,ボーナスの値を受け取ってビルドする
	BonusNeco(string, int, int);
	//年収（月給12ヶ月＋ボーナス）を戻す関数
	//親クラスが持っているものと同じ名前でも使える
	int get_nensyu() const{ return get_gekkyu() * (12 + bonus); }
};

//コンストラクタ。
//文字列sと整数gをサラリー猫に渡し、bonusには整数bを渡してビルド
BonusNeco::BonusNeco(string s, int g, int b) : SalaryNeco(s,g), bonus(b){}

//ここまでボーナスねこ---------------

int main(){
	string name;
	int gekkyu;
	int bonus;
	//名前を決める
	cout << "ボーナスねこをメモリ上に作成します。 /n名前を入力してください。" << endl;
	cin >> name;
	//月給を決める
	cout << "月給を決めて入力してください。半角数字でお願いします。" << endl;
	cin >> gekkyu;
	//ボーナス
	cout << "ボーナスは給料の何ヶ月分か入力してください。" << endl;
	cin >> bonus;
	BonusNeco dora(name, gekkyu, bonus);
	//ここからボーナス猫で遊ぶ。ループを抜けるには1~3以外の数字を入力
	while(1){
		int ans;
		cout << "どうしますか？" <<endl;
		cout << "1.鳴かせる 2.年収を表示 3.昇給 4.やめる" << endl;
		cin >> ans;
		//1ならnakuで鳴く
		if(ans == 1){
			dora.naku();
		}
		//2ならget_nensyuで年収表示
		else if(ans == 2){
			cout << "現在の年収は" << dora.get_nensyu() << "です。" << endl;
		}
		//3ならsyoukyuで昇給させる
		else if(ans == 3){
			dora.syoukyu();
			cout << "1万円昇給しました。" << endl;
		}
		else {
			break;
		}
	cout << endl;
	}
	cout << "あばよ！" << endl;
}



