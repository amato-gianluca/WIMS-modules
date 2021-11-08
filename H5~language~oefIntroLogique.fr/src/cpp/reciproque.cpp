target=reciproque

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
\integer{init= 10}

\text{elles=L�a,Lili,Julie,Leila,Lola}
\text{luis=L�o,Lulu,Jules,Malik,Luis}
\integer{i=random(1..4)}
\text{Elle=\elles[\i]}
\text{Lui=\luis[\i]}

\text{Alist= il est su�dois,il est �cossais,il est australien,elle est allemande,elle est cubaine, elle est japonaise}
\text{Blist= il joue au tennis,
il joue du biniou, il surfe, elle joue du piano , elle danse la salsa,
elle fait du Kendo}
\text{Clist= il est blond,
il porte une jupe, il ne porte pas de cravate,  elle ne se maquille pas , elle est brune, elle  porte des kimonos}
\text{Dlist= il a des enfants,
il sort le dimanche, il passe ses vacances � Bali, elle roule en v�lo ,elle adore les maths, elle fait de l'origami}
\text{Elist= il est v�g�tarien,
il est mari�, il aime la bi�re, elle aime la Bratwurst , elle boit de la tequila, elle est c�libataire
}


\text{nonAlist= il n'est pas su�dois, il n'est pas �cossais, il n'est pas australien, elle n'est pas allemande , elle n'est pas cubaine, elle n'est pas japonaise}
\text{nonBlist =il ne joue pas au tennis,
il ne joue pas du biniou , il ne  surfe pas , elle ne joue pas du piano , elle ne danse pas la salsa, elle ne fait pas Kendo}
\text{nonClist= il n'est pas blond,
il ne porte pas de jupe, il porte  une cravate, elle se maquille , elle n'est pas brune, elle ne porte pas de kimono }
\text{nonDlist= il n'a pas d'enfant,
il ne sort pas le dimanche, il ne passe pas ses vacances � Bali, elle ne roule pas en v�lo , elle d�teste les maths, elle ne fait pas de l'origami}
\text{nonElist=il n'est pas v�g�tarien,
il n'est pas mari�, il n'aime pas la bi�re, elle n'aime pas la Bratwurst, elle ne boit pas de tequila, elle est mari�e}

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


\text{ass=
\si \A alors \C,
\si \A ou \si \B alors \C,
\si \A et \si \B alors \D,
\si \A alors \C ou \D,
\si \B alors \C et \D,
\si \nonA ou \si \B alors \C,
\si \A et \si \nonB alors \D,
\si \A alors \nonC ou \D,
\si \B alors \C ou \nonD,
\si \A alors \C et \nonD,
\si \B alors \nonC et \D
}

\text{contra=
\si \nonC  alors  \nonA,
\si  \nonC alors  \nonA et \nonB,
\si  \nonD alors  \nonA ou \nonB,
\si  \nonC et \si \nonD  alors  \nonA,
\si \nonC ou \si \nonD  alors  \nonB,
\si  \nonC alors  \A et \nonB,
\si \nonD alors \nonA ou \B ,
 \si \C et \si \nonD alors \nonA ,
\si \nonC et \si \D alors \nonB,
\si  \nonC ou \si \D alors \nonA ,
\si \C ou \si \nonD alors  \nonB
}

\text{rec=
\si \C alors \A,
\si  \C alors \A ou \B,
\si \D alors \A et \B,
\si \C ou \si \D alors \A,
\si \C et \si \D alors \B,
\si \C alors \nonA ou \B ,
\si \D alors \A et \nonB ,
\si \nonC ou \si \D alors \A ,
\si \C ou \si \nonD alors \B,
\si  \C et \si  \nonD alors \A ,
\si \nonC et \si \D alors  \B 
}

\integer{rep=random(1..3)}
\integer{i=random(1..11)}

\text{prop1=item(\i,\ass)}

\integer{j=\i-1}
\integer{k=\i+1}
\text{autre=\rep==3 and \j==0?item(2..11,\rec),item(2..11,\contra)}
\text{autre=\rep==3 and \j>0?item(1..\j,\rec),item(\k..11,\contra)}



\text{prop2=\rep==1?item(\i,\rec)}
\text{prop2=\rep==2?item(\i,\contra)}
\text{prop2=\rep==3?randitem(\autre)}



#include "lang.inc"

\statement{
 <div style="background-color:#FFFF66;">

<ul><li><p>\Lui �nonce l'implication suivante  :</p> 
<center>
<font color= green> \(P_1) : " \prop1 "</font>
</center>

</li>
<li>
<p>Puis \Elle  �nonce la proposition \(P_2 ) :</p>
<center> 
<font color= blue>\(P_2) : " \prop2 "</font>
</center>

</li>
</ul>

<p>La proposition \(P_2)  formul�e par \Elle  
 \embed{reply1} de la proposition \(P_1) �nonc�e par \Lui.  </p> 

</div>
}


\answer{}{\rep;est la r�ciproque,est la contrapos�e,n'est ni la r�ciproque ni la contrapos�e}{type=menu}

\hint{
<ul>Consid�rons l'implication "si \(A) alors \(B)". Alors :
<li>
sa <b>r�ciproque</b> est la proposition "si \(B) alors \(A)" ;
</li> 
<li> 
sa <b>contrapos�e</b> est la proposition "si \(non B) alors \(non A)"
</li>
</ul>
La conjonction  "\(A) et \(B)" a pour n�gation "\( non A) ou  \(non B)".  <BR/>
La disjonction  "\(A) ou \(B)" a pour n�gation "\( non A) et \(non B)".  <BR/>

}
