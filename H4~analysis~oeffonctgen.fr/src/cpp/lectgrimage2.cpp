target=lectgrimage2

#include "header.inc"
#include "lang_titles.inc"


%% couleur des grilles
\text{gridcolor=lightblue}
\integer{xmin=-5}
\integer{xmax=7}
%% Choix de 4 points dans le cadre
\integer{x0=random(-4..-2)}
\integer{x1=\x0+random(1..3)}
\integer{x2=\x1+random(1..3)}
\integer{x3=\x2+random(1..3)}
\integer{k=random(1..4)}
%% debug integer{k=4}


\if{\k=4}
{
  %% k=4
  \integer{y0=random(0..5)}
  \integer{y1=\y0}
  \integer{y2=\y0-(\x2)+(\x1)}
%% sinusoide, droite sinusoide
\text{ft= (\y2 -(\y1))*(t-(\x2))/(\x2-(\x1))+(\y2)}
\rational{y3=evalue(\ft,t=\x3)}
\text{f0=\y0+sin((t-(\x0))*pi/(\x1-(\x0)))}
\text{f1=\y3+sin((t-(\x3))*pi/(\x0-(\x1)))}
\integer{yy=\y2}
\rational{y2=\y3}
\integer{y3=\yy}
\integer{kk=random(1,-1)}
\text{f0=\kk*(\f0)}
\text{f1=\kk*(\f1)}
\text{ft=\kk*(\ft)}
\integer{y0=\kk*(\y0)}
\integer{y3=\kk*(\y3)}
\integer{y1=\kk*(\y1)}
\integer{y2=\kk*(\y2)}
\integer{x4=\x3+(\x1)-(\x0)}
  \text{graph=
   trange \x0,\x1
   plot red,t,\f0
   trange \x1,\x3
   plot red,t,\ft
   trange \x3,\x4
   plot red,t,\f1}
    \text{rep0=2 \x0 \x1}
    \text{rep1=\x2}
    \text{type2=numeric}
    \text{type1=wlist}
\integer{xx=\x2}
\rational{x2=\x3}
\integer{x3=\xx}
}

\if{\k=3}
{
  %% k=3
  \integer{y0=random(-6..0)}
  \integer{y1=\y0+random(1..3)}
  \integer{y2=\y0}
  \integer{y3=random(3..5)}
%% Polynome d'interpollation
\text{f0=\y0*(t-(\x1))*(t-(\x2))/((\x0-(\x1))*(\x0-(\x2)))}
\text{f1=\y1*(t-(\x0))*(t-(\x2))/((\x1-(\x0))*(\x1-(\x2)))}
\text{f2=\y2*(t-(\x1))*(t-(\x0))/((\x2-(\x1))*(\x2-(\x0)))}
\text{f= \f0 + (\f1) +(\f2)}
\text{ft= (\y3 -(\y0))*(t-(\x2))/(\x3-(\x2))+(\y2)}
  \text{graph=
   trange \xmin,\x2
   plot red,t,\f
   trange \x2,\xmax
   plot red,t,\ft}
    \text{rep0=2 \x0 \x2}
    \text{rep1=\x3}
    \text{type2=numeric}
    \text{type1=wlist}
}
\if{\k=1}
{
%% k=1
    \integer{y0=random(-5..0)}
    \integer{y1=\y0}
    \integer{y2=\y0}
    \integer{y3=random(3..6)}
    \text{rep0=3 \x0 \x1 \x2}
    \text{rep1=\x3}
    \text{type2=numeric}
    \text{type1=wlist}
}
\if{\k=2}
{
%% k=2
    \integer{y0=random(-6..-3)}
    \integer{y1=random(0..5)}
    \integer{y2=\y1}
    \integer{y3=\y1}
    \text{rep0=\x0}
    \text{rep1=3 \x1 \x2 \x3}
    \text{type1=numeric}
    \text{type2=wlist}
}
\if{\k<3}
{
%% Polynome d'interpollation
\text{f0=\y0*(x-(\x1))*(x-(\x2))*(x-(\x3))/((\x0-(\x1))*(\x0-(\x2))*(\x0-(\x3)))}
\text{f1=\y1*(x-(\x0))*(x-(\x2))*(x-(\x3))/((\x1-(\x0))*(\x1-(\x2))*(\x1-(\x3)))}
\text{f2=\y2*(x-(\x1))*(x-(\x0))*(x-(\x3))/((\x2-(\x1))*(\x2-(\x0))*(\x2-(\x3)))}
\text{f3=\y3*(x-(\x1))*(x-(\x2))*(x-(\x0))/((\x3-(\x1))*(\x3-(\x2))*(\x3-(\x0)))}
\text{f= \f0 + (\f1) +(\f2)+ (\f3)}
  \text{graph=
   plot red,\f}

}


%% cadre générique %%
\text{cadre=
xrange \xmin,\xmax
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
\graph
}
%% fin du cadre générique %%

%% enoncé de l'exo %%



#include "lang.inc"

\statement{
<p>
Dans le plan muni d'un repère orthonormé \((O,i,j)\),
on a tracé la courbe représentative d'une fonction \(f).</p>

<div class="wimscenter"> \draw{400,400}{\cadre}</div>
<p>
Par lecture graphique déterminer les images des réels suivants.
</p>

Votre réponse :
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
%% soumission de réponse %%
\answer{image de x0}{\y0}{type=numeric}
\answer{image de x1}{\y1}{type=numeric}
\answer{image de x2}{\y2}{type=numeric}
\answer{image de x3}{\y3}{type=numeric}
