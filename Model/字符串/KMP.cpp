#include <cstring>
int next[110];
//kmpģ��
//ע������next�ڴ��ʱ�Ǵ�1��ʼ�ģ������ַ����д���Ǵ�0��ʼ
void get_next(char t[])//���next���飬�൱���Լ����Լ�ƥ��
{
	int i,j;
	i=1;
	next[1]=0;//���õݹ��ı�Ҫ��ʼ��
	j=0;//����j�����Ǳ�iС��
	while(i<strlen(t))
	{
		if(j==0||t[i-1]==t[j-1])//����next�е��±�Ҫ��һ�������ַ�����
		{
			i++;
			j++;
			if(t[i-1]!=t[j-1])
				next[i]=j;
			else
				next[i]=next[j];//������һ���Ż�

		}
		else
			j=next[j];//��ǰ��
	}
}

int kmp(char s[],char t[])
{
	get_next(t);
	int i,j;
	int lens,lent;
	i=1;//��1��ʼ
	j=1;
	while(i<=strlen(s)&&j<=strlen(t))
	{
		if(j==0||s[i-1]==t[j-1]){i++;j++;}
		else
			j=next[j];
	}
	if(j>strlen(t))
		return 1;//����Ҳ���Է���i-strlen��t�������ƥ���������п�ʼ��λ��
	else
		return 0;
}
