#include "book.h"

/**
 * Chapter 5
 * Control flow
 */
int main() {
    char src_data[2] = {0x41, 0x42}; // { A, B }
    char dest_data[2] = {0x44, 0x45}; // { D, E }

    printf("dest_data={ %c, %c }\n\n", dest_data[0], dest_data[1]);

    book_memset(dest_data, 0, 2);

    printf("src_data={ %c, %c }\n", src_data[0], src_data[1]);
    printf("dest_data={ %c, %c }\n\n", dest_data[0], dest_data[1]);

    book_memcopy(dest_data, src_data, 2);

    printf("src_data={ %c, %c }\n", src_data[0], src_data[1]);
    printf("dest_data={ %c, %c }\n\n", dest_data[0], dest_data[1]);

    int elements[2] = {10, 20};

    int element_index = find_element(2, elements, 10);
    printf("element_index=%d", element_index);
}