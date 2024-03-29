target=sensvargr

#include "header.inc"
#include "lang_titles.inc"


%% couleur des grilles
\text{gridcolor=grey}

%% Choix de 4 points dans le cadre
\integer{x0=random(-4..-2)}
\integer{x1=\x0+random(1..3)}
\integer{x2=\x1+random(1..3)}
\integer{x3=\x2+1}
\integer{c=random(1..3)*random(1,-1)}
\integer{d=random(-2..2)}

%% Calcul de la d�riv�e
\text{fder=\c*(x-(\x1))*(x-(\x2))}
%% on integre
\text{f=\c*(x^3/3-((\x1)+(\x2))*x^2/2+(\x1)*(\x2)*x+(\d))}

%% Calcul de l'�chelle sur y
\real{y1=evalue(\f,x=\x1)}
\real{y2=evalue(\f,x=\x2)}
\integer{ymin=\y1>\y2?\y2-5:\y1-5}
\integer{ymax=\y1>\y2?\y1+5:\y2+5}
\integer{yoffset=(\ymax+(\ymin))/2}
%% centrage de l'image
\integer{ymin=\ymin-\yoffset}
\integer{ymax=\ymax-\yoffset}
\text{f=\f-\yoffset}

%% cadre g�n�rique %%
\text{cadre=
xrange -5,7
yrange \ymin,\ymax
linewidth 1
  parallel -5,\ymin,-5,\ymax,0.2,0,60,\gridcolor
linewidth 2
  parallel -5,\ymin,-5,\ymax,1,0,12,grey
linewidth 2
vline 0,0,black
hline 0,0,black
line -0.2,1,0.2,1,black
line 1,-0.2,1,0.2,black
text black,0.7,-0.1,medium,I
text black,-0.4,1,medium,J
text red,0.7,-0.1,medium,i
text red,-0.2,0.7,medium,j
text black,-0.2,-0.1,medium,O
    linewidth 2
    plot red,\f
}
%% fin du cadre g�n�rique %%

%% Choix des intervalles
\matrix{interval=\x0,\x1
\x1,\x2
\x2,\x3
\x1,\x3
\x0,\x2}

%% Pr�paration des r�ponses
\text{replist=non monotone, croissante, d�croissante}
\if{\c>0}
 { \text{goodrep=2,3,2,1,1}}
 { \text{goodrep=3,2,3,1,1}}

%% Pr�paration des questions
\text{indl=shuffle(5)}
\text{q1=\interval[\indl[1];]}
\text{q2=\interval[\indl[2];]}
\text{q3=\interval[\indl[3];]}
\text{q4=\interval[\indl[4];]}
\text{q5=\interval[\indl[5];]}
%% enonc� de l'exo %%


#include "lang.inc"

\statement{
<div class="float_right spacer">
\draw{400,400}{\cadre}
</div>
      <p>
      Dans le plan muni d'un rep�re orthogonal \((O,I,J)\),
on a trac� la courbe repr�sentative d'une fonction \(f).<br />
Par lecture graphique d�terminer le sens de variation de \(f)
sur les intervalles suivants:
      </p>
<br class="clearall"/>
Votre r�ponse :
<ul>
<li>sur &#91;\q1[1];\q1[2]&#93;, \(f) est \embed{reply1}</li>
<li>sur &#91;\q2[1];\q2[2]&#93;, \(f) est \embed{reply2}</li>
<li>sur &#91;\q3[1];\q3[2]&#93;, \(f) est \embed{reply3}</li>
<li>sur &#91;\q4[1];\q4[2]&#93;, \(f) est \embed{reply4}</li>
<li>sur &#91;\q5[1];\q5[2]&#93;, \(f) est \embed{reply5}</li>
</ul>

}
%% soumission de r�ponse %%
\answer{ \(f) est:}{\goodrep[\indl[1]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[2]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[3]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[4]];\replist}{type=menu}
\answer{ \(f) est:}{\goodrep[\indl[5]];\replist}{type=menu}
