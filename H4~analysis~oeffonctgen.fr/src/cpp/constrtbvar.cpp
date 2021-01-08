target=constrtbvar

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
\integer{xmin=-10}
\integer{xmax=10}
\integer{ymin=-10}
\integer{ymax=10}


%% la liste des objets que l'on peut cliquer pour r�soudre l'exercice %%
\text{vse=\(\searrow)}
\text{vne=\(\nearrow)}
\matrix{symb = \vse,\vne,\vse
\vne,\vse,\vne}
\text{variations = \(\nearrow),\(\searrow)}
\text{monotone = \(\nearrow),\(\searrow)}

%% choix du sens de variation
\integer{cas=random(1,2)}
\integer{cas2=random(1..4)}


%% cas pour d�terminer sens de variation
%% cas 2 pour d�terminer si borne infinie ou pas
%% cas2=1 +inf, =2 -inf =3 ou4 born�e
\integer{i1=\cas=1?1:2}
\integer{i2=\cas=1?2:1}
\text{c_f=\cas=1?1,2,1:2,1,2}
\text{monotone=\symb[\cas;]}

%% choix des valeurs de x
\integer{x1=random(-10..-5)}
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
     \integer{y1=2*\ymax}
   }
   {
     \text{d1=\y1}
   }
 \text{d2=\y2}
 \text{d3=\y3}
 \if{\cas2=2}
  {
    \text{d4=\(-\infty)}
     \integer{y4=2*\ymin}
  }
  {
    \text{d4=\y4}
  }
 }
 {
     \text{pos=bottom,top,bottom,top}
  \if{\cas2=2}
   {
     \text{d1=\(-\infty)}
     \integer{y1=2*\ymin}
   }
   {
     \text{d1=\y1}
   }
 \text{d3=\y3}
 \text{d2=\y2}
  \if{\cas=1}
   {
     \text{d4=\(+\infty)}
     \integer{y4=2*\ymax}
   }
   {
     \text{d4=\y4}
   }
 }
%% Choix des intervalles
\matrix{interval=\x1,\x2
\x2,\x3
\x3,\x4
\x1,\x3
\x2,\x4}

