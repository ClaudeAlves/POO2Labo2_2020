/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 - classe String
 Fichier     : main.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 01.04.2020

 But         : Fichier de tests de notre classe String

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include <iostream>
#include "String.h"

using namespace std;

int main() {
    cout << boolalpha; // affichage en boolean plutôt que 0/1
    // chaîne vide
    String emptyString;
    cout << "il devrait y avoir une chaîne vide ici :D : " << emptyString << endl;
    // constructeur de copie
    String toBeCopied("Yamaha");
    String copy(toBeCopied);
    cout << "à copier : " << toBeCopied << ", copie : " << copy << endl;
    // constructeur par char/int/double/bool
    String booleanString(true);
    String doubleString(12.2);
    String intString(13);
    String charString('G');
    cout << "constructeur de char : " << charString << endl
         << "constructeur de int : " << intString << endl
         << "constructeur de double : " << doubleString << endl
         << "constructeur de bool : " << booleanString << endl;
    // concaténation
    /**
     * ici nous ne testons que la méthode append(const char*) car celle-ci est appelées par append(string) et ces
     * deux méthodes sont ensuite appelées par operator+= respectivement pour const char * et String puis celles-ci
     * par les méthodes operator+
     */
    String hello("Hello");
    const char *world = "world";
    cout << "Concatenation de : " << hello << " et : " << world << " : " << hello.append(world) << endl;
    // opérations de modification
    /**
     * comme pour la concaténation ici nous ne testons que la méthode set(const char*) car les méthodes
     * operator=(String) operator=(const char*) et at(string) la réutilisent
     */
    String before("Avant");
    const char *after = "Apres";
    cout << "La string " << before << " devient " << before.set(after) << endl;
    // opérations d'égalité
    /**
     * une fois n'est pas coutume nous allons tester que la méthode equal(const char*) car les méthodes
     * operator==(const char*) operator==(String) et equal(String) l'appelent
     */
    String toCompare("un");
    const char *toCompareFalse = "deux";
    const char *toCompareTrue = "un";
    cout << "la string " << toCompare << " est elle egale a " << toCompareFalse << " : "
         << toCompare.equal(toCompareFalse) << endl;
    cout << "la string " << toCompare << " est elle egale a " << toCompareTrue << " : "
         << toCompare.equal(toCompareTrue) << endl;
    // opérations d'accès at [] substr
    String access("la Belle et le Clochard");
    cout << "La String est : " << access << endl
         << "\tla position 0 avec operator[] : " << access[0] << endl
         << "\tla position 4 avec at : " << access.at(4) << endl
         << "\tune substring : " << access.subString(3, 7) << endl;
    // String à la c ainsi que taille
    String fourSizedString("1234");
    cout << "la taille de " << fourSizedString << " est de " << fourSizedString.size() << endl;
    cout << "la chaine de caracteres au format C de " << fourSizedString << " est " << fourSizedString.getCString()
         << endl;
    // opérations de flux
    String saisie;
    cin >> saisie;
    cout << saisie;

    return EXIT_SUCCESS;
}
