/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo2 - classe String
 Fichier     : String.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 01.04.2020

 But         : Classe qui reproduit le type string en c++

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO2_2020_STRING_H
#define POO2LABO2_2020_STRING_H

#include <cstdlib>
#include <string>

class String {
    /**
     * Surcharge de l'opérateur + pour concaténation String/String
     * @param lhs membre de gauche
     * @param rhs membre de droite
     * @return résultat de la concaténation
     */
    friend String operator+(String lhs, const String &rhs);

    /**
     * Surcharge de l'opérateur + pour concaténation String/chaînes de caractères
     * @param lhs membre de gauche
     * @param rhs membre de droite
     * @return résultat de la concaténation
     */
    friend String operator+(String lhs, const char *rhs);

    /**
     * Surcharge de l'opérateur + pour concaténation chaînes de caractères/String
     * @param lhs membre de gauche
     * @param rhs membre de droite
     * @return résultat de la concaténation
     */
    friend String operator+(const char *lhs, const String &rhs);

    /**
     * Surcharge de l'opérateur de flux sortant
     * @param out flux de sortie
     * @param rhs membre de droite
     * @return flux de sortie
     */
    friend std::ostream &operator<<(std::ostream &out, const String &rhs);

    /**
     * Surcharge de l'opérateur de flux entrant
     * @param in flux entrant
     * @param rhs membre de droite
     * @return flux entrant
     */
    friend std::istream &operator>>(std::istream &in, String &rhs);

public :
    /**
     * Constructeur de String vide
     */
    explicit String();

    /**
     * Constructeur de copie
     * @param other String a copier
     */
    String(const String &other);

    /**
     * Constructeur par chaîne de caractères
     * @param other chaîne de caractères
     */
    explicit String(const char *const &other);

    /**
     * Constructeur par caractère simple
     * @param c char
     */
    explicit String(char c);

    /**
     * Constructeur pas booléen
     * @param b booléen
     */
    explicit String(bool b);

    /**
     * Constructeur par entier
     * @param i entier
     */
    explicit String(int i);

    /**
     * Constructeur par double
     * @param d double
     */
    explicit String(double d);

    /**
     * Méthode qui donne la taille de la String sans le caractère de fin
     * @return la taille de la String
     */
    size_t size() const;

    /**
     * Méthode d'accès à un élément de la String
     * @throws out_of_range
     * @param i index d'accès
     * @return référence sur la valeur
     */
    char &at(size_t i) const;

    /**
     * Surcharge de l'opérateur[] qui permet l'accès à un élément de la String
     * @throws out_of_range
     * @param i index d'accès
     * @return référence sur la valeur
     */
    char &operator[](size_t i) const;

    /**
     * Méthode qui renvoi la String sous forme d'une chaîne de caractères
     * @return la chaîne de caractères
     */
    const char *getCString() const;

    /**
     * Surcharge de l'opérateur d'égalité
     * @param other String de comparaison
     * @return vrai ou faux selon la comparaison
     */
    bool operator==(const String &other) const;

    /**
     * Surcharge de l'opérateur d'égalité avec une chaîne de caractère en comparaison
     * @param other chaîne de caractères à comparer
     * @return vrai ou faux selon la comparaison
     */
    bool operator==(const char *const &other) const;

    /**
     * Méthode de comparaison de contenu de deux Strings
     * @param other String de comparaison
     * @return vrai ou faux selon la comparaison
     */
    bool equal(const String &other) const;

    /**
     * Méthode de comparaison de contenu d'une String avec une chaîne de caractères
     * @param other chaîne de caractères de comparaison
     * @return vrai ou faux selon la comparaison
     */
    bool equal(const char *const &other) const;

    /**
     * Surcharge de l'opérateur d'affectation
     * @param other String à affecter
     * @return notre objet
     */
    String &operator=(const String &other);

    /**
     * Surcharge de l'opérateur d'affectation avec une chaîne de caractères
     * @param other chaîne de caractères à affecter
     * @return notre objet
     */
    String &operator=(const char *const &other);

    /**
     * Méthode qui permet de mettre à jour le contenu de la String
     * @param other autre String sur laquelle mettre à jour
     */
    String &set(const String &other);

    /**
     * Méthode qui permet de mettre à jour le contenu de la String
     * @param other chaîne de caractère sur laquelle mettre à jour
     */
    String &set(const char *const &other);

    /**
     * Méthode qui permet la concaténation d'une String
     * @param other paramètre à concaténer
     * @return le résultats de la concaténation
     */
    String &append(const String &other);

    /**
     * Méthode qui permet la concaténation d'un const char*
     * @param other paramètre à concaténer
     * @return le résultats de la concaténation
     */
    String &append(const char *const &other);

    /**
     * Surcharge de la méthode += avec une String
     * @param other paramètre à concaténer
     * @return le résultats de la concaténation
     */
    String &operator+=(const String &other);

    /**
     * Surcharge de la méthode += avec un const char*
     * @param other paramètre à concaténer
     * @return le résultats de la concaténation
     */
    String &operator+=(const char *const &other);

    /**
     * Méthode qui permet de prendre une sous String continue dans notre String
     * @throws out_of_range, invalid_argument
     * @param begin début de la String
     * @param end fin de la String
     * @return la sous chaîne continue
     */
    String subString(size_t begin, size_t end) const;

    /**
     * Destructeur
     */
    ~String();

private :
    char *content; // contenu de notre String
    /**
     * Méthode qui permet l'initialisation pour la construction d'une String
     * @param content chaîne qui servira de contenu
     */
    void initialize(const char *content);

    /**
     * Méthode d'effacement de la mémoire
     */
    void erase();

    static const size_t READING_MAX = 120;

    /**
     * Méthode qui permet la création d'une String depuis un nombre
     * @param number nombre à convertir
     */
    void numberToString(double number);
};

#endif //POO2LABO2_2020_STRING_H
