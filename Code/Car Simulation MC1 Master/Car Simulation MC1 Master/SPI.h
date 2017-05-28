/*
 * SPI.h
 *
 * Created: 5/9/2016 02:48:47 م
 *  Author: Ahmed
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "INIT_PIN.h"
#include "TYPE_DATE.h"
#include "micro_config.h"

#define SPI_PORT PORTB
#define SPI_RES DDRB
#define  SS PB0
#define MOSI PB2
#define MISO PB3
#define SCK PB1


void SPI_Master_init(void);
void SPI_Slave_init(void);
void SPI_SendByte(uint8 date);
uint8 SPI_ReciveByte(void);
void SPI_SendString(const uint8 *str);
void SPI_ReciveString(uint8 *str);


#endif /* SPI_H_ */