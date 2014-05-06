//hello3.cpp
#include <iostream>
//ここでも文字列を使うので、stringのライブラリを借りてくる
#include <string>
using namespace std;

int main()
{
    string name; //名前を受ける入れ物
    int age; //整数（年齢）の入れ物

    cout << "こんにちは。私はコンピュータです。" << endl;
    cout << "あなたの名前を入力してください。" <<endl;
    cin >> name; //名前をキーボードから入力してもらう

    cout << name << "さん、よろしく。" << endl;

    cout << "ところで、" << name << "さん。失礼ですがお年はおいくつですか？" << endl;
    cout << "入力はかならず、半角の数字でお願いします。" << endl;
    cin >> age; //年齢を半角で入力してもらう

    cout << "なるほど。" << age << "歳ですか。" << endl;
    cout << "私はもうすぐ2歳のマシンです。" << endl;    
}



