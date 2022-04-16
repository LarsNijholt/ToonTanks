// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RootComponent = BaseMesh;
	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	SmokeTrail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Smoke Trail"));
	SmokeTrail->SetupAttachment(RootComponent);
	ProjectileMovementComp->InitialSpeed = 1300.f;
	ProjectileMovementComp->MaxSpeed = 1500.f;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	BaseMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	PlaySound(LaunchSound);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	auto MyOwner = GetOwner();
	if (MyOwner == nullptr) return;

	auto  MyOwnerInstigator = MyOwner->GetInstigatorController();
	auto DamegeTypeClass = UDamageType::StaticClass();

	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, MyOwnerInstigator, this, DamegeTypeClass);
		if(HitParticles) UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles, GetActorLocation(), GetActorRotation());
	}
	PlaySound(LaunchSound);
	Destroy();
}

void AProjectile::PlaySound(USoundBase* sound)
{
	UGameplayStatics::PlaySoundAtLocation(this, sound, GetActorLocation());
}