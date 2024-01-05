// Neo4j Connector © 2024 by [Developer Bastian}(https://www.youtube.com/@bastiandev/) is licensed under CC BY 4.0

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "UObject/NoExportTypes.h"
#include "Neo4j_Connector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRESTRequestComplete, const FString&, Response, bool, bSuccessful);

/**
 * Class with methods to connect to and receive data from a Neo4j graph DB
 */
UCLASS()
class BA_NEO4J_PLUGIN_API UNeo4j_Connector : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly)
	FOnRESTRequestComplete OnRESTRequestComplete;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Meta = (BlueprintInternalUseOnly, DisplayName = "Neo4j Connector"), Category = "Dev Bastian")
	static UNeo4j_Connector* CreateREST_API_ConnectionObject(
		const FString& UserName,
		const FString& Password,
		const FString& Url,
		const FString& Verb,
		TMap<FString, FString> Headers,
		const FString& JsonBody);

protected:
	void StartRequest(const FString& UserName, const FString& Password, const FString& Url, const FString& Verb, TMap<FString, FString>& Headers, const FString& JsonBody);
	void GetResponseString(const FString& ResponseContent, bool success);
};