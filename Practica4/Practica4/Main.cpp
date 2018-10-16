#include "main.h"
#include "mainc.h"

using namespace std;

int main() {
	int ** poblacion_inicial;
	int ** padres = Crear();
	int ** descendencia = Crear();
	int** mutantes = Crear();
	poblacion_inicial=crearpoblacion();	

	AG_Ruleta(poblacion_inicial);
		
	return 0;
}
