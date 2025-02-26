# Push_swap

voir emplacement libft pour rendu

- 18.02:    ft_logic.c ->   faire un clone de list_a pour verif si resultat identique apres un tri
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