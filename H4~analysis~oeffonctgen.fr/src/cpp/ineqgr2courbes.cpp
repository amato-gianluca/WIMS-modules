target=ineqgr2courbes

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
\integer{x1=\x0+random(2..5)}
\integer{x2=\x1+random(3..5)}
%% x3 sym�trique de x0 par rapport � l'axe de f donc y3=y0
\integer{x3=\x2+\x1-\x0}
\integer{x4=\xmax}
\integer{y0=random(2..5)}
\integer{z0=random(7..\ymax)}
\integer{offset=random(0..5)}
\integer{orientx=random(1,-1)}

\integer{x0=\orientx*(\x0)}
\integer{x1=\orientx*(\x1)}
\integer{x2=\orientx*(\x2)}
\integer{x3=\orientx*(\x3)}
\integer{x4=\orientx*(\x4)}


\text{sgt=>}
\text{sge=\(\ge )}
\text{slt=<}
\text{sle=\(\le )}
%% la liste des objets que l'on peut cliquer pour r�soudre l'exercice %%
\text{tx1=\(\x1)}
\text{tx2=\(\x2)}
\text{tx3=\(\x3)}
\text{tx4=\(\x4)}
\text{tx5=\(\x0)}
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
\text{permut=shuffle(\x1,\x2,\x3,\t4,\t0)}

\text{clicList=
\crocg,\ptvirg,\crocd,\union,\inter,\infg,\infd,\empt,\bracg,\bracd,\permut[1],\permut[2],\permut[3],\permut[4],\permut[5]
}
%% taille des symboles et des champs � remplir par clic LxHxnb %%
\text{size=60x40x12}

\text{crochg=\strictineq=0?\crocd:\crocg}
\text{crochd=\strictineq=0?\crocg:\crocd}

%% pr�paration de la courbe f
%% premi�re parabole
%% passe par x0,z0 et s'annule en x1, x2
\rational{c1=(\z0)/(((\x1)-(\x0))*((\x2)-(\x0)))}
\text{f1= \c1*(t-(\x1))*(t-(\x2))-\offset}
\text{f1=\orient*(\f1)}
\rational{f0=evalue(\f1,t=\x0)}

%% deuxi�me parabole
%% passe par x3,y3=y0 etx4,y4=y0 s'annule en x2
\rational{c2=(\y0)/(((\x3)-(\x2))*((\x4)-(\x2)))}
\text{f2= -(\c2)*(t-(\x3))*(t-(\x4))+(\y0)-(\offset)}
\text{f2=\orient*(\f2)}
\rational{y3=evalue(\f2,t=\x3)}

%% pr�paration de la courbe g
%% passe par x0,y0 et s'annule en x1, x2
\rational{c1=(\y0)/(((\x1)-(\x0))*((\x2)-(\x0)))}
\text{g= \c1*(t-(\x1))*(t-(\x2))-(\offset)}
\text{g=\orient*(\g)}
\rational{g0=evalue(\g,t=\x0)}

\text{cadrefct=
trange \x0,\x4
 plot red,t,\g
trange \x0,\x2
 plot blue,t,\f1
trange \x2,\x4
 plot blue,t,\f2
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
   \if{(\sensineq=2 and \orient=1) or (\sensineq=1 and \orient=-1)}{
       \if{\orientx=1}{
         \text{grep=\crochg,\x1,\ptvirg,\x2,\crochd,\union,\crochg,\x3,\ptvirg,\infd,\crocg}
        }{
         \text{grep=\crocd,\infg,\ptvirg,\x3,\crochd,\union,\crochg,\x2,\ptvirg,\x1,\crochd}
        }
      }{
       \if{\orientx=1}{
         \text{grep=\crocd,\infg,\ptvirg,\x1,\crochd,\union,\crochg,\x2,\ptvirg,\x3,\crochd}
        }{
         \text{grep=\crochg,\x3,\ptvirg,\x2,\crochd,\union,\crochg,\x1,\ptvirg,\infd,\crocg}
        }
      }

%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<div class="float_right spacer">
\draw{400,400}{\cadre}
</div>
<p>
\name_statement1 \((O,i,j)\),
\name_statement2 <span style="color:red">\(f)</span> \name_statement2b <span style="color:blue">\(g)</span>.
</p><p>
\name_statement2c.
</p>
<br class="clearall" />
<div class="wims_question"><p>
\name_statement3 \quest.
</p>
\Votrereponse\spacebeforecolon: S= \embed{reply1,\size}
</div>
}
%% soumission de r�ponse %%
\answer{}{\grep;\clicList}{type=clickfill}
