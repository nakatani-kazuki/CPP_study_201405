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
    Neko(string s){
        name = s;
    }
    void set_cry(string s){
        cry = s;
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
    Neko dora(s);
    cout << "あなたの名づけた猫がメモリ上に生成されました。" << endl;
    cout << "鳴き声を決めて下さい" << endl;
    cin >> s2;
    dora.set_cry(s2);
    cout << "猫が鳴きます。" << endl;
    dora.naku();
}

