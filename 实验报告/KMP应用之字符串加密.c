#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct {
	char* str;
	int maxlength;
	int length;
}Dstring;
void Initiate(Dstring* S, int max, char *string) {
	int i;//��ʼ������
	S->str = (char*)malloc(sizeof(char) * max);//���붯̬����ռ�
	S->maxlength = max;
	S->length = strlen(string);//�ô��ĵ�ǰ����ֵ
	for (i = 0; i < S->length; i++)
		S->str[i] = string[i];//��ֵ
}
int KMPIndex(Dstring S,Dstring T,int next[]) {//kmp�㷨
	//��������S��start��ʼ���Ӵ�T���ɹ��򷵻�T��S�����ַ��±꣬ʧ���򷵻�0
	//����next�д����ģʽ��T��next��j��ֵ
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.str[i] == T.str[j]) {
			++i;
			++j;//�����ȽϺ����ַ�
		}
		else j = next[j];//ģʽ���ƶ�
	}
	if (j > T.length)
		return i - T.length;//ƥ��ɹ�
	else return 0;
}
void GetNext(Dstring T, int next[]) {
	//���Ӵ�T��next��j��ֵ����������next��
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
}//���ܺ���
void main(void) {//��ĸӳ�����ַ������м��ܡ�
	Dstring string1, string2, string3,string4;
	int max1 = 30, max2 = 30, max3 = 30;
	Initiate(&string1, max1, "abcdefghijklmnopqrstuvwxyz");
	Initiate(&string2, max2, "ngzqtcobmuhelkpdawxfyivrsj");
	Initiate(&string3, max3, "encrypt");//������ı�
	Encrypt(string3, string1, string2);
	int i;
	for (i = 0; i < string3.length; i++)
		printf("%c", string3.str[i]);
}//��������ֲ�֪������ɶ����omg������һ��̬����ͳ����⡣