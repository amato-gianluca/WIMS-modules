target=validite

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
\range{-10..10}
\text{monaide=wims(record 4 to 5  of glossaire)}
\help{\monaide}

\text{Alist= il est su�dois,il est �cossais,il est australien,elle est allemande,elle est cubaine, elle est japonaise}
\text{Blist= il joue au tennis,
il joue du biniou, il surfe, elle joue du piano , elle danse la salsa,
elle fait du Kendo}
\text{Clist= il est blond,
il porte une jupe, il ne porte pas de cravate,  elle ne se maquille pas , elle est brune, elle  porte des kimonos}
\text{Dlist= il fait du ski,
il fait du rugby, il passe ses vacances � Bali, elle roule en v�lo ,elle adore les maths, elle apprend l'ikebana}



\text{nonAlist= il n'est pas su�dois, il n'est pas �cossais, il n'est pas australien, elle n'est pas allemande , elle n'est pas cubaine, elle n'est pas japonaise}
\text{nonBlist =il ne joue pas au tennis,
il ne joue pas du biniou , il ne  surfe pas , elle ne joue pas du piano , elle ne danse pas la salsa, elle ne fait pas Kendo}
\text{nonClist= il n'est pas blond,
il ne porte pas de jupe, il porte des cravates, elle se maquille , elle n'est pas brune, elle ne porte pas de kimono }
\text{nonDlist= il ne fait pas de ski,
il ne fait pas de rugby, il ne passe pas ses vacances � Bali, elle ne roule pas en v�lo , elle d�teste les maths, elle n'apprend pas l'ikebana}

\integer{a=random(1..6)}

\text{A=\Alist[\a]}
\text{B=\Blist[\a]}
\text{C=\Clist[\a]}
\text{D=\Dlist[\a]}

\text{nonA=\nonAlist[\a]}
\text{nonB=\nonBlist[\a]}
\text{nonC=\nonClist[\a]}
\text{nonD=\nonDlist[\a]}

\text{val=randint(0,1),randint(0,1),randint(0,1),randint(0,1)}

\text{si=\a<4?s':si}

\text{liste=oui,1,2,3,4,5,6}

\text{elles=L�a,Lili,Julie,Leila,Lola}
\text{luis=L�o,Lulu,Jules,Malik,Luis}
\integer{i=random(1..4)}
\text{Elle=\elles[\i]}
\text{Lui=\luis[\i]}

\text{mrx=\a<4?\Lui:\Elle}

/** reglement compatible **/ 
/**  un  mod�le : Av Bv Cv Dv Ef **/

\text{reg=
\A ou \B,
\C ou \D,
\si \A et \si \B alors \D, 
\si \B et \si \nonC alors \D,
 \si \C et \si \nonA alors \nonD ,
\si \B ou \si \D  alors   \A,
\A si et seulement \si \D,
\A et \B,
\C et \nonD
}

\text{ind=shuffle(1,2,3,4,5,6,7,8,9)}
\integer{i1=\ind[1]}
\integer{i2=\ind[2]}
\integer{i3=\ind[3]}
\integer{i4=\ind[4]}

\integer{cond1=\val[1]==1 or \val[2]==1?1:2}

\integer{cond2=\val[3]==1 or \val[4]==1?1:2}

\integer{cond3=(\val[1]==0 or \val[2]==0 or \val[4]==1)?1:2}

\integer{cond4=(\val[3]==1 or \val[2]==0 or \val[4]==1)?1:2}

\integer{cond5=(\val[3]==0 or \val[1]==1 or \val[4]==0)?1:2}

\integer{cond6=(\val[2]==0 and \val[4]==0) or \val[1]==1?1:2}

\integer{cond7=(\val[1]==\val[4])?1:2}

\integer{cond8=\val[1]==1 and \val[2]==1?1:2}

\integer{cond9=\val[3]==1 and \val[4]==0?1:2}


\text{conditions=\cond1,\cond2,\cond3,\cond4,\cond5,\cond6,\cond7,\cond8,\cond9}
\integer{rep1=\conditions[\i1]}
\integer{rep2=\conditions[\i2]}
\integer{rep3=\conditions[\i3]}
\integer{rep4=\conditions[\i4]}



#include "lang.inc"

\statement{

<div style="background-color:#FFFF66;">

<p>\mrx  poss�de les  caract�ristiques suivantes :  
<ul>
<li>\if{\val[1]==1}{\A}{\nonA}</li>
<li>\if{\val[2]==1}{\B}{\nonB}</li>
<li>\if{\val[3]==1}{\C}{\nonC}</li>
<li>\if{\val[4]==1}{\D}{\nonD}</li>
</ul>
</p> 

<p>
Pour adh�rer �  un club de loisir \if{\a<4}{masculin}{f�minin},  \mrx  devrait remplir toutes les conditions ci-dessous.
 <br/>
Pour chacune d'entre elles, indiquez si  \mrx la v�rifie ou pas :
</p>
<table width="75%" align="center" cellpadding=5>
<tr>
<td width="5%">1.</td>
<td width="75%">\reg[\i1]</td>
<td width="20%">\embed{reply1}</td>
</tr>
<tr>
<td width="5%">2.</td>
<td width="75%">\reg[\i2]</td>
<td width="20%">\embed{reply2}</td>
</tr>
<tr>
<td width="5%">3.</td>
<td width="75%">\reg[\i3]</td>
<td width="20%">\embed{reply3}</td>
</tr>
<tr>
<td width="5%">4.</td>
<td width="75%">\reg[\i4]</td>
<td width="20%">\embed{reply4}</td>
</tr>
</table>

</div>
}
\answer{clause 1}{\rep1;vrai,faux}{type=radio}
\answer{clause 2}{\rep2;vrai,faux}{type=radio}
\answer{clause 3}{\rep3;vrai,faux}{type=radio}
\answer{clause 4}{\rep4;vrai,faux}{type=radio}

\hint{Il s'agit de calculer les valeurs de v�rit� des assertions (formules) propos�es, connaissant les valeurs de v�rit�
des propositions �l�mentaires. <br/> Pour tout rappel sur le calcul des 
valeurs de v�rit�, voir l'aide ou l'exercice "Tables de v�rit�".}
