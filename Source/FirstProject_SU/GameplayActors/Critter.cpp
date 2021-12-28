// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "CritterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
ACritter::ACritter()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraInput = FVector2D(0.f, 0.f);
	MaxSpeed = 100;
	CurrentVelocity = FVector(0.0f);

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Critter Root"));
	CritterMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Critter Mesh"));

	SetRootComponent(RootComponent);
	CritterMesh->SetupAttachment(GetRootComponent());

	CritterSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Critter Spring Arm"));
	CritterSpringArm->SetupAttachment(GetRootComponent());
	CritterSpringArm->SetRelativeRotation(FRotator(-40.f, 0.f, 0.f));
	CritterSpringArm->bEnableCameraLag = true;
	CritterSpringArm->CameraLagSpeed = 3.f;
	CritterSpringArm->TargetArmLength = 400.f;


	CritterCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Critter Camera"));
	CritterCamera->SetupAttachment(CritterSpringArm);


	CritterMovementComponent = CreateDefaultSubobject<UCritterMovementComponent>(TEXT("Critter Movement Component"));
	CritterMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);*/

	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += CameraInput.X;
	SetActorRotation(NewRotation);

	FRotator NewSpringArmRotation = CritterSpringArm->GetComponentRotation();
	NewSpringArmRotation.Pitch += CameraInput.Y;
	CritterSpringArm->SetWorldRotation(NewSpringArmRotation);

}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACritter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACritter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("CameraPitch"), this, &ACritter::CameraPitch);
	PlayerInputComponent->BindAxis(TEXT("CameraYaw"), this, &ACritter::CameraYaw);
}

void ACritter::MoveForward(float value)
{
	FVector forward = GetActorForwardVector();
	UCritterMovementComponent* moveComponent = (UCritterMovementComponent*)GetMovementComponent();
	if (moveComponent)
	{
		moveComponent->AddInputVector(forward * value);
	}
}

void ACritter::MoveRight(float value)
{
	FVector right = GetActorRightVector();
	UCritterMovementComponent* moveComponent = (UCritterMovementComponent*)GetMovementComponent();
	if (moveComponent)
	{
		moveComponent->AddInputVector(right * value);
	}
}

void ACritter::CameraPitch(float value)
{
	CameraInput.Y = value;
}

void ACritter::CameraYaw(float value)
{
	CameraInput.X = value;
}
UPawnMovementComponent* ACritter::GetMovementComponent() const
{
	return CritterMovementComponent;
}



