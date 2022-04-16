// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Components")
		class UProjectileMovementComponent* ProjectileMovementComp;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"), Category = "Combat")
		float BaseDamage = 10.f;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UPROPERTY(EditAnywhere, Category = "Combat")
		class UParticleSystem* HitParticles;
	UPROPERTY(VisibleAnywhere, Category = "Combat")
		class UParticleSystemComponent* SmokeTrail;
	UPROPERTY(EditAnywhere, Category = "Combat")
		class USoundBase* LaunchSound;
	UPROPERTY(EditAnywhere, Category = "Combat")
		USoundBase* HitSound;
	UFUNCTION()
		void PlaySound(USoundBase* sound);
};
