target=lecttbimage

#include "header.inc"
#include "lang_titles.inc"


%% couleur des grilles
\text{gridcolor=lightblue}

%% Choix de 10 points dans le cadre
\integer{nbpt=10}
\integer{xmin=-10}
\integer{xmax=10}
\integer{x=\xmin}
\text{listx=}
\text{listy=}
\for{i=1 to \nbpt}
{
\real{x=\x+randint(0..2)+randint(1..10)/10}
\text{listx=wims(append item \x to \listx)}
\real{y=randint(-100..100)/10}
\text{listy=wims(append item \y to \listy)}
}

\text{listy2=\listy}
%% Choix des questions
\text{listind=shuffle(\nbpt)}
\text{q1=\listx[\listind[1]]}
\text{q2=\listx[\listind[2]]}
\text{q3=\listx[\listind[3]]}
\text{q4=\listx[\listind[4]]}
\text{rep1=\listy[\listind[1]]}
\text{rep2=\listy[\listind[2]]}
\text{rep3=\listy[\listind[3]]}
\text{rep4=\listy[\listind[4]]}

%% pour tester la compr�hension
\text{listy=wims(replace item number \listind[5] by \q2 in \listy)}
\text{listy=wims(replace item number \listind[6] by \q4 in \listy)}
\text{listy=wims(replace item number \listind[7] by \q4 in \listy)}


\text{lignex=}
\for{i=1 to \nbpt}
{
\text{lignex=\lignex <td>\listx[\i]</td>}
}
\text{ligney=}
\for{i=1 to \nbpt}
{
\text{ligney=\ligney <td>\listy[\i]</td>}
}


%% enonc� de l'exo %%



#include "lang.inc"

\statement{
<p>
Une fonction \(f) est donn�e par son tableau de valeurs:
</p>
<table class="wimscenter wimsborder">
<tr>
<td>\(x)</td>\lignex
</tr>
<tr><td>\(f(x))</td>\ligney
</tr>
</table>
<p>
Par lecture du tableau, d�terminer les images des r�els suivants:
</p>
Votre r�ponse :
<ul><li>
image de \q1 : \embed{reply 1,3}
</li><li>
image de \q2 : \embed{reply 2,3}
</li><li>
image de \q3 : \embed{reply 3,3}
</li><li>
image de \q4 : \embed{reply 4,3}
</li></ul>
}
%% soumission de r�ponse %%
\answer{image de x0}{\rep1}{type=numeric}
\answer{image de x1}{\rep2}{type=numeric}
\answer{image de x2}{\rep3}{type=numeric}
\answer{image de x3}{\rep4}{type=numeric}
