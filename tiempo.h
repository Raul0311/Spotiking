//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#ifndef TIEMPO_H
#define TIEMPO_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define GREEN "\033[1;32m"      /* Green */
#define YELLOW "\033[1;33m"      /* Yellow */
#define BLUE "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define CYAN "\033[1;36m"      /* Cyan */
#define WHITE "\033[1;37m"      /* White */
#define RED "\033[1;31m"	/* Red */
#define DEBUG "\033[1;34m"

class Tiempo {
    private:
        int minutos;
        int segundos;
        bool test;
    public:
        Tiempo();
        Tiempo(const Tiempo &t);
        ~Tiempo();
        /*--------GETS--------*/
        int getMinutos() const;
        int getSegundos() const;
        bool getTest() const;
        /*--------SETS--------*/
        void setMinutos(const int minutos);
        void setSegundos(const int segundos);
        /*--------SOBRECARGA DE OPERADORES--------*/
        Tiempo operator+(const Tiempo &t);
        friend ostream& operator<<(ostream&flujo, Tiempo &t);
        /*--------MÉTODO ADICIONAL--------*/
        void convertiraMinutosySegundos(int minutos, int segundos);
};

#endif