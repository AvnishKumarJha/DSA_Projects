// Program of Medical Store  Management System using Linked List in c.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Medicine
{
    int id, price, quantity;
    char medicinename[100];
    char Company[100], info[50000];
    int Mfg_Date;
    int Exp_Date;
    struct Medicine *next;
} * head;

void insert(int id, int price, int quantity, char *medicinename, char *Company, char *info, int Mfg_date, int Exp_date)
{

    struct Medicine *Medicine = (struct Medicine *)malloc(sizeof(struct Medicine));
    Medicine->id = id;
    Medicine->price = price;
    Medicine->quantity = quantity;
    Medicine->Mfg_Date = Mfg_date;
    Medicine->Exp_Date = Exp_date;

    strcpy(Medicine->medicinename, medicinename);
    strcpy(Medicine->Company, Company);
    strcpy(Medicine->info, info);
    Medicine->next = NULL;

    if (head == NULL)
    {
        
        head = Medicine;
    }
    else
    {
        
        Medicine->next = head;
        head = Medicine;
    }
}

void search(int id)
{
    struct Medicine *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("Id Number: %d\n", temp->id);
            printf("The price of the Medicine is: %d\n", temp->price);
            printf("The Quantity of the Medicine is: %d\n", temp->quantity);
            printf("Medicine Name: %s\n", temp->medicinename);
            printf("Company: %s\n", temp->Company);
            printf("Info: %s\n", temp->info);
            printf("Manufacture date of the medicine is: %d\n",temp->Mfg_Date);
            printf("Expiry date of the medicine is: %d\n", temp->Exp_Date);
            return;
        }
        temp = temp->next;
    }
    printf("Medicine with Id Number %d is not found !!!\n", id);
}

void update(int id)
{

    struct Medicine *temp = head;
    while (temp != NULL)
    {

        if (temp->id == id)
        {
            printf("Record with Id Number %d Found !!!\n", id);
            printf("Enter the Price of the medicine: ");
            scanf("%d\n", &temp->price);
            printf("Enter the quantity of the medicine: ");
            scanf("%d\n", &temp->quantity);
            printf("Enter New Medicine Name: ");
            scanf("%s\n", &temp->medicinename[100]);
            printf("Enter New Company: ");
            scanf("%s\n", &temp->Company[100]);
            printf("Enter New Info: ");
            scanf("%s\n", &temp->info[50000]);
            printf("Manufacture date of the medicine is: \n" );
            scanf("%d",temp->Mfg_Date);
            printf("Expiry date of the medicine is: \n");
            scanf("%d", &temp->Exp_Date);

            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Medicine with Id Number %d is not found !!!\n", id);
}

void Delete(int id)
{
    struct Medicine *temp1 = head;
    struct Medicine *temp2 = head;
    while (temp1 != NULL)
    {

        if (temp1->id == id)
        {

            printf("Record with Id Number %d Found !!!\n", id);

            if (temp1 == temp2)
            {
                
                head = head->next;
                free(temp1);
            }
            else
            {
                
                temp2->next = temp1->next;
                free(temp1);
            }

            printf("Record Successfully Deleted !!!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("Student with Id Number %d is not found !!!\n", id);
}

void display()
{
    struct Medicine *temp = head;
    while (temp != NULL)
    {

        printf("Id Number: %d\n", temp->id);
        printf("Price: %d\n", temp->price);
        printf("Quantity: %d\n", temp->quantity);
        printf("Medicine Name: %s\n", temp->medicinename);
        printf("Company: %s\n", temp->Company);
        printf("Info : %s\n", temp->info);
        printf("Manufacture Date : %d\n", temp->Mfg_Date);
        printf("Expiry Date : %d\n", temp->Exp_Date);

        temp = temp->next;
    }
}

void main()
{
    head = NULL;
    int choice;
    int id;
    int price;
    int quantity;
    char medicinename[100];
    char company[100];
    char info[50000];
    int Mfg_Date[20];
    int Exp_Date[20];

    printf("1. To Insert Medicine details\n2. To Search for Medicine details\n3. To Delete Medicine details\n4. To Update Medicine details\n5. To Display all Medicine details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Id Number: ");
            scanf("%d", &id);
            printf("Enter price: ");
            scanf("%d", &price);
            printf("Enter Quantity: ");
            scanf("%d", &quantity);
            printf("Enter Medicine Name: ");
            scanf("%s",&medicinename[100]);
            printf("Enter Company Name: ");
            scanf("%s", company);
            printf("Enter Info About Medicine: ");
            scanf("%s", info);
            printf("Enter the Manufacture Date : ");
            scanf("%d", Mfg_Date);
            printf("Enter the Expiry date: ");
            scanf("%d", Exp_Date);
            insert(id, price, quantity, medicinename, company, info, *Mfg_Date, *Exp_Date);
            break;

        case 2:
            printf("Enter Id Number to search: ");
            scanf("%d", &id);
            search(id);
            break;

        case 3:
            printf("Enter Id Number to delete: ");
            scanf("%d", &id);
            Delete(id);
            break;

        case 4:
            printf("Enter Id Number to Update: ");
            scanf("%d", &id);
            update(id);
            break;

        case 5:
            display();
            break;
        }

    } while (choice != 0);
}
