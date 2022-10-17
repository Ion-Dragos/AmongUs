# Among Us
## Ion Dragos - Cosmin


* TASK 1 

    * Pentru acest task am construit matricea direct. Nu am mai construit-o in forma initiala dupa sa o rotesc la dreapta pentru ca mi s-a parut ineficient
    * De asemenea nu am folosit strcpy-uri sau strcat-uri pentru ca am inteles ca ar fi niste functi lente iar mai tarziu ar fi incetinit foarte mult rularea checker-ului. 
    * Ideea la care m-am gandit a fost sa aloc dinamic o variabila sub forma unui vector si nu sub forma de matrice pentru a fi mai usor sa introduc elemente in aceasta. Stiu ca puteam sa fac mult mai usor si mai eficient toata treaba asta cu cazurile insa nu am mai apucat sa modific.
    * Daca input-ul este un numar de o cifra o iau pur si simplu si o pun in matrice, adaugand '0' pentru a transorma int in char
    * Daca input-ul este un numar de doua cifre atunci mai intai iau prima cifra si o introduc, dupa pe cea de-a doua. Acelasi rationament este si pentru cazul cand input-ul are 3 cifre.
    * Un lucru destul de nasol a fost faptul ca au fost putine teste, iar acestea pentru task-ul 1 acopereau doar cazurile cand input-ul are 1 sau 2 cifre, iar la task-ul 8 apar si cazuri cand are 3.

* TASK 2

    * Acest task mi s-a parut cel mai accesibil, iar acest lucru se datoreaza faptului ca in tema 2 am avut ceva asemanator cand venea vorba sa scoatem input-ul cu strtok. 
    * Am intializat un char pointer token si am alocat dinamic un string result pe care il voi casta la sfarsit in void*. De fiecare data cand se intaleste caracterul '_' se ia numarul care se afla dupa el si se aduna la suma
    * Transform din int in char cu atoi pentru a avea grija si de cazurile cand un numar este negativ.

* TASK 3

    * Pentru acest task am luat input-ul si l-am pus intr-un int pointer numit vector. De aici am extras primul elemente care reprezinta numarul de elemente din vector.
    * Pe urma am luat primul caz cand numarul de elemente este par. Am declarat si alocat dinamic doua buffere pentru a pastra in ele elementele pe care le extrag. Practic trebuie sa interschimb elementele de pe pozitiile i si i + 1. La sfarsit trebuie sa am grija si la ultimul caracter sa fie '\0'.
    * Pentru cel de-al doilea caz trebuie practic sa inversez vectorul. Mi s-a parul mai usor sa il parcurg invers si sa introduc fiecare element pe rand in vectorul meu alocat dinamic. La fel, trebuie sa am grija la null terminator.

* TASK 4

    * Aici nu cred ca sunt multe de explicat. Pur si simplu am alocat dinamic structurile date conform cerintei.

* TASK 5

    * Acest task mi s-a parut cel mai dificil pentru ca a trebuit sa inteleg efectiv cum functioneaza structurile si pointerii insa a fost foarte bun a-mi implementa in rutina cum sa lucrez cu aceastea. In rest pur si simplu am respectat formatul dorit de tema.

* TASK 6

    * Acest task pot spune ca a fost cel mai frustrant pentru ca a trebuit sa respect in tocmai modul in care cei care au realizat tema au dorit sa scriem Playerii si Game-ul
    * Ciudat a fost faptul ca pe ocw nu este scris corect exact formatul si a trebuit sa ma uit in teste de multe ori si pentru un singur spatiu gresit nu se acordau puncte.

* TASK 7

    * Pentru acest task am realizat o functie auxiliara pentru a modulariza mai bine codul numita ManhattanDistance care calculeaza distanta dintre impostor si un crewmate
    * Pe urma iterez prin toti crewmates iar daca acestia sunt in viata le calculez distanta Manhattan. Daca aceasta este mai mica decat killRange atunci vad care este cea mai mica si retin in variabila index_of_player pozitia acestuia. Am pus <= pentru a-l lua pe cel care are index-ul mai mare asa cum este precizat in cerinta. Daca index_of_player este diferit de -1 inseamna ca nimeni nu a fost omorat.

* TASK 8

    * Am tinut cont sa incep sa calculez distanta Manhattan de la cea de-a doua pozitie si sa fie circular modul in care sunt acestea alese.

* TASK 9

    * Am dat free la toate structurile folosite


