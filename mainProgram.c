//GLOBAL VARIABLES HERE:
//test for hansen
int billColour = 0;

//HANSEN doing the function that moves the money up from the holder

//move robot given distance
void driveRobot(int dist, int speed)
{
	motor[motorA]=speed;
	while(SensorValue[S3]>dist)
	{}
	motor[motorA]=0;

}

//reset robot to origin (will need to be used in simutaneously with driveRobot)
void resetRobot(int speed)
{
	motor[motorA]=-speed;
	while(sensorValue[S2]!=1)
	{}
	motor[motorA]=0;
}

//pickup bill

//release bill

//count bill quantity
int getNumBills()

//Read Bill Value
void readBillValue(billColor)
{

}

//convert color integer to dist in cm
double getDist()
{

}

//hard stop and reset
void stopEverything()
{
	motor[motorA]=-100;
	while(nMotorEncoder[motorA]>0)
	{}
	motor[motorA]=0;
}

task main()
{
bool billsLeft=true;

while(billsLeft&&SensorValue[/*touchsensor*/]!=1)
{
readBillValue(billColor);

//PICKUP BILL

nMotorEncoder[motorA]=0;
driveRobot(getDistance(billColor), 50)

//RELEASE BILL

resetRobot(-50);

//IF NO BILLS LEFT, GET OUT OF THE WHILE LOOP

}
stopEverything();


}
