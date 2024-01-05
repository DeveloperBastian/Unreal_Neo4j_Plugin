// Neo4j Connector © 2024 by [Developer Bastian}(https://www.youtube.com/@bastiandev/) is licensed under CC BY 4.0

#include "Neo4j_Connector.h"
#include "HttpModule.h"
#include "Http.h"
#include "Tasks/Task.h"

using namespace UE::Tasks;

UNeo4j_Connector* UNeo4j_Connector::CreateREST_API_ConnectionObject(
	const FString& UserName, 
	const FString& Password, 
	const FString& Url, 
	const FString& Verb, 
	TMap<FString, 
	FString> Headers, 
	const FString& JsonBody)
{
	UNeo4j_Connector* const Proxy = NewObject<UNeo4j_Connector>();
	Proxy->SetFlags(RF_StrongRefOnFrame);
	Proxy->StartRequest(UserName, Password, Url, Verb, Headers, JsonBody);
	return Proxy;
}

void UNeo4j_Connector::StartRequest(const FString& UserName, const FString& Password, const FString& Url, const FString& Verb, TMap<FString, FString>& Headers, const FString& JsonBody)
{
	// Add Auth to Header Map - use "None" if UserName is empty, else Base64 encode UserName and Password
	if (UserName.IsEmpty())
	{
		Headers.Add("Authorization", "None");
	}
	else
	{
		FString encoded = "Basic " + FBase64::Encode(UserName + ":" + Password);
		Headers.Add("Authorization", encoded);
	}
	// Launch task
	TTask<void> ConnectToAPI = Launch(UE_SOURCE_LOCATION, [this, UserName, Password, Url, Verb, Headers, JsonBody] {
		FHttpModule& httpModule = FHttpModule::Get();
		// Prepare request
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> pRequest = httpModule.CreateRequest();
		pRequest->SetURL(Url);
		pRequest->SetVerb(Verb);
		pRequest->SetContentAsString(JsonBody);

		// Add Headers
		for (const TPair<FString, FString>& kvp : Headers)
		{
			pRequest->AppendToHeader(kvp.Key, kvp.Value);
		}
		pRequest->ProcessRequest();
		// Define what will happen onComplete
		pRequest->OnProcessRequestComplete().BindLambda(
			[&](
				FHttpRequestPtr pRequest,
				FHttpResponsePtr pResponse, bool success)
			mutable {
				switch (pRequest->GetStatus()) {
				case EHttpRequestStatus::Succeeded:
					UE_LOG(LogTemp, Log, TEXT("Successful Neo4j API response: %s"), *(pResponse->GetContentAsString().Left(64)));
					GetResponseString(pResponse->GetContentAsString(), true);
					break;
				case EHttpRequestStatus::Failed_ConnectionError:
					UE_LOG(LogTemp, Error, TEXT("Neo4j API: Connection failed."));
					GetResponseString("Neo4j API: Connection failed.", false);
					break;
				default:
					UE_LOG(LogTemp, Error, TEXT("Neo4j API: Request failed."));
					GetResponseString("Neo4j API: Request failed.", false);
				}
			});
		});
}

void UNeo4j_Connector::GetResponseString(const FString& ResponseContent, bool success)
{
	check(IsInGameThread());
	OnRESTRequestComplete.Broadcast(ResponseContent, true);
}
