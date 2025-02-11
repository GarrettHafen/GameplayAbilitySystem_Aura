// Copyright Garrett Hafen


#include "AbilitySystem/Data/LevelUpInfo.h"

int32 ULevelUpInfo::FindLevelForXP(int32 XP) const
{
	int32 Level = 1;
	bool bSearching = true;
	while (bSearching)
	{
		//LevelUpInformation[0] = Blank;
		//LevelUpInformation[1] = Level 1 Information
		//LevelUpInformation[2] = Level 2 Information
		if (LevelUpInfomation.Num() - 1 <= Level ) return Level;

		if (XP >= LevelUpInfomation[Level].LevelUpRequirement)
		{
			++Level;
		}
		else
		{
			bSearching = false;
		}
		
	}
	return Level;
}
