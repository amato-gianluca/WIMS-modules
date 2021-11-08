target=incoherence

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
\range{-10..10}
\text{monaide=wims(record 8 to 10  of glossaire)}
\help{\monaide}

\text{Alist= il est su�dois,il est �cossais,il est australien,elle est allemande,elle est cubaine, elle est japonaise}
\text{Blist= il joue au tennis,
il joue du biniou, il surfe, elle joue du piano , elle danse la salsa,
elle fait du Kendo}
\text{Clist= il est blond,
il porte une jupe, il ne porte pas de cravate,  elle ne se maquille pas , elle est brune, elle  porte des kimonos}
\text{Dlist= il fait du ski,
il joue du rugby, il passe ses vacances � Bali, elle roule en v�lo ,elle adore les maths, elle fait de l'origami}
\text{Elist= il est v�g�tarien,
il est mari�, il aime la bi�re, elle aime la Bratwurst , elle boit de la tequila, elle est c�libataire
}


\text{nonAlist= il n'est pas su�dois, il n'est pas �cossais, il n'est pas australien, elle n'est pas allemande , elle n'est pas cubaine, elle n'est pas japonaise}
\text{nonBlist =il ne joue pas au tennis,
il ne joue pas du biniou , il ne  surfe pas , elle ne joue pas du piano , elle ne danse pas la salsa, elle ne fait pas Kendo}
\text{nonClist= il n'est pas blond,
il ne porte pas de jupe, il porte  une cravate, elle se maquille , elle n'est pas brune, elle ne porte pas de kimono }
\text{nonDlist= il ne fait pas de ski,
il ne joue pas du rugby, il ne passe pas ses vacances � Bali, elle ne roule pas en v�lo , elle d�teste les maths, elle ne fait pas de l'origami}
\text{nonElist=il n'est pas v�g�tarien,
il est c�libataire, il n'aime pas la bi�re, elle n'aime pas la Bratwurst, elle ne boit pas de tequila, elle est mari�e}

\integer{a=random(1..6)}
\integer{cas=random(1..3)}

\text{A=\Alist[\a]}
\text{B=\Blist[\a]}
\text{C=\Clist[\a]}
\text{D=\Dlist[\a]}
\text{E=\Elist[\a]}

\text{nonA=\nonAlist[\a]}
\text{nonB=\nonBlist[\a]}
\text{nonC=\nonClist[\a]}
\text{nonD=\nonDlist[\a]}
\text{nonE=\nonElist[\a]}

\text{si=\a<4?s':si}



\text{liste=shuffle(\A,\B,\C,\D,\E)}

/** reglement 1; contradiction sur A et D  **/ 

\text{reg=\cas==1?shuffle(
\si \B alors \A, 
\C ou \B , 
\si \E alors \nonD ,
\D si et seulement \si \A , 
\si \C alors \A et \E , 
\si \A alors \C)
}

\text{rep=\cas==1?position(\A,\liste),position(\D,\liste)}

/** reglement 2; contradiction sur A  **/ 

\text{reg=\cas==2?shuffle(
\A ou \B,  
\si \B ou \si \C alors  \A ,
\si \A et \si \nonB alors \D,
 \si \D  ou  \si \nonC alors \nonA ,
\si \B alors \nonC)
}

\text{rep=\cas==2?position(\A,\liste)}


/** reglement 3; contradiction sur B  et A ; A et B �tant �quivalent**/ 

\text{reg=\cas==3?shuffle(
\A ou \B,  \D ou \C, 
\si \A et \si \D alors  \B ,
\si \A et \si \C alors  \B ,
\si \D et \si \C alors  \nonB ,
\si \B et \si \nonD alors \nonA,
\si \B et \si \nonC alors \nonA,
\si \nonA alors \nonB)
}

\text{rep=\cas==3?position(\B,\liste),position(\A,\liste)}




#include "lang.inc"

\statement{
<div style="background-color:#FFFF66;">

<p> 
Pour adh�rer � un club de loisir \if{\a<4}{masculin, tout candidat est cens�}{f�minin, toute candidate est cens�e} remplir chacune des conditions suivantes :
</p>
<ol>
<li>\reg[1]</li>
<li>\reg[2]</li>
<li>\reg[3]</li>
<li>\reg[4]</li>
<li>\reg[5]</li>
\if{\cas!=2}{<li>\reg[6]</li>}
\if{\cas==3}{<li>\reg[7]</li>}
\if{\cas==3}{<li>\reg[8]</li>}
</ol>

<p> Cochez dans la liste suivante une proposition \(A), qui devrait �tre <b><font color="blue">� la fois vraie et fausse</font></b> et ce, <b><font color="blue">dans toute interpr�tation</font></b>  o� les conditions du r�glement seraient simultan�ment vraies. <br/>
Cela prouve par l'absurde que les conditions du r�glement sont incompatibles.
 </p>
<center>\embed{reply1}</center> 
<p><i>Remarque :  vous devez, tel  Sherlock Holmes, savoir envisager tous les cas et pister toutes les d�ductions ...</i>
</p>
</div>
}

\answer{Contradiction}{\rep;\liste}{type=radio}
 

\hint{<font color="blue">
<p>
<b>Faire une analyse de cas</b> :
<ul> 
<li> considerez  les interpr�tations  dans laquelle 
les conditions du r�glement soient toutes vraies ; </li>
<li> envisagez les diff�rents cas, et pour chacun
 affectez les valeurs de v�rit� aux diff�rentes propositions �l�mentaires ;</li>
<li> trouvez \(A) telle que, dans toute interpr�tation,   \(A) devrait �tre vraie et fausse � la fois ;</li>
</ul>
Ceci prouve par l'absurde qu'il n'existe aucune interpr�tation 
rendant simultan�ment vraies  toutes les conditions du r�glement.
<p/>
<b>Exemple</b> : <br/>
Supposons que les conditions suivantes soient simultan�ment vraies  :
<center>\(P_1) : A ou B  &nbsp; ;&nbsp;
 \(P_2) : si A alors C ou B &nbsp; ;&nbsp;
\(P_3) :  si C  alors non A et B  &nbsp; ;&nbsp;
\(P_4) :  si B  alors  A et C   &nbsp; ;&nbsp;
</center>
\(P_1) donne � distinguer deux cas : ou bien \(A) est vrai ou bien \(B) est vrai. 
<ol>
<li> Si \(A) est vrai et \(B) quelconque :   par 
\(P_2) et \(P_4) on d�duit que  C est n�cessairement vrai ; par \(P_3) 
on d�duit alors que \(A) est faux. </li>
<li>Si \(A) est faux et donc \(B) est vrai :  par \(P_4) on d�duit que \(A) est vrai.
</li>
</ol> Dans tous les cas, \(A) devrait donc �tre � la fois vrai et faux. Ceci est  absurde.  Il n'existe donc  aucune interpr�tation dans laquelle \(P_1), \(P_2) et \(P_3) soient simultan�ment vraies.  On dit que \(P_1), \(P_2) et \(P_3) sont incompatibles.
</font>
}
