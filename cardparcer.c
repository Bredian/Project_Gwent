#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int main(int argc, char * argv[]){
	assert(argc==2);
	printf("Cardparcer launched\n");
	char  name[100];
	char  text[20];
	int kek,value[3],skill[3],heroic,strength,row,faction;
	FILE * library;
	FILE * code;
	library = fopen(argv[1],"r");
	printf("Card library found\n");
	assert(library!=NULL);
	code = fopen("library.h","w");
	printf("Code file created\n");
	assert(code!=NULL);
	while(!feof(library)){
		printf("Initialising card...\n");
		fscanf(library,"%s",name);
		printf("Card name read\n");
		printf("Card name written\n");
		fscanf(library,"%s",text);
		printf("Card identy read\n");
		if(strcmp(text,"leader")==0)
			value[0]=1;
            value[1]=0;
            value[2]=0;
		if(strcmp(text,"special")==0)
			value[0]=0;
            value[1]=1;
            value[2]=0;
		if(strcmp(text,"unit")==0)
			value[0]=0;
            value[1]=0;
            value[2]=1;
		printf("Card identity written\n");
		fscanf(library,"%d",&kek);
		printf("Card skill read\n");
        	if(strcmp(text,"leader")==0)
			skill[0]=kek;
            skill[1]=0;
            skill[2]=0;
		if(strcmp(text,"special")==0)
			skill[0]=0;
            skill[1]=kek;
            skill[2]=0;
		if(strcmp(text,"unit")==0)
			skill[0]=0;
            skill[1]=0;
            skill[2]=kek;
		printf("Card skill written\n");
		fscanf(library,"%d",&heroic);
		printf("Card heroism read\n");
		printf("Card heroism written\n");
		fscanf(library,"%d",&strength);
		printf("Card strength read\n");
		printf("Card strength written\n");
		fscanf(library,"%d",&row);
		printf("Card row read\n");
		printf("Card row written\n");
		fscanf(library,"%d",&faction);
		printf("Card faction read\n");
		printf("Card faction written\n");
		fscanf(library,"%s",text);
		printf("Card type read\n");
		printf("Card type written\n");
        fprintf(code,"volatile card %s={%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,\"%s\"};\n",name,value[0],value[1],value[2],skill[0],skill[1],skill[2],heroic,strength,row,faction,text);
	}
	return 0;
}
