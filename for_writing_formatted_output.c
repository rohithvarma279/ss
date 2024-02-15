#include <stdio.h>
#include <string.h>

int main() {
    FILE *inputFile = fopen("output.txt", "r");
    FILE *outputFile = fopen("formatted_output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    char line[100]; // Assuming lines are not longer than 100 characters

    while (fgets(line, sizeof(line), inputFile)) {
        // Split the line into fields
        char *fields[4];
        int fieldCount = 0;
        char *token = strtok(line, "\t");

        while (token != NULL && fieldCount < 4) {
            fields[fieldCount] = token;
            token = strtok(NULL, "\t");
            fieldCount++;
        }

        // Format and write the fields to the output file
        for (int i = 0; i < fieldCount; i++) {
            fprintf(outputFile, "%-10s", fields[i]);
        }

        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
