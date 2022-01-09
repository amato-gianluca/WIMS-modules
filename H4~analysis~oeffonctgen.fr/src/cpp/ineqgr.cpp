target=ineqgr

#include "header.inc"
#include "lang_titles.inc"

\keywords{equations,inequalities,intervals,roots}
%%%%%%%%%% AF : disparaitre les croix quand les bornes sont infinies%%%%%%%%%%
\keywords{function,graphing}
%% Choix des types de courbes %%%
\integer{k=random(1..3)}
%% couleur des grilles
\text{gridcolor=grey}
%% Choix de 4 points dans le cadre
\integer{x0=random(-4..-3)}
\integer{x1=\x0+random(1,2)}
\integer{x2=\x1+random(1,2)}
\integer{x3=\x2+random(1..3)}
\real{x4=(\x1+(\x2))/2}
\real{x5=(\x2+(\x3))/2}
\text{sgt=>}
\text{sge=\(\ge )}
\text{slt=<}
\text{sle=\(\le )}
%%%%%%%%%%% la liste des objets que l'on peut cliquer pour r�soudre l'exercice ###
\text{tx0=\(\x0)}
\text{tx1=\(\x1)}
\text{tx2=\(\x2)}
\text{tx3=\(\x3)}
\text{tx4=\(\x4)}
\text{tx5=\(\x5)}
\text{crocg=&#91;}
\text{crocd=&#93;}
\text{bracg=&#123;}
\text{bracd=&#125;}
\text{union=\(\cup)}
\text{inter=\(\cap)}
\text{infg=\(-\infty)}
\text{infd=\(+\infty)}
\text{empt=\(\emptyset)}
\text{ptvirg=&#59;}
\text{permut=shuffle(\x1,\x2,\x3,\x4,\x5,\x0)}
\text{clicList=
\crocg,\ptvirg,\crocd,\union,\inter,\infg,\infd,\empt,\bracg,\bracd,\permut[1],\permut[2],\permut[3],\permut[4],\permut[5],\permut[6]
}
%% taille des symboles et des champs � remplir par clic LxHxnb %%
\text{size=60x40x12}
%% choix de la question
\integer{casineq=random(1,2)}
%% 1: 1 ant�c�dent 2: 3 ant�c�dents
\integer{sensineq=random(1..2)}
\integer{strictineq=random(0..1)}
\text{crochg=\strictineq=0?\crocd:\crocg}
\text{crochd=\strictineq=0?\crocg:\crocd}
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
%% Polynome d'interpollation
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
%% Polynome d'interpollation
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
Bugs dans la partie ci-dessous "k=4" : il faudrait modifier l'ensemble de d�finition de la fonction (qui n'est plus R)
Il faudrait aussi ajouter des ronds rouges aux extr�mit�s de la courbe pour indiquer que ces points font bien partie de la courbe
(v�rifier que c'est bien ce qui est sous-entendu par l'�nonc�)
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
   plot red,t,\f1}
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
%%%%%%%%%%%%%%%%% r�ponse k=4 %%%%%%%%%%%%%%%%%%%%%
\text{goodrep=}
  \if{\k=4}{
 \if{\casineq=1}
 {
  \integer{val=\y0}
  \if{\kk=1}
  {\text{goodrep=\goodrep,\x0,\x1}
    \if{\sensineq=2}
      {
       \text{grep=\crochg,\x0,\ptvirg,\x1,\crochd}
       %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x0}
       \text{x12=\x1}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
       \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd,\union,\crochg,\x1,\ptvirg,\infd,\crocg}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x0}
       \text{x21=\x1}
       \text{x22=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
  }
  {\text{goodrep=\goodrep,\x0,\x1}
    \if{\sensineq=1}
      {
       \text{grep=\crochg,\x0,\ptvirg,\x1,\crochd}
       %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x0}
       \text{x12=\x1}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
       \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd,\union,\crochg,\x1,\ptvirg,\infd,\crocg}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x0}
       \text{x21=\x1}
       \text{x22=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
  }
 }
 {
  \integer{val=\y3}
  \if{\kk=1}
  {\text{goodrep=\goodrep,\x02}
    \if{\sensineq=2}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x2,\crochd}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x2}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
       \text{grep=\crochg,\x2,\ptvirg,\infd,\crocg}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x2}
       \text{x12=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
  }
  {\text{goodrep=\goodrep,\x02}
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x2,\crochd}
 %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x2}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
       \text{grep=\crochg,\x2,\ptvirg,\infd,\crocg}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x2}
       \text{x12=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
  }
 }
     \text{rep0=2 \x0 \x1}
    \text{rep1=\x2}
    \text{type2=numeric}
    \text{type1=wlist}
    }
