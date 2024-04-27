/*
//================================================
* 4 Omni Robot Controler
* Created: 09/06/2014 12:30:00
* Author: Huynh Cao Tuan
//================================================

	void robotAnalytics(void) // Dat trong timer de Robot hoat dong
	//----------------------
	void robotRun(int angle, int maxSpeed)
	void robotCurve(int angle, int maxSpeed, float curve)
	
	vidu: robotRun(450, 70)
			Chay Robot huong:	450
			Toc do toi da: 		70
	
	//----------------------
	void robotRotateFree(float rotate, int rotatePoint)
	void robotRotate(int rotateAngle, float rotate, int rotatePoint)
	int robotFixAngle()

	vidu: robotRotate(0.5, 0)
			Quay robot tu do:		30000 	{Neu nho hon thi nghia la quay den goc do thi Stop}
			Huong va ty le quay: 	0.5
			Tam quay :				0 		{0 : tam robot, 1: banh truoc trai...,2,3, 4: Banh sau phai}
	

	//----------------------
	void robotSetACC(int N)			// Thiet lap gia toc
	void robotStop(int acc) 		// Stop tat ca
	void robotRotateStop(int acc) 	// Stop xoay
	
	//----------------------
	int robotIsRun() 		// Kiem tra ro bot co dang chay hay khong
	int robotAngle()  		// Tra ve gia tri hien tai cua La ban
	int robotSpeed()  		//Toc do hien tai cua robot
*/

#include <stdlib.h>
#include <math.h>

extern vs16	data_imu;

//=================================================
//--------------- Cac hang so ---------------------
//=================================================
int maxSpeed = 255;  // Toc do toi da se chinh la fixDirError + maxSpeed
float f0005 = 0.005, f05 = 0.5, f2 = 2.0, f4 = 4.0, f5 = 5.0, f10 = 10.0, f30 = 30.0, f45 = 45.0;
int i100 = 100, i3 = 3;
//------------ su dung cho ham gia toc bac 2 ---------------------
//float _A = 0.23, _B= 4.88, _C= 3.9, _D= -13.95, _E= 411.16, _M= 5972.07;
//------------ su dung cho ham gia toc bac 1 tuyen tinh--------------
float _Y = 12;
float _X = 200;

int motorLock = 2;
int motorLockRepeat = 1000;
float radian = 3.141592653589793238462643/180;
//=================================================
//------ Bien toan cuc de dieu khien ------
//=================================================
int _robotChange=0, _robotRotatePoint=0;
int _robotCurrentSpeed=0, _robotRunSpeed=0, _robotMaxSpeed=0;
int _robotAccStop=0, _robotCounter=0;
int _robotAngle=30000, _robotRotateAngle=0, _robotIMUInit=0;
float _robotRotate=0, _robotCurve=0;
int _accRun = 0, _accCustom = 0, _robotAngleCounterFix=0;

int _robotIMUAngle=0, _IMUAngle_Before=0;
float _robotRunFL=0, _robotRunFR=0, _robotRunRL=0, _robotRunRR=0;


