#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CharCount(FILE *fp){
	int charcount=0;
	char ch;
	ch=fgetc(fp);
	while(!feof(fp)){
		charcount++;
		ch=fgetc(fp);
	}
	printf("字符数:%d\n",charcount);
	rewind(fp);
}

void WordCount(FILE *fp){
	int wordcount=0;
	char ch;
	ch=fgetc(fp);
	while(!feof(fp)){
		 if(isalnum(ch)||ch==95)
         {
             //而且后续字符也是字母数字或者下划线
             while(isalnum(ch)||ch==95)
             {
                 ch=fgetc(fp);
             }
             //单词数量增加1
             wordcount++;
         }
         
         ch=fgetc(fp);
     }
     printf("单词数:%d\n",wordcount);
     rewind(fp);
}

int main(int argc,char* argv[])
{
   FILE *fp;
 
               fp=fopen(argv[2],"r");
               if(fp==NULL)
              {
                  printf("不能打开文件");
                  
              }
              if(strcmp(argv[1],"-c")==0)
              {
                  CharCount(fp);
              }
              else if(strcmp(argv[1],"-w")==0)
              {
                  WordCount(fp);
              }

}


