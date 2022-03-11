/***
	****************************************************************************************************
	*	@file  	touch_480x272.c
	*	@version V1.1
	*  @date    2020-10-14
	*	@author  反客科技
	*	@brief   GT911触摸驱动
   ****************************************************************************************************
   *  @description
	*
	*	实验平台：反客STM32F429IGT6(型号FK429M2)核心板 + 4.3寸RGB液晶屏(屏幕型号RGB043M1-480*272)
	*	淘宝地址：https://shop212360197.taobao.com
	*	QQ交流群：536665479
	*
>>>>> V1.1 （2020-10-14）版本变更说明：
	*
	*	1. 将驱动文件名称由 “touch_043.c” 改为 “touch_480x272.c”
	*	2. 去除 修改触摸IC内部参数的代码，防止用户意外改写触摸参数
	*	
>>>>>	文件说明：
	*
	*  1.触摸屏相关的操作函数
	* 	2.使用模拟IIC
	*	3.通信速度默认为100KHz
	*	
	*****************************************************************************************************
***/

#include "touch_480x272.h"

TouchStructure touchInfo; 			//	触摸信息结构体，在函数 Touch_Scan() 里被调用，存储触摸数据


/*****************************************************************************************
*	函 数 名:	GT9XX_Reset
*	入口参数:	无
*	返 回 值:	无
*	函数功能:	复位GT911
*	说    明:	复位GT911，并将芯片的IIC地址配置为0xBA/0xBB
******************************************************************************************/

void GT9XX_Reset(void)
{
	Touch_INT_Out();	//	将INT引脚配置为输出
	
	// 初始化引脚状态
	HAL_GPIO_WritePin(Touch_INT_PORT,Touch_INT_PIN,GPIO_PIN_RESET);  // INT输出低电平
	HAL_GPIO_WritePin(Touch_RST_PORT,Touch_RST_PIN,GPIO_PIN_SET);    // RST输出高	电平
	Touch_IIC_Delay(10000);
	
	// 开始执行复位
	//	INT引脚保持低电平不变，将器件地址设置为0XBA/0XBB
	HAL_GPIO_WritePin(Touch_RST_PORT,Touch_RST_PIN,GPIO_PIN_RESET); // 拉低复位引脚，此时芯片执行复位
	Touch_IIC_Delay(250000);										// 延时
	HAL_GPIO_WritePin(Touch_RST_PORT,Touch_RST_PIN,GPIO_PIN_SET);			// 拉高复位引脚，复位结束
	Touch_IIC_Delay(450000);										// 延时
	Touch_INT_In();													// INT引脚转为浮空输入
	Touch_IIC_Delay(350000);										// 延时
									
}


/*****************************************************************************************
*	函 数 名:	GT9XX_WriteHandle
*	入口参数:	addr - 要操作的寄存器
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 写操作
*	说    明:	对指定的寄存器执行写操作
******************************************************************************************/

uint8_t GT9XX_WriteHandle (uint16_t addr)
{
	uint8_t status;				// 状态标志位

	Touch_IIC_Start();	// 启动IIC通信
	if( Touch_IIC_WriteByte(GT9XX_IIC_WADDR) == ACK_OK ) //写数据指令
	{
		if( Touch_IIC_WriteByte((uint8_t)(addr >> 8)) == ACK_OK ) //写入16位地址
		{
			if( Touch_IIC_WriteByte((uint8_t)(addr)) != ACK_OK )
			{
				status = ERROR;	// 操作失败
			}			
		}
	}
	status = SUCCESS;	// 操作成功
	return status;	
}

/*****************************************************************************************
*	函 数 名:	GT9XX_WriteData
*	入口参数:	addr - 要写入的寄存器
*					value - 要写入的数据
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 写一字节数据
*	说    明:	对指定的寄存器写入一字节数据
******************************************************************************************/

uint8_t GT9XX_WriteData (uint16_t addr,uint8_t value)
{
	uint8_t status;
	
	Touch_IIC_Start(); //启动IIC通讯

	if( GT9XX_WriteHandle(addr) == SUCCESS)	//写入要操作的寄存器
	{
		if (Touch_IIC_WriteByte(value) != ACK_OK) //写数据
		{
			status = ERROR;						
		}
	}	
	Touch_IIC_Stop(); // 停止通讯
	
	status = SUCCESS;	// 写入成功
	return status;
}

/*****************************************************************************************
*	函 数 名:	GT9XX_WriteReg
*	入口参数:	addr - 要写入的寄存器区域首地址
*					cnt  - 数据长度
*					value - 要写入的数据区
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 写寄存器
*	说    明:	往芯片的寄存器区写入指定长度的数据
******************************************************************************************/

uint8_t GT9XX_WriteReg (uint16_t addr, uint8_t cnt, uint8_t *value)
{
	uint8_t status;
	uint8_t i;

	Touch_IIC_Start();

	if( GT9XX_WriteHandle(addr) == SUCCESS) 	// 写入要操作的寄存器
	{
		for(i = 0 ; i < cnt; i++)			 	// 计数
		{
			Touch_IIC_WriteByte(value[i]);	// 写入数据
		}					
		Touch_IIC_Stop();		// 停止IIC通信
		status = SUCCESS;		// 写入成功
	}
	else
	{
		Touch_IIC_Stop();		// 停止IIC通信
		status = ERROR;		// 写入失败
	}
	return status;	
}

