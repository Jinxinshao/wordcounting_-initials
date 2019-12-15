/*
File name:词频统计.cpp
Author:杨柳
Date:2017.3.25
IDE:DEV-c++ 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 100000


// C++ program to print initials of a name 
#include <bits/stdc++.h> 
using namespace std;



//int a;

struct Word      //单词结构体
{
int  num;//单词频数
char ch[20];//每一个单词
} word[MAX_NUM];
int select=1;//select 为是否退出系统的标记
 
//向用户提供帮助说明
void help()
{
    printf("\n（1）可导入任意英文文本文件");
	printf("\n（2）统计该英文文件中单词数和各单词出现的频率（次数），并能将单词按字典顺序输出");
	printf("\n（3）将单词及频率写入文件");
}
 
//获取英文文本信息及总单词数
void  readfile(char essay[],int total_num,char ch)
 
{
   FILE *fp;
   int i=1;
   fp=fopen("data.txt","r");
   if(!fp)
   {
	   printf("\n打开文件data.txt失败!");
	   exit(0);
   }
   ch=fgetc(fp);//ch为文章第一个字符，判断文章文件是否为空。
   if(ch!=EOF)
   {
     essay[0]=ch;
     for(i;!feof(fp);i++) //如果未遇到读入文本结束符
	 {
          essay[i]=fgetc(fp);//获取文章，将文章中的各个字符放到essay数组中
	 }
     essay[i]='\0';//在读取文章时，并没有将字符串的结束标志读进去，为了后面使用strtok等字符串的相关函数，加上’\0’。
     total_num=i;//记录单词的数量
   }
     if(0==i)
	   printf("\n文件为空，请选择英文文本输入！");
     else
	   printf("\n");
   fclose(fp);
 }
 
 //读新的 
 void  readfilenew(char essay[],int total_num,char ch)
 
{
   FILE *fp;
   int i=1;
   fp=fopen("initial.txt","r");
   if(!fp)
   {
	   printf("\n打开文件data.txt失败!");
	   exit(0);
   }
   ch=fgetc(fp);//ch为文章第一个字符，判断文章文件是否为空。
   if(ch!=EOF)
   {
     essay[0]=ch;
     for(i;!feof(fp);i++) //如果未遇到读入文本结束符
	 {
          essay[i]=fgetc(fp);//获取文章，将文章中的各个字符放到essay数组中
	 }
     essay[i]='\0';//在读取文章时，并没有将字符串的结束标志读进去，为了后面使用strtok等字符串的相关函数，加上’\0’。
     total_num=i;//记录单词的数量
   }
     if(0==i)
	   printf("\n文件为空，请选择英文文本输入！");
     else
	   printf("\n");
   fclose(fp);
 }
 
 
 
 
 
 
 
 
 //写首字母 
 void  writefilenew(char essay[] ,int total_num, char ch)
{
    char essay_str[MAX_NUM];
    FILE *fp;
    char str=' ';
    getchar();
    int i=0;
    fp=fopen("data.txt","w");
    if(!fp)
    {
	   printf("\n打开文件data.txt失败!");
    }
    printf("请输入:");
    gets(essay_str);
    if(ch!=EOF)
    fputc(str,fp);
    fputs(essay_str,fp);//将新增的文章读到文件上
    strcat(essay,essay_str);
    readfile(essay,total_num,ch);
    printf("添加成功");
    printf("\n");
    fclose(fp);
}
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
/*向文件写入英文文本信息*/
void  writefile(char essay[] ,int total_num, char ch)
{
    char essay_str[MAX_NUM];
    FILE *fp;
    char str=' ';
    getchar();
    int i=0;
    fp=fopen("data.txt","w");
    if(!fp)
    {
	   printf("\n打开文件data.txt失败!");
    }
    printf("请输入:");
    gets(essay_str);
    if(ch!=EOF)
    fputc(str,fp);
    fputs(essay_str,fp);//将新增的文章读到文件上
    strcat(essay,essay_str);
    readfile(essay,total_num,ch);
    printf("添加成功");
    printf("\n");
    fclose(fp);
}
 
//显示英文文本 
void show(char essay[],int total_num,char ch)//显示文章
 
