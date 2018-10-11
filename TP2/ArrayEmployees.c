#include "ArrayEmployees.h"

int initEmployees(sEmployee *list, int len){
    int i;
    int ret=-1;

    if(list!=NULL){
        for(i=0;i<len;i++){
            if(list[i].isEmpty!=1){
                list[i].isEmpty=1;
            }
        }

        if(i==len)
            ret=0;
    }

    return ret;
}

int freeSlot(sEmployee *list, int len){
    int i;
    int index=-1;

    for(i=0;i<len;i++){
        if(list[i].isEmpty==1){
            index=i;
            break;
        }
    }

    return index;
}

int addEmployee(sEmployee *list, int len, int id, char *name, char *lastName, float salary, int sector){
    int index;

    index=freeSlot(list,len);

    if(index!=-1){
        printf("\nIngrese nombre: ");
        getString(name, CHARSIZE);
        printf("\nIngrese apellido: ");
        getString(lastName, CHARSIZE);
        printf("\nIngrese salario: ");
        salary=getFloat(salary, CHARSIZE);
        printf("\nIngrese sector: ");
        sector=getInt(sector, CHARSIZE);

        list[index].id=id;
        strcpy(list[index].name, name);
        strcpy(list[index].lastName, lastName);
        list[index].salary=salary;
        list[index].sector=sector;
        list[index].isEmpty=0;
    }

    return index;
}

void getEmployees(sEmployee *list, int len, int id, char *name, char *lastName, float salary, int sector){
    int retEmployee=0;
    char option;

    do{
        retEmployee=addEmployee(list,len,id,name,lastName,salary,sector);
        if(retEmployee!=-1){
            if(id<=INTSIZE){
                id++;
            }else{
                printf("\nEl numero id llego a su limite.\n");
                break;
            }
        }else{
            printf("\nError. No hay mas espacio.\n");
            break;
        }
        printf("\nDesea ingresar otro empleado? S/N: ");
        option=getChar(option);
    }while(option=='S');
}

int findEmployeeById(sEmployee *list,int len, int id){
    int i;
    int index=-1;

    printf("Ingrese el ID del trabajador: ");
    id=getInt(id,CHARSIZE);

    for(i=0;i<len;i++){
        if(list[i].isEmpty==0){
            if(id==list[i].id){
                index=i;
                break;
            }
        }
    }

    return index;
}

int editEmployee(sEmployee *list, int index, int id, char *name, char *lastName, float salary, int sector){
    char option1;
    char option2='\0';

    employeeStructData(list, index);

    printf("\nMODIFICAR: \n1. NOMBRE.\n2. APELLIDO.\n3. SALARIO.\n4. SECTOR.\n5. VOLVER AL MENU PRINCIPAL.\n\nIngrese opcion: ");
    option1=getche();
    fflush(stdin);

    option1=valCharModEmployee(option1);

    switch(option1){
        case '1':
            printf("Ingrese nombre: ");
            getString(name, CHARSIZE);
            employeeDataName(list,name,index);
            index=valChange(option2,index);

            if(index==-1){
                break;
            }
            strcpy(list[index].name,name);
            break;
        case '2':
            printf("\nIngrese apellido: ");
            getString(lastName, CHARSIZE);
            employeeDataLastName(list,lastName,index);
            index=valChange(option2,index);

            if(index==-1){
                break;
            }
            strcpy(list[index].lastName,lastName);
            break;
        case '3':
            printf("\nIngrese salario: ");
            salary=getFloat(salary, CHARSIZE);
            employeeDataSalary(list,salary,index);
            index=valChange(option2,index);

            if(index==-1){
                break;
            }
            list[index].salary=salary;
            break;
        case '4':
            printf("\nIngrese sector: ");
            sector=getInt(sector, CHARSIZE);
            employeeDataSector(list,sector,index);
            index=valChange(option2,index);

            if(index==-1){
                break;
            }
            list[index].sector=sector;
            break;
        case '5':
            index=-1;
            break;
    }

    return index;
}

void modifyEmployee(sEmployee *list,int id, char *name, char *lastName, float salary, int sector){
    int index;
    int auxId=0;
    char option='\0';

    do{
        index=findEmployeeById(list,STRUCTARRAY,auxId);

        if(index!=-1){
            if(editEmployee(list,index,id,name,lastName,salary,sector)==-1)
                break;
        }else{
            printf("\nLa ID ingresada no existe.\n");
            break;
        }
        printf("\nDesea modificar otro empleado? S/N: ");
        option=getChar(option);
    }while(option=='S');
}

