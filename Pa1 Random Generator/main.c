#include <stdio.h>
#include <stdlib.h>

double calculateHealAmount(double attackerMinPhysicalResistance, double attackerMaxPhysicalResistance,double attackerMinCritDamage, double attackerMaxCritDamage, double attackerCritChance, double attackerAttack)
{
	double healAmount;
	double randomCrit;
	randomCrit = (double)((double)(rand() % 100 + 0) / (double)100);

	if (randomCrit <= attackerCritChance)
	{
		healAmount = ((((double)attackerAttack * 0.4) 
			* ((double)(rand() % ((int)(attackerMaxCritDamage - attackerMinCritDamage) + (int)attackerMinCritDamage)))
			* ((double)(rand() % (int)(attackerMaxPhysicalResistance - attackerMinPhysicalResistance) + (int)attackerMinPhysicalResistance) + 100)/100.00));
	}
	else
	{
		healAmount = ((((double)attackerAttack * 0.4)
			* ((double)(rand() % (int)(attackerMaxPhysicalResistance - attackerMinPhysicalResistance) + (int)attackerMinPhysicalResistance) + 100) / 100.00));
	}
	return healAmount;
};

double calculateDamageAmount(double attackerMinPhysicalResistance, double attackerMaxPhysicalResistance, double attackerMinCritDamage, double attackerMaxCritDamage, double attackerCritChance, double attackerAttack)
{
	double randomCrit;
	double damageDealt;
	randomCrit = (double)((double)(rand() % 100 + 0) / (double)100);

	if (randomCrit <= attackerCritChance)
	{
		damageDealt = (double)( (double)attackerAttack 
			* (double)(rand() % (int)(attackerMaxCritDamage - attackerMinCritDamage)  + (int)attackerMinCritDamage)
			* (1.00 - ((double)(rand() % (int)(attackerMaxPhysicalResistance - attackerMinPhysicalResistance) + (int)attackerMinPhysicalResistance) / 100.00)));
	}
	else
	{
		damageDealt = (double)((double)attackerAttack
			* (1.00 - ((double)(rand() % (int)(attackerMaxPhysicalResistance - attackerMinPhysicalResistance) + (int)attackerMinPhysicalResistance) / 100.00)));
	}
	return damageDealt;
};

void createPlayerCharacter(int roleNumber, double *playerHealth, double *playerMaxHealth, double *playerAttack, double *playerMinPhysicalResistance, double *playerMaxPhysicalResistance, double *playerCritChance , double *playerMinCritDamage, double *playerMaxCritDamage)
{
	switch (roleNumber)
	{
	case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
		*playerHealth = 10000; //Set *playersHealth to 10000;
		*playerMaxHealth = 10000; //Set *playerMaxHealth to 10000;
		*playerAttack = 300; //Set *playerAttack to 300;
		*playerMaxPhysicalResistance = 80.00; //Set *playerMaxPhysicalResistance to 80%;
		*playerMinPhysicalResistance = 60.00; //Set *playerMinPhysicalResistance to 60%;
		*playerCritChance = 0.20; //Set *playerMaxCritChance to 0.20;
		*playerMaxCritDamage = 8.00; //Set *playerMaxCritDamage to 8.00;
		*playerMinCritDamage = 6.00; //Set *playerMinCritDamage to 6.00;
								  /*END of your solution*/
		break;
	case 2: //Mage: Low: health and resistance. Medium: crit damage and crit chance High: attack
			/*BEGINNING of your solution*/
		*playerHealth = 4000; //Set *playersHealth to 4000;
		*playerMaxHealth = 4000; //Set *playerMaxHealth to 4000;
		*playerAttack = 1000; //Set *playerAttack to 1000;
		*playerMaxPhysicalResistance = 40.00; //Set *playerMaxPhysicalResistance to 40.00%;
		*playerMinPhysicalResistance = 30.00; //Set *playerMinPhysicalResistance to 30.00%;
		*playerCritChance = 0.40; //Set *playerMaxCritChance to 0.40;
		*playerMaxCritDamage = 4.00; //Set *playerMaxCritDamage to 4.00;
		*playerMinCritDamage = 3.00; //Set *playerMinCritDamage to 3.00;
								  /*END of your solution*/
		break;
	case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
		   /*BEGINNING of your solution*/
		*playerHealth = 6000; //Set *playersHealth to 6000;
		*playerMaxHealth = 6000; //Set **playerMaxHealth to 6000;
		*playerAttack = 600; //Set *playerAttack to 600;
		*playerMaxPhysicalResistance = 50.00; //Set *playerMaxPhysicalResistance to 50.00%;
		*playerMinPhysicalResistance = 40.00; //Set *playerMinPhysicalResistance to 40.00%;
		*playerCritChance = 0.80; //Set *playerMaxCritChance to 0.80;
		*playerMaxCritDamage = 7.00; //Set *playerMaxCritDamage to 7.00;
		*playerMinCritDamage = 5.00; //Set *playerMinCritDamage to 5.00;
								  /*END of your solution*/
		break;
	}
};

