#include <iostream>
#include <stdlib.h>
#include <fstream>


using namespace std;
struct Curso
{
    string nombre_curso;
    int codigo_curso;
    float nota_obtenida;
};

struct Alumno {
    string nombre_alumno;
    int legajo;
    int cantidad_cursos_tomados;
    Curso* cursos = nullptr;
};

void pedir_datos(Alumno* alumno, int cantidad_alumnos) {
    ofstream  archivo;
    archivo.open("mini_proyecto.txt",ios::out);

    if (archivo.fail())
    {
        cout<<"Error al abrir el archivo.";
        exit(1);
    }


    for (int i = 0; i < cantidad_alumnos; i++)
    {
        cout<<"Ingrese el nombre del alumno: "; cin>>alumno[i].nombre_alumno;
        cout<<"Ingrese el legajo del alumno: "; cin>>alumno[i].legajo;
        cout<<"Ingrese la cantidad de cursos tomados del alumno: "; cin>>alumno[i].cantidad_cursos_tomados;
        alumno[i].cursos = new Curso[alumno[i].cantidad_cursos_tomados];
        
        archivo<<"Datos del alumno: "<<endl;
        archivo<<"nombre alumno: "<<alumno[i].nombre_alumno<<endl;
        archivo<<"legajo alumno: "<<alumno[i].legajo<<endl;
        archivo<<"cantidad de cursos tomados del alumno: "<<alumno[i].cantidad_cursos_tomados<<endl;

        for (int j = 0; j < alumno[i].cantidad_cursos_tomados; j++)
        {
            cout<<"Ingrese nombre del curso tomado: "; cin>>alumno[i].cursos[j].nombre_curso;
            cout<<"Ingrese el codigo del curso tomado: "; cin>>alumno[i].cursos[j].codigo_curso;
            cout<<"Ingrese la nota del curso tomado: "; cin>>alumno[i].cursos[j].nota_obtenida;
            archivo<<"Cursos del alumno: "<<endl;
            archivo<<"nombre curso: "<<alumno[i].cursos[j].nombre_curso<<endl;
            archivo<<"codigo curso: "<<alumno[i].cursos[j].codigo_curso<<endl;
            archivo<<"nota obtenida del curso: "<<alumno[i].cursos[j].nota_obtenida<<endl;
        } 
    }
    archivo.close();
}
void mostrar_datos(Alumno* alumno, int cantidad_alumnos) {
    for (int i = 0; i < cantidad_alumnos; i++)
    {
        cout<<alumno[i].nombre_alumno<<endl;
        cout<<alumno[i].legajo<<endl;
        cout<<alumno[i].cantidad_cursos_tomados<<endl;
        for (int j = 0; j < alumno[i].cantidad_cursos_tomados; j++)
        {
            cout<<alumno[i].cursos[j].nombre_curso<<endl;
            cout<<alumno[i].cursos[j].codigo_curso<<endl;
            cout<<alumno[i].cursos[j].nota_obtenida<<endl;
        }
    }
}

void leer_archivo() {
    ifstream archivo;
    string texto;
    archivo.open("mini_proyecto.txt", ios::in);
    if (archivo.fail())
    {
        cout<<"Error al abrir el archivo.";
        exit(1);
    }

    while (!archivo.eof())
    {
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    
    archivo.close();
}

int main() {
    int cantidad_alumnos;
    cout<<"Ingrese la cantidad de alumnos que quiere ingresar: "; cin>>cantidad_alumnos;
    Alumno* alumnos = new Alumno[cantidad_alumnos];

    pedir_datos(alumnos, cantidad_alumnos);
    //mostrar_datos(alumnos, cantidad_alumnos);
    //leer_archivo();
    estadisticas(alumnos, cantidad_alumnos);


    for (int i = 0; i < cantidad_alumnos; i++)
    {
        delete[] alumnos[i].cursos;
    }

    delete[] alumnos;
    return 0;
}