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
typedef struct {    //3. write the employee struc
    int id;
    char name[NAME_SIZE];
    char position[POSITION_SIZE];
    double salary;
} employee;

typedef struct {    //4. write the employee list stuct
    employee array[EMPLOYEELIST_LIST_LENGTH];
    int length;
    int count;
} employeeList;     
    
typedef struct {    //12 write expense struct
    int employee_id;    
    char description[DESCRIPTION_LENGTH];
    double cost;
} expense;

typedef struct {    //13. write expense list struct
    expense array[EXPENSELIST_LIST_LENGTH];
    int length;
    int count;
} expenseList;

//Function prototypes
employeeList create_employee_list(); 
int read_employees (employeeList *el);
void print_employee (employee e);
void print_employee_list (employeeList el);
expenseList create_expense_list();
int read_expenses (expenseList *exl);
void print_expense(expense ex);
void print_expense_list(expenseList exl);
void calc_expenses(employeeList el, expenseList exl);

//
//
//
//
///
//2. Write empty main function: 
int main(){

    employeeList el = create_employee_list(); //6. test create employee list in main
    read_employees(&el);           //8. test read_employees in main
    print_employee_list(el);    //11. test print_employee_list in main
    expenseList exl = create_expense_list(); //15. test create_expense_list in main
    read_expenses(&exl);     //17. test read_expenses in main
    print_expense_list(exl); // 20. test print_expense_list in main
    calc_expenses(el, exl); //22. Test calc_expenses in main
    return 0;
}
//
//
//
//
//
employeeList create_employee_list(){    //5. create employee list function
    employeeList el;
    el.length = EMPLOYEELIST_LIST_LENGTH;
    el.count = 0;
    return el;
}

int read_employees (employeeList *el){  //7. write read_employees function
    char employee_str[EMPLOYEELIST_LIST_LENGTH][100];
    int employee_str_count = 0;

    strcpy(employee_str[0] , "1|Archer, Malory|CEO|500000.0");
    employee_str_count++;
    strcpy(employee_str[1] , "2|Archer, Sterling|Agent|250000.0");
    employee_str_count++;
    strcpy(employee_str[2] , "3|Kane, Lana|Agent|300000.0");
    employee_str_count++;
    strcpy(employee_str[3] , "4|Figus, Ceril|Accountant|100000.0");
    employee_str_count++;
    strcpy(employee_str[4] , "5|Tunt, Cheryl|Secretary|65000.0");
    employee_str_count++;
    strcpy(employee_str[5] , "6|Poovey, Pam|HR|85000.0");
    employee_str_count++;

    //printf("%d records read.\n", employee_str_count);
    //for (int i= 0; i <employee_str_count; i++)
    //    printf("%s\n", employee_str[i]);

    char *ptr;
    for (int i = 0; i < employee_str_count; i++){
        el->array[i].id = atoi(strtok(employee_str[i], "|"));
        strcpy(el->array[i].name, strtok(NULL, "|"));
        strcpy(el->array[i].position, strtok(NULL, "|"));
        el->array[i].salary = strtod(strtok(NULL, "|"), &ptr);
        el->count += 1;
    }

    return employee_str_count; 
}

void print_employee (employee e){   //9.write print employee function
    printf("%8s %d\n", "ID:", e.id);
    printf("%8s %s\n", "Name:", e.name);
    printf("%8s %s\n", "Position:", e.position);
    printf("%8s %.2f\n", "Salary:", e.salary);
}

void print_employee_list (employeeList el){ //10. write print employee list function
    printf("EMPLOYEE LIST:\nThere are %d employees\n\n", el.count);
    for (int i = 0; i < el.count; i++){
        print_employee(el.array[i]);
        printf("\n");
    }
}
expenseList create_expense_list(){  //13. write create_expense_list function
    expenseList exl;    
    exl.length = EXPENSELIST_LIST_LENGTH;
    exl.count = 0;
    return exl;
}

