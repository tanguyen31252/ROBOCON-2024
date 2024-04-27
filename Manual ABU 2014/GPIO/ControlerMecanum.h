// 4 Mecanum Robot Controler
// Created: 25/06/2013 09:00:00 PM
// Author: Huynh Cao Tuan
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//=================================================
//--------------- Cac hang so ---------------------
//=================================================
extern vs16	data_imu;

const unsigned char maxSpeed = 255;  // Toc do toi da se chinh la fixDirError + maxSpeed

const unsigned char motorLock = 2;
const unsigned int motorLockRepeat = 2000;
const float radian = 3.141592653589793238462643/180;
//=================================================
//------ Bien toan cuc de dieu khien ------
//=================================================
char _robotChange=0, _robotRotatePoint=0;
unsigned char _robotCurrentSpeed=0, _robotRunSpeed=0, _robotMaxSpeed=0;
int _robotAccStop=0, _robotCounter=0;
int _robotAngle=30000, _robotRotateAngle=0, _robotIMUInit=0;
float _robotRotate=0, _robotCurve=0;
unsigned char _accRun = 0, _accCustom = 0, _robotAngleCounterFix=0;

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
void readIMU(void)
{
		_robotIMUAngle = -data_imu;
}

//------------------------------------------------------------------------------
int robotSpeed()
{
    return _robotCurrentSpeed;
}

