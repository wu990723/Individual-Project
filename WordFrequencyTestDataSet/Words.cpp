//�ó���Ϊ����Ƶ��ͳ�ƣ��ɶ�ȡһ��Ӣ���ı��ļ����������ţ���������Ļ�������������Ӣ���ı��г��ֵĴ�����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define i 1000
int b;
struct word
{
  char w[20];
  int num;

}s[i];
void file1()//�����ļ��ڵĵ���
{
  FILE *p;
  int j,k;
  char temp[20];
  if((p=fopen("1.txt","r"))==NULL)
  {
    printf("�޷��򿪴��ļ���\n");
    exit(0);

  }
  while(!feof(p))
  {

   for(j=0;j<20;j++)
   {
     temp[j]=fgetc(p);
     if(temp[j]==' '||temp[j]==','||temp[j]=='.'||temp[j]=='!'||temp[j]=='?')
     {
       temp[j]='\0';

           strcpy(s[b].w,temp);

       b++;
       break;
     }

   }
      }
  fclose(p);

}

void file2()//�����ʼ���Ƶ��д���ļ���
{
   FILE *q;
       int j;
       if((q=fopen("5.txt","w"))==NULL)
       {
           printf("�޷��򿪴��ļ���\n");
           return;
       }
       for(j=0;j<b;j++)
          if((fwrite(&s[j],sizeof(struct word),1,q)!=1)&&(s[j].num>0))
           printf("�޷��򿪴��ļ���\n");
          fclose(q);
}

void count()//ͳ�����е��ʵĸ���
{
  int j;
   printf("�ļ��еĵ�����Ϊ��%d\n\n",b);
   printf("������е��ʣ����ֵ�˳���������\n");
   for(j=0;j<b;j++)
       printf("%s ",s[j].w);
       printf("\n\n");
}
void hz()//ͳ��ÿ�����ʳ��ֵ�Ƶ��
{
   int j,k,flag=1;
      for(j=0;j<b;j++)
      {
        for(k=0;k<j;k++)
        {
          if(strcmp(s[j].w,s[k].w)==0)
          {
              flag=0;
              break;
          }
          else flag=1;

        }
        while(flag)
        {
          for(k=j;k<b;k++)
          {
            if(strcmp(s[k].w,s[j].w)==0)
                s[j].num++;


          }

        flag=0;
        }
      }
}

void sort()//�����ʰ��ֵ�˳������
{
  int j,k,c;
  char temp[20];
  for(j=0;j<b-1;j++)
  {
      c=j;
      for(k=j+1;k<b;k++)
         if(strcmp(s[c].w,s[k].w)>0)
             c=k;
         if(c!=j)
         {
           strcpy(temp,s[c].w);
           strcpy(s[c].w,s[j].w);
           strcpy(s[j].w,temp);
         }
  }

}

void shuchu()//������ʼ����ʵ�Ƶ��
{
    int j;
    printf("������ʼ����Ƶ�ʣ�\n");
    for(j=0;j<b;j++)
    {
        if(s[j].num>0)
        printf("%s����%d�� ",s[j].w,s[j].num);
    }
   printf("\n\n");

}

int main()//������
{
  file1();
  sort();
  hz();
  count();
  shuchu();
  file2();
  return 0;
}
