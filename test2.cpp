/*
File name:��Ƶͳ��.cpp
Author:����
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

struct Word      //���ʽṹ��
{
int  num;//����Ƶ��
char ch[20];//ÿһ������
} word[MAX_NUM];
int select=1;//select Ϊ�Ƿ��˳�ϵͳ�ı��
 
//���û��ṩ����˵��
void help()
{
    printf("\n��1���ɵ�������Ӣ���ı��ļ�");
	printf("\n��2��ͳ�Ƹ�Ӣ���ļ��е������͸����ʳ��ֵ�Ƶ�ʣ������������ܽ����ʰ��ֵ�˳�����");
	printf("\n��3�������ʼ�Ƶ��д���ļ�");
}
 
//��ȡӢ���ı���Ϣ���ܵ�����
void  readfile(char essay[],int total_num,char ch)
 
{
   FILE *fp;
   int i=1;
   fp=fopen("data.txt","r");
   if(!fp)
   {
	   printf("\n���ļ�data.txtʧ��!");
	   exit(0);
   }
   ch=fgetc(fp);//chΪ���µ�һ���ַ����ж������ļ��Ƿ�Ϊ�ա�
   if(ch!=EOF)
   {
     essay[0]=ch;
     for(i;!feof(fp);i++) //���δ���������ı�������
	 {
          essay[i]=fgetc(fp);//��ȡ���£��������еĸ����ַ��ŵ�essay������
	 }
     essay[i]='\0';//�ڶ�ȡ����ʱ����û�н��ַ����Ľ�����־����ȥ��Ϊ�˺���ʹ��strtok���ַ�������غ��������ϡ�\0����
     total_num=i;//��¼���ʵ�����
   }
     if(0==i)
	   printf("\n�ļ�Ϊ�գ���ѡ��Ӣ���ı����룡");
     else
	   printf("\n");
   fclose(fp);
 }
 
 //���µ� 
 void  readfilenew(char essay[],int total_num,char ch)
 
{
   FILE *fp;
   int i=1;
   fp=fopen("initial.txt","r");
   if(!fp)
   {
	   printf("\n���ļ�data.txtʧ��!");
	   exit(0);
   }
   ch=fgetc(fp);//chΪ���µ�һ���ַ����ж������ļ��Ƿ�Ϊ�ա�
   if(ch!=EOF)
   {
     essay[0]=ch;
     for(i;!feof(fp);i++) //���δ���������ı�������
	 {
          essay[i]=fgetc(fp);//��ȡ���£��������еĸ����ַ��ŵ�essay������
	 }
     essay[i]='\0';//�ڶ�ȡ����ʱ����û�н��ַ����Ľ�����־����ȥ��Ϊ�˺���ʹ��strtok���ַ�������غ��������ϡ�\0����
     total_num=i;//��¼���ʵ�����
   }
     if(0==i)
	   printf("\n�ļ�Ϊ�գ���ѡ��Ӣ���ı����룡");
     else
	   printf("\n");
   fclose(fp);
 }
 
 
 
 
 
 
 
 
 //д����ĸ 
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
	   printf("\n���ļ�data.txtʧ��!");
    }
    printf("������:");
    gets(essay_str);
    if(ch!=EOF)
    fputc(str,fp);
    fputs(essay_str,fp);//�����������¶����ļ���
    strcat(essay,essay_str);
    readfile(essay,total_num,ch);
    printf("��ӳɹ�");
    printf("\n");
    fclose(fp);
}
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
/*���ļ�д��Ӣ���ı���Ϣ*/
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
	   printf("\n���ļ�data.txtʧ��!");
    }
    printf("������:");
    gets(essay_str);
    if(ch!=EOF)
    fputc(str,fp);
    fputs(essay_str,fp);//�����������¶����ļ���
    strcat(essay,essay_str);
    readfile(essay,total_num,ch);
    printf("��ӳɹ�");
    printf("\n");
    fclose(fp);
}
 
//��ʾӢ���ı� 
void show(char essay[],int total_num,char ch)//��ʾ����
 
