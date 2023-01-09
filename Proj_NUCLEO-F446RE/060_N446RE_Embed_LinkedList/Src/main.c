/**/

#if 0
#include <stdio.h>

typedef int Data;	//pseudonim
typedef struct Node Node;

struct Node
{
	Data data;			//Memorarea efectiva a numarului
	Node* next;			//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
};						//Обратите внимание, что структура тут создаётся в виде рекурсивного дерева.


/***************************MAIN*******************/
int main(void)
{
	Node*  list=NULL;		//Declararea listei vida

	Node a={3}, b={17}, c={21}, t={10};
	list = &a;
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("Hello\n");				fflush(stdout);

	printf("a data= %d\n",a.data);	fflush(stdout);
	printf("b data= %d\n",b.data);	fflush(stdout);
	printf("c data= %d\n",c.data);	fflush(stdout);
	printf("\n");					fflush(stdout);


	return 0;
}
#endif


#if 0
#include <stdio.h>

typedef int Data;	//pseudonim
typedef struct Node Node;

struct Node
{
	Data data;			//Memorarea efectiva a numarului
	Node* next;			//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
};
/***************************MAIN*******************/
int main(void)
{

//Node*  list=NULL;		//Declararea listei vida

	Node a={3}, b={17}, c={21}, t={10};

	//Node s;
	//s.data=333;

//	list = &a;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("Hello\n");				fflush(stdout);

	printf("a data= %d\n",a.data);	fflush(stdout);
	printf("b data= %d\n",b.data);	fflush(stdout);
	printf("c data= %d\n",c.data);	fflush(stdout);

//	printf("s data= %d\n",s.data);	fflush(stdout);
	printf("\n");					fflush(stdout);

	return 0;
}//END MAIN
#endif


#if 0
#include <stdio.h>

//typedef int Data;	//pseudonim
typedef struct Node Node;

struct Node
{
	int	 data;			//Memorarea efectiva a numarului
	Node* next;			//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
};
/***************************MAIN*******************/
int main(void)
{

//Node*  list=NULL;		//Declararea listei vida

	Node a={3}, b={17}, c={21}, t={10};

	//Node s;
	//s.data=333;

//	list = &a;

	Node *p;
	p=&a;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("Hello\n");				fflush(stdout);

	printf("a data= %d\n",p->data);	fflush(stdout);
	p=p->next;
	printf("b data= %d\n",p->data);	fflush(stdout);
	p=p->next;
	printf("c data= %d\n",p->data);	fflush(stdout);

//	printf("s data= %d\n",s.data);	fflush(stdout);
	printf("\n");					fflush(stdout);

	return 0;
}//END MAIN
#endif


#if 0
/**/
#include <stdio.h>

//typedef int Data;	//pseudonim
typedef struct Node Node;

struct Node
{
	int	 data;			//Memorarea efectiva a numarului
	Node* next;			//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
};
/***************************MAIN*******************/
int main(void)
{

//Node*  list=NULL;		//Declararea listei vida

	Node a={3}, b={17}, c={21}, t={10};

	//Node s;
	//s.data=333;

//	list = &a;

	Node *p;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("Hello\n");				fflush(stdout);

	for(p=&a; p!=NULL; p=p->next){
		printf("a data= %d\n",p->data);	fflush(stdout);
		}
	printf("\n");					fflush(stdout);

	return 0;
}//END MAIN

#endif


#if 0
/*am adaugat o functie care sami printeze lista
 * penntru asta am facut un pointer care sa indice la capul listei
 * CUM DE FACUT FARA POINTERUL list*/
#include <stdio.h>

 typedef struct Node
{
	int	 data;				//Memorarea efectiva a numarului
	struct Node* next;		//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
}Node_t;

