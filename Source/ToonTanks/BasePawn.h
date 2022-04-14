// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float speed = 10.f;

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();

private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		class UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		USceneComponent* BulletSpawnPoint;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		TSubclassOf<class AProjectile> ProjectileClass;
};
