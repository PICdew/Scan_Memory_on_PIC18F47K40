# Scan_Memory_on_PIC18F47K40
Scan Memory on Microchip PIC18F47K40 with CRC internal hardware feature.

/*******************************************************************************
 Programmer: Caio Cesar Bosco
 Date: 28/12/2017
 Code: Scan Memory with CRC on PIC18F47K40
 
 Language: C
 Compiler:xc8
 IDE: Mplabx
 Target: PIC18F47K40
 Download CRC Calculator at Microchip Site:http://www.microchip.com/mymicrochip/filehandler.aspx?ddocname=en572174
 
 * This code do the scan memory in Burst Mode with internal DMA and CRC PIC resources.  
 * It's just a Microchip Application Note Implementation, for more
 * information access:
 * 
 * http://ww1.microchip.com/downloads/en/AppNotes/90003128A.pdf
 * http://ww1.microchip.com/downloads/en/AppNotes/00001817A.pdf
 * 
 *  
 ******************************************************************************/
