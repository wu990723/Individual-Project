#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring> 

using namespace std;
#define MAX_LENGTH 1<<10//���ʵ���󳤶�


typedef struct{
string str;
int cnt;
}word;


int number_of_words=0;//��¼����ͳ������
vector<string> virtual_word;//��Ҫ����ȥ����ʼ�
vector<string> raw_word;//��Դ�ı��еĵ��ʼ�
vector<word> word_statistics;//ͳ�ƽ����


/*�ֵ�����ȽϺ���*/
bool cmp_raw_word(const string &a,const string &b){return a<b;}


/*�ʻ���ִ�����������ȽϺ���*/
bool cmp_word_statistics(const word &a,const word &b){return a.cnt>b.cnt;}


/*���ȡ�Դ�����Դ�ļ��Լ�����ļ�����Сд��ĸ������к��ּ��ַ�*/
bool skip(){ scanf("%*[^a-z||A-Z]"); return true;}


int main(int argc, char **argv)
{
/*��ʼ��ʱ��*/
clock_t start,finish;
double totaltime;
start=clock();


printf("Wait for a moment please.\n");


/*���建��ռ�*/
word w;
char _word[MAX_LENGTH];


vector<string>::iterator it,last;
vector<word>::iterator wit;


/*�ض����������� virtual.txt �ļ�,��ȡ virtual.txt �ļ�����Ӣ�ĵ���*/
freopen("virtual.ini","r",stdin);
while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF) virtual_word.push_back(_word);


/*����ʱ���������Ա�������������*/
sort(virtual_word.begin(),virtual_word.end(),cmp_raw_word);


/*�ض�����������Ŀ���ļ�,����ȡĿ���ļ�������Ӣ�ĵ���*/

char ch[50];
strcpy(ch,argv[1]);
freopen(ch,"r",stdin);
while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF)
{
 number_of_words++;
 /*��ֻ������ĸ��д�ĵ��ʵ�����ĸת����Сд*/
 if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])) _word[0]|=1<<5;
 raw_word.push_back(_word);
}
/*�ض���������� out.txt �ļ���������˵����Ϣ*/
freopen("Result.txt","w",stdout);
printf("-----------------------------------------------\n");
printf("%d words be counted! \nDetails are as follow:\n",number_of_words);
printf("no.   word       time        frequency\n");
printf("-----------------------------------------------\n");
/*��û�м�⵽����ʱ,�������򲢷�����ʾ��Ϣ*/
if(!raw_word.size())
{
 printf("There is no word in the \"in.txt\" or \"in.txt\" inexistence!\n");
printf("-----------------------------------------------\n");
 return 0;
}
/*�Ե��ʼ������ֵ������Ա���г��ִ���ͳ�Ʋ���*/
sort(raw_word.begin(),raw_word.end(),cmp_raw_word);
for(last=raw_word.begin(),it=raw_word.begin()+1;it!=raw_word.end();it++)
{
 if(*it!=*last)
 {
w.str=*last;
w.cnt=it-last;
/*�õ���ͳ�ƽ���� virtual_word ��������֤,δ�� virtual_word �����г��ֲż�����*/
if(!binary_search(virtual_word.begin(),virtual_word.end(),*last)) word_statistics.push_back(w);
last=it;
 }
}
/*�ֲ�����ѭ��ʱ���һ��δ�����뵥��*/
w.str=*last;
w.cnt=it-last;
if(!binary_search(virtual_word.begin(),virtual_word.end(),*last)) word_statistics.push_back(w);
/*�Խ�������г��ִ����ؼ��ʽ�������*/
sort(word_statistics.begin(),word_statistics.end(),cmp_word_statistics);
bool b=false;
for(wit=word_statistics.begin();wit!=word_statistics.end();wit++)
{
 /*Ϊ��֤ͳ��������,��ͳ������������е���*/
 if((*wit).cnt*1.0/number_of_words>=0.05||((*wit).cnt>=2&&(*wit).cnt*100.0/number_of_words>=0.01)){
 printf("%-5d %-16s %5d %17.3lf%%\n",wit-word_statistics.begin()+1,((*wit).str).c_str(),(*wit).cnt,(*wit).cnt*100.0/number_of_words);
 b=true;
 }
}
/*��ͳ�����������������Ŀ������ʾ*/
if(!b)printf("no appropriate word!\n");
printf("-----------------------------------------------\n");
/*���㲢���ͳ�Ƴ������ĵ�ʱ��*/
finish=clock();
totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
printf("The program cost %.4lf second(s)",totaltime);
return 0;
}

