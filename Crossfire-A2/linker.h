/*
 * linker.h
 *
 *  Created on: 22 Feb 2017
 *      Author: Conor Beenham
 *		Student #: 16350851
 */

#ifndef LINKER_H_
#define LINKER_H_

void get_Players();
void get_Slots();

typedef struct player_Attributes
{
	char player_Type[30];
	char player_Name[20];
	int life_Points;
	int Dexterity;
	int Luck;
	int Magic;
	int Smartness;
	int Strength;
} player;

typedef struct slot_Attributes
{
	char slot_Entrance[20];
	char slot_Location[30];
	char slot_Exit[20];
} slot;

player Players[6];
slot Slots[20];

unsigned int player_Count;
unsigned int slot_Count;

#endif /* LINKER_H_ */
