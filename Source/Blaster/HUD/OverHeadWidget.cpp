// Fill out your copyright notice in the Description page of Project Settings.


#include "OverHeadWidget.h"

#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverHeadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();

}

void UOverHeadWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(DisplayText)
	{
		DisplayText->SetText(FText::FromString(TEXT("")));
	}
}

void UOverHeadWidget::SetDisplayText(FString TextToDisplay)
{
	if(DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverHeadWidget::ShowPlayerNetRole(APawn* Pawn)
{
	ENetRole RemoteRole = Pawn->GetRemoteRole();
	FString RoleString;
	switch (RemoteRole)
	{
	case ROLE_Authority:
		RoleString = "Authority";
		break;
	case ROLE_AutonomousProxy:
		RoleString = "Autonomous Proxy";
		break;
	case ROLE_SimulatedProxy:
		RoleString = "Simulated Proxy";
		break;
	case ROLE_None:
		RoleString = "None";
		break;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role: %s"), *RoleString);
	SetDisplayText(RemoteRoleString);
	
}

void UOverHeadWidget::ShowPlayerName(APawn* Pawn)
{
			APlayerState* PlayerState = Pawn->GetPlayerState();
			if(PlayerState!=nullptr)
			{
				SetDisplayText(PlayerState->GetPlayerName());
			}else
			{
				SetDisplayText((TEXT("Could not find PlayerState")));
			}
}


