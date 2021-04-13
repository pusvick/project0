// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"

// Sets default values
AInventoryActor::AInventoryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
    
    //BaseMesh->SetStaticMesh()
    //SetRootComponent(BaseMesh);
    FTransform ActorTransform = GetActorTransform();
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/tennisball_02_tennisBall.tennisball_02_tennisBall'"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset2(TEXT("StaticMesh'/Game/1.1'"));
    Asset = MeshAsset.Object;
    Asset2 = MeshAsset2.Object;
    
}

void AInventoryActor::changeMesh(UStaticMeshComponent* Mesh, UStaticMesh* mesh1, UStaticMesh* mesh2)
{
    switch (GeometryPayloads.MeshType)
    {
        case EInventory::tennisBall:
        {
           Mesh->SetStaticMesh(mesh1);
        }
        break;
        case EInventory::Doge:
        {
            Mesh->SetStaticMesh(mesh2);
        }
        break;
        default: break;
    }

    

}

// Called when the game starts or when spawned
void AInventoryActor::BeginPlay()
{


	Super::BeginPlay();
    changeMesh(BaseMesh, Asset, Asset2);
}

// Called every frame
void AInventoryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

