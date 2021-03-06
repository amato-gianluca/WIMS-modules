target=lectgrantec

#include "header.inc"
#include "lang_titles.inc"


%% couleur des grilles
\text{gridcolor=lightblue}

%% Choix de 4 points dans le cadre
\integer{x0=random(-4..-2)}
\integer{x1=\x0+random(1..3)}
\integer{x2=\x1+random(1..3)}
\integer{x3=\x2+random(1..3)}
\integer{k=random(1,2)}
\if{\k=1}
{
\integer{y0=random(-5..0)}
\integer{y1=\y0}
\integer{y2=\y0}
\integer{y3=random(3..6)}
\text{rep0=\x0,\x1,\x2}
\text{rep1=\x3}
\text{type2=set}
\text{type1=set}
}
{
\integer{y0=random(-6..-3)}
\integer{y1=random(0..5)}
\integer{y2=\y1}
\integer{y3=\y1}
\text{rep0=\x0}
\text{rep1=\x1,\x2,\x3}
\text{type1=set}
\text{type2=set}
}

%% Polynome d'interpollation
\text{f0=\y0*(x-(\x1))*(x-(\x2))*(x-(\x3))/((\x0-(\x1))*(\x0-(\x2))*(\x0-(\x3)))}
\text{f1=\y1*(x-(\x0))*(x-(\x2))*(x-(\x3))/((\x1-(\x0))*(\x1-(\x2))*(\x1-(\x3)))}
\text{f2=\y2*(x-(\x1))*(x-(\x0))*(x-(\x3))/((\x2-(\x1))*(\x2-(\x0))*(\x2-(\x3)))}
\text{f3=\y3*(x-(\x1))*(x-(\x2))*(x-(\x0))/((\x3-(\x1))*(\x3-(\x2))*(\x3-(\x0)))}
\text{f= \f0 + (\f1) +(\f2)+ (\f3)}


%% cadre g�n�rique %%
\text{cadre=
xrange -5,7
yrange -6,6
gridfill 0,0,5,5,\gridcolor
linewidth 1
linewidth 2
  parallel -5,-6,-5,6,1,0,12,blue
  parallel -5,-6,7,-6,0,1,13,blue
linewidth 2
vline 0,0,black
hline 0,0,black
arrow 0,0,1,0,10,magenta
arrow 0,0,0,1,10,magenta
text red,0.7,-0.1,medium,i
text red,-0.2,0.7,medium,j
text black,-0.2,-0.1,medium,O
    linewidth 2
    plot red,\f
}
%% fin du cadre g�n�rique %%

%% enonc� de l'exo %%


#include "lang.inc"

\statement{
Dans le plan muni d'un rep�re orthonorm� \((O,i,j)\),
on a trac� la courbe repr�sentative d'une fonction \(f).

    <div class="wimscenter">\draw{400,400}{\cadre}</div>
<p>
Par lecture graphique d�terminer les ant�c�dents des r�els suivants.
</p>
Votre r�ponse :
<ul><li>
ant�c�dent(s) de \y0 : \embed{reply 1,3}
</li><li>
ant�c�dent(s) de \y3 : \embed{reply 2,3}
</li></ul>

<div class="wims_instruction">
S'il y a plusieurs ant�c�dents, les ranger par ordre croissant s�par�s par une virgule.
</div>
}
%% soumission de r�ponse %%
\answer{ant�c�dent de y0}{\rep0}{type=\type1}
\answer{ant�c�dent de y3}{\rep1}{type=\type2}