{
   if(ch==EOF)
          printf("\n文件为空，请选择英文文本输入！");
   else
          printf("%s",essay);
          printf("\n");
}
 
 
/*按字典顺序进行单词排序*/
void sort(int k)
{
	int num;
	int i,j,t;  //定义局部变量i,j
	char temp[20];  //临时字符数组
	for(i=0;i<k-1;i++)
	{
		for(j=k-1;j>i;j--)
			if((strcmp(word[j].ch,word[j+1].ch)==1)) //比较两个单词，若后一个单词大于前一个，进行调换
			{
             strcpy(temp,word[j].ch);//交换单词
             strcpy(word[j].ch,word[j+1].ch);
             strcpy(word[j+1].ch,temp);
             t=word[j].num;//交换单词频数
             word[j].num=word[j+1].num;
             word[j+1].num=t;
			}
	}
} 
 
 
//统计单词频数
void count(char *essay,char *b)
{
  
int j,i=0;//i记录有多少不同的单词，n记录相同单词出现的次数
 
char *t;
 
bool judge=false;
 
float sum=0;
 
FILE *fp;
 
    for(t=strtok(essay,b);t!=NULL;t=strtok(NULL,b))
 
{
 
//利用strtok函数将文章中的单词分离开。
 
   sum++;//单词总数
 
   strcpy(word[i].ch,t);
 
   (word[i].num)=1;
 
 
   for(j=0;j<i;j++)
 
      if(strcmp(word[i].ch,word[j].ch)==0)
 
  {
 
      (word[j].num)++;
 
      judge=true;
 
  }
 
   if(judge)
 
   i--;
 
   i++;
 
   judge=false;
 
   }
 
   i=i-1;
   sort(i);
   int sum_n=(int)sum;
   printf("单词总数为：%d\n",sum_n);
 
   fp=fopen("count.txt","w");
 
    if(!fp)
 
    {
 
   printf("\n打开文件count.txt失败!");
 
   exit(0);
 
} 
 
   fprintf(fp,"单词总数为：%d\n",sum_n);////将单词总数读到文件中
 
   for(j=0;j<i;j++)
 
   {
 
   fprintf(fp,"%-16s\t%d\t%f\t\n",word[j].ch,word[j].num,(word[j].num/sum));//将单词、单词频数读到文件中
 
   printf("%-16s\t%d\t%f\t\n",word[j].ch,word[j].num,(word[j].num/sum));//将单词、单词频数打印到屏幕上
 
   }
 
    fclose(fp);
 
}
 
 
  //首字母显示 
 void printInitials(const string& name) 
{ 
    
	//char essay_str[MAX_NUM];
    FILE *fp;
    char str=' ';
    //getchar();
    //int i=0;
    fp=fopen("initial.txt","w");
    if(!fp)
    {
	   printf("\n打开文件initial.txt失败!");
    }
    //printf("请输入:");
    //gets(essay_str);
    //if(ch!=EOF)
    //fputc(str,fp);

  //  strcat(essay,essay_str);
   // readfile(essay,total_num,ch);
	
	
	
	
	
	
	if (name.length() == 0) 
        return; 
  
    // Since touuper() returns int, we do typecasting 
    cout << (char)toupper(name[0]); 
  //  char a
 
//	unsigned char a;  
//	a=(char)toupper(name[0]);
    fprintf(fp,"%C ",(char)toupper(name[0]));//将单词、单词频数读到文件中
  //	fputs(char(toupper(name[0])),fp);//将新增的文章读到文件上
    // Traverse rest of the string and print the 
    // characters after spaces. 
    for (int i = 1; i < name.length() - 1; i++) 
        {if (name[i] == ' ') 
            {
			cout << " " << (char)toupper(name[i + 1]);
			
		    fprintf(fp,"%C ",(char)toupper(name[i+1]));//将单词、单词频数读到文件中		    
		//	fputs(char(toupper(name[i + 1])),fp);//将新增的文章读到文件上
		//	fputs(' ',fp);//将新增的文章读到文件上
			} 
			
		} 
	fclose(fp);

//	char ch[20];
//	writefilenew((name) ,(int)name.length(), ch);
} 
 
 
 
 
void menu()
{
    int item,total_num=0;//total_ch记录文章中的总字符数
    char b[20]={',','.','?',':','-',' '},essay[2*MAX_NUM],ch;
    printf("\n");
	printf("              *********************************************************\n");
	printf("              #                                                       #\n");
	printf("              #                 词频统计                              #\n");
	printf("              #                                                       #\n");
	printf("              *********************************************************\n");
	printf("              #                                                       #\n");
	printf("              #           1.显示英文文本                              #\n");
	printf("              #                                                       #\n");
	printf("              #           2.显示单词总数、全部单词及频数              #\n");
	printf("              #                                                       #\n");
	printf("              #           3.帮助                                      #\n");
	printf("              #                                                       #\n");
	printf("              #           4.输入英文文本                              #\n");
	printf("              #                                                       #\n");
	printf("              #           5.退出系统                                  #\n");
	printf("              #                                                       #\n");
	printf("              #           6.首字母显示                                #\n");
	printf("              #                                                       #\n");
	printf("              #           7.首字母统计（按7后count.txt就把2覆盖了）   #\n");
	printf("              *********************************************************\n"); 
    printf("请选择您需要的操作序号(1-7)按回车确认:");
    readfile(essay,total_num,ch);
    scanf("%d",&item);
    printf("\n");
   
    switch(item)
  {
   	  case 1:show(essay,total_num,ch);break;
      case 2:count(essay,b);break;
      case 3:help();break;
      case 4:writefile(essay,total_num,ch);break;
      case 5:select=0;break;
      case 6:printInitials(essay);break; 
      case 7:readfilenew(essay,total_num,ch);count(essay,b);break;
      default:printf("请在1-7之间选择\n");break;
   }
}
 
int main()
{ 
  	while(select)
	{
		menu();
	}
	return 1;
} 


