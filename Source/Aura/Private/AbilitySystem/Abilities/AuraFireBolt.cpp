// Copyright Garrett Hafen


#include "AbilitySystem/Abilities/AuraFireBolt.h"

#include "AuraGameplayTags.h"

FString UAuraFireBolt::GetDescription(int32 Level)
{
	const int Damage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			//Title
			"<Title>FIRE BOLT</><Small>Level: </><Level>%d </>\n\n"

			//Details
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			//Description
			"<Default>Launches a bolt of fire, exploding on impact and dealing </><Damage>%d</>"
			"<Default> fire damage with a chance to burn</>"),

			//Values
			Level,
			ManaCost,
			Cooldown,
			Damage);
	}
	return FString::Printf(TEXT(
		"<Title>FIRE BOLT</><Small>Level: </><Level>%d </>\n\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
		"<Default>Launches %d bolts of fire, exploding on impact and dealing </><Damage>%d</>"
		"<Default> fire damage with a chance to burn.</>"),
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		Damage);
}

FString UAuraFireBolt::GetNextLevelDescription(int32 Level)
{
	const int Damage = GetDamageByDamageType(Level, FAuraGameplayTags::Get().Damage_Fire);
	const float ManaCost = FMath::Abs(GetManaCost(Level));	
	const float Cooldown = GetCooldown(Level);
	
	return FString::Printf(TEXT(
		"<Title>NEXT LEVEL</><Small>Level: </><Level>%d </>\n\n"
		"<Small>ManaCost: </><ManaCost>%.1f</>\n"
		"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"
		"<Default>Launches %d bolts of fire, exploding on impact and dealing </><Damage>%d</>"
		"<Default> fire damage with a chance to burn.</>"),
		Level,
		ManaCost,
		Cooldown,
		FMath::Min(Level, NumProjectiles),
		Damage);
	
}