void employeeDataName(sEmployee *list, char *name, int index){
    printf("%10s %15s %15s %15s %15s\n","Nombre","Apellido","Salario","Sector","ID");
    printf("%10s %15s %15.2f %15d %15d",name,list[index].lastName,list[index].salary,list[index].sector,list[index].id);
}

void employeeDataLastName(sEmployee *list, char *lastName, int index){
    printf("%10s %15s %15s %15s %15s\n","Nombre","Apellido","Salario","Sector","ID");
    printf("%10s %15s %15.2f %15d %15d",list[index].name,lastName,list[index].salary,list[index].sector,list[index].id);
}

void employeeDataSalary(sEmployee *list, float salary, int index){
    printf("%10s %15s %15s %15s %15s\n","Nombre","Apellido","Salario","Sector","ID");
    printf("%10s %15s %15.2f %15d %15d",list[index].name,list[index].lastName,salary,list[index].sector,list[index].id);
}

void employeeDataSector(sEmployee *list, int sector, int index){
    printf("%10s %15s %15s %15s %15s\n","Nombre","Apellido","Salario","Sector","ID");
    printf("%10s %15s %15.2f %15d %15d",list[index].name,list[index].lastName,list[index].salary,sector,list[index].id);
}

void employeeStructData(sEmployee *list, int index){
    printf("%10s %15s %15s %15s %15s\n","Nombre","Apellido","Salario","Sector","ID");
    printf("%10s %15s %15.2f %15d %15d",list[index].name,list[index].lastName,list[index].salary,list[index].sector,list[index].id);
}

int valChange(char option, int index){
    printf("\nEsta seguro de realizar el cambio? S/N: ");
    option=getChar(option);

    if(option=='N'){
        index=-1;
    }

    return index;
}

char valCharModEmployee(char option){
    while(option !='1' && option!='2' && option!='3' && option!='4' && option!='5'){
        printf("\nError. Ingrese las opciones del menu: ");
        option=getche();
        fflush(stdin);
    }

    return option;
}

int removeEmployee(sEmployee *list, int len, int id){
    int index=-1;

    index=findEmployeeById(list,len,id);

    return index;
}

void deleteEmployee(sEmployee *list, int len){
    char option='\0';
    int auxId=0;
    int index;

    do{
        index=removeEmployee(list,len,auxId);
        if(index!=-1){
            list[index].isEmpty=1;
        }else{
            printf("\nLa ID ingresada no existe.\n");
            break;
        }
        printf("\nDesea borrar otro empleado? S/N: ");
        option=getChar(option);
    }while(option=='S');

}

void getString(char *pString,int len){
    char *pChar;

    if(fgets(pString,len,stdin)!=NULL){
        if((pChar=strchr(pString,'\n')))///check exist newline
            *pChar='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }
    }

    valString(pString, pChar, len);
}

