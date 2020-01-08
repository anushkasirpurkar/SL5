#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct table
	{
		char mnemonic[6];
		char type[3];
		int opcode;
	};

struct table MOT[25]={{"STOP","IS",00},{"ADD","IS",01},{"SUB","IS",02},{"MULT","IS",03},{"MOVER","IS",04},{"MOVEM","IS",05},			{"COMP","IS",06},{"BC","IS",07},{"DIV","IS",8},{"READ","IS",9},{"PRINT","IS",10},{"START","AD",01},{"END","AD",02},{"ORIGIN","AD",03},{"EQU","AD",04},{"LTORG","AD",05},{"DS","DL",01},{"DC","DL",02}};

struct table ROT[5]={{"AREG","RG",01},{"BREG","RG",02},{"CREG","RG",03},{"DREG","RG",04}};
	
void main()
{
	

	FILE *f;
	char l[5],mne[5],reg[5],con[5];
	int i,j;
	
	f=fopen("input.asm","r");
    	
	if(f==NULL) 
		{
	        printf("Error! opening file");
       		exit(1);
    	}
    	
	while(!feof(f))
		{
			fscanf(f,"%s %s %s %s\n",l,mne,reg,con);
				
			if(strcmp(l,"-")==0||strcmp(reg,"-")==0)
				printf("- ");
			
    		for(j=0;j<25;j++)
				{
					if(strcmp(mne,MOT[j].mnemonic)==0)
					printf("(%s, %d) ",MOT[j].type,MOT[j].opcode);	
				}
			
			for(j=0;j<5;j++)
				{
					if(strcmp(reg,ROT[j].mnemonic)==0)
					printf("(%s, %d) ",ROT[j].type,ROT[j].opcode);	
				}
				
			
						
			if(strcmp(con,"-")==0)
				printf("- \n");
			else				
				printf("%s \n",con);
	}
    	fclose(f);
		
}
