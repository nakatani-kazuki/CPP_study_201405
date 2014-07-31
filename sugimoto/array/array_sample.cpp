//hairetu_sample.cpp
//10人の学生の点数を入力し、その平均値を計算するプログラム
#include <iostream>
using namespace std;

int tensu[10]; //0〜9までの整数を格納する、10個の入れ物の配列。

int main(){
	int sum = 0; //合計点を入れる入れ物
	cout << "10人の点数を順番に入力してください。" << endl;
	//配列の番号[10]になるまで、1つずつ数を増やしていく
	for (int i = 0; i < 10; i++){
		cin >> tensu[i]; //配列にひとつずつ点数をcin
	}
	cout << "それでは平均点を計算します。" << endl;
	//全部の数を合計（配列の中身をひとつずつ足していく）
	for (int i = 0; i < 10; i++){
		sum += tensu[i];
	}
	cout << "平均点は" << sum/10 << "点です。" << endl;

	//↓配列の要素数を求める関数。
	//sizeofはバイト数を返す変数らしくて、１要素あたりのバイトで割ると、配列のハコの数が出る、という仕組みだそう。
	int size = sizeof(tensu) / sizeof(tensu[0]);
	cout << "配列の要素数は" << size << "です。" << endl;
}


//こう書いてみたけど、なぜこれでは動かないのか…
// void test(){
// 	int size = sizeof(tensu);
// 	cout << "配列の要素数は" << size << "です。" << endl;
// }