//Include Necessary Libraries:
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//MACROS:
#define NAME_SIZE 50
#define POSITION_SIZE 50
#define EMPLOYEELIST_LIST_LENGTH 50
#define DESCRIPTION_LENGTH 100
#define EXPENSELIST_LIST_LENGTH 20
//Structs:
typedef struct
{ //3. write the employee struc
    int id;
    char name[NAME_SIZE];
    char position[POSITION_SIZE];
    double salary;
} employee;

typedef struct
{ //4. write the employee list stuct
    employee array[EMPLOYEELIST_LIST_LENGTH];
    int length;
    int count;
} employeeList;

typedef struct
{ //12 write expense struct
    int employee_id;
    char description[DESCRIPTION_LENGTH];
    double cost;
} expense;

typedef struct
{ //13. write expense list struct
    expense array[EXPENSELIST_LIST_LENGTH];
    int length;
    int count;
} expenseList;

//function prototypes
employeeList create_employee_list();
int read_employees(char filename[], employeeList *el);

void print_employee_list (employeeList el, char filename[]);
expenseList create_expense_list();
int read_expenses (char filename[], expenseList *exl);
void print_expense_list(expenseList exl, char filename[]);
void calc_expenses(employeeList el, expenseList exl, char filename[]);

//main function
int main()
{
    employeeList el = create_employee_list();
    char filename[20] = "isisStaff.txt";
    read_employees(filename, &el);

    char outfilename[] = "ARJUN_LAB_11_OUTPUTFILE.txt";
    print_employee_list(el, outfilename);

    expenseList exl = create_expense_list();
    char exfilename[20] = "isisExp.csv";
    read_expenses(exfilename, &exl);
    print_expense_list(exl, outfilename );
    calc_expenses(el, exl, outfilename);

    return 0;
}

employeeList create_employee_list()
{ //5. create employee list function
    employeeList el;
    el.length = EMPLOYEELIST_LIST_LENGTH;
    el.count = 0;
    return el;
}

int read_employees(char filename[], employeeList *el)
{
    FILE *file = fopen(filename, "r");
    char buffer[200];
    int recs = 0;
    if (file == NULL)
    {
        perror("File failed to open");
        exit(999);
    }
    while (fgets(buffer, 200, file) != NULL)
    {
        buffer[strlen(buffer) - 1] = '\0';
        //printf("%s\n", buffer);
        el->array[recs].id = atoi(strtok(buffer, "|"));
        strcpy(el->array[recs].name, strtok(NULL, "|"));
        strcpy(el->array[recs].position, strtok(NULL, "|"));
        el->array[recs].salary = atof(strtok(NULL, "|"));
        recs++;
        el->count += 1;
    }
    fclose(file);

    return recs;
}


void print_employee_list (employeeList el, char filename[]){ //10. write print employee list function
    FILE *out_file = fopen(filename, "w");
    int recs = 0;
    char buffer[40];
    if (out_file == NULL){
        perror("FILE IS INVALID");
        exit(999);
    }

    fprintf(out_file, "EMPLOYEE LIST:\nThere are %d employees\n\n", el.count);
    
    for (int i = 0; i < el.count; i++){
    fprintf(out_file,"%8s %d\n", "ID:", el.array[i].id);
    fprintf(out_file,"%8s %s\n", "Name:", el.array[i].name);
    fprintf(out_file,"%8s %s\n", "Position:", el.array[i].position);
    fprintf(out_file,"%8s %.2f\n", "Salary:", el.array[i].salary);
    }
    fprintf(out_file, "\n\n\n");
    fclose(out_file);

}

expenseList create_expense_list(){
    expenseList exl;
    exl.length = EXPENSELIST_LIST_LENGTH;
    exl.count = 0;
    return exl;
}

int read_expenses (char filename[], expenseList *exl){

    FILE *file = fopen(filename, "r");
    int recs = 0;
    char buffer[40];
    if (file == NULL){
        perror("FILE IS INVALID");
        exit(999);
    }

    while(fgets(buffer,40,file) != NULL){
        buffer[strlen(buffer) - 1] = '\0';
        exl->array[recs].employee_id = atoi(strtok(buffer, ",")); 
        strcpy(exl->array[recs].description, strtok(NULL, ","));
        exl->array[recs].cost = atof(strtok(NULL, ","));
        exl->count +=1;
        recs++;
    }

return recs;
}

void print_expense_list(expenseList exl, char filename[]){
    FILE *out_file = fopen(filename, "a");
    char buffer[40];
    if (out_file == NULL){
        perror("FILE IS INVALID");
        exit(999);
    }

    fprintf(out_file, "ISIS Expenses:\n");
    for (int i = 0; i < exl.count; i++){
    fprintf(out_file, "%13s %d\n", "Employee ID:", exl.array[i].employee_id);
    fprintf(out_file, "%13s %s\n", "Description:", exl.array[i].description);
    fprintf(out_file, "%13s %.2f\n", "Cost:", exl.array[i].cost);
    }
    fclose(out_file);
}
void calc_expenses(employeeList el, expenseList exl, char filename[]){ //21. write calc_expenses function
    double total;
    int k = 0;

    FILE *out_file = fopen(filename, "a");
    if(out_file == NULL){
        perror("FILE FAILED TO OPEN");
        exit(777);
    }

    fprintf(out_file, "\n\n\n");
    for(int i = 0; i < el.count / 2; i++){
        total = 0;
        fprintf(out_file, "%d %s %s $%.2f\n", el.array[i].id, el.array[i].name, 
                el.array[i].position, el.array[i].salary);
        fprintf(out_file,"    %s $%.2f\n", exl.array[k].description, exl.array[k].cost);
        total += exl.array[k].cost;
        k++;
        fprintf(out_file, "    %s $%.2f\n", exl.array[k].description, exl.array[k].cost);
        total += exl.array[k].cost;
        k++;
        fprintf(out_file, "    %s $%.2f\n", exl.array[k].description, exl.array[k].cost);
        total += exl.array[k].cost;
        fprintf(out_file,"Total: $%.2f\n\n", total );
        k++;
    }
    int h = 9;
    for(int i = 3; i < el.count; i++){
        total = 0;
        fprintf(out_file, "%d %s %s $%.2f\n", el.array[i].id, el.array[i].name, 
                el.array[i].position, el.array[i].salary);
        fprintf(out_file,"    %s $%.2f\n", exl.array[h].description, exl.array[h].cost);
        total += exl.array[h].cost;
        h++;
        fprintf(out_file, "    %s $%.2f\n", exl.array[h].description, exl.array[h].cost);
        total += exl.array[h].cost;
        fprintf(out_file, "Total: $%.2f\n\n", total );

        h++;
        
    }
}
