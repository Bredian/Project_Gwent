#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
int main(int argc, char * argv[]){
	assert(argc==2);
	printf("Cardparcer launched\n");
	char  name[100];
	char  text[20];
	int value;
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
		fprintf(code,"card %s;\n",name);
		printf("Card name written\n");
		fscanf(library,"%s",text);
		printf("Card identy read\n");
		if(strcmp(text,"leader")==0)
			fprintf(code,"%s.leadership=1;\n%s.speciality=0;\n%s.unit=0;\n",name,name,name);
		if(strcmp(text,"special")==0)
			fprintf(code,"%s.leadership=0;\n%s.speciality=1;\n%s.unit=0;\n",name,name,name);
		if(strcmp(text,"unit")==0)
			fprintf(code,"%s.leadership=0;\n%s.speciality=0;\n%s.unit=1;\n",name,name,name);
		printf("Card identity written\n");
		fscanf(library,"%d",&value);
		printf("Card skill read\n");
        	if(strcmp(text,"leader")==0)
			fprintf(code,"%s.leader_skill=%d;\n%s.special_skill=0;\n%s.unit_skill=0;\n",name,value,name,name);
		if(strcmp(text,"special")==0)
			fprintf(code,"%s.leader_skill=0;\n%s.special_skill=%d;\n%s.unit_skill=0;\n",name,name,value,name);
		if(strcmp(text,"unit")==0)
			fprintf(code,"%s.leader_skill=0;\n%s.special_skill=0;\n%s.unit_skill=%d;\n",name,name,name,value);
		printf("Card skill written\n");
		fscanf(library,"%d",&value);
		printf("Card heroism read\n");
		fprintf(code,"%s.heroic=%d;\n",name,value);
		printf("Card heroism written\n");
		fscanf(library,"%d",&value);
		printf("Card strength read\n");
		fprintf(code,"%s.strength=%d;\n",name,value);
		printf("Card strength written\n");
		fscanf(library,"%d",&value);
		printf("Card row read\n");
		fprintf(code,"%s.row=%d;\n",name,value);
		printf("Card row written\n");
		fscanf(library,"%d",&value);
		printf("Card faction read\n");
		fprintf(code,"%s.faction=%d;\n",name,value);
		printf("Card faction written\n");
		fscanf(library,"%s",text);
		printf("Card type read\n");
		fprintf(code,"%s.type=\"%s\";\n",name,text);
		printf("Card type written\n");
	}
	return 0;
}
