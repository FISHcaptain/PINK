#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct {
	char* str;
	int maxlength;
	int length;
}Dstring;
void Initiate(Dstring* S, int max, char *string) {
	int i;//初始化函数
	S->str = (char*)malloc(sizeof(char) * max);//申请动态数组空间
	S->maxlength = max;
	S->length = strlen(string);//置串的当前长度值
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i];//赋值
}
int KMPIndex(Dstring S,Dstring T,int next[]) {//kmp算法
	//查找主串S从start开始的子串T，成功则返回T在S中首字符下标，失败则返回0
	//数组next中存放有模式串T的next【j】值
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.str[i] == T.str[j]) {
			++i;
			++j;//继续比较后续字符
		}
		else j = next[j];//模式串移动
	}
	if (j > T.length)
		return i - T.length;//匹配成功
	else return 0;
}
void GetNext(Dstring T, int next[]) {
	//求子串T的next【j】值并存于数组next中
	int j = 0, i = 1;
	next[1] = 0;
	while (i< T.length) {
		if (j == 0 || T.str[i] == T.str[j]) {
			j++;
			i++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
void Encrypt(Dstring T,Dstring S,Dstring F) {
	int i;
	Dstring string5;
	int max5 = 1;
	int next[30];
	for (i = 0; i < T.length; i++)
		Initiate(&string5, max5, T.str[i]);
	GetNext(string5, next);
	KMPIndex(S, T, next);
	T.str[i] = F.str[KMPIndex(S, T, next)];
}//加密函数
void main(void) {//字母映射表对字符串进行加密。
	Dstring string1, string2, string3,string4;
	int max1 = 30, max2 = 30, max3 = 30;
	Initiate(&string1, max1, "abcdefghijklmnopqrstuvwxyz");
	Initiate(&string2, max2, "ngzqtcobmuhelkpdawxfyivrsj");
	Initiate(&string3, max3, "encrypt");//需加密文本
	Encrypt(string3, string1, string2);
	int i;
	for (i = 0; i < string3.length; i++)
		printf("%c", string3.str[i]);
}//这个程序又不知道出了啥问题omg，好像一动态分配就出问题。