#include <stdio.h>
#include <string.h>
void cbcEncryptWithErrorPropagation(const char *plaintext, char *ciphertext, size_t blockCount) {
    char iv[16] = {0}; 
    for (size_t i = 0; i < blockCount; ++i) {
        
        for (int j = 0; j < 16; ++j) {
            ciphertext[i * 16 + j] = plaintext[i * 16 + j] ^ iv[j];
        }

        memcpy(iv, ciphertext + i * 16, 16);
    }
}

int main() {
    const char plaintext[] = "This is a sample plaintext block with an error in the first block.";
    const size_t blockCount = strlen(plaintext) / 16 + 1; 
    char ciphertext[256]; 
   
    cbcEncryptWithErrorPropagation(plaintext, ciphertext, blockCount);
   
    printf("Ciphertext:\n");
    for (size_t i = 0; i < blockCount; ++i) {
        for (int j = 0; j < 16; ++j) {
            printf("%02X", (unsigned char)ciphertext[i * 16 + j]);
        }
        printf(" ");
    }
    printf("\n");
    
    return 0;
}
