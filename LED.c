#include "LPC11XX.H"

#define LED1_ON() (LPC_GPIO2->DATA &= ~(1<<2))
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<2))


void Delay()
{
	uint16_t i,j;
	for(i=0;i<5000;i++)
		for(j=0;j<1000;j++);
}


void LedInit(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);   // 使能IO配置块时钟
	LPC_IOCON->PIO2_2 &= ~0x07;							// 
	LPC_IOCON->PIO2_2 |= 0x00;							// 配置P2.0为GPIO
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);	// 关闭IOCON配置时钟
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);		// 使能GPIO时钟
	LPC_GPIO2->DIR |= (1<<2);								// 配置P2.0为输出
	LPC_GPIO2->DATA |= (1<<2);							// 将P2.0置为高电平
}

int main()
{
	LedInit();
	while(1)
	{
		
		LED1_ON();
		Delay();
		LED1_OFF();
		Delay();
		
	}
}

