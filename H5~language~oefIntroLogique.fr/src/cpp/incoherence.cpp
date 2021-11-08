target=incoherence

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
\range{-10..10}
\text{monaide=wims(record 8 to 10  of glossaire)}
\help{\monaide}

\text{Alist= il est suédois,il est écossais,il est australien,elle est allemande,elle est cubaine, elle est japonaise}
\text{Blist= il joue au tennis,
il joue du biniou, il surfe, elle joue du piano , elle danse la salsa,
elle fait du Kendo}
\text{Clist= il est blond,
il porte une jupe, il ne porte pas de cravate,  elle ne se maquille pas , elle est brune, elle  porte des kimonos}
\text{Dlist= il fait du ski,
il joue du rugby, il passe ses vacances à Bali, elle roule en vélo ,elle adore les maths, elle fait de l'origami}
\text{Elist= il est végétarien,
il est marié, il aime la bière, elle aime la Bratwurst , elle boit de la tequila, elle est célibataire
}


\text{nonAlist= il n'est pas suédois, il n'est pas écossais, il n'est pas australien, elle n'est pas allemande , elle n'est pas cubaine, elle n'est pas japonaise}
\text{nonBlist =il ne joue pas au tennis,
il ne joue pas du biniou , il ne  surfe pas , elle ne joue pas du piano , elle ne danse pas la salsa, elle ne fait pas Kendo}
\text{nonClist= il n'est pas blond,
il ne porte pas de jupe, il porte  une cravate, elle se maquille , elle n'est pas brune, elle ne porte pas de kimono }
\text{nonDlist= il ne fait pas de ski,
il ne joue pas du rugby, il ne passe pas ses vacances à Bali, elle ne roule pas en vélo , elle déteste les maths, elle ne fait pas de l'origami}
\text{nonElist=il n'est pas végétarien,
il est célibataire, il n'aime pas la bière, elle n'aime pas la Bratwurst, elle ne boit pas de tequila, elle est mariée}

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


/** reglement 3; contradiction sur B  et A ; A et B étant équivalent**/ 

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
Pour adhérer à un club de loisir \if{\a<4}{masculin, tout candidat est censé}{féminin, toute candidate est censée} remplir chacune des conditions suivantes :
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

<p> Cochez dans la liste suivante une proposition \(A), qui devrait être <b><font color="blue">à la fois vraie et fausse</font></b> et ce, <b><font color="blue">dans toute interprétation</font></b>  où les conditions du règlement seraient simultanément vraies. <br/>
Cela prouve par l'absurde que les conditions du règlement sont incompatibles.
 </p>
<center>\embed{reply1}</center> 
<p><i>Remarque :  vous devez, tel  Sherlock Holmes, savoir envisager tous les cas et pister toutes les déductions ...</i>
</p>
</div>
}

\answer{Contradiction}{\rep;\liste}{type=radio}
 

\hint{<font color="blue">
<p>
<b>Faire une analyse de cas</b> :
<ul> 
<li> considerez  les interprétations  dans laquelle 
les conditions du règlement soient toutes vraies ; </li>
<li> envisagez les différents cas, et pour chacun
 affectez les valeurs de vérité aux différentes propositions élémentaires ;</li>
<li> trouvez \(A) telle que, dans toute interprétation,   \(A) devrait être vraie et fausse à la fois ;</li>
</ul>
Ceci prouve par l'absurde qu'il n'existe aucune interprétation 
rendant simultanément vraies  toutes les conditions du règlement.
<p/>
<b>Exemple</b> : <br/>
Supposons que les conditions suivantes soient simultanément vraies  :
<center>\(P_1) : A ou B  &nbsp; ;&nbsp;
 \(P_2) : si A alors C ou B &nbsp; ;&nbsp;
\(P_3) :  si C  alors non A et B  &nbsp; ;&nbsp;
\(P_4) :  si B  alors  A et C   &nbsp; ;&nbsp;
</center>
\(P_1) donne à distinguer deux cas : ou bien \(A) est vrai ou bien \(B) est vrai. 
<ol>
<li> Si \(A) est vrai et \(B) quelconque :   par 
\(P_2) et \(P_4) on déduit que  C est nécessairement vrai ; par \(P_3) 
on déduit alors que \(A) est faux. </li>
<li>Si \(A) est faux et donc \(B) est vrai :  par \(P_4) on déduit que \(A) est vrai.
</li>
</ol> Dans tous les cas, \(A) devrait donc être à la fois vrai et faux. Ceci est  absurde.  Il n'existe donc  aucune interprétation dans laquelle \(P_1), \(P_2) et \(P_3) soient simultanément vraies.  On dit que \(P_1), \(P_2) et \(P_3) sont incompatibles.
</font>
}
