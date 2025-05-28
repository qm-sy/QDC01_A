#include "eeprom_crl.h"

uint8_t mode_info[5];

/**
 * @brief	eeprom状态判定，是否写入过
 *
 * @param   
 *
 * @return  void
**/
void eeprom_statu_judge( void )
{
    uint8_t eeprom_statu_flag;

    eeprom_statu_flag = ISP_Read(EEPROM_STATU_JUDGE);

    if( eeprom_statu_flag == 0xFF)
    {
        ac_dc.power_level       = 0x32;          // 50 220V输出50%功率
        ac_dc.fan_level         = 0x03;          // 3  风扇默认三档
        ac_dc.alarm_temp_val    = 0x50;          // 报警温度默认80℃
        ac_dc.sync_flag         = 0x00;          // 0000 0000  sync默认关
        ac_dc.channel_num       = 0x05;          // 0000 0111  三路全开
        ac_dc.mode_num          = 0x02;          // 50         220V输出50%功率
        ac_dc.ac_switch         = 1;

        eeprom_data_record();
    }
    eeprom_data_init(); 
}

void eeprom_data_record( void )
{
    ISP_Earse(0X00);

    ISP_Write(POWER_ADDR,ac_dc.power_level);
    ISP_Write(FAN_ADDR,ac_dc.fan_level);
    ISP_Write(ALARM_ADDR,ac_dc.alarm_temp_val);
    ISP_Write(SYNC_ADDR,ac_dc.sync_flag);
    ISP_Write(CHANNEL_ADDR,ac_dc.channel_num);
    ISP_Write(MODE_ADDR,ac_dc.mode_num);
    ISP_Write(AC_SWITCH,ac_dc.ac_switch);

    ISP_Write(EEPROM_STATU_JUDGE,0x58);
}


/**
 * @brief	eeprom 数据初始化
 *
 * @param   
 *
 * @return  void
**/
void eeprom_data_init( void )
{
    ac_dc.power_level = ISP_Read(POWER_ADDR);
    ac_220v_crl(ac_dc.power_level);

    ac_dc.fan_level = ISP_Read(FAN_ADDR);
    fan_ctrl(ac_dc.fan_level);

    ac_dc.alarm_temp_val = ISP_Read(ALARM_ADDR);

    ac_dc.sync_flag = ISP_Read(SYNC_ADDR);

    ac_dc.channel_num = ISP_Read(CHANNEL_ADDR);
    channel_choose();

    ac_dc.mode_num = ISP_Read(MODE_ADDR);

    ac_dc.ac_switch = ISP_Read(AC_SWITCH);
}
