//hito_sample5.cpp
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

	//5つのオブジェクトを作ってポインタを↑の変数に入れる
	x[0] = new Samurai(12);
	x[1] = new Samurai(15);
	x[2] = new Ninja(7);
	x[3] = new Ninja(8);
	x[4] = new Matimusume(18);

	// ループでまわして全部の自己紹介を一気にさせることができる！
	for(int i = 0; i < 5; i++){
		x[i]->Jikosyoukai();
	}

	// 同様にして、オブジェクトを破棄する
	for(int i = 0; i < 5; i++){
		delete x[i];
	}
}



