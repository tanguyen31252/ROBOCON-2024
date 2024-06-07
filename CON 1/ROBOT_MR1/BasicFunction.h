
// void Bam_thanh_laser_trai_1800(int speed, int AngleHead, int lazer_stable_trai, int num_change_stable, int fix_max, int limit)
// {
// 	int fix = absI((lazeTraiValue - lazer_stable_trai) * 10);

// 	if (fix > 600)
// 		fix = 600;

// 	if (lazeTraiValue > limit)
// 	{
// 		if (lazeTraiValue - lazer_stable_trai > num_change_stable)
// 		{
// 			robotRunAngle(-1800 + fix, speed, AngleHead, 0.2);
// 		}
// 		else if (lazeTraiValue - lazer_stable_trai < -num_change_stable)
// 		{
// 			robotRunAngle(1800 - fix, speed, AngleHead, 0.2);
// 		}
// 		else
// 			robotRunAngle(1800, speed, AngleHead, 0.2);
// 	}
// 	else
// 			robotRunAngle(1800, speed, AngleHead, 0.2);
// }

void Bam_thanh_laser_trai(int speed, int AngleHead, int lazer_stable_trai, int num_change_stable)
{
	int fix = absI((lazeTraiValue - lazer_stable_trai) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(0, speed, AngleHead, 0.1);
	else if (lazeTraiValue < lazer_stable_trai)
		robotRunAngle(fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(-fix, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_trai_1800(int speed, int AngleHead, int lazer_stable_trai, int num_change_stable)
{
	int fix = absI((lazeTraiValue - lazer_stable_trai) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(1800, speed, AngleHead, 0.1);
	else if (lazeTraiValue > lazer_stable_trai)
		robotRunAngle(1800 + fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(1800 - fix, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_phai(int speed, int AngleHead, int lazer_stable_phai, int num_change_stable)
{
	int fix = absI((lazePhaiValue - lazer_stable_phai) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(0, speed, AngleHead, 0.1);
	else if (lazePhaiValue > lazer_stable_phai)
		robotRunAngle(fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(-fix, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_phai_1800(int speed, int AngleHead, int lazer_stable_phai, int num_change_stable)
{
	int fix = absI((lazePhaiValue - lazer_stable_phai) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(1800, speed, AngleHead, 0.1);
	else if (lazePhaiValue > lazer_stable_phai)
		robotRunAngle(1800 - fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(1800 + fix, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_truoc_900(int speed, int AngleHead, int lazer_stable_truoc, int num_change_stable)
{
	int fix = absI((lazeTruocValue - lazer_stable_truoc) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(900, speed, AngleHead, 0.1);
	else if (lazeTruocValue > lazer_stable_truoc)
		robotRunAngle(900 - fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(900 + fix, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_truoc_am_900(int speed, int AngleHead, int lazer_stable_truoc, int num_change_stable)
{
	int fix = absI((lazeTruocValue - lazer_stable_truoc) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(-900, speed, AngleHead, 0.1);
	else if (lazeTruocValue > lazer_stable_truoc)
		robotRunAngle(-900 + fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(-900 - fix, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_sau_900(int speed, int AngleHead, int lazer_stable_sau, int num_change_stable)
{
	int fix = absI((lazeSauValue - lazer_stable_sau) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(900, speed, AngleHead, 0.1);
	else if (lazeSauValue > lazer_stable_sau)
		robotRunAngle(900 + fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(900 - fix, speed, AngleHead, 0.1);
}

void Bam_thanh_laser_sau_am_900(int speed, int AngleHead, int lazer_stable_sau, int num_change_stable)
{
	int fix = absI((lazeSauValue - lazer_stable_sau) * 15);

	if (fix > 200) fix = 200;

	if(fix < num_change_stable)
		robotRunAngle(-900, speed, AngleHead, 0.1);
	else if (lazeSauValue > lazer_stable_sau)
		robotRunAngle(-900 - fix, speed, AngleHead, 0.1);
	else 
		robotRunAngle(-900 + fix, speed, AngleHead, 0.1);
}