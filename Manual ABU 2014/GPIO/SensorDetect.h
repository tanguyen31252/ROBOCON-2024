int lastSensorLeft=0, lastSensorRight=0;
char colorSensorLeft=0, colorSensorRight=0;

char cb_TTruoc=0, cb_TSau=0, cb_PTruoc=0, cb_PSau=0, countToTestSensor=0;
char cb_TTCount=0, cb_TSCount=0, cb_PTCount=0, cb_PSCount=0;

vu8 wantExit(void);
//==============================================================================
//------------------------------------------------------------------------------
char cb_TT()
{
	int M = 0;
	if(cb_TT0) M++;
	if(cb_TT1) M++;
	if(cb_TT2) M++;
	return M > 1;
}
//------------------------------------------------------------------------------
char cb_TS()
{
	int M = 0;
	if(cb_TS0) M++;
	if(cb_TS1) M++;
	if(cb_TS2) M++;
	return M > 1;
}
//------------------------------------------------------------------------------
char cb_PT()
{
	int M = 0;
	if(cb_PT0) M++;
	if(cb_PT1) M++;
	if(cb_PT2) M++;
	return M > 1;
}
//------------------------------------------------------------------------------
char cb_PS()
{
	int M = 0;
	if(cb_PS0) M++;
	if(cb_PS1) M++;
	if(cb_PS2) M++;
	return M > 1;
}
//==============================================================================
// Line Sensor Analytics
//==============================================================================
//==============================================================================
//-------------- Neu la 2 vung giong nhau cach nhau boi line -------------------
char sensorDetectXXXXX(int *sensor, char STruoc, char SSau)
{
	if(*sensor >= 0)
	{
		if((STruoc && !SSau) || (!STruoc && !SSau)) *sensor= -1;
	}else{
		if((!STruoc && SSau) || (!STruoc && !SSau)) *sensor= 1;
	}

	if(!STruoc || !SSau) return 1;
	else return 0;
}
//==============================================================================
//--------------------- Neu la 2 vung mau phan biet -------------------------
char sensorDetect(int *sensor, char STruoc, char SSau)
{
	if(STruoc && SSau)
	{
		*sensor = 1;
		return 0;	
	}

	if(!STruoc && !SSau)
	{
		*sensor = -1;
		return 0;
	}
	return 1;
}
//-----------------------------------------------------------------
char colorSensorDetect()
{
	const char Count = 3;

	if(!cb_TT())cb_TTCount++;
	if(!cb_TS())cb_TSCount++;
	if(!cb_PT())cb_PTCount++;
	if(!cb_PS())cb_PSCount++;

	if(++countToTestSensor > Count)
	{
		if(cb_TTCount >= Count)	cb_TTruoc=0;
		else 					cb_TTruoc=1;

		if(cb_TSCount >= Count)	cb_TSau=0;
		else 					cb_TSau=1;

		if(cb_PTCount >= Count) cb_PTruoc=0;
		else 					cb_PTruoc=1;

		if(cb_PSCount >= Count) cb_PSau=0;
		else 					cb_PSau=1;

		countToTestSensor =0;
		cb_TTCount = 0;
		cb_TSCount = 0;
		cb_PTCount = 0;
		cb_PSCount = 0;
		//----------------------------------------------------------------------
		colorSensorLeft = sensorDetect(&lastSensorLeft, cb_TTruoc, cb_TSau);
		colorSensorRight = sensorDetect(&lastSensorRight, cb_PTruoc, cb_PSau);

		return 0;
	}
	else return 1;
}
//==============================================================================
//==============================================================================
//==============================================================================

int robotLineDetect(unsigned int speed)
{
    int vitri=0;
	do{
		robotRun(0, speed); // toc do chay den line
		do{
			if(!cb_TTruoc || !cb_TSau) vitri=1;
			else if(!cb_PTruoc || !cb_PSau) vitri=2;
			else vitri=0;
			if(wantExit()) return 0;
		}while(vitri==0);

		robotStop(0);
		delay_ms(10);

		if(!cb_TTruoc || !cb_TSau) vitri=1;
		else if(!cb_PTruoc || !cb_PSau) vitri=2;
		else vitri=0;
		if(wantExit()) return 0;
	}while(vitri==0);

    if(vitri==2)// ben Trai sai
    {
        robotRotateFree(0.5, 2);
        while(cb_TTruoc && cb_TSau) if(wantExit()) return 0;
    }
    else // ben Phai sai
    {
        robotRotateFree(-0.5, 1);
        while(cb_PTruoc && cb_PSau)if(wantExit()) return 0;
    }

    robotStop(0);
    return 1;
}
//==============================================================================
//==============================================================================

