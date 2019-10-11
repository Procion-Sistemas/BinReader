/*
*calisto 2019
* this tool can open any binary file 
* and print hexa or char bytes from it
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned int bin=0;
static unsigned int shar=0;
static unsigned int hexa=0;
int main(int argc,char *argv[])
{
	int args(int,char**);
	void help();
	void form(int);
	int byte,view=0,line=0,file_position;
	FILE *file;
	if(argc!=3)
	{
		help();
		exit(1);
	}
	file_position = args(argc,&argv[0]);
	file = fopen(argv[file_position],"rb");
	if(file==NULL)
	{
		printf("cant open the binary file %s\n",argv[2]);
		exit(1);
	}
	if(shar == 1)
	{
		while(1)
		{
			if(view==0)
				printf("|");
			byte = fgetc(file);
			if(byte == -1)
				break;
			if(byte>=32&&byte<=126)
			{
				printf("%c",byte);
			}
			else
			{	
				printf(".");
			}
			view++;
			if(view>=32)
			{	
				printf("|\n");
				view=0;
			}
			line++;
		}
	}
	if(hexa == 1)
	{
		while(1)
		{
			byte = fgetc(file);
			if(byte == -1)
				break;
			form(byte);
			view++;
			if(view>=16)
			{	
				printf("\n");
				view=0;
			}
			line++;
		}
	}
}
int args(int argc, char*argv[])
{
	int cont;
	void help();
	char *arguments[] = {"-b","-x","-c","-h"};
	for(cont=1;cont<argc;cont++)
	{	
		if(strcmp(argv[cont],arguments[0])==0)
		{
			bin = 1;
			if(cont==1)
				return 2;
			return 1;
		}
		else
		if(strcmp(argv[cont],arguments[1])==0)
		{
			hexa = 1;
			if(cont==1)
				return 2;
			return 1;
		}	
		else
		if(strcmp(argv[cont],arguments[2])==0)
		{
			shar = 1;
			if(cont==1)
				return 2;
			return 1;
		}
		else
		if(strcmp(argv[cont],arguments[3])==0)
			help();
	}
}
void help()
{
	int cont;
	char *msgs[] = {"\n\n",
				" [!] It's very simple, please use:\n",
				" [?] BinReader [-c || -b || -x || -h ] binary\n\n",
				"  <-c> read the binary file on ascii-char mode\n",
				"  <-b> read the binary file on bits mode\n",
				"  <-x> read the binary file on hexa mode <coming soon>",
				"\n\n"};
	for(cont=0;cont<7;cont++)
		printf("%s",msgs[cont]);
}
void form(int byte)
{
	if(byte>15)
	{
		printf("%x ",byte);
	}
	else
	{
		printf("0%x ",byte);
	}
}

