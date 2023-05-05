#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//-----------------------------Structures
//nested struct
struct Details {
    float weight;
    float height;
    float ExcHr;
    char FoodType[30];
};
typedef struct Details data;
//main struct
struct Client {
    char Name[30];
    int Gender;
    int Age;
    struct Details data;
};
typedef struct Client client;
//--------------------------Global variables
client *arr = NULL;//global array
int SIZE = 0;      //initializing size of array
int client_num = 0;//index of array
//--------------------------functions
void print_menu();
void add();
void Delete();
void up_date();
void sorting();
void display();
int find_index();
void swap(client *a, client *b);
int main() {
    arr = (client*) malloc(SIZE * sizeof(client));
    int choice;
    while (1) {
        print_menu();
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            add();
            break;

        case 2:
            Delete();
            break;

        case 3:
            up_date();
            break;

        case 4:
            sorting();
            break;

        case 5:
            display();
            break;

        case 0:
            free(arr);
            exit(0);

        default:
            printf("Invalid input");
        }
    }

    free(arr);
    return 0;
}
void print_menu() {
    printf("====================================\n");
    printf("Clients' Data \n");
    printf("choose the desired function:\n");
    printf("1- Add new account\n");
    printf("2- Delete account\n");
    printf("3- Update account\n");
    printf("4- Sort account\n");
    printf("5- Display all accounts\n");
    printf("0- Exit\n");
    printf("-->> ");

}

void add() {
    SIZE++ ;//increment size
    arr = (client*) realloc(arr, SIZE * sizeof(client));
    printf("Please fillout the following data\n");
    printf("Name: ");
    fgets(arr[client_num].Name,30,stdin);
    fgets(arr[client_num].Name,30,stdin);
    printf("Choose Gender:\n1.Female\n2.Male\n>> ");
    scanf("%d",&arr[client_num].Gender);
    printf("Age: ");
    scanf("%d",&arr[client_num].Age);
    printf("Choose the type of diet:\n");
    printf("- omnivorous \n");
    printf("- Vegetarian \n>> ");
    fgets(arr[client_num].data.FoodType,30,stdin);
    fgets(arr[client_num].data.FoodType,30,stdin);
    printf("Weight = ");
    scanf("%f",&arr[client_num].data.weight);
    printf("\nHeight = ");
    scanf("%f",&arr[client_num].data.height);
    printf("\nTotal working-out hours per week = ");
    scanf("%f",&arr[client_num].data.ExcHr);
    client_num++;//increment num of clients
}

void Delete () {
    int i = find_index();//index of acc need to be deleted
    if(i != -1) {
        //swap
        if(i < (SIZE-1)) {
            swap( &arr[SIZE-1], &arr[i]);
        }
        printf("Deleted!\n");
        SIZE-- ;
        arr = (client*) realloc(arr, SIZE * sizeof(client));
    } else {
        printf("Account doesn't exist!\n");
    }

}
void display() {
    if(SIZE==0)
        printf("Array is empty!\n");
    int i;

    for(i=0; i < SIZE ; i++) {
        printf("---------------------------------\n");
        printf("client number %d",i+1);
        printf("\nName:              %s",arr[i].Name);
        if(arr[i].Gender == 1)
            printf("Gender:            Female\n");
        else
            printf("Gender:            Male\n");
        printf("Age:               %d\n",arr[i].Age);
        printf("Weight:            %.2f Kg\n",arr[i].data.weight);
        printf("Height:            %.2f Cm\n",arr[i].data.height);
        printf("working-Out hours: %.2f hrs/week\n",arr[i].data.ExcHr);
        printf("Type of diet:      %s\n",arr[i].data.FoodType);
    }
}
int find_index() {

    int i, index=-1;
    char iname[30];
    int age_;
    printf("Enter name: ");
    fgets(iname,30,stdin);
    fgets(iname,30,stdin);
    printf("Enter your age: ");
    scanf("%d",&age_);
    for(i=0 ; i < SIZE; i++) {
        if((strcmp((arr[i].Name),(iname)) == 0) && (age_ == arr[i].Age)) {
            index=i;
            break;
        }
    }
    return (index);
}

