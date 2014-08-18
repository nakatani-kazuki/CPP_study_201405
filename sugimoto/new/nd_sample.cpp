//nd_sample.cpp
#include <iostream>
using namespace std;

class Nanika{
	int datum;
public:
	// 引数を取らないコンストラクタ
	Nanika() : datum(0){
		cout << "Nanikaのインスタンス" << datum << "が生成されました。" << endl;
	}

	// 引数を取るコンストラクタ
	Nanika(int x) : datum(x){
		cout << "Nanikaのインスタンス" << datum << "が生成されました。" << endl;
	}

	void func() const{
		cout << "Nanikaのインスタンス" << datum << "のfuncが呼ばれました。" << endl;
	}

	// デストラクタ
	~Nanika(){
		cout << "Nanikaのインスタンス" << datum << "が消滅しました。" << endl;
	}
};

int main(){
	// Nanikaのポインタ（住所）を先に用意する
	Nanika *p;
	cout << "Nanikaのオブジェクトを生成" << endl;
	p = new Nanika(1);

	// pはポインタなので、関数を呼び出すのには->を使う
	p->func();

	// デストラクタを使って、インスタンスを消滅させる
	delete p;
}


