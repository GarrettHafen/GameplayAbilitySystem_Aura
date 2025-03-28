#pragma once

#include "GameplayEffect.h"
#include "GameplayEffectTypes.h"
#include "AuraAbilityTypes.generated.h"
USTRUCT(BlueprintType)
struct FDamageEffectParams
{
	GENERATED_BODY()

	FDamageEffectParams(){}

	UPROPERTY(Blueprintreadwrite)
	TObjectPtr<UObject> WorldContextObject = nullptr;

	UPROPERTY(Blueprintreadwrite)
	TSubclassOf<UGameplayEffect> DamageGameplayEffectClass = nullptr;

	UPROPERTY(Blueprintreadwrite)
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystemComponent = nullptr;

	UPROPERTY(Blueprintreadwrite)
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystemComponent = nullptr;

	UPROPERTY(Blueprintreadwrite)
	float BaseDamage = 0.0f;
	
	UPROPERTY(Blueprintreadwrite)
	float AbilityLevel = 1;
	
	UPROPERTY(Blueprintreadwrite)
	FGameplayTag DamageType = FGameplayTag();
	
	UPROPERTY(Blueprintreadwrite)
	float DebuffChance = 0.0f;
	
	UPROPERTY(Blueprintreadwrite)
	float DebuffDuration = 0.0f;
	
	UPROPERTY(Blueprintreadwrite)
	float DebuffFrequency = 0.0f;
	
	UPROPERTY(Blueprintreadwrite)
	float DebuffDamage = 0.0f;

	UPROPERTY(Blueprintreadwrite)
    float DeathImpulseMagnitude = 0.0f;

	UPROPERTY(Blueprintreadwrite)
	FVector DeathImpulse = FVector::ZeroVector;

	UPROPERTY(Blueprintreadwrite)
	float KnockbackForceMagnitude = 0.0f;

	UPROPERTY(Blueprintreadwrite)
	FVector KnockbackForce = FVector::ZeroVector;

	UPROPERTY(Blueprintreadwrite)
	float KnockbackChance = 0.0f;
};

USTRUCT(BlueprintType)
struct FAuraGameplayEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()

public:
	bool IsCriticalHit() const {return bIsCriticalHit;}
	bool IsBlockedHit() const {return bIsBlockedHit;}
	bool IsSuccessfulDebuff() const {return bIsSuccessfulDebuff;}
	float GetDebuffDamage() const {return DebuffDamage;}
	float GetDebuffFrequency() const {return DebuffFrequency;}
	float GetDebuffDuration() const {return DebuffDuration;}
	TSharedPtr<FGameplayTag> GetDamageType() const {return DamageType;}
	FVector GetDeathImpulse() const {return DeathImpulse;}
	FVector GetKnockbackForce() const {return KnockbackForce;}
	

	void SetIsCriticalHit(bool bInIsCriticalHit){bIsCriticalHit = bInIsCriticalHit;}
	void SetIsBlockedHit(bool bInIsBlockedHit){bIsBlockedHit = bInIsBlockedHit;}
	void SetIsSuccessfulDebuff(bool bInIsDebuff){bIsSuccessfulDebuff = bInIsDebuff;}
	void SetDebuffDamage(float InDamage){DebuffDamage = InDamage;}
	void SetDebuffDuration(float InDuration){DebuffDuration = InDuration;}
	void SetDebuffFrequency(float InFrequency){DebuffFrequency = InFrequency;}
	void SetDamageType(TSharedPtr<FGameplayTag> InDamageType){DamageType = InDamageType;}
	void SetDeathImpulse(const FVector& InImpulse) {DeathImpulse = InImpulse;}
	void SetKnockbackForce(const FVector& InForce) {KnockbackForce = InForce;}
	
	/** Returns the actual struct used for serialization, subclasses must override this! */
	virtual UScriptStruct* GetScriptStruct() const
	{
		return StaticStruct();
	}

	/** Creates a copy of this context, used to duplicate for later modifications */
	virtual FAuraGameplayEffectContext* Duplicate() const
	{
		FAuraGameplayEffectContext* NewContext = new FAuraGameplayEffectContext();
		*NewContext = *this;
		if (GetHitResult())
		{
			// Does a deep copy of the hit result
			NewContext->AddHitResult(*GetHitResult(), true);
		}
		return NewContext;
	}

	/** Custom serialization, subclasses must override this */
	virtual bool NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess);
protected:

	UPROPERTY()
	bool bIsBlockedHit = false;
	
	UPROPERTY()
	bool bIsCriticalHit = false;
	
	UPROPERTY()
	bool bIsSuccessfulDebuff = false;
	
	UPROPERTY()
	float DebuffDamage = 0.0f;
	
	UPROPERTY()
	float DebuffDuration = 0.0f;
	
	UPROPERTY()
	float DebuffFrequency = 0.0f;

	TSharedPtr<FGameplayTag> DamageType;

	UPROPERTY()
	FVector DeathImpulse = FVector::ZeroVector;
	
	UPROPERTY()
	FVector KnockbackForce = FVector::ZeroVector;
	
	
};

template<>
struct TStructOpsTypeTraits<FAuraGameplayEffectContext> : TStructOpsTypeTraitsBase2<FAuraGameplayEffectContext>
{
	enum
	{
		WithNetSerializer = true,
		WithCopy = true
	};
};