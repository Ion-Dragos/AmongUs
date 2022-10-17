#include "utils.h"

void* (* Abilities[4])(void* x) = {RotateMatrix, DecodeString, InvertArray, KillPlayer};

char *fromEnumtoString(PlayerRoles playerRole)
{
	char *str = calloc(MAX_LEN_STR_ATR, sizeof(char));
	switch(playerRole)
	{
		case Rotator:
			str = strcpy(str, "Rotator");
			break;
		case Decoder:
			str = strcpy(str, "Decoder");
			break;
		case Invertor:
			str = strcpy(str, "Invertor");
			break;
		case Impostor:
			str = strcpy(str, "Impostor");
			break;
	}
	return str;
}

// Task 1
void *RotateMatrix(void *input) {
	int n, k = 0;
	n = *((int*)input);

	char* mat = (char*) calloc (MAX_LEN_STR_OUT, sizeof(char));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((n - j) < 10 && (i + 1) < 10) {
				mat[k++] = (n - j) + '0';
				mat[k++] = (i + 1) + '0';
				mat[k++] = ' ';
			} else if ((n - j) >= 10 && (n - j) < 100 && (i + 1) < 10) {
				mat[k++] = (n - j) / 10 + '0';
				mat[k++] = (n - j) % 10 + '0';
				mat[k++] = (i + 1) + '0';
				mat[k++] = ' ';
			}

			if ((i + 1) >= 10 && (i + 1) < 100 && (n - j) < 10) {
				mat[k++] = (n - j) + '0';
				mat[k++] = (i + 1) / 10 + '0';
				mat[k++] = (i + 1) % 10 + '0';
				mat[k++] = ' ';

			} else if ((i + 1) >= 10 && (i + 1) < 100 && (n - j) >= 10 && (n - j) < 100) {
				mat[k++] = (n - j) / 10 + '0';
				mat[k++] = (n - j) % 10 + '0';
				mat[k++] = (i + 1) / 10 + '0';
				mat[k++] = (i + 1) % 10 + '0';
				mat[k++] = ' ';
			}

			if ((n - j) >= 100 && (i + 1) >= 100) {
				mat[k++] = (n - j) / 100 + '0';
				mat[k++] = ((n - j) / 10) % 10 + '0';
				mat[k++] = (n - j) % 100 + '0';
				mat[k++] = (i + 1) / 100 + '0';
				mat[k++] = ((i + 1) / 10) % 10 + '0';
				mat[k++] = (i + 1) % 100 + '0';
				mat[k++] = ' ';
			}

			if ((n - j) < 10 && (i + 1) >= 100) {
				mat[k++] = (n - j) / 10 + '0';
				mat[k++] = (i + 1) / 100 + '0';
				mat[k++] = ((i + 1) / 10) % 10 + '0';
				mat[k++] = (i + 1) % 100 + '0';
				mat[k++] = ' ';
			}

			if ((i + 1) < 10 && (n - j) >= 100) {
				mat[k++] = (n - j) / 100 + '0';
				mat[k++] = ((n - j) / 10) % 10 + '0';
				mat[k++] = (n - j) % 100 + '0';
				mat[k++] = (i + 1) + '0';
				mat[k++] = ' ';
			}

			if ((n - j) >= 10 && (n - j) < 100 && (i + 1) >= 100) {
				mat[k++] = (n - j) / 10 + '0';
				mat[k++] = (n - j) % 10 + '0';
				mat[k++] = (i + 1) / 100 + '0';
				mat[k++] = ((i + 1) / 10) % 10 + '0';
				mat[k++] = (i + 1) % 100 + '0';
				mat[k++] = ' ';
			}

			if ((n - j) >= 100 && (i + 1) >= 10 && (i + 1) < 100) {
				mat[k++] = (n - j) / 100 + '0';
				mat[k++] = ((n - j) / 10) % 10 + '0';
				mat[k++] = (n - j) % 100 + '0';
				mat[k++] = (i + 1) / 10 + '0';
				mat[k++] = (i + 1) % 10 + '0';
				mat[k++] = ' ';
			}
		}
		mat[k - 1] = '\n';
	}

	return (void*)mat;
}

// Task 2
void *DecodeString(void *input) {
	char* result = (char*) calloc (MAX_LEN_STR_ATR, sizeof(char));
	char* token;
	int sum = 0;

	token = strtok(input, "_");

	while (token != NULL) {
		int number = atoi(token);
		sum += number;
		token = strtok(NULL, "_");
	}

	sprintf(result,"%d",sum);

	return (void*) result;
}