void valString(char *pString, char *pChar, int len){
    while(searchNoAlpha(pString)!=0 || pString[0]=='\0' || isspace(pString[0])!=0 || twoWords(pString)!=0){
        printf("\nError. No puede ingresar numeros o mas de un espacio.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((pChar=strchr(pString,'\n')))///check exist newline
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }

    toUpperChars(pString);
}

void toUpperChars(char *pString){
    int i;

    strlwr(pString);
    pString[0]=toupper(pString[0]);

    for(i=0;pString[i]!='\0';i++){
        if(pString[i]==' ')
            pString[i+1]=toupper(pString[i+1]);
    }
}

int twoWords(char *pString){
    int i;
    int ret=0;
    int cont=0;

    for(i=0;pString[i]!='\0';i++){
        if(cont<2){
            if(pString[i]==' '){
                cont++;
            }
        }else{
            ret=-1;
            break;
        }
    }

    return ret;
}

int searchNoAlpha(char *pString){
    int i;
    int ret=0;

    for(i=0;pString[i]!='\0';i++){
        if(isalpha(pString[i])==0 && pString[i]!=' '){
            ret=-1;
            break;
        }
    }

    return ret;
}

int searchSpace(char *pString){
    int i;
    int ret=0;

    for(i=0;i!='\0';i++){
        if(isspace(pString[i])!=0){
            ret=-1;
            break;
        }
    }

    return ret;
}

float getFloat(float salary, int len){
    char auxSalary[len];
    char *p;

    if(fgets(auxSalary,len,stdin)!=NULL){
        if((p=strchr(auxSalary,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }
    }

    salary=valFloat(auxSalary,salary,p,len);

    return salary;
}

float valFloat(char *pString, float salary, char *pChar, int len){
    while(searchCharacterFloat(pString)!=0 || searchSpace(pString)!=0 || pString[0]=='\0' ){
        printf("\nError. No puede ingresar letras, simbolos o espacios.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((pChar=strchr(pString,'\n')))///check exist newline
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }

    salary=atof(pString);

    return salary;
}

int searchCharacterFloat(char *pString){
    int i;
    int ret=0;
    int cont=0;

    for(i=0;pString[i]!='\0';i++){
        if(cont<2 && (pString[0]!='.' || pString[0]!=',')){
            if(pString[i]==',' || pString[i]=='.'){
                pString[i]='.';
                cont++;
            }else if(isalnum(pString[i])==0 || isalpha(pString[i])!=0){
                ret=-1;
                break;
            }
        }else{
            ret=-1;
            break;
        }
    }

    return ret;
}

int getInt(int sector, int len){
    char auxSector[len];
    char *p;

    if(fgets(auxSector,len,stdin)!=NULL){
        if((p=strchr(auxSector,'\n')))///check exist newline
            *p='\0';
        else{
            scanf("%*[^\n]");
            scanf("%*c");///clear upto newline
        }
    }

    sector=valInt(auxSector,sector,p,len);

    return sector;
}

int valInt(char *pString, int sector, char *pChar, int len){
    while(searchCharacterInt(pString)!=0 || searchSpace(pString)!=0 || pString[0]=='\0'){
        printf("\nError. No se pueden poner letras o simbolos.\nIngrese de nuevo: ");
        if(fgets(pString,len,stdin)!=NULL){
            if((pChar=strchr(pString,'\n')))///check exist newline
                *pChar='\0';
            else{
                scanf("%*[^\n]");
                scanf("%*c");///clear upto newline
            }
        }
    }

    sector=atoi(pString);

    return sector;
}

int searchCharacterInt(char *pString){
    int i;
    int ret=0;

    for(i=0;pString[i]!='\0';i++){
        if(isalnum(pString[i])==0 || isalpha(pString[i])!=0){
            ret=-1;
            break;
        }
    }

    return ret;
}

char getChar(char option){
    option=getchar();
    fflush(stdin);
    option=toupper(option);

    valChar(option);

    return option;
}

void valChar(char option){
    while(option!='S' && option!='N'){
        printf("\nError. Ingrese S si quiere ingresar otro empleado o N si quiere volver al menu.\nIngrese S/N: ");
        option=getchar();
        fflush(stdin);
        option=toupper(option);
    }
}

int verifyVoid(sEmployee *list, int len){
    int i;
    int ret=0;

    for(i=0;i<len;i++){
        if(list[i].isEmpty==0){
            ret=1;
            break;
        }
    }

    return ret;
}

int sortEmployees(sEmployee *list, int len, int order){
    int ret=-1;
    char option;

    printf("\nASCENDENTE (1).\nDESCENDENTE (0)\n\nIngrese opcion: ");

    option=getche();
    fflush(stdin);

    option=valOrder(option);

    switch(option){
        case '0':
            downOrder(list,len);
            ret=0;
            break;
        case '1':
            upOrder(list,len);
            ret=0;
            break;
    }

    return ret;
}

char valOrder(char option){
    while(option!='0' && option!='1'){
        printf("\nError. Ingrese 1 o 0: ");
        option=getche();
        fflush(stdin);
    }

    return option;
}

void upOrder(sEmployee *list,int len){
    int i;
    int j;
    char auxLastName[CHARSIZE];
    char auxName[CHARSIZE];
    float auxSalary;
    int auxSector;
    int auxId;

    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++){
            if(list[i].isEmpty==0 && list[j].isEmpty==0){
                if(stricmp(list[i].lastName,list[j].lastName)>0){
                    strcpy(auxLastName,list[i].lastName);
                    strcpy(list[i].lastName,list[j].lastName);
                    strcpy(list[j].lastName,auxLastName);
                    strcpy(auxName,list[i].name);
                    strcpy(list[i].name,list[j].name);
                    strcpy(list[j].name,auxName);
                    auxSalary=list[i].salary;
                    list[i].salary=list[j].salary;
                    list[j].salary=auxSalary;
                    auxSector=list[i].sector;
                    list[i].sector=list[j].sector;
                    list[j].sector=auxSector;
                    auxId=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=auxId;
                }else if(stricmp(list[i].lastName,list[j].lastName)==0){
                    if(list[i].sector<list[j].sector){
                        strcpy(auxLastName,list[i].lastName);
                        strcpy(list[i].lastName,list[j].lastName);
                        strcpy(list[j].lastName,auxLastName);
                        strcpy(auxName,list[i].name);
                        strcpy(list[i].name,list[j].name);
                        strcpy(list[j].name,auxName);
                        auxSalary=list[i].salary;
                        list[i].salary=list[j].salary;
                        list[j].salary=auxSalary;
                        auxSector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=auxSector;
                        auxId=list[i].id;
                        list[i].id=list[j].id;
                        list[j].id=auxId;
                    }
                }
            }
        }
    }
}

void downOrder(sEmployee *list, int len){
    int i;
    int j;
    char auxLastName[CHARSIZE];
    char auxName[CHARSIZE];
    float auxSalary;
    int auxSector;
    int auxId;

    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++){
            if(list[i].isEmpty==0 && list[j].isEmpty==0){
                if(stricmp(list[i].lastName,list[j].lastName)<0){
                    strcpy(auxLastName,list[i].lastName);
                    strcpy(list[i].lastName,list[j].lastName);
                    strcpy(list[j].lastName,auxLastName);
                    strcpy(auxName,list[i].name);
                    strcpy(list[i].name,list[j].name);
                    strcpy(list[j].name,auxName);
                    auxSalary=list[i].salary;
                    list[i].salary=list[j].salary;
                    list[j].salary=auxSalary;
                    auxSector=list[i].sector;
                    list[i].sector=list[j].sector;
                    list[j].sector=auxSector;
                    auxId=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=auxId;
                }else if(stricmp(list[i].lastName,list[j].lastName)==0){
                    if(list[i].sector>list[j].sector){
                        strcpy(auxLastName,list[i].lastName);
                        strcpy(list[i].lastName,list[j].lastName);
                        strcpy(list[j].lastName,auxLastName);
                        strcpy(auxName,list[i].name);
                        strcpy(list[i].name,list[j].name);
                        strcpy(list[j].name,auxName);
                        auxSalary=list[i].salary;
                        list[i].salary=list[j].salary;
                        list[j].salary=auxSalary;
                        auxSector=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=auxSector;
                        auxId=list[i].id;
                        list[i].id=list[j].id;
                        list[j].id=auxId;
                    }
                }
            }
        }
    }
}