/*****************************************************************************************
*	函 数 名:	GT9XX_ReadReg
*	入口参数:	addr - 要读取的寄存器区域首地址
*					cnt  - 数据长度
*					value - 要读取的数据区
*	返 回 值:	SUCCESS - 操作成功
*					ERROR	  - 操作失败
*	函数功能:	GT9XX 读寄存器
*	说    明:	从芯片的寄存器区读取指定长度的数据
******************************************************************************************/

uint8_t GT9XX_ReadReg (uint16_t addr, uint8_t cnt, uint8_t *value)
{
	uint8_t status;
	uint8_t i;

	status = ERROR;
	Touch_IIC_Start();		// 启动IIC通信

	if( GT9XX_WriteHandle(addr) == SUCCESS) //写入要操作的寄存器
	{
		Touch_IIC_Start(); //重新启动IIC通讯

		if (Touch_IIC_WriteByte(GT9XX_IIC_RADDR) == ACK_OK)	// 发送读命令
		{	
			for(i = 0 ; i < cnt; i++)	// 计数
			{
				if (i == (cnt - 1))
				{
					value[i] = Touch_IIC_ReadByte(0);	// 读到最后一个数据时发送 非应答信号
				}
				else
				{
					value[i] = Touch_IIC_ReadByte(1);	// 发送应答信号
				}
			}					
			Touch_IIC_Stop();	// 停止IIC通信
			status = SUCCESS;
		}
	}
	Touch_IIC_Stop();	// 停止IIC通信
	return (status);	
}



/*****************************************************************************************
*	函 数 名: Touch_Init
*	入口参数: 无
*	返 回 值: SUCCESS  - 初始化成功
*            ERROR 	 - 错误，未检测到触摸屏	
*	函数功能: 触摸IC初始化，并读取相应信息发送到串口
*	说    明: 初始化触摸面板
******************************************************************************************/

uint8_t Touch_Init(void)
{
	uint8_t GT9XX_Info[11];	// 触摸屏IC信息
	uint8_t cfgVersion = 0;	// 触摸配置版本
	
	Touch_IIC_GPIO_Config(); 	// 初始化IIC引脚
	GT9XX_Reset();					// GT911 复位
	
	GT9XX_ReadReg (GT9XX_ID_ADDR,11,GT9XX_Info);		// 读触摸屏IC信息
	GT9XX_ReadReg (GT9XX_CFG_ADDR,1,&cfgVersion);	// 读触摸配置版本
	
	if( GT9XX_Info[0] == '9' )	//判断第一个字符是否为 9
	{
		printf("Touch ID: GT%.4s \r\n",GT9XX_Info);	//打印触摸芯片的ID
		printf("固件版本： 0X%.4x\r\n",(GT9XX_Info[5]<<8) + GT9XX_Info[4]);	// 芯片固件版本
		printf("触摸分辨率：%d * %d\r\n",(GT9XX_Info[7]<<8) + GT9XX_Info[6],(GT9XX_Info[9]<<8) +GT9XX_Info[8]);	// 当前触摸分辨率		
		printf("触摸参数配置版本： 0X%.2x \r\n",cfgVersion);	// 触摸配置版本	
		
		return SUCCESS;
	}
	else
	{
		printf("Touch Error\r\n");	//错误，未检测到触摸屏
		return ERROR;
	}

}

/*****************************************************************************************
*	函 数 名: Touch_Scan
*	入口参数: 无
*	返 回 值: 无
*	函数功能: 触摸扫描
*	说    明: 在程序里周期性的调用该函数，用以检测触摸操作，触摸信息存储在 touchInfo 结构体
******************************************************************************************/

void Touch_Scan(void)
{
 	uint8_t  touchData[2 + 8 * TOUCH_MAX ]; 		// 用于存储触摸数据
	uint8_t  i = 0;	
	
	GT9XX_ReadReg (GT9XX_READ_ADDR,2 + 8 * TOUCH_MAX ,touchData);	// 读数据
	GT9XX_WriteData (GT9XX_READ_ADDR,0);									//	清除触摸芯片的寄存器标志位
	touchInfo.num = touchData[0] & 0x0f;									// 取当前的触摸点数
	
	if ( (touchInfo.num >= 1) && (touchInfo.num <=5) ) 	//	当触摸数在 1-5 之间时
	{
		for(i=0;i<touchInfo.num;i++)		// 取相应的触摸坐标
		{
			touchInfo.y[i] = (touchData[5+8*i]<<8) | touchData[4+8*i];	// 获取Y坐标
			touchInfo.x[i] = (touchData[3+8*i]<<8) | touchData[2+8*i];	//	获取X坐标			
		}
		touchInfo.flag = 1;	// 触摸标志位置1，代表有触摸动作发生
	}
	else                       
	{
		touchInfo.flag = 0;	// 触摸标志位置0，无触摸动作
	}
}

/******************************************************************************************/

