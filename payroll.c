#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

  /* structure to store employee salary details */
  struct employee {
        int empId;
        char name[32];
        int basic, ha, da, ma, oa; 
        int nhif, paye, loan, nssf;
        float gross, net;
  };

  /* prints payslip for the requested employee */
  void printSalary(struct employee e1) {
        printf("Salary Slip of %s:\n", e1.name);
        printf("Employee ID: %d\n", e1.empId);
        printf("Basic Salary: %d\n", e1.basic);
        printf("House Allowance: %d\n", e1.ha);
        printf("Milleage Allowance: %d\n", e1.ma);
        printf("Overtime Allowanc: %d\n", e1.oa);
        printf("Gross Salary: %.2f Rupees\n", e1.gross);

        printf("\nDeductions: \n");
        printf("NHIF: %d\n", e1.nhif);
        printf("PAYE: %d\n", e1.paye);
        printf("Loan: %d\n", e1.loan);
        printf("NSSF: %d\n", e1.nssf);
        printf("\nNet Salary: %.2f Rupees\n\n", e1.net);
        return;
  }

  /* display all the employee records entered */
  void display(struct employee e1) {
        printf("%d \t %s \t %d \t %d \t %d \t %d \t %d \t %d \n", e1.empId, e1.name, e1.basic, e1.ha, e1.ma, e1.oa, e1.nhif, e1.paye, e1.loan, e1.nssf);
        return;
  }

  int main() {
        int i, ch, num, flag, empID;
        int choice, update, updateChoice;
        struct employee *e1;

        /* get the number of employees from the user  */
        printf("Enter the number of employees:");
        scanf("%d", &num);

        /* dynamically allocate memory to store employee salary details */
        e1 = (struct employee *)malloc(sizeof(struct employee) * num);

        /* get the employee salary details from the customer */
        printf("Enter your input for every employee:\n");
        for (i = 0; i < num; i++) {
                printf("Employee ID:");
                scanf("%d", &(e1[i].empId));
                getchar();
                printf("Employee Name:");
                fgets(e1[i].name, 32, stdin);
                e1[i].name[strlen(e1[i].name) - 1] = '\0';
                printf("Basic Salary:");
                scanf("%d", &(e1[i].basic));
                printf("House Allowance:");
                scanf("%d", &(e1[i].ha));
                printf("Milleage Allowance:");
                scanf("%d", &(e1[i].ma));
                printf("Overtime Allowance:");
                scanf("%d", &(e1[i].oa));
                printf("Enter the deductions: \n");
                printf("NHIF:");
                scanf("%d", &(e1[i].nhif));
                printf("PAYE:");
                scanf("%d", &(e1[i].paye));
                printf("Loan:");
                scanf("%d", &(e1[i].loan));
                printf("NSSF:");
                scanf("%d", &(e1[i].nssf));
                printf("\n");

        }

        /* printing payslip for the given employee ID */
        while (1) {
                
                printf("\n   EMPLOYEE PAYROLL SYSTEM \n");
                printf("\n\n*****CHOOSE YOUR OPTION*****\n");
                printf("1) SHOW ALL RECORDS\n");
                printf("2) ADD NEW EMPLOYEE RECORD\n");
                printf("3) PRINT THE SALARY SLIP\n");
                printf("4) UPDATE EMPLOYEE RECORD\n");
                printf("5) EXIT\n");
                printf("Enter your choice : ");
                scanf("%d", &choice);
                
                if (choice != 5) {
                switch(choice){
                        case 1 : /*printing all the records entered before printing the slip */
                                        printf("\nEmp. ID. Emp.Name \t Basic \t HRA \t DA \t MA \t PF \t Insurance \n") ;
                                        
                                        for (i = 0; i < num; i++) {
                                                display(e1[i]);
                                        }
                                        break;

                        case 2 : /*adding a new member in the employee list created */
                                        num++;
                                        i = num-1;
                                        printf("Employee ID:");
                                        scanf("%d", &(e1[i].empId));
                                        getchar();
                                        printf("Employee Name:");
                                        fgets(e1[i].name, 32, stdin);
                                        e1[i].name[strlen(e1[i].name) - 1] = '\0';
                                        printf("Basic Salary:");
                                        scanf("%d", &(e1[i].basic));
                                        printf("House Allowance:");
                                        scanf("%d", &(e1[i].ha));
                                        printf("Milleage Allowance:");
                                        scanf("%d", &(e1[i].ma));
                                        printf("Overtime Allowance:");
                                        scanf("%d", &(e1[i].oa));
                                        printf("Enter the deductions:\n");
                                        printf("NHIF:");
                                        scanf("%d", &(e1[i].nhif));
                                        printf("PAYE:");
                                        scanf("%d", &(e1[i].paye));
                                        printf("Loan:");
                                        scanf("%d", &(e1[i].loan));
                                        printf("NSSF:");
                                        scanf("%d", &(e1[i].nssf));
                                        printf("\n");
                                        break;

                        case 3 :        /* gross and net salary calculation */
                                        for (i = 0; i < num; i++) {
                                                e1[i].gross = e1[i].basic +
                                                        (e1[i].ha * e1[i].basic) / 100 +
                                                                (e1[i].ma * e1[i].basic) / 100 +
                                                                        (e1[i].oa * e1[i].basic) / 100;
                                                e1[i].net = e1[i].gross - (e1[i].nhif + e1[i].paye + e1[i].loan + e1[i].nssf);
                                        }
                                        
                                        printf("Enter employee ID to get payslip:");
                                        scanf("%d", &empID);

                                        flag = 0;
                                        for (i = 0; i < num; i++) {
                                                if (empID == e1[i].empId) {
                                                        printSalary(e1[i]);
                                                        flag = 1;
                                                }
                                        }

                                        if (!flag) {
                                                printf("No Record Found!!\n");
                                        }
                                        break;

                        case 4 :        printf("Enter the employee ID to update data: ");
                                        scanf("%d", &update);
                                        
                                        flag = 0;
                                        for (i = 0; i < num; i++) {
                                                if (update == e1[i].empId) {
                                                        
                                                        printf("\n\n WHAT YOU WANT TO UPDATE? \n");
                                                        printf("1) NAME\n");
                                                        printf("2) BASIC SALARY\n");
                                                        printf("3) HOUSE ALLOWANCE\n");
                                                        printf("4) MILLEAGE ALLOWANCE\n");
                                                        printf("5) OVERTIME ALLOWANCE\n");
                                                        printf("6) NHIF \n");
                                                        printf("7) PAYE \n");
                                                        printf("7) LOAN \n");
                                                        printf("7) NSSF \n");
                                                        printf("8) UPDATE ALL RECORDS \n");
                                                        printf("Enter your choice : ");
                                                        scanf("%d", &updateChoice);
                                                        
                                                        switch(updateChoice){
                                                                case 1 :        getchar();
                                                                                printf("Employee Name:");
                                                                                fgets(e1[i].name, 32, stdin);
                                                                                e1[i].name[strlen(e1[i].name) - 1] = '\0';
                                                                                break;

                                                                case 2 :        printf("Basic Salary:");
                                                                                scanf("%d", &(e1[i].basic));
                                                                                break;

                                                                case 3 :        printf("House Allowance:");
                                                                                scanf("%d", &(e1[i].ha));
                                                                                break;

                                                                case 4 :        printf("Milleage Allowance:");
                                                                                scanf("%d", &(e1[i].ma));
                                                                                break;

                                                                case 5 :        printf("Overtime Allowance:");
                                                                                scanf("%d", &(e1[i].oa));
                                                                                break;

                                                                case 6 :        printf("NHIF:");
                                                                                scanf("%d", &(e1[i].nhif));
                                                                                break;

                                                                case 7 :        printf("PAYE:");
                                                                                scanf("%d", &(e1[i].paye));
                                                                                break;

                                                                case 8 :        printf("Loan:");
                                                                                scanf("%d", &(e1[i].loan));
                                                                                break; 

                                                                case 9 :        printf("NSSF:");
                                                                                scanf("%d", &(e1[i].nssf));
                                                                                break;

                                                                case 10 :        getchar();
                                                                                printf("Employee Name:");
                                                                                fgets(e1[i].name, 32, stdin);
                                                                                e1[i].name[strlen(e1[i].name) - 1] = '\0';
                                                                                printf("Basic Salary:");
                                                                                scanf("%d", &(e1[i].basic));
                                                                                printf("House Allowance:");
                                                                                scanf("%d", &(e1[i].ha));
                                                                                printf("Milleage Allowance:");
                                                                                scanf("%d", &(e1[i].ma));
                                                                                printf("Overtime Allowance:");
                                                                                scanf("%d", &(e1[i].oa));
                                                                                printf("Enter the deductions:");
                                                                                printf("NHIF:");
                                                                                scanf("%d", &(e1[i].nhif));
                                                                                printf("PAYE:");
                                                                                scanf("%d", &(e1[i].paye));
                                                                                printf("Loan:");
                                                                                scanf("%d", &(e1[i].loan));
                                                                                printf("NSSF:");
                                                                                scanf("%d", &(e1[i].nssf));
                                                                                printf("\n");
                                                                                break;

                                                                default:        printf("Error Selection. Try Again !");
                                                        }
                                                        
                                                        flag = 1;
                                                }
                                        }

                                        if (!flag) {
                                                printf("No Record Found!!\n");
                                        }
                                        break;
                        case 5 : //printf("5");
                                 break;
                        default: printf("error");
                }

                printf("\n Do You Want To Continue(1/0):");
                scanf("%d", &ch);
                
                } else {
                        ch = 0;
                }

                if (!ch) {
                        break;
                }
        }
        return 0;
  }
