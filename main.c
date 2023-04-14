#include <stdio.h>
#define INT_BITS 32
#define BASE64_LOWER_A 26
#define BASE64_ZERO 52
#define BASE64_PLUS 62
#define BASE64_SLASH 63
int main() {
    int is_zero = 0;
    do {
        char input;
        printf("Choose an option:\n"
               "0. Exit\n"
               "1. Hourglass\n"
               "2. Reverse bits\n"
               "3. Reverse digits\n"
               "4. Convert to Decimal\n"
               "5. Base64 to Decimal\n"
               "6. Swap bits\n");
        scanf(" %c", &input);
        switch (input) {
            case '0':
                is_zero = 1;
                break;
            case '1': {
                // Get size
                int size;
                printf("Enter size:\n");
                scanf(" %d", &size);
                char upper, lower;
                {
                    // Get flag
                    int flag;
                    printf("Enter flag:\n");
                    scanf(" %d", &flag);
                    // Check parameters validity
                    if (size < 3 || (flag != 0 && flag != 1)) {
                        printf("Invalid Parameters\n");
                        break;
                    }
                    // Set upper and lower characters
                    upper = flag ? '.' : ' ';
                    lower = '.' + ' ' - upper;
                }
                // Print hourglass
                // Print first line
                for (int i = 0; i < size; ++i) {
                    printf("-");
                }
                printf("\n");
                // Print upper half
                for (int i = 0; i < size / 2; ++i) {
                    // Print indentation
                    for (int j = 0; j < i; ++j) {
                        printf(" ");
                    }
                    printf("\\");
                    // Print upper character
                    for (int j = 0; j < size - 2 * i - 2; ++j) {
                        printf("%c", upper);
                    }
                    printf("/\n");
                }
                // Handle odd size
                if (size % 2 == 1) {
                    // Print indentation
                    for (int i = 0; i < size / 2; ++i) {
                        printf(" ");
                    }
                    printf("X\n");
                }
                // Print lower half
                for (int i = 0; i < size / 2; ++i) {
                    // Print indentation
                    for (int j = 0; j < size / 2 - i - 1; ++j) {
                        printf(" ");
                    }
                    printf("/");
                    // Print lower character
                    for (int j = 0; j < size - 2 * (size / 2 - i - 1) - 2; ++j) {
                        printf("%c", lower);
                    }
                    printf("\\\n");
                }
                // Print last line
                for (int i = 0; i < size; ++i) {
                    printf("-");
                }
                printf("\n");
                break;
            }
            case '2': {
                // Get num
                unsigned int num;
                printf("Enter a number:\n");
                scanf(" %u", &num);
                int reversed_num = 0;
                unsigned int mask = 1u << (INT_BITS - 1);
                while (num > 0) {
                    // Check if rightmost bit is on
                    if (num & 1u) {
                        // Turn on corresponding bit
                        reversed_num = reversed_num | mask;
                    }
                    // Proceed to next bit
                    mask = mask >> 1;
                    num = num >> 1;
                }
                printf("The reversed number is %d\n", reversed_num);
                break;
            }
            case '3': {
                // Get num
                int num;
                printf("Enter a number:\n");
                scanf(" %d", &num);
                long long reversed_num = 0;
                while (num > 0) {
                    reversed_num = reversed_num * 10 + num % 10;
                    num /= 10;
                }
                printf("The reversed number is %lld\n", reversed_num);
                break;
            }
            case '4': {
                // Get base
                int base;
                printf("Enter base:\n");
                scanf(" %d", &base);
                // Check base validity
                if (base < 2 || base > 9) {
                    printf("Invalid Base\n");
                    break;
                }
                char c;
                printf("Enter a number:\n");
                scanf(" %c", &c);
                int is_valid = 1, converted_num = 0;
                while (c != '\n') {
                    // Check c validity
                    int digit = c - '0';
                    if (digit < 0 || digit >= base) {
                        printf("Invalid character %c in base %d\n", c, base);
                        is_valid = 0;
                        // Clean stdin
                        scanf("%*[^\n]");
                        break;
                    }
                    converted_num = converted_num * base + digit;
                    scanf("%c", &c);
                }
                if (is_valid) {
                    printf("The converted number is %d\n", converted_num);
                }
                break;
            }
            case '5': {
                char c;
                printf("Enter a number in base 64:\n");
                scanf(" %c", &c);
                int is_valid = 1;
                long long converted_num = 0;
                while (c != '\n') {
                    int is_A_Z = c >= 'A' && c <= 'Z';
                    int is_a_z = c >= 'a' && c <= 'z';
                    int is_digit = c >= '0' && c <= '9';
                    int is_plus = c == '+';
                    int is_slash = c == '/';
                    // Check c validity
                    if (!is_A_Z && !is_a_z && !is_digit && !is_plus && !is_slash) {
                        printf("Invalid character %c in base 64\n", c);
                        is_valid = 0;
                        // Clean stdin
                        scanf("%*[^\n]");
                        break;
                    }
                    // Get c base 64 value
                    int base64_val;
                    if (is_A_Z) {
                        base64_val = c - 'A';
                    }
                    if (is_a_z) {
                        base64_val = BASE64_LOWER_A + (c - 'a');
                    }
                    if (is_digit) {
                        base64_val = BASE64_ZERO + (c - '0');
                    }
                    if (is_plus) {
                        base64_val = BASE64_PLUS;
                    }
                    if (is_slash) {
                        base64_val = BASE64_SLASH;
                    }
                    converted_num = converted_num * 64 + base64_val;
                    scanf("%c", &c);
                }
                if (is_valid) {
                    printf("The converted number is %lld\n", converted_num);
                }
                break;
            }
            case '6': {
                // Get num
                unsigned int num;
                printf("Enter a number:\n");
                scanf(" %u", &num);
                // Get indices
                int i, j;
                printf("Enter indexes:\n");
                scanf(" %d%d", &i, &j);
                // Check indices validity
                if (i < 0 || i > 31 || j < 0 || j > 31) {
                    printf("Invalid indexes\n");
                    break;
                }
                unsigned int i_mask = 1u << i;
                unsigned int j_mask = 1u << j;
                unsigned int is_i_on = num & i_mask;
                unsigned int is_j_on = num & j_mask;
                if (is_i_on && !is_j_on) {
                    // Turn off ith bit
                    num = num & (~i_mask);
                    // Turn on jth bit
                    num = num | j_mask;
                } else if (!is_i_on && is_j_on) {
                    // Turn on ith bit
                    num = num | i_mask;
                    // Turn off jth bit
                    num = num & (~j_mask);
                }
                printf("The result is %u\n", num);
                break;
            }
                default: {
                    printf("Invalid option\n");
                    break;
                }
        }
    } while (!is_zero);
    return 0;
}
