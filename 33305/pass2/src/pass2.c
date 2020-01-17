/*
 ============================================================================
 Name        : pass2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void) {
	FILE *ipf;
	FILE *opf;
	char wc[10];
	char blankline[] = "---------------------------------------------------";
	int i;

	ipf = fopen("ir.txt","r");
	opf = fopen("output.txt","w");

	while(!feof(ipf))
	{
		fscanf(ipf,"%s",wc);
		printf("%s",wc);

		for(i=0;i<strlen(wc);i++)
		{
			if(strcmp(wc[i],"AD")==0)
					fprintf(opf,"%s\n",blankline);

			else
				fprintf(opf,"%s",wc);
		}

	}
return 0;
}
