#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct {
	char* str;
	int maxlength;
	int length;
}Dstring;
void Initiate(Dstring* S, int max, char* string) {
	int i;//初始化函数
	S->str = (char*)malloc(sizeof(char) * max);//申请动态数组空间
	S->maxlength = max;
	S->length = strlen(string);//置串的当前长度值
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i];//赋值
}
int Insert(Dstring* S, int pos, Dstring T) {//插入子串函数
	int i;//在主串的位置pos插入子串t
	if (pos < 0) {
		printf("参数pos出错!");
		return 0;
	}
	else {
		if (S->length + T.length > S->maxlength) {
			realloc(S->str, (S->length + T.length) * sizeof(char));//不晓得这里有啥错误
			S->maxlength = S->length + T.length;
		}
		for (i = S->length - 1; i >= pos; i--)
			S->str[i + T.length] = S->str[i];
		for (i = 0; i < T.length; i++)
			S->str[pos + i] = T.str[i];
		S->length += T.length;
		return 1;
	}
}
int Delete(Dstring* S, int pos, int len) {//删除子串函数
	int i;//删除主串中从位置pos开始长度为len的子串
	if (S->length <= 0) {
		printf("数组中未存放字符无元素可删！\n");
		return 0;
	}
	else if (pos < 0 || len<0 || pos + len>S->length) {
		printf("参数pos和len不合法");
		return 0;
	}
	else {
		for (i = pos + len; i <= S->length - 1; i++)
			S->str[i - len] = S->str[i];
		S->length = S->length - len;
		return 1;
	}
}
int SubString(Dstring* S, int pos, int len, Dstring* T) {//取子串函数
	int i;//取主串S从pos的长度为len的子串，取成功则返回1，失败则返回0
	if (pos < 0 || len<0 || pos + len>S->length) {
		printf("参数pos和len出错！");
		return 0;
	}
	if (len > T->maxlength) {
		T->str = (char*)malloc(len * sizeof(char));
		T->maxlength = len;
	}
	for (i = 0; i < len; i++)
		T->length = len;
	return 1;
}//位置从0开始计数
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
void main(void) {
	//将串string2的头6个字符添加都string1的尾部，输出结果
	//查找串string3在串string1中的位置pos，若string3不存在于string1.则将string3插入string1的第六个位置上
	Dstring string1, string2, string3, string4;
	int i, max1 = 20, max2 = 15, max3 = 5;
	int max4 = 8;
	int next[30];
	int pos = 0;
	Initiate(&string1, max1, "typedefstructArcBox");
	Initiate(&string2, max2, "VertexTypedata");
	Initiate(&string3, max3, "data");
	Initiate(&string4, max4, "");
	printf("      string1是:");
	for (i = 0; i < string1.length; i++)
		printf("%c", string1.str[i]);
	printf("     string2是:");
	for (i = 0; i < string2.length; i++)
		printf("%c", string2.str[i]);
	//kmp算法运用
	GetNext(string3, next);
	pos = KMPIndex(string1, string3, next);
	if (pos == 0) {
		Insert(&string1, 6, string3);
		printf("插入string3之后的string1为；");
		for (i = 0; i < string1.length; i++);
		printf("     %c", string1.str[i]);
	}
	else printf("%d", pos);
	SubString(&string2, 0, 6, &string4);
	Insert(&string1, 18, string4);
	printf("        操作之后string1是：");
	for (i = 0; i < string1.length; i++)
		printf("%c", string1.str[i]);
}//不知道为啥结果出现了汉字，和上一个程序的错误是一样的。
