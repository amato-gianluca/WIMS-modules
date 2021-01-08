target=ineqgr2dtes

#include "header.inc"
#include "lang_titles.inc"


%% choix de la question
\integer{casineq=random(1,2)}
%% 1: 1 ant�c�dent  2: 3 ant�c�dents
\integer{sensineqg=random(1..2)}
\integer{strictineqg=random(0..1)}
\integer{sensineqh=random(1..2)}
\integer{strictineqh=random(0..1)}


%% couleur des grilles
\text{gridcolor=lightblue}
\integer{xmin=-10}
\integer{xmax=10}
\integer{ymin=-10}
\integer{ymax=10}

%% Choix de 4 points dans le cadre
\matrix{xl=-7,-3,5,8
-6,-2,3,6
-7,-5,0,3
-7,-3,1,5
-7,-3,4,9
-8,-4,1,8
-7,-3,0,9
-5,-1,4,9
-7,-4,1,7
-6,-4,-1,4
-7,-3,1,8
-6,-2,4,7
-9,-5,2,5
-8,-4,1,7
-9,-7,-4,0
-9,-5,1,8
-9,-7,-4,9
-6,-3,1,9
-9,-5,1,9
-6,-4,1,4
}
\matrix{yl=-5,0,-1,6
-4,3,-6,7
-2,5,0,6
-2,4,0,9
-6,0,-2,3
-1,4,-3,2
0,7,-8,3
-4,2,-1,9
0,5,1,9
-4,3,-2,8
-4,3,-7,-1
-2,3,-7,9
-4,1,-3,6
-1,4,-8,-6
-6,0,-5,3
-2,3,-8,6
0,7,-8,1
-4,2,-6,3
-5,1,-6,2
-4,1,-5,5
}
\integer{indx=random(1..20)}
\integer{orient=random(1,-1)}
\integer{x1=\xl[\indx;1]}
\integer{x2=\xl[\indx;2]}
\integer{x3=\xl[\indx;3]}
\integer{x4=\xl[\indx;4]}
\integer{y1=\orient*\yl[\indx;1]}
\integer{y2=\orient*\yl[\indx;2]}
\integer{y3=\orient*\yl[\indx;3]}
\integer{y4=\orient*\yl[\indx;4]}

\real{x5=(\x1+(\x2))/2}
\real{x6=(\x2+(\x3))/2}



\text{sgt=>}
\text{sge=\(\ge )}
\text{slt=<}
\text{sle=\(\le )}
%% la liste des objets que l'on peut cliquer pour r�soudre l'exercice %%
\text{tx6=\(\x6)}
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

\text{permut=shuffle(\x1,\x2,\x3,\x4,\x5,\x6)}

\text{clicList=
\crocg,\ptvirg,\crocd,\union,\inter,\infg,\infd,\empt,\bracg,\bracd,\permut[1],\permut[2],\permut[3],\permut[4],\permut[5],\permut[6]
}
%% taille des symboles et des champs � remplir par clic LxHxnb %%
\text{size=60x40x12}



\text{gcrochg=\strictineqg=0?\crocd:\crocg}
\text{gcrochd=\strictineqg=0?\crocg:\crocd}
\text{hcrochg=\strictineqh=0?\crocd:\crocg}
\text{hcrochd=\strictineqh=0?\crocg:\crocd}

%% pr�paration de la courbe f
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
trange \xmin,\x2
 plot red,t,\f
trange \x2,\t3
 plot red,t,\g
trange \t3,\x3
 plot red,t,\h
trange \x3,\xmax
 plot red,t,\l
}

%% Choix de 2 droites
\text{colordte=green,blue}
\integer{indcol1=random(1,2)}
\integer{indcol2=\indcol1=1?2:1}
\text{dt1=((\y2)-(\y1))*(x-(\x2))/((\x2)-(\x1))+(\y2)}
\text{dt2=((\y4)-(\y3))*(x-(\x4))/((\x4)-(\x3))+(\y4)}
\text{cadredte=
 plot \colordte[\indcol1],\dt1
 plot \colordte[\indcol2],\dt2
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
\cadredte
\cadrefct
}
%% fin du cadre g�n�rique %%


%% pr�paration de la question
\text{symb=\slt,\sgt,\sle,\sge}
\integer{jg=\sensineqg+2*\strictineqg}
\text{questg= \(f(x)) \symb[\jg] \(g(x))}
\integer{jh=\sensineqh+2*\strictineqh}
\text{questh= \(f(x)) \symb[\jh] \(h(x))}

%% pr�paration de la r�ponse
   \if{(\sensineqg=1 and \orient=1) or (\sensineqg=2 and \orient=-1)}
      {
         \text{grepg=\crocd,\infg,\ptvirg,\x1,\gcrochd,\union,\gcrochg,\x2,\ptvirg,\infd,\crocg}
      }
      {
         \text{grepg=\gcrochg,\x1,\ptvirg,\x2,\gcrochd}
      }
   \if{(\sensineqh=2 and \orient=1) or (\sensineqh=1 and \orient=-1)}
      {
         \text{greph=\crocd,\infg,\ptvirg,\x3,\hcrochd,\union,\hcrochg,\x4,\ptvirg,\infd,\crocg}
      }
      {
         \text{greph=\hcrochg,\x3,\ptvirg,\x4,\hcrochd}
      }

%% permutation des r�ponses en fonctions des couleurs
\if{\indcol1=2}
{
  \text{grep=\grepg}
  \text{grepg=\greph}
  \text{greph=\grep}
  \text{questg= \(f(x)) \symb[\jh] \(g(x))}
  \text{questh= \(f(x)) \symb[\jg] \(h(x))}
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
de deux fonctions affines <span style="color:\colordte[1]">\(g)</span>
 et <span style="color:\colordte[2]">\(h)</span>.
</p><p>
On admet que les repr�sentations graphiques ne se coupent pas en dehors du cadre affich�.
</p>
<p>R�soudre graphiquement les in�quations suivantes.</p>
<br class="clearall" />
Votre r�ponse :
<ul>
 <li>\questg : S= \embed{reply1,\size}</li>
<li>\questh : S= \embed{reply2,\size}</li>
</ul>
}
%% soumission de r�ponse %%
\answer{}{\grepg;\clicList}{type=clickfill}
\answer{}{\greph;\clicList}{type=clickfill}
