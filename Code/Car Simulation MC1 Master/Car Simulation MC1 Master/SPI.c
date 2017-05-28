/*
 * SPI.c
 *
 * Created: 5/9/2016 02:49:01 م
 *  Author: Ahmed
 */ 
 #include "SPI.h"

 
 void SPI_Master_init(void)
 {
	 SPI_RES|=(1<<MOSI)|(1<<SS)|(1<<SCK);
	 CLEAR_BIT(SPI_PORT,MISO);
	 SPCR=(1<<SPE)|(1<<MSTR);

 }
 void SPI_Slave_init(void)
 {
 
 CLEAR_BIT(SPI_PORT,PB4);
 CLEAR_BIT(SPI_PORT,PB5);
 CLEAR_BIT(SPI_PORT,PB7);
 SET_BIT(SPI_PORT,PB6);
 SPCR = (1<<SPE) ;
 }

 void SPI_SendByte(uint8 date)
 {
 	 SPDR=date;
	 while(BIT_IS_CLEAR(SPSR,SPIF)){}
 }
 uint8 SPI_ReciveByte(void)
 {
	 while(BIT_IS_CLEAR(SPSR,SPIF)){}
	 return SPDR;
 }
 void SPI_SendString(const uint8 *str)
 {
	 
	 uint8 i = 0;
	 while (str[i] != '\0')
	 {
		 SPI_SendByte(str[i]);
		 ++i;
	 }
 
 }
 void SPI_ReciveString(uint8 *str)
 {
	 
	 uint8 i =0;
	 str[i]= SPI_ReciveByte();
	 while(str[i] != '#')
	 {
		 i++;
		 str[i]=SPI_ReciveByte();
	 }
	 str[i]='\0';
 }