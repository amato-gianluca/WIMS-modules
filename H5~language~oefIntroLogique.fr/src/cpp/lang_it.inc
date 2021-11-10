\text{ou=o}
\text{et=e}
\text{si1=se}
\text{si2=se}
\text{Si1=Se}
\text{Si2=Se}
\text{alors=allora}
\text{oui=sì}
\text{non=no}
\text{non2=non}
\text{spacebeforecolon=}
\text{Remarque=Nota}


#if defined TARGET_connecteursLN
\text{Alist =
c'è uno sciopero degli autobus,
stamattina piove,
fa freddo,
c'è il sole,
sta piovendo,
mangio un sacco di torte,
sono felice,
ascolto Radio Latina,
voglio progredire in matematica,
voglio migliorare il mio inglese,
ho il raffreddore,
lei balla,
suoni la chitarra,
non vuole diventare un ingegnere,
fai schifo in matematica,
siamo tristi,
il lavoro è motivante
}

\text{Blist =
sono in ritardo per la scuola,
prendo il mio ombrello,
mi metto un maglione,
indosso occhiali scuri,
fa freddo,
sto ingrassando,
rido,
io ballo la salsa,
mi esercito con WIMS,
vedrò solo i film in versione originale,
la mia voce è rotta,
lei corre,
tu canti,
lei vuole andare all'estero,
sei forte in francese,
siamo innamorati,
la soddisfazione è totale
}

\text{nonAlist=
non c'è sciopero degli autobus,
stamattina non piove,
non fa freddo,
non c'è il sole,
non sta piovendo,
mangio poche torte,
sono triste,
non ascolto Radio Latina,
non voglio progredire in matematica,
non voglio migliorare il mio inglese,
non ho il raffreddore,
lei non balla,
non suoni la chitarra,
vuole diventare un ingegnere,
sei bravo in matematica,
siamo felici,
il lavoro non è motivante
}

\text{nonBlist=
non sono in ritardo per la scuola,
non prendo il mio ombrello,
non ho indossato un maglione,
non porto occhiali scuri,
è caldo,
non sto ingrassando,
non rido,
non ballo la salsa,
non mi esercito con WIMS,
guardo Lost In Translation in italiano,
parlo normalmente,
lei non corre,
tu non canti,
vuole restare in Italia,
fai schifo in francese,
non siamo innamorati,
la soddisfazione è parziale
}

\text{name_statement1=Per ciascuna delle seguenti proposizioni, a sinistra, determina la sua struttura logica.}
\text{name_statement2=le proposizioni possono essere solo vere o false... }
\text{name_statement3=(Fare clic sugli elementi corrispondenti a due a due.)}

#endif

#if defined TARGET_deduction
\text{Alist =
c'è uno sciopero degli autobus,
piove al mattino,
fa freddo,
c'è il sole,
mangio un sacco di torte,
sono felice,
io ballo la salsa,
voglio progredire,
voglio migliorare il mio inglese,
ho il raffreddore
}

\text{Blist =
sono in ritardo per la scuola,
prendo il mio ombrello,
mi metto un maglione,
indosso occhiali scuri,
sto ingrassando,
rido,
ascolto solo Radio Latina,
mi esercito con WIMS,
vedo tutti i film in versione originale,
la mia voce è rotta
}

\text{nonAlist=
gli autobus non scioperano,
non piove al mattino,
non è freddo,
non c'è il sole oggi,
ho mangiato poche torte,
sono triste,
non mi piace la salsa,
non voglio progredire,
non voglio migliorare il mio inglese,
non ho il raffreddore
}

\text{nonBlist=
non sono in ritardo per la scuola,
non prendo il mio ombrello,
non ho indossato un maglione,
non porto occhiali scuri,
non sono ingrassato,
non rido,
ho ascoltato Fun Radio,
non mi sono esercitato con WIMS,
Guardo Lost In Translation in italiano,
parlo normalmente
}

\text{name_statement1=Assumiamo che sia vera la seguente implicazione:}
\text{name_statement2=Qualcuno mi incontra e nota che:}
\text{name_statement3=Questa persona deduce che:}
\text{name_statement4=Il suo ragionamento è corretto ?}
\text{name_answer=Ragionameto corretto}
#endif

#if defined TARGET_implication
\text{Quand=Quando}
\text{Chaque=Ogni volta che}
\text{whatif=Senza fare altre ipotesi, cosa possiamo dire che succede quando}

