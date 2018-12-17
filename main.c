#include <stdio.h>

void bundleFiles(FILE* file1, FILE* file2);

int main() {
    printf("Welcome to the bundler. "
           "You must supply the names of two JavaScript files that you would like to be bundled."
           "\nPlease enter the name of the first file\n");
    char file1Name[50];
    scanf("%49s", &file1Name);
    FILE* file1 = fopen(file1Name, "r");
    if (file1 != NULL){
        printf("Please enter the name of the second file\n");
        char file2Name[50];
        scanf("%49s", &file2Name);
        FILE* file2 = fopen(file2Name, "r");
        if (file2 != NULL){
            printf("The bundler will be starting\n");
            bundleFiles(file1, file2);
        }else{
            printf("The second file was not found. The program will be terminated.");
        }
    } else{
        printf("The first file was not found. The program will be terminated.");
    }
    return 0;
}

void bundleFiles(FILE* file1, FILE* file2){
    FILE* bundledFile = fopen("bundle.js", "w");
    char buffer[1024];
    int file1Size = 0, file2Size = 0, bundledSize = 0;

    //checks for end of file and writes from file 1 to the bundled file
    while (fscanf(file1, "%s[\n]", buffer) == 1){
        fprintf(bundledFile, "%s ", buffer);
    }
    //checks for end of file and writes from file 2 to the bundled file
    while (fscanf(file2, "%s[\n]", buffer) == 1){
        fprintf(bundledFile, "%s ", buffer);
    }

    //gets size of files by setting the pointer to the end and then calling for the position
    fseek(file1, 0, SEEK_END);
    file1Size = ftell(file1);
    fseek(file2, 0, SEEK_END);
    file2Size = ftell(file2);
    fseek(bundledFile, 0, SEEK_END);
    bundledSize = ftell(bundledFile);
    
    printf("The bundler has finished.\n"
           "Size of File 1: %d bytes\n"
           "Size of File 2: %d bytes\n"
           "Size of bundled file: %d bytes", file1Size, file2Size, bundledSize);
    fclose(file1);
    fclose(file2);
    fclose(bundledFile);
}