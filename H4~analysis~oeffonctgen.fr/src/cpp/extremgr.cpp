target=extremgr

#include "header.inc"
#include "lang_titles.inc"

\keywords{function,graphing,intervals,bound}


\integer{xmin=-10}
\integer{xmax=10}
\integer{ymin=-10}
\integer{ymax=10}


\matrix{symb = \(\searrow),\(\nearrow),\(\searrow)
\(\nearrow),\(\searrow),\(\nearrow)}
\text{variations = \(\nearrow),\(\searrow)}
\text{monotone = \(\nearrow),\(\searrow)}

%% choix du sens de variation
\integer{cas=random(1,2)}
\integer{cas2=random(1..4)}

%% cas pour d�terminer sens de variation
%% cas 2 pour d�terminer si borne infinie ou pas
%% cas2=1 +inf, =2 -inf =3 ou 4 born�e

\integer{i1=\cas=1?1:2}
\integer{i2=\cas=1?2:1}
\text{c_f=\cas=1?1,2,1:2,1,2}
\text{monotone=\symb[\cas;]}

%% choix des valeurs de x
\integer{x1=random(-9..-5)}
\integer{x2=\x1+random(3..5)}
\integer{x3=\x2+random(3..5)}
\integer{x4=\x3+random(3..5)}
\text{xl=\x1,\x2,\x3,\x4}


%% choix des valeurs de f(x)
\integer{y1=random(-3..3)}
\if{\cas=1}
 {
 \integer{y2=\y1-random(2..6)}
 \integer{y3=\y2+random(2..7)}
 \integer{y3=\y3=\y1?\y3+1}
 \integer{y4=\y3-random(2..5)}
 \integer{y4=\y4=\y1?\y4-1}
 \integer{y4=\y4=\y2?\y4-1}
 \integer{y4=\y4<\ymin?\ymin}
 }
 {
 \integer{y2=\y1+random(2..6)}
 \integer{y3=\y2-random(2..7)}
 \integer{y3=\y3=\y1?\y3-1}
 \integer{y4=\y3+random(2..5)}
 \integer{y4=\y4=\y1?\y4+1}
 \integer{y4=\y4=\y2?\y4+1}
 \integer{y4=\y4>\ymax?\ymax}
 }
\text{yl=\y1,\y2,\y3,\y4}
\text{indl=shuffle(4)}
%% on choisit la question image de \xl[\indl[1]]
%% et on veut tester la compr�hension
%% on veut \yl[indl[2]]=\xl[\indl[1]]
%%integer{rep1=\yl[\indl[1]]}
%%integer{offset=\xl[\indl[1]]-\yl[\indl[2]]}
%%integer{y1=\y1+\offset}
%%integer{y2=\y2+\offset}
%%integer{y3=\y3+\offset}
%%integer{y4=\y4+\offset}
%%integer{rep1=\rep1+\offset}

