// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "../Public/TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	// TODO clamp actual throttle value
	auto ForceApllied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApllied, ForceLocation);
}
