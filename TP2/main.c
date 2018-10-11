#include "ArrayEmployees.h"

int main()
{
    sEmployee arrayEmployees[STRUCTARRAY];
    int id=1;
    char name[CHARSIZE];
    char lastName[CHARSIZE];
    float salary=0;
    int sector=0;
    char option;
    int flag=0;
    int ret;

    ret=initEmployees(arrayEmployees,STRUCTARRAY);

    if(ret!=0){
        printf("\nError. Algo salio mal.\n");
        return ret;
    }

    do{
        printf("\n1. ALTAS.\n2. MODIFICAR.\n3. BAJAS.\n4. INFORMAR.\n5. SALIR.\n\nIngrese opcion: ");
        option=getche();
        fflush(stdin);

        flag=verifyVoid(arrayEmployees,STRUCTARRAY);

        if(flag==0 && (option=='2' || option=='3' || option=='4')){
            printf("\nError. No hay ningun empleado cargado.\n");
            continue;
        }

        switch(option){
            case '1':
                getEmployees(arrayEmployees,STRUCTARRAY,id,name,lastName,salary,sector);
                flag=1;
                break;
            case '2':
                modifyEmployee(arrayEmployees,id,name,lastName,salary,sector);
                break;
            case '3':
                deleteEmployee(arrayEmployees,STRUCTARRAY);
                break;
            case '4':
                showList(arrayEmployees,STRUCTARRAY);
                break;
            default:
                if(option!='5')
                    printf("\nError. Ingrese una opcion perteneciente al menu.\n\n");
                break;
        }
    }while(option!='5');

    return ret;
}