{
   if(ch==EOF)
          printf("\n�ļ�Ϊ�գ���ѡ��Ӣ���ı����룡");
   else
          printf("%s",essay);
          printf("\n");
}
 
 
/*���ֵ�˳����е�������*/
void sort(int k)
{
	int num;
	int i,j,t;  //����ֲ�����i,j
	char temp[20];  //��ʱ�ַ�����
	for(i=0;i<k-1;i++)
	{
		for(j=k-1;j>i;j--)
			if((strcmp(word[j].ch,word[j+1].ch)==1)) //�Ƚ��������ʣ�����һ�����ʴ���ǰһ�������е���
			{
             strcpy(temp,word[j].ch);//��������
             strcpy(word[j].ch,word[j+1].ch);
             strcpy(word[j+1].ch,temp);
             t=word[j].num;//��������Ƶ��
             word[j].num=word[j+1].num;
             word[j+1].num=t;
			}
	}
} 
 
 
//ͳ�Ƶ���Ƶ��
void count(char *essay,char *b)
{
  
int j,i=0;//i��¼�ж��ٲ�ͬ�ĵ��ʣ�n��¼��ͬ���ʳ��ֵĴ���
 
char *t;
 
bool judge=false;
 
float sum=0;
 
FILE *fp;
 
    for(t=strtok(essay,b);t!=NULL;t=strtok(NULL,b))
 
{
 
//����strtok�����������еĵ��ʷ��뿪��
 
   sum++;//��������
 
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
   printf("��������Ϊ��%d\n",sum_n);
 
   fp=fopen("count.txt","w");
 
    if(!fp)
 
    {
 
   printf("\n���ļ�count.txtʧ��!");
 
   exit(0);
 
} 
 
   fprintf(fp,"��������Ϊ��%d\n",sum_n);////���������������ļ���
 
   for(j=0;j<i;j++)
 
   {
 
   fprintf(fp,"%-16s\t%d\t%f\t\n",word[j].ch,word[j].num,(word[j].num/sum));//�����ʡ�����Ƶ�������ļ���
 
   printf("%-16s\t%d\t%f\t\n",word[j].ch,word[j].num,(word[j].num/sum));//�����ʡ�����Ƶ����ӡ����Ļ��
 
   }
 
    fclose(fp);
 
}
 
 
  //����ĸ��ʾ 
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
	   printf("\n���ļ�initial.txtʧ��!");
    }
    //printf("������:");
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
    fprintf(fp,"%C ",(char)toupper(name[0]));//�����ʡ�����Ƶ�������ļ���
  //	fputs(char(toupper(name[0])),fp);//�����������¶����ļ���
    // Traverse rest of the string and print the 
    // characters after spaces. 
    for (int i = 1; i < name.length() - 1; i++) 
        {if (name[i] == ' ') 
            {
			cout << " " << (char)toupper(name[i + 1]);
			
		    fprintf(fp,"%C ",(char)toupper(name[i+1]));//�����ʡ�����Ƶ�������ļ���		    
		//	fputs(char(toupper(name[i + 1])),fp);//�����������¶����ļ���
		//	fputs(' ',fp);//�����������¶����ļ���
			} 
			
		} 
	fclose(fp);

//	char ch[20];
//	writefilenew((name) ,(int)name.length(), ch);
} 
 
 
 
 
void menu()
{
    int item,total_num=0;//total_ch��¼�����е����ַ���
    char b[20]={',','.','?',':','-',' '},essay[2*MAX_NUM],ch;
    printf("\n");
	printf("              *********************************************************\n");
	printf("              #                                                       #\n");
	printf("              #                 ��Ƶͳ��                              #\n");
	printf("              #                                                       #\n");
	printf("              *********************************************************\n");
	printf("              #                                                       #\n");
	printf("              #           1.��ʾӢ���ı�                              #\n");
	printf("              #                                                       #\n");
	printf("              #           2.��ʾ����������ȫ�����ʼ�Ƶ��              #\n");
	printf("              #                                                       #\n");
	printf("              #           3.����                                      #\n");
	printf("              #                                                       #\n");
	printf("              #           4.����Ӣ���ı�                              #\n");
	printf("              #                                                       #\n");
	printf("              #           5.�˳�ϵͳ                                  #\n");
	printf("              #                                                       #\n");
	printf("              #           6.����ĸ��ʾ                                #\n");
	printf("              #                                                       #\n");
	printf("              #           7.����ĸͳ�ƣ���7��count.txt�Ͱ�2�����ˣ�   #\n");
	printf("              *********************************************************\n"); 
    printf("��ѡ������Ҫ�Ĳ������(1-7)���س�ȷ��:");
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
      default:printf("����1-7֮��ѡ��\n");break;
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