//==========================================================================================
//==========================================================================================
//==========================================================================================
void setMotor(int speed_FL, int speed_FR, int speed_RL, int speed_RR)
{
	if(!speed_FL) mor_FrontLeft = motorLock;
	else if(speed_FL > 0)
 	{
	 	mor_FrontLeft = speed_FL;
		mor_FrontLeft_next;
 	}else{
		mor_FrontLeft = -speed_FL;
		mor_FrontLeft_back;
 	}

	if(!speed_FR) mor_FrontRight = motorLock;
	else if(speed_FR > 0)
 	{
	 	mor_FrontRight = speed_FR;
		mor_FrontRight_next;
 	}else{
		mor_FrontRight = -speed_FR;
		mor_FrontRight_back;
 	}

	if(!speed_RL) mor_RearLeft = motorLock;
	else if(speed_RL > 0)
 	{
	 	mor_RearLeft = speed_RL;
		mor_RearLeft_next;
 	}else{
		mor_RearLeft = -speed_RL;
		mor_RearLeft_back;
 	}

 	if(!speed_RR) mor_RearRight = motorLock;
	else if(speed_RR > 0)
 	{
	 	mor_RearRight = speed_RR;
		mor_RearRight_next;
 	}else{
		mor_RearRight = -speed_RR;
		mor_RearRight_back;
 	}
}
//------------------------------------------------------------------------------
void setAllMotor(int speed)
{
	mor_FrontLeft = speed;
	mor_FrontRight = speed;
	mor_RearLeft = speed;
	mor_RearRight = speed;
}
//------------------------------------------------------------------------------
vs32 robotAngle(void)
{
	return -data_imu;
}
//------------------------------------------------------------------------------
//==========================================================================================
//------------------------------------------------------------------------------
int roundF(float num)
{
	if(num < 0) return num - f05;
	else return num + f05;
}
//------------------------------------------------------------------------------
int absI(int num)
{
	if(num >= 0) return num;
	else return -num;
}
//------------------------------------------------------------------------------
int giaToc(int x)
{
	// ------ gia toc bac 2 -----------
	//float b = ((float)_B*x + _E);
	//float y = (-b + sqrtf(b*b - f4*_C*((float)_A*x*x + (float)_D*x - _M)))/(f2*_C);
	// ------ gia toc bac 1 -----------
	float y = (-_Y/_X)*x + _Y;
	
	return (int)y;
}
//------------------------------------------------------------------------------
float maxF4(float N1, float N2, float N3, float N4)
{
	float _maxNum = 0.1;
	if(N1<0) N1 = -N1;
	if(N2<0) N2 = -N2;
	if(N3<0) N3 = -N3;
	if(N4<0) N4 = -N4;

	if(N1>_maxNum) _maxNum = N1;
	if(N2>_maxNum) _maxNum = N2;
	if(N3>_maxNum) _maxNum = N3;
	if(N4>_maxNum) _maxNum = N4;

	return _maxNum;
}
//------------------------------------------------------------------------------
int robotIsRun()
{
    return (_robotAngle == 30000)? 0: 1;
}
//------------------------------------------------------------------------------
int robotSpeed()
{
    return _robotCurrentSpeed;
}
//------------------------------------------------------------------------------
//==========================================================================================
//------------------------------------------------------------------------------
void calculateMotor(float rotate)
{
	float angle;

	if(_robotAngle == 30000)// khi robot quay tai cho
	{
		_robotRunFL = _robotRunFR = _robotRunRL = _robotRunRR = 0;
	}
	else // khi robot vua chay vua quay
	{
		angle = (float)(_robotAngle - (_robotIMUAngle - _robotIMUInit) - _robotRotate * f30);
		angle = radian * (angle/f10 + f45);

		_robotRunRR = sinf(angle);
		_robotRunRL = cosf(angle);

		_robotRunFL = _robotRunRR + _robotCurve;
		_robotRunFR = _robotRunRL - _robotCurve;
	}

	if(rotate){
		switch(_robotRotatePoint)
		{
			case 0:
					_robotRunFL += rotate;
					_robotRunFR -= rotate;
					_robotRunRL += rotate;
					_robotRunRR -= rotate;
					break;
			case 1:
					_robotRunFR -= rotate;
					_robotRunRL += rotate;
					_robotRunRR -= rotate*f2;
					break;
			case 2:
					_robotRunFL += rotate;
					_robotRunRL += rotate*f2;
					_robotRunRR -= rotate;
					break;
			case 3:
					_robotRunFL += rotate;
					_robotRunFR -= rotate*f2;
					_robotRunRR -= rotate;
					break;
			case 4:
					_robotRunFL += rotate*f2;
					_robotRunFR -= rotate;
					_robotRunRL += rotate;
					break;
		}
	}

	//----------- tinh toc do toi da ----------------
	_robotMaxSpeed = (int)(maxSpeed/maxF4(_robotRunFL, _robotRunFR, _robotRunRL, _robotRunRR));
    if(_robotCurrentSpeed > _robotMaxSpeed) _robotCurrentSpeed = _robotMaxSpeed;
	//------------------------------------------------
	_robotChange = 1;
}
//------------------------------------------------------------------------------
void robotStop(unsigned int acc)
{
	_robotRunSpeed = 0;
	_robotAccStop = acc;

    if(!acc){
        _robotCurrentSpeed = 0;
	    _robotCurve = 0;
		_robotAngle = 30000;

		_robotRotate = 0;
	    _robotRotatePoint = 0;
	    _robotRotateAngle = 0;
		_robotAngleCounterFix = 0;
        _accCustom = 0;

		calculateMotor(0);
    }
}
//------------------------------------------------------------------------------
void robotRotateStop()
{
	if(_robotRotate || _robotRotatePoint || _robotRotateAngle)
    {
        _robotRotate = 0;
        _robotRotatePoint = 0;
        _robotRotateAngle = 0;
        _robotAngleCounterFix = 0;

        _robotIMUInit = _robotIMUAngle;

        calculateMotor(_robotRotate);
    }
}
//------------------------------------------------------------------------------
void robotSetACC(int N)
{
    _accCustom=N;
}
//------------------------------------------------------------------------------
void robotCurve(int angle, int maxSpeed, float curve)
{
    if(_robotAngle != angle || _robotRunSpeed != maxSpeed || _robotCurve != curve)
    {
        _accRun = (_accCustom? _accCustom: 10);
        _robotRunSpeed = maxSpeed;

        _robotIMUInit = _robotIMUAngle;
        _robotCurve = curve;
        _robotAngle = angle;
        _robotCounter = 0;

        calculateMotor(_robotRotate);
    }
}
//------------------------------------------------------------------------------
void robotRun(int angle, int maxSpeed)
{
	robotCurve(angle, maxSpeed, 0);
}
//------------------------------------------------------------------------------
void robotRotate(int rotateAngle, float rotate, int rotatePoint)
{
    if(_robotRotateAngle != rotateAngle || _robotRotate != rotate || _robotRotatePoint != rotatePoint)
    {
        if(_robotAngle == 30000)
        {
            _robotRunSpeed = 50;
            _robotCurrentSpeed = 3;
            _accRun = (_accCustom? _accCustom: 10);

            if(rotateAngle < 30000 && ((rotate > 0 && _robotIMUAngle > rotateAngle) || (rotate < 0 && _robotIMUAngle < rotateAngle ))) rotate = - rotate;
        }

        _robotRotateAngle = rotateAngle;
        _robotRotatePoint = rotatePoint;
        _robotRotate = rotate;
        _robotCounter = 0;

        _robotAngleCounterFix = 0;

        calculateMotor(_robotRotate);
    }
}
//------------------------------------------------------------------------------
void robotRotateFree(float rotate, int rotatePoint)
{
	robotRotate(30000, rotate, rotatePoint);
}
//------------------------------------------------------------------------------
int robotFixAngle()
{
    if(_robotAngleCounterFix > 0)
    {
    	if(absI(_robotRotateAngle - _robotIMUAngle) < 5){
	    	if(_robotAngleCounterFix++ > 100)
            {
                robotStop(0);
                return 0;
            }
	    }else{
            _robotRunSpeed = 5;
        	_robotCurrentSpeed = 3;
         	_accRun = 10;
	
	        if(_robotIMUAngle > _robotRotateAngle) _robotRotate = -1;
	        else _robotRotate = 1;
    	}
    }
    return 1;
}
//-----------------------------------------------------------------
void robotDirectionAnalytics()
{
    // Khi chay duong cong hoac khong chay hoac quay tu do thi thoat
    if(_robotCurve || !_robotCurrentSpeed || _robotRotateAngle >= 30000) return;
    // Khi co lenh xoay
    if(_robotRotate)
    {
        // Khi chi xoay tai cho
        if(_robotAngle == 30000)
        {
            if((_robotRotate > 0 && _robotIMUAngle > _robotRotateAngle - _robotCurrentSpeed*_robotRotate - i100) ||
               (_robotRotate < 0 && _robotIMUAngle < _robotRotateAngle - _robotCurrentSpeed*_robotRotate + i100))
            {
                // Khi dung goc thi dung robot, khoa banh xe, va bat dau Fix Angle
                if(absI(_robotRotateAngle - _robotIMUAngle) < 5)
                {
                	_robotCurrentSpeed = 0;
                    _robotRotate = 0;
                    _robotAngleCounterFix = 1;
                    calculateMotor(0);
                    
                    return;
                }else{
                	if(_robotRotateAngle > _robotIMUAngle)
	                	calculateMotor((float)(f5 + (int)(absI(_robotRotateAngle - _robotIMUAngle)/f10))/_robotCurrentSpeed);
	                else
	                	calculateMotor(-(float)(f5 + (int)(absI(_robotRotateAngle - _robotIMUAngle)/f10))/_robotCurrentSpeed);
                }
            }else calculateMotor(_robotRotate);
        }
        else
        {// Vua chay thang vua xoay
            if((_robotRotate > 0 && _robotIMUAngle > _robotRotateAngle - _robotCurrentSpeed*_robotRotate - i100) ||
               (_robotRotate < 0 && _robotIMUAngle < _robotRotateAngle - _robotCurrentSpeed*_robotRotate + i100))
            {
            	if(_robotRotateAngle > _robotIMUAngle)
	   				calculateMotor(absI(_robotRotateAngle - _robotIMUAngle)/f10/_robotCurrentSpeed);
	   			else
				   	calculateMotor(-absI(_robotRotateAngle - _robotIMUAngle)/f10/_robotCurrentSpeed);
            }
            else calculateMotor(_robotRotate);//---- Neu chua dat den goc can quay ----------
        }
        
        return;
    }

    // Khi chay thang
    calculateMotor(f0005 * (_robotIMUInit - _robotIMUAngle));
}

