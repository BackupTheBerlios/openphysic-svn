<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>G&eacute;n&eacute;ration de papiers sp&eacute;ciaux</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
</head>

<body bgcolor="#FFFFFF">
<p><b>Cette page vous permet de g&eacute;n&eacute;rer &agrave; la demande des 
  papiers sp&eacute;ciaux (papier millim&eacute;tr&eacute;, semi-log, quadrill&eacute;, 
  etc...).</b></p>
  <p>Le format de sortie est le format PDF qui permet d'obtenir une tr&egrave;s bonne 
  qualit&eacute; d'impression quelque soit votre environnement (Windows, Mac ou 
  GNU/Linux) et votre imprimante (imprimante laser conseill&eacute;e car les marges 
  physiques d'impression sont plus petites que sur des imprimantes jet d'encre).</p>
<p>Une fois que vous avez valid&eacute; vos choix en cliquant sur le bouton &quot;Valider&quot;, 
  le lecteur Acrobat Reader se lance dans votre navigateur. Vous pouvez alors 
  soit imprimer la ou les pages demand&eacute;es avec l'ic&ocirc;ne &quot;Imprimer 
  : <img src="imprime_acrobat.png" width="20" height="17" align="bottom" alt="imprime_acrobat">&quot;, 
  soit enregistrer ce document pour une utilisation future avec l'ic&ocirc;ne 
  &quot;Enregistrer : <img src="sauve_acrobat.png" width="17" height="17" align="bottom" alt="sauve_acrobat">&quot;.</p>

<hr>
<form method="post" action="gen_papier.php" name="papier">
  <div align="center"> 
    <table width="80%" border="0" cellspacing="0" cellpadding="0">
      <tr> 
        <td colspan="2"> 
          <div align="center">Type de papier : 
            <select name="papier">
              <option value="1" selected>Papier quadrill&eacute; 5mm x 5mm</option>
              <option value="2">Papier millimettr&eacute;</option>
              <option value="3">Papier semi-log 3 modules</option>
              <option value="4">Papier semi-log 4 modules</option>
	      <option value="5">Papier log-log 3 modules</option>
              <option value="6">Papier log-log 4 modules</option>
              <option value="7">Grille au pas 2,54mm</option>
	      <option value="8">Ligne d'écriture CP</option>
              <option value="9">Ligne d'écriture 12mm</option>
              <option value="10">Ligne d'écriture 10mm</option>
              <option value="11">Ligne d'écriture 8mm</option>
            </select>
            et le nombre d'exemplaires 
            <select name="nb_papier">
              <option value="1" selected>1</option>
              <?php
			  for($i=2;$i<=50;$i++) print("<option value=\"$i\">$i</option>\n");
              ?>
            </select>
          </div>
        </td>
      </tr>
      <tr> 
        <td colspan="2">&nbsp; </td>
      </tr>
      <tr> 
        <td colspan="2"> 
          <div align="center"><font color="#00CC00"><b>Facultatif</b></font></div>
        </td>
      </tr>
      <tr> 
        <td width="50%"> 
          <input type="checkbox" name="imp_type_papier" value="True" checked>
          Impression du type de papier et de la date en pied de page<br>
          <input type="checkbox" name="imp_logo" value="True" checked>
          Impression du logo</td>
        <td width="50%"> 
          <div align="right">Couleur de la grille principale : 
            <select name="coul_prim">
              <option value="#000000" selected>Noir</option>
              <option value="#800000">Rouge</option>
	      <option value="#FF0000">Rouge foncé</option>
              <option value="#00FF00">Vert</option>
	      <option value="#008000">Vert foncé</option>
	      <option value="#FFFF00">Jaune</option>
	      <option value="#808000">Jaune foncé</option>
              <option value="#0000FF">Bleu</option>
	      <option value="#000080">Bleu foncé</option>
	      <option value="#FF00FF">Rose</option>
	      <option value="#800080">Rose foncé</option>
	      <option value="#00FFFF">Cyan</option>
	      <option value="#008080">Cyan foncé</option>
              <option value="#808080">Gris</option>
	      <option value="#C0C0C0">Gris clair</option>
            </select>
            <br>
            Couleur de la grille secondaire : 
            <select name="coul_sec">
	      <option value="#000000">Noir</option>
              <option value="#800000">Rouge</option>
	      <option value="#FF0000">Rouge foncé</option>
              <option value="#00FF00">Vert</option>
	      <option value="#008000">Vert foncé</option>
	      <option value="#FFFF00">Jaune</option>
	      <option value="#808000">Jaune foncé</option>
              <option value="#0000FF">Bleu</option>
	      <option value="#000080">Bleu foncé</option>
	      <option value="#FF00FF">Rose</option>
	      <option value="#800080">Rose foncé</option>
	      <option value="#00FFFF">Cyan</option>
	      <option value="#008080">Cyan foncé</option>
              <option value="#808080" selected>Gris</option>
	      <option value="#C0C0C0">Gris clair</option>
            </select>
          </div>
        </td>
      </tr>
      <tr> 
        <td colspan="2">&nbsp;</td>
      </tr>
      <tr> 
        <td colspan="2">          <div align="center"> 
            <input type="submit" name="Submit" value="Valider">
            <input type="reset" name="retablir" value="R&eacute;tablir">
            <input type="button" name="fermer" value="Quitter" onClick="window.close();">
			</div>
        </td>
      </tr>
    </table>
  </div>
