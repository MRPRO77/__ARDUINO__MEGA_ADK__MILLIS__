/************************************************************************************************************

                                      configurações Mega ADK
************************************************************************************************************/

                                   /* Arquivos de Bibliotecas */

 // ========================================================================================================
// --- Bibliotecas Auxiliares --- //

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#include <Adafruit_GFX.h>
#include <Adafruit_BusIO_Register.h>
#include <TCA9548A.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_SSD1306.h>



/**********************************************************************************************************/
                                        /* Arquivos de inclusão */


#include "config_mcu.h"



// =============================================================================================================
// --- Mapeamento de Hardware ---

#define OLED_RESET 3                                 // pino reset Oled
#define led_Sinalizacao 22                           // Led Sinalização Funcionamento do programa




/**********************************************************************************************************/
                                        /* Arquivos de inclusão */
LiquidCrystal_I2C lcd(0x27,20,4);            // Set the LCD address to 0x27 for a 16 chars and 2 line display
Adafruit_SSD1306 display(OLED_RESET);        // Objeto para o OLED
TCA9548A I2CMux;                             // Address can be passed into the constructor
//==============================================================
//  -----Diretivas TCA9548A
#define i2clcd        0
#define i2coled       1

#define usalcd    I2CMux.openChannel(i2clcd)
#define usaoled   I2CMux.openChannel(i2coled)
// =============================================================================================================
// --- Protótipo das Funções ---
void Funcionamento_Sistema();                //Função para o supervisionamento do funcionamento do sistema

// =============================================================================================================
// --- Variáveis Globais ---
char control = 0x01;                         //variável de controle de teclado
char counter = 0x00;                         //variável auxiliar de contagem
int  number_teclado  = 0x00;                 //variável para armazenar o número pressionado no teclado
unsigned long ultimaMudanca = millis();      //variável para contagem de tempo sinalização do funcionamento do programa




// ======================================================================================================
// --- Função de inicialização do AVR 2560 ADK---
// ======================================================================================================
// --- Objetos ---
 void config_mcu()

 {
              
           

                                   Wire.begin();
                           Serial.begin(115200);
                             I2CMux.begin(Wire);
                 
            


                                         usalcd;
                                     delay(100);
                                     lcd.init();
                                lcd.backlight();       
                         I2CMux.closeChannel(0);
       
                                         usalcd;
                                    lcd.clear(); 
                             lcd.setCursor(2,1);
                  lcd.print("MRPRO TECNOLOGIA");
                         I2CMux.closeChannel(0);





                                         usaoled;
       display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
                          display.clearDisplay();
                          I2CMux.closeChannel(1);




                                         usaoled;
                          display.clearDisplay();
                          display.setTextSize(1);
                     display.setTextColor(WHITE);
                         display.setCursor(30,0);
                     display.print("Tecnologia");
                                      delay(100);
                               display.display();
                          display.setTextSize(2);
                        display.setCursor(33,10);
                          display.print("MRPRO");
                                      delay(100);
                               display.display();  
                          I2CMux.closeChannel(1);


                          
                 pinMode(led_Sinalizacao,OUTPUT);                                    // configura digital 22 como saida


     
     
    
            
            

                
   
 }



 void Funcionamento_Sistema ()

   {
        if ((millis() - ultimaMudanca) < 2000)
        {
        digitalWrite(led_Sinalizacao, HIGH);
        }
        else
        {
        digitalWrite(led_Sinalizacao,LOW);
        }
        if((millis() - ultimaMudanca) > 4000)
        {
            ultimaMudanca = millis();
        }

 }

 