//cup.cpp
#include <iostream>
using namespace std;

class Cup
{
	int nakami;
public:
	// //↓cupオブジェクトを、nakami10の決め打ちで作る
	// Cup() : nakami(10){}

	//↓cupオブジェクトを、xの変数を受けて、nakamiにxを代入できるようにする
	Cup(int x) : nakami(x){}
	void dasu(int);
	void ireru(int);
};

void Cup::ireru(int z){
	nakami += z;
	cout << "水を入れました。" <<endl;
	cout << "現在のコップの中身は" << nakami << "です。" << endl;
}

void Cup::dasu(int y){
	if(nakami >= y){
		nakami -=y;
		cout << "水を出しました。" <<endl;
		cout << "現在のコップの中身は" << nakami << "です。" << endl;
	}
	else{
		cout << "そんなに水がありません。" <<endl;
		cout << "現在のコップの中には" << nakami << "入っているだけです。" << endl;
	}
}

// int main()
// {
// 	int x;
// 	cout << "コップを生成します。どれだけ水をいれるか入力してください。" << endl;
// 	cin >> x;
// 	Cup cup(x);
// 	int y;
// 	cout << "コップから水を出します。出す量を入力してください。" << endl;
// 	cin >> y;
// 	cup.dasu(y);
// 	int z;
// 	cout << "コップから水が減ってしまった！ちょっと足します。足す量を入力してください。" << endl;
// 	cin >> z;
// 	cup.ireru(z);
// 	cout << "終了" <<endl;
// }

int main()
{
	int x;
	cout << "コップを生成します。どれだけ水をいれるか入力してください。" << endl;
	cin >> x;
	Cup cup(x);

	int ans;
	cout << "水を出したい場合は1、足したい場合は5を入力してください" << endl;
	cin >> ans;
	if(ans == 1){
		int y;
		cout << "コップから水を出します。出す量を入力してください。" << endl;
		cin >> y;
		cup.dasu(y);
	}
	else if(ans == 5){
		int z;
		cout << "コップに水を足します。足す量を入力してください。" << endl;
		cin >> z;
		cup.ireru(z);
	}
	else{
		cout << "入力した数字が間違っています。" << endl;
	}
	cout << "終了" <<endl;
}








