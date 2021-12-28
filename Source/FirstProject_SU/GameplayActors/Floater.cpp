// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Aura_StaticMesh"));
	
	bShouldFloat = false;

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(InitialLocation);

	StaticMesh->AddForce(FVector(1.0f, 0.0f, 0.0f));
	
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FHitResult HitResult;
		AddActorWorldOffset(InitialDirection, true, &HitResult);

		FVector HitLocation = HitResult.Location;

		UE_LOG(LogTemp, Warning, TEXT("Hit location: X = %f, Y = %f, Z = %f"),
			HitLocation.X, HitLocation.Y, HitLocation.Z);
	}
}

