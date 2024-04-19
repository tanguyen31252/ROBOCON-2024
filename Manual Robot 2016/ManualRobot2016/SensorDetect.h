int lastSensorLeft=0, lastSensorRight=0;
char colorSensorLeft=0, colorSensorRight=0;

char cb_TTruoc=0, cb_TSau=0, cb_PTruoc=0, cb_PSau=0, countToTestSensor=0;   
char cb_TTCount=0, cb_TSCount=0, cb_PTCount=0, cb_PSCount=0;

//==============================================================================
//------------------------------------------------------------------------------
char cb_TT()
{
	return (cb_TT0 && cb_TT1);
}
//------------------------------------------------------------------------------
char cb_TS()
{
	return (cb_TS0 && cb_TS1);
}
//------------------------------------------------------------------------------
char cb_PT()
{
	return (cb_PT0 && cb_PT1);
}
//------------------------------------------------------------------------------
char cb_PS()
{
	return (cb_PS0 && cb_PS1);
}
//==============================================================================
// Line Sensor Analytics
//==============================================================================
//==============================================================================
char sensorLineDetect(int *sensor, char STruoc, char SSau)
{
	if(*sensor >= 0)
		{
			if(!STruoc && !SSau) *sensor = -1;		// o trong
		}
// 	else if(*sensor < 0)
// 	{
// 			if(STruoc && SSau)	 *sensor = 1;
// 	}
	else
		{
			if(!STruoc && SSau) *sensor = 1;
						//*sensor = 1;			// 1 trong 1 ngoai	
		}
	
	if(!STruoc && !SSau) return 2;
		else if(!STruoc && SSau) return 1;			
			else return 0;
}
//-----------------------------------------------------------------
char colorSensorDetect()
{
	const char Count = 4;

	if(!cb_TT())	cb_TTCount++;
	if(!cb_TS())	cb_TSCount++;
	if(!cb_PT())	cb_PTCount++;
	if(!cb_PS())	cb_PSCount++;

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
		colorSensorLeft = sensorLineDetect(&lastSensorLeft, cb_TTruoc, cb_TSau);
		colorSensorRight = sensorLineDetect(&lastSensorRight, cb_PTruoc, cb_PSau);
		
    return 0;
	}
	else return 1;
}
//==============================================================================
//==============================================================================
//==============================================================================

