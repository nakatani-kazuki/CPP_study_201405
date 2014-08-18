//hito_sample4.cpp
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
	Hito One(10);
	Samurai Two(12);
	Ninja Three(14);
	Matimusume Four(16);
	Hito *p;

	// pにOne（という名前のHito）を入れて、pのJikosyoukaiを呼び出す
	p = &One;
	p->Jikosyoukai();

	// pにTwo（という名前のSamurai）を入れて、pのJikosyoukaiを呼び出す
	p = &Two;
	p->Jikosyoukai();

	// pにThree（という名前のNinja）を入れて、pのJikosyoukaiを呼び出す
	p = &Three;
	p->Jikosyoukai();

	// pにFour（という名前のMatimusume）を入れて、pのJikosyoukaiを呼び出す
	p = &Four;
	p->Jikosyoukai();
}



