#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct
{
	char *str;
	int maxlength;
	int length;
} Dstring;
void Initiate(Dstring *S, int max, char *string)
{
	int i;										 // 初始化函数
	S->str = (char *)malloc(sizeof(char) * max); // 申请动态数组空间
	S->maxlength = max;
	S->length = strlen(string); // 置串的当前长度值
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i]; // 赋值
}
int Insert(Dstring *S, int pos, Dstring T)
{		   // 插入子串函数
	int i; // 在主串的位置pos插入子串t
	if (pos < 0)
	{
		printf("参数pos出错!");
		return 0;
	}
	else
	{
		if (S->length + T.length > S->maxlength)
		{
			// 错误1 直接在原有地址上进行新的内存申请，破坏了原有内容。去搜索深拷贝是什么东西。 比如原来内容是123 你要申请到长度6，直接在原有地址上申请新的内存，原来的123就被破坏了找不到了
			// 正常操作是 新申请一块内存，然后把原有数据拷贝过去，最后让原有内容的指针指向新申请的内存 (深拷贝)

			// 错误2 malloc申请的内存是未初始化的，比如申请了一块内存 内存里面会是乱码的内容，你这里打印中文的原因就是内存未初始化，被识别成了乱码的中文
			// 使用calloc申请内存会自动初始化内存为\0， 字符串默认以\0字节为结尾，这样有新增内容就能识别到，不至于去继续读取未初始化的内存
			char *new_string = (char *)calloc((S->length + T.length), sizeof(char)); // 不晓得这里有啥错误
			S->maxlength = S->length + T.length;
			for (int j = 0; j < S->length; j++)
			{
				new_string[j] = S->str[j];
			}
			S->str = new_string;
		}
		for (i = S->length - 1; i >= pos; i--)
			S->str[i + T.length] = S->str[i];
		for (i = 0; i < T.length; i++)
			S->str[pos + i] = T.str[i];
		S->length += T.length;
		return 1;
	}
}
int Delete(Dstring *S, int pos, int len)
{		   // 删除子串函数
	int i; // 删除主串中从位置pos开始长度为len的子串
	if (S->length <= 0)
	{
		printf("数组中未存放字符无元素可删！\n");
		return 0;
	}
	else if (pos < 0 || len < 0 || pos + len > S->length)
	{
		printf("参数pos和len不合法");
		return 0;
	}
	else
	{
		for (i = pos + len; i <= S->length - 1; i++)
			S->str[i - len] = S->str[i];
		S->length = S->length - len;
		return 1;
	}
}
int SubString(Dstring *S, int pos, int len, Dstring *T)
{		   // 取子串函数
	int i; // 取主串S从pos的长度为len的子串，取成功则返回1，失败则返回0
	if (pos < 0 || len < 0 || pos + len > S->length)
	{
		printf("参数pos和len出错！");
		return 0;
	}
	if (len > T->maxlength)
	{
		T->str = (char *)calloc(len, sizeof(char));
		T->maxlength = len;
	}
	// 错误3 字串的初始化是这样初始化，之前没理解到代码在干什么操作
	for (i = 0; i < len; i++)
	{
		T->str[i] = S->str[pos + i];
	}
	T->length = len;
	return 1;
} // 位置从0开始计数
int KMPIndex(Dstring S, Dstring T, int next[])
{ // kmp算法
	// 查找主串S从start开始的子串T，成功则返回T在S中首字符下标，失败则返回0
	// 数组next中存放有模式串T的next【j】值
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.str[i] == T.str[j])
		{
			++i;
			++j; // 继续比较后续字符
		}
		else
			j = next[j]; // 模式串移动
	}
	if (j > T.length)
		return i - T.length; // 匹配成功
	else
		return 0;
}
void GetNext(Dstring T, int next[])
{
	// 求子串T的next【j】值并存于数组next中
	int j = 0, i = 1;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.str[i] == T.str[j])
		{
			j++;
			i++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
void main(void)
{
	// 将串string2的头6个字符添加都string1的尾部，输出结果
	// 查找串string3在串string1中的位置pos，若string3不存在于string1.则将string3插入string1的第六个位置上
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
	{
		printf("%c", string1.str[i]);
	}

	printf("     string2是:");
	for (i = 0; i < string2.length; i++)
	{
		printf("%c", string2.str[i]);
	}

	// kmp算法运用
	GetNext(string3, next);
	pos = KMPIndex(string1, string3, next);
	if (pos == 0)
	{
		Insert(&string1, 6, string3);
		printf("插入string3之后的string1为；");
		for (i = 0; i < string1.length; i++)
		{
			printf("%c", string1.str[i]);
		}
	}
	else
	{
		printf("%d", pos);
	}
	SubString(&string2, 0, 6, &string4);
	Insert(&string1, 18, string4);
	printf("        操作之后string1是：");
	// 错误4 所有的if else for等逻辑判断处理的流程，只要有执行代码都用{}包起来，尤其是ifelse需要对应上，这里大量出现if有{}else没有的情况，for循环也不带{}
	for (i = 0; i < string1.length; i++)
	{
		printf("%c", string1.str[i]);
	}

} // 不知道为啥结果出现了汉字，和上一个程序的错误是一样的。
