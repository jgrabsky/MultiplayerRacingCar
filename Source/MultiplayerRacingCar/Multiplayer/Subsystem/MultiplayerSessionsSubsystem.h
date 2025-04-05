// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MultiplayerSessionsSubsystem.generated.h"

class IOnlineSubsystem;

/**
 * 
 */
UCLASS()
class MULTIPLAYERRACINGCAR_API UMultiplayerSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UMultiplayerSessionsSubsystem();

protected:
	UFUNCTION(BlueprintCallable, Category = "Multiplayer")
	void CreateSession();

	// delegate callbacks
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

private:
	IOnlineSubsystem* OnlineSubsystem;
	IOnlineSessionPtr SessionInterface;

	// delegates
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
};
