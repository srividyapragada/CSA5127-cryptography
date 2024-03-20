#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], char key[]) {
    int i, j;
    char encrypted_text[strlen(text)];
    int key_length = strlen(key);
    
    for (i = 0; i < strlen(text); i++) {
        char current_key = key[i % key_length]; 
        
        if (isalpha(text[i])) {
            char base;
            if (islower(text[i]))
                base = 'a';
            else
                base = 'A';
            
            encrypted_text[i] = (text[i] - base + current_key - 'a') % 26 + base;
        } else {
            encrypted_text[i] = text[i]; 
        }
    }
    encrypted_text[i] = '\0';

    printf("Encrypted text: %s", encrypted_text);
}

int main() {
    char text[100];
    char key[100];

    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    text[strcspn(text, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    encrypt(text, key);
    
    return 0;
}
