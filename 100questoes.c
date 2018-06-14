/*50 QUESTÕES(2) BY PEDRO SILVA*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

int length (LInt l){
    int leng;
    for (leng = 0; l;l=l->prox,leng++);
    return leng;
}

void freeL (LInt l){
    LInt p;
    while (l){
        p = l->prox;
        free(l);
        l = p;
    }
}

void imprimeL (LInt l){
    while(l){
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

LInt reverseL (LInt l){
    LInt p=l, ant=NULL;
    while (l){
        p = l->prox;
        l->prox = ant;
        ant = l;
        l = p;
    }
    l = ant;
    return l;
}

void insertOrd (LInt *l, int x){
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    while(*l && x > (*l)->valor)
        l = &((*l)->prox);
    new->prox = *l;
    *l = new;
}

int removeOneOrd (LInt *l, int x){
    LInt p;
    int r=1;
    while(*l && (*l)->valor < x)
       l=&((*l)->prox);
    if(*l){
       p=(*l)->prox;
       free(*l);
       *l=p;
       r=0;
   }
   return r;
}

void merge (LInt *r, LInt l1, LInt l2) {

    while (l1 != NULL && l2 != NULL)
        if (l1->valor < l2->valor) {
            *r = l1;
            r = &((*r)->prox);
            l1 = l1->prox;
        } else {
            *r = l2;
            r = &((*r)->prox);
            l2 = l2->prox;
        }

    if (l1 == NULL) *r = l2;
    else *r = l1;
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while (l){
        if(l->valor<x){
            *mx = l;
            mx = &((*mx)->prox);
        }
        else{
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }
    *mx=*Mx=NULL;
}

LInt parteAmeio (LInt *l){
    int halfleng = length(*l)/2;
    LInt* p = l, k=*l;
    int i;
    for (i=0; i<halfleng; i++) 
        p = &((*p)->prox);
    *l=*p;
    *p = NULL;
    if (!(halfleng)) {
    	*l=k;
    	return NULL;
    }
    else return k;
 }

int removeAll (LInt *l, int x){
   int count=0;
   LInt p;
   while(*l){
        if((*l)->valor == x){
            count++;
            p=(*l)->prox;
            free(*l);
            *l=p;
        }
        else l=&((*l)->prox);
    }
    return count;
}

int removeDups (LInt *l){
    int count=0;
    while(*l){
        count += removeAll(&((*l)->prox),(*l)->valor);
        l=&((*l)->prox);
    }
    return count;
}

int removeMaiorL (LInt *l){
    LInt *p = l; int maior = (*l)->valor;
    while (*p){
        if ((*p)->valor > maior) maior = (*p)->valor;
        p = &((*p)->prox);
    }
    while (*l){
        if ((*l)->valor == maior) {
            p = &((*l)->prox);
            free(*l);
            *l=*p;
            return maior;
        }
        else l = &((*l)->prox);
    }
    return maior;
}

void init (LInt *l){
    while (*l && (*l)->prox) l = &((*l)->prox);
    free (*l);
    *l = NULL;
}

void appendL (LInt *l, int x){
    while (*l) l = &((*l)->prox);
    *l = malloc(sizeof(struct lligada));
    (*l)->valor = x;
    (*l)->prox = NULL;
}

void concatL (LInt *l, LInt b){
    while (*l ) l = &((*l)->prox);
    (*l) = b;
}

LInt cloneL (LInt l){
	LInt r, *e=&r;
	while(l){
		*e = malloc(sizeof(struct lligada));
		(*e)->valor = l->valor;
		l = l->prox;
		e = &((*e)->prox);
	}
	*e=NULL;
	return r;
}

LInt cloneRev (LInt l){
    LInt r, ant=NULL;
    while (l){
        r = malloc (sizeof(struct lligada));
        r -> valor = l ->valor;
        r -> prox = ant;
        ant = r;
        l = l->prox;
    }
    return r;
}

int maximo (LInt l){
    int max = l->valor;
    l = l->prox;
    while (l){
        if (l->valor > max) max = l->valor;
        l = l->prox;
    }
    return max;
}

int take (int n, LInt *l){
    LInt *p;
    int count;
    for (count=0 ; count < n && *l ; l = &((*l)->prox),count++);
    while (*l){
        p = &((*l)->prox);
        free(*l);
        *l = *p;
    }
    return count;
}

int drop (int n, LInt *l){
    int count;
    LInt *p;
    for (count=0; count<n && *l; count++){
        p = &((*l)->prox);
        free(*l);
        *l=*p;
    }
    return count;
}

LInt NForward (LInt l, int n){
    for(; l && n>0; n--, l = l->prox);
    return l;
}

int listToArray (LInt l, int v[], int N){
    int i;
    for (i=0; i<N && l; l=l->prox, i++){
        v[i] = l->valor;
    }
    return i;
}

LInt arrayToList (int v[], int N){
    LInt r=NULL, *er = &r;
    int i;
    for(i=0; i<N; i++){
        (*er )= malloc (sizeof(struct lligada));
        (*er)->valor = v[i];
        er = &((*er)->prox);
    }
    return r;
}

LInt somasAcL (LInt l) {
    int soma=0;
    LInt r, *er = &r;
    while (l){
        soma += l->valor;
        (*er )= malloc (sizeof(struct lligada));
        (*er)->valor = soma;
        er = &((*er)->prox);
        l = l->prox;
    }
    *er = NULL;
    return r;
}

void remreps (LInt l){
    LInt p, pt;
    while(l)
    {   p = l->prox;
        while(p && l->valor == p->valor){
            pt = p->prox;
            free(p);
            p = pt;
        }
        l->prox = p;
        l = l->prox;
    }
}

LInt rotateL (LInt l){
    LInt *p=&l,r=NULL;
    while(*p)
        p=&((*p)->prox);
    *p=l;
    if(l){
        r = l->prox;
        l->prox = NULL;
    }
    return r;
}

/*ATENÇAO, A FUNÇAO "PARTE" NÃO PARTE A LISTA EM VALORES PARES E IMPARES MAS SIM EM 
  POSIÇOES PARES E POSIÇOES IMPARES!!!!*/

