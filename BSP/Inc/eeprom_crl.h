#ifndef __EEPROM_CRL_H_
#define __EEPROM_CRL_H_

#include "eeprom.h"
#include "sys.h"
#include "power_crl.h"
#include "ntc.h"
#include "stdio.h"

#define POWER_ADDR          0x0000
#define FAN_ADDR            0x0001
#define ALARM_ADDR          0x0002
#define SYNC_ADDR           0x0003
#define CHANNEL_ADDR        0x0004
#define MODE_ADDR           0x0005
#define AC_SWITCH           0X0006

#define EEPROM_STATU_JUDGE  0X0010         

void eeprom_statu_judge( void );
void eeprom_data_record( void );
void eeprom_data_init( void );

#endif