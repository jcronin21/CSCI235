#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* unsigned_to_binary(unsigned x) {
    int num_bits = 0;
    unsigned temp = x;
    while (temp > 0) {
        num_bits++;
        temp /= 2;
    }

    if (num_bits == 0) {
        num_bits = 1;
    }

    char* binary_str = (char*)malloc(num_bits + 1);
    if (binary_str == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    for (int i = num_bits - 1; i >= 0; i--) {
        binary_str[i] = (x % 2) ? '1' : '0';
        x /= 2;
    }

    binary_str[num_bits] = '\0';

    return binary_str;
}

unsigned binary_to_unsigned( char* str){
int len = strlen(str);
unsigned num =0;
//    int num = 0;

    for(int i=0; i < len; i++){
      if(str[i] == '1') {

  //   num = num+pow(2,(len-1)-1);
       num += (1 << (len -1-i));
    }
  }

  return num;



}


char* add_binary(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int max_len = (len1 > len2) ? len1 : len2;

    char* result = (char*)malloc(max_len + 2);
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    int carry = 0; // Initialize carry to 0
    int i = len1 - 1; // Start from the least significant bit of str1
    int j = len2 - 1; // Start from the least significant bit of str2;
    int k = 0; // Index for the result string

    while (i >= 0 || j >= 0 || carry > 0) {
        int bit1 = (i >= 0) ? (str1[i] - '0') : 0;
        int bit2 = (j >= 0) ? (str2[j] - '0') : 0;

        int sum = bit1 + bit2 + carry;
        carry = sum / 2;

        result[k++] = (sum % 2) + '0';

        if (i >= 0) i--;
        if (j >= 0) j--;
    }

    result[k] = '\0';

    int start = 0;
    int end = k - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    return result;
}

/*int main() {
    unsigned num1 = 13;
    unsigned num2 = 257;

    char* binary_str1 = unsigned_to_binary(num1);
    char* binary_str2 = unsigned_to_binary(num2);

    if (binary_str1 != NULL && binary_str2 != NULL) {
        printf("Binary representation of %u: %s\n", num1, binary_str1);
        printf("Binary representation of %u: %s\n", num2, binary_str2);

        char* sum = add_binary(binary_str1, binary_str2);

        if (sum != NULL) {
            printf("Binary sum of 13 + 257: %s\n", sum);

            unsigned result = binary_to_unsigned(sum);
//            printf("Decimal representation of binary sum: %u\n", result);

            free(sum);
        }

        free(binary_str1);
        free(binary_str2);
    }

    return 0;
}*/

