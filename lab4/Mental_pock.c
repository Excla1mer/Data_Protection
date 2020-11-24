#include "../libs/headers.h"

#define COUNT_PLAYERS 23
#define COUNT_CARDS 52

typedef struct card_s
{
	char name;
	char rank;
	unsigned long long id;
} card_t;

typedef struct player_s
{
	card_t p_cards[2];
} player_t;

uint64_t evklid2(uint64_t a, uint64_t p) {
	uint64_t U[2] = { p,0 }, V[2] = { a,1 }, T[2];
	while (V[0] >= 0) {
		if (V[0] == 0) {
			if (U[1] < 0) {
				U[1] += p;
			}

			return U[0];
		}
		uint64_t q = U[0] / V[0];
		for (int i = 0; i < 2; i++) {
			T[i] = U[i] - q * V[i];
			U[i] = V[i];
			V[i] = T[i];
		}
	}
}

void shuffle(int *deck) {
	for (int i = 0; i < COUNT_CARDS; i++) {
		int j = rand() % COUNT_CARDS;
		int temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

int euclied(int a, int b)
{
  int i;
  if(a < b){
    i = a;
    a = b;
    b = i;
  }
  int q, u[2], v[2], t[2];
  u[0] = a;
  u[1] = 0;
  v[0] = b;
  v[1] = 1;
  while(v[0] != 0) {
    q = u[0] / v[0];
    t[0] = u[0] % v[0];
    t[1] = u[1] - q * v[1];
    for(i = 0; i < 2; i++){
      u[i] = v[i];
      v[i] = t[i];
    }
  }
  if(u[1] < 0)
  	u[1] += a;
  return u[1];
}

int main() {
	char cards_name[13] = "023456789BQKT";
	char card_rank[4] = "kpbc";
	srand(time(NULL));
	int deck[52];
	card_t card[52];
	int cards_count = COUNT_CARDS - 1;
	int table[5];
	player_t players[COUNT_PLAYERS];
	uint64_t *C = (uint64_t *)malloc(sizeof(uint64_t) * COUNT_PLAYERS);
	uint64_t *D = (uint64_t *)malloc(sizeof(uint64_t) * COUNT_PLAYERS);
	int test[3] = {2,3,5};

	if (COUNT_PLAYERS > 23)
	{
		printf("Преввышен лимит игроков\n");
		return 0;
	}

	while(1)
	{
		q = random() % 10000;
		if(isPrime(q))
		{
			p = 2 * q + 1;
			if(isPrime(p))
			break;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			strcpy(&card[i*13 + j].name, &cards_name[j]);
			strcpy(&card[i*13 + j].rank, &card_rank[i]);
			deck[i*13 + j] = 1 + random() % p - 1;
			card[i*13 + j].id = deck[i*13 + j];

		}
	}

	printf("p = %lld q = %lld\n", p, q);

	for (int i = 0; i < COUNT_PLAYERS; i++)
	{
		do
		{
			D[i] = rand() % (p - 1);

		} while(evklid2(D[i], p - 1) != 1);
		
		C[i] = euclied(D[i], p - 1);

		printf("c = %ld d = %ld\n", C[i], D[i]);
	}

	for (int j = 0; j < COUNT_PLAYERS; j++)
	{
		for (int i = 0; i < COUNT_CARDS; i++)
		{
			deck[i] = powMod(deck[i], C[j], p);
		}
		shuffle(deck);
	}

	for (int i = 0; i < COUNT_PLAYERS; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			players[i].p_cards[j].id = deck[cards_count];
			cards_count--;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		table[i] = deck[cards_count];
		cards_count--;
	}

	for (int i = 0; i < COUNT_PLAYERS; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < COUNT_PLAYERS; k++)
			{
				players[i].p_cards[j].id = powMod(players[i].p_cards[j].id, D[k], p);
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			table[i] = powMod(table[i], D[j], p);
		}
	}

	for (int i = 0; i < COUNT_PLAYERS; i++)
	{
		for (int j = 0; j < COUNT_CARDS; j++)
		{
			if (players[i].p_cards[0].id == card[j].id)
			{
				printf("Игрок %d Значение = %c Масть = %c\n", i, card[j].name, card[j].rank);
				break;
			}
		}
		for (int j = 0; j < COUNT_CARDS; j++)
		{
			if (players[i].p_cards[1].id == card[j].id)
			{
				printf("Игрок %d Значение = %c Масть = %c\n", i, card[j].name, card[j].rank);
				break;
			}
		}
	}

	printf("СТОЛ:\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < COUNT_CARDS; j++)
		{
			if (table[i] == card[j].id)
			{
				printf("Значение = %c Масть = %c\n", card[j].name, card[j].rank);
				break;
			}
		}
	}

	return 0;
}
