
class BeastAlgorithm{
	
private:
	
enum ShotType {Top_Bank=0, Top_Swish, Mid_Bank, Mid_Swish, Outlet_Pass, Layup};

//ShotType currentShotType;

float manualDistanceAdj ;

//float targetDistanceCamera;
float targetDistance;

float convOutletPassDistance;
float convManualDistanceAdj;
float convTargetDistance;

float topToMidRimHeight;
float relativeTargetHeight;

float heightToTarget;
float distanceToTarget;

float velocityCalculationNumerator;
float velocityCalculationDenominator;
float ballVelocity;
float shooterRPMCommand;
float shooterAngleCommand;

float backspinVelocity;
float backspinSpeed;
float shooterWheelSpeedTop;
float shooterWheelSpeedBot;
float shooterWheelTorque;
float shooterWheelSpeed;
float shooterWheelPower;
float maxShooterWheelPower;
float shooterPowerPercent;
float convLayupDistance;
float shooterAngleOfAttack;

//bool manualDistanceOverride;

public:
	BeastAlgorithm();
	float calculate(float targetDistanceCamera, ShotType currentShotType, bool manualDistanceOverride);
};
