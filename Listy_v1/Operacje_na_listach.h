#ifndef _OPERACJE_NA_LISTACH_H
#define _OPERACJE_NA_LISTACH_H

#include "global.h"
typedef struct tagListItem
{
	LISTINFO* pList;
	tagListItem* m_pNext;
}ListItem;




int isEmpty( ListItem* pList );										//zwraca 0 lub 1 w zale�no�ci czy stos jest pusty czy lub nie
void FreeList( ListItem* pList );									//czy�ci list�, robi j� pust�
void Insert( ListItem* pAfter, LISTINFO* pInfo );					//wstawia po wska�niku wskazany parametr
void InsertOnFront( ListItem* pList, LISTINFO* pInfo );				//wstawiam na pocz�tek now� informacj�, odpowiednik funkcji push
void Remove( ListItem* pAfter );									//po tym elemencie kt�ry przekazuje wska�nik
void RemoveOnFront( ListItem* pList );								//Usuwa pierwszy istotny element
ListItem* CreateEmptyList();										//je�li funkcja zwr�ci NULL tzn �e nast�pi� b��d
ListItem* Front( ListItem* pList );									//zwraca szczytowy element (zwraca ca�y element listy) (odpowiednik funkcji top)
void DelList( ListItem** pHead );									//Usuwa ca�� list�
ListItem* Find( ListItem* pList, const void* x, ListItem** pPrev, int( __cdecl *Compare )(const void*, const void*) );  //wsk do szukanego const void* - czyli wska�nik na funkcj� compare , pPrev );
void SortList( ListItem* pList, int( *pF )(const void*, const void*) );    /*wska�nik do funkcji otrzymuj�cej dwa parametry const void* i zwracaj�cej int*  );*/

#endif