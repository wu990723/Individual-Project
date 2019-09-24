//该程序为单词频率统计，可读取一个英文文本文件（含标点符号），可在屏幕上输出个单词在英文文本中出现的次数。
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
void file1()//读出文件内的单词
{
  FILE *p;
  int j,k;
  char temp[20];
  if((p=fopen("1.txt","r"))==NULL)
  {
    printf("无法打开此文件！\n");
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

void file2()//将单词及其频率写入文件内
{
   FILE *q;
       int j;
       if((q=fopen("5.txt","w"))==NULL)
       {
           printf("无法打开此文件！\n");
           return;
       }
       for(j=0;j<b;j++)
          if((fwrite(&s[j],sizeof(struct word),1,q)!=1)&&(s[j].num>0))
           printf("无法打开此文件！\n");
          fclose(q);
}

void count()//统计所有单词的个数
{
  int j;
   printf("文件中的单词数为：%d\n\n",b);
   printf("输出所有单词（按字典顺序输出）：\n");
   for(j=0;j<b;j++)
       printf("%s ",s[j].w);
       printf("\n\n");
}
void hz()//统计每个单词出现的频率
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

void sort()//将单词按字典顺序排序
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

void shuchu()//输出单词及单词的频率
{
    int j;
    printf("输出单词及其的频率：\n");
    for(j=0;j<b;j++)
    {
        if(s[j].num>0)
        printf("%s出现%d次 ",s[j].w,s[j].num);
    }
   printf("\n\n");

}

int main()//主函数
{
  file1();
  sort();
  hz();
  count();
  shuchu();
  file2();
  return 0;
}
