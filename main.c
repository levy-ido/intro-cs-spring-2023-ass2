#include <stdio.h>
#define SPACE_DOT_SUM 78
#define INT_BITS 32
#define ZERO_ASCII 48
#define A_ASCII 65
int main() {
    char user_input, c;
    int num, reversed_num, base, digit, invalid_string, is_A_Z, is_a_z, is_digit, is_plus, is_slash;
    long converted;
    do {
        printf("Choose an option:\n");
        printf("0. Exit\n");
        printf("1. Hourglass\n");
        printf("2. Reverse bits\n");
        printf("3. Reverse digits\n");
        printf("4. Convert to Decimal\n");
        printf("5. Base64 to Decimal\n");
        printf("6. Swap bits\n");
        scanf(" %c", &user_input);
        switch (user_input) {
            case '0':
                return 0;
            case '1':
                // Get parameters
                printf("Enter size:\n");
                int size;
                scanf(" %d", &size);
                printf("Enter flag:\n");
                int flag;
                scanf(" %d", &flag);
                // Check parameters validity
                if (size < 3 || (flag != 0 && flag != 1)) {
                    printf("Invalid Parameters\n");
                    break;
                }
                // Print hourglass
                // Print first line
                for (int i = 0; i < size; ++i) {
                    printf("-");
                }
                // Set filling characters
                char upper_filling = flag ? '.':' ';
                char lower_filling = SPACE_DOT_SUM - upper_filling;
                // Print upper half
                for (int i = 0; i < size / 2; ++i) {
                    printf("\n");
                    // Print initial spaces
                    for (int j = 0; j < i; ++j) {
                        printf(" ");
                    }
                    printf("\\");
                    // Print filling characters
                    for (int j = 0; j < size - 2 * i - 2; ++j) {
                        printf("%c", upper_filling);
                    }
                    printf("/");
                }
                // Handle odd size
                if (size % 2 == 1) {
                    printf("\n");
                    for (int i = 0; i < size / 2; ++i) {
                        printf(" ");
                    }
                    printf("X");
                }
                // Print lower half
                for (int i = 0; i < size / 2; ++i) {
                    printf("\n");
                    // Print initial spaces
                    for (int j = 0; j < size / 2 - i - 1; ++j) {
                        printf(" ");
                    }
                    printf("/");
                    // Print filling characters
                    for (int j = 0; j < size - 2 * (size / 2 - i - 1) - 2; ++j) {
                        printf("%c", lower_filling);
                    }
                    printf("\\");
                }
                printf("\n");
                // Print last line
                for (int i = 0; i < size; ++i) {
                    printf("-");
                }
                printf("\n");
                break;
            case '2':
                printf("Enter a number:\n");
                scanf(" %d", &num);
                // Get nums' bits
                unsigned int num_bits = num;
                reversed_num = 0;
                unsigned int mask = 1 << (INT_BITS - 1);
                while (num_bits > 0) {
                    // Is rightmost bin on
                    unsigned int is_on = num_bits & 1;
                    if (is_on) {
                        // Turn on corresponding bit
                        reversed_num = reversed_num | mask;
                    }
                    // Proceed to next bit
                    mask = mask >> 1;
                    num_bits = num_bits >> 1;
                }
                printf("The reversed number is %d\n", reversed_num);
                break;
            case '3':
                // What if the reversed number overflows?
                printf("Enter a number:\n");
                scanf(" %d", &num);
                reversed_num = 0;
                while (num > 0) {
                    reversed_num = reversed_num * 10 + num % 10;
                    num /= 10;
                }
                printf("The reversed number is %d\n", reversed_num);
                break;
            case '4':
                printf("Enter base:\n");
                scanf(" %d", &base);
                if (base < 2 || base > 9) {
                    printf("Invalid Base\n");
                    break;
                }
                num = 0;
                invalid_string = 0;
                printf("Enter a number:\n");
                scanf(" %c", &c);
                while (c != '\n') {
                    num *= base;
                    digit = c - ZERO_ASCII;
                    if (digit < 0 || digit >= base) {
                        printf("Invalid character %c in base %d\n", c, base);
                        invalid_string = 1;
                        // Clean stdin
                        scanf("%*[^\n]");
                        break;
                    }
                    num += digit;
                    scanf("%c", &c);
                }
                if (!invalid_string) {
                    printf("The converted number is %d\n", num);
                }
                break;
            case '5':
                converted = 0;
                invalid_string = 0;
                printf("Enter a number in base 64:\n");
                scanf(" %c", &c);
                while (c != '\n') {
                    converted *= 64;
                    is_A_Z = c >= 'A' && c <= 'Z';
                    is_a_z = c >= 'a' && c <= 'z';
                    is_digit = c >= '0' && c <= '9';
                    is_plus = c == '+';
                    is_slash = c == '/';
                    if (!is_A_Z && !is_a_z && !is_digit && !is_plus && !is_slash) {
                        printf("Invalid character %c in base 64\n", c);
                        invalid_string = 1;
                        // Clean stdin
                        scanf("%*[^\n]");
                        break;
                    }
                    if (is_A_Z) {
                        digit = c - A_ASCII;
                    }
                    if (is_a_z) {
                        // 'a' base 64 value = 26. 'a' ascii value = 97
                        // Add the relative position of c in 'a'-'z' to the 'a' base 64 value
                        digit = 26 + (c - 97);
                    }
                    if (is_digit) {
                        // '0' base 64 value = 52
                        // Add the relative position of c in '0'-'9' to the '0' base 64 value
                        digit = 52 + (c - ZERO_ASCII);
                    }
                    if (is_plus) {
                        digit = 62;
                    }
                    if (is_slash) {
                        digit = 63;
                    }
                    converted += digit;
                    scanf("%c", &c);
                }
                if (!invalid_string) {
                    printf("The converted number is %ld\n", converted);
                }
                break;
            case '6':
                printf("Execute task 6\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (1);
}