\text{prem = Il signor Alex si siede davanti alla TV,
La signora Alice esce a fare una passeggiata nel parco,
Fred è nel parco,
Suzy si arrampica sull'albero,
Nestor si gira nel parco,
Bubu si seppellisce sottoterra,
Fred fruga nella sporcizia,
La signora Alice è molto arrabbiata
}

\text{conc = La signora Alice esce a fare una passeggiata nel parco,
il suo cane Fred lo accompagna,
Suzy si arrampica sull'albero,
Nestor lascia l'albero per girarsi nel parco,
Bubu si seppellisce sottoterra,
Fred fruga nella sporcizia,
La signora Alice si arrabbia,
Il signor Alex si siede davanti alla TV
}

\text{nonPr = Il signor Alex non si siede davanti alla TV,
La signora Alice non esce a fare una passeggiata nel parco,
Fred non è nel parco,
Suzy non si arrampica sull'albero,
Nestor non si gira nel parco,
Bubu non si seppellisce sottoterra,
Fred non scava nella sporcizia,
La signora Alice non si arrabbia
}

\text{nonCo = La signora Alice non esce a fare una passeggiata nel parco,
Fred non accompagna la signora Alice,
Suzy non si arrampica sull'albero,
Nestor non lascia l'albero per girarsi nel parco,
Bubu non si seppellisce sottoterra,
Fred non scava nella sporcizia,
La signora Alice non si arrabbia,
Il signor Alex non si siede davanti alla TV
}

\text{sujPr=il Signor Alex, la Signora Alice, Fred il cane, Suzy il gatto, Nestor il passero, Bubu il lombrico, Fred il cane, la Signora Alice}
\text{sujCo=la Signora Alice, Fred il cane, Suzy il gatto, Nestor il passero, Bubu il lombrico, Fred il cane, la Signora Alice, il Signor Alex}
\text{none=non possiamo concludere nulla}

