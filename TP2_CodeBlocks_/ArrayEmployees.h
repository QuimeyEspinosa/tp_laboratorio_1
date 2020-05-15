#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int idSector;
    char description[20];

} eSector;

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int isEmpty;

} eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int printMenuModifications();
int printMenuInformes();

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param employees[] vector de empleados
 * \param tam int Array length
 */
void initEmployees(eEmployee employees[], int tam);

//funciones para mostrar uno o todos los empleados
void printEmployee(eEmployee employee, eSector sectores[], int tamSec);

/** \brief print the content of employees array
 *
 * \param employee[] vector employees
 * \param int tam cantidad de empleados
 * \param sectores[] vector sectores
 * \param int tamSec cantidad de sectores
 *
 */
void printEmployees(eEmployee employees[], int tam, eSector sectores[], int tamSec);
//------------------------------------------------

//funciones para mostrar uno o mas sectores
void printSector(eSector sector, int tamSec);
void printSectores(eSector sectores[], int tamSec);
//------------------------------------------------

//funciones que buscan un indice disponible y que buscan un empleado por ID
int findEmployee(eEmployee employee[], int tam);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param id int
 * \param employee[] vector employees
 * \param int tam cantidad empleados
 * \return Return employee index position or (-1) if invalid length
 *
 */
int findEmployeeById(int id, eEmployee employee[], int tam);
//------------------------------------------------

//funcion ALTA EMPLEADOS
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param int idx autoincremental
 * \param employee[] vector employees
 * \param int tam cantidad de empleados
 * \param sectores[] vector sectores
 * \param int tamSec cantidad de sectores
 * \return int Return retorna 1 si se ingresaron empleados, retorna 0 si no
 */
int addEmployees(int idx, eEmployee employee[], int tam, eSector sectores[], int tamSec);
//------------------------------------------------

//funcion MODIFICAR EMPLEADOS y funciones para el submenu (modificar nombre, apellido, salario, sector)
void modifyEmployee(eEmployee employee[], int tam, eSector sectores[], int tamSec);
void modifyEmployeeName(eEmployee employee[], int tam, eSector sectores[], int tamSec);
void modifyEmployeeLastName(eEmployee employee[], int tam, eSector sectores[], int tamSec);
void modifyEmployeeSalary(eEmployee employee[], int tam, eSector sectores[], int tamSec);
void modifyEmployeeSector(eEmployee employee[], int tam, eSector sectores[], int tamSec);
//------------------------------------------------

//funcion BAJA EMPLEADOS
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param employee[] vector employees
 * \param int tam cantidad de empleados
 * \param sectores[] vector sectores
 * \param int tamSec cantidad de sectores
 *
 */
void removeEmployee(eEmployee employee[], int tam, eSector sectores[], int tamSec);
//------------------------------------------------

//funcion INFORMAR EMPLEADOS y funciones para el submenu (informar alfabeticamente por apellido y sector, informar salarios)
/** \brief menu sort
 *
 * \param employee[] vector employees
 * \param int tam cantidad de empleados
 * \param sectores[] vector sectores
 * \param int tamSec cantidad de sectores
 *
 */
void sortEmployees(eEmployee employee[], int tam, eSector sectores[], int tamSec);

/** \brief Sort the elements in the array of employees by last name and sector
 *
 * \param employee[] vector employees
 * \param int tam cantidad de empleados
 * \param sectores[] vector sectores
 * \param int tamSec cantidad de sectores
 *
 */
void sortEmployeesByLastNameAndSector(eEmployee employee[], int tam, eSector sectores[], int tamSec, int order);
/** \brief It shows the total wage and it's average, also shows employees who have had exceded the average wage
 *
 * \param employee[] vector employees
 * \param int tam cantidad de empleados
 * \param sectores[] vector sectores
 * \param int tamSec cantidad de sectores
 *
 */
void sortEmployeesBySalarys(eEmployee employee[], int tam, eSector sectores[], int tamSec);
//------------------------------------------------

//funcion que aniade la descripcion de un sector a un vector
int addDescriptionSector (char description[], int id, eSector sectores[], int tamSec);
//------------------------------------------------

