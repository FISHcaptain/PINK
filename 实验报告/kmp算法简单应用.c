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
	int i;										 // ��ʼ������
	S->str = (char *)malloc(sizeof(char) * max); // ���붯̬����ռ�
	S->maxlength = max;
	S->length = strlen(string); // �ô��ĵ�ǰ����ֵ
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i]; // ��ֵ
}
int Insert(Dstring *S, int pos, Dstring T)
{		   // �����Ӵ�����
	int i; // ��������λ��pos�����Ӵ�t
	if (pos < 0)
	{
		printf("����pos����!");
		return 0;
	}
	else
	{
		if (S->length + T.length > S->maxlength)
		{
			// ����1 ֱ����ԭ�е�ַ�Ͻ����µ��ڴ����룬�ƻ���ԭ�����ݡ�ȥ���������ʲô������ ����ԭ��������123 ��Ҫ���뵽����6��ֱ����ԭ�е�ַ�������µ��ڴ棬ԭ����123�ͱ��ƻ����Ҳ�����
			// ���������� ������һ���ڴ棬Ȼ���ԭ�����ݿ�����ȥ�������ԭ�����ݵ�ָ��ָ����������ڴ� (���)

			// ����2 malloc������ڴ���δ��ʼ���ģ�����������һ���ڴ� �ڴ����������������ݣ��������ӡ���ĵ�ԭ������ڴ�δ��ʼ������ʶ��������������
			// ʹ��calloc�����ڴ���Զ���ʼ���ڴ�Ϊ\0�� �ַ���Ĭ����\0�ֽ�Ϊ��β���������������ݾ���ʶ�𵽣�������ȥ������ȡδ��ʼ�����ڴ�
			char *new_string = (char *)calloc((S->length + T.length), sizeof(char)); // ������������ɶ����
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
{		   // ɾ���Ӵ�����
	int i; // ɾ�������д�λ��pos��ʼ����Ϊlen���Ӵ�
	if (S->length <= 0)
	{
		printf("������δ����ַ���Ԫ�ؿ�ɾ��\n");
		return 0;
	}
	else if (pos < 0 || len < 0 || pos + len > S->length)
	{
		printf("����pos��len���Ϸ�");
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
{		   // ȡ�Ӵ�����
	int i; // ȡ����S��pos�ĳ���Ϊlen���Ӵ���ȡ�ɹ��򷵻�1��ʧ���򷵻�0
	if (pos < 0 || len < 0 || pos + len > S->length)
	{
		printf("����pos��len����");
		return 0;
	}
	if (len > T->maxlength)
	{
		T->str = (char *)calloc(len, sizeof(char));
		T->maxlength = len;
	}
	// ����3 �ִ��ĳ�ʼ����������ʼ����֮ǰû��⵽�����ڸ�ʲô����
	for (i = 0; i < len; i++)
	{
		T->str[i] = S->str[pos + i];
	}
	T->length = len;
	return 1;
} // λ�ô�0��ʼ����
int KMPIndex(Dstring S, Dstring T, int next[])
{ // kmp�㷨
	// ��������S��start��ʼ���Ӵ�T���ɹ��򷵻�T��S�����ַ��±꣬ʧ���򷵻�0
	// ����next�д����ģʽ��T��next��j��ֵ
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (j == 0 || S.str[i] == T.str[j])
		{
			++i;
			++j; // �����ȽϺ����ַ�
		}
		else
			j = next[j]; // ģʽ���ƶ�
	}
	if (j > T.length)
		return i - T.length; // ƥ��ɹ�
	else
		return 0;
}
void GetNext(Dstring T, int next[])
{
	// ���Ӵ�T��next��j��ֵ����������next��
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
	// ����string2��ͷ6���ַ���Ӷ�string1��β����������
	// ���Ҵ�string3�ڴ�string1�е�λ��pos����string3��������string1.��string3����string1�ĵ�����λ����
	Dstring string1, string2, string3, string4;
	int i, max1 = 20, max2 = 15, max3 = 5;
	int max4 = 8;
	int next[30];
	int pos = 0;
	Initiate(&string1, max1, "typedefstructArcBox");
	Initiate(&string2, max2, "VertexTypedata");
	Initiate(&string3, max3, "data");
	Initiate(&string4, max4, "");
	printf("      string1��:");
	for (i = 0; i < string1.length; i++)
	{
		printf("%c", string1.str[i]);
	}

	printf("     string2��:");
	for (i = 0; i < string2.length; i++)
	{
		printf("%c", string2.str[i]);
	}

	// kmp�㷨����
	GetNext(string3, next);
	pos = KMPIndex(string1, string3, next);
	if (pos == 0)
	{
		Insert(&string1, 6, string3);
		printf("����string3֮���string1Ϊ��");
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
	printf("        ����֮��string1�ǣ�");
	// ����4 ���е�if else for���߼��жϴ�������̣�ֻҪ��ִ�д��붼��{}��������������ifelse��Ҫ��Ӧ�ϣ������������if��{}elseû�е������forѭ��Ҳ����{}
	for (i = 0; i < string1.length; i++)
	{
		printf("%c", string1.str[i]);
	}

} // ��֪��Ϊɶ��������˺��֣�����һ������Ĵ�����һ���ġ�
