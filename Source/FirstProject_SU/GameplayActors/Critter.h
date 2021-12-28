// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Critter.generated.h"

UCLASS()
class FIRSTPROJECT_SU_API ACritter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACritter();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Aura_CritterVariables")
	USkeletalMeshComponent* CritterMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Aura_CritterVariables")
    class UCameraComponent* CritterCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Aura_CritterVariables")
	class USpringArmComponent* CritterSpringArm;

	UPROPERTY(VisibleAnywhere,Category = "Aura_CritterVariables")
	class UCritterMovementComponent* CritterMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Aura_CritterVariables");
	float MaxSpeed;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float value);
	void MoveRight(float value);

	void CameraPitch(float value);
	void CameraYaw(float value);

	virtual UPawnMovementComponent* GetMovementComponent() const;
	
	FVector2D CameraInput;
	
	FVector CurrentVelocity;
};
