//Game.cpp
#include <iostream>
#include <cstdlib>  //乱数のために必要（説明は次回）
#include <ctime>    //乱数のために必要（説明は次回）
using namespace std;

//ここから勇者

class Hero
{
public:
	//Heroはパワーという要素を持っています
	int power;
	//パワー100でヒーローを作ります
	Hero() : power(100){}
	void kougeki_suru(int n); 
	void kougeki_sareru(int n);
};

void Hero::kougeki_suru(int n){
	cout << "悪党め！やっつけてやる！！" << endl;
	cout << "パワー" << n << "の攻撃！どか〜ん！！" << endl;
	//攻撃に使ったパワーが減る
	power -=n; 

	//パワー0以上残っていればそのまま生存、0以下だと死ぬ
	if(power >= 0){
		cout << "現在のパワーは" << power << "です。" << endl;
	}
	else{
		cout << "しまった！パワーを使いすぎた…これまでか…" << endl;
		cout << "ヒーローは死んでしまいました。" << endl;
	}
}

//「攻撃される」関数。相手の攻撃の数字の分、HPを削る。
void Hero::kougeki_sareru(int n){
	cout << "あいたたたたたた！！" << endl;
	cout << n << "のダメージを食らった！！" << endl;
	power -= n;
	if(power >= 0){
		cout << "現在のパワーは" << power << "です。" << endl;
	}
	else{
		cout << "くっ…こんなところで…" << endl;
		cout << "ヒーローは死んでしまいました。" << endl;
	}
}


// ここまで勇者
// ここから大魔王


class Daimao
{
public:
	int power;
	//パワー100で大魔王を作ります
	Daimao() : power(100){}
	void kougeki_suru(int n); 
	void kougeki_sareru(int n);
};

void Daimao::kougeki_suru(int n){
	cout << "フハハハ！！これでも喰らえ！！！！" << endl;
	cout << "パワー" << n << "の攻撃！どか〜ん！！" << endl;
	//攻撃に使ったパワーが減る
	power -=n; 

	//パワー0以上残っていればそのまま生存、0以下だと死ぬ
	if(power < 0){
		cout << "しまった！パワーを使いすぎただと…" << endl;
		cout << "大魔王は死んでしまいました。" << endl;
	}
}

void Daimao::kougeki_sareru(int n){
	cout << "ぐああああああ！！！" << endl;
	power -= n;
	if(power < 0){
		cout << "ぐふっ…ばかな…" << endl;
		cout << "大魔王をやっつけました。" << endl;
	}
}

// ここまで大魔王
// ここから対決場所

class Taiketu_basyo
{
	//対決を作るには大魔王と勇者が必要なので、ここでオブジェクトを作る
	Daimao bu;
	Hero you;
	//対決の中に、大魔王と勇者の場所を作成する（定義はあと）
	int bu_no_basyo;  //あとで決める
	int you_no_basyo;  //ユーザが入力
public:
	//ビルド用。一発目をどう作るかは後で。
	Taiketu_basyo();
	//実際にバトルさせる関数
	void taiketu();
};


//対決場所をビルドする。
//乱数で大魔王の居場所を生成、勇者の居場所はユーザに入力させて初期値とする
Taiketu_basyo::Taiketu_basyo()
{
	//乱数の初期化らしい
	srand( (unsigned) time(NULL) );
	//rand() %5 で、0~4までの乱数が取れる。＋1して1〜5にしとく
	bu_no_basyo = rand() %5 + 1;
	cout << "大魔王ブーをやっつけろ！ \n" << endl;
	cout << "大魔王は1〜5のどこかに潜んでいます。" << endl;	
	cout << "あなたも隠れて！1~5のうち、隠れたい数字を入力してください" << endl;
	cin >> you_no_basyo;
}


//実際に対決をさせる関数
//大魔王の攻撃はランダムで生成、勇者の攻撃はユーザに入力させてお互い殴らせる
void Taiketu_basyo::taiketu(){

	while( bu.power > 0 && you.power > 0)
		{
	//最初にユーザの攻撃
		int iti, kougeki;
		cout << "あなたの攻撃です。狙う位置を1~5の数値で入力してください。" << endl;
		cin >> iti;
		cout << "攻撃に使うパワー（100以下の数値）を入力してください" << endl;	
		cin >> kougeki;
		cout << endl;
		//Heroのkougeki_suru関数に、今入力された攻撃パワーを渡して攻撃
		//実際にはHeroのパワーがこの分減るだけ
		you.kougeki_suru(kougeki);
		//大魔王の場所とユーザが狙った場所が合っていたら大魔王のパワーが削れる
		if(bu_no_basyo == iti){
			//ユーザが入力した攻撃力の2倍のダメージを食らう
			bu.kougeki_sareru(kougeki*2);
		}
		else{
			cout << "ミス！大魔王は別の場所にいる！" << endl;	
		}

		//この時点でyouが死んでたらループを抜ける
		if(bu.power <= 0 or you.power <= 0){
			break;
		}

	//ここから大魔王の攻撃
		cout << endl;
		cout << "大魔王の攻撃！" << endl;	
		cout << endl;
		cin.sync(); //あとで
		cin.get(); //あとで
		//大魔王が狙う位置を1〜5のランダムで生成
		iti = rand() %5+1; 
		//大魔王の使うパワーを1~100のランダムで生成
		kougeki = rand() %50+1;
		//Daimaoのkougeki_suru関数に、今入力された攻撃パワーを渡して攻撃
		//実際にはDaimaoのパワーがこの分減るだけ
		bu.kougeki_suru(kougeki);
		if(you_no_basyo == iti){
			//攻撃力の2倍のダメージを食らう
			you.kougeki_sareru(kougeki*2);
		}
		else{
		cout << "ラッキー！大魔王の攻撃がはずれた！ \n" << endl;	
		}
	}

	if(you.power >0)
	{
		cout << "おめでとう！あなたの勝利だ！！" << endl;	
	}
	else{
		cout << "残念！ブウに負けてしまいました…" << endl;	
	}
}


//対決をビルドして、バトル
int main()
{
	//Taiketu_basyoのビルド。名前はdokoka。
	Taiketu_basyo dokoka;
	//Taiketu_basyoが持っている「taiketu」コマンドを呼び出す
	dokoka.taiketu();
}





