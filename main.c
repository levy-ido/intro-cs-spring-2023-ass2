#include <stdio.h>
#define SPACE_DOT_SUM 78
#define INT_BITS 32
int main() {
    char user_input;
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
                int num;
                scanf(" %d", &num);
                // Get nums' bits
                unsigned int num_bits = num;
                int reversed_num = 0;
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
                printf("Enter a number:\n");
                scanf(" %d", &num);

                break;
            case '4':
                printf("Execute task 4\n");
                break;
            case '5':
                printf("Execute task 5\n");
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
