# Checker Tema 1 - 2021
Checker-ul este o aplicație de testare automată a temelor. Este un produs open-source realizat de către și pentru studenții din Facultatea de Automatică și Calculatoare - UPB, și este menit atât să usureze munca asistenților de a corecta teme cât și sa ofere studenților o evaluare cât mai obiectivă.

## Rularea checker-ului
Pentru a verifica functionarea checker-ului va trebui sa descarcati tot depozitul de mai sus, dupa aceasta deschideti un terminal in folderul in care se afla depozitul descarcat si scrieti urmatoarea comanda:
```shell
./checker.sh
````



README - "BRAI STEFAN ADRIAN 313 AA"

    In implementarea realizata de mine am folosit parametrii functiei main
 pentru a accesa fisierele cu care operez.In continuare am luat un vector in care stochez cerintele prezente in c.in si le verific pe rand cu cate un "if" statement si realizez cerinta:

CERINTA 1:
    Folosesc functia read_team pentru a citi pe rand fiecare echipa si
 membrii sai. Echipele subnt stochate intr o stiva, iar in cadrul unei structuri "Team" se regaseste o stiva de structuri "Player".Dupa aceea, numele din stiva obtinuta sunt trecute in r.out.

CERINTA 2:
    Pentru cerinta 2 folosesc functia score_calculator pentru a calcula 
 punctajul echipelor si dupa aceea team_removal pentru a scoate numarul "no_of_teams- l" care reprezinta nr de echipe minus prima putere a lui 2 mai mica decat acesta.

CERINTA 3:
    Initial , adaug echipele obtinute la cerinta 2 , apoi pt n cicluri , n
 reprezentand puterea lui 2 ce ne da nr de echipe ramase , comparam 2 cate elem din coada si adaugam in stivele de castigatori si invinsi. La finalul unui ciclu , reumplem coada.

Cerinta 4:
    Adaug in BST-ul format din noduri ce contin numele si scorul echipei.Dupa aceea , parcurgem in preordine arborele si notam in r.out

CERINTA 5:
    Cu stiva salvata la cerinta 4 putem sa adaugam in AVL cu ajutorul
 functiilor prezentate la curs.Aceasta cerinta nu este realizata totusi intr un mod conventional , deoarece echilibrarea avl ului nu actualiza corect
 inaltimea unui nod.



