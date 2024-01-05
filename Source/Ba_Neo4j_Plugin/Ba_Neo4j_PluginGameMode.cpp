// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ba_Neo4j_PluginGameMode.h"
#include "Ba_Neo4j_PluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABa_Neo4j_PluginGameMode::ABa_Neo4j_PluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
