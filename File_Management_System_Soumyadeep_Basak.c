#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void createFile(FILE *file) {
    if (file == NULL) {
    printf("Unable to create the file.\n");
        
    }
    printf("File created successfully.\n");
}





void writeFile(FILE *file) {
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    char content[100];
    printf("Enter content to write: ");
    //fgets(content, sizeof(content), stdin);
    //gets(content);
    scanf("%s",&content);
    fprintf(file, "%s", content);
    printf("Content written successfully.\n");
}


void readFile(FILE *file) {
    char ch;
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    printf("\nFile content:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    printf("\n");
    
}




void deleteFile(char fname[]) {
	if (remove(fname) == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Unable to delete the file.\n");
    }}
    
    
    
    
void renameFile(char fname[]){
	printf("Enter the new filename: ");
	char filename[50];
    scanf("%s", filename);
    if (rename(fname, filename) == 0)
    printf("File renamed successfully!\n");
    else
    printf("Error: Failed to rename file.\n");
}
    
    
    
void modifyFile(FILE *file,char fname[]) {
	char  tempFilename[100], line[1000], findStr[100], replaceStr[100];
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        exit(1);
    }
    printf("Enter the string to find: ");
    scanf("%s", findStr);
    printf("Enter the string to replace with: ");
    scanf("%s", replaceStr);
    sprintf(tempFilename, "temp_%s", fname);
    FILE *tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("Error: Unable to create the temporary file.\n");
        fclose(file);
        exit(1);
    }
    while (fgets(line, sizeof(line), file)) {
        char *pos = strstr(line, findStr);
        while (pos != NULL) {
            strncpy(pos, replaceStr, strlen(replaceStr));
            pos = strstr(pos + strlen(replaceStr), findStr);
        }
        fputs(line, tempFile);
    }
    fclose(file);
    fclose(tempFile);
    if (remove(fname) != 0) {
        printf("Error: Unable to remove the original file.\n");
        exit(1);
    }
    if (rename(tempFilename, fname) != 0) {
        printf("Error: Unable to rename the temporary file.\n");
        exit(1);
    }
    printf("File modified successfully.\n");
}    




int main(){
	char fname[100];
	printf("FILE MANAGEMENT SYSTEM\nBy Soumyadeep Basak");
	printf("Enter name of file you want to operate on:\n(NOTE:Please add .txt after the name of file)\n");
	scanf("%s",&fname);
	int choice;
    do{
    	printf("Menu:\n");
        printf("1. Create a file\n");
        printf("2. Read a file\n");
        printf("3. Write to a file\n");
        printf("4. Append to a file\n");
        printf("5. Delete a file\n");
        printf("6. Modify a file\n");
        printf("7. Rename a file\n");
        printf("0. Exit\n");
		printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        	case 1:
        		{
				FILE *file1 = fopen(fname, "w");
                createFile(file1);
                fclose(file1);
                break;}
            case 2:
        		{
				FILE *file1 = fopen(fname, "r");
                readFile(file1);
                fclose(file1);
                break;}
            case 3:
                {
				FILE *file3 = fopen(fname, "w");
				writeFile(file3);
				fclose(file3);
                break;}
            case 4:
                {
				FILE *file3 = fopen(fname, "a");
				writeFile(file3);
				fclose(file3);
                break;}
            case 5:
			{
				deleteFile(fname);
				break;}
			case 6:
				{
					FILE *file3 = fopen(fname, "r+");
					modifyFile(file3,fname);
					fclose(file3);
				}
			case 7:{
        		 renameFile(fname);
        		 break;
			}
            case 0:
            	{break;}
		}
	}
	while(choice!=0);
}