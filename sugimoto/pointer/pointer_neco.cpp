//pointer_neko.cpp
#include <iostream>
#include <string>
using namespace std;

class Neco{
	string name;
public:
	Neco(string);
	void naku() const;
};

Neco::Neco(string s) : name(s){}

void Neco::naku() const{
	cout << "にゃあ。俺様は" << name << "だ。" << endl;
}

int main(){
	Neco dora("ボス");
	Neco* pcat; //変数宣言してないのになんで動くの？

	pcat = &dora;
	dora.naku();
	pcat->naku();
}


