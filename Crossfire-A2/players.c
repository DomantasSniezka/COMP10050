/*
 * players.c
 *
 *  Created on: 22 Feb 2017
 *      Author: Conor Beenham
 *		Student #: 16350851
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linker.h"

#define MAX_PLAYER_SIZE 6

int String_Check(char string1[50], char string2[50]);
int Check_playerType(int i);

void get_Players()
{
	//	Declaring variables
	int i, tmpType, tmpChar;
	char voidString[10];

	//	DO-WHILE loop to make sure user selects a right amount of players
	do
	{
		printf("How many players do you want? (Max of six)\n");
		scanf("%u", &player_Count);
	}while (player_Count > MAX_PLAYER_SIZE || player_Count <= 0);

	for ( i = 0 ; i < player_Count ; i++)
	{
		do
		{
			//	Asking user what player_Type they want to be
			printf("What player type do you want player %d to be?\n", i+1);
			printf("1: Elf\n2: Human\n3: Ogre\n4: Wizard\n");
			scanf("%d", &tmpType);

			fgets(voidString, 250, stdin);	//	Used to cancel the 'phantom enter' after scanf

			//	IF statement to check if user has selected a valid player type
			if (tmpType > 4 || tmpType <= 0) printf("**ERROR** Invalid Player Type\n");

		}while(tmpType > 4 || tmpType <= 0);

		switch(tmpType)
		{
			case 1:
				strcpy(Players[i].player_Type,"Elf");
				break;
			case 2:
				strcpy(Players[i].player_Type,"Human");
				break;
			case 3:
				strcpy(Players[i].player_Type,"Ogre");
				break;
			case 4:
				strcpy(Players[i].player_Type,"Wizard");
				break;
		}

		printf("Give Player %d (%s) a name (Letters, numbers and 'spaces' only):\n", i+1,Players[i].player_Type);
		fgets(Players[i].player_Name, 100, stdin);

		for (tmpChar = 0 ; Players[i].player_Name[tmpChar] != '\0' ; tmpChar++)
		{
			if (!((Players[i].player_Name[tmpChar] >= 65 && Players[i].player_Name[tmpChar] <= 91)			//	If char isn't uppercase letter
				|| (Players[i].player_Name[tmpChar] >= 97 && Players[i].player_Name[tmpChar] <= 122)		//	If char isn't lowercase letter
				|| (Players[i].player_Name[tmpChar] >= 48 && Players[i].player_Name[tmpChar] <= 57)			//	If char isn't a number
				|| (Players[i].player_Name[tmpChar] == 32))) Players[i].player_Name[tmpChar] = '\0';		//	If char isn't a space set to null
		}

		tmpType = Check_playerType(i) - 1;
		/*
		for (tmpChar	= 0 ; Players[i].player_Type[tmpChar] != '\0' ; tmpChar++)
		{
			printf("%d, %c\n", Players[i].player_Type[tmpChar],Players[i].player_Type[tmpChar]);
		}
		*/
		//tmpChar = strlen(Players[i].player_Name) - 1;
		//printf("%d", tmpChar);
		//if (Players[i].player_Name[tmpChar] == 10) Players[i].player_Name[tmpChar] = '\0';
	}

	for ( i = 0 ; i < player_Count ; i++)
	{
		printf("Player %d: %s (%s)\n", i+1,Players[i].player_Name,Players[i].player_Type);
	}
}

int String_Check(char string1[50], char string2[50])
{
	int result;
	result = strcmp(string1,string2);
	return result;
}

int Check_playerType(int i)
{
	//	Function to check the player type
	if (String_Check(Players[i].player_Type,"Elf") == 0)
	{
		printf("You're an elf %s!\n", Players[i].player_Name);
		return 1;
	}

	else if (String_Check(Players[i].player_Type,"Human") == 0)
	{
		printf("You're a human %s!\n", Players[i].player_Name);
		return 2;
	}

	else if (String_Check(Players[i].player_Type,"Ogre") == 0)
	{
		printf("You're an ogre %s!\n", Players[i].player_Name);
		return 3;
	}

	else if (String_Check(Players[i].player_Type,"Wizard") == 0)
	{
		printf("You're a wizard %s!\n", Players[i].player_Name);
		return 4;
	}

	return 0;
}