\text{name_citation=Questo esercizio si basa su un esempio
fornito da Alan Selby, in "Elements of Reason: understanding and explaining reason and math"
Volume 1,
Stampato in Canada
ISBN 0-9697564-1-0.
http://whyslopes.com/volume1a/}

\text{Question=Domanda}
\text{name_characters=I nostri personaggi sono}
\text{name_statement1=Si consideri la seguente implicazione, che assumiamo essere vera:}
\text{name_statement2=Si considerino le seguenti implicazioni, che assumiamo essere entrambe vere:}

#endif

#if defined TARGET_incoherence
\text{Alist=è svedese, è scozzese, è australiano, è tedesca, è cubana, è giapponese}
\text{Blist=gioca a tennis, suona il violino, fa surf, suona il piano, balla la salsa, fa Kendo}
\text{Clist=è biondo, indossa una gonna, non indossa una cravatta, non si trucca, è bruna, indossa il kimono}
\text{Dlist=sta sciando, lui gioca a rugby, trascorre le vacanze a Bali, va in bicicletta, ama la matematica, fa gli origami}
\text{Elist=è vegetariano, è sposato, gli piace la birra, le piacciono i wurstel, beve tequila, è single}

\text{nonAlist=non è svedese, non è scozzese, non è australiano, non è tedesca, non è cubana, non è giapponese }
\text{nonBlist=non gioca a tennis, non suona il violino, non fa surf, non suona il piano, non balla salsa, non fa Kendo}
\text{nonClist=non è biondo, non indossa una gonna, indossa una cravatta, è truccata, non è bruna, non indossa un kimono}
\text{nonDlist=non scia, non gioca a rugby, non passa le vacanze a Bali, non va in bicicletta, odia la matematica, non fa gli origami}
\text{nonElist=non è vegetariano, è single, non gli piace la birra,  non le piacciono i wurstel, non beve tequila, è sposata}

\text{\name_statement1=Per entrare in un circolo ricreativo }
\text{\name_statement2=maschile, ogni candidato è tenuto a}
\text{\name_statement3=femminile, ogni candidata è tenuta a}
\text{\name_statement4=soddisfare tutte le seguenti condizioni:}

lasciare le virgole in name_statlist1
\text{name_question1=Trova nel seguente elenco una proposizione \(A\), che dovrebbe essere}
\text{name_question2=allo stesso tempo vera e falsa}
\text{name_question3=, e questo}
\text{name_question4=in qualsiasi interpretazione}
\text{name_question5=dove i termini del regolamento sarebbero contemporaneamente veri.}
\text{name_question6=Ciò dimostra per assurdo che i termini del regolamento sono incompatibili.}
\text{\name_remark=Nota: devi, come Sherlock Holmes, sapere come considerare tutti i casi e tenere traccia di tutte le inferenze...}
\text{Contradiction=Contraddizione}
\text{\name_cases=Fai un'analisi dei casi}
\text{\name_case1=considera le interpretazioni secondo le quali i termini del regolamento sono tutti veri;}
\text{\name_case2=considera i diversi casi, e per ciascuno assegna i valori di verità alle diverse proposizioni elementari;}
\text{\name_case3=trova \(A) tale che in ogni interpretazione \(A) dovrebbe essere sia vera che falsa;}
\text{\name_casesend=Ciò dimostra per assurdo che non esiste un'interpretazione che renda contemporaneamente veri tutti i termini del regolamento.}

\text{Exemple=Esempio}
\text{name_example1=Supponiamo che le seguenti condizioni siano contemporaneamente vere:}
\text{name_example2=\(P_1) ci permette di distinguere due casi: o \(A) è vero o \(B) è vero.}
\text{name_example3=Se \(A) è vero, indipendentemente da \(B): per \(P_2) e \(P_4) deduciamo che C è necessariamente vero; di \(P_3) deduciamo allora che \(A) è falso.}
\text{name_example4=Se \(A) è falso e quindi \(B) è vero: per \(P_4) deduciamo che \(A) è vero.}
\text{name_example5=In ogni caso, \(A) dovrebbe essere sia vero che falso. Questo non ha senso. Non c'è quindi
nessuna interpretazione in cui \(P_1), \(P_2) e \(P_3) sono simultaneamente veri. Diciamo che \(P_1), \(P_2) e \(P_3) sono inconsistenti.}
#endif

#if defined TARGET_negationLN

\text{name_subjects=greco, greci, logico, logici, compiti di matematica, compiti di matematica, film, film, saggio, saggi, allievo, allievi, adulto, adulti}
\text{name_verbs=è un bugiardo, sono bugiardi, è pazzo, sono pazzi, è facile, sono facili, è divertente, sono divertenti, è vecchio, sono vecchi, è felice,
sono felici, è responsabile, sono responsabili}
\text{name_nonverbs=è schietto, aono schietti, è sano di mente, sono sani di mente, è difficile, sono difficili, è tragico, sono tragicu, è giovane, sono giovani,
è infelice, sono infelici, è irresponsabile, sono irresponsabili}
\text{name_adj=bugiardo, pazzo, facile, comico, vecchio, felice, responsabile}
\text{name_nonadj=franco, sano di mente, difficile, tragico, giovane, infelice, irresponsabile}

\text{name_Alist=
Sta piovendo,
Lei balla,
Lui suona la chitarra,
Sarà un ingegnere,
Faccio schifo in matematica,
Siamo tristi,
I pesci non volano}

\text{name_Blist=
fa freddo,
lei corre,
lui canta,
lavorerà all'estero,
sono bravo in italiano,
sfortunato,
le galline nuotano
}

\text{name_nonAlist=
Non sta piovendo,
Lei non balla,
Lui non suona la chitarra,
Non sarà un ingegnere,
Sono bravo in matematica,
Siamo felici,
Il pesci volano
}

\text{name_nonBlist=
fa caldo,
lei non corre,
lui non canta,
resterà in Italia,
faccio schifo in italiano,
felice,
le galline non nuotano
}

\text{Ilexiste=Esiste un}
\text{qui=che}
\text{Tous=Tutti i/gli}
\text{Aucun=Nessun}
\text{nest=è}
\text{Certains=Alcuni}

\text{name_statement1=Sia data la proposizione \(P\) seguente:}
\text{name_statement2=Qual è la negazione di \(P\)?}
\text{name_question=La negazione di \(P) è}
\text{name_remark1=La vostra risposta}
\text{name_remark2=non è la negazione di}
\text{name_remark3=&#32; al contrario è sinonimo}
#endif

#if defined TARGET_negationMath
#endif

#if defined TARGET_reciproque
#endif

#if defined TARGET_tautologie
#endif

#if defined TARGET_valeursVerite
#endif

#if defined TARGET_validite
#endif

