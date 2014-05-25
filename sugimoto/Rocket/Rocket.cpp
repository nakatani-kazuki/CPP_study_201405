//neko.cpp
#include <iostream>
#include <string>
using namespace std;

class Rocket
{
	int nenryo;
	int sokudo;
public:
	Rocket(int);
	void kasoku();
};

Rocket::Rocket(int x){
	nenryo = x;
	sokudo = 0;
}

void Rocket::kasoku(){
	if(nenryo >= 2){
		sokudo +=2;
		nenryo -=2;
		cout<< "現在の燃料は" << nenryo << "です。" <<endl;
		cout<< "現在の速度は" << sokudo << "です。" <<endl;
	}
	else {
			cout<< "燃料切れです。加速できません。漂流です。" <<endl;	
	}
}

int main(){
	cout<< "ロケットをメモリ上につくります。燃料（整数）を入力してください" <<endl;
	int n;  //ユーザの入力した数字を受ける
	cin >> n; //キーボードで入寮kされた数字をnに入れる

	//nを使ってRocketをビルドする。nは整数
	Rocket ohtori(n);
	cout << "加速します。" << endl;
	ohtori.kasoku(); //鳳の中の加速機能を使う
	cout << "また、加速します。" << endl;
	ohtori.kasoku();
	cout << "またまた、加速します。" << endl;
	ohtori.kasoku();
	cout << "鳳号の冒険は終わりました。" << endl;




}





