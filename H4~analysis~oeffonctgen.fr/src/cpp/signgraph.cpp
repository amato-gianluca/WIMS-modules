target=signgraph

#include "header.inc"
#include "lang_titles.inc"


\real{x1=randint(-4..0)}
\real{x2=\x1+randint(3..6)}
\real{S=\x1+\x2}
\real{P=\x1*\x2}
%%on fait en sorte que la courbe ne sorte pas de la fen�tre graphique :
\real{a=4/(\x1-\x2)^2*randint(1..6)*random(-1,1)}
\function{f=maxima(expand(\a*(x-\x1)*(x-\x2)))}
\text{signe=(\a>0)? 2,1,2:1,2,1}
\text{signeS=(\a>0)? +,-,+:-,+,-}
%%%%%%%%%%%%%%%%%%%
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

  linewidth 1.5
plot blue,\f
}
\text{imgsol=
\img
linewidth 2
crosshairsize 5
crosshairs red,\x1,0,\x2,0}
%%%%%%%%%%%%%%


#include "lang.inc"

\statement{Ci-dessous est trac�e la courbe repr�sentative d'une fonction f d�finie sur \(\mathbb{R}).
<div class="wimscenter">
\draw{300,300}{
\img}
</div> 
<p>Lire graphiquement le signe de \(f(x)) :</p>
<table cellspacing="0" width="40%">
<tbody>
<tr>
<td
style="border-right: 1px solid; border-bottom: 1px solid;text-align: center;" width="35%">\(x)
</td>
<td style="border-bottom: 1px solid;text-align: left; width: 5%">\(-\infty) </td>
<td style="border-bottom: 1px solid;text-align: center; width: 10%"></td>
<td style="border-bottom: 1px solid;text-align: center; width: 5%">\embed{r1,2}</td>
<td style="border-bottom: 1px solid;text-align: center; width: 10%"></td>
<td style="border-bottom: 1px solid;text-align: center; width: 5%">\embed{r2,2}</td>
<td style="border-bottom: 1px solid;text-align: center; width: 10%"></td>
<td style="border-bottom: 1px solid;text-align: right; width: 5%">\(+\infty)</td>
</tr>
<tr>
<td style="border-right: 1px solid;text-align: center;">\(f(x))</td>
<td style="text-align: left; width: 5%"></td>
<td style="text-align: center; width: 10%">\embed{r3,2}</td>
<td style="text-align: center; width: 5%">0</td>
<td style="text-align: center; width: 10%">\embed{r4,2}</td>
<td style="text-align: center; width: 5%">0</td>
<td style="text-align: center; width: 10%">\embed{r5,2}</td>
<td style="text-align: right; width: 5%"></td>
</tr>
</tbody>
</table>
}

\answer{}{\x1}{type=numeric}
\answer{}{\x2}{type=numeric}
\answer{}{\signe[1];-,+}{type=menu}
\answer{}{\signe[2];-,+}{type=menu}
\answer{}{\signe[3];-,+}{type=menu}

\solution{<div class="wimscenter">
\draw{300,300}{
\imgsol}
</div> 
<p>Dans le graphique ci dessus, la fonction change de signe lorsque la courbe coupe l'axe des abscisses 
(points rouges de la courbe).</p>
<p>Le tableau de signe est donc le suivant :</p>
<table cellspacing="0" width="40%">
<tbody>
<tr>
<td
style="border-right: 1px solid; border-bottom: 1px solid;text-align: center;" width="35%">\(x)
</td>
<td style="border-bottom: 1px solid;text-align: left; width: 5%">-&infin; </td>
<td style="border-bottom: 1px solid;text-align: center; width: 10%"></td>
<td style="border-bottom: 1px solid;text-align: center; width: 5%">\x1</td>
<td style="border-bottom: 1px solid;text-align: center; width: 10%"></td>
<td style="border-bottom: 1px solid;text-align: center; width: 5%">\x2</td>
<td style="border-bottom: 1px solid;text-align: center; width: 10%"></td>
<td style="border-bottom: 1px solid;text-align: right; width: 5%">+&infin;</td>
</tr>
<tr>
<td style="border-right: 1px solid;text-align: center;">\(f(x))</td>
<td style="text-align: left; width: 5%"></td>
<td style="text-align: center; width: 10%">\signeS[1]</td>
<td style="text-align: center; width: 5%">0</td>
<td style="text-align: center; width: 10%">\signeS[2]</td>
<td style="text-align: center; width: 5%">0</td>
<td style="text-align: center; width: 10%">\signeS[3]</td>
<td style="text-align: right; width: 5%"></td>
</tr>
</tbody>
</table>}
