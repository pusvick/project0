// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InventoryActor.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;
    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
   // static ConstructorHelpers::FClassFinder<UClass> PlayerPawnClassFinder(TEXT("/Game/player/MyInventoryActor"));
   // PlayerClassFinder = PlayerPawnClassFinder.Class;
}
// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    FHitResult OutHit;
    FVector Start = CameraComponent->GetComponentLocation();
    FVector ForwardVector = CameraComponent->GetForwardVector();
    FVector End = (Start + (ForwardVector * 1000.0f));
    FCollisionQueryParams CollisionParam;
    bool IsHit = GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParam);
    if (IsHit)
    {
       AActor* ActorHit = OutHit.GetActor();
       // UE_LOG(LogTemp, Warning, TEXT("Actor name %s"), *OutHit.GetActor()->GetName());
       UClass* HitActorClass = OutHit.GetActor()->GetClass();
      FName ActoreName= HitActorClass->GetFName();
      FString TheString = "MyInventoryActor_C";
      FName ConvertedFString = FName(*TheString);
     // if (ActoreName == ConvertedFString)
     // {
          //bGrabActor = true;
    //      AHitActor = ActorHit;
     // }
    //  else
    //  {
         // bGrabActor = false;
    //      AHitActor = NULL;
   //   }
      // FString test = *HitActorClass->GetFName().ToString();
      // UE_LOG(LogTemp, Warning, TEXT("Actor name %s"), test);
       //

    }

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
    PlayerInputComponent->BindAxis("TurnAround", this, &APlayerCharacter::TurnAround);
    PlayerInputComponent->BindAction("GrabUngrabInv", IE_Pressed, this, &APlayerCharacter::GrabUngrabInventory);

    

}

void APlayerCharacter::MoveForward(float Amount) {
    AddMovementInput(GetActorForwardVector(), Amount);
}

void APlayerCharacter::MoveRight(float Amount) {
    AddMovementInput(GetActorRightVector(),Amount);

}

void APlayerCharacter::LookUp(float Amount) {
    AddControllerPitchInput(Amount);
}

void APlayerCharacter::TurnAround(float Amount) {
    AddControllerYawInput(Amount);
}

void APlayerCharacter::ChangeInventory(float inventoryType) {

}

void APlayerCharacter::GrabUngrabInventory() {
    if (bGrabActor)
    {
     

    }
}



