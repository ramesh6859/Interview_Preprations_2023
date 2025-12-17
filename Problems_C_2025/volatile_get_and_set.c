#include <stdio.h>
#include <stdint.h>

#define REG_ADDRESS 0x40021000U  
volatile uint32_t *reg = (volatile uint32_t *)REG_ADDRESS;
void setRegister(uint32_t value) {
    *reg = value;
}
uint32_t getRegister(void) {
    return *reg;
}
int main(void) {
    setRegister(0xABCD1234);
    uint32_t val = getRegister();
    printf("Register value: 0x%08X\n", val);
    return 0;
}