//==========================================================================================
void ac_Stop(void)
{
	_robotCurve = 0;
    _robotRotate = 0;
    _robotRotatePoint = 0;
    _robotAngle = 30000;
    _robotRotateAngle = 0;
    _robotAngleCounterFix = 0;
    _accCustom=0;
    
	if(++_robotCounter < motorLockRepeat) setAllMotor(motorLock);
	else {
		_robotCounter = motorLockRepeat;
		setAllMotor(0);
	}
}
//------------------------------------------------------------------------------
void ac_SpeedACC(int acc, int n)
{
	if(++_robotCounter > acc)
    {
        _robotCurrentSpeed += n;
        _robotCounter = 0;
    }
}
//------------------------------------------------------------------------------
void robotAnalytics(void)//-------- Dat trong Interup Timer ---------
{
	_robotIMUAngle = robotAngle();
    //======= Gia toc di chuyen ==========
    if(_robotRunSpeed > 0)// Robot dang duoc ra lenh chay
    {
        if(_robotCurrentSpeed != _robotRunSpeed)
        {
            if(_robotCurrentSpeed < _robotRunSpeed)
            {
            	if(_robotCurrentSpeed < _robotMaxSpeed) ac_SpeedACC(giaToc(_robotCurrentSpeed), 1); //--- Phuong trinh Gia toc --------	
            }
			else ac_SpeedACC(0, -1); //--- Phuong trinh Giam toc --------
        }
    }
    else  //-------- Robot duoc lenh Stop -----------
        if(_robotCurrentSpeed > 0) ac_SpeedACC(_robotAccStop, -4); //-------- Giam toc do -----------
		else{
			ac_Stop();
			return;
		}
	
	//======= Fix robot theo IMU ==========
    if(_IMUAngle_Before != _robotIMUAngle)
    {
        robotDirectionAnalytics();
        _IMUAngle_Before = _robotIMUAngle;
    }

    //======= Thiet lap thong so dong co ==========
    if(_robotChange) setMotor(roundF(_robotCurrentSpeed * _robotRunFL), roundF(_robotCurrentSpeed * _robotRunFR), roundF(_robotCurrentSpeed * _robotRunRL), roundF(_robotCurrentSpeed * _robotRunRR));
}

//==========================================================================================
//==========================================================================================
//==========================================================================================
