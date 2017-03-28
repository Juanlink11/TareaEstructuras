#include <stdio.h>
#include <stdlib.h>



struct nodo{
	int dato;
	struct nodo* sig;
	struct nodo* ant;
};

typedef struct nodo* ListEn;

ListEn crearListEn(){
	ListEn lst;
	lst = NULL;
	return lst;
}

int longListEn(ListEn lst){
	ListEn tmp;
	int cont = 0;
	tmp = lst;
	while(tmp != NULL){
		tmp = tmp->sig;
		cont++;
	}
	return cont;
}

ListEn anxListEn(ListEn lst, int elem){
	ListEn nuevo, tmp;
	nuevo = (ListEn) malloc(sizeof(struct nodo));
	nuevo->dato = elem;
	nuevo->sig = NULL;
	nuevo->ant = NULL;
		if(lst == NULL){
			lst = nuevo;
		}
		else{
			tmp = lst;
			while(tmp->sig != NULL)
				tmp = tmp->sig;
			nuevo->ant=tmp;
			tmp->sig = nuevo; 
		}
	return lst;
}

ListEn elimListEn(ListEn lst, int pos){
	ListEn tmp;
	if(pos >= 1 && pos <= longListEn(lst)){
		if(pos == 1){
			lst = lst->sig;
			lst->ant=NULL;
		}
		else{
			tmp = lst;
			for(int i = 0; i < pos-2; i++){
				tmp = tmp->sig;
			}
			if(pos ==longListEn(lst)){
				tmp->sig=NULL;
			}
			else{
				tmp->sig = tmp->sig->sig;
				tmp->sig->ant=tmp;
			}
		}
	}
return lst;
}


int main(){
	ListEn Holi,temporal;
	Holi=crearListEn();
	Holi=anxListEn(Holi,1);
	Holi=anxListEn(Holi,2);
	Holi=anxListEn(Holi,3);
	Holi=anxListEn(Holi,4);
	Holi=anxListEn(Holi,5);
	Holi=anxListEn(Holi,6);
	Holi=anxListEn(Holi,7);
	Holi=elimListEn(Holi,3);
	printf("%d\n",longListEn(Holi) );
	int i,n=6;
	temporal=Holi;
	for(i=0;i<n;i++){
		printf("%d ",(temporal->dato));
		temporal=temporal->sig;
	}
	printf("\n");
}