target=connecteursLN

#include "header.inc"
#include "lang_titles.inc"

\language{fr}
\range{-10..10}
\text{monaide=wims(record 1 to 3 of glossaire)}
\help{\monaide}

\integer{n=random(1..17)}

\text{ou=\;ou\;}
\text{et=\;et\;}

\text{Alist =
il y a grève de bus,
il pleut ce matin,
il fait froid,
il y a du soleil,
il pleut,
je  mange beaucoup de gâteaux,
je suis joyeux,
j'écoute  Radio Latina,
je veux progresser en maths,
je veux perfectionner mon anglais,
je suis enrhumé(e),
elle danse,
tu joues de la guitare,
elle  ne veut pas devenir ingénieur,
vous êtes nuls en maths,
on est triste,
le travail est motivant
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
je ne vais voir que des films en VO,
ma voix est cassée,
elle court,
tu chantes,
elle veut partir à l'étranger,
vous êtes forts français,
on est amoureux,
la satisfaction est totale 
}

\text{nonAlist= 
il n'y a pas grève de bus,
il ne pleut pas ce matin,
il ne fait pas froid,
il n'y a pas de soleil ,
il ne pleut pas,
je mange peu de gâteaux,
je suis triste,
je n'écoute pas Radio Latina,
je ne veux pas progresser  en maths,
je ne veux pas améliorer mon anglais,
je ne suis pas enrhumé(e),
elle ne danse pas,
tu ne joues pas de la guitare,
elle  veut devenir ingénieur,
vous êtes forts en maths,
on est joyeux,
le travail n'est pas motivant
}

\text{nonBlist=
je n'arrive pas en retard  au lycée,
je ne prends pas mon parapluie, 
je n'ai pas mis de pull,
je ne porte pas de lunettes noires,
il fait chaud,
je ne grossis pas,
je ne ris pas,
je ne danse pas la salsa,
je ne m'entraîne pas  sous WIMS,
je regarde Lost In Translation en VF,
je parle normalement,
elle ne court pas,
tu ne chantes pas,
elle veut rester en France,
vous êtes nuls en français,
on n'est pas amoureux,
la satisfaction est partielle
}

\text{A=item(\n,\Alist)}
\text{nonA=item(\n,\nonAlist)}
\text{B=item(\n,\Blist)}
\text{nonB=item(\n,\nonBlist)}


\text{AouB=\A ou \B}
\text{nonAouB=\nonA ou  \B}
\text{AounonB=\A ou  \nonB}
\text{nonAounonB=\nonA ou  \nonB}
\text{AetB=\A et \B}
\text{nonAetB=\nonA et  \B}
\text{AetnonB=\A et  \nonB}
\text{niAniB= \nonA et  \nonB}

\text{si=\n<5?s':si}

\text{AimplB= randitem( \si \A alors  \B , \B \si \A)}
\text{nonAimplB= randitem(\si \nonA alors  \B, \B \si \nonA)}
\text{AimplnonB= randitem(\si \A alors  \nonB , \nonB \si \A) }
\text{nonAimplnonB= randitem(\si \nonA alors  \nonB, \nonB \si \nonA)}
\text{BimplA= randitem(si \B alors  \A, \A si \B)}
\text{nonBimplA= randitem(si \nonB alors  \A, \A si \nonB)}
\text{BimplnonA=randitem( si \B alors  \nonA, \nonA si \B)}
\text{nonBimplnonA= randitem(si \nonB alors  \nonA, \nonA si \nonB)}

\text{ind=shuffle(1,2,3,4,5,6,7,8,9,10,11,12)}


\text{ass=
\AetB,\nonAetB,\AetnonB,\niAniB,
\AouB,\AounonB,\nonAouB,\nonAounonB,
\AimplB,\nonAimplB,\AimplnonB,\nonAimplnonB,
\BimplA,\nonBimplA,\BimplnonA,\nonBimplnonA
}
\text{typ=
\(A \et B) ,\(\bar{A} \et B),\(A \et \bar{B}), \(\bar{A} \et \bar{B}),
\(A \ou B), \(A \ou \bar{B}),\(\bar{A} \ou  B),\(\bar{A} \ou \bar{B}),
\(A \rightarrow B),\(\bar{A}\rightarrow B),
\(A\rightarrow\bar{B}),\(\bar{A}\rightarrow\bar{B}),
\(B\rightarrow A),\(\bar{B}\rightarrow A),
\(B\rightarrow\bar{A}),\(\bar{B}\rightarrow\bar{A})
}

\text{list1=item(\ind[1],\ass),item(\ind[2],\ass),item(\ind[3],\ass),
item(\ind[4],\ass),item(\ind[5],\ass)} 

\text{list2=item(\ind[1],\typ),item(\ind[2],\typ),item(\ind[3],\typ),
item(\ind[4],\typ),item(\ind[5],\typ)} 



#include "lang.inc"

\statement{

<div style="background-color:#FFFF66;">

<p>Pour chacune des propositions  suivantes, à gauche, déterminer sa structure logique.</p>
<p><i>Remarque</i> : les propositions peuvent être vraies ou fausses ...</p>
<center>
<font color="blue"><b> \(A) : " \A "</b></font>
&nbsp; et &nbsp; <font color="green"><b>  \(B) : " \B "</b></font>
</center>


<p align="center"><i>
(Cliquer sur les élements qui se correspondent deux à deux.)</i></p>

</div>


<center>\embed{reply1,40x400x100}</center> 

}

\answer{\list1;\list2}{\list1;\list2}{type=correspond}{option=split}
