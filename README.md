# Push_swap

voir emplacement libft pour rendu

- 18.02:    ft_logic.c 		-> faire un clone de list_a pour verif si resultat identique apres un tri
                            -> si c'est different: maj du clone + printf operations
                            -> si c'est identique: maj du clone + suppr operations en att de print
            
            general ->      controler tous espaces4 - tab4
        
24.02:      faire pre-tri pour assigner valeurs du plus petit au plus grand > 1,2,3,4 etc
			bubblesort ->	if i0 > i1 = swap i++, else i++; j: nbre de chiffes (j-- quand au bout)

			ft_logic.c 	->	check le nombre de bits selon la "taille" des nombres pour boucle while "(pos < 4)"
							De 0 à 1 → 1 bit ( 21=221=2 )
							De 2 à 3 → 2 bits ( 22=422=4 )
							De 4 à 7 → 3 bits ( 23=823=8 )
							De 8 à 15 → 4 bits ( 24=1624=16 )
							etc

			general ->		voir si nombres negatifs
							! Error si certains param de sont pas des nombres !

							Error sur sortie d'erreur ! 

			! voir dereferencement et pointeurs (chatgpt - controle coherence..)

			tests ->		probleme ft_sort.c


- 25.02: 
#define PL() printf("-----\nfile: %s\nfunction: %s\nline: %d\n-----\n",\
		 __FILE__, __func__, __LINE__);
appel: PL();


- 1.03:
		fait:		- ajoute fichier complete.c pour tests avec toutes les fonctions

		a faire:	- controle .h prototypes
					- mise au propre fichiers
					- check jours precedents

					ok	- ft_logic.c - copy_list: enregistrer dans nouvelle chaine
						les operations, faire copie de list_a chaque iteration.
						imprimer les operations uniquement si list_a != copie

					ok	- faire pre-tri (bubble sort) pour assigner nombres (1, 2, 3, etc)
						aux int entrant (apres atoi) pour tri plus rapide des gros nombres, et pas besoin de gerer les binaires negatifs etc

					- voir ft_node.c - t_list_ps	*ft_create(int value)
					- ft_logic 25lignes!
		
		en cours:	- ft_logic (complete) copy_list 

- 7.03:
		fait:		- ok jusqu'a ft_logic

		a faire:	- check jours precedents
					ok	- tri radix selon list_a->num
					- mettre au propre fichiers separes + normi
					- makefile et .h
		
		en cours:	- test.c ok, complete.c pour suite (maj ok)

- 8.03	a faire:	ok	- Error s'ils ne tiennent pas dans un int
					ok	- si l'entree est 1 chaine ($ARG)
					- faire makefile pour ./libft
					- ajouter a ./libft atoi split etc
					- separer les fichiers
					- controler fonctions normi
					- propre .h

- 9.03	a faire:	- maj headers a 42
					- check .h + makefile
					- check norminette
		
		fait		- code ok