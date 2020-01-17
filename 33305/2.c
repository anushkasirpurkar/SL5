#include<stdio.h>
#include<string.h>
char mot[6][6]={"STOP","ADD","SUB","MUL","MOVER","MOVEM"}; //mnemonics
char r[4][6]={"AREG","BREG","CREG","DREG"}; //registers

struct l
{ char name; //name of literal
int add; //address ofliteral
} lit[20];

struct s
{ char name[20]; // name of symbol
int add; //address of symbol
} sy[20];

int main()

{

char wc[10];
int lc,n1=0,ns=0,i,j=0,k=0,litflag=0,m=0,tempb,flag=0;
FILE *fip,*fir;
fip=fopen("input.asm","r"); //assembler input
fir=fopen("ir.txt","w"); //Intermediate Representation
fscanf(fip,"%s",wc); //read input
while(!feof(fip))
{
up:if(!strcmp(wc,"START")) //if start copy address(lc)
{
fscanf(fip,"%d",&lc);
fprintf(fir,"(%s,%d)(%s,%d)\t LC\n","AD",1,"C",lc);
}
fscanf(fip,"%s",wc); //read next
//check if it is present in mnemonics table
for(i=0;i<6;i++)
{
if(!strcmp(wc,mot[i]))
{
fprintf(fir,"(%s,%d)","IS",i+1); //found in mot
fscanf(fip,"%s",wc);
for(j=0;j<4;j++) //now find register
if(!strcmp(wc,r[j]))
fprintf(fir,"(%d)",j+1);
fscanf(fip,"%s",wc);
if(!strcmp(wc,"=")) //if = means literal
{
k=2;
fscanf(fip,"%s",wc);
//check if said literal already present in literlar table
for(j=0;j<n1;j++)
{
if(lit[j].name==wc[k]) //if(!strcmp(lit[j].name,wc[k]))
{
litflag=1;
fprintf(fir,"(%s,%d)\t %d","L",j,lc);
}
} //else add new entry in Literal table
if(litflag==0)
{
lit[n1].name=wc[k];
fprintf(fir,"(%s,%d)\t %d","L",n1,lc);
n1++;
}

break;
}
else //if it’s not literal it must be symbol
{
for(j=0;j<ns;j++)
{
//check if said symbol is present in symbol table
if(!strcmp(sy[j].name,wc))
{
flag=1;
fprintf(fir,"(%s,%d)\t %d\n","S",j,lc);
lc++;
goto up;
}
} //else add new entry in symbol table
if(flag==0)
{
strcpy(sy[ns].name,wc);
fprintf(fir,"(%s,%d)\t %d","S",ns,lc);
ns++;
break;
}
}
}
//if it’s not there in mot then check for symbol definition [DC/DS]
for(m=0;m<ns;m++)
{
if(!strcmp(wc,sy[m].name))
{
fscanf(fip,"%s",wc);
if(!strcmp(wc,"DS"))
{
fscanf(fip,"%d",&tempb);
fprintf(fir,"(%s,%d)(%d)\t %d\n","DL",2,tempb,lc);
sy[m].add=lc;
lc+=tempb;
goto up;
}
else if(!strcmp(wc,"DC"))
{
fscanf(fip,"%d",&tempb);
fprintf(fir,"(%s,%d)(%d)\t %d\n","DL",1,tempb,lc);
sy[m].add=lc;
lc++;
goto up;
}
}
}
}
//check for END of assembly statements
if(!strcmp(wc,"END"))
{
fprintf(fir,"(%s,%d)\n","AD",2);
for(i=0;i<n1;i++)
{
fprintf(fir,"(%s,%d)(%s,%c)\t %d\n","DL",1,"C",lit[i].name,lc);
lit[i].add=lc;
lc++;
}
break;
}
lc++;
fprintf(fir,"\n");
}
//print databases

printf("\n DATABASE:-");
printf("\n\n1] SYMBOL TABLE:\n——————–\nSYMBOL\tSYMBOL\tADDRESS");
for(i=0;i<ns;i++)
printf("\n %d\t %s\t%d",i,sy[i].name,sy[i].add);
printf("\n\n2] LITERAL TABLE:\n——————–\nLITERAL\tLITERAL\tADDRESS");
for(i=0;i<n1;i++)
printf("\n %d\t %c\t%d",i,lit[i].name,lit[i].add);
printf("\n");
fclose(fir); //close files opened
fclose(fip);
return 0;

}
