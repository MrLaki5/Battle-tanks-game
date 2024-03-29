// Copyright Milan Lazarevic

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:

	TArray<class ASprungWheel*> GetWheels() const;

	void BeginPlay() override;

public:
	UTankTrack();

	//Sets Throttle from -1 to 1
	UFUNCTION(BlueprintCallable, Category = "Input")
		void setThrottle(float Throttle);

	void DriveTrack(float CurrentThrottle);

	//Max force per track, in Newtons (mass * acceleration)
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 10000000; //400000 = 40000kg *10cm/s2 *100 (conver cm to m)
	
};
