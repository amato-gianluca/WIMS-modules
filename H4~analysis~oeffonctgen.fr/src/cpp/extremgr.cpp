target=extremgr

#include "header.inc"
#include "lang_titles.inc"


%% couleur des grilles
\text{gridcolor=lightblue}
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
     \text{crog=&#93;}
     \integer{y1=2*\ymax}
   }
   {
     \text{d1=\y1}
     \text{crog=&#91;}
   }
 \text{d2=\y2}
 \text{d3=\y3}
 \if{\cas2=2}
  {
    \text{d4=\(-\infty)}
     \text{crod=&#91;}
     \integer{y4=2*\ymin}
  }
  {
    \text{d4=\y4}
     \text{crod=&#93;}
  }
 }
 {
     \text{pos=bottom,top,bottom,top}
  \if{\cas2=2}
   {
     \text{d1=\(-\infty)}
     \text{crog=&#93;}
     \integer{y1=2*\ymin}
   }
   {
     \text{d1=\y1}
     \text{crog=&#91;}
   }
 \text{d3=\y3}
 \text{d2=\y2}
  \if{\cas2=1}
   {
     \text{d4=\(+\infty)}
     \text{crod=&#91;}
     \integer{y4=2*\ymax}
   }
   {
     \text{d4=\y4}
     \text{crod=&#93;}
   }
 }
%% Choix des intervalles
\matrix{interval=\x1,\x2
\x2,\x3
\x3,\x4
\x1,\x3
\x2,\x4}

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
\text{trace=\y1 \y2 \y3 \y4 max:\indrepM min:\indrepm valb:\valb valbx:\valbx valb2:\valb2 valbx2:\valbx2}
\text{trace=}
\text{\mstep=r1,r2}
\nextstep{\mstep}



#include "lang.inc"

\statement{
<div class="float_right spacer"> \draw{400,400}{\cadre}
</div>
      Dans le plan muni d'un rep�re orthogonal \((O,i,j)\),
on a trac� la courbe repr�sentative d'une fonction \(f) d�finie sur l'intervalle
<div class="wimscenter"> \crog \x1;\x4 \crod.</div>
<p>
On cherche � �tudier ses extrema �ventuels par lecture graphique.</p>
\trace
<br class="clearall" />
\if{\step=1}{\(f) admet un maximum global : \embed{r1}<br />
\(f) admet un minimum global : \embed{r2}
}
{
   \if{\step=2}
   { \(f) atteint son \borne : \embed{r3}
en \(x)= \embed{r4}
   }
   {\if{\mstep=r5,r6}{\(f) atteint son minimum : \embed{r5} en \(x) = \embed{r6}}
   }
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
