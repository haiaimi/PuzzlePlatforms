// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform(const FObjectInitializer& ObjectInitilizer) :Super(ObjectInitilizer)
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())  //��ǰ�Ƿ�Ϊ������
	{
		SetReplicates(true);     //ͬ�����ͻ���
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);     //��TargetLocation���λ��ת������������λ��
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		const FVector Location = GetActorLocation();
		//const FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);    
		const FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal(); 
		const FVector NewLocation = Location + Direction * Speed*DeltaTime;

		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (GetActorLocation() - GlobalStartLocation).Size();
		if (JourneyTravelled >= JourneyLength)
		{
			FVector swap = GlobalTargetLocation;
			GlobalTargetLocation = GlobalStartLocation;
			GlobalStartLocation = swap;
		}
		SetActorLocation(NewLocation);
	}
}