</form>
<hr>
<p><font color="#6666FF">Foire Aux Questions (FAQ) :</font></p>
<p><font color="#FF0000">1 - L'impression n'est pas &agrave; l'&eacute;chelle...</font><br>
  Acrobat Reader redimensionne la page pour l'adapter aux marges d'impression 
  de votre imprimante. Pour &eacute;viter cela, lorsque vous cliquez sur le bouton 
  &quot;Imprimer&quot;, d&eacute;cochez la case &quot;Ajuster &agrave; la page&quot;.<br>
  <font color="#FF0000">2 - L'impression est tronqu&eacute;e, le logo ou le type
  de papier ne s'impriment
pas...</font><br>
Une imprimante ne peut pas imprimer jusqu'au bord du papier et ceci plus particuli&egrave;rement
sur le bas de la page. Les imprimantes jet d'encre sont plus sujettes &agrave; ce ph&eacute;nom&egrave;ne
que les imprimantes lasers. Dans la mesure du possible, r&eacute;alisez vos impressions
sur une &quot;laser&quot; ou d&eacute;cochez les cases &quot;Impression du type de papier...&quot; et &quot;Impression
du logo...&quot;.<br>
<font color="#FF0000">3 - Mon ordinateur ne peut pas lire les fichiers au format PDF...</font><br>
Il faut installer le lecteur Adobe Acrobat Reader sur votre ordinateur. Ce logiciel
est disponible gratuitement aupr&eacute;s de la soci&eacute;t&eacute; <a href="http://www.adobe.com">Adobe</a>.</p>
<hr>
<p>Cette page est volontairement tr&egrave;s d&eacute;pouill&eacute;e, si quelqu'un 
  veut se charger de l'aspect &quot;cosm&eacute;tique&quot;...<br>
  Les sources de cette page sont disponibles en cliquant ici. J'utilise la librairie 
  FPDF dont le site est <a href="http://www.fpdf.org">ici</a>.<br>

</p>

<p>Pour toutes remarques (dysfonctionnement, nouveau papier, etc...), &eacute;crivez 
  &agrave; l'adresse suivante :<br>
 <a href="mailto:olivier point dartois at ac tiret limoges point fr">olivier point dartois at ac tiret limoges point fr</a>.
 Merci d'avance et bonne utilisation.</p>

<p>
Avant derni&egrave;re modification : 18/07/2003 par O.Dartois<br>
Derni&egrave;re modification : 25/11/2004 par S.Celles
</p>

<p>
      <a href="http://validator.w3.org/check?uri=referer"><img border="0"
          src="http://www.w3.org/Icons/valid-html401"
          alt="Valid HTML 4.01!" height="31" width="88"></a>
    </p>

</body>
</html>
