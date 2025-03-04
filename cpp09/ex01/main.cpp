/*
	数値を スタックに積む
	演算子が出たら、スタックの上の2つの数値を取り出して計算
	計算結果を スタックに戻す
	最後にスタックに 1 つの値が残れば正しい計算、そうでなければエラー

	3 4 + 5 2 - * == (3 + 4) * (5 - 2)


	1. コマンドライン引数から RPN 式を受け取る
		例: ./rpn "3 4 + 5 2 - *"
		数値 (3, 4, 5, 2) と演算子 (+, -, *, /) を解析する
	2. スタックを使って計算する
		std::stack<int> を使って、数値を 積む (push) → 取り出す (pop)
	3️. 無効な入力のエラーチェック
		数値以外の無効な文字があるか？
		演算子が適切な場所にあるか？
		計算後にスタックに 1 つの値だけが残っているか？
	4️. 計算結果を表示する
		計算が成功すれば結果を表示
		エラーがあれば適切なメッセージを出す

	std::stack -> the last element you pushed is the top one
	why stack is the most suitable container for this?
	-> because LIFO behavior matchs the RPN caliculation
		push numbers to stack until operator(+-...), then take the number out and do math
	-> because we always want to access the top(last elements), so we can simply access to the one we want!

*/


#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid input." << std::endl;
		std::cerr << "Usage example: ./RPN \"7 7 * 7 -\"" << std::endl;
		return 1;
	}
	argv[1]
	return 0;
}
