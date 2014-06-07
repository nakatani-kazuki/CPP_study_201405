//neko.cpp
#include <iostream>
#include <string>
using namespace std;

class Neko
{
private:
    string name;
    string cry;
public:
    Neko(string s ,string s2){
        name = s;
        cry = s2;
    }
    void naku(){
        cout<<cry<<"。俺様は"<<name<<"だ。"<<endl;
    }
};

int main()
{
    string  s;
    string  s2;
    cout << "どら猫を生成します。名前を入力してください。" << endl;
    cin >> s;
    cout << "鳴き声を決めて下さい" << endl;
    cin >> s2;
    Neko dora(s, s2);
    cout << "あなたの名づけた猫がメモリ上に生成されました。" << endl;
    cout << "猫が鳴きます。" << endl;
    dora.naku();
}

