#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//VARIABLES-------------------------------------------------------------------------------
typedef unsigned int info;
typedef struct Node{
    struct Node *previous;
    struct Node *next;
    info data;
} *node;

typedef struct Deque{
    struct Node *first;
    struct Node *last;
} *deque;

//FUNKCIJOS---------------------------------------------------------------------------------
/*
- priima argumenta size - deko elementu maksimuma
- malloc isskiria vietos deque struct
- nustato rodykles i elementus NULL ir sukurtu elementu i 0
- grazina deque
*/
deque createDeque();
/*
- malloc isskiria vietos
- nustato visas rodykles i NULL
- grazina node
*/
node createNode();
/*
- jei rodykles i elementus nepriskirtos reiksmes bei sukurtu elementu kiekis lygus 0 - dekas tuscias - funkcija grazina 1
- kitaip grazina - 0
*/
int emptyDeque(deque deck);
/*
- jei rodyklems priskirtos reiksmes bei sukurtu elementu skaicius lygus deko dydziui - dekas pilnas - funkcija grazina 1
- kitaip grazina - 0
*/
int fullDeque(deque deck);
/*
- priima argumentus - adresa i deka; duomenis, saugomus elemente
- jei dekas pilnas - grazinama 1
- sukuriamas node
- node data skilciai priskiriami perduoti duomenys
- jei dekas tuscias - pirmam bei paskutiniam elementui priskiriamas dabartinis
- jei dekas netuscias - dabartinis node rodo i buvusi pirma elementa; dabartinis tampa pirmas elementas deke
- sukurtu elementu skaicius padideja 1
- grazinama - 0
*/
int pushFront(deque *deck, info input);
/*
- priima argumentus - adresa i deka; duomenis, saugomus elemente
- jei dekas pilnas - grazinama 1
- sukuriamas node
- node data skilciai priskiriami perduoti duomenys
- jei dekas tuscias - pirmam bei paskutiniam elementui priskiriamas dabartinis
- jei dekas netuscias - buves paskutinis rodo i dabartini node; dabartinis tampa paskutinis elementas deke
- sukurtu elementu skaicius padideja 1
- grazinama - 0
*/
int pushBack(deque *deck, info input);
/*
- priima argumenta - adresa i deka
- patikrinama, jei tuscias dekas, grazinama - NULL
- pirmo elemento duomenys issaugomi
- sekantis elementas tampa pirmu deke
- rodykle, i pries ji einanti elementa, nustatoma i NULL
- buves pirmas elementas istrinamas
- grazinama duomenys buve elemente
*/
info popFront(deque *deck);
/*
- priima argumenta - adresa i deka
- patikrinama, jei tuscias dekas, grazinama - NULL
- paskutinio elemento duomenys issaugomi
- pries ji einantis elementas tampa paskutiniu deke
- rodykle, i sekanti, nustatoma i NULL
- buves paskutinis elementas istrinamas
- grazinama duomenys buve elemente
*/
info popBack(deque *deck);
/*
- patikrinama, jei tuscias dekas, atlaisvinamas deko kintamasis
- jei deke yra elementu, kievienas atskirai atlaisvinamas, kol dekas lieka tuscias
*/
void deleteDeque(deque *deck);
/*
- grazina deko sukurtu elementu kieki
*/
int nodesInDeque(deque deck);
/*
- priima argumenta - deka 
- patikrinama, jei dekas tuscias, grazinama - NULL
- kitaip, grazinama pirmo elemento duomenys
*/
info dataFirstNode(deque deck);
/*
- priima argumenta - deka 
- patikrinama, jei dekas tuscias, grazinama - NULL
- kitaip, grazinama pirmo elemento duomenys
*/
info dataLastNodde(deque deck);
#endif