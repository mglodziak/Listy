#include "global.h"
#include "Operacje_na_listach.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int isEmpty( ListItem* pList )
{
	return !(pList->m_pNext); 
}

void Insert( ListItem* pAfter, LISTINFO* pList )
{
	ListItem* p = (ListItem*)calloc(1, sizeof( ListItem ) );

	if (!p)
	{
		printf( "Insert: Error" );
		return;
	}
	

		p->pList = pList;
		p->m_pNext = pAfter->m_pNext;
		pAfter->m_pNext = p;
}

void FreeList( ListItem* pList )
{
	while (pList->m_pNext)
		RemoveOnFront( pList );
}
void InsertOnFront( ListItem* pList, LISTINFO* pInfo )
{
	Insert ( pList, pInfo );
}
 void Remove( ListItem* pAfter )
{
	if (isEmpty( pAfter )) 
	{
		printf( "ERROR: Kolejka juz jest pusta!! " );
		return;
	}

	ListItem* p = pAfter->m_pNext;
	pAfter->m_pNext = p->m_pNext;

	free( p->pList );
	free( p );
}
void RemoveOnFront( ListItem* pList )
{
	Remove( pList );
}
ListItem* CreateEmptyList()
{
	ListItem* pHead = (ListItem*)calloc(1, sizeof( ListItem ) );
	if (!pHead)
	{
		printf( "Error: Brak pamieci pHead..." );
		return 0;
	}
	LISTINFO* pData = (LISTINFO*)calloc( 1, sizeof LISTINFO );
	if (!pData)
	{
		printf( "Error: Brak pamiêci pData" );
		return 0;
	}
	//pData->nKey = NULL;
	pHead->pList = pData;
	//pHead->m_pNext = NULL;

	return pHead;
}

ListItem* Front( ListItem* pList )
{
	if (!isEmpty( pList )) // jesli lista nie jest pusta!!!
		return pList->m_pNext; // zwraca pierwszy element listy, wkaŸnik przestawiony na kolejny
	return 0; // jesli pusta
}
void DelList( ListItem** pHead )
{
	FreeList( *pHead );
	free( *pHead );
	*pHead = NULL;
}
ListItem* Find( ListItem* pList, const void* x, ListItem** pPrev, int( __cdecl *Compare )(const void*, const void*) )
{
	ListItem* p = pList->m_pNext;
	*pPrev = pList; // czy aby na pewno???, tak na pewno. 

	while (p->m_pNext)
	{
		if (Compare( x, ((const void*)p->m_pNext->pList) ) == 0) // porównaj dane wejsciowe do funkcji z lista, jesli zero tzn, ze trafilismy
			return p;
		*pPrev = p;	 // jesli nie to przestaw wskazniki, szukaj dalej
		p = p->m_pNext;
	}
	
	return *pPrev = NULL; //na koniec listy daj null.;
}

void SortList( ListItem* pList, int( __cdecl *Compare )(const void*, const void*) ) 
{
	ListItem* pS = pList;
	while (pS->m_pNext)
	{
		ListItem* min_listy = pS; // przypisanie wskaŸników
		ListItem* next_element = min_listy->m_pNext;
		while (next_element->m_pNext)
		{
			if (Compare( (const void*)(min_listy->m_pNext->pList), (const void*)(next_element->m_pNext->pList) ) == 1) // jak dam minus 1 to posortuje malej¹co
				min_listy = next_element;

			next_element = next_element->m_pNext;
		}
		if (pS != min_listy)		//jeœli nie znajduje siê na pocz¹tku minimum czyli nieposortowane, jesli min bêdzie na pocz¹tku to znaczy, ¿e posortowane
		{
			next_element = min_listy->m_pNext->m_pNext;
			min_listy->m_pNext->m_pNext = pS->m_pNext;
			pS->m_pNext = min_listy->m_pNext;
			min_listy->m_pNext = next_element;
		}
		pS = pS->m_pNext; // kolejny element listy
	}
}
