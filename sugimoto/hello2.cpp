//hello2.cpp
#include <iostream>
//文字列をこのプログラムのなかで使えるようにするために、ライブラリを借りてくる
#include <string>
using namespace std;

int main()
{
    //↓stringは文字列の総称。nameは勝手に決めた変数名みたいなもん。
    //変数を定義するときに、「これは何を入れる用の箱です」っていう種別も最初に定義する必要がある
    string name;
    cout << "こんにちは。私はコンピュータです" << endl;
    cout << "あなたの名前を入力してください" << endl;
    //↓cin は、標準入力から入力を受けとってnameの中に突っ込む
    cin >> name;
    cout << name << "さん、よろしく。" << endl;
}






