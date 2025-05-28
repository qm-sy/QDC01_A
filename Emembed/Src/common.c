#include "common.h"

/**
 * @brief	一些定时执行的事件   Timer3：10ms
 *
 * @param   
 *
 * @return  void
**/
void Tim3_ISR( void ) interrupt 19
{

    static uint16_t temp_scan_cnt = 0;
    
    /* 1, Signal_IN状态查询           */
    if( Signal_IN == 0 )
    {
        ac_dc.signal_in_flag = 1;
    }else
    {
        ac_dc.signal_in_flag = 0;
    }

    /* 2, temp 上报 1s/次                             */
    if( temp.temp_scan_flag == 0 )
    {
        temp_scan_cnt++;
        if( temp_scan_cnt == 100 )
        {
            temp.temp_scan_flag = 1;
            temp_scan_cnt = 0;
        }
    }
}
