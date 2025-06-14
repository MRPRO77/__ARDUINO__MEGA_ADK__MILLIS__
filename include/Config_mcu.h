/********************************Função que configura Pinos do MCU**************************************

                                   configuração para placa Mega ADK

********************************************************************************************************/
/*******************************************************************************************************/
/* Arquivos de inclusão */

#ifndef Config_mcu_h_
#define Config_mcu_h_
                
                
// ======================================================================================================
// --- Protótipo das Funções ---
void config_mcu ();
void Funcionamento_Sistema();                //Função para o supervisionamento do funcionamento do sistema
void readKeyboard();                  //Função para leitura do teclado
void store(char value);               //Função para armazenar o número digitado no teclado matricial
void numero();                        //Função para imprimir o número digitado na tela do LCD  


#endif