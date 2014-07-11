//neko.cpp
#include <iostream>
#include <string>
using namespace std;

//ここから基本のねこ---------------
class Neco
{
//外部からはアクセスできない2
private:
	string name;
//外部からも使ったり表示させたりすることができる
public:
	//ビルドする。class名で同じ名前を定義しないといけないらしい
	Neco(string);
	//void は、返り値を必要としない関数。returnとかが含まれない
	void naku()const; //★ここどういう意味？
};

Neco::Neco(string s):name(s){}
void Neco::naku()const{
		cout<< "にゃあ。俺様は" << name << "だ。" << endl;
	}

//ここまで基本のねこ---------------

//ここからサラリーねこ---------------
class SalaryNeco : public Neco{
	int gekkyu;
public:
	//コンストラクタ
SalaryNeco(string s,int x) : Neco(s), gekkyu(x){}
int get_nensyu() const{ return gekkyu * 12; }
void syoukyu() { gekkyu++;}
};

int main()
{
	cout << "サラリー猫を生成します。名前を入力してください。" << endl;
	string temp;
	cin >> temp;
	cout << "初任給を決めて入力してください。" << endl;
	cout << "1万円単位で、半角整数で入力してください" << endl;
	int syoninkyuu;
	cin >> syoninkyuu;
	SalaryNeco dora(temp, syoninkyuu);
	cout << "サラリーネコが誕生しました" << endl;
	//ループ。抜けるには4か1～3以外の数字を入れる
	while(1){ //基本無限ループにするやり方。抜けるコマンドを内側に設定しておく
		cout << "どうしますか？" << endl;
		cout << "1.鳴かせる 2.年収を表示 3.昇給 4.終了する" << endl;
		int ans;
		cin >> ans;
		//1を選んだらnakuコマンドで鳴かせる
		if(ans == 1){ 
			dora.naku();
		//2を選んだらget_nensyuで年収表示
		}else if(ans == 2){
			cout << "現在の年収は" << dora.get_nensyu() << "です。" << endl;
		//3を選んだらsyoukyuでgekkyuをあげる
		}else if(ans == 3){
			dora.syoukyu();
			cout << "1万円昇給しました。" << endl;
		//上記のどの数字でもなかったらループから抜ける
		}else{
			break;
		}
		cout << endl;
	}
cout << "あばよ！" << endl;
}