void showList(sEmployee *list, int len){
    int order=0;
    char option;
    int retSort;
    int retEmployee;

    printf("\n1. ORDENAR LISTA(ASCENDENTE O DESCENDENTE)\n2. MOSTRAR TOTAL DE SUELDOS, PROMEDIO Y EMPLEADOS QUE GANAN MAS QUE LA MEDIA.");
    printf("\n\nIngrese opcion: ");

    option=getche();
    fflush(stdin);

    option=valCharList(option);

    switch(option){
        case '1':
            if((retSort=sortEmployees(list, len, order)!=0)){
                printf("\nError. Algo salio mal.\n");
            }else{
                printf("\nTabla de empleados ordenada con exito.\n");
                    if((retEmployee=printEmployee(list,len)==0)){
                        printf("\nError. Algo salio mal y no se pueden mostrar los empleados.\n");
                    }
            }
            break;
        case '2':
            if((retEmployee=printEmployee(list,len)!=0)){
                printf("\nError. Algo salio mal.\n");
            }else{
                printf("\nTabla de empleados ordenada con exito.\n");
            }
            break;
    }
}

int printEmployee(sEmployee *list, int len){
    int i;

    printf("%10s %15s %15s %15s %15s\n","Apellido","Nombre","Salario","Sector","ID");
    for(i=0;i<len;i++){
        if(list[i].isEmpty==0){
            printf("\n%10s %15s %15.2f %15d %15d",list[i].lastName,list[i].name,list[i].salary,list[i].sector,list[i].id);
        }
    }

    return i;
}

char valCharList(char option){
    while(option !='1' && option!='2'){
        printf("\nError. Ingrese las opciones del menu: ");
        option=getche();
        fflush(stdin);
    }

    return option;
}
