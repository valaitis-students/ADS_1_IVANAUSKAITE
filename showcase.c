#include "deque.h"

int validateAnswer(char *input){
    int convertedInput = atoi(input);
    if(convertedInput < 1 || convertedInput > 8){
        printf("Ivestis negalima.\n");
        getchar();
        return 0;
    }else{
        system("cls");
        return convertedInput;
    }
}

int inputChoice(){
    char answer[2];
    int validation = 0;
    do{
        printf("ANSWER - ");
        scanf("%s", &answer);
        validation = validateAnswer(answer);
    }while(validation == 0);
    return validation;
}

info dataInput(){
    info data = 0;
    printf("Data iterpiama: ");
    scanf("%u", &data); 
    return data;
}

void actions(int choice, deque *deck){
    int temp = 0;
    switch (choice){
    case 1:
        pushFront(deck, dataInput());
        break;
    case 2:
        pushBack(deck, dataInput());
        break;
    case 3:
        temp = nodesInDeque(*deck);
        printf("Elementu kiekis deke - %d ", temp);
        getch();
        break;
    case 4:
        if(emptyDeque(*deck) != 1){
            printf("Pirmame elemente saugomas skaicius - %d", dataFirstNode(*deck),"\n");
        }else{
            printf("Dekas yra tuscias.\n");
        }
        getch();
        break;
    case 5:
        if(emptyDeque(*deck) != 1){
            printf("Paskutiniame elemente saugomas skaicius - %d", dataLastNodde(*deck),"\n");
        }else{
            printf("Dekas yra tuscias.\n");
        }
        getch();
        break;
    case 6:
        printf("Elementai -");
        while(emptyDeque(*deck) != 1){
            printf(" %d", popFront(deck));
            printf(";");
        }
        getch();
        return;
    }
}

void menu(){
    printf("Pasirinkimai:(iveskite skaiciu operacijos, kuria norite atlikti)\n");
    printf("1. Iterpti elementa i pradzia.\n2. Iterpti elementa i pabaiga.\n3. Atspausdinti elementu kieki deke.\n4. Atspausdinti pirma elementa.\n5. Atspausdinti paskutini elementa.\n6. Atspausdinti deka.\n7. Sunaikinti deka ir uzdaryti programa.\n");
}

//MAIN--------------------------------------------------------------------------------
int main(){
    deque example = createDeque();
    int choice = 0;
    printf("DEKO, SAUGANCIO NATURALIUOSIUS SKAICIUS, KURIMAS.\n\n");
    while(choice != 7){
        menu();
        choice = inputChoice();
        actions(choice, &example);
        system("cls");
    }
    deleteDeque(&example);
    return 0;
}