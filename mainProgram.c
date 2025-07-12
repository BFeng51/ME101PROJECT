//SENSOR INPUTS ARE WRITTEN ASSUMING STANDARD CONFIGURATION (SUBJECT TO CHANGE)
//S4 WILL BE SHUTDOWN BUTTON (TOUCH SENSOR)
//GLOBAL VARIABLES HERE:


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
	while(SensorValue[S2]<=dist){}

		if(SensorValue[S4]==1)
		{
			stopEverything();
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
float getBillValue()

{
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

}



task main()
{
float totalValue=0;
int billColor, billCount = 0;
bool billsLeft=true;

while(billsLeft&&SensorValue[S4]!=1)
{
billColor=getBillColor();

//PICKUP BILL

nMotorEncoder[motorA]=0;

driveRobot(getDist(billColor), 50);

//RELEASE BILL

resetRobot(50);

if(SensorValue[S4]==1)//might not always check
{
	billsLeft=false;
}
totalValue+=
billCount++;
}



}
