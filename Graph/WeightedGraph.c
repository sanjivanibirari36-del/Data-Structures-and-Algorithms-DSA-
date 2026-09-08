#include <stdio.h>
#include <malloc.h>

struct vertex
{
	struct vertex *pNextVertex;
	int iData;
	struct edge *pAdjEdge;
};

struct edge
{
	struct vertex *pAdjVertex;
	int iWeight;
	struct edge *pNextEdge;
};

void InsertVertex(struct vertex **, int);
void InsertEdge(struct vertex **, struct vertex *, int, int); 
void Display(struct vertex *);
void DeleteAll(struct vertex **);

int main(void)
{
	int iVertices;
	int iCounter1;
	int iNo;
	int iEdgeWeight;
	struct vertex *pRoot = NULL;
	struct vertex *pTemp = NULL;
	
	printf("How many vertices you want(<10)?\n");
	scanf("%d", &iVertices);
	
	for(iCounter1 = 0; iCounter1 < iVertices; iCounter1++)
	{
		printf("Enter vertex: ");
		scanf("%d", &iNo);
		InsertVertex(&pRoot, iNo);
	}
	printf("\n");
	pTemp = pRoot;
	
  while(pTemp != NULL)
  {
		printf("How many adjacent vertices for %d?\n", pTemp->iData);
		scanf("%d", &iNo);
		
		for(iCounter1 = 0; iCounter1 < iNo; iCounter1++)
		{
			printf("Enter %d vertex: \n", iCounter1+1);
			scanf("%d", &iVertices);
			
			printf("Enter edge weight: \n");
			scanf("%d", &iEdgeWeight);
			
			if(iEdgeWeight == 0)
				continue;
			
			InsertEdge(&pRoot, pTemp,	iVertices, iEdgeWeight);
		}
		printf("\n");
		pTemp = pTemp->pNextVertex;
	} 
	
	Display(pRoot);
	
	DeleteAll(&pRoot);
	if(pRoot == NULL)
		printf("\nGraph is empty!\n");
	else
		printf("\nGraph is not empty!\n");
	
	return 0;
}

void InsertVertex(struct vertex **ppRoot, int iNo)
{
	struct vertex *pNewVertex = NULL;
	struct vertex *pTemp = NULL;
		
	pNewVertex = (struct vertex *)malloc(sizeof(struct vertex));
	if(pNewVertex == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}
		
	pNewVertex->iData = iNo;
	pNewVertex->pNextVertex = pNewVertex->pNextVertex = NULL;
		
	if(*ppRoot == NULL)
	{
		*ppRoot = pNewVertex;
		return;
	}
	
	pTemp = *ppRoot;
	
	while(pTemp->pNextVertex != NULL)
		pTemp = pTemp->pNextVertex;
		
	pTemp->pNextVertex = pNewVertex;
}

void InsertEdge(struct vertex **ppRoot, struct vertex *pVertex, int iAdjVertex, int iEdgeWeight)
{
	struct edge *pNewEdge = NULL;
	struct vertex *pTemp1 = NULL;
	struct edge *pTemp2 = NULL;
	
	if(*ppRoot == NULL)
		return;
		
	pNewEdge = (struct edge *)malloc(sizeof(struct edge));
	if(pNewEdge == NULL)
	{
		printf("Memory allocation failed!\n");
		return;
	}
	
	pNewEdge->iWeight = iEdgeWeight;
	pNewEdge->pNextEdge = NULL;
	
	pTemp1 = *ppRoot;
	while(pTemp1 != NULL)
	{
		if(pTemp1->iData == iAdjVertex)
			break;
		pTemp1 = pTemp1->pNextVertex;
	}
	
	if(pTemp1 == NULL)
	{
		printf("Invalid vertex!\n");
		return;
	}
	pNewEdge->pAdjVertex = pTemp1;

	if(pVertex->pAdjEdge == NULL)
	{
		pVertex->pAdjEdge = pNewEdge;
		return;
	}
	
	pTemp2 = pVertex->pAdjEdge;
	
	while(pTemp2->pNextEdge != NULL)
		pTemp2 = pTemp2->pNextEdge;
		
	pTemp2->pNextEdge = pNewEdge;
}	

void Display(struct vertex *pRoot)
{
	struct edge *pEdge = NULL;
	
	if(pRoot == NULL)
	{
		printf("Graph is empty!\n");
		return;
	}
	
	while(pRoot != NULL)
	{
		printf("%d-> ", pRoot->iData);
		
		pEdge = pRoot->pAdjEdge;
		
		while(pEdge != NULL)
		{
			printf("%d", pEdge->pAdjVertex->iData);
			printf("(%d) ", pEdge->iWeight);
			
			pEdge = pEdge->pNextEdge;
		}
		printf("\n");
		
		pRoot = pRoot->pNextVertex;
	}
}

void DeleteAll(struct vertex **ppRoot)
{
	struct vertex *pTemp1 = NULL;
	struct edge *pTemp2 = NULL;
	
	if(*ppRoot == NULL)
		return;
	
	pTemp1 = *ppRoot;
	
	while(pTemp1 != NULL)
	{
		pTemp2 = pTemp1->pAdjEdge;
		while(pTemp2 != NULL)
		{
			pTemp1->pAdjEdge = pTemp2->pNextEdge;
			pTemp2->pAdjVertex = NULL;
			pTemp2->pNextEdge = NULL;
			free(pTemp2);
			
			pTemp2 = pTemp1->pAdjEdge;
		}
		
		pTemp1 = pTemp1->pNextVertex;
	}
	
	while(*ppRoot != NULL)
	{
		pTemp1 = *ppRoot;
		*ppRoot = pTemp1->pNextVertex;
		pTemp1->pNextVertex = NULL;
		free(pTemp1);
	}
}			
