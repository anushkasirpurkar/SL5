#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mnemonic
{
	char name[10];
	char type[5];
	int code;
};

struct mnemonic mnemo[18] = {{"START","AD",01},{"END","AD",02},{"ORIGIN","AD",03},{"EQU","AD",04},{"LTORG","AD",05},{"STOP","IS",00},{"ADD","IS",01},{"SUB","IS",02},{"MULT","IS",03},{"MOVER","IS",04},{"MOVEM","IS",05},{"COMP","IS",06},{"BC","IS",07},{"DIV","IS",8},{"READ","IS",9},{"PRINT","IS",10},{"DC","DL",01},{"DS","DL",0}};



int main()
{
	FILE *ipf;
	FILE *opf;
	FILE *symf;
	FILE *litf;
	FILE *poolf;

	char label[10],mne[10],op1[10],op2[10];
	char start[] = "START";
	char end = "END";
	char dash[] = "-";
	char constant[] = "C";
	char symbol[] = "S";

	struct mnemonic mnemo[20];

	int lc=0;

	ipf = fopen("input.txt","r");
	opf = fopen("output.txt","w");

	while(!feof(ipf))
	{
		fscanf(ipf,"%s %s %s %s",label,mne,op1,op2);

			if(strcmp(mne,start)==0)
			{
				if(strcmp(op2,dash)!=0)
				{
					lc = atoi(op2);
					fprintf(opf,"(%s %d) (%s %d) \n",mnemo[0].type , mnemo[0].code  ,constant ,lc);
				}

				else
					printf("Invalid operand 2\n");


			}

			else
			{


				while(strcmp(mne,end)!=0)
				{
					if(strcmp(label,dash)!=0)
					{
						//add it into symbol table
					}

					fprintf(opf,"(%s %d) (%s %d) %d\n",mnemo[0].type , mnemo[0].code  ,constant ,lc, lc);
					lc = lc + 1;

				}
			}

	}


	return 0;
}
