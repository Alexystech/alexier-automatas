/* Algoritmos de ordenamiento - Examen */

#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<iomanip> //Permite usar setw()

using namespace std;

/*Funci�n void para ordenar elementos por insercion*/
void insercion(int *array,int n){
    int k,j, aux;

    for(k=1; k<n; k++){
        j=k;
        aux=array[k];
        while(j>0 && aux < array[j-1]){
            array[j]=array[j-1];
            j--;
        }
        array[j]=aux;
    }
}

/*Funci�n void para ordenar elementos por seleccion*/
void seleccion(int *array,int n){
    int k,j, indiceMenor;

    for(k=0; k<n-1; k++){
        indiceMenor=k;
        for(j=k+1; j<n; j++)
            if(array[j]<array[indiceMenor])
                indiceMenor=j;
        if(k!=indiceMenor){
            double aux=array[k];
            array[k]=array[indiceMenor];
            array[indiceMenor]=aux;
        }
    }
}

/*Funci�n void para ordenar elementos*/
void quicksort(int *array, int primero, int ultimo){
    int k,j,central,pivote;
    central=(primero+ultimo)/2; //Hallar la posici�n central del arreglo
    pivote=array[central];//Capturar el valor del medio del arreglo
    k=primero; //Declaraci�n de �ndices para separar en izquierda y derecha
    j=ultimo;

    do{ //Separando en dos partes el array, sublistas
        while(array[k]<pivote)k++; //Valores menores al pivote
        while(array[j]>pivote)j--; //VAlores ayores al pivote
        if(k<=j){
            int tmp; //Intercambio de valores
            tmp=array[k];
            array[k]=array[j];
            array[j]=tmp;
            k++;
            j--;
        }
    }while(k<=j);

    if(primero<j) //Los condicionales para acomodar los valores de acuerdo a su tama�o
        quicksort(array,primero,j); //izquierda del pivote
    if(k<ultimo)
        quicksort(array,k,ultimo); //derecha del pivote
}

/*Funci�n void para ordenar elementos*/
void shell(int *array,int n){
    int salto, k, band;
    float temporal; //Se guardar� temporalmenete cada salto

    for(salto=n/2; salto>0; salto=salto/2)
        do{
            band=0; //Se inicializa en 0 la variable bandera
            for(k=0; k<n-salto; k++)
                if(array[k]>array[k+salto]){
                    temporal=array[k];
                    array[k]=array[k+salto]; //Se hace el intercambio
                    array[k+salto]=temporal;
                    band=1;
                }

        }while(band);

}

/*Algoritmo del m�todo burbuja*/
void burbuja(int *array, int n){
    int aux;
    for(int k=0;k<n-1;k++){ //Ordenar vector | Bucle anidado
        for(int j=0;j<n-1;j++){ //j es el numero posterior al "primero"
            if(array[j]>array[j+1]){ //condicion para ordenar; numero actual es mayor al siguiente
                aux=array[j];//si lo hay, un intercambio (auxiliar)
                array[j]=array[j+1];
                array[j+1]=aux;
            }
        }
    }
}

void mostrarOrden(int *array,int n){
    int k;
    cout<<"\n\t***** Elementos del Arreglo ordenados *****"<<endl;
    for(int k=0;k<n;k++){
        cout<<array[k]<<setw(5);
    }
    cout<<endl;
}

int main(){
    int array2[100000];
    int i, min, max, elementos;

    srand(time(NULL));

    cout<<"\n\t\t----- METODOS DE ORDENAMIENTO -----\n";
    cout<<"\nOpciones de tamanio\n";
    cout<<"Prueba de 10\n";
    cout<<"Prueba de 100\n";
    cout<<"Prueba de 1000\n";
    cout<<"Pruebe de 10000\n";
    cout<<"Prueba de 100000\n";

    cout<<"\nEscriba la cifra para su prueba: ";
    cin>>elementos;
    cout<<"Ingrese el limite superior: ";
    cin>>max;
    cout<<"Ingrese elimite inferior: ";
    cin>>min;

//    cout<<"\n\n\t***** Lista desordenada *****\n";
    for(i=0; i<elementos; i++){
        array2[i]=min+rand()%(max-min+1);
//        cout<<array2[i]<<setw(5);
    }

    cout<< "*********************************"<<endl;
    cout<< "\ttiempos finales"<<endl;
    cout<< "*********************************"<<endl;

    unsigned tiempoInicio,tiempoFin;

    tiempoInicio = clock();
    insercion(array2,i);
    tiempoFin = clock();

    double tiempoEjecucion = (double(tiempoInicio-tiempoFin)/CLOCKS_PER_SEC);
    cout<<"Ordenamiento insercion: "<<tiempoEjecucion<<" microsegundos"<<endl;

    tiempoInicio=clock();

    seleccion(array2,i);
    cout<<"***** METODO SLECCION *****"<<endl;

    tiempoFin=clock();

    tiempoEjecucion=(double(tiempoInicio-tiempoFin)/CLOCKS_PER_SEC);
    cout<<"Tiempo de ejecucion: "<<tiempoEjecucion<<endl;

    tiempoInicio=clock();

    quicksort(array2,0,i-1);
    cout<<"***** METODO QUICKSORT *****"<<endl;

    tiempoFin=clock();

    tiempoEjecucion=(double(tiempoInicio-tiempoFin)/CLOCKS_PER_SEC);
    cout<<"Ordenamiento quicksort: "<<tiempoEjecucion<<" microsegundos"<<endl;git

    tiempoInicio=clock();

    shell(array2,i);
    cout<<"***** METODO SHELL *****"<<endl;

    tiempoFin=clock();

    tiempoEjecucion=(double(tiempoInicio-tiempoFin)/CLOCKS_PER_SEC);
    cout<<"Ordenamiento shell: "<<tiempoEjecucion<<" microsegundos"<<endl;

    tiempoInicio=clock();

    burbuja(array2,i);
    cout<<"***** METODO BURBUJA *****"<<endl;

    tiempoFin=clock();

    tiempoEjecucion=(double(tiempoInicio-tiempoFin)/CLOCKS_PER_SEC);
    cout<<"Tiempo de ejecucion: "<<tiempoEjecucion<<endl;

    getch();
    return 0;
}





