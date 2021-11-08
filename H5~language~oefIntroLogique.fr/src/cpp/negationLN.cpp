target=negationLN

#include "header.inc"
#include "lang_titles.inc"

\range{-10..10}
\text{monaide=wims(record 11  of glossaire)}
\help{\monaide}

\integer{a=random(1..4)}
\integer{cas=\a<3?1:2}
\integer{u=random(1..7)}

\text{sujets=\cas==2?grec,grecs,logicien,logiciens, devoir de maths,
devoirs de maths,film,films,sage,sages,élève,élèves,adulte,adultes}
\text{verbes=\cas==2?est menteur,sont menteurs,
est fou, sont fous, est facile, sont faciles, est comique, sont comiques,est âgé, sont âgés, est heureux,sont heureux,est responsable,sont responsables}

\text{nonverbes=\cas==2?est franc,sont francs,
est sain d'esprit, sont sains d'esprit, est difficile, sont difficiles, est tragique, sont tragiques, est jeune, sont jeunes, est malheureux, sont malheureux,est irresponsable,sont irresponsables}

\text{suj=\cas==2?item(2*\u-1, \sujets)}
\text{sujs=\cas==2?item(2*\u,\sujets)}
\text{verb=\cas==2?item(2*\u-1, \verbes)}
\text{verbs=\cas==2?item(2*\u, \verbes)}
\text{nonverb=\cas==2?item(2*\u-1, \nonverbes)}
\text{nonverbs=\cas==2?item(2*\u, \nonverbes)}
\text{adj=\cas==2?item(\u,menteur,fou,facile,comique, âgé, heureux,responsable)}
\text{nonadj=\cas==2?item(\u,franc,sain d'esprit,
difficile,tragique, jeune ,malheureux,irresponsable)}

\text{Alist=\cas==1?
Il pleut,
Elle danse,
Il joue de la guitare,
Elle sera ingénieur,
Je suis nul en maths,
On est triste,
Les poissons ne volent pas
}

\text{Blist= \cas==1?
il fait froid,
elle court,
il chante,
travaillera à l'étranger,
je suis fort en français,
malheureux,
les poules nagent
}

\text{nonAlist=\cas==1?
Il ne pleut pas,
Elle ne danse pas,
Il ne joue pas de la guitare,
Elle ne sera pas ingénieur,
Je suis fort en maths,
On est joyeux,
Les poissons volent
}

\text{nonBlist=\cas==1?
il fait chaud,
elle ne court pas,
il ne chante pas,
restera en France,
je suis nul en français,
heureux,
les poules ne nagent pas
}

\text{A=\cas==1?item(\u,\Alist)}
\text{B=\cas==1?item(\u,\Blist)}
\text{nonA=\cas==1?item(\u,\nonAlist)}
\text{nonB=\cas==1?item(\u,\nonBlist)}

\text{prop=item(\a,\A et \B,\A ou \B,Il existe un \suj qui \verb,
Tous les  \sujs \verbs )}

\text{neg=\a==1?\nonA ou \nonB}
\text{neg=\a==2?\nonA et \nonB}

\text{ass=\a==1?
\A ou \nonB,
\nonA ou \B,
\nonA et \nonB
}

\text{ass=\a==2?
\A et \nonB,
\nonA et \B,
\nonA ou \nonB
}

\text{neg=(\a==3)?randitem(Aucun \suj n'est \adj, Tous les \sujs \nonverbs)}

\text{ass=(\a==3)?
Tous les \sujs  \verbs,
Aucun \suj n'est \nonadj,
Il existe un \suj qui \nonverb,
Certains \sujs \verbs,
Certains \sujs \nonverbs
}

\text{neg=(\a==4)?randitem(Il existe un \suj qui \nonverb,
Certains \sujs \nonverbs)}

\text{ass=(\a==4)?
Certains \sujs \verbs,
Il existe un \suj qui \verb,
Aucun \suj n'est \adj,
Aucun \suj n'est \nonadj,
Tous les \sujs \nonverbs
}

\text{choix=shuffle(\ass)}



#include "lang.inc"

\statement{
<div style="background-color:#FFFF66;">

<p>On donne la proposition \(P) suivante :</p>
<center> <font color="blue"><b>\(P) : " \prop "</b></font></center>
<p>Quelle est  la négation de \(P) ?</p>
</div>
}

\choice{La négation de \(P) est}{\neg}{\choix}

\feedback{\a==4 and (\choice1 issametext Aucun \suj n'est\nonadj)}
{<b>Remarque</b>
Votre réponse "Aucun \suj n'est \nonadj" n'est pas la négation de
 "\prop" ; au contraire c'est un synonyme.  }
