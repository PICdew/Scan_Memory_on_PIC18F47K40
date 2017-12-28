/*******************************************************************************
 Programmer: Caio Cesar Bosco
 Date: 28/12/2017
 Code: Scan Memory with CRC on PIC18F47K40

 * This code do the scan memory in Burst Mode with internal DMA and CRC PIC resources.  
 * It's just a Microchip Application Note Implementation, for more
 * information access:
 * 
 * http://ww1.microchip.com/downloads/en/AppNotes/90003128A.pdf
 * http://ww1.microchip.com/downloads/en/AppNotes/00001817A.pdf
 * 
 *  
 ******************************************************************************/

#include <xc.h>
#include "HAL.h"

//******************************************************************************
//The lastest Two address holds Memory's CRC value (computed by a external application). 
//Download CRC Calculator on Microchip Site: 
//         http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en572174

const int CRC_checkValue @ 0x1FFFE=0x189C;

//****************************************************************************

void main()
{
    int crc=0;//Receives On Running CRC value.
    
    config_osc();//Configure Internal Oscillator on 64MHz
    config_ios();//Configure uC pins
    
    SCANCON0bits.EN=1;//Enable Flash Scan_Memory.
    SCANCON0bits.MODE=1;//Burst Mode - Stop Firmware Flow for Scanning.
    SCANCON0bits.INTM=0;//No interrupts along Scanning Process.
    
    //***********Selecting Initial Flash Memory Address for Scanning************
    
    SCANLADRU=0;
    SCANLADRL=0;
    SCANLADRH=0;
    
    //**************************************************************************

    //***********Selecting Last Flash Memory Address for Scanning************
    
    SCANHADRU=0x01;
    SCANHADRL=0xFC;
    SCANHADRH=0xFF;   

    //Microchip PIC18F47K40's an 8 bits architecture, but opcode's a 16 bits
    //instruction. So the last valid flash address's: 0x1FFFC(opcode MSB)-0x1FFFD(opcode LSB)
    //0x1FFFE - 0x1FFFF holds Flash Memory CRC Value. 
    //**************************************************************************
    
    CRCCON0bits.EN=1;//Enable Internal CRC Module    
    
    CRCACCH=0xFF;//Seeding CRC Accumulator 
    CRCACCL=0xFF;//Seeding CRC Accumulator
    
    //************************16 bit Polynomial CRC-CCITT*************************
    //Polynomial: x^16+x^15+x^5+1
    CRCXORH=0x10;
    CRCXORL=0x21;
    //****************************************************************************

    CRCCON1bits.DLEN=0b0111;//Data Lenght
    CRCCON1bits.PLEN=0b1111;//Polynomial Lenght
    CRCCON0bits.ACCM=1;//Augmented Mode On
    CRCCON0bits.SHIFTM=0;//Big-Endian 
    
    LED=0;//Led off
    
    while(1)//Super-Loop
    {
        CRCCON0bits.CRCGO=1;//Run CRC Module
        SCANCON0bits.GO=1;//Run Scan Memory
        
        while(SCANCON0bits.GO);//Waiting Scan
        while(CRCCON0bits.BUSY);//Waiting CRC Module
        
        crc=CRCACCL+(CRCACCH<<8);//Holds "On Running" CRC value 
        
        if(crc==CRC_checkValue)
        {
            /*******************************************************************
             *If "On Running" memory CRC is the same as the Previously Memory CRC Value, 
             toggles LED.
            *******************************************************************/
            LED=~LED;
            
            /******************************************************************
             (If necessary put a delay routine here).
             ******************************************************************/
        }
    }    
}    


