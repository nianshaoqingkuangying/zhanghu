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
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);   // ʹ��IO���ÿ�ʱ��
	LPC_IOCON->PIO2_2 &= ~0x07;							// 
	LPC_IOCON->PIO2_2 |= 0x00;							// ����P2.0ΪGPIO
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);	// �ر�IOCON����ʱ��
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);		// ʹ��GPIOʱ��
	LPC_GPIO2->DIR |= (1<<2);								// ����P2.0Ϊ���
	LPC_GPIO2->DATA |= (1<<2);							// ��P2.0��Ϊ�ߵ�ƽ
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

