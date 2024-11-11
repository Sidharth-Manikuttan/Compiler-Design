#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void main() {
FILE *input = fopen("input.txt", "r");
char buffer[100], ch, c;
int n = 0, i;
if (input == NULL) {
printf("Error opening file.\n");
exit(1);
}
printf("File Content : \n");
while ((ch = fgetc(input)) != EOF) {
printf("%c", ch);
}
fclose(input);
printf("\n");
input = fopen("input.txt", "r");
if (input == NULL) {
printf("Error reopening file.\n");
exit(1);
}
printf("Output of lexical analyzer is : \n");
while ((c = fgetc(input)) != EOF) {
if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '=' || c == ';' || c == ',' || c == ' ' || c == '>') {
if (strncmp("int", buffer, 3) == 0 || strncmp("float", buffer, 5) == 0 || strncmp("if", buffer, 2) == 0 ||
strncmp("else", buffer, 4) == 0 || strncmp("printf", buffer, 6) == 0) {
printf("%s is a keyword\n", buffer);
} else {
printf("%s is a identifier\n", buffer);
}
for (i = 0; i < 10; i++) {
buffer[i] = '\0';
}
n = 0;
if (c != ' ') {
printf("%c is an operator\n", c);
}
} else if (isalnum(c)||c=='_') {
buffer[n++] = c;
buffer[n] = '\0';
}
}
if (buffer[0] != '\0') {
printf("%s is a identifier\n", buffer);
}
fclose(input);
}
