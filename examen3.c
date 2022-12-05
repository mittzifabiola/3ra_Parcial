//R. DON JUAN RAMOS MITZI FABIOLA 
//EXAMEN 3ra Parcial

#include <stdlib.h>
#include <stdio.h>

struct nodo {
	struct nodo* hijo_izq;
	struct nodo* hijo_der;
	int nivel;
	int num;
};

struct nodo* nuevo_nodo(int num);
void destroy_tree(struct nodo* tree);
void insertar_nodo(struct nodo* root, struct nodo* nodo);
int busqueda(struct nodo* tree, int num);

int main() {
	int num = 0, nivel = 0;
	struct nodo* tree = nuevo_nodo(6);
	insertar_nodo(tree, nuevo_nodo(5));
	insertar_nodo(tree, nuevo_nodo(11));
	insertar_nodo(tree, nuevo_nodo(4));
	insertar_nodo(tree, nuevo_nodo(3));
	insertar_nodo(tree, nuevo_nodo(8));
	insertar_nodo(tree, nuevo_nodo(12));
	insertar_nodo(tree, nuevo_nodo(9));
	insertar_nodo(tree, nuevo_nodo(21));
	
	printf("¿Qué numero desea buscar?: ");
	scanf("%d", &num);
	nivel = busqueda(tree, num);
	if (nivel > 0)
		printf("El numero %d esta en el nivel: %d\n",num, nivel);
	else 
		printf("Numero %d NO se encontró\n",num);

	return 0;
}


struct nodo* nuevo_nodo(int num) {
	struct nodo* nodo = NULL;
	nodo = malloc(sizeof(struct nodo));
	nodo->hijo_izq = NULL;
	nodo->hijo_der = NULL;
	nodo->nivel = 1;
	nodo->num = num;
	return nodo;
}

void insertar_nodo(struct nodo* root, struct nodo* nodo) {
	if (root != NULL && nodo != NULL) {
		nodo->nivel = root->nivel + 1;
		if (nodo->num > root->num) {
			if (root->hijo_der == NULL)
				root->hijo_der = nodo;
			else
				insertar_nodo(root->hijo_der, nodo);
		} else {
			if (root->hijo_der == NULL)
				root->hijo_izq = nodo;
			else
				insertar_nodo(root->hijo_izq, nodo);
		}
	}
}

int busqueda(struct nodo* tree, int num) {
	int l = 0;
	if (tree == NULL)
		return 0;
	if (tree->num == num)
		return tree->nivel;
	l = busqueda(tree->hijo_izq, num);
	if (l > 0)
		return l;
	l = busqueda(tree->hijo_der, num);
	if (l > 0)
		return l;
	return 0;
}
