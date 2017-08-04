#include <stdio.h>
#include <math.h>

//page table
const unsigned page_table[] = {5, 6, 1, 2};

#define LOG_ADDR_SPACE 16
#define PAGE_SIZE 4


unsigned mask(unsigned a);

int main()
{
    const unsigned n = log2(PAGE_SIZE);
    const unsigned m = log2(LOG_ADDR_SPACE) - n;

    printf("Logical | Page | Page   | Frame | Phys   \n");
    printf("Address |   #  | Offset |   #   | Address\n");
    printf("--------------------------------------------\n");
    for (unsigned log_addr = 0; log_addr < LOG_ADDR_SPACE; log_addr++) {
        //init logical address -- page number (p) -- page offset (d) -- frame number (f) -- phys address
        unsigned p = log_addr >> n;
        unsigned f = page_table[p];
        unsigned d = (mask(n) & log_addr);
        unsigned phys_addr = (f << n) + d;
        printf("%7u | %4u | %6u | %5u | %4u\n", log_addr, p, d, f, phys_addr);
    }
}

unsigned mask(unsigned a) {
    return (1 << a) - 1;
}
