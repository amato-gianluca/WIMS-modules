target=tautologie

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
\range{-10..10}
\text{monaide=wims(record 6  of glossaire)}
\help{\monaide}

\text{Alist =
il y a grève de bus,
il pleut le matin,
il fait froid,
il y a du soleil,
il pleut,
je  mange beaucoup de gâteaux,
je suis joyeux,
j'écoute  Radio Latina,
je progresse en maths,
j'aime l'anglais,
je suis enrhumé(e),
elle danse,
tu joues de la guitare,
tu veux être ingénieur,
vous êtes nuls en maths,
on est triste,
les poissons ne volent pas,
le travail est motivant,
}

\text{Blist =
j'arrive en retard au lycée,
je prends mon parapluie, 
je mets un pull,
je porte des lunettes noires,
il fait froid,
je grossis,
je ris,
je  danse  la salsa,
je m'entraîne sous WIMS ,
je vois tous les films  en VO,
ma voix est cassée,
elle court,
tu chantes,
tu pars  à l'étranger,
vous êtes forts français,
on est amoureux,
les poules nagent,
la satisfaction est totale ,
}

\text{nonAlist= 
il n'y a pas grève de bus,
il ne pleut pas le matin,
il ne fait pas froid,
il n'y a pas de soleil ,
il ne pleut pas,
je mange peu de gâteaux,
je suis triste,
je n'écoute pas Radio Latina,
je ne progresse pas  en maths,
je n'aime pas l'anglais,
je ne suis pas enrhumé(e),
elle ne danse pas,
tu ne joues pas de la guitare,
tu ne veux pas être  ingénieur,
vous êtes forts en maths,
on est joyeux,
les poissons volent,
le travail n'est pas motivant
}

\text{nonBlist=
je suis arrivé(e) à l'heure au lycée,
je ne prends pas mon parapluie, 
je n'ai pas mis de pull,
je ne porte pas de lunettes noires,
il fait chaud,
je n'ai pas grossi,
je ne ris pas,
je ne danse pas la salsa,
je ne m'entraîne pas sous WIMS,
je ne vois aucun film en VO,
je parle normalement,
elle ne court pas,
tu ne chantes pas,
tu ne pars à l'étranger,
vous êtes nuls en français,
on n'est pas amoureux,
les poules ne nagent pas,
la satisfaction est partielle
}

\integer{a=random(1..18)}
\text{A=item(\a,\Alist)}
\text{nonA=item(\a,\nonAlist)}
\text{B=item(\a,\Blist)}
\text{nonB=item(\a,\nonBlist)}

\text{si=\a<6?s':si}

\text{tau=\si \A alors  \A,
\si \A alors  \A ou \B,
\si \A alors  si \B alors  \A,
\si \A et \si \B alors  \A,
\A ou \B ou (\nonA et \nonB),
\A ou \nonA,
\A ou \B ou \nonA,
\si \nonA alors  \A ou \nonA,
\si \nonA et \si \A  alors  \B,
\si \A et si \B  alors \A ou \B,
\si \A alors \B ou si \B alors \A,
\si \A alors \B ou si \nonA alors \B
}

/** les 12 premières  sont tautologiques , les 11 suivantes non **/
\text{ass=\tau,
\A ou \B, 
\A et \B, 
\si \A alors \B, 
\A et \nonA,
\si \A alors \nonA, 
\si \A alors \nonA ou \B,
\si \A alors \A et \B, 
\si \nonA alors \A ou  \B, 
\si \A ou si \B  alors \A et \B, 
\si \nonA ou \si \A  alors  \B,
\si \A alors \B et si \B alors \A
}

\text{typ=
\(A \rightarrow  A),
\(A \rightarrow   A \;ou\; B),
\(A \rightarrow  (B \rightarrow  A)),
\(A  \; et  \; B \rightarrow  A),
\(A  \; ou  \; B  \; ou \;  (\bar{A} \;et\; \bar{B})),
\(A  \; ou \;  \bar{A}),
\(A  \; ou \;  B \; ou \;  \bar{A}),
\(\bar{A} \rightarrow   A \;ou\; \bar{A}),
\(\bar{A}  \; et  \; A  \rightarrow  B),
\(A  \; et \;  B  \rightarrow  A \;ou\; B),
\(A \rightarrow  B \; ou \; B  \rightarrow A),
\(A \rightarrow  B \; ou \;  \bar{A}  \rightarrow B),
\(A  \; ou \;  B), 
\(A  \; et \;  B), 
\( A \rightarrow B), 
\(A \;et\;\bar{ A}),
\(A  \rightarrow \bar{ A}), 
\( A  \rightarrow \bar{ A} \;ou\; B),
\(A \rightarrow A \;et\; B), 
\(\bar{ A}  \rightarrow A \;ou\;  B), 
\(A \;ou\; B  \rightarrow A \;et\; B), 
\(\bar{ A} \;ou\; A \rightarrow  B),
\(A \rightarrow  B \; et \;B  \rightarrow A)
}

\integer{ind=random(1..23)}
\text{P=item(\ind,\ass)}
\text{typP=item(\ind,\typ)}
\text{shtyp=shuffle(\typ)}

\text{choix=item(1,\shtyp),item(2,\shtyp),item(3,\shtyp),
item(4,\shtyp),item(5,\shtyp)} 
\text{liste= 
(\typP isitemof \choix)?shuffle(\choix):shuffle(\typP,\choix)}

\integer{rep1=position(\typP,\liste)}
\integer{rep2=\ind<13?1:2}
\integer{test=(\typP isitemof \choix)?oui:non}



#include "lang.inc"

\statement{
<div style="background-color:#FFFF66;">

<p>Soient \(A) : " \A " et  \(B) : " \B ". </p>
<p>On considère la proposition \(P) suivante :</p>
<center><font color="blue"> \(P) : " \P "</font></center>
<p>Quelle formule logique correspond à \(P)  ?</p>
<center>\embed{reply1}</center> 
<p> \(P) est-elle une tautologie  ?  \embed{reply2}</p> 
</div>
}

\answer{Type formule}{\rep1;\liste}{type=checkbox}
\answer{Tautologie?}{\rep2;oui,non}{type=checkbox}
\hint{Une tautologie est une proposition logique toujours vraie (quelle que soient les valeurs de vérité de ses propositions élémentaires).}
