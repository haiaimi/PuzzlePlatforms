// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_UCLASS_BODY()
	
	
public:
	virtual void Tick(float DeltaTime)override;

protected:
	virtual void BeginPlay()override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(MakeEditWidget = true))
	FVector TargetLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector GlobalStartLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector GlobalTargetLocation;
};
