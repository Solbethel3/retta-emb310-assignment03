
/*
//Morse code
//The following program uses LED2 to show morse code of first name
// Name - RETTA
        R . - .
        E .
        T -
        T -
        A . -
one unit is defined 1 ms
The length of a dot is one unit --> 1s
The length of a dash is three unit --> 3s
Space between units of the same letter is one unit --> 1s
Space between letters is three units --> 3s
Space between words is 7 units --> 7s
*/

#include <stdio.h> 
#include <string.h>

void delay(unsigned int n); // Prototype declaration for delay function

#if 1
#define R ".-."
#define E "."
#define T "-"
#define T "-"
#define A "-."
#define dotLength 1000 //delay 1 second for dot
#define dashLength 3*dotLength // 3X longer than the dot
#define wordLength 7*dotLength // space between words.
#define ODR14 (1<<14)
#define HELLO WORLD AND WELCOME TO EMBEDDED SYSTEM
#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x00)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))

char ch_arr[5][6] = { R,E,T,T,A}; //First Name ---> RETTA

int counter;
int main() {

//RCC Base Address:0x40021000
//RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
//Address offset
//1. Enable clock to peripheral
RCC_AHB2ENR |=0x2; //Enable Clock for GPIOB -> BIT 1 -> 0x2

//GPIOB Base Address:0x48000400
//GPIO port mode register (GPIOx_MODER) (x = A..E and H)
//Address offset: 0x00
//Set bit[29:28] to 0x01 so --> 0x4000 enable PB14 as output

GPIOB_MODER &=0xDFFFFFFF;

//GPIOB Base Address:0x48000400
//GPIO port output data register (GPIOx_ODR) (x = A..E and H)
//Address offset: 0x14
//Set bit[14] to 1 so --> turn LED to ON
//Set bit[14] to 0 so --> turn LED to OFF

while(1) 
{  
    int i = 0;
    char c = 0;
    while(i < 5){
        int j = 0;
        while(j < 5) {
            c = ch_arr[i][j];
            if(c == '\0') {
                break;
            }
            else {
                if(c =='.') {  
                    GPIOB_ODR |= ODR14;//LED2 ON
                    delay(dotLength); //1 second delay for a dot
                    GPIOB_ODR &= ~ODR14;// LED2 OFF
                    delay(dotLength);//1 second time delay between units of the same letter is one unit 
                }
                else if(ch_arr[i][j]=='-') {  
                    GPIOB_ODR |= ODR14;//LED2 ON
                    delay(dashLength); //3 seconds delay for dash
                    GPIOB_ODR &= ~ODR14;//LED2 OFF
                    delay(dotLength);//1 second time delay between units of the same letter is one unit 
                }
                
            }
            j++;
        }
        i++;
    }
    delay(wordLength);// Reset to the begining of the word --> 7 seconds time delay between words -->First Name
}
return 0;
}
#endif

//Delay
void delay(unsigned int n){

    unsigned int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < 1000; j++){
            // do nothing 
        }
    }    
}
