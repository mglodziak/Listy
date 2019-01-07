// Listy_v1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define DEBUG_TEST

// listy_start.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Operacje_na_listach.h"
#include "global.h"
#include "stdlib.h"
#include "time.h"



int Compare( const void* p, const void* q );  //porównuje dwa wskaŸniki na strukturê
void PrintList( ListItem* pList); //wyœwietla listê
int main( int argc, char *argv[] )
{
	srand( (unsigned)time( NULL ) );
	ListItem* Head = CreateEmptyList(); // tworzê pust¹ listê
	if (!Head)
	{
		printf( "Error! Nie udalo sie utworzyc listy" );
			return 0;
	}

	//------WSTAWIANIE----------

	for (int i = 0, wstaw=3; i < 3; i++) //wstawiam w pêtli 3 elementy
	{
		LISTINFO* pData1 = (LISTINFO*)malloc( sizeof( LISTINFO ) ); //testujê wstawianie na pocz¹tek. Wsadzam sobie trzy, ustalone przeze mnie, cyfry.
		pData1->nKey = wstaw;
		InsertOnFront( Head, pData1 );
		wstaw=2*wstaw+1;
#ifdef  DEBUG_TEST
		PrintList( Head );
		printf( "\n\n" );
#endif
	}
	
	LISTINFO key = { 7 }; // wsadzam na liste przed elementem wpisanym w {} (jesli takowy istnieje)
	ListItem* pPrev = NULL;
	ListItem* p = NULL;
	p = Find( Head, &key, &pPrev, Compare );

	if (p != NULL)
	{
		LISTINFO* pData5 = (LISTINFO*)malloc( sizeof( LISTINFO ) );
		pData5->nKey = 20;
		Insert( p, pData5 );
	}

#ifdef  DEBUG_TEST
	PrintList( Head );
	printf( "\n\n" );
#endif
	
	for (int i = 0; i < 5; i++) // wstawiam 5 losowych elementow na poczatek 
	{
		LISTINFO* pData = (LISTINFO*)malloc( sizeof( LISTINFO ) );
		pData->nKey = rand() % 10 + 1;
		InsertOnFront( Head, pData );
	}
#ifdef  DEBUG_TEST
	PrintList( Head );
	printf( "\n\n" );
#endif


	//------USUWANIE--------
	RemoveOnFront( Head ); // usuwam sobie pierwszy element z listy
#ifdef  DEBUG_TEST
	PrintList( Head );
	printf( "\n\n" );
#endif

	LISTINFO keyR = { 7 }; // wsadzam na liste przed elementem wpisanym w {} (jesli takowy istnieje)
	ListItem* pPrevR = NULL;
	ListItem* pR = NULL;
	pR = Find( Head, &keyR, &pPrevR, Compare );

	if (p != NULL)
	{
		Remove( pR ); // usunie pierwsz¹ siódemkê z listy o ile nie wystêpuje na 1 miejscu
	}
#ifdef  DEBUG_TEST
	PrintList( Head );
	printf( "\n\n" );
#endif

	SortList( Head, Compare ); // posortuje to co pozosta³o

	#ifdef  DEBUG_TEST
	PrintList( Head);
	printf( "\n\n" );
	#endif

	FreeList(Head);

	return 0;
}


//--------
int Compare( const void* p, const void* q )
{
	if (((ListInfo*)p)->nKey > ((ListInfo*)q)->nKey)
		return 1;
	if (((ListInfo*)p)->nKey == ((ListInfo*)q)->nKey)
		return 0;
	return -1;
}

//--------

void PrintList( ListItem* pList )
{
	ListItem* p = Front( pList );
	while (p)
	{
		printf( "%d ", p->pList->nKey );
		p = p->m_pNext;
	}
}