LInt parte (LInt l){
	LInt pares;
	LInt *ep =&pares;
	while(l){
		if(l->prox){
  			*ep=l->prox;
  			ep=&(l->prox->prox);
  			l->prox=l->prox->prox;
		}
		l=l->prox;
	}
	*ep=NULL;
	return pares;
}

//OU
/* not my version */
LInt parte (LInt l){
    if (l == NULL || l -> prox == NULL) return NULL;
    else {
        LInt topEven = l -> prox;
        while (l -> prox) {
            LInt temp = l -> prox;
            l -> prox = temp -> prox;
            l = temp;
        }
        return topEven;
    }
}

ABin cloneAB (ABin a) {
   ABin r;
   if (!a) r=NULL;
    else{
        r = (ABin)malloc(sizeof(struct nodo));
        r->valor = a->valor;
        r->esq = cloneAB(a->esq);
        r->dir = cloneAB(a->dir);
    }    
    return r;
}
int max (int x, int y){
    if (x>y) return x;
    else return y;
}

int altura (ABin a)
{
    int r=0,altesq=0,altdir=0;
    if (a){
        altesq = altura (a->esq);
        altdir = altura (a->dir);
        r = 1 + max (altesq,altdir);
    }
    return r;
}

//OU
/* adaptada à minha versão */
#define MAX(x,y) ((x) > (y) ? (x) : (y))

int altura (ABin a){
    return (a == NULL) ? -1 : 1 + MAX(altura(a->dir), altura(a->esq));
}

void mirror (ABin *a) {
    ABin r;
    if (*a){
        r = (*a)->dir;
        (*a)->dir = (*a)->esq;
        (*a)->esq = r;
        
        mirror(&((*a)->dir));
        mirror(&((*a)->esq));
      
    }
}

