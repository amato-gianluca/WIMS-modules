#include "lang_fr.inc"
\text{glossaire=data/glossaire_fr}
\if{\lang=it}{
#include "lang_it.inc"
\text{glossaire=data/glossaire_it}
}

\if{\confparm1=2}{
\text{ou=\vee}
\text{et=\wedge}
\text{not=\neg}
\text{glossaire_index=_2}
}{
\text{ou=\;\;\mathrm{\name_ou}\;\;}
\text{et=\;\;\mathrm{\name_et}\;\;}
\text{not=\overline}
\text{glossaire_index=_1}
}

\text{glossaire=\glossaire\glossaire_index}
