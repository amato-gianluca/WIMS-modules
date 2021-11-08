target=deduction

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
\integer{init= 10}
\text{monaide=wims(record 8 to  10 of glossaire)}
\help{\monaide}

\text{Alist =
il y a gr�ve de bus,
il pleut le matin,
il fait froid,
il y a du soleil,
je  mange beaucoup de g�teaux,
je suis joyeux,
je danse la salsa,
je veux progresser,
je veux am�liorer mon anglais,
je suis enrhum�(e)
}

\text{Blist =
j'arrive en retard au lyc�e,
je prends mon parapluie, 
je mets un pull,
je porte des lunettes noires,
je grossis,
je ris,
je n'�coute que Radio Latina,
je m'entra�ne sous WIMS ,
je  vois tous les films en VO,
ma voix est cass�e
}

\text{nonAlist= 
les bus ne sont pas gr�ve,
il ne pleut pas le matin,
il ne faisait pas froid,
il n'y a pas de soleil aujourd'hui,
j'ai mang� peu de g�teaux,
je suis triste,
je n'aime pas la salsa,
je ne veux pas progresser,
je ne veux pas am�liorer mon anglais,
je ne suis pas enrhum�(e)
}

\text{nonBlist=
je n'arrive pas en retard au lyc�e,
je ne prend pas mon  parapluie, 
je n'ai pas mis de pull,
je ne porte pas de lunettes noires,
je n'ai pas grossi,
je ne ris pas,
j'ai �cout� Fun Radio,
je ne me suis pas entra�n�(e) sous WIMS,
je regarde Lost In Translation en VF,
je parle normalement
}

\integer{a=random(1..\init)}

\text{A=item(\a,\Alist)}
\text{B=item(\a,\Blist)}
\text{nonA=item(\a,\nonAlist)}
\text{nonB=item(\a,\nonBlist)}

\text{AouB=\A ou \B}
\text{AetB=\A et \B}

\text{nonAouB=\nonA ou  \B}
\text{AounonB=\A ou  \nonB}
\text{nonAounonB=\nonA ou  \nonB}
\text{nonAetB=\nonA et  \B}
\text{AetnonB=\A et  \nonB}
\text{niAniB= \nonA et  \nonB}

\text{si=\a<4?S':Si}

\integer{casH=random(1..2)}
\integer{casC=random(1..6)}
\text{hyp=\A,\nonB}
\text{H=item(\casH,\hyp)}

/** liste d'assertions ; les  4 premi�res sont justes **/
\text{ass=\casH==1?
\B,\AetB,\AounonB,\nonAouB,\nonAounonB,\nonAetB,\AetnonB,\niAniB:
\nonA,\nonAounonB,\niAniB,\AounonB, \nonAetB,\AetnonB,\A,\AetB}

\text{C=item(\casC,\ass)}

\integer{rep=\casC<5?1:2}




#include "lang.inc"

\statement{

<div style="background-color:#FFFF66;">
<ul>
<li>
<p>On suppose que l'implication suivante est vraie : </p>
<center>
<font color= green><b> \(H_1) : " \si \A, alors \B "</b></font></center></p>
</li>
<li>
<p>Quelqu'un me rencontre et constate que :</p>
<center> <font color= blue><b> \(H_2) : " \H "</b> </font></center>
</li>
<li>
<p>Cette personne en d�duit que  : </p>
<center><font color= red><b> \(C) : "  \C "</b> </font></center> 
</li>
</ul>

<p>Son raisonnement  est-il valide  ?  \embed{reply1} </p> 
</div>}

\Alist
\answer{Raisonnement juste}{\rep;oui,non}{type=checkbox}
