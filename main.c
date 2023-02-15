#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>

/*
Структура должна описывать результат запроса.
В ней должны находиться поля, которые возвращает запрос.
*/
struct Result {
    char* firstname;
    char* lastname;
    char* job_id;
    char* hire_date;
    char* department;
};

/*
Функция выводит массив с результатами запроса в виде:
{имя, фамилия, id должности, дата приёма на работу, название отдела}
{имя, фамилия, id должности, дата приёма на работу, название отдела}
{имя, фамилия, id должности, дата приёма на работу, название отдела}
...
*/
void show_result(struct Result *result, int size){
    for (int i = 0; i < size; i++)
    {
        printf("{%s, %s, %s, %s, %s}\n", result[i].firstname, result[i].lastname, result[i].job_id, result[i].hire_date, result[i].department);
    }
}


/*
Реализовать функцию, выполняющую параметрический запрос, описанный в функции main.
Функция должна выполнять подготовленный запрос, переданный во втором параметре;
в третьем и четвёртом параметре передаётся диапазон дат, который задаёт интересующий период найма сотрудника.
Функция не должна выводить что-то на терминал, результат должен записываться в массив dest,
память для которого выделяется в этой же функции. Функция возвращает размер массива dest (количество элементов)
или 0 в случае ошибки.
*/
int get_result(struct Result **dest, sqlite3_stmt *stmt, char *lo_hire_date, char *hi_hire_date){
    sqlite3_reset(stmt);
    int columns = sqlite3_column_count(stmt);
    int j = 0;
    int size = 0;
    int step = 0;
    sqlite3_bind_text(stmt, 1, lo_hire_date, strlen(lo_hire_date), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, hi_hire_date, strlen(hi_hire_date), SQLITE_STATIC);
    while(1)
    {
        step = sqlite3_step(stmt);
        if (step != SQLITE_ROW)
        {
            break;
        }
        
        size++;
    }
    
    sqlite3_bind_text(stmt, 1, lo_hire_date, strlen(lo_hire_date), SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, hi_hire_date, strlen(hi_hire_date), SQLITE_STATIC);
    *dest = calloc(size,sizeof(struct Result));
    for (int i = 0; i < size; i++)
    {
        (*dest)[i].firstname = (char*)malloc(20 * sizeof(char));
        (*dest)[i].lastname = (char*)malloc(20 * sizeof(char));
        (*dest)[i].job_id = (char*)malloc(20 * sizeof(char));
        (*dest)[i].hire_date = (char*)malloc(20 * sizeof(char));
        (*dest)[i].department = (char*)malloc(20 * sizeof(char));
        step = sqlite3_step(stmt);
        strcpy((*dest)[i].firstname,sqlite3_column_text(stmt,0));
        strcpy((*dest)[i].lastname,sqlite3_column_text(stmt,1));
        strcpy((*dest)[i].job_id,sqlite3_column_text(stmt,2));
        strcpy((*dest)[i].hire_date,sqlite3_column_text(stmt,3));
        strcpy((*dest)[i].department,sqlite3_column_text(stmt,4));
    } 
    return size;
}

int main(int argc, char *argv[]){
    sqlite3 *db;
    int rc = sqlite3_open("hr.db", &db);
    
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    /*
    Строка sql_query должна содержать запрос, который возвращает информацию о сотрудниках,
    которые были наняты в определённый период. Диапазон дат должен задаваться параметрами.
    Запрос должен возвращать имя, фамилию сотрудника, id должности, дату приёма на работу,
    название отдела, где работает сотрудник.
    */
    char *sql_query = "select first_name, last_name, job_id, hire_date,"
    "departments.department_name from employees join departments on departments."
    "department_id == employees.department_id where hire_date between @lo_date and @hi_date;";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql_query, -1, &stmt, NULL);

    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 2;
    }

    //Код для проверки
    struct Result *result;
    int result_size = get_result(&result, stmt, "2007-11-05", "2009-07-05");
    printf("first query:\n");
    show_result(result, result_size);
    if(result_size > 0){
        free(result);
    }

    result_size = get_result(&result, stmt, "2002-01-10", "2005-10-15");
    printf("\nsecond query:\n");
    show_result(result, result_size);
    if(result_size > 0){
        free(result);
    }

    result_size = get_result(&result, stmt, "2006-11-05", "2008-07-30");
    printf("\nthird query:\n");
    show_result(result, result_size);
    if(result_size > 0){
        free(result);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}