LInt* inorder(ABin a, LInt *l){
    if(a == NULL)
        (*l) = NULL;
    else{
        inorder(a->esq, l);
        while(*l)
            l = &((*l)->prox);
        (*l) = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &((*l)->prox);
        inorder(a->dir, l);
    }
    return l;
}

void preorder(ABin a, LInt *l){
    LInt pt;
    if (a == NULL) *l = NULL;
    else{
        *l = malloc(sizeof(lligada));
        (*l)->valor = a->valor;
        preorder(a->esq, &(*l)->prox);
        pt = *l;
        while (pt->prox != NULL)
            pt = pt->prox;
        preorder(a->dir, &pt->prox);
    }
}

void posorder (ABin a, LInt *l){
    if(a == NULL) *l = NULL;
    else{
        posorder(a->esq, l);
        while(*l)
            l = &((*l)->prox);
        posorder(a->dir, l);
        while(*l)
            l = &((*l)->prox);
        (*l) = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL; 
    }
}

int depth (ABin a, int x) {
    int r = 1, ld = 0, rd = 0;
    if (a == NULL) return -1;
    if (a -> valor == x) return 1;
    else {
        ld = depth (a -> esq, x);
        rd = depth (a -> dir, x);
        if (rd < 0) r += ld;
        if (ld < 0) r += rd;
        if (rd > 0 && ld > 0 && ld > rd) r += rd;
        if (rd > 0 && ld > 0 && ld < rd) r += ld;
    }
    return r;
}

int freeAB (ABin a) {
    int count=0,countd=0, counte=0;
    if (a){
        if (a->esq) counte = freeAB(a->esq);
        if (a->dir) countd = freeAB(a->dir);
        free(a);
        count += (counte + countd + 1);
    }
    return count;
}

int pruneAB (ABin *a, int l) {
    int count=0;
    if (*a){
        count += pruneAB(&((*a)->esq),l-1);
        count += pruneAB(&((*a)->dir),l-1);
        if (l<1){
            free(*a);
            *a = NULL;
            count++;
        }
    }
    return count;
}

int iguaisAB (ABin a, ABin b) {
    int r=0;
    if (a && b){
        if (a->valor == b->valor){
            r=1;
        } else r=0;
        r &= iguaisAB(a->esq,b->esq);
        r &= iguaisAB(a->dir,b->dir);
    }
    if (!a && !b) r=1;
    return r;
}

LInt nivelL (ABin a, int n) {
    LInt l1 = NULL, l2 = NULL, temp;
    if (a) {
        if (n == 1) {
            l1 = malloc (sizeof (struct lligada));
            l1 -> valor = a -> valor;
            l1 -> prox = NULL;
        }
        else {
            l1 = nivelL (a -> esq, n - 1);
            l2 = nivelL (a -> dir, n - 1);
            if (l1) {
                temp = l1;
                while (temp && temp -> prox) temp = temp -> prox;
                l1 -> prox = l2;
            }
            else if (l2) return l2;
        }
    }
    return l1;
}

int nivelV (ABin a, int n, int v[]) {
    int i = 0, esq = 0, dir = 0;
    if (a) {
        if (n == 1) {
            v [i] = a -> valor; 
            i++;
        }
        else {
            esq = nivelV (a -> esq, n - 1, v);
            dir = nivelV (a -> dir, n - 1, v + esq);
            i = esq + dir;
        }
    }
    return i;
}

int dumpAbin (ABin a, int v[], int N) {
    int i = 0, esq = 0, dir = 0;
    if (a) {
        if (a -> esq) esq = dumpAbin (a -> esq, v, N);
        if (esq < N) {
            v [esq] = a -> valor;
            i++;
        }
        if (esq + 1 < N && a -> dir) dir = dumpAbin (a -> dir, v, N - esq - 1); 
        i = i + esq + dir;
    }
    return i;
}

