//hito_sample6.cpp
#include <iostream>
using namespace std;


class Hito{
	int power;
public:
	Hito(int x) : power(x){}
	// 仮想デストラクタ。基底クラスにあればいいっぽい
	virtual ~Hito(){};
	// xを受け取ってpowerに代入する
	void set_power(int x){ power = x; }
	int get_power() const{ return power; }
// ↓これをつけると仮想関数になる
	virtual void Jikosyoukai();
};


class Samurai : public Hito{
public:
	Samurai(int x) : Hito(x){}
	void Jikosyoukai();
};

class Ninja : public Hito{
public:
	Ninja(int x) : Hito(x){}
	void Jikosyoukai();
};

class Matimusume : public Hito{
public:
	Matimusume(int x) : Hito(x){}
	void Jikosyoukai();
};



void Hito::Jikosyoukai(){
	power--;
	cout << "俺は人だ。" << endl;
	cout << "俺のパワーは" << power << "だ。" << endl;
}

void Samurai::Jikosyoukai(){
	set_power(get_power() -1);
	cout << "俺はさむらいだ。" << endl;
	cout << "俺のパワーは" << get_power() << "だ。" << endl;
}

void Ninja::Jikosyoukai(){
	set_power(get_power() -1);
	cout << "拙者は忍者でござる。" << endl;
	cout << "拙者のパワーは" << get_power() << "でござる。" << endl;
}

void Matimusume::Jikosyoukai(){
	set_power(get_power() -1);
	cout << "あたいは江戸っ子よ。" << endl;
	cout << "あたいのパワーは" << get_power() << "よ。" << endl;
}


int main(){
	// 配列で、5つの変数を用意する。これがいかに書くオブジェクトそれぞれのポインタとなる。
	Hito *x[5];
	int temp, power;

	// ループで、オブジェクトを作る＆そのアドレスをポインタへ代入していく
	cout << "5人のデータを順次入力してください" << endl;
	for(int i; i<5; i++){
		cout << "選択してください：" << endl;
		cout << "1.さむらい  2.忍者  3.町娘" << endl;
		cin >> temp;
		cout << "パワーを入力してください。" << endl;
		cin >> power;
		// switch文。1だったらこの処理、2だったらこの処理…というのを指定できる
		switch(temp){
			case 1:
				x[i] = new Samurai(power);
				break;
			case 2:
				x[i] = new Ninja(power);
				break;
			case 3:
				x[i] = new Matimusume(power);
				break;
		}
	}

	cout << "それでは各自自己紹介します。よろしいですか？" << endl;
	cout << "1.はい  2いいえ" << endl;
	cin >> temp;
	// ユーザが1以外の整数を入力したら終了
	if(temp != 1){
		// mainの中でのreturn 0;は処理を終了させる
		return 0;
	} else {
		for(int i = 0; i < 5; i++){
			x[i]->Jikosyoukai();
		}
		for(int i = 0; i < 5; i++){
			delete x[i];
		}
	}
}



