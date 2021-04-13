// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameMode.h"
#include "PlayerCharacter.h"
#include "PPlayerController.h"

APlayerGameMode::APlayerGameMode() {
    DefaultPawnClass = APlayerCharacter::StaticClass();
    PlayerControllerClass = APPlayerController::StaticClass();

}