target=lecttbantec

#include "header.inc"
#include "lang_titles.inc"

\css{<style>
table.tab_var {margin-left:auto;margin-right:auto;
   border:solid 1px black;}
table.tab_var tr, table.tab_var td, table.tab_var th {
   padding:7pt;margin-top:10px; margin-bottom:10px;
   text-align:center; border-collapse:collapse; min-width:10pt;
   }
table.tab_var th { border:solid 1px black}
table.tab_var tr { border:solid 1px black}
</style>
}

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
\integer{x=\x+randint(0..2)*10+randint(1..10)}
\text{listx=wims(append item \x to \listx)}
\integer{y=randint(-100..100)}
\text{listy=wims(append item \y to \listy)}
}

\text{listy2=\listy}
%% Choix des questions
\text{listind=shuffle(\nbpt)}
\text{rep1=\listx[\listind[1]]}
\text{rep2=\listx[\listind[2]]}
\text{rep3=\listx[\listind[3]]}
\text{rep4=\listx[\listind[4]]}

%% pour tester la compr�hension
\text{listy=wims(replace item number \listind[2] by \listx[\listind[5]] in \listy)}
\text{listy=wims(replace item number \listind[4] by \listx[\listind[7]] in \listy)}

%% on veut au moins une image avec 2 ant�c�dents
\integer{i=random(1..4)}
\integer{j=random(5..10)}
\text{listy=wims(replace item number \listind[\j] by \listy[\listind[\i]] in \listy)}

\text{q1=\listy[\listind[1]]}
\text{q2=\listy[\listind[2]]}
\text{q3=\listy[\listind[3]]}
\text{q4=\listy[\listind[4]]}
%% On teste la pr�sence de plusieurs ant�c�dents
\text{indrep1=wims(positionof item \q1 in \listy)}
\integer{nr=items(\indrep1)}
\if{\nr=1}
{
 \text{type1=numeric}
}
{
\text{type1=wlist}
\text{rep1=\nr}
\for{i=1 to \nr}
  {\text{rep1=\rep1 \listx[\indrep1[\i]]}}
}

\text{indrep2=wims(positionof item \q2 in \listy)}
\integer{nr=items(\indrep2)}
\if{\nr=1}
{
 \text{type2=numeric}
}
{
\text{type2=wlist}
\text{rep2=\nr}
\for{i=1 to \nr}
  {\text{rep2=\rep2 \listx[\indrep2[\i]]}}
}

\text{indrep3=wims(positionof item \q3 in \listy)}
\integer{nr=items(\indrep3)}
\if{\nr=1}
{
 \text{type3=numeric}
}
{
\text{type3=wlist}
\text{rep3=\nr}
\for{i=1 to \nr}
  {\text{rep3=\rep3 \listx[\indrep3[\i]]}}
}

\text{indrep4=wims(positionof item \q4 in \listy)}
\integer{nr=items(\indrep4)}
\if{\nr=1}
{
 \text{type4=numeric}
}
{
\text{type4=wlist}
\text{rep4=\nr}
\for{i=1 to \nr}
  {\text{rep4=\rep4 \listx[\indrep4[\i]]}}
}


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
<table class="wimscenter wimsborder tab_var">
<tr><th>\(x)</th>\lignex</tr>
<tr><th>\(f(x))</th>\ligney</tr>
</table>
<p>
Par lecture du tableau, d�terminer les ant�c�dents des r�els suivants:
</p>
Votre r�ponse :
<ul><li>
ant�c�dent(s) de \q1 : \embed{reply 1,8}
</li><li>
ant�c�dent(s) de \q2 : \embed{reply 2,8}
</li><li>
ant�c�dent(s) de \q3 : \embed{reply 3,8}
</li><li>
ant�c�dent(s) de \q4 : \embed{reply 4,8}
</li></ul>
<div class="wims_instruction">
S'il y a plusieurs ant�c�dents, les ranger par ordre croissant s�par�s par un espace.
</div>
}
%% soumission de r�ponse %%
\answer{ant�c�dent(s) de \q1}{\rep1}{type=\type1}
\answer{ant�c�dent(s) de \q2}{\rep2}{type=\type2}
\answer{ant�c�dent(s) de \q3}{\rep3}{type=\type3}
\answer{ant�c�dent(s) de \q4}{\rep4}{type=\type4}