\if{\cas=1}
 {
     \text{pos=top,bottom,top,bottom}
  \if{\cas2=1}
   {
     \text{d1=\(+\infty)}
      \text{x1=-11}
     \integer{y1=4*\ymax}
      \text{crog=&#93;}
   }
   {
     \text{d1=\y1}
      \text{crog=&#91;}
   }
 \text{d2=\y2}
 \text{d3=\y3}
 \if{\cas2=2}
  {
    \text{d4=\(+\infty)}
   \text{x4=11}
 \integer{y4=4*\ymin}
  }
  {
    \text{d4=\y4}
  }
 }
 {
     \text{pos=bottom,top,bottom,top}
  \if{\cas2=1}
   {
     \text{d1=\(-\infty)}
      \text{x1=-11}
     \integer{y1=2*\ymin}
   }
   {
     \text{d1=\y1}
   }
 \text{d3=\y3}
 \text{d2=\y2}
  \if{\cas2=2}
   {
     \text{d4=\(+\infty)}
\text{x4=11}
     \integer{y4=2*\ymax}
   }
   {
     \text{d4=\y4}
   }
 }
\if{\cas2=1}{\text{crog=&#93;}}{\text{crog=&#91;}}
\if{\cas2=2}{\text{crod=&#91;}}{\text{crod=&#93;}}

%% la liste des objets que l'on peut cliquer pour r�soudre l'exercice %%
\text{vx1=(\cas2=1)? \(-\infty):\(\x1)}
\text{vx2=\(\x2)}
\text{vx3=\(\x3)}
\text{vx4=(\cas2=2)? \(+\infty):\(\x4)}
\text{vy1=\(\y1)}
\text{vy2=\(\y2)}
\text{vy3=\(\y3)}
\text{vy4=\(\y4)}
\text{vesp=&nbsp;}
\text{infg=\(-\infty)}
\text{infd=\(+\infty)}
\text{ptvirg=&#59;}

%% Pr�paration des r�ponses
\text{choixrepM= oui, non } %% major�e
\text{choixrepm= oui, non } %% minor�e
\text{borne2=minimum}
\text{replist=non monotone, croissante, d�croissante}
\if{\cas=1}
 {
 \integer{vymin=\y2<\y4?\y2:\y4}
 \integer{vymax=\y1<\y3?\y3:\y1}
 \integer{vxmin=\y2<\y4?\x2:\x4}
 \integer{vxmax=\y1<\y3?\x3:\x1}
 \integer{valb=\vymax}
 \integer{valbx=\vxmax}
 \integer{valb2=\vymin}
 \integer{valbx2=\vxmin}
 \if{\cas2>2}
  {
   \text{borne=maximum}
   \integer{indrepM=1}
   \integer{indrepm=1}
   \text{mstep2=r3,r4}
   \text{mstep3=r5,r6}
  }
  {
   \text{mstep3=}
   \if{\cas2=1}
     {
      \integer{indrepM=2}
      \integer{indrepm=1}
      \text{borne=minimum}
      \text{mstep2=r3,r4}
     \integer{valb=\valb2}
     \integer{valbx=\valbx2}
     }
     {
      \integer{indrepM=1}
      \integer{indrepm=2}
      \text{borne=maximum}
      \text{mstep2=r3,r4}
     }
  }
}
{
%% cas = 2
 \integer{vymin=\y1<\y3?\y1:\y3}
 \integer{vymax=\y2<\y4?\y4:\y2}
 \integer{vxmin=\y1<\y3?\x1:\x3}
 \integer{vxmax=\y2<\y4?\x4:\x2}
 \integer{valb=\vymax}
 \integer{valbx=\vxmax}
 \integer{valb2=\vymin}
 \integer{valbx2=\vxmin}
 \if{\cas2>2}
  {
   \text{borne=maximum}
   \integer{indrepM=1}
   \integer{indrepm=1}
   \text{mstep2=r3,r4}
   \text{mstep3=r5,r6}
  }
  {
   \text{mstep3=}
   \if{\cas2=1}
     {
      \integer{indrepM=1}
      \integer{indrepm=2}
      \text{borne=maximum}
      \text{mstep2=r3,r4}
        }
     {
      \integer{indrepM=2}
      \integer{indrepm=1}
      \text{borne=minimum}
      \text{mstep2=r3,r4}
 \integer{valb=\valb2}
 \integer{valbx=\valbx2}
     }
  }
}

%% Choix du graphique: 1=droites 2=paraboles
\integer{typegr=random(1,2)}
\integer{typegr=2}
\if{\typegr=2}
{
 \rational{t3=((\x2)+(\x3))/2}
 \rational{yt3=((\y2)+(\y3))/2}
%% premi�re parabole
%% passe par x1,y1 et x2,y2 et d�riv�e s'annule en x2
\rational{a1=((\y1)-(\y2))/((\x1)-(\x2))^2}
\rational{b1=-2*\a1*\x2}
\rational{c1=( (\y2)*( (\x1)^2-2*(\x1)*(\x2) )+(\y1)*(\x2)^2 )/((\x1)-(\x2))^2}
\text{f= \a1*t^2+(\b1)*t+(\c1)}

%% deuxi�me parabole
%% passe par t3,yt3 et x2,y2 et d�riv�e s'annule en x2
\rational{a2=((\yt3)-(\y2))/((\t3)-(\x2))^2}
\rational{b2=-2*\a2*\x2}
\rational{c2=( (\y2)*( (\t3)^2-2*(\t3)*(\x2) )+(\yt3)*(\x2)^2 )/((\t3)-(\x2))^2}
\text{g= \a2*t^2+(\b2)*t+(\c2)}

%% troisi�me parabole
%% passe par t3,yt3 et x3,y3 et d�riv�e s'annule en x3
\rational{a3=((\yt3)-(\y3))/((\t3)-(\x3))^2}
\rational{b3=-2*\a3*\x3}
\rational{c3=( (\y3)*( (\t3)^2-2*(\t3)*(\x3) )+(\yt3)*(\x3)^2 )/((\t3)-(\x3))^2}
\text{h= \a3*t^2+(\b3)*t+(\c3)}

%% quatri�me parabole
%% passe par x3,y3 et x4,y4 et d�riv�e s'annule en x3
\rational{a4=((\y4)-(\y3))/((\x4)-(\x3))^2}
\rational{b4=-2*\a4*\x3}
\rational{c4=( (\y3)*( (\x4)^2-2*(\x4)*(\x3) )+(\y4)*(\x3)^2 )/((\x4)-(\x3))^2}
\text{l= \a4*t^2+(\b4)*t+(\c4)}

\text{cadrefct=
trange \x1,\x2
 plot red,t,\f
trange \x2,\t3
 plot red,t,\g
trange \t3,\x3
 plot red,t,\h
trange \x3,\x4
 plot red,t,\l
}
}
{
\text{cadrefct=
lines red,\x1,\y1,\x2,\y2,\x3,\y3,\x4,\y4
}
}
%% cadre g�n�rique %%
%%%%%%%%%  adaptation aux valeurs de l'�nonc�
\integer{xmin=\vx1=\(-\infty)?-10:\x1-1}
\integer{xmax=\vx4=\(+\infty)?10:\x4+1}

\integer{ymin= \indrepm ==2 ?-10: min(\valb2-1,-2)}
\integer{ymax= \indrepM ==2 ? 10: max(\valb+1,2)}

%%%%%%%%% taille du cadre %%%%%%%%%%
\integer{hcadre=(\xmax-\xmin)*20}
\integer{vcadre=(\ymax-\ymin)*20}


\text{cadre=
xrange \xmin,\xmax
yrange \ymin,\ymax
linewidth 1
linewidth 2
  parallel \xmin,\ymin,\xmin,\ymax,1,0,30,grey
  parallel \xmin,\ymin,\xmax,\ymin,0,1,30,grey
linewidth 2
parallel -5,-0.3,-5,0.3,10,0,2,black
text black,-5.2,1,medium,-5
text black,4.8,1,medium,5
parallel 0.3,5,-0.3,5,0,-10,2,black
text black,0.5,-5,medium,-5
text black,0.5,5,medium,5
vline 0,0,black
hline 0,0,black
arrow 0,0,1,0,10,black
arrow 0,0,0,1,10,black
text black, 0.7,-0.1,medium,I
text black,-0.6,1.2,medium,J
text black,-0.5,-0.1,medium,O
    linewidth 2
\cadrefct
}
%% fin du cadre g�n�rique %%

%% Solution %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% affichage pour le max %%%%%%%%%%

\if{\indrepM=1}{
\if{\borne==maximum}{
\text{seuilmax= dhline 1,\valb,blue}
\text{textesol= La fonction poss�de un maximum qui vaut \valb puisque :
<ul><li>toute la courbe se situe en dessous de la droite d'�quation \(y=\valb) (en pointill�s bleus sur le  graphique)
</li><li>le point de coordonnn�es \((\valbx ; \valb)) appartient � la courbe.
</li></ul> }}
{
{\text{seuilmax=dhline 1,\valb2,blue}
\text{textesol2= La fonction poss�de un maximum qui vaut \valb2 puisque :
<ul><li>toute la courbe se situe en dessous de la droite d'�quation \(y=\valb2) (en pointill�s bleus sur le  graphique)
</li><li>le point de coordonnn�es \((\valb2x ; \valb2)) appartient � la courbe.
</li></ul> }
}
}
}
{\text{textesol3=La fonction ne poss�de pas de maximum. En effet, sur le graphique, aucune droite parall�le � l'axe des abscisses n'est au dessus de toute la courbe.}}
%% affichage pour le min %%%%%%%%%%
\if{\indrepm=1}{
\if{\borne==minimum}{
\text{seuilmin= dhline 1,\valb,green}
\text{textesol= La fonction poss�de un minimum qui vaut \valb puisque :
<ul><li>toute la courbe se situe au dessus de la droite d'�quation \(y=\valb) (en pointill�s verts sur le graphique)
</li><li>le point de coordonnn�es \((\valbx ; \valb)) appartient � la courbe.
</li></ul> }
}
{\text{seuilmin=dhline 1,\valb2,green}
\text{textesol2= La fonction poss�de un minimum qui vaut \valb2 puisque :
<ul><li>toute la courbe se situe au dessus de la droite d'�quation \(y=\valb2) (en pointill�s verts sur le graphique)
</li><li>le point de coordonnn�es \((\valbx2 ; \valb2)) appartient � la courbe.
</li></ul> }
}
}
{\text{textesol4=La fonction ne poss�de pas de minimum. En effet, sur le graphique, aucune droite parall�le � l'axe des abscisses n'est au dessous de toute la courbe.}}



\text{cadresol=\seuilmax
\seuilmin
}



%%%%% Fin solution %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% enonc� de l'exo %%
\text{trace=\y1 \y2 \y3 \y4 max:\indrepM min:\indrepm valb:\valb valbx:\valbx valb2:\valb2 valbx2:\valbx2}
\text{trace=}
\text{\mstep=r1,r2}
\nextstep{\mstep}



#include "lang.inc"

\statement{
      Dans le plan muni d'un rep�re orthogonal \((O,I,J)\),
on a trac� la courbe repr�sentative d'une fonction \(f) d�finie sur l'intervalle
 \crog \vx1;\vx4 \crod.
<div class="wimscenter"> \draw{\hcadre,\vcadre}{\cadre}
</div>
<p>
On cherche � �tudier ses extrema �ventuels par lecture graphique.</p>
\trace

\if{\step=1}{<div class=wims_question>Compl�tez :<br />
\(f) admet un maximum global : \embed{r1}<br />
\(f) admet un minimum global : \embed{r2}</div>
}
{
   \if{\step=2}
   {<div class=wims_question>
   Compl�tez :<br />
   Le \borne de  \(f) est \embed{r3,2}. <br />
   Il est atteint pour \(x)= \embed{r4,2}
   </div>}
   {\if{\mstep=r5,r6}{<div class=wims_question>
   Compl�tez :<br />
   Le minimum de \(f) est \embed{r5,2}.<br />
   Il est atteint pour \(x) = \embed{r6,2}}.
   </div>}
}
}

\if{\step=2}{\text{mstep=\mstep2}}
{ \if{\step=3}{\text{mstep=\mstep3}}{\text{mstep=}}

}

\answer{\(f) admet un maximum}{\indrepM;\choixrepM}{type=menu}
\answer{\(f) admet un minimum}{\indrepm;\choixrepm}{type=menu}
\answer{\borne}{\valb}{type=numeric}
\answer{abscisse du \borne}{\valbx}{type=numeric}
\answer{\borne2}{\valb2}{type=numeric}
\answer{abscisse du \borne2}{\valbx2}{type=numeric}

\solution{<div class="wimscenter"> \draw{\hcadre,\vcadre}{\cadre
\cadresol}
</div>
\textesol
\textesol2
\textesol3
\textesol4
}

%%%%%%%%
%%rappels
%%% \borne

%%\indrepM=1 il existe un maximum
%%\indrepm=1 il existe un minimum

%%\valb : y maximum
%% \valbx : abs du max

%%\valb2 : y minimum 
%%\valb2x : abs du min
%%%%%%
