////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: arthuryang
////Nickname: ArthurYang
////Run ID: 
////Submit time: 2014-01-15 15:48:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1736
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1352KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <string>
using namespace std;
 
int main()
{
 //wchar_t ch;
 //wcin.imbue(locale("chs"));   //���ﲻ����wchar_t�������������
 
 //wcout.imbue(locale("chs"));
 int flag = 0;  // 0��ʾ��ߣ�1��ʾ�ұ�
 char article[1000000];
    while(gets(article) != NULL)
    {
     flag = 0;
     int len = strlen(article);
      for(int i=0; i<len; ++i)
   { 
      string tmp ;
   tmp =  tmp+article[i] + article[i+1];   // �����ж��Ƿ�������"��"��"��"
          if(tmp=="��" || tmp=="��")
              flag = !flag;  
   if(article[i] == ',')
               cout << "��";
        else if(article[i] == '.')
                  cout << "��";
           else if(article[i] == '!')
                 cout << "��";
           else if(article[i] == '"')
           {
                if(flag == 0)
                    cout << "��";
                else
                    cout << "��";
                flag = !flag;
            }
            else if(article[i] == '<' && article[i+1]=='<')
            {
                  cout << "��";
                  i++;
            }
            else if(article[i] == '>' && article[i+1]=='>')
            {
                  cout << "��";
                  i++;
            }
             else if(article[i] == '?')
                 cout << "��";
             else
                  cout << article[i];
  }
  cout << endl;
    }
 return 0;
}