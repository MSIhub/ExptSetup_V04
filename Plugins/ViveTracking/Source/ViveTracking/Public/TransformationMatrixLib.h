// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TransformationMatrixLib.generated.h"

USTRUCT(BlueprintType)
struct FTrackerDataStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tracker Data Struct")
		float timestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tracker Data Struct")
		FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tracker Data Struct")
		FVector LinearVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tracker Data Struct")
		FVector LinearAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tracker Data Struct")
		FRotator Orientation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tracker Data Struct")
		FRotator AngularVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tracker Data Struct")
		FRotator AngularAcceleration;

	
};



/**
 * 
 */
UCLASS()
class UTransformationMatrixLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable)
		static FMatrix TransformationMatrix(FRotator InRot, FVector InTrans);

		UFUNCTION(BlueprintCallable)
		static FMatrix TransformationMatrix_Inverse(FMatrix InTransformationMatrix);

		UFUNCTION(BlueprintCallable)
		static FMatrix TransformationMatrix_Multiply(FMatrix InTransformationMatrix1, FMatrix InTransformationMatrix2);

		UFUNCTION(BlueprintCallable)
		static FVector TransformationMatrix_PositionExtract(FMatrix InTransformationMatrix);

		UFUNCTION(BlueprintCallable)
		static FRotator TransformationMatrix_RotationRPYExtract(FMatrix InTransformationMatrix);

		UFUNCTION(BlueprintCallable)
		static float AngleOffsetCorrector(float InAngle);

		UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString", CompactNodeTitle = "->", Keywords = "String", HideSelfPin), Category = "DataStruct")
		static FString FTrackerDataStructToString(FTrackerDataStruct d) {
			return FString::SanitizeFloat(d.timestamp) + " " + FString::SanitizeFloat(d.Position.X) + " " + FString::SanitizeFloat(d.Position.Y) + " " + FString::SanitizeFloat(d.Position.Z) + " " + FString::SanitizeFloat(d.LinearVelocity.X) + " " + FString::SanitizeFloat(d.LinearVelocity.Y)
				+ " " + FString::SanitizeFloat(d.LinearVelocity.Z) + " " + FString::SanitizeFloat(d.LinearAcceleration.X) + " " + FString::SanitizeFloat(d.LinearAcceleration.Y) + " " + FString::SanitizeFloat(d.LinearAcceleration.Z) + " " + FString::SanitizeFloat(d.Orientation.Roll)
				+ " " + FString::SanitizeFloat(d.Orientation.Pitch) + " " + FString::SanitizeFloat(d.Orientation.Yaw) + " " + FString::SanitizeFloat(d.AngularVelocity.Roll) + " " + FString::SanitizeFloat(d.AngularVelocity.Pitch) + " " + FString::SanitizeFloat(d.AngularVelocity.Yaw)
				+ " " + FString::SanitizeFloat(d.AngularAcceleration.Roll) + " " + FString::SanitizeFloat(d.AngularAcceleration.Pitch) + " " + FString::SanitizeFloat(d.AngularAcceleration.Yaw);
		}
	
};