void createBoss(double *bossHealth, double *bossAttack, double *bossMaxPhysicalResistance, double *bossMinPhysicalResistance, double *bossMaxCritDamage, double *bossMinCritDamage, double *bossCritChance)
{
	/*BEGINNING of your solution*/
	*bossHealth = 50000; //Set *bossHealth to 50000
	*bossAttack = (double)(rand() % 200 + 400); //Set *bossAttack to a randomized number in the range between 400 to 600 inclusively
	*bossMaxPhysicalResistance = 60.00; //Set *bossMaxPhysicalResistance to 60.00;
	*bossMinPhysicalResistance = 30.00; //Set *bossMinPhysicalResistance to 30.00;
	*bossCritChance = (double)((rand() % 10 + 20) / 100); //Set *bossCritChance to a randomized number in the range between 10 to 20 inclusively;
	*bossMaxCritDamage = 1.00; //Set *bossMaxCritDamage to 100.00;
	*bossMinCritDamage = 3.00; //Set *bossMinCritDamage to 300.00;
													/*END of your solution*/
};

int getUserInput(int numOfChoices) {
	int number;
	while (1 == 1) // Always true, C is stupid
	{
		scanf("%d", &number);
		for (int i = 1; i <= numOfChoices; i++) // Loops through the possible choices
		{
			if (number == i)
			{
				printf("\n");
				return i;
			}
		}
		//Error Message
		fseek(stdin, 0, SEEK_END); //Flush input buffer
		printf("<----------------------------------------------------------------------------->\n");
		printf("Invalid Input Error: Please enter a one of the number above!\n");

	}
	return number;
}

void introduction() {
	printf("Welcome to your Programming Assignment 1!\n");
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Silva.\n");
	printf("You can choose to be a WARRIOR, a MAGE or an Archer.\n ");
	printf("1. Warrior\n ");
	printf("2. Mage\n ");
	printf("3. Archer\n");
	printf("Please select your class with the coresponding numbers. ");
	printf("Selection: ");
}

int playerMove()
{
	int random;
	printf("1. Attack\n");
	printf("2. Heal\n");
	printf("Selection: ");
	random = getUserInput(2);
	return random;
}
int main()
{
	//CHARACTER 
	const char roleName1[10] = { 'W','a','r','r','i','o','r' };
	const char roleName2[10] = { 'M','a','g','e' };
	const char roleName3[10] = { 'A','r','c','h','e','r' };
	double playerHealth;
	double playerAttack;
	double playerMaxHealth;
	//CHARACTER STATS
	double playerMinPhysicalResistance;
	double playerMaxPhysicalResistance;
	double playerCritChance;
	double playerMinCritDamage;
	double playerMaxCritDamage;

	//BOSS STATS
	char bossName[10] = { 'S', 'i', 'l', 'v', 'a' };
	double bossHealth;
	double bossAttack;
	double bossMinPhysicalResistance;
	double bossMaxPhysicalResistance;
	double bossCritChance;
	double bossMinCritDamage;
	double bossMaxCritDamage;

	//FUNCTION
	int renderOpCode = -1;
	double *renderArgument1 = NULL;
	double *renderArgument2 = NULL;
	renderArgument1 = malloc(sizeof(double));
	renderArgument2 = malloc(sizeof(double));

	introduction();
	createPlayerCharacter(getUserInput(3), &playerHealth, &playerMaxHealth, &playerAttack, &playerMinPhysicalResistance, &playerMaxPhysicalResistance, &playerCritChance, &playerMinCritDamage, &playerMaxCritDamage);
	createBoss( &bossHealth, &bossAttack, &bossMaxPhysicalResistance, &bossMinPhysicalResistance, &bossMaxCritDamage, &bossMinCritDamage, &bossCritChance);
	
	while (1 == 1) 
	{
		while (bossHealth >= 0)
		{
			int temp = playerMove();
			if (temp == 1)
			{
				double amount = calculateDamageAmount( bossMinPhysicalResistance, bossMaxPhysicalResistance, playerMinCritDamage, playerMaxCritDamage, playerCritChance,  playerAttack);
				printf("Player dealt %d to Boss.\n", (int)amount);
				bossHealth -= amount;
				printf("Boss heal is %d.\n", (int)bossHealth);
			}
			if (temp == 2)
			{
				double amount = calculateHealAmount(playerMinPhysicalResistance, playerMaxPhysicalResistance, playerMinCritDamage, playerMaxCritDamage, playerCritChance, playerAttack);
				printf("Player heal %d to self HP.\n", (int)amount);
				playerHealth += amount;
				printf("Player heal is %d.\n", (int)playerHealth);
			}
			double amount = calculateDamageAmount(playerMinPhysicalResistance, playerMaxPhysicalResistance, bossMinCritDamage, bossMaxCritDamage, bossCritChance, bossAttack);
			printf("<----------------------------------------------------------------------------->\n");
			printf("Boss dealt %d to Player.\n", (int)amount);
			playerHealth -= amount;
			printf("Player heal is %d.\n", (int)playerHealth);
			printf("<----------------------------------------------------------------------------->\n");
		}
	}

	return 0;
};