int soma_subarvores (ABin a) {
    int r = 0, rd = 0, re = 0;
    if (a) {
        if (a -> esq) re = soma_subarvores (a -> esq);
        if (a -> dir) rd = soma_subarvores (a -> dir);
        r = a -> valor + re + rd;
    }
    return r;
}

ABin somasAcA (ABin a) {
    ABin r; 
    if (a) {
        r = malloc (sizeof (struct nodo));
        r -> valor = soma_subarvores (a);
        r -> dir = NULL; r -> esq = NULL;
        if (a -> esq) r -> esq = somasAcA (a -> esq);
        if (a -> dir) r -> dir = somasAcA (a -> dir);
    }
    return r;
}

int contaFolhas (ABin a) {
    int c = 0,esq=0,dir=0;
    if (a){
        if (!(a->esq) && !(a->dir)) c++;
        esq = contaFolhas(a->esq);
        dir = contaFolhas(a->dir);
        c += esq + dir;
    }
    return c;
}

ABin cloneMirror (ABin a) {
    ABin r = NULL; 
    if (a) {
        r = malloc (sizeof (struct nodo));
        r -> valor = a -> valor;
        r -> dir = r -> esq = NULL;
        if (a -> dir) r -> esq = cloneMirror (a -> dir);
        if (a -> esq) r -> dir = cloneMirror (a -> esq);
    }
    return r;
}

int addOrd (ABin *a, int x) {
    int r = 0;
    
    while (*a && !r) {
        if ((*a) -> valor == x) r = 1;
        else {
            if ((*a) -> valor > x) a = & ((*a) -> esq);
            else 
            	if ((*a) -> valor < x) a = & ((*a) -> dir);
        }
    }
    
    if (!(*a)) {
        *a = malloc (sizeof (struct nodo));
        (*a) -> valor = x;
        (*a) -> esq = (*a) -> dir = NULL;
    }
    return r;
}

int lookupAB (ABin a, int x) {
    while(a){
        if (x == a->valor) return 1;
        if (x > a->valor) a = a -> dir;
        else a = a ->esq;
    }
    return 0;
}

int maiorAB (ABin a) {
    while (a && a->dir) a = a -> dir;
    return a->valor;
}

int depthOrd (ABin a, int x){
    int r;
    if(!a) return -1;
    if(a->valor == x) return 1;
    if(a->valor > x)
        r = depthOrd(a->esq, x);
    else
        r = depthOrd(a->dir, x);
    if (r == -1) return -1;
    else return (r+1);
}

void removeMaiorA (ABin *a) {
    while (*a && (*a)->dir) a = &((*a)->dir);
    free(*a);
    *a = (*a)->esq;
}

int quantosMaiores (ABin a, int x) {
    int c=0,esq=0,dir=0;
    if (a){
        if (a->valor > x) c++;
        esq = quantosMaiores(a->esq,x);
        dir = quantosMaiores(a->dir,x);
        c+= esq + dir; 
    }
    return c;
}

void listToBTree (LInt l, ABin *a) {
    while (l){
        (*a) = malloc (sizeof(struct nodo));
        (*a) -> valor = l ->valor;
        (*a) -> esq = NULL;
        a = &((*a)->dir);
        l = l -> prox;
    }
}

int maior(ABin a , int x){
  int r = 0;     
  if(a == NULL) r = 1;
  else if(a->valor > x && maior(a->dir,x) && maior(a->esq,x)) r = 1;
  return r;
}

int menor(ABin a , int x){
  int r = 0;
  if(a == NULL) r = 1;
  else if(a->valor < x && menor(a->dir,x) && menor(a->esq,x)) r = 1;
     
  return r;
}
 
/* not my version */
int deProcura (ABin a){
	int r=0;
	if (a == NULL) r = 1;
  else if( menor(a->esq,a->valor) && maior(a->dir,a->valor) && deProcura(a->dir) && deProcura(a->esq)) r= 1;
	return r;
}
