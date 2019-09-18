#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static unsigned int bin=0;
static unsigned int shar=0;
static unsigned int hexa=0;
int main(int argc,char *argv[])
{
	void args(int,char**);
	void help();
	void form(int);
	int byte,view=0,line=0;;
	FILE *file;
	if(argc!=3)
	{
		help();
		exit(1);
	}
	file = fopen(argv[1],"rb");
	args(argc,&argv[0]);
	if(shar == 1)
	{
		while(1)
		{
			if(view==0)
				printf("|",line);
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
void args(int argc, char*argv[])
{
	int cont;
	char *arguments[] = {"-b","-x","-c"};
	for(cont=0;cont<argc;cont++)
	{	
		if(strcmp(argv[cont],arguments[0])==0)
		{
			bin = 1;
		}
		else
		if(strcmp(argv[cont],arguments[1])==0)
		{
			hexa = 1;
		}	
		else
		if(strcmp(argv[cont],arguments[2])==0)
		{
			shar = 1;
		}
	}
}
void help()
{
	int cont;
	char *msgs[] = {"\n\n",
				" [!] It's very simple, please use:\n",
				" [?] BinReader binary [-c || -b || -x ]\n\n",
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
	if(byte<=15)
	{
		printf("%x  ",byte);
	}
}
