// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryActor.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;



UCLASS()
class GEOMETRYSANDBOX_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();
   

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "bGrabActor")
    bool bGrabActor;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AHitActor")
    AActor* AHitActor;
    UClass* PlayerClassFinder;;
    AActor* GrabActor;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);
	void LookUp(float Amount);
    void TurnAround(float Amount);
    void ChangeInventory(float inventoryType);
    void GrabUngrabInventory();
};