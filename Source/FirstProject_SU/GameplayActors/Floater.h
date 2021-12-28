// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class FIRSTPROJECT_SU_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category ="Aura_StaticMesh")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditInstanceOnly,BlueprintReadWrite,Category = "Aura_FloaterVariables")
	FVector InitialLocation;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Aura_FloaterVariables")
	FVector InitialDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aura_FloaterVariables")
	bool bShouldFloat;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
