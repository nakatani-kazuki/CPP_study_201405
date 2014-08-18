//hito_sample2.cpp
#include <iostream>
using namespace std;


class Hito{
	int power;
public:
	Hito(int x) : power(x){}
	// xを受け取ってpowerに代入する
	void set_power(int x){ power = x; }
	int get_power() const{ return power; }
	void Jikosyoukai();
};

class Samurai : public Hito{
public:
	// Hitoにxを渡すだけ
	Samurai(int x) : Hito(x){}
	// Hitoと同名のメンバ関数
	void Jikosyoukai();
};



void Hito::Jikosyoukai(){
	// 自己紹介するごとにパワーが1減る
	power--;
	cout << "俺は人だ。" << endl;
	cout << "俺のパワーは" << power << "だ。" << endl;
}

void Samurai::Jikosyoukai(){
	// パワーを持ってきて、1減らして、その値をセットする。外からのアクセスになるので関数を呼び出す
	set_power(get_power() -1);
	cout << "俺はさむらいだ。" << endl;
	cout << "俺のパワーは" << get_power() << "だ。" << endl;
}



int main(){
	Hito *p1 , *p2;
	// p1にHitoを作ってJikosyoukaiさせる
	p1 = new Hito(10);
	p1->Jikosyoukai();

	// p2にSamuraiを作ってJikosyoukaiさせる
	p2 = new Samurai(12);
	p2->Jikosyoukai();

	delete p1;
	delete p2;
}