//Task 3
void *InvertArray(void *input) {
	int* vector = (int*)input;
	int n = *vector;
	char* inversed = (char*) calloc (MAX_LEN_STR_OUT, sizeof(char));

	if (n % 2 == 0) {

		char* buffer1 = (char*) calloc (MAX_LEN_STR_ATR, sizeof(int));
		char* buffer2 = (char*) calloc (MAX_LEN_STR_ATR, sizeof(int));

		for (int i = 1; i < n; i += 2) {
			sprintf(buffer1, "%d", vector[i + 1]);
			strcat(inversed, buffer1);
			strcat(inversed, " ");

			sprintf(buffer2, "%d", vector[i]);
			strcat(inversed, buffer2);
			strcat(inversed, " ");
		}

		inversed[strlen(inversed) - 1] = '\0';
		return inversed;

	} else {

		char* buffer2 = (char*) calloc (MAX_LEN_STR_ATR, sizeof(int));

		for (int i = n; i > 0; i--) {
			sprintf(buffer2, "%d", vector[i]);
			strcat(inversed, buffer2);
			strcat(inversed, " ");
		}

		inversed[strlen(inversed) - 1] = '\0';
		return inversed;
	}

}

//Task 4
Player *allocPlayer() {
	Player *player = (Player*) calloc (1, sizeof(Player));
	player->name = calloc (MAX_LEN_STR_ATR, sizeof(char));
	player->color = calloc (MAX_LEN_STR_ATR, sizeof(char));
	player->hat = calloc (MAX_LEN_STR_ATR, sizeof(char));
	player->indexOfLocation = 0;
	player->alive = 1;

	return player;
}

//Task 4
Game *allocGame() {
	Game *game = (Game*) calloc (1, sizeof(Game));
	game->name = (char*) calloc (MAX_LEN_STR_OUT, sizeof(char));

	return game;
}

//Task 5
Player *ReadPlayer(FILE *inputFile) {
	Player* player = allocPlayer();

	fscanf(inputFile, "%s\n", player->name);
	fscanf(inputFile, "%s\n", player->color);
	fscanf(inputFile, "%s\n", player->hat);
	fscanf(inputFile, "%d\n", &(player->numberOfLocations));

	player->locations = (Location*) calloc (player->numberOfLocations, sizeof(Location));

	for (int i = 0; i < player->numberOfLocations; i++) {
		fscanf(inputFile,"(%d,%d)\n", &(player->locations[i]).x, &(player->locations[i]).y);
	}

	char* buffer = (char*) calloc (MAX_LEN_STR_ATR, sizeof(char));
	fscanf(inputFile, "%s\n", buffer);

	if (strcmp(buffer, "Decoder") == 0) {
		player->playerRole = Decoder;		
	}

	if (strcmp(buffer, "Rotator") == 0) {
		player->playerRole = Rotator;		
	}

	if (strcmp(buffer, "Invertor") == 0) {
		player->playerRole = Invertor;
	}

	if (strcmp(buffer, "Impostor") == 0) {
		player->playerRole = Impostor;
	}
	
	return player;
}

// Task 5
Game *ReadGame(FILE *inputFile) {

	Game* game = allocGame();
	
	fscanf(inputFile, "%s\n", game->name);
	fscanf(inputFile, "%d\n", &(game->killRange));
	fscanf(inputFile, "%d\n", &(game->numberOfCrewmates));

	game->crewmates = (Player**) calloc (1, sizeof(Player*));

	for(int i = 0; i < game->numberOfCrewmates; i++) {
		game->crewmates[i] = ReadPlayer(inputFile);
	}

	game->impostor = (Player*) calloc (1, sizeof(Player));
	game->impostor = ReadPlayer(inputFile);

	return game;

}

// Task 6
void WritePlayer(Player *player, FILE *outputFile) {

		fprintf(outputFile, "Player %s with color %s, hat %s and role %s has entered the game.\n", 
					player->name, player->color, player->hat, fromEnumtoString(player->playerRole));

		fprintf(outputFile, "Player's locations: ");

		for(int i = 0; i < player->numberOfLocations; i++) {

			fprintf(outputFile, "(%d,%d) ", player->locations[i].x, player->locations[i].y);

		}

		fprintf(outputFile, "\n");
		
	return;
}

// Task 6
void WriteGame(Game *game, FILE *outputFile) {
	fprintf(outputFile, "Game %s has just started!\n", game->name);
	fprintf(outputFile, "\tGame options:\n");
	fprintf(outputFile, "Kill Range: %d\n", game->killRange);
	fprintf(outputFile, "Number of crewmates: %d\n", game->numberOfCrewmates);
	fprintf(outputFile, "\n");


	fprintf(outputFile, "\tCrewmates:\n");
	for (int i = 0; i < game->numberOfCrewmates; i++) {
		WritePlayer(game->crewmates[i], outputFile);
	}

	fprintf(outputFile, "\n");

	fprintf(outputFile, "\tImpostor:\n");
	WritePlayer(game->impostor, outputFile);
}

