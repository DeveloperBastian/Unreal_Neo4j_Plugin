// Copyright Epic Games, Inc. All Rights Reserved.

#include "BA_Neo4j.h"

#define LOCTEXT_NAMESPACE "FBA_Neo4jModule"

void FBA_Neo4jModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FBA_Neo4jModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBA_Neo4jModule, BA_Neo4j)