// wc0.1.0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<stdio.h>


int number(FILE* p) {//字符数
	int n = 0;
	char r;
	r = fgetc(p);
	for (; r != EOF;) {
		n++;
		r = fgetc(p);
		//putchar(r);
		//printf("___%d\n", n);
	}
	return n;
}

int line(FILE* p) {//行数
	int n = 0;
	int i = 1;
	char r;
	r = fgetc(p);
	for (; r != EOF;) {
		n++;
		r = fgetc(p);
		if (r == '\n') {
			i++;
			//printf("(%d)", i);
		}
		//putchar(r);
		//printf("___%d\n",n);
	}
	return i;
}

int check(char r) {//判断r是否为字母或数字，ASCII码：48~57,65~90,97~122
	int a, b, c;
	a = ((r > 47) && (r < 58));
	b = ((r > 64) && (r < 91));
	c = ((r > 96) && (r < 123));
	return a || b || c;
}

int word(FILE *p) {//词数
	int n = 0;
	int i = 0;
	char r1,r2;
	r1 = fgetc(p);
	r2 = r1;
	for (; (r1 != EOF) && r2 != EOF;) {
		n++;
		r1 = fgetc(p);
		if (check(r1)){
			r2 = fgetc(p);
			while (check(r2)) {
				r2 = fgetc(p);
			}
			i++;
		}
		//putchar(r);
		//printf("___%d\n",n);
	}
	return i;
}

int main() {
	FILE* fp;
	//printf("0\n");
	fopen_s(&fp, "file.c", "r");
	if (fp == NULL) {
		printf("ERROR");
		return 0;
	}
	//printf("1\n");
	printf("字符数：%d\n", number(fp));
	fopen_s(&fp, "file.c", "r");
	printf("列数：%d", line(fp));
	fopen_s(&fp, "file.c", "r");
	printf("词数：%d", word(fp));
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
