// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObject.h"


UMyObject::UMyObject()
{
     myFloat = 77.7f;
}

void UMyObject::myFunction()
{
    UE_LOG(LogTemp, Warning, TEXT("This is a warning text."));
}

