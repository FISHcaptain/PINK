#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct {
	char* str;
	int maxlength;
	int length;
}Dstring;
void Initiate(Dstring* S, int max, char* string) {
	int i;
	S->str = (char*)malloc(sizeof(char) * max);//申请动态数组空间
	S->maxlength = max;
	S->length = strlen(string);//置串的当前长度值
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i];//赋值
}
int Insert(Dstring* S, int pos, Dstring T) {
	int i;
	if (pos < 0) {
		printf("参数pos出错!");
		return 0;
	}
	else {
		if (S->length + T.length > S->maxlength) {
			realloc(S->str, (S->length + T.length) * sizeof(char));
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
int Delete(Dstring* S, int pos, int len) {
	int i;
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
int SubString(Dstring* S, int pos, int len, Dstring* T) {
	int i;
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
}
void main(void) {
	Dstring mystring1, mystring2, mystring3;
	int i, max1 = 5, max2 = 9, max3 = 0;//测试初始化函数
	Initiate(&mystring1, max1, "Data");
	Initiate(&mystring2, max2, "Structure");
	Initiate(&mystring3, max3, "");
	printf("初始mystring2串:          ");
	for (i = 0; i < mystring2.length; i++)
		printf("%c", mystring2.str[i]);
	printf("   maxlength=%d", mystring2.maxlength);
	printf("    length=%d\n", mystring2.length);
	Insert(&mystring2, 0, mystring1);
	printf("插入子串后mystring2串:    ");
	for (i = 0; i < mystring2.length; i++)
		printf("%c", mystring2.str[i]);
	printf("    maxlength=%d", mystring2.maxlength);
	printf("    length=%d\n", mystring2.length);
	Delete(&mystring2, 0, 5);
	printf("删除子串后mystring2串：  ");
	for (i = 0; i < mystring2.length; i++)
		printf("%c", mystring2.str[i]);
	printf("      maxlength=%d", mystring2.maxlength);
	printf("     length=%d\n", mystring2.length);
	SubString(&mystring2, 0, 5, &mystring3);
	printf("取子串后mystring3串：         ");
	for (i = 0; i < mystring3.length; i++)
		printf("%c", mystring3.str[i]);
		printf("    maxlength=%d", mystring3.maxlength);
	printf("     length=%d\n", mystring3.length);
}