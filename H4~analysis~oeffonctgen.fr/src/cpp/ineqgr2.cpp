target=ineqgr2

#include "header.inc"
#include "lang_titles.inc"

# TODO : am�liorer la lisibilit� en s'inspirant de ineqgr.oef


%% choix de la question
\integer{sensineq=random(1..2)}
\integer{strictineq=random(0..1)}


%% couleur des grilles
\text{gridcolor=lightblue}
\integer{xmin=-10}
\integer{xmax=10}
\integer{ymin=-10}
\integer{ymax=10}

%% Choix de 4 points dans le cadre
\integer{orient=random(1,-1)}

\integer{x0=\xmin}
\integer{x1=\x0+random(2..7)}
\integer{x2=\x1+random(2..4)}
\integer{x3=\x2+random(1..\xmax-1-\x2)}
\integer{y1=random(-5..5)}
\integer{y2=\y1-random(1..\y1-\ymin)}
\integer{y3=\y2+random(1..\ymax-\y2)}
\integer{offset=random(0..5)}
\integer{orientx=random(1,-1)}

\integer{x0=\orientx*(\x0)}
\integer{x1=\orientx*(\x1)}
\integer{x2=\orientx*(\x2)}
\integer{x3=\orientx*(\x3)}

\text{sgt=>}
\text{sge=\(\ge )}
\text{slt=<}
\text{sle=\(\le )}
%% la liste des objets que l'on peut cliquer pour r�soudre l'exercice %%
\text{tx1=\(\x1\)}
\text{tx2=\(\x2\)}
\text{tx3=\(\x3\)}
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
\integer{t0=random(-20..-11)}
\integer{t4=random(11..20)}

\text{permut=shuffle(\x1,\x2,\x3,\t0,\t4)}

\text{clicList=
\crocg,\ptvirg,\crocd,\union,\inter,\infg,\infd,\empt,\bracg,\bracd,\permut[1],\permut[2],\permut[3],\permut[4],\permut[5]
}
%% taille des symboles et des champs � remplir par clic LxHxnb %%
\text{size=60x40x12}



\text{crochg=\strictineq=0?\crocd:\crocg}
\text{crochd=\strictineq=0?\crocg:\crocd}

%% pr�paration de la courbe f
%% parabole par interpolation lagrange
%% passe par x1,y1 , x2,y2 et x3,y3
\rational{f1=(\t0)/(((\x1)-(\x0))*((\x2)-(\x0)))}
\text{f1= \y1*(t-(\x2))*(t-(\x3))/(((\x1)-(\x2))*((\x1)-(\x3)))}
\text{f2= \y2*(t-(\x1))*(t-(\x3))/(((\x2)-(\x1))*((\x2)-(\x3)))}
\text{f3= \y3*(t-(\x2))*(t-(\x1))/(((\x3)-(\x2))*((\x3)-(\x1)))}
\text{f= (\f1)+(\f2)+(\f3)}
\text{f=\orient*(\f)}

%% Pr�paration de la droite
%% passe par x1,y1 et x3,y3
\rational{c=((\y3)-(\y1))/((\x3)-(\x1))}
\text{g= (\c)*(t-(\x3))+(\y3)}
\text{g=\orient*(\g)}

\text{cadrefct=
trange \xmin,\xmax
 plot green,t,\g
trange \xmin,\xmax
 plot red,t,\f
}


%% cadre g�n�rique %%
\text{cadre=
xrange \xmin,\xmax
yrange \ymin,\ymax
linewidth 1
  parallel \xmin,\ymin,\xmin,\ymax,0.2,0,100,\gridcolor
  parallel \xmin,\ymin,\xmax,\ymin,0,0.2,100,\gridcolor
linewidth 2
  parallel \xmin,\ymin,\xmin,\ymax,1,0,21,gray
  parallel \xmin,\ymin,\xmax,\ymin,0,1,21,gray
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


%% pr�paration de la question
\text{symb=\slt,\sgt,\sle,\sge}
\integer{j=\sensineq+2*\strictineq}
\text{quest= \(f(x)) \symb[\j] \(g(x))}

%% pr�paration de la r�ponse
   \if{(\sensineq=1 and \orient=1) or (\sensineq=2 and \orient=-1)}{
       \if{\orientx=1}{
         \text{grep=\crochg,\x1,\ptvirg,\x3,\crochd}
        }{
         \text{grep=\crochg,\x3,\ptvirg,\x1,\crochd}
        }
      }{
       \if{\orientx=1}{
         \text{grep=\crocd,\infg,\ptvirg,\x1,\crochd,\union,\crochg,\x3,\ptvirg,\infd,\crocg}
        }{
         \text{grep=\crocd,\infg,\ptvirg,\x3,\crochd,\union,\crochg,\x1,\ptvirg,\infd,\crocg}
        }
      }

%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<div class="float_right spacer">
\draw{400,400}{\cadre}
</div>
 <p>
Dans le plan muni d'un rep�re orthonorm� \((O,i,j)\),
on a trac� la courbe repr�sentative d'une fonction <span style="color:red">\(f)</span> et
d'une fonction affine <span style="color:green">\(g)</span>.
</p><p>
On admet que les repr�sentations graphiques ne se coupent pas en dehors du cadre affich�.
</p>
<br class="clearall" />
<div class="wims_question">
<p>
R�soudre graphiquement l'in�quation suivante \quest.
</p>
<div>
Votre r�ponse. S= \embed{reply1,\size}
</div>
</div>
}
%% soumission de r�ponse %%
\answer{}{\grep;\clicList}{type=clickfill}
