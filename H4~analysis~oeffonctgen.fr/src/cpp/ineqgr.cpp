target=ineqgr

#include "header.inc"
#include "lang_titles.inc"


## couleur des grilles
\text{gridcolor=lightblue}
\integer{xmin=-5}
\integer{xmax=7}
## Choix de 4 points dans le cadre
\integer{x0=random(-4..-2)}
\integer{x1=\x0+random(1..3)}
\integer{x2=\x1+random(1..3)}
\integer{x3=\x2+random(1..3)}
\real{x4=(\x1+(\x2))/2}
\real{x5=(\x2+(\x3))/2}

\text{sgt=>}
\text{sge=\(\ge )}
\text{slt=<}
\text{sle=\(\le )}
### la liste des objets que l'on peut cliquer pour r�soudre l'exercice ###
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
%% 1: 1 ant�c�dent  2: 3 ant�c�dents
\integer{sensineq=random(1..2)}
\integer{strictineq=random(0..1)}
\text{crochg=\strictineq=0?\crocd:\crocg}
\text{crochd=\strictineq=0?\crocg:\crocd}

\integer{k=random(1..4)}
%%  debug integer{k=4} type de courbe


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
\rational{yg=((\y0)+(\y2))/2}
\text{flg=\y0+((\yg)-(\y0))*(t-(\x0))/((\xmin)-1-(\x0))}
\integer{x4=\x3+(\x1)-(\x0)}
\rational{yd=((\y3)+(\y2))/2}
\text{fld=\y3+((\yd)-(\y3))*(t-(\x4))/((\xmax)+1-(\x4))}
\integer{yy=\y2}
\rational{y2=\y3}
\integer{y3=\yy}
\integer{kk=random(1,-1)}
\text{f0=\kk*(\f0)}
\text{f1=\kk*(\f1)}
\text{ft=\kk*(\ft)}
\text{flg=\kk*(\flg)}
\text{fld=\kk*(\fld)}
\integer{y0=\kk*(\y0)}
\integer{y3=\kk*(\y3)}
  \text{graph=
   trange \x0,\x1
   plot red,t,\f0
   trange \x1,\x3
   plot red,t,\ft
   trange \x3,\x4
   plot red,t,\f1
   trange \xmin,\x0
   plot red,t,\flg
   trange \x4,\xmax
   plot red,t,\fld}
  \integer{val=\casineq=1?\y0:\y3}
   %% reponse
 \if{\casineq=1}
 {
  \integer{val=\y0}
  \if{\kk=1}
  {
    \if{\sensineq=2}
      {
       \text{grep=\crochg,\x0,\ptvirg,\x1,\crochd}
      }
      {
       \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd,\union,\crochg,\x1,\ptvirg,\infd,\crocg}
      }

  }
  {
    \if{\sensineq=1}
      {
       \text{grep=\crochg,\x0,\ptvirg,\x1,\crochd}
      }
      {
       \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd,\union,\crochg,\x1,\ptvirg,\infd,\crocg}
      }

  }
 }
 {
  \integer{val=\y3}
  \if{\kk=1}
  {
    \if{\sensineq=2}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x2,\crochd}
      }
      {
       \text{grep=\crochg,\x2,\ptvirg,\infd,\crocg}
      }

  }
  {
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x2,\crochd}
      }
      {
       \text{grep=\crochg,\x2,\ptvirg,\infd,\crocg}
      }

  }
 }
     \text{rep0=2 \x0 \x1}
    \text{rep1=\x2}
    \text{type2=numeric}
    \text{type1=wlist}
}

\if{\k=3}
{
  %% k=3
  \integer{y0=random(-5..0)}
  \integer{y1=\y0+random(1..3)}
  \integer{y2=\y0}
  \integer{y3=random(3..6)}
  \integer{y3=\y3=\y1?\y3+1}
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
   %% reponse
 \if{\casineq=1}
 {
  \integer{val=\y0}
   \if{\sensineq=1}
      {
      \if{\strictineq=0}
        {
         \text{grep=\crocd,\infg,\ptvirg,\x0,\crocg}
        }
        {
         \text{grep=\crocd,\infg,\ptvirg,\x0,\crocd,\union,\bracg,\x2,\bracd}
        }
      }
      {
      \if{\strictineq=0}
        {
         \text{grep=\crocd,\x0,\ptvirg,\x2,\crocg,\union,\crocd,\x2,\ptvirg,\infd,\crocg}
        }
        {
         \text{grep=\crocg,\x0,\ptvirg,\infd,\crocg}
        }
      }

 }
 {
  \integer{val=\y3}
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x3,\crochd}
      }
      {
       \text{grep=\crochg,\x3,\ptvirg,\infd,\crocg}
      }

 }
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
   %% reponse
 \if{\casineq=1}
 {
  \integer{val=\y0}
   \if{\sensineq=1}
      {
         \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd,\union,\crochg,\x1,\ptvirg,\x2,\crochd}
      }
      {
         \text{grep=\crochg,\x0,\ptvirg,\x1,\crochd,\union,\crochg,\x2,\ptvirg,\infd,\crocg}
      }

 }
 {
  \integer{val=\y3}
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x3,\crochd}
      }
      {
       \text{grep=\crochg,\x3,\ptvirg,\infd,\crocg}
      }

 }
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
 \if{\casineq=1}
 {
  \integer{val=\y3}
   \if{\sensineq=1}
      {
         \text{grep=\crocd,\infg,\ptvirg,\x1,\crochd,\union,\crochg,\x2,\ptvirg,\x3,\crochd}
      }
      {
         \text{grep=\crochg,\x1,\ptvirg,\x2,\crochd,\union,\crochg,\x3,\ptvirg,\infd,\crocg}
      }

 }
 {
  \integer{val=\y0}
    \if{\sensineq=1}
      {
       \text{grep=\crocd,\infg,\ptvirg,\x0,\crochd}
      }
      {
       \text{grep=\crochg,\x0,\ptvirg,\infd,\crocg}
      }

 }
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


%% cadre g�n�rique %%
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
%% fin du cadre g�n�rique %%


%% pr�paration de la question
\text{symb=\slt,\sgt,\sle,\sge}
\integer{j=\sensineq+2*\strictineq}
\text{quest= \(f(x)) \symb[\j] \(\val)}

%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<div class="float_right spacer">
\draw{400,400}{\cadre}
</div>
<p>
Dans le plan muni d'un rep�re orthonorm� \((O,i,j)\),
on a trac� la courbe repr�sentative d'une fonction \(f).</p><p>
R�soudre graphiquement l'in�quation. </p>
<br class="clearall" />
<div class="wimscenter">\quest.</div>

<div>
Votre r�ponse. S= \embed{reply1,\size}
</div>
}
%% soumission de r�ponse %%
\answer{}{\grep;\clicList}{type=clickfill}