%%%%%%% fin k=4 %%%%%%%%%%%%%%
%%%%%%% reponse k=3 %%%%%%%%%%%%%%
\if{\k=3}{
 \if{\casineq=1}
 {
  \integer{val=\y0}
   \if{\sensineq=1}
      {
      \if{\strictineq=0}
        {
         \text{grep=\crocd,\infg,\ptvirg,\x0,\crocg}
         \text{goodrep=\goodrep,\x0}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x0}
%%%%%%% fin pour solution affichage des segments %%%%%%%
        }
        {
         \text{grep=\crocd,\infg,\ptvirg,\x0,\crocd,\union,\bracg,\x2,\bracd}
                \text{goodrep=\goodrep,\x0,\x2}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x0}
       \text{crossol=\x2}
%%%%%%% fin pour solution affichage des segments %%%%%%%
        }
      }
      {
      \if{\strictineq=0}
        {
         \text{grep=\crocd,\x0,\ptvirg,\x2,\crocg,\union,\crocd,\x2,\ptvirg,\infd,\crocg}
         \text{goodrep=\goodrep,\x0,\x2}
         %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x0}
       \text{x12=\x2}
       \text{x21=\x2}
       \text{x22=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
        }
        {
         \text{grep=\crocg,\x0,\ptvirg,\infd,\crocg}
                \text{goodrep=\goodrep,\x0}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x0}
       \text{x12=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
        }
      }
 }
 {
  \integer{val=\y3}
  \text{goodrep=\goodrep,\x3}
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x3,\crochd}
       %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x3}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
       \text{grep=\crochg,\x3,\ptvirg,\infd,\crocg}
       %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x3}
       \text{x12=100}
      %%%%%%% fin pour solution affichage des segments %%%%%%%
      }
 }
    \text{rep0=2 \x0 \x2}
    \text{rep1=\x3}
    \text{type2=numeric}
    \text{type1=wlist}
}
%%%%%%%%%%% fin r�ponse k=3 %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% r�ponse k=1 %%%%%%%%
\if{\k=1}
{
 \if{\casineq=1}
 {\text{goodrep=\goodrep,\x0,\x1,\x2}
  \integer{val=\y0}
   \if{\sensineq=1}
      {
         \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd,\union,\crochg,\x1,\ptvirg,\x2,\crochd}
     %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x0}
       \text{x21=\x1}
       \text{x22=\x2}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
         \text{grep=\crochg,\x0,\ptvirg,\x1,\crochd,\union,\crochg,\x2,\ptvirg,\infd,\crocg}
         %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x0}
       \text{x12=\x1}
       \text{x21=\x2}
       \text{x22=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
 }
 { \text{goodrep=\goodrep,\x3}
  \integer{val=\y3}
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x3,\crochd}
       %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x3}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
       \text{grep=\crochg,\x3,\ptvirg,\infd,\crocg}
       %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x3}
       \text{x12=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
 }
    \text{rep0=3 \x0 \x1 \x2}
    \text{rep1=\x3}
    \text{type2=numeric}
    \text{type1=wlist}
}
%%%%%%%%%%% fin r�ponse k=1 %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% r�ponse k=2 %%%%%%%%
\if{\k=2}
{
 \if{\casineq=1}
 {\text{goodrep=\goodrep,\x1,\x2,\x3}
  \integer{val=\y3}
   \if{\sensineq=1}
      {
         \text{grep=\crocd,\infg,\ptvirg,\x1,\crochd,\union,\crochg,\x2,\ptvirg,\x3,\crochd}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x1}
       \text{x21=\x2}
       \text{x22=\x3}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
         \text{grep=\crochg,\x1,\ptvirg,\x2,\crochd,\union,\crochg,\x3,\ptvirg,\infd,\crocg}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x1}
       \text{x12=\x2}
       \text{x21=\x3}
       \text{x22=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
 }
 { \text{goodrep=\goodrep,\x0}
  \integer{val=\y0}
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd}
%%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=-100}
       \text{x12=\x0}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
      {
       \text{grep=\crochg,\x0,\ptvirg,\infd,\crocg}
       %%%%%%%%pour solution affichage des segments %%%%%%%
       \text{x11=\x0}
       \text{x12=100}
%%%%%%% fin pour solution affichage des segments %%%%%%%
      }
 }
    \text{rep0=\x0}
    \text{rep1=3 \x1 \x2 \x3}
    \text{type1=numeric}
    \text{type2=wlist}
}
%%%%%%%%%%% fin r�ponse k=2 %%%%%%%%
%% image solution %%%%
\text{colsol=blue}
\text{delt=0.4}
\real{val0=\val+\delt}
\text{delt2=\val>0?-\delt:\delt}
\text{grepsol=\grep[1] \grep[2] \grep[3] \grep[4] \grep[5] \grep[6]\grep[7]\grep[8]\grep[9]\grep[10]\grep[11]}
%%%%%%%%%%% test \x21 >-110 pour savoir si \x21 et \x22 existent %%%%%%%%%%%
\if{\x21!=}{
\text{pts=
crosshair \x11,\val,green
crosshair \x11,0,\colsol
crosshair \x12,\val,green
crosshair \x12,0,\colsol
crosshair \x21,\val,green
crosshair \x21,0,\colsol
crosshair \x22,\val,green
crosshair \x22,0,\colsol}}
{\text{pts=
crosshair \x11,0,\colsol
crosshair \x11,\val,green
crosshair \x12,0,\colsol
crosshair \x12,\val,green}}
\text{line=
linewidth 4
segment \x11,0,\x12,0,\colsol
segment \x21,0,\x22,0,\colsol
linewidth 3
dline \xmin,\val,\xmax,\val,\colsol
}
\text{imgsol0=draw(400,400
\img
\pts
\line
)}
\text{imgsol=<img src="\imgsol0" alt="repr�sentation graphique"/>}
%% fin image solution %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% pr�paration de la question
\text{symb=\slt,\sgt,\sle,\sge}
\integer{j=\sensineq+2*\strictineq}
\text{quest= \(f(x)) \symb[\j] \(\val)}
\text{enonce=R�soudre graphiquement l'in�quation : \quest.}
%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<p>Dans le plan muni d'un rep�re orthonorm� \((O,I,J)\),
on a trac� la courbe repr�sentative d'une fonction \(f) d�finie sur \ensdef.</p>
<div class=wimscenter>\imgstat</div>
<div class=wims_question>\enonce
<BR />Votre r�ponse :
<br />L'ensemble des solutions est S= \embed{reply1,\size}
</div>
}
%%%% soumission de r�ponse %%%%
\answer{}{\grep;\clicList}{type=clickfill}
%%%%%%%% solution %%%%%%%%%%%%%%%%%
\solution{
<div class=wimscenter>Il faut r�soudre graphiquement l'in�quation : \quest</div>
<ul>Codages :
<li>Les croix vertes sont les points de la courbe qui permettent de r�soudre.</li>
<li>Les segments bleus contiennent les nombres qui sont solutions de l'�quation \(f(x)=\val). </li>
<li>Les croix bleues sont les bornes de l'ensemble des solutions.</i>
</ul>
<p> La solution est : \grepsol</p>
<div class=wimscenter>\imgsol</div>
}
