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

#if 0
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


#if 0
/*************************POINTERS**********************************************
 * cream o variabila si doua pointere
 * afisam adresa si valoare variabilei
 * initiem aldoilea pointer cu adresa variabilei
 * afisam adresa si valoarea pointelor
 * */

#include <stdio.h>
#include <stdlib.h>


/***************************MAIN*******************/
int main(void)
{
	printf("Hello\n");	fflush(stdout);

	uint32_t TestVariable =100;

	uint32_t *pPointer=(uint32_t *) 0x2001fff5;

	uint32_t *pPointertoVar=&TestVariable;


	printf("TestVariable value=%d\n", TestVariable);	fflush(stdout);
	printf("TestVariable address=%x\n",&TestVariable);	fflush(stdout);

	printf("pPointer value=%p\n",pPointer);				fflush(stdout);	//печатаем значение указателя
	printf("pPointer address=%x\n",&pPointer);			fflush(stdout); //печатем адрес указателя.
	uint32_t pointAddresVariable;

	pointAddresVariable=*pPointer;

	printf("\r\n");		fflush(stdout);
	printf("pointAddresVariable value=%x\n",pointAddresVariable);	fflush(stdout); //печатаем содержание на котром указывает указатель

	printf("pPointertoVar value=%p\n",pPointertoVar);		fflush(stdout);
	printf("pPointertoVar address=%x\n",&pPointertoVar);	fflush(stdout);
	printf("\r\n");		fflush(stdout);

	printf("Type long unsigned int - %u byte\r\n", sizeof(long unsigned int)); fflush(stdout);
	printf("Type long  - %u byte\r\n", sizeof(long)); fflush(stdout);
	printf("Type int  - %u byte\r\n", sizeof(int)); fflush(stdout);
	return 0;
}//END MAIN
#endif

#if 1
/*************************POINTERS**********************************************
 * cream o variabila si doua pointere
 * afisam adresa si valoare variabilei
 * initiem aldoilea pointer cu adresa variabilei
 * afisam adresa si valoarea pointelor
 * */

#include <stdio.h>
#include <stdlib.h>


/***************************MAIN*******************/
int main(void)
{
	printf("Hello\n");	fflush(stdout);

	uint32_t *pPointer=(uint32_t *) 0x20000008;

	uint32_t pointAddresVariable=*pPointer;	//эта опереация называется разыменование указателя

	printf("\r\n");		fflush(stdout);

	printf("pPointer address (location)=%x\n",&pPointer);	fflush(stdout);

	printf("pPointer value=%p\n",pPointer);	fflush(stdout);

	printf("pointAddresVariable value=%x\n",pointAddresVariable);	fflush(stdout); //печатаем содержание на котром указывает указатель

	printf("dereferencing value=%x\n",*pPointer);				fflush(stdout); //печатаем содержание на котром указывает указатель

	printf("adr = %08x\n", &pPointer);

	printf("\r\n");		fflush(stdout);


}//END MAIN
#endif


