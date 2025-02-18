#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000

typedef struct s_hashnode {
    int value;
    struct s_hashnode *next;
} t_hashnode;

typedef struct s_hashset {
    t_hashnode *buckets[TABLE_SIZE];
} t_hashset;

// Fonction de hachage simple pour des int
unsigned int hash_function(int value) {
    return (unsigned int)value % TABLE_SIZE;
}

// Crée un ensemble vide
t_hashset *hashset_create(void) {
    t_hashset *set = malloc(sizeof(t_hashset));
    if (!set)
        return NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
        set->buckets[i] = NULL;
    return set;
}

// Vérifie si l'ensemble contient la valeur
bool hashset_contains(t_hashset *set, int value) {
    unsigned int index = hash_function(value);
    t_hashnode *node = set->buckets[index];
    while (node) {
        if (node->value == value)
            return true;
        node = node->next;
    }
    return false;
}

// Insère la valeur dans l'ensemble
void hashset_insert(t_hashset *set, int value) {
    unsigned int index = hash_function(value);
    t_hashnode *new_node = malloc(sizeof(t_hashnode));
    if (!new_node)
        return; // gestion simplifiée d'erreur
    new_node->value = value;
    new_node->next = set->buckets[index];
    set->buckets[index] = new_node;
}

// Libère la mémoire de la table de hachage
void hashset_destroy(t_hashset *set) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        t_hashnode *node = set->buckets[i];
        while (node) {
            t_hashnode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(set);
}

// Fonction qui vérifie s'il y a des doublons dans la liste
int check_double_hash(t_list_ps *list_a) {
    t_hashset *set = hashset_create();
    if (!set)
        return 0; // en cas d'échec de l'allocation

    while (list_a) {
        if (hashset_contains(set, list_a->value)) {
            hashset_destroy(set);
            return 0;
        }
        hashset_insert(set, list_a->value);
        list_a = list_a->next;
    }
    hashset_destroy(set);
    return 1;
}