//==========================================================================================
//==========================================================================================
//------------------------------------------------------------------------------
int roundMe(float num)
{
	if(num < 0) return num - 0.5;
	else return num + 0.5;
}
//------------------------------------------------------------------------------
float maxMe(float N1, float N2, float N3, float N4)
{
	float _maxNum=1;
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
void calculateMotor(float rotate)
{
	float angle;

	if(_robotAngle == 30000)// khi robot quay tai cho
	{
		_robotRunFL = _robotRunFR = _robotRunRL = _robotRunRR = 0;
	}
	else // khi robot vua chay vua quay
	{
		angle = (float)(_robotAngle - (_robotIMUAngle - _robotIMUInit) - _robotRotate*30);
		angle = radian * (angle/10 + 45);

		_robotRunRR = sinf(angle)*4;
		_robotRunRL = cosf(angle)*4;

		_robotRunFL = _robotRunRR + _robotCurve;
		_robotRunFR = _robotRunRL - _robotCurve;
	}

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
					_robotRunRR -= rotate*2;
					break;
			case 2:
					_robotRunFL += rotate;
					_robotRunRL += rotate*2;
					_robotRunRR -= rotate;
					break;
			case 3:
					_robotRunFL += rotate;
					_robotRunFR -= rotate*2;
					_robotRunRR -= rotate;
					break;
			case 4:
					_robotRunFL += rotate*2;
					_robotRunFR -= rotate;
					_robotRunRL += rotate;
					break;
		}
	//----------- tinh toc do toi da ----------------
	_robotMaxSpeed = (int)(maxSpeed/maxMe(_robotRunFL, _robotRunFR, _robotRunRL, _robotRunRR));
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
void robotSetACC(unsigned char N)
{
    _accCustom=N;
}
//------------------------------------------------------------------------------
char robotIsRun()
{
    return (_robotAngle == 30000)? 0: 1;
}
//------------------------------------------------------------------------------
void robotRun(int angle, unsigned char maxSpeed, float curve)
{
    if(_robotAngle != angle || _robotRunSpeed != maxSpeed || _robotCurve != curve)
    {
        _accRun = (_accCustom? _accCustom: 32);
        _robotRunSpeed = maxSpeed;

        _robotIMUInit = _robotIMUAngle;
        _robotCurve = curve;
        _robotAngle = angle;
        _robotCounter = 0;

        calculateMotor(_robotRotate);
    }
}
//------------------------------------------------------------------------------
char robotRotate(int rotateAngle, float rotate, char rotatePoint)
{
    //--------------------------------------------
    if(_robotAngleCounterFix > 0)
    {
        if(!_robotRotate)
        {
            _robotRunSpeed = 5;
        	_robotCurrentSpeed = 3;
         	_accRun = 1;
	
	        if(_robotIMUAngle > rotateAngle) _robotRotate = -1;
	        else _robotRotate = 1;
        }
        else if(_robotAngleCounterFix++ > 25)
            {
                robotStop(0);
                return 0;
            }
    }
    //--------------------------------------------
    if(_robotRotateAngle != rotateAngle || _robotRotatePoint != rotatePoint)
    {
        if(_robotAngle == 30000)
        {
            _robotRunSpeed = 60;
            _robotCurrentSpeed = 3;
            _accRun = (_accCustom? _accCustom: 35);

            if(rotateAngle < 30000 && ((rotate > 0 && _robotIMUAngle > rotateAngle) || (rotate < 0 && _robotIMUAngle < rotateAngle ))) rotate = - rotate;
        }

        _robotRotateAngle = rotateAngle;
        _robotRotatePoint = rotatePoint;
        _robotRotate = rotate;
        _robotCounter = 0;

        _robotAngleCounterFix = 0;

        calculateMotor(_robotRotate);
    }
    //--------------------------------------------
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
            if((_robotRotate > 0 && _robotIMUAngle > _robotRotateAngle - ( _robotCurrentSpeed*_robotRotate*3 + 100)) ||
               (_robotRotate < 0 && _robotIMUAngle < _robotRotateAngle + (-_robotCurrentSpeed*_robotRotate*3 + 100)))
            {
                // Khi dung goc thi dung robot, khoa banh xe, va bat dau Fix Angle
                if(_robotRotateAngle - 10 < _robotIMUAngle && _robotIMUAngle < _robotRotateAngle + 10)
                {
                	_robotCurrentSpeed = 0;
                    _robotRotate = 0;
                    calculateMotor(0);

                    _robotAngleCounterFix = 1;
                    return;
                }
                _robotCurrentSpeed = 10;
                //------------------------------------------
                calculateMotor(((_robotRotateAngle > _robotIMUAngle)?1:-1)*fmin((5 + abs(_robotRotateAngle - _robotIMUAngle)/(float)50),10)/_robotCurrentSpeed);
            }else calculateMotor(_robotRotate);
        }
        else
        {// Vua chay thang vua xoay
            if((_robotRotate > 0 && _robotIMUAngle > _robotRotateAngle - ( _robotCurrentSpeed*_robotRotate*3 + 50)) ||
               (_robotRotate < 0 && _robotIMUAngle < _robotRotateAngle + (-_robotCurrentSpeed*_robotRotate*3 + 50)))
            {
                calculateMotor((_robotRotateAngle - _robotIMUAngle)/(float)10/_robotCurrentSpeed);
            }
            else calculateMotor(_robotRotate);//---- Neu chua dat den goc can quay ----------
        }
        return;
    }

    // Khi chay thang
    calculateMotor(0.005*(_robotIMUInit - _robotIMUAngle));
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
void ac_SpeedACC(int acc, char n)
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
	readIMU();
    //======= Gia toc di chuyen ==========
    if(_robotRunSpeed > 0)// Robot dang duoc ra lenh chay
    {
        if(_robotCurrentSpeed != _robotRunSpeed)
        {
            if(_robotCurrentSpeed < _robotRunSpeed)
            {
            	if(_robotCurrentSpeed < _robotMaxSpeed) ac_SpeedACC(_accRun - _robotCurrentSpeed, 1); //--- Phuong trinh Gia toc --------	
            }
			else ac_SpeedACC(1, -1); //--- Phuong trinh Giam toc --------
        }
    }
    else  //-------- Robot duoc lenh Stop -----------
        if(_robotCurrentSpeed > 0) ac_SpeedACC(_robotAccStop, -1); //-------- Giam toc do -----------
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
    if(_robotChange) setMotor(roundMe(_robotCurrentSpeed * _robotRunFL), roundMe(_robotCurrentSpeed * _robotRunFR), roundMe(_robotCurrentSpeed * _robotRunRL), roundMe(_robotCurrentSpeed * _robotRunRR));
}
//==========================================================================================
//==========================================================================================
//==========================================================================================
