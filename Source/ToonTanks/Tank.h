// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		class UCameraComponent* PlayerCamera;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Tank")
		float movementSpeed = 200.f;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Tank")
		float turnRate = 200.f;

	void Move(float value);
	void Turn(float value);
	void GetMouseCursor();
	APlayerController* PlayerControllerRef;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
