//neko.cpp
#include <iostream>
#include <string>
using namespace std;

class Neco
{
//外部からはアクセスできない2
private:
	string name;
//外部からも使ったり表示させたりすることができる
public:
	//体力
	int hp;
	//ビルドする。class名で同じ名前を定義しないといけないらしい
	Neco(string s){
		name = s;
		hp = 10;
	}

	//食事をもらう（もらって食べた量だけ体力を増やす）
	int eat(int i){
		hp += i;
		cout << "えさを" << i << "食べました" << endl;
		return hp;
	}

	//鳴いて体力を5減らす関数
	int naku(string call){
		cout<< call << "。俺様は" << name << "だ。" << endl;
		hp -= 5;
		return hp;
	}

};

int main()
{
	string s;
	int current_hp;
	int food;
	cout << "どら猫を生成します。名前を入力してください。" << endl;
	cin >> s;
	Neco dora(s);
	cout << "あなたの名づけた猫がメモリ上に生成されました。" << endl;
	//鳴き声を入力。鳴くと体力が減る。
	string call;
	cout << "では、この子の鳴き声を入力してください。" << endl;
	cin >> call;
	cout << "猫が鳴きます。" << endl;
	current_hp = dora.naku(call);
	cout << "現在の体力は" << current_hp <<"です。" << endl;	
	//ごはんをあげる。ごはんをあげると体力が増える。
	cout << "では、この子にえさをあげる数を入力してください" << endl;
	cin >> food;
	cout << "えさをあげました。" << endl;
	current_hp = dora.eat(food);
	cout << "現在の体力は" << current_hp <<"です。" << endl;	
}


//↓最初にやった、名前を[dora]決め打ちにするパターン
// int main()
// {
// 	//↓perlでやってたところの、ビルドしたものを受け取る変数名みたいな役
// 	Neco dora("ボス");
// 	cout << "あなたの名づけた猫がメモリ上に作成されました。" << endl;
// 	cout << "猫が鳴きます。" << endl;
// 	//doraはもうobject化されてるから、そいつのもってるnakuを呼び出す
// 	dora.naku();
// }