void robotLineRun(int angle, int maxSP)
{
		float _S1 = 10 , _R1 = 1;
		float _S2 = 200, _R2 = 65;
		float _A=(_R2-_R1)/(_S2-_S1), _B=(_R1*_S2-_S1*_R2)/(_S2-_S1);
    int k = (angle>0? -1:1);		
	
		float hesoXoayNhieu= k*0.35;
		float hesoXoayIt= k*0.15;

    float hesoCungTron;

	if(robotSpeed() != 0) hesoCungTron = k*(float)(robotSpeed()*_A + _B)/robotSpeed();

	if(colorSensorLeft && colorSensorRight)// dang o dung vi tri, chay theo Line
	{
		robotCurve(angle, maxSP , hesoCungTron);
	}
	else// dang sai vi tri
	{		
		if(!colorSensorLeft && colorSensorRight)// ben Trai sai
		{
			if(lastSensorLeft >= 0)
			{
				robotCurve(angle + k*40, maxSP , (angle > 0?hesoXoayIt:hesoXoayNhieu));// Dang o ngoai
			}
			else
			{
				robotCurve(angle - k*40, maxSP , (angle > 0?hesoXoayNhieu:hesoXoayIt));// Dang o trong
			}
		}
		else
		{
			if(colorSensorLeft && !colorSensorRight)// ben Phai sai
    		{
		    	if(lastSensorRight >= 0)
				{
					robotCurve(angle + k*40, maxSP , (angle > 0?hesoXoayNhieu:hesoXoayIt));// Dang o ngoai
			    }
				else
				{
					robotCurve(angle - k*40, maxSP , (angle > 0?hesoXoayIt:hesoXoayNhieu));// Dang o trong
    			}
			}
			else // Ca hai dieu sai
			{
				if(lastSensorLeft >= 0 && lastSensorRight >= 0)// 2 Dang o ngoai
				{ 
					robotCurve(angle + k*60, maxSP, hesoCungTron);
				}
				else
				{
					if(lastSensorLeft < 0 && lastSensorRight < 0)// 2 Dang o trong
					{ 
						robotCurve(angle - k*60, maxSP, hesoCungTron);
					}
					else // 1 trong 1 ngoai
					{ 					
						if(lastSensorLeft >= 0)// ben trai o ngoai
							robotCurve(angle - k*40, maxSP, (angle>0?-hesoXoayIt:hesoXoayNhieu));
						else
							robotCurve(angle + k*40, maxSP, (angle>0?hesoXoayNhieu:-hesoXoayIt));
					}
				}
			}		
		}
	}
}

//==============================================================================
//==============================================================================
//==============================================================================
void robotLineRun_clockwise111(int angle, int maxSP)
{
		int		a;
		float _S1 = 10 , _R1 = 10;
		float _S2 = 100, _R2 = 70;
		float _A=(_R2-_R1)/(_S2-_S1), _B=(_R1*_S2-_S1*_R2)/(_S2-_S1);
		float hesoXoayVo= 0.15;
		float hesoXoayRa= 0.25;

    int k = (angle>0 ? -1:1);
    float hesoCungTron;

	if(robotSpeed() != 0) hesoCungTron = (float)(robotSpeed()*_A + _B)/robotSpeed();

	if(colorSensorLeft && colorSensorRight)// dang o dung vi tri, chay theo Line
	{
		robotCurve(angle, maxSP , k*hesoCungTron);
		lcd_printInt(3,10,a);	
	}
	else// dang sai vi tri
	{		
		if(!colorSensorLeft && colorSensorRight)// ben Trai sai
		{
			if(lastSensorLeft >= 0)
			{
				lcd_printInt(3,10,1);
				robotCurve(angle + k*40, maxSP , k*hesoXoayRa);// Dang o ngoai
			}
			else
			{
				lcd_printInt(3,10,2);
				robotCurve(angle - k*40, maxSP , k*hesoXoayVo);// Dang o trong
			}
		}
		else
		{
			if(colorSensorLeft && !colorSensorRight)// ben Phai sai
    		{
		    	if(lastSensorRight >= 0)
				{
					lcd_printInt(3,10,3);
					robotCurve(angle + k*40, maxSP , k*hesoXoayVo);// Dang o ngoai
			  	}
				else
				{
					lcd_printInt(3,10,4);
					robotCurve(angle - k*40, maxSP , k*hesoXoayRa);// Dang o trong
    		}
			}
			else // Ca hai dieu sai
			{
				if(lastSensorLeft >= 0 && lastSensorRight >= 0)// 2 Dang o ngoai
				{ 
					lcd_printInt(3,10,5);
					robotCurve(angle + k*60, maxSP, k*hesoCungTron);
				}
				else
				{
					if(lastSensorLeft < 0 && lastSensorRight < 0)// 2 Dang o trong
					{ 
						lcd_printInt(3,10,6);
						robotCurve(angle - k*60, maxSP, k*hesoCungTron);
					}
					else // 1 trong 1 ngoai
					{ 					
						if(lastSensorLeft >= 0)// ben trai o ngoai
						{
							robotCurve(angle - k*40, maxSP, hesoXoayVo);
							lcd_printInt(3,10,7);
						}
						else
						{
							robotCurve(angle + k*40, maxSP, (angle>0?hesoXoayVo:-hesoXoayRa));
							lcd_printInt(3,10,8);
						}
					}
				}
			}		
		}
	}
}

