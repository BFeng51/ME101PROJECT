
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


void confirmCashBoxPosition()
{
   if(SensorValue[S4]>12)
   {
     motor[motorC]=10;
     while(SensorValue[S4]>12)
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
int testNum = 0;
configureAllSensors();

testNum = getBillColor();

confirmCashBoxPosition();

wait1Msec(1000);
displayString(1, "Test Number: %d", testNum);
wait1Msec(10000);

}
