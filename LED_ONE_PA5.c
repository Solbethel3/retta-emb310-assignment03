
/////////////////////////////////////////////////////////////////////////////
/////////////////////Home work for LED1 PA5 ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////
#if 1
#define ODR5 (1<<5)
#define HELLO WORLD AND WELCOME TO EMBEDDED SYSTEM
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))

#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

void delayMs(unsigned int n);
int main() {

//RCC Base Address:0x40021000
//RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
//Address offset
//1. Enable clock to peripheral
RCC_AHB2ENR |=0x1; //Enable Clock for GPIOA -> BIT 0 -> 0x1

//GPIOA Base Address:0x4800 0000
//GPIO port mode register (GPIOx_MODER) (x = A..E and H)
//Address offset: 0x00
//Set bit[11:10] to 0x01 so --> 0x20 enable PA5 as output

GPIOA_MODER &=0xFFFFF7FF;

//GPIOA Base Address:0x48000000
//GPIO port output data register (GPIOx_ODR) (x = A..E and H)
//Address offset: 0x14
//Set bit[5] to 1 so --> turn LED to ON
//Set bit[5] to 0 so --> turn LED to OFF

    while(1) {
       
        delayMs(1);//delay 1 second

        GPIOA_ODR ^= ODR5;// //GPIO_ODR: Turn LED1 (PA5) OFF
    }

return 0;

}

//Delays n milli seconds for (80 MHZ CPU clock
void delayMs(unsigned int n){

    unsigned int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < 10000; j++){
            // do nothing 
        }
    }    
}

#endif