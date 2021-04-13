// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "InventoryActor.generated.h"



UENUM(BlueprintType)
enum class EInventory : uint8
{
    tennisBall,
    Doge
};

USTRUCT(BlueprintType)
struct FInventoryStruct
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    EInventory MeshType = EInventory::tennisBall;

};

UCLASS()
class GEOMETRYSANDBOX_API AInventoryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryActor();

    UPROPERTY(VisibleAnywhere)
		 UStaticMeshComponent* BaseMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
        FInventoryStruct GeometryPayloads;
	 UStaticMesh* Asset;
     UStaticMesh* Asset2;
   

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    void changeMesh(UStaticMeshComponent* Mesh, UStaticMesh* mesh1, UStaticMesh* mesh2);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
