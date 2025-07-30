
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


int getBillColor()
{
int colorNum=0;
colorNum=SensorValue[S3];
return colorNum;
}

void driveRobot(int dist, int speed)
{
	nMotorEncoder[motorA]=0;
	motor[motorA]=speed;
	while(SensorValue[S2]>=dist)
	{
		if(SensorValue[S1]==1)
		{
		//	stopEverything();
		}
  }

	motor[motorA]=0;

}


void confirmCashBoxPosition()
{
   if(SensorValue[S4]>15.5)
   {
     motor[motorC]=25;
     while(SensorValue[S4]>15.5)
     {}
   	 motor[motorC]=0;
   } else if(SensorValue[S4]<10)
   {
      motor[motorC]=-50;
     while(SensorValue[S4]<10)
     {}
   	 motor[motorC]=0;
   }

}

int getBillValue(int billColor)
{
	int storedValues[6]={5,20,10,50,0,100};
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

void manipulateBill(int direction, float armDist)
{
	nMotorEncoder[motorB]=0;
	motor[motorB] = direction*100; //max speed for max force
	while(nMotorEncoder[motorB]<armDist*145)//20 is a placeholder value
	{}
	motor[motorB]=0;
}


//pickup/release bill, positive direction brings the arm down
void armDown(int direction, float armDist)
{
	nMotorEncoder[motorB]=0;
	motor[motorB] = direction*100; //max speed for max force
	while(nMotorEncoder[motorB]<armDist*200)
	{}
	motor[motorB]=0;
}

void armUp(int direction, float armDist)
{
	nMotorEncoder[motorB]=0;
	motor[motorB] = direction*100; //max speed for max force
	while(nMotorEncoder[motorB]>armDist*200)
	{}
	motor[motorB]=0;
}


task main()
{
int testNum = 0;


}