int read_expenses (expenseList *exl){ //16 write read_expenses function
    char expense_str[EXPENSELIST_LIST_LENGTH][100];
    int expense_str_count = 0;

    strcpy(expense_str[0] , "1,Dinner,456.23");
    expense_str_count++;
    strcpy(expense_str[1] , "1,Air Travel,692.12");
    expense_str_count++;
    strcpy(expense_str[2] , "1,Spa Day,725.00");
    expense_str_count++;
    strcpy(expense_str[3] , "2,Bar Bill,392.34");
    expense_str_count++;
    strcpy(expense_str[4] , "2,Glenghoulie Blue,320.00");
    expense_str_count++;
    strcpy(expense_str[5] , "2,Bar Bill,523.54");
    expense_str_count++;
    strcpy(expense_str[6] , "3,Explosives,550.00");
    expense_str_count++;
    strcpy(expense_str[7] , "3,Firearms,2343.56");
    expense_str_count++;
    strcpy(expense_str[8] , "3,Amunition,245.98");
    expense_str_count++;
    strcpy(expense_str[9] , "4,Lunch,52.45");
    expense_str_count++;
    strcpy(expense_str[10] , "4,Ledger,23.45");
    expense_str_count++;
    strcpy(expense_str[11] , "5,Copy Paper,56.23");
    expense_str_count++;
    strcpy(expense_str[12] , "5,Staples,12.09");
    expense_str_count++;
    strcpy(expense_str[13] , "6,Milk,4.50");
    expense_str_count++;
    strcpy(expense_str[14] , "6,Cheese,7.89");
    expense_str_count++;

    char *ptr;
    for (int i = 0; i < expense_str_count; i++){
        exl->array[i].employee_id = atoi(strtok(expense_str[i], ","));
        strcpy(exl->array[i].description, strtok(NULL, ","));
        exl->array[i].cost = strtod(strtok(NULL, ","), &ptr);
        exl->count += 1;
    }


    return expense_str_count;
}

void print_expense(expense ex){     //18 write print_expense function
    printf("%13s %d\n", "Employee ID:", ex.employee_id);
    printf("%13s %s\n", "Description:", ex.description);
    printf("%13s %.2f\n", "Cost:", ex.cost);
}

void print_expense_list(expenseList exl){   //19 write print_expense_list function
    printf("I.S.I.S Expenses\n\n");
    for (int i = 0; i < exl.count; i++){
        print_expense(exl.array[i]);
        printf("\n");
    }
}

void calc_expenses(employeeList el, expenseList exl){ //21. write calc_expenses function
    double total;
    int k = 0;
    for(int i = 0; i < el.count / 2; i++){
        total = 0;
        printf("%d %s %s $%.2f\n", el.array[i].id, el.array[i].name, 
                el.array[i].position, el.array[i].salary);
        printf("    %s $%.2f\n", exl.array[k].description, exl.array[k].cost);
        total += exl.array[k].cost;
        k++;
        printf("    %s $%.2f\n", exl.array[k].description, exl.array[k].cost);
        total += exl.array[k].cost;
        k++;
        printf("    %s $%.2f\n", exl.array[k].description, exl.array[k].cost);
        total += exl.array[k].cost;
        printf("Total: $%.2f\n\n", total );
        k++;
    }
    int h = 9;
    for(int i = 3; i < el.count; i++){
        total = 0;
        printf("%d %s %s $%.2f\n", el.array[i].id, el.array[i].name, 
                el.array[i].position, el.array[i].salary);
        printf("    %s $%.2f\n", exl.array[h].description, exl.array[h].cost);
        total += exl.array[h].cost;
        h++;
        printf("    %s $%.2f\n", exl.array[h].description, exl.array[h].cost);
        total += exl.array[h].cost;
        printf("Total: $%.2f\n\n", total );

        h++;
        
    }
}