void print(Node_t *list){

	for(Node_t* p=list; p!=NULL; p=p->next){
			printf("a data= %d\n",p->data);	fflush(stdout);
			}
		printf("\n");					fflush(stdout);
}
/***************************MAIN*******************/
int main(void)
{
	/*NULL nu influenteaza la nimic*/
//	Node_t*  list=NULL;		//Declararea listei vida
	Node_t*  list;			//Declararea listei vida

	Node_t a={3}, b={17}, c={21}, t={10};

	list = &a;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("Hello\n");				fflush(stdout);

	print (list);

	return 0;
}//END MAIN
#endif

#if 0
/*adaugam nodul t intre cap si a
 * in p inscriem adresa lui t si inscriem in p-> next=list*/
#include <stdio.h>

 typedef struct Node
{
	int	 data;				//Memorarea efectiva a numarului
	struct Node* next;		//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
}Node_t;

void print(Node_t *list){
	for(Node_t* p=list; p!=NULL; p=p->next){
			printf("a data= %d\n",p->data);	fflush(stdout);
			}
		printf("\n");					fflush(stdout);
}


/***************************MAIN*******************/
int main(void)
{
	/*NULL nu influenteaza la nimic*/
//	Node_t*  list=NULL;		//Declararea listei vida
	Node_t*  list;			//Declararea listei vida

	Node_t a={3}, b={17}, c={21}, t={10};

	list = &a;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("Hello\n");				fflush(stdout);

	print (list);

	//asa:
//	t.next=&a;
//	list=&t;

	//sau asa
	Node_t *p=&t;
	p->next=&a;
	list=p;

	print (list);

	return 0;
}//END MAIN
#endif

#if 1
/*acum creem funtia push care adauga un element nou*/
#include <stdio.h>
#include <stdlib.h>


 typedef struct Node
{
	int	 data;				//Memorarea efectiva a numarului
	struct Node* next;		//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
}Node_t;

void push(Node_t **plist, int  d);

void print(Node_t *list);

void print(Node_t *list){

	for(Node_t* p=list; p!=NULL; p=p->next){
			printf("a data= %d\n",p->data);	fflush(stdout);
			}
		printf("\n");					fflush(stdout);
}

void push(Node_t **plist, int d){
	//asa:
	//	t.next=&a;
	//	list=&t;

	//sau asa
	Node_t *p=malloc(sizeof(Node_t));
	p->data=d;
	p->next=*plist;
	*plist=p;
}

/***************************MAIN*******************/
int main(void)
{
	/*NULL nu influenteaza la nimic*/
//	Node_t*  list=NULL;		//Declararea listei vida
	Node_t*  list;			//Declararea listei vida

	Node_t a={3}, b={17}, c={21}, t={10};

	list = &a;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	printf("Hello\n");				fflush(stdout);

	print (list);

	push(&list,10);

	print (list);

	return 0;
}//END MAIN
#endif




#if 0
/*teste functiei push*/
#include <stdio.h>
#include <stdlib.h>


 typedef struct Node
{
	int	 data;				//Memorarea efectiva a numarului
	struct Node* next;		//Memorarea legaturii catre urmatorul nod //indicator la struct Node //compilatorul stie ca Node este nume typedef
}Node_t;

void push(Node_t **plist, int  d);

void print(Node_t *list);

void print(Node_t *list){

	for(Node_t* p=list; p!=NULL; p=p->next){
			printf("a data= %d\n",p->data);	fflush(stdout);
			}
		printf("\n");					fflush(stdout);
}

void push(Node_t **plist, int d){
	//asa:
	//	t.next=&a;
	//	list=&t;

	//sau asa
	Node_t *p=malloc(sizeof(Node_t));
	p->data=d;
	p->next=*plist;
	*plist=p;
}

/***************************MAIN*******************/
int main(void)
{
	int test[]={21, 17, 3, 10};
	/*NULL nu influenteaza la nimic*/
//	Node_t*  list=NULL;		//Declararea listei vida
	Node_t*  list;			//Declararea listei vida

	for(size_t i=0; 1<sizeof(test)/sizeof(test[0]); i++)
	{
		push(&list, test[i]);
		print(list);
	}

	printf("Hello\n");				fflush(stdout);

	print (list);

	push(&list,10);

	print (list);

	return 0;
}//END MAIN
#endif

