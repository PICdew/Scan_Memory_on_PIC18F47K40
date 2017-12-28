#include <xc.h>

#ifndef HAL
    #include "HAL.h"
#endif

void config_ios()
{
/*******************************************************************************
 * This function configs the main pin's registers.
 ******************************************************************************/
    
    //PORTA Configuration   
    
    LATA = 0x00;//Latch's set  Low 
    TRISA = 0xFF;//Tristate sets "In"  
    ANSELA = 0xFF;//Analog Inputs Disabled
    WPUA = 0x00;//Internal Weak Pull-ups Disabled
    ODCONA = 0x00;//Open Drain Disabled 

    //PORTB Configuration      

    LATB = 0x00;//Latch's set  Low  
    TRISB = 0xFF;//Tristate sets "In"   
    ANSELB = 0xFF;//Analog Inputs Disabled
    WPUB = 0x00;//Internal Weak Pull-ups Disabled
    ODCONB = 0x00;//Open Drain Disabled      
    
    //PORTC Configuration    

    LATC = 0x00;//Latch's set  Low  
    TRISC = 0xFF;//Tristate sets "In"   
    ANSELC = 0xFF;//Analog Inputs Disabled
    WPUC = 0x00;//Internal Weak Pull-ups Disabled
    ODCONC = 0x00;//Open Drain Disabled      

    //PORTD Configuration   

    LATD = 0x00;//Latch's set  Low  
    TRISD = 0xEF;//PIN RD7(LED) -> Out   
    ANSELD = 0xFF;//Analog Inputs Disabled
    WPUD = 0x00;//Internal Weak Pull-ups Disabled
    ODCOND = 0x00;//Open Drain Disabled      

    //PORTE Configuration   

    LATE = 0x00;//Latch's set  Low  
    TRISE = 0xFF;//Tristate sets "In"   
    ANSELE = 0xFF;//Analog Inputs Disabled
    WPUE = 0x00;//Internal Weak Pull-ups Disabled
    ODCONE = 0x00;//Open Drain Disabled      
    
    return;
    
}

void config_osc()
{
/*******************************************************************************
 * This function configs the main osc's registers.
 ******************************************************************************/
    
    // NOSC HFINTOSC; NDIV 1; 
    OSCCON1 = 0x60;
    // CSWHOLD may proceed; SOSCPWR Low power; 
    OSCCON3 = 0x00;
    // MFOEN disabled; LFOEN disabled; ADOEN disabled; SOSCEN disabled; EXTOEN disabled; HFOEN disabled; 
    OSCEN = 0x00;
    // HFFRQ 64_MHz; 
    OSCFRQ = 0x08;
    // TUN 0; 
    OSCTUNE = 0x00;    
    return;
}