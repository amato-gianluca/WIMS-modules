target=lectgrimage

#include "header.inc"
#include "lang_titles.inc"


%% couleur des grilles
\text{gridcolor=lightblue}

%% Choix de 4 points dans le cadre
\integer{x0=random(-4..-2)}
\integer{x1=\x0+random(1..3)}
\integer{x2=\x1+random(1..3)}
\integer{x3=\x2+random(1..3)}
\integer{y0=random(-5..5)}
\integer{y1=random(-5..5)}
\integer{y2=random(-5..5)}
\integer{y3=random(-5..5)}

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
<p>
Dans le plan muni d'un rep�re orthonorm� \((O,i,j)\),
on a trac� la courbe repr�sentative d'une fonction \(f).</p>

<div class="wimscenter"> \draw{400,400}{\cadre}</div>
<p>
Par lecture graphique d�terminer les images des r�els suivants:
</p>

Votre r�ponse :
<ul><li>
image de \x0 : \embed{reply 1,3}
</li><li>
image de \x1 : \embed{reply 2,3}
</li><li>
image de \x2 : \embed{reply 3,3}
</li><li>
image de \x3 : \embed{reply 4,3}
</li></ul>
}
%% soumission de r�ponse %%
\answer{image de x0}{\y0}{type=numeric}
\answer{image de x1}{\y1}{type=numeric}
\answer{image de x2}{\y2}{type=numeric}
\answer{image de x3}{\y3}{type=numeric}
