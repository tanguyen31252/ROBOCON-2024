//----------------------------CHAY BAM THANH BANG LAZE--------------------------
void bam_thanh_laze_ngang(float angle, int maxSpeed, float robotAngle, float rototate, float angle_fix, int laze_stable_ngang, int num_stable_change, int dung_laze_nao)
{
	if(dung_laze_nao - laze_stable_ngang > num_stable_change)
	{
		robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, rototate);
	}
	else if(dung_laze_nao - laze_stable_ngang < num_stable_change)
	{
		robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, rototate);
	}
	else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
}

////////////////////////////////////////////////////////////////////////////////
void bam_thanh_laze_doc(float angle, int maxSpeed, float robotAngle, float rototate, float angle_fix, int laze_stable_doc, int num_stable_change, int dung_laze_nao)
{
	if(dung_laze_nao - laze_stable_doc > num_stable_change)
	{
		robotRunAngle(angle + angle_fix, maxSpeed, robotAngle, rototate);
	}
	else if(dung_laze_nao - laze_stable_doc < num_stable_change)
	{
		robotRunAngle(angle - angle_fix, maxSpeed, robotAngle, rototate);
	}
	else robotRunAngle(angle, maxSpeed, robotAngle, rototate);
}