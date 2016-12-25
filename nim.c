#include <stdio.h>

int checkError(int, int);
void showRest(int);
int finish(int);
int select(int);

int main(void) {
	int rest = 15;
	printf("%d個でゲームを開始します。\n\n", rest);

	while (1) {
		// ユーザーのターン
		int count;
		printf("何個取りますか？(1〜3)\n");
		scanf("%d", &count);	// 整数以外が入力された場合は知らん
		if (checkError(rest, count)) continue;
		rest -= count;
		showRest(rest);
		if (finish(rest)) {
			printf("あなたの負けです。\n");
			break;
		}
		 
		// コンピューターのターン
		count = select(rest);
		printf("%d個取りました。\n", count);
		rest -= count;
		showRest(rest);
		if (finish(rest)) {
			printf("あなたの勝ちです。\n");
			break;
		}
	}

	return 0;
}

// ユーザーの入力値が不正であれば1, 正常であれば0を返す。
int checkError(int rest, int count) {
	if (count > 3) {
		printf("入力値の範囲は 1 〜 3 です。\n");
		return 1;
	}

	return 0;
}

// 残りの石の数を表示
void showRest(int rest) {
	printf("残り %d 個です。\n\n", rest);
}

// 勝負が付いていたら1, 付いていなければ0 を返す
int finish(int rest) {
	return (rest <= 0) ? 1 : 0;
}

// コンピューターが取る石の数を求める
int select(int rest) {
	if (rest == 3) return 2;
	if (rest == 2) return 1;
	if (rest == 1) return 1;

	switch (rest % 4) {
		case 0:
			return 3;
		case 1: // これは負けパターンなので、とりあえず1個取る
			return 1;
		case 2:
			return 1;
		case 3:
			return 2;
	}
	return 1; // warning対策
}
