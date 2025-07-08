//HANSEN doing the function that moves the money up from the holder

//move robot given distance
void driveRobot(int dist, int speed)
{
	motor[motorA]=speed;
	while(sensorValue[S3]>dist)
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

//count bills

//hard stop and reset
task main()
{



}
