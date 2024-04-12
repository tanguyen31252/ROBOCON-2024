void bam_thanh_laze_ngang(float angle, int maxSpeed, float robotAngle, float angle_fix, int laze_stable_ngang, int num_stable_change)
{
	if(NUT_CHUYEN_SAN == 1)
	{
		if(lazeNgangDoValue - laze_stable_ngang > num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else if(lazeNgangDoValue - laze_stable_ngang < num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, 0.2);
	}
	else
	{
		if(lazeNgangXanhValue - laze_stable_ngang > num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else if(lazeNgangXanhValue - laze_stable_ngang < num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, 0.2);
	}
}

void bam_thanh_laze_doc(float angle, int maxSpeed, float robotAngle, float angle_fix, int laze_stable_sau, int num_stable_change)
{
	if(NUT_CHUYEN_SAN == 1)
	{
		if(lazeSauValue - laze_stable_sau > num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else if(lazeSauValue - laze_stable_sau < num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, 0.2);
	}
	else
	{
		if(lazeSauValue - laze_stable_sau > num_stable_change)
		{
			robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else if(lazeSauValue - laze_stable_sau < num_stable_change)
		{
			robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, 0.2);
		}
		else robotRunAngle(angle, maxSpeed, robotAngle, 0.2);
	}
}