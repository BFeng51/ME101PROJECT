/*
MOTOR A - DRIVES THE ROBOT
MOTOR B - MOVES SORTING ARM
MOTOR C - MOVES CASH BOX
*/

//GLOBAL VARIABLES HERE:
bool billsLeft=true;

//configure all sensors
void configureAllSensors()
{
SensorType[S1] = sensorEV3_Touch;
SensorType[S2] = sensorEV3_Ultrasonic;//distance to drive
SensorType[S3] = sensorEV3_Color;
wait1Msec(50);
SensorMode[S3] = modeEV3Color_Color;
wait1Msec(50);
SensorType[S4] = sensorEV3_Ultrasonic;//cash distance from top of pile
wait1Msec(50);

}

//hard stop and reset
void stopEverything()
{
	if(SensorValue[S2]<200)//placeholder value
	{
	motor[motorA]=-100;
	while(SensorValue[S2]<200)//placeholder value
	{}
	motor[motorA]=0;

	}

	if(nMotorEncoder[motorB]>0)
	{
		motor[motorB]=-100;
		while(nMotorEncoder[motorB]>0)
		{}
		motor[motorB] = 0;

	}

	if(nMotorEncoder[motorC]>0)//placeholder value
	{
		motor[motorC]=-100;
		while(nMotorEncoder[motorC]>0)
		{}
		motor[motorC]=0;
	}
billsLeft=false;

}

//drive robot given distance
void driveRobot(int dist, int speed)
{
	nMotorEncoder[motorA]=0;
	motor[motorA]=speed;
	while(SensorValue[S2]<=dist)
	{
		if(SensorValue[S1]==1)
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
	while(SensorValue[S2]>200)
	{}
	motor[motorA]=0;
}

//pickup/release bill
void manipulateBill(int direction, float armDist)
{
	nMotorEncoder[motorB]=0;
	motor[motorB] = direction*100; //max speed for max force
	while(nMotorEncoder[motorB]<armDist*20)//20 is a placeholder value
	{}
	motor[motorB]=0;
}



//return value of bill
int getBillValue(int billColor)
{
	int storedValues[6]={5,20,10,50,0,100};

	/*int billValue=0;

	if(billColor==2)
	billValue=5;

	if(billColor==3)
	billValue=20;

	if(billColor==4)//sensor can't read purple, tentatively using yellow
	billValue=10;

	if(billColor==5)
	billValue=50;

	if(billColor==7)
	billValue=100;*/

	for(int i=2; i<=7; i++)
	{

		if(i!=6)
		{
			if(billColor==i)
			{
				return storedValues[i-2];
			}
		}
	}
	return 0;

}

//get bill value from color sensor
int getBillColor()
{
int colorNum=0;
colorNum=SensorValue[S3];
return colorNum;
}

//convert color integer to dist in cm
//MIGHT END UP CONVERTING THIS TO FOR LOOP BASED ON DESIGN REVIEW FEEDBACK
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

//check if cash box is positioned high enough and adjust if necessary
void confirmCashBoxPosition()
{
   if(SensorValue[S4]>3.5)
   {
     motor[motorC]=5;
     while(SensorValue[S4]>3.5)
     {}
   	 motor[motorC]=0;
   } else if(SensorValue[S4]<3.4)
   {
      motor[motorC]=-5;
     while(SensorValue[S4]<3.4)
     {}
   	 motor[motorC]=0;
   }

}


task main()
{
configureAllSensors();

int totalValue=0;
int billColor, billCount = 0;


while(billsLeft)
{
billColor=getBillColor();

confirmCashBoxPosition();

manipulateBill(-1,1);

manipulateBill(1,0.5);


driveRobot(getDist(billColor), 50);

manipulateBill(1,1);

resetRobot(50);


if(SensorValue[S3]==0||SensorValue[S3]==1)
{
	billsLeft=false;
}

totalValue+=getBillValue(billColor);
billCount++;
}
displayString(0,"total number of bills is  %d",billCount);
displayString(1,"total value is $ %d",totalValue);
//add in hard stop message and or error


}
