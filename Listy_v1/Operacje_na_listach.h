#ifndef _OPERACJE_NA_LISTACH_H
#define _OPERACJE_NA_LISTACH_H

#include "global.h"
typedef struct tagListItem
{
	LISTINFO* pList;
	tagListItem* m_pNext;
}ListItem;




int isEmpty( ListItem* pList );										//zwraca 0 lub 1 w zale¿noœci czy stos jest pusty czy lub nie
void FreeList( ListItem* pList );									//czyœci listê, robi j¹ pust¹
void Insert( ListItem* pAfter, LISTINFO* pInfo );					//wstawia po wskaŸniku wskazany parametr
void InsertOnFront( ListItem* pList, LISTINFO* pInfo );				//wstawiam na pocz¹tek now¹ informacjê, odpowiednik funkcji push
void Remove( ListItem* pAfter );									//po tym elemencie który przekazuje wskaŸnik
void RemoveOnFront( ListItem* pList );								//Usuwa pierwszy istotny element
ListItem* CreateEmptyList();										//jeœli funkcja zwróci NULL tzn ¿e nast¹pi³ b³¹d
ListItem* Front( ListItem* pList );									//zwraca szczytowy element (zwraca ca³y element listy) (odpowiednik funkcji top)
void DelList( ListItem** pHead );									//Usuwa ca³¹ listê
ListItem* Find( ListItem* pList, const void* x, ListItem** pPrev, int( __cdecl *Compare )(const void*, const void*) );  //wsk do szukanego const void* - czyli wskaŸnik na funkcjê compare , pPrev );
void SortList( ListItem* pList, int( *pF )(const void*, const void*) );    /*wskaŸnik do funkcji otrzymuj¹cej dwa parametry const void* i zwracaj¹cej int*  );*/

#endif