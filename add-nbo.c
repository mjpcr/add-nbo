#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h> // For ntohl() function

uint32_t read_number_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("파일 '%s'을(를) 열 수 없습니다.\n", filename);
        exit(EXIT_FAILURE);
    }

    uint32_t number;
    if (fread(&number, sizeof(uint32_t), 1, file) != 1) {
        printf("파일 '%s'에서 숫자를 읽어오지 못했습니다.\n", filename);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
    return ntohl(number); // Convert from network byte order to host byte order
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("사용법: %s <첫 번째 파일> <두 번째 파일>\n", argv[0]);
        return 1;
    }

    const char *file1_name = argv[1];
    const char *file2_name = argv[2];

    uint32_t num1 = read_number_from_file(file1_name);
    uint32_t num2 = read_number_from_file(file2_name);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}
