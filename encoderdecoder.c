#include <stdio.h>
#include <stdlib.h>

void encodeMessage( char* message) {
    FILE* file = fopen("C:\\encoded_message.txt", "w");
    if (file == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    int i = 0;
    while (message[i] != '\0') {
        fputc(message[i] + 1, file);
        i++;
    }

    fclose(file);
    file =fopen("C:\\encoded_message.txt", "r");
    if (file == NULL) 
    printf("Error in opening file\n");
    else {
        char c;
        printf("your encoded messege is:");
        while ((c = fgetc(file)) != EOF) {
            printf("%c", c);
            }
            fclose(file);
            } 

            }
void decodeMessage() {
    FILE* file = fopen("C:\\encoded_message.txt", "r");
    if (file == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }

    printf("Decoded message: ");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch - 1);
    }
    printf("\n");

    fclose(file);
}

int main() {
    char message[100];
int choice;
    printf("Secret Message Encoder/Decoder\n");
    printf("-----------------------------\n");
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
     do {
        printf("\nChoose an option:\n");
        printf("1. Encode message\n");
        printf("2. Decode message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                encodeMessage(message);
                break;
            case 2:
                decodeMessage();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
    return 0;
}
