<?php	function func_SetRgbValueFromHex ($pHexColor) {		// INPUT :		// $pHexColor : ie #339933		// OUTPUT :		// return rgb array		// Source : Rini Setiadarma, http://www.oodie.com/		$l_returnarray = array ();		if (!(strpos ($pHexColor, "#") === FALSE)) {			$pHexColor = str_replace ("#", "", $pHexColor);			for ($l_counter = 0; $l_counter < 3; $l_counter++) {				$l_temp = substr($pHexColor, 2 * $l_counter, 2);				$l_returnarray[$l_counter] = 16 * hexdec(substr($l_temp, 0, 1)) + hexdec(substr($l_temp, 1, 1));			}		}		return $l_returnarray;	}		require('./semi_log.php');			// R�cup�ration des variables pour �tre compatible PHP 4.2.0	$coul_prim = $_REQUEST['coul_prim'];	$coul_sec = $_REQUEST['coul_sec'];	$imp_type_papier = $_REQUEST['imp_type_papier'];	$imp_logo = $_REQUEST['imp_logo'];	$nb_papier = $_REQUEST['nb_papier'];	$couleur_rgb_prim = func_SetRgbValueFromHex($coul_prim);	$couleur_rgb_sec = func_SetRgbValueFromHex($coul_sec);	define('FPDF_FONTPATH', './font/');	require('./fpdf.php');	$lycee = "IUT";	$ville = "POITIERS";	$auteur = "S�bastien CELLES";	$auteur_mail = "s.celles@gmail.com";		$tick = array ("no" => 0, "small" => 1,"big" => 2, "verybig" => 3);  	$width = array ("normal" => 0.1, "bold" => 0.35, "normal-bold"=>0.25);	$pdf = new FPDF();	$pdf->Open();	$pdf->SetAuthor($auteur);	$pdf->SetTitle('G�n�ration de papiers sp�ciaux');	$pdf->SetMargins(0, 0);	$pdf->SetLineWidth($width["normal"]);	$pdf->SetAutoPageBreak(1);	$pdf->SetFont('Arial', '', 8);	$pdf->SetTextColor(0, 0, 0);	$date = date("d/m/Y � H:i:s");				switch ($_REQUEST['papier']) {		// G�n�ration papier quadrill� 5mm x 5mm		case 1:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 10; $i <= 280; $i += 5) {				$pdf->Line(10, $i, 200, $i);			}			for($i = 10; $i <= 200; $i += 5) {				$pdf->Line($i, 10, $i, 280);			}			$type_papier = 'Papier quadrill�';		}		break;						// G�n�ration papier millimetr�		case 2:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Grille secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 10; $i <= 280; $i++) {				$pdf->Line(10, $i, 200, $i);			}			for($i = 10; $i <= 200; $i++) {				$pdf->Line($i, 10, $i, 280);			}			for($i = 10; $i <= 200; $i += 10) {				$pdf->Line($i, 10-$tick["small"], $i, 280+$tick["small"]);			}			for($i = 10; $i <= 200; $i += 50) {				$pdf->Line($i, 10-$tick["big"], $i, 280+$tick["big"]);			}			for($i = 280; $i >= 0; $i -= 10) {				$pdf->Line(9, $i, 201, $i);			}			for($i = 280; $i >= 0; $i -= 50) {				$pdf->Line(8, $i, 202, $i);			}			// Grille primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 10; $i <= 280; $i += 10) {				$pdf->Line(10, $i, 200, $i);			}			for($i = 10; $i <= 200; $i += 10) {				$pdf->Line($i, 10, $i, 280);			}			$type_papier = 'Papier millimetr�';		}		break;						// G�n�ration papier semi-log a 3 modules		case 3:		semi_log(3);		break;						// G�n�ration papier semi-log a 4 modules		case 4:		semi_log(4);		break;						// G�n�ration papier log-log a 3 modules		case 5:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Grille secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 1; $i <= 5; $i += 0.1) {				$x = log10($i) * 90;				$pdf->Line(15, 10+$x, 195, 10+$x);				$pdf->Line(15, 100+$x, 195, 100+$x);				$pdf->Line(15, 190+$x, 195, 190+$x);			}			for($i = 5; $i <= 10; $i += 0.2) {				$x = log10($i) * 90;				$pdf->Line(15, 10+$x, 195, 10+$x);				$pdf->Line(15, 100+$x, 195, 100+$x);				$pdf->Line(15, 190+$x, 195, 190+$x);			}			for($i = 1; $i <= 5; $i += 0.1) {				$x = log10($i) * 60;				$pdf->Line(15+$x, 10, 15+$x, 280);				$pdf->Line(75+$x, 10, 75+$x, 280);				$pdf->Line(135+$x, 10, 135+$x, 280);			}			for($i = 5; $i <= 10; $i += 0.2) {				$x = log10($i) * 60;				$pdf->Line(15+$x, 10, 15+$x, 280);				$pdf->Line(75+$x, 10, 75+$x, 280);				$pdf->Line(135+$x, 10, 135+$x, 280);			}			// Grille primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 1; $i <= 10; $i++) {				$x = log10($i) * 90;				$pdf->Line(15, 10+$x, 195, 10+$x);				$pdf->Line(15, 100+$x, 195, 100+$x);				$pdf->Line(15, 190+$x, 195, 190+$x);			}			for($i = 1; $i <= 10; $i++) {				$x = log10($i) * 60;				$pdf->Line(15+$x, 10, 15+$x, 280);				$pdf->Line(75+$x, 10, 75+$x, 280);				$pdf->Line(135+$x, 10, 135+$x, 280);			}			$type_papier = 'Papier logarithmique-logarithmique � 3 modules';		}		break;						// G�n�ration papier log-log a 4 modules		case 6:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Grille secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 1; $i <= 5; $i += 0.1) {				$x = log10($i) * 67.5;				$pdf->Line(15, 10+$x, 195, 10+$x);				$pdf->Line(15, 77.5+$x, 195, 77.5+$x);				$pdf->Line(15, 145+$x, 195, 145+$x);				$pdf->Line(15, 212.5+$x, 195, 212.5+$x);			}			for($i = 5; $i <= 10; $i += 0.2) {				$x = log10($i) * 67.5;				$pdf->Line(15, 10+$x, 195, 10+$x);				$pdf->Line(15, 77.5+$x, 195, 77.5+$x);				$pdf->Line(15, 145+$x, 195, 145+$x);				$pdf->Line(15, 212.5+$x, 195, 212.5+$x);			}			for($i = 1; $i <= 5; $i += 0.1) {				$x = log10($i) * 45;				$pdf->Line(15+$x, 10, 15+$x, 280);				$pdf->Line(60+$x, 10, 60+$x, 280);				$pdf->Line(105+$x, 10, 105+$x, 280);				$pdf->Line(150+$x, 10, 150+$x, 280);			}			for($i = 5; $i <= 10; $i += 0.2) {				$x = log10($i) * 45;				$pdf->Line(15+$x, 10, 15+$x, 280);				$pdf->Line(60+$x, 10, 60+$x, 280);				$pdf->Line(105+$x, 10, 105+$x, 280);				$pdf->Line(150+$x, 10, 150+$x, 280);			}			// Grille primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 1; $i <= 10; $i++) {				$x = log10($i) * 67.5;				$pdf->Line(15, 10+$x, 195, 10+$x);				$pdf->Line(15, 77.5+$x, 195, 77.5+$x);				$pdf->Line(15, 145+$x, 195, 145+$x);				$pdf->Line(15, 212.5+$x, 195, 212.5+$x);			}			for($i = 1; $i <= 10; $i++) {				$x = log10($i) * 45;				$pdf->Line(15+$x, 10, 15+$x, 280);				$pdf->Line(60+$x, 10, 60+$x, 280);				$pdf->Line(105+$x, 10, 105+$x, 280);				$pdf->Line(150+$x, 10, 150+$x, 280);			}			$type_papier = 'Papier logarithmique-logarithmique � 4 modules';		}		break;						// Grille au pas 2,54mm, soit 1/100 de pouce		case 7:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Grille secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 10; $i <= 279.24; $i += 2.54) {				$pdf->Line(10, $i, 200.66, $i);			}			for($i = 10; $i <= 200.66; $i += 2.54) {				$pdf->Line($i, 10, $i, 279.24);			}			$type_papier = 'Grille au pas 2,54mm';		}		break;						// G�n�ration papier ligne d'ecriture CP N�1		case 8:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Ligne secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 25; $i <= 270; $i += 17) {				$pdf->Line(25, $i, 185, $i);			}			for($i = 32; $i <= 260; $i += 17) {				$pdf->Line(25, $i, 185, $i);			}			// Ligne primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 35; $i <= 260; $i += 17) {				$pdf->Line(25, $i, 185, $i);			}			$pdf->SetDrawColor(255, 0, 0);			$pdf->Line(55, 25, 55, 263);			$type_papier = 'Feuille d\'�criture';		}		break;						// G�n�ration papier ligne d'ecriture 12mm		case 9:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Ligne secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 25; $i <= 265; $i += 3) {				$pdf->Line(25, $i, 185, $i);			}			// Ligne primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 25; $i <= 270; $i += 12) {				$pdf->Line(25, $i, 185, $i);			}			$pdf->SetDrawColor(255, 0, 0);			$pdf->Line(55, 25, 55, 265);			$type_papier = 'Feuille d\'�criture 12mm';		}		break;						// G�n�ration papier ligne d'ecriture 10mm		case 10:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Ligne secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 25; $i <= 265; $i += 2.5) {				$pdf->Line(25, $i, 185, $i);			}			// Ligne primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 25; $i <= 265; $i += 10) {				$pdf->Line(25, $i, 185, $i);			}			$pdf->SetDrawColor(255, 0, 0);			$pdf->Line(55, 25, 55, 265);			$type_papier = 'Feuille d\'�criture 8mm';		}		break;						// G�n�ration papier ligne d'ecriture 8mm		case 11:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Ligne secondaire			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($i = 25; $i <= 265; $i += 2) {				$pdf->Line(25, $i, 185, $i);			}			// Ligne primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 25; $i <= 265; $i += 8) {				$pdf->Line(25, $i, 185, $i);			}			$pdf->SetDrawColor(255, 0, 0);			$pdf->Line(55, 25, 55, 265);			$type_papier = 'Feuille d\'�criture 8mm';		}		break;				// G�n�ration papier semi-log a 1 module		case 12:		for($page = 1; $page <= $nb_papier; $page++) {			$pdf->AddPage();			// Grille secondaire			$pdf->SetLineWidth($width["normal"]);			$pdf->SetDrawColor($couleur_rgb_sec[0], $couleur_rgb_sec[1], $couleur_rgb_sec[2]);			for($j = 10; $j <= 200; $j++) {				$pdf->Line($j, 10-$tick["small"], $j, 280+$tick["small"]);			}			$pdf->SetLineWidth($width["normal-bold"]);			for($j = 10; $j <= 200; $j += 10) {				$pdf->Line($j, 10-$tick["big"], $j, 280+$tick["big"]);			}			$pdf->SetLineWidth($width["normal"]);			for($i = 1; $i <= 10; $i += 0.1) {				$x = 270 - log10($i) * 270;				$pdf->Line(10-$tick["small"], 10+$x, 200+$tick["small"], 10+$x);			}						$pdf->SetLineWidth($width["normal-bold"]);						for($i = 1; $i <= 10; $i += 0.5) {				$x = 270 - log10($i) * 270;				$pdf->Line(10-$tick["big"], 10+$x, 200+$tick["big"], 10+$x);			}			// Grille primaire			$pdf->SetLineWidth($width["bold"]);			$pdf->SetDrawColor($couleur_rgb_prim[0], $couleur_rgb_prim[1], $couleur_rgb_prim[2]);			for($i = 1; $i <= 10; $i++) {				$x = 270 - log10($i) * 270;				$pdf->Line(10-$tick["verybig"], 10+$x, 200+$tick["verybig"], 10+$x);			}			for($j = 10; $j <= 200; $j += 50) {				$pdf->Line($j, 10-$tick["verybig"], $j, 280+$tick["verybig"]);			}			$pdf->Line(200, 10-$tick["verybig"], 200, 280+$tick["verybig"]);			$type_papier = 'Papier semi-logarithmique � 1 module';		}		$pdf->SetLineWidth($width["normal"]);		break;				// G�n�ration papier semi-log a 2 modules		case 13:		semi_log(2);		break;		// G�n�ration papier semi-log a 5 modules		case 14:		semi_log(5);		break;						// En cas de probl�me, affichage d'une page d'erreur		default:		$pdf->AddPage();		$pdf->Image('images/logo_erreur.png', 30, 30, 20);		$pdf->Image('images/logo_erreur.png', 160, 30, 20);		$pdf->SetFont('Arial', 'B', 48);		$pdf->SetTextColor(255, 0, 0);		$largeur = $pdf->GetStringWidth('ERREUR');		$pos = 105-($largeur/2);		$pdf->Text($pos, 45, 'ERREUR');		$pdf->SetTextColor(0, 0, 0);		$pdf->SetFont('Arial', '', 12);		$largeur = $pdf->GetStringWidth($date);		$pos = 105-($largeur/2);		$pdf->Text($pos, 50, $date);		$pdf->Image('images/logo_info.png', 30, 60, 20);		$pdf->Image('images/logo_info.png', 160, 60, 20);		$pdf->SetTextColor(0, 0, 255);		$largeur = $pdf->GetStringWidth('Le papier que vous avez s�lectionn� n\'existe pas...');		$pos = 105-($largeur/2);		$pdf->Text($pos, 70, 'Le papier que vous avez s�lectionn� n\'existe pas...');		$largeur = $pdf->GetStringWidth('Imprimez ce document, puis d�posez-le dans mon casier.');		$pos = 105-($largeur/2);		$pdf->Text($pos, 75, 'Imprimez ce document, puis d�posez-le dans mon casier.');		$pdf->Image('images/logo_mel.png', 30, 90, 20);		$pdf->Image('images/logo_mel.png', 160, 90, 20);		$largeur = $pdf->GetStringWidth('Sinon sauvegardez ce document et envoyez-le � :');		$pos = 105-($largeur/2);		$pdf->Text($pos, 100, 'Sinon sauvegardez ce document et envoyez-le � :');		$pdf->SetTextColor(0, 255, 0);		$largeur = $pdf->GetStringWidth($auteur_mail);		$pos = 105-($largeur/2);		$pdf->Text($pos, 105, $auteur_mail);	}				if ($imp_type_papier) {		$pdf->Text(10, 290, $type_papier.' - G�n�r� le '.$date.' - '.$lycee.' - '.$ville);	}		if ($imp_logo) {		$pdf->Image('images/logo.png', 190, 285, 10);	}		// Envoi du document au navigateur	$pdf->Output();?>