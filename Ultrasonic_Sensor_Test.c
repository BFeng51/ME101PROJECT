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
task main()
{


configureAllSensors();
float distance = SensorValue[S4];
displayString(2,"%f",distance);
wait1Msec(10000);

}
