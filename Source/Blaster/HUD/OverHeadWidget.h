// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blaster/Character/BlasterCharacter.h"
#include "Blueprint/UserWidget.h"
#include "OverHeadWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLASTER_API UOverHeadWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeDestruct() override;
	virtual void NativeConstruct() override;
	
public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* DisplayText;
	void SetDisplayText(FString TextToDisplay);
	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* Pawn);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerName(APawn* Pawn);
};