%% la liste des objets que l'on peut cliquer pour r�soudre l'exercice %%
\text{vx1=\(\x1)}
\text{vx2=\(\x2)}
\text{vx3=\(\x3)}
\text{vx4=\(\x4)}
\text{vy1=\(\y1)}
\text{vy2=\(\y2)}
\text{vy3=\(\y3)}
\text{vy4=\(\y4)}
\text{vesp=&nbsp;}
\text{infg=\(-\infty)}
\text{infd=\(+\infty)}
\text{empt=\(\emptyset)}
\text{ptvirg=&#59;}

\text{permut=shuffle(\vx1,\vx2,\vx3,\vx4,\vy1,\vy2,\vy3,\vy4)}
\text{permut= wims(listuniq \permut)}

\text{clicList=
\vse,\vne,\ptvirg,\vesp,\infg,\infd,\empt,\permut
}
%% taille des symboles et des champs � remplir par clic LxHxnb %%
\text{size=60x40x7}
\integer{ind1=wims( positionof item \vx1 in \permut)}
\integer{ind2=wims( positionof item \vx2 in \permut)}
\integer{ind3=wims( positionof item \vx3 in \permut)}
\integer{ind4=wims( positionof item \vx4 in \permut)}
\integer{jnd1=wims( positionof item \vy1 in \permut)}
\integer{jnd2=wims( positionof item \vy2 in \permut)}
\integer{jnd3=wims( positionof item \vy3 in \permut)}
\integer{jnd4=wims( positionof item \vy4 in \permut)}

\text{grepx=\permut[\ind1],\vesp,\permut[\ind2],\vesp,\permut[\ind3],\vesp,\permut[\ind4]}
\text{grepfx=\infg,\monotone[1],\permut[\jnd2],\monotone[2],\permut[\jnd3],\monotone[3],\permut[\jnd4]}
\if{\cas=1}
 {
  \if{\cas2=1}
   {
    \text{grepfx=\infd}
    \text{crog=&#93;}
   }
   {
    \text{grepfx=\permut[\jnd1]}
    \text{crog=&#91;}
   }
 \text{grepfx=\grepfx,\monotone[1],\permut[\jnd2],\monotone[2],\permut[\jnd3],\monotone[3]}
 \if{\cas2=2}
  {
    \text{grepfx=\grepfx,\infg}
    \text{crod=&#91;}
  }
  {
    \text{grepfx=\grepfx,\permut[\jnd4]}
    \text{crod=&#93;}
  }
 }
 {
  \if{\cas2=2}
   {
    \text{grepfx=\infg}
    \text{crog=&#93;}
   }
   {
    \text{grepfx=\permut[\jnd1]}
    \text{crog=&#91;}
   }
 \text{grepfx=\grepfx,\monotone[1],\permut[\jnd2],\monotone[2],\permut[\jnd3],\monotone[3]}
 \if{\cas=1}
   {
    \text{grepfx=\grepfx,\infd}
    \text{crod=&#91;}
   }
   {
    \text{grepfx=\grepfx,\permut[\jnd4]}
    \text{crod=&#93;}
   }
 }


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
   \text{mstep2=r1,r2}
   \text{mstep3=r3,r4}
  }
  {
   \text{mstep3=}
   \if{\cas2=1}
     {
      \integer{indrepM=2}
      \integer{indrepm=1}
      \text{borne=minimum}
      \text{mstep2=r1,r2}
     \integer{valb=\valb2}
     \integer{valbx=\valbx2}
     }
     {
      \integer{indrepM=1}
      \integer{indrepm=2}
      \text{borne=maximum}
      \text{mstep2=r1,r2}
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
   \text{mstep2=r1,r2}
   \text{mstep3=r3,r4}
  }
  {
   \text{mstep3=}
   \if{\cas2=1}
     {
      \integer{indrepM=2}
      \integer{indrepm=1}
      \text{borne=minimum}
      \text{mstep2=r1,r2}
     \integer{valb=\valb2}
     \integer{valbx=\valbx2}
     }
     {
      \integer{indrepM=1}
      \integer{indrepm=2}
      \text{borne=maximum}
      \text{mstep2=r1,r2}
     }
  }
}
%% Pr�paration des questions
\text{indl=shuffle(5)}
\text{q1=\interval[\indl[1];]}
\text{q2=\interval[\indl[2];]}
\text{q3=\interval[\indl[3];]}
\text{q4=\interval[\indl[4];]}
\text{q5=\interval[\indl[5];]}

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
\text{cadre=
xrange \xmin,\xmax
yrange \ymin,\ymax
linewidth 1
  parallel \xmin,\ymin,\xmin,\ymax,0.2,0,100,\gridcolor
  parallel \xmin,\ymin,\xmax,\ymin,0,0.2,100,\gridcolor
linewidth 2
  parallel \xmin,\ymin,\xmin,\ymax,1,0,21,blue
  parallel \xmin,\ymin,\xmax,\ymin,0,1,21,blue
linewidth 2
vline 0,0,black
hline 0,0,black
arrow 0,0,1,0,10,magenta
arrow 0,0,0,1,10,magenta
text red,0.7,-0.1,medium,i
text red,-0.2,0.7,medium,j
text black,-0.2,-0.1,medium,O
    linewidth 2
\cadrefct
}
%% fin du cadre g�n�rique %%

%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<div class="float_right spacer">
 \draw{400,400}{\cadre}
</div>
Dans le plan muni d'un rep�re orthogonal \((O,i,j)\),
on a trac� la courbe repr�sentative d'une fonction \(f) d�finie sur l'intervalle \crog \x1;\x4 \crod.
<p>
Construire le tableau des variations de \(f) en draguant les �l�ments n�cessaires
dans la ligne \(x) et dans la ligne \(f(x)) du tableau ci-dessous.
</p>
<br class="clearall" />
<table class="wimsborder wimscenter">
  <tr><th>\(x) </th><td>\embed{reply1,\size}</td></tr>
 <tr><th>\(f(x))</th><td>\embed{reply2,\size}</td></tr>
</table>
}

\answer{}{\grepx;\clicList}{type=clickfill}
\answer{}{\grepfx;\clicList}{type=clickfill}
