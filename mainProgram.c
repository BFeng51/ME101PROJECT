//SENSOR INPUTS ARE WRITTEN ASSUMING STANDARD CONFIGURATION (SUBJECT TO CHANGE)
//S4 WILL BE SHUTDOWN BUTTON (TOUCH SENSOR)
//GLOBAL VARIABLES HERE:

//configure all sensors
void configureAllSensors()
{
SensorType[S1] = sensorEV3_Touch;
SensorType[S2] = sensorEV3_Ultrasonic;
SensorType[S3] = sensorEV3_Color;
wait1Msec(50);
SensorMode[S3] = modeEV3Color_Color;
wait1Msec(50);
SensorType[S4] = sensorEV3_Gyro;
wait1Msec(50);
SensorMode[S4] = modeEV3Gyro_Calibration;
wait1Msec(50);
SensorMode[S4] = modeEV3Gyro_RateAndAngle;
wait1Msec(50);
}

//hard stop and reset
void stopEverything()
{
	motor[motorA]=-100;
	while(SensorValue[S1]!=1)
	{}
	motor[motorA]=0;
}
//HANSEN doing the function that moves the money up from the holder

//move robot given distance
void driveRobot(int dist, int speed)
{
	motor[motorA]=speed;
	while(SensorValue[S2]<=dist)
	{
		if(SensorValue[S4]==1)
		{
			stopEverything();
		}
  }

	motor[motorA]=0;

}

//reset robot to origin using touch sensor
void resetRobot(int speed)
{
	motor[motorA]=-speed;
	while(SensorValue[S1]!=1)
	{}
	motor[motorA]=0;
}

//pickup bill

//release bill


//return value of bill
int getBillValue(int billColor)
{
	int billValue=0;

	if(billColor==2)
	billValue=5;

	if(billColor==3)
	billValue=20;

	if(billColor==4)//sensor can't read purple, tentatively using yellow
	billValue=10;

	if(billColor==5)
	billValue=50;

	if(billColor==7)
	billValue=100;

return billValue;

}

//get bill value from color sensor
int getBillColor()
{
int colorNum=0;
colorNum=SensorValue[S3];
return colorNum;
}

//convert color integer to dist in cm
float getDist(int billColor)
{
float distCM=0;
	if(billColor==2)
	distCM=20;

	if(billColor==3)
	distCM=10;

	if(billColor==4)//sensor can't read purple, tentatively using yellow
	distCM=30;

	if(billColor==5)
	distCM=40;

	if(billColor==7)
	distCM=50;

return distCM;
}



task main()
configureAllSensors();
{
int totalValue=0;
int billColor, billCount = 0;
bool billsLeft=true;

while(billsLeft)
{
billColor=getBillColor();

//PICKUP BILL

nMotorEncoder[motorA]=0;

driveRobot(getDist(billColor), 50);

//RELEASE BILL

resetRobot(50);

//CHECK FOR BILLS LEFT

totalValue+=getBillValue(billColor);
billCount++;
}
displayString(0,"total value");


}
