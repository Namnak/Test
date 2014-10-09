

#include <stdio.h>

//GLOBAL VAR
char output[1000];

int write_file(char *file_name){

	FILE *ptr_file;
		int x;
	ptr_file =fopen(file_name, "w");

		if (!ptr_file)
			return 1;

		for (x=1; x<=10; x++)
			fprintf(ptr_file,"%d\n", x);

	fclose(ptr_file);

	return  0;
}

int count_file_line(char *file_name, int print){

	FILE *ptr_file;

   	char buf[1000];
	int count = 0;

	ptr_file =fopen(file_name,"r");

	while (fgets(buf,1000, ptr_file)!=NULL){
		count++;
	}

	if(print == 1){
		printf("count_file_line_function: %ld \n", count);
	}
    	
	fclose(ptr_file); 	
    return count;
}

char *read_file(char *file_name, int line){

	FILE *ptr_file;

   	char buf[1000];
   	//char output[1000]; Weg finden nicht als globale, sonden in Funktion.
    int i = 0;

    ptr_file =fopen(file_name,"r");

    // Wichtig! sicher heits Abfrage wenn Date nicht existent
    //if (!ptr_file)
    //  		return 1; 


    if(count_file_line(file_name, 0) >= line){

    	for(i = 0; i < line; i++){

			if(i == line-1){
	    		fgets(output, 1000, ptr_file);
	    	}
	    	else{
	    		fgets(buf, 1000, ptr_file);
	    	}
	    }
	}
	else{
		printf("ERRO: line not in file!");
	}
	    
	fclose(ptr_file); 		

	return  output;
}

int main(int argc, char *argv[])
{
    printf("Programm start... \n\n");

 /*
    for(i = 0; i < num; i++) {
    	printf("ary: %ld \n", ary[i]);
    }
*/
    //write_file("output.txt");
    int k;
    for(k= 0; k < count_file_line("input.txt", 0); k++)
    	printf("%s",read_file("input.txt", k));
	    
    return 0;

}