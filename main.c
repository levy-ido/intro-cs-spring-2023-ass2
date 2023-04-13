#include <stdio.h>
#define SPACE_DOT_SUM 78
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
                // get_parameters
                printf("Enter size:\n");
                int size;
                scanf(" %d", &size);
                printf("Enter flag:\n");
                int flag;
                scanf(" %d", &flag);
                // check_parameters_validity
                if (size < 3 || (flag != 0 && flag != 1)) {
                    printf("Invalid Parameters\n");
                    break;
                }
                // print_hourglass
                // print_first_line
                for (int i = 0; i < size; ++i) {
                    printf("-");
                }
                // set_filling_characters
                char first_half_c = flag ? '.':' ';
                char second_half_c = SPACE_DOT_SUM - first_half_c;
                // print_first_half
                for (int i = 0; i < size / 2; ++i) {
                    printf("\n");
                    // print_initial_spaces
                    for (int j = 0; j < i; ++j) {
                        printf(" ");
                    }
                    printf("\\");
                    // print_filling_characters
                    for (int j = 0; j < size - 2 * i - 2; ++j) {
                        printf("%c", first_half_c);
                    }
                    printf("/");
                }
                // handle_odd_size
                if (size % 2 == 1) {
                    printf("\n");
                    for (int i = 0; i < size / 2; ++i) {
                        printf(" ");
                    }
                    printf("X");
                }
                // print_second_half
                for (int i = 0; i < size / 2; ++i) {
                    printf("\n");
                    // print_initial_spaces
                    for (int j = 0; j < size / 2 - i - 1; ++j) {
                        printf(" ");
                    }
                    printf("/");
                    // print_filling_characters
                    for (int j = 0; j < size - 2 * (size / 2 - i - 1) - 2; ++j) {
                        printf("%c", second_half_c);
                    }
                    printf("\\");
                }
                printf("\n");
                // print_last_line
                for (int i = 0; i < size; ++i) {
                    printf("-");
                }
                printf("\n");
                break;
            case '2':
                printf("Execute task 2\n");
                break;
            case '3':
                printf("Execute task 3\n");
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