int ManhattanDistance(Player* impostor, Player* crewmate) {
	int index_impostor_location = impostor->indexOfLocation;
	int index_crewmate_location = crewmate->indexOfLocation;

	int x_impostor = impostor->locations[index_impostor_location].x;
	int x_crewmate = crewmate->locations[index_crewmate_location].x;

	int y_impostor = impostor->locations[index_impostor_location].y;
	int y_crewmate = crewmate->locations[index_crewmate_location].y;

	int distance_Manhattan = (abs(x_impostor - x_crewmate) + abs(y_impostor - y_crewmate));

	return distance_Manhattan;
}

//Task 7
void *KillPlayer(void *input) {
	Game* game = (Game*) input;
	Player* impostor = game->impostor;

	char* result = (char*) calloc (MAX_LEN_STR_OUT, sizeof(char));

	int killRange = game->killRange;

	int min_distance = INT_MAX;
	int index_of_player = -1;

	for (int i = 0; i < game->numberOfCrewmates; i++) {
		if (game->crewmates[i]->alive == 1) {
			int distance_Manhattan = ManhattanDistance(impostor, game->crewmates[i]);
			if(distance_Manhattan <= killRange) {
				if(distance_Manhattan <= min_distance) {
					min_distance = distance_Manhattan;
					index_of_player = i;
				}
			}
		}
	}

	if (index_of_player != -1) {
		sprintf(result, "Impostor %s has just killed crewmate %s from distance %d.", 
			impostor->name, game->crewmates[index_of_player]->name, min_distance);

		game->crewmates[index_of_player]->alive = 0;
	} else {
		sprintf(result, "Impostor %s couldn't kill anybody.", impostor->name);
	}	
	
	return (void*) result;
}

// Task 8
void CalcuateNextCycleOfGame(Game *game, FILE *outputFile, void **inputMatrix)
{
	for (int i = 0; i < game -> numberOfCrewmates; i++) {
		if (game->crewmates[i]->alive == 0) {
			fprintf(outputFile, "Crewmate %s is dead.\n", game->crewmates[i]->name);
		} else {
			fprintf(outputFile, "Crewmate %s went to location ", game->crewmates[i]->name);

			game->crewmates[i]->indexOfLocation++;

			if (game->crewmates[i]->indexOfLocation == (game->crewmates[i]->numberOfLocations )) {
				game->crewmates[i]->indexOfLocation = 0;
			}

			fprintf(outputFile, "(%d,%d).\n", game -> crewmates[i]->locations[game->crewmates[i]->indexOfLocation].x, game->crewmates[i]->locations[(*game).crewmates[i]->indexOfLocation].y);
			fprintf(outputFile, "Crewmate %s's output:\n", game -> crewmates[i]->name);

			if (game->crewmates[i]->playerRole == 0) {
				char *output = RotateMatrix(inputMatrix[i]);

				fprintf(outputFile, "%s\n", output);
				free(output);
			}

			if (game->crewmates[i]->playerRole == 1) {
				char *output = DecodeString(inputMatrix[i]);

				fprintf(outputFile, "%s\n", output);
				free(output);
			}

			if (game->crewmates[i]->playerRole == 2) {
				char *output = InvertArray(inputMatrix[i]);

				fprintf(outputFile, "%s\n", output);
				free(output);
			}
		}
	}

	fprintf(outputFile, "Impostor %s went to location ", game->impostor->name);

	(*game).impostor->indexOfLocation++;

	if (game->impostor->indexOfLocation == (game->impostor->numberOfLocations)) {
		game->impostor->indexOfLocation = 0;
	}

	fprintf(outputFile, "(%d,%d).\n", game->impostor->locations[game->impostor->indexOfLocation].x, 
										game->impostor->locations[game->impostor->indexOfLocation].y);
	fprintf(outputFile, "Impostor %s's output:\n", game->impostor->name);

	char *output = KillPlayer(game);

	fprintf(outputFile, "%s\n", output);
	free(output);
}

// Task 9
void FreePlayer(Player *player) {
	free(player->name);
	free(player->hat);
	free(player->color);
	free(player->locations);
	free(player);
}

// Task 9
void FreeGame(Game *game) {
	free(game->name);

	for (int i = 0; i < game->numberOfCrewmates; i++) {
		FreePlayer(game->crewmates[i]);
	}

	free(game->crewmates);
	FreePlayer(game->impostor);
	free(game);
}