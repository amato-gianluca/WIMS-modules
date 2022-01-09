target=lectgrimage2

#include "header.inc"
#include "lang_titles.inc"

%%%%%%%%%% AF : disparaitre les croix quand les bornes sont infinies%%%%%%%%%%
\keywords{function,graphing}
%% Choix des types de courbes %%%
\integer{k=random(1..4)}
%% couleur des grilles
\text{gridcolor=grey}
%% Choix de 4 points dans le cadre
\integer{x0=random(-4..-3)}
\integer{x1=\x0+random(1,2)}
\integer{x2=\x1+random(1,2)}
\integer{x3=\x2+random(1..3)}
%%%%%%%%%%%%%%%%%%%%%%%% diff�rentes fonctions %%%%%%%%%%%%%%%%%%
\if{\k=1}
{
\integer{y0=random(-5..0)}
\integer{y1=\y0}
\integer{y2=\y0}
\integer{y3=random(3..5)}
\text{rep0=\x0,\x1,\x2}
\text{rep1=\x3}
}
\if{\k=2}{
\integer{y0=random(-5..-3)}
\integer{y1=random(0..5)}
\integer{y2=\y1}
\integer{y3=\y1}
\text{rep0=\x0}
\text{rep1=\x1,\x2,\x3}
}
\if{\k=3}
{ \integer{y0=randint(-5..0)}
  \integer{y1=\y0+randint(1..3)}
  \integer{y2=\y0}
  \integer{y3=random(4..5)}
  \text{rep0=\x0,\x2}
  \text{rep1=\x3}
}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\if{\k<3}{
%% Polynome d'interpolation
\text{f0=\y0*(x-(\x1))*(x-(\x2))*(x-(\x3))/((\x0-(\x1))*(\x0-(\x2))*(\x0-(\x3)))}
\text{f1=\y1*(x-(\x0))*(x-(\x2))*(x-(\x3))/((\x1-(\x0))*(\x1-(\x2))*(\x1-(\x3)))}
\text{f2=\y2*(x-(\x1))*(x-(\x0))*(x-(\x3))/((\x2-(\x1))*(\x2-(\x0))*(\x2-(\x3)))}
\text{f3=\y3*(x-(\x1))*(x-(\x2))*(x-(\x0))/((\x3-(\x1))*(\x3-(\x2))*(\x3-(\x0)))}
\text{f= \f0 + (\f1) +(\f2)+ (\f3)}
\text{graph=plot red,\f}
\text{ensdef=\(\mathbb{R})}
}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\if{\k=3}
{
%% Polynome d'interpolation
\text{f0=\y0*(t-(\x1))*(t-(\x2))/((\x0-(\x1))*(\x0-(\x2)))}
\text{f1=\y1*(t-(\x0))*(t-(\x2))/((\x1-(\x0))*(\x1-(\x2)))}
\text{f2=\y2*(t-(\x1))*(t-(\x0))/((\x2-(\x1))*(\x2-(\x0)))}
\text{f= \f0 + (\f1) +(\f2)}
\text{ft= (\y3 -(\y0))*(t-(\x2))/(\x3-(\x2))+(\y2)}
\text{graph=
   trange -5,\x2
   plot red,t,\f
   trange \x2,7
   plot red,t,\ft}
\text{ensdef=\(\mathbb{R})}
   }
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\if{\k=4}
{
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
\integer{x4=\x3+(\x1)-(\x0)}
  \text{graph=
   trange \x0,\x1
   plot red,t,\f0
   trange \x1,\x3
   plot red,t,\ft
   trange \x3,\x4
   plot red,t,\f1
   circle \x0,\y0,6,red
   circle \x4,\kk*\y2,6,red}
   \text{ensdef=l'intervalle \(\left[ \x0 ; \x4 \right])}
\text{rep0=\x0,\x1}
\text{rep1=\x2}
}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% cadre image g�n�rique %%
\integer{xmin=-5}
\integer{xmax=7}
\text{img=
xrange \xmin,\xmax
yrange -6,6
linewidth 1
linewidth 2
  parallel -5,-6,-5,6,1,0,12,grey
  parallel -5,-6,7,-6,0,1,13,grey
linewidth 2
vline 0,0,black
hline 0,0,black
line -0.2,1,0.2,1,black
line 1,-0.2,1,0.2,black
text black,0.7,-0.1,medium,I
text black,-0.4,1,medium,J
text black,-0.3,-0.1,medium,O
parallel -4,0.2,-4,-0.2,8,0,2,black
text black,-4.1,0.6,medium,-4
text black,3.9,0.6,medium,4
parallel -0.2,-4,0.2,-4,0,8,2,black
text black,0.4,-4,medium,-4
text black,0.4,4,medium,4
    linewidth 2
   \graph
}
%% fin du cadre g�n�rique %%
%% image statement %%%%
\text{imgstat0=draw(400,400
\img
)}
\text{imgstat=<img src="\imgstat0" alt="repr�sentation graphique"/>}
%% choix de la question/r�ponse
\integer{choixq=random(1,2)}
\integer{val=\choixq=1?\y0:\y3}
\text{goodrep=\choixq=1?\rep0:\rep1}
\text{quest=randomitem(\goodrep)}
%% image solution %%%%
\text{colsol=blue}
\text{delt=0.4}
\real{val0=\val+\delt}
\text{delt2=\val>0?-\delt:\delt}
\text{pts=
crosshair \quest,0,black
crosshair \quest,\val,\colsol
crosshair 0,\val,green
darrow \quest,\val,0,\val,10,green
dvline \quest,0,\colsol
text \colsol,\quest,\delt2,medium,\quest
text green,\delt,\val0,medium,\val}
\text{imgsol0=draw(400,400
\img
\pts
\line
)}
\text{imgsol=<img src="\imgsol0" alt="repr�sentation graphique"/>}
%% fin image solution %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\text{enonce=D�terminez graphiquement l'image de \(\quest) par la fonction \(f)}
%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<p>Dans le plan muni d'un rep�re orthonorm� \((O,I,J)\),
on a trac� la courbe repr�sentative d'une fonction \(f) d�finie sur \ensdef.</p>
<div class=wimscenter>\imgstat</div>
<div class=wims_question>\enonce
<br />L'image de \(\quest) est �gale � : \embed{reply 1,3}</div>
\instruction
}
%%%% soumission de r�ponse %%%%
\answer{solution}{\val}{type=integer}
%%%%%%%% solution %%%%%%%%%%%%%%%%%
\solution{L'image de \(\quest) est �gale � \(\val)
<div class=wimscenter>\imgsol</div>
Par �tape :
<ul><li>On trace la droite d'�quation \(x=\quest) <font color=blue>(en bleue sur le graphique)</font>.</li>
<li>Puis on rep�re le point d'intersection avec la courbe <font color=blue>(croix bleue)</font></li>
<li>Enfin, on regarde l'ordonn�e de ce point <font color=green>( Tirets verts)</font>.</li>
</ul>}
