//----------------------------CHAY BAM THANH BANG LAZE--------------------------
void bam_thanh_laze_ngang(float angle, int maxSpeed, float robotAngle, float rototate, float angle_fix, int laze_stable_ngang, int num_stable_change, int dung_laze_nao)
{
	int fix;

	if(angle_fix > 0)
	{
		fix = abs(dung_laze_nao - laze_stable_ngang) * 12;
		if (fix > angle_fix)	fix = angle_fix;
	}
	else
	{
		fix = -abs(dung_laze_nao - laze_stable_ngang) * 12;
		if (fix < angle_fix)	fix = angle_fix;
	}

	if(dung_laze_nao - laze_stable_ngang > num_stable_change)
	{
		robotRunAngle(angle + fix, maxSpeed, robotAngle, rototate);
	}
	else if(dung_laze_nao - laze_stable_ngang < num_stable_change)
	{
		robotRunAngle(angle - fix, maxSpeed, robotAngle, rototate);
	}
	else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
}
////////////////////////////////////////////////////////////////////////////////
void bam_thanh_laze_doc(float angle, int maxSpeed, float robotAngle, float rototate, float angle_fix, int laze_stable_doc, int num_stable_change, int dung_laze_nao)
{
	int fix;

	fix = abs(dung_laze_nao - laze_stable_doc) * 12;

	if (fix > angle_fix)
		fix = angle_fix;

	if(dung_laze_nao - laze_stable_doc > num_stable_change)
	{
		robotRunAngle(angle + fix, maxSpeed, robotAngle, rototate);
	}
	else if(dung_laze_nao - laze_stable_doc < num_stable_change)
	{
		robotRunAngle(angle - fix, maxSpeed, robotAngle, rototate);
	}
	else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
}

void nang_xl_hot_bong()
{
	XL_TR_NONG_HA_TAT;
	XL_NONG_HA_BAT;
}