void bam_thanh_laze_ngang(float angle, int maxSpeed, float robotAngle, float rotate, float angle_fix, int laze_stable_ngang, int num_stable_change)
{
	if(NUT_CHUYEN_SAN == 1)
	{
		if(laze_4H_Value - laze_stable_ngang > num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, rotate);
		}
		else if(laze_4H_Value - laze_stable_ngang < num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, rotate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rotate);
	}
	else
	{
		if(laze_8H_Value - laze_stable_ngang > num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, rotate);
		}
		else if(laze_8H_Value - laze_stable_ngang < num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, rotate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rotate);
	}
}

void bam_thanh_laze_doc(float angle, int maxSpeed, float robotAngle, float rotate, float angle_fix, int laze_stable_sau, int num_stable_change)
{
	if(NUT_CHUYEN_SAN == 1)
	{
		if(laze_0H_Value - laze_stable_sau > num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, rotate);
		}
		else if(laze_0H_Value - laze_stable_sau < num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, rotate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rotate);
	}
	else
	{
		if(laze_0H_Value - laze_stable_sau > num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, rotate);
		}
		else if(laze_0H_Value - laze_stable_sau < num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, rotate);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, rotate);
	}
}