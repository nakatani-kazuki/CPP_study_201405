//hito_sample.cpp
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

void Hito::Jikosyoukai(){
	// 自己紹介するごとにパワーが1減る
	power--;
	cout << "俺は人だ。" << endl;
	cout << "俺のパワーは" << power << "だ。" << endl;
}

int main(){
	Hito *p;
	// とりあえずパワー10のHitoを作る
	p = new Hito(10);
	// pのとこにあるオブジェクトのJikosyoukaiを呼ぶ
	p->Jikosyoukai();
	delete p;
}