void swap(client *a, client *b) {
    client temp = *a;
    *b = *a;
    *a = temp;
}
void up_date() {
    int opp;
    int f = find_index();
    if(f != -1) {
        printf("Choose the data needed to be updated:\n");
        printf("1- All data\n");
        printf("2- Name\n");
        printf("3- Gender\n");
        printf("4- Age\n");
        printf("5- Weight\n");
        printf("6- Height\n");
        printf("7- Working-Out hours per week\n");
        printf("8- Type of diet\n>> ");
        scanf("%d",&opp);
        switch(opp) {
        case 1: {
            printf("Please fillout the following data\n");
            printf("Name: ");
            fgets(arr[f].Name,30,stdin);
            fgets(arr[f].Name,30,stdin);
            printf("Choose Gender:\n1.Female\n2.Male\n>> ");
            scanf("%d",&arr[f].Gender);
            printf("Age: ");
            scanf("%d",&arr[f].Age);
            printf("Choose the type of diet:\n");
            printf("- omnivorous \n");
            printf("- Vegetarian \n>> ");
            fgets(arr[f].data.FoodType,30,stdin);
            fgets(arr[f].data.FoodType,30,stdin);
            printf("Weight = ");
            scanf("%f",&arr[f].data.weight);
            printf("\nHeight = ");
            scanf("%f",&arr[f].data.height);
            printf("\nTotal working-out hours per week = ");
            scanf("%f",&arr[f].data.ExcHr);
        }
        break;
        case 2: {
            printf("Name: ");
            fgets(arr[f].Name,30,stdin);
            fgets(arr[f].Name,30,stdin);
        }
        break;
        case 3: {
            printf("Choose Gender:\n1.Female\n2.Male\n>> ");
            scanf("%d",&arr[f].Gender);
        }
        break;
        case 4: {
            printf("Age: ");
            scanf("%d",&arr[f].Age);
        }
        break;
        case 5: {
            printf("Weight = ");
            scanf("%f",&arr[f].data.weight);
        }
        break;
        case 6: {
            printf("\nHeight = ");
            scanf("%f",&arr[f].data.height);
        }
        break;
        case 7: {
            printf("\nTotal working-out hours per week = ");
            scanf("%f",&arr[f].data.ExcHr);
        }
        break;
        case 8: {
            printf("Choose the type of diet:\n");
            printf("- omnivorous \n");
            printf("- Vegetarian \n>> ");
        }
        break;
        }
    } else
        printf("Account doesn't exists!!\n");
}
void sorting() {
    char temp[30], temp_[30] ;
    int temp_x, temp_y ;
    float temp_w, temp_h, temp_r ;
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (strcmp(arr[i].Name, arr[j].Name) > 0) {
                //swapping names
                strcpy(temp, arr[i].Name);
                strcpy(arr[i].Name, arr[j].Name);
                strcpy(arr[j].Name, temp);
                //swapping type of diet
                strcpy(temp_, arr[i].data.FoodType);
                strcpy(arr[i].data.FoodType, arr[j].data.FoodType);
                strcpy(arr[j].data.FoodType, temp_);
                //swapping age
                temp_x = arr[i].Age ;
                arr[i].Age = arr[j].Age ;
                arr[j].Age = temp_x ;
                //swapping gender
                temp_y = arr[i].Gender ;
                arr[i].Gender = arr[j].Gender ;
                arr[j].Gender = temp_y ;
                //swapping	weights
                temp_w = arr[i].data.weight ;
                arr[i].data.weight = arr[j].data.weight ;
                arr[j].data.weight = temp_w ;
                //swapping heights
                temp_h = arr[i].data.height ;
                arr[i].data.height = arr[j].data.height ;
                arr[j].data.height = temp_h ;
                //swapping ExcHrs
                temp_r = arr[i].data.ExcHr ;
                arr[i].data.ExcHr = arr[j].data.ExcHr ;
                arr[j].data.ExcHr = temp_r ;
            } else if (strcmp(arr[i].Name, arr[j].Name) == 0) {
                if (arr[i].Age > arr[j].Age) {
                    //swapping ages
                    temp_x = arr[i].Age ;
                    arr[i].Age = arr[j].Age ;
                    arr[j].Age = temp_x ;
                    //swapping gender
                    temp_y = arr[i].Gender ;
                    arr[i].Gender = arr[j].Gender ;
                    arr[j].Gender = temp_y ;
                    //swapping	weights
                    temp_w = arr[i].data.weight ;
                    arr[i].data.weight = arr[j].data.weight ;
                    arr[j].data.weight = temp_w ;
                    //swapping heights
                    temp_h = arr[i].data.height ;
                    arr[i].data.height = arr[j].data.height ;
                    arr[j].data.height = temp_h ;
                    //swapping ExcHrs
                    temp_r = arr[i].data.ExcHr ;
                    arr[i].data.ExcHr = arr[j].data.ExcHr ;
                    arr[j].data.ExcHr = temp_r ;
                    //swapping names
                    strcpy(temp, arr[i].Name);
                    strcpy(arr[i].Name, arr[j].Name);
                    strcpy(arr[j].Name, temp);
                    //swapping type of diet
                    strcpy(temp_, arr[i].data.FoodType);
                    strcpy(arr[i].data.FoodType, arr[j].data.FoodType);
                    strcpy(arr[j].data.FoodType, temp_);

                }
            }
        }
    }
    display();